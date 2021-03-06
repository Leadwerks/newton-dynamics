/* Copyright (c) <2003-2019> <Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/

#ifndef __DEMO_DEBRIS_ENTITY_H__
#define __DEMO_DEBRIS_ENTITY_H__

#include "ndDemoMesh.h"
#include "ndDemoEntity.h"


class DebrisPoint
{
	public:
	ndMeshVector4 m_posit;
	ndMeshVector m_normal;
	ndMeshUV m_uv;
};

class ndDemoDebrisRootEntity;

class ndDemoDebrisMesh : public ndDemoMesh
{
	public:
	ndDemoDebrisMesh(ndDemoDebrisMesh* const srcMesh, const dArray<DebrisPoint>& vertexArray);
	ndDemoDebrisMesh(const char* const name, ndMeshEffect* const meshNode, const ndShaderPrograms& shaderCache, dInt32 offsetBase, dArray<DebrisPoint>& vertexArray);

	void Render(ndDemoEntityManager* const scene, const dMatrix& modelMatrix);

	private:
	ndDemoSubMeshMaterial m_material[2];
	dInt32 m_textureLocation1;

	friend class ndDemoDebrisRootEntity;
};

class ndDemoDebrisRootEntity: public ndDemoEntity
{
	public:
	ndDemoDebrisRootEntity();
	ndDemoDebrisRootEntity(const ndDemoDebrisRootEntity& copyFrom);
	virtual ~ndDemoDebrisRootEntity(void);

	void FinalizeConstruction(const dArray<DebrisPoint>& vertexArray);

	virtual void Render(dFloat32 timeStep, ndDemoEntityManager* const scene, const dMatrix& matrix) const;

	//dInt32 m_vertexCount;
	//dInt32 m_buffRefCount;
	//GLuint m_vertexBuffer;
	//GLuint m_vertextArrayBuffer;
};

class ndDemoDebrisEntity : public ndDemoEntity
{
	public:
	ndDemoDebrisEntity(ndMeshEffect* const meshNode, dArray<DebrisPoint>& vertexArray, ndDemoDebrisRootEntity* const parent, const ndShaderPrograms& shaderCache);
	ndDemoDebrisEntity(const ndDemoDebrisEntity& copyFrom);
	virtual ~ndDemoDebrisEntity();
	dNodeBaseHierarchy* CreateClone() const;

	virtual void Render(dFloat32 timeStep, ndDemoEntityManager* const scene, const dMatrix& matrix) const;

	//dInt32 m_vertexOffsetBase;
};


#endif