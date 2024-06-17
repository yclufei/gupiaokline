// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasText 包装器类

class CCanvasText : public CCanvas
{
public:
	CCanvasText() {} // 调用 COleDispatchDriver 默认构造函数
	CCanvasText(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasText(const CCanvasText& dispatchSrc) : CCanvas(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ICanvasText 方法
public:

	// ICanvasText 属性
public:

};
