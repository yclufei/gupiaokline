// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#pragma once

#include "commacro.h"
#include "CCanvas.h"

// CCanvasBuySell ��װ����

class CCanvasBuySell : public CCanvas
{
public:
	CCanvasBuySell() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CCanvasBuySell(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasBuySell(const CCanvasBuySell & dispatchSrc) : CCanvas(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// ICanvasBuySell ����
public:

	// ICanvasBuySell ����
public:

};
