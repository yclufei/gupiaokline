// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasToolbar ��װ����

class CCanvasToolbar : public CCanvas
{
public:
	CCanvasToolbar() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCanvasToolbar(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasToolbar(const CCanvasToolbar& dispatchSrc) : CCanvas(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICanvasToolbar ����
public:

	// ICanvasToolbar ����
public:

};
