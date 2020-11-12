/* Copyright (c) <2003-2019> <Julio Jerez, Newton Game Dynamics>
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
*
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source distribution.
*/

// adapted from code by written by Paul Bourke may 1994
//http://paulbourke.net/geometry/polygonise/

#ifndef __D_ISO_SURFACE_H__
#define __D_ISO_SURFACE_H__

#include "dCoreStdafx.h"

#include <map>
#include <vector>

struct POINT3DID 
{
	dInt32 newID;
	float x, y, z;
};

typedef std::map<dInt32, POINT3DID> ID2POINT3DID;

struct TRIANGLE 
{
	dInt32 pointID[3];
};

typedef std::vector<TRIANGLE> TRIANGLEVECTOR;

template <class T>
class dIsoSurface 
{
	public:
	dIsoSurface();
	~dIsoSurface();
	
	// Generates the iso surface from the scalar field contained in the
	// buffer ptScalarField[].
	void GenerateSurface(const T* ptScalarField, T tIsoLevel, dInt32 nCellsX, dInt32 nCellsY,  dInt32 nCellsZ, float fCellLengthX, float fCellLengthY, float fCellLengthZ);

	// Returns true if a valid surface has been generated.
	bool IsSurfaceValid();

	// Deletes the iso surface.
	void DeleteSurface();

	// Returns the length, width, and height of the volume in which the
	// iso surface in enclosed in.  Returns -1 if the surface is not
	// valid.
	int GetVolumeLengths(float& fVolLengthX, float& fVolLengthY, float& fVolLengthZ);

	protected:
	// The number of vertices which make up the iso surface.
	dInt32 m_nVertices;

	// The vertices which make up the iso surface.
	dVector* m_ppt3dVertices;

	// The number of triangles which make up the iso surface.
	dInt32 m_nTriangles;

	// The indices of the vertices which make up the triangles.
	dInt32* m_piTriangleIndices;

	// The number of normals.
	dInt32 m_nNormals;

	// The normals.
	dVector* m_pvec3dNormals;

	// List of POINT3Ds which form the iso surface.
	ID2POINT3DID m_i2pt3idVertices;

	// List of TRIANGLES which form the triangulation of the iso surface.
	TRIANGLEVECTOR m_trivecTriangles;

	// Returns the edge ID.
	dInt32 GetEdgeID(dInt32 nX, dInt32 nY, dInt32 nZ, dInt32 nEdgeNo);

	// Returns the vertex ID.
	dInt32 GetVertexID(dInt32 nX, dInt32 nY, dInt32 nZ);

	// Calculates the intersection point of the iso surface with an
	// edge.
	POINT3DID CalculateIntersection(dInt32 nX, dInt32 nY, dInt32 nZ, dInt32 nEdgeNo);

	// Interpolates between two grid points to produce the point at which
	// the iso surface intersects an edge.
	POINT3DID Interpolate(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2, T tVal1, T tVal2);
 
	// Renames vertices and triangles so that they can be accessed more
	// efficiently.
	void RenameVerticesAndTriangles();

	// Calculates the normals.
	void CalculateNormals();

	// No. of cells in x, y, and z directions.
	dInt32 m_nCellsX, m_nCellsY, m_nCellsZ;

	// Cell length in x, y, and z directions.
	float m_fCellLengthX, m_fCellLengthY, m_fCellLengthZ;

	// The buffer holding the scalar field.
	const T* m_ptScalarField;

	// The iso surface value.
	T m_tIsoLevel;

	// Indicates whether a valid surface is present.
	bool m_bValidSurface;

	// Lookup tables used in the construction of the iso surface.
	static const dInt32 m_edgeTable[256];
	static const dInt32 m_triTable[256][16];
};

#endif

