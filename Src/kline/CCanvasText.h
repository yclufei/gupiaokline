// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasText ��װ����

class CCanvasText : public CCanvas
{
public:
	CCanvasText() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCanvasText(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasText(const CCanvasText& dispatchSrc) : CCanvas(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICanvasText ����
public:

	// ICanvasText ����
public:

};
