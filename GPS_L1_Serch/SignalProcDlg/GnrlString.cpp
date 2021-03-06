// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// GnrlString.cpp
//
// 依存：MFC
// 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include "stdafx.h"

#include "GnrlString.h"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// CString型16進文字列をuint32型整数へ変換
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void dump16ToUint32(CString &Text ,uint32_t &nValue)
{
	wchar_t*	pszEnd;

	nValue = (uint32_t)::_wcstoi64(Text.GetBuffer(0) ,&pszEnd ,16);		// 16進文字列→int変換		wcstolだと0x7FFFFFFFまでしか変換できない。
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void uint32ToDump16(CString &Text ,uint32_t nValue ,uint32_t Digits)
{
//	CString str;

	const wchar_t *format[] = {
		_T("%00X") ,_T("%01X") ,_T("%02X") ,_T("%03X") ,_T("%04X") ,_T("%05X") ,_T("%06X") ,_T("%07X"),
		_T("%08X") ,_T("%09X") ,_T("%010X") ,_T("%011X") ,_T("%012X") ,_T("%013X") ,_T("%014X") ,_T("%015X"),
		_T("%016X")
	};

	if(Digits > 16)	Digits = 16;

	Text.Format(format[Digits] ,nValue);
	
}

