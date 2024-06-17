// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasGraph 包装器类

class CCanvasGraph : public CCanvas
{
public:
	CCanvasGraph() {} // 调用 COleDispatchDriver 默认构造函数
	CCanvasGraph(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasGraph(const CCanvasGraph& dispatchSrc) : CCanvas(dispatchSrc) {}

	// 特性
public:

	// 操作
public:
	void SetChartType(LONG level, LONG ctype, BYTE r, BYTE g, BYTE b, BYTE a)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_UI1 VTS_UI1 VTS_UI1 VTS_UI1;
		InvokeHelper(DISPIDSETCHARTTYPE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, level, ctype, r, g, b, a);
	}



	// ICanvasGraph 方法
public:

	// ICanvasGraph 属性
public:

};
