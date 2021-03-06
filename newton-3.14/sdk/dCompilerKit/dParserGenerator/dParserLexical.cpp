/* Copyright (c) <2003-2016> <Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/


//
//Auto generated Lexical Analyzer class: dParserLexical.cpp
//

#include <dParserCompiler.h>

#include "dParserLexical.h"


dParserLexical::dParserLexical(const char* const data)
	:m_tokenString ("")
	,m_data(data)
	,m_index(0)
	,m_startIndex(0)
	,m_lineNumber(1)
{
}

dParserLexical::~dParserLexical()
{
}


void dParserLexical::ReadBalancedExpression (char open, char close)
{
	int count = 1;
	while (count) {
		int ch = NextChar();
		if (ch == '\n') {
			m_lineNumber ++;
		}

		if(ch == open) {
			count ++;
		} else if (ch == close) {
			count --;
		} else {
			if (ch == '\'')	{
				ch = NextChar();
				if (ch == '\\') {
					ch = NextChar();
				}
				ch = NextChar();
			} else if (ch == '\"') {
				for (ch = NextChar(); ch != '\"'; ch = NextChar()) {
					if (ch == '\\') {
						ch = NextChar();
					}
				}
			}
		}
	}

	dString tmp (m_tokenString);
	GetLexString();
	m_tokenString = tmp + m_tokenString;
}


void dParserLexical::GetLexString ()
{
	int length = m_index - m_startIndex;
	const char* const data = &m_data[m_startIndex];
	m_tokenString = dString (data, length);
	m_startIndex = m_index;
}


int dParserLexical::GetNextStateIndex (char symbol, int count, const char* const characterSet) const
{
	int i0 = 0;
	int i1 = count - 1;
	while ((i1 - i0) >= 4) {
		int i = (i1 + i0 + 1)>>1;
		if (symbol <= characterSet[i]) {
			i1 = i;
		} else {
			i0 = i;
		}
	}

	for (int i = i0; i <= i1; i ++) {
		if (symbol == characterSet[i]) {
			return i;
		}
	}
	return -1;
}

int dParserLexical::NextToken ()
{
	static short transitionsCount[] = {
			74, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 126, 126, 10, 0, 0, 63, 63, 0, 0, 
			2, 127, 127, 127, 127, 78, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
			1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 127, 127, 127, 127, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	static short transitionsStart[] = {
			0, 74, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 
			78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 204, 78, 78, 214, 214, 78, 78, 
			277, 279, 406, 279, 279, 533, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 
			629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 647, 774, 647, 647, 901, 902, 903, 904, 905, 906, 907, 908, 909, 910, 
			911, 912, 913, 914, 915, 916, 917, 918, 919, 920, 921, 922, 923, 924, 925, 926, 927};
	static short nextStateSet[] = {
			1, 1, 1, 1, 81, 53, 48, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 42, 43, 45, 45, 45, 45, 45, 
			45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 
			45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 
			46, 47, 1, 1, 1, 1, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 
			39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 
			39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 
			39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 
			39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 
			39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 44, 44, 
			44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 
			44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 
			44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 49, 40, 52, 52, 52, 52, 52, 52, 52, 52, 52, 
			52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 
			52, 52, 52, 52, 52, 52, 52, 52, 50, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 
			52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 
			52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 
			52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 51, 51, 
			51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 
			51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 38, 51, 51, 51, 
			51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 
			51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 
			51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 
			51, 51, 51, 51, 51, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 
			62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 
			62, 61, 60, 59, 58, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 
			62, 62, 62, 62, 62, 62, 62, 57, 56, 55, 54, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 
			24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 2, 108, 105, 102, 98, 94, 90, 86, 82, 85, 
			85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 
			85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 83, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 
			85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 
			85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 
			85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 
			85, 85, 85, 85, 85, 85, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 
			84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 
			84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 
			84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 
			84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 
			84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 10, 84, 84, 87, 88, 89, 9, 91, 92, 93, 8, 95, 96, 97, 
			7, 99, 100, 101, 6, 103, 104, 5, 106, 107, 4, 109, 110, 111, 112, 3};
	static char  nextCharacterSet[] = {
			9, 10, 13, 32, 37, 39, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 65, 66, 67, 68, 69, 
			70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 95, 97, 98, 
			99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 
			123, 124, 9, 10, 13, 32, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
			20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 
			44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 
			68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 
			92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 
			116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 49, 
			50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
			81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 95, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 
			110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 42, 47, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
			10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 
			34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 
			58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 
			82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 
			106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 1, 2, 
			3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
			27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
			51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 
			75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 
			99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 
			123, 124, 125, 126, 127, 33, 35, 37, 38, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 65, 
			66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 
			90, 91, 92, 93, 94, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 
			116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 
			39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 37, 101, 108, 112, 114, 115, 116, 117, 123, 1, 
			2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 
			26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 
			50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 
			74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 
			98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 
			122, 123, 124, 125, 126, 127, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 
			19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 
			43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 
			67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 
			91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 
			115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 110, 105, 111, 110, 111, 107, 101, 110, 116, 97, 114, 
			116, 105, 103, 104, 116, 114, 101, 99, 101, 102, 116, 120, 112, 101, 99, 116};
	
	m_startIndex = m_index;

	int state = 0;
	int zeroCount = 2;
	char ch = NextChar();
	do {
		int transCount = transitionsCount[state];
		int tranStart = transitionsStart[state];
		int nextStateIndex = GetNextStateIndex (ch, transCount, &nextCharacterSet[tranStart]);
		if (nextStateIndex >= 0) {
			ch = NextChar();
			short* const stateArray = &nextStateSet[tranStart];
			state = stateArray[nextStateIndex];
		} else {
			UnGetChar ();
			GetLexString ();
			switch (state) 
			{
				case 1:
				{
					state = 0;
					ch = NextChar();
					break;
				}
				case 2:
				{
					 return dParserCompiler::GRAMMAR_SEGMENT;
				}
				case 3:
				{
					 return dParserCompiler::EXPECT;
				}
				case 4:
				{
					 return dParserCompiler::LEFT;
				}
				case 5:
				{
					 return dParserCompiler::PREC;
				}
				case 6:
				{
					 return dParserCompiler::RIGHT;
				}
				case 7:
				{
					 return dParserCompiler::START;
				}
				case 8:
				{
					 return dParserCompiler::TOKEN;
				}
				case 9:
				{
					 return dParserCompiler::UNION;
				}
				case 10:
				{
					 m_tokenString.Replace(0, 2, ""); m_tokenString.Replace(m_tokenString.Size() - 2, 2, ""); return dParserCompiler::CODE_BLOCK;
				}
				case 11:
				{
					 m_tokenString = "!"; return('!'); 
				}
				case 12:
				{
					 m_tokenString = "#"; return('#'); 
				}
				case 13:
				{
					 m_tokenString = "%"; return('%'); 
				}
				case 14:
				{
					 m_tokenString = "&"; return('&'); 
				}
				case 15:
				{
					 m_tokenString = "("; return('('); 
				}
				case 16:
				{
					 m_tokenString = ")"; return(')'); 
				}
				case 17:
				{
					 m_tokenString = "*"; return('*'); 
				}
				case 18:
				{
					 m_tokenString = "+"; return('+'); 
				}
				case 19:
				{
					 m_tokenString = ","; return(','); 
				}
				case 20:
				{
					 m_tokenString = "-"; return('-'); 
				}
				case 21:
				{
					 m_tokenString = "."; return('.'); 
				}
				case 22:
				{
					 m_tokenString = "/"; return('/'); 
				}
				case 23:
				{
					 m_tokenString = ":"; return(':'); 
				}
				case 24:
				{
					 m_tokenString = ";"; return(';'); 
				}
				case 25:
				{
					 m_tokenString = "<"; return('<'); 
				}
				case 26:
				{
					 m_tokenString = "="; return('='); 
				}
				case 27:
				{
					 m_tokenString = ">"; return('>'); 
				}
				case 28:
				{
					 m_tokenString = "?"; return('?'); 
				}
				case 29:
				{
					 m_tokenString = m_tokenString.SubString (1, 1); return(m_tokenString[0]); 
				}
				case 30:
				{
					 m_tokenString = "["; return('['); 
				}
				case 31:
				{
					 m_tokenString = "\\"; return('\\'); 
				}
				case 32:
				{
					 m_tokenString = "]"; return(']'); 
				}
				case 33:
				{
					 m_tokenString = "^"; return('^'); 
				}
				case 34:
				{
					 m_tokenString = "{"; return('{'); 
				}
				case 35:
				{
					 m_tokenString = "|"; return('|'); 
				}
				case 36:
				{
					 m_tokenString = "}"; return('}'); 
				}
				case 37:
				{
					 m_tokenString = "~"; return('~'); 
				}
				case 38:
				{
					
					state = 0;
					ch = NextChar();
					break;
				}
				case 39:
				{
					
					state = 0;
					ch = NextChar();
					break;
				}
				case 40:
				{
					
					state = 0;
					ch = NextChar();
					break;
				}
				case 41:
				{
					 return dParserCompiler::INTEGER;
				}
				case 42:
				{
					 return(dParserCompiler::COLOM); 
				}
				case 43:
				{
					 return(dParserCompiler::SIMICOLOM); 
				}
				case 44:
				{
					 return dParserCompiler::LITERAL;
				}
				case 45:
				{
					 return dParserCompiler::LITERAL;
				}
				case 46:
				{
					 ReadBalancedExpression ('{', '}'); return dParserCompiler::SEMANTIC_ACTION;
				}
				case 47:
				{
					 return(dParserCompiler::OR); 
				}


				default:
				{
					// Lexical error
					return -1;
				}
			}
		}
		if (!ch) {
			zeroCount--;
		}
	} while (zeroCount);
	// Unknown pattern
	return -1;
}

