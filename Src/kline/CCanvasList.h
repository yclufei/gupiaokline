// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasList ��װ����

class CCanvasList : public CCanvas
{
public:
	CCanvasList() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCanvasList(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasList(const CCanvasList& dispatchSrc) : CCanvas(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICanvasList ����
public:

	// ICanvasList ����
public:

};
