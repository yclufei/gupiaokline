// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#pragma once
#include "commacro.h"


#ifdef _WIN64

#ifdef DEBUG
#import "../../Output/Debug_x64/CKUI.ocx" no_namespace
#else
#import "../../Output/Release_x64/CKUI.ocx" no_namespace
#endif

#else

#ifdef DEBUG
#import "../../Output/Debug_x86/CKUI.ocx" no_namespace
#else
#import "../../Output/Release_x86/CKUI.ocx" no_namespace
#endif

#endif




// CCanvas 包装器类


class CCanvas : public COleDispatchDriver
{
public:
	CCanvas() {} // 调用 COleDispatchDriver 默认构造函数
	CCanvas(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCanvas(const CCanvas& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// ICanvas 方法
public:
	void Splitter(long row, long col)
	{
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(DISPIDSPLITTER, DISPATCH_METHOD, VT_EMPTY, NULL, parms, row, col);
	}
	LPDISPATCH CreateSubCanvas(long row, long col, long stype, signed char * sname)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI1;
		InvokeHelper(DISPIDCREATESUBCANVAS, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, row, col, stype, sname);
		return result;
	}
	LPDISPATCH GetSubCanvas(long row, long col)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(DISPIDGETSUBCANVAS, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, row, col);
		return result;
	}
	virtual void SetData(unsigned char * pData, long nSize, signed char * pszDataFmts, signed char * pszColNames, signed char * pszLineTypes, signed char * pszColors)
	{
		static BYTE parms[] = VTS_PUI1 VTS_I4 VTS_PI1 VTS_PI1 VTS_PI1 VTS_PI1;
		InvokeHelper(DISPIDSETDATA, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pData, nSize, pszDataFmts, pszColNames, pszLineTypes, pszColors);
	}
	void SetTitle(signed char * title)
	{
		static BYTE parms[] = VTS_PI1;
		InvokeHelper(DISPIDSETTITLE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, title);
	}
	void RemoveLinkage(signed char * title)
	{
		static BYTE parms[] = VTS_PI1;
		InvokeHelper(DISPIDREMOVELINKAGE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, title);
	}
	void AddLinkage(signed char * title)
	{
		static BYTE parms[] = VTS_PI1;
		InvokeHelper(DISPIDADDLINKAGE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, title);
	}
	void SetXAxis(signed char * __MIDL__ICanvas0000)
	{
		static BYTE parms[] = VTS_PI1;
		InvokeHelper(DISPIDSETXAXIS, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0000);
	}
	void SetYAxis(signed char * __MIDL__ICanvas0000)
	{
		static BYTE parms[] = VTS_PI1;
		InvokeHelper(DISPIDSETYAXIS, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0000);
	}
	void SetXAxisVisible(long __MIDL__ICanvas0001)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(DISPIDSETXAXISVISIBLE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0001);
	}
	void SetYAxisVisible(long __MIDL__ICanvas0001)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(DISPIDSETYAXISVISIBLE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0001);
	}
	void SetVisible(BYTE __MIDL__ICanvas0001)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(DISPIDSETVISIBLE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0001);
	}
	void ShowPaintChart(BYTE __MIDL__ICanvas0001)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(DISPIDSHOWPAINTCHART, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0001);
	}

	
	void SetXRange(__int64 __MIDL__ICanvas0002, __int64 __MIDL__ICanvas0003)
	{
		static BYTE parms[] = VTS_I8 VTS_I8;
		InvokeHelper(DISPIDSETXRANGE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0002, __MIDL__ICanvas0003);
	}


	void SetXRangeByRow(long __MIDL__ICanvas0004, long __MIDL__ICanvas0005)
	{
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(DISPIDSETXRANGEBYROW, DISPATCH_METHOD, VT_EMPTY, NULL, parms, __MIDL__ICanvas0004, __MIDL__ICanvas0005);
	}

	void SetItemSize(long a, long b, long c)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(DISPIDSETITEMSIZE, DISPATCH_METHOD, VT_EMPTY, NULL, parms, a, b, c);
	}

	void UpdataForDataChange()
	{
		InvokeHelper(DISPIDUPDATAFORDATACHANGE, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


	void RemoveChart(signed char * chartname)
	{
		static BYTE parms[] = VTS_PI1;
		InvokeHelper(DISPIDREMOVECHART, DISPATCH_METHOD, VT_EMPTY, NULL, parms, chartname);
	}

	// ICanvas 属性
public:

};
