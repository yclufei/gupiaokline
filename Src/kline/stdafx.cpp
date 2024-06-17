
// stdafx.cpp : 只包括标准包含文件的源文件
// kline.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"


/*
void *operator new(size_t sz)
{
	if (sz == 1032)
	{
		TRACE("1032\n");
	}
	TRACE("operator new:%d Bytes\n", sz);
	void *m = malloc(sz);
	if (!m)
		TRACE("out of memory\n");
	return m;
}

void operator delete(void *m)
{
	TRACE("operator delete\n");
	free(m);
}



void operator delete[](void* p)
{
	TRACE("operator delete\n");
	free(p);
}
*/