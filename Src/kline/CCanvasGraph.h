// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasGraph ��װ����

class CCanvasGraph : public CCanvas
{
public:
	CCanvasGraph() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCanvasGraph(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasGraph(const CCanvasGraph& dispatchSrc) : CCanvas(dispatchSrc) {}

	// ����
public:

	// ����
public:
	void SetChartType(LONG level, LONG ctype, BYTE r, BYTE g, BYTE b, BYTE a)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_UI1 VTS_UI1 VTS_UI1 VTS_UI1;
		InvokeHelper(DISPIDSETCHARTTYPE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, level, ctype, r, g, b, a);
	}



	// ICanvasGraph ����
public:

	// ICanvasGraph ����
public:

};
