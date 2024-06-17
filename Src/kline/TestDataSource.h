#pragma once
#include <stdint.h>

class CRingBuffer;

class CTestDataSource
{
public:
	CTestDataSource(char *);
	~CTestDataSource();

	unsigned char * GetBuffer(int64_t time = -1);

	int GetRow() {
		return m_iRows - 1;
	}
private:

	char*** m_ppList;
	int m_iRows;
	int m_iCols;
	int m_iTtotalSize;
	unsigned char * m_pBuffer;
	CRingBuffer * m_cRbk;
	int64_t * m_arDateArray;
};

