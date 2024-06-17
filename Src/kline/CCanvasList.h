// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#pragma once

#include "commacro.h"
#include "CCanvas.h"
// CCanvasList 包装器类

class CCanvasList : public CCanvas
{
public:
	CCanvasList() {} // 调用 COleDispatchDriver 默认构造函数
	CCanvasList(LPDISPATCH pDispatch) : CCanvas(pDispatch) {}
	CCanvasList(const CCanvasList& dispatchSrc) : CCanvas(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ICanvasList 方法
public:

	// ICanvasList 属性
public:

};
