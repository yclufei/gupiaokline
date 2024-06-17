// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasToolbar 包装器类

class CCanvasToolbar : public CCanvas
{
public:
	CCanvasToolbar() {} // 调用 COleDispatchDriver 默认构造函数
	CCanvasToolbar(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasToolbar(const CCanvasToolbar& dispatchSrc) : CCanvas(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ICanvasToolbar 方法
public:

	// ICanvasToolbar 属性
public:

};
