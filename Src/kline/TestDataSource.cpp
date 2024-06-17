#include "stdafx.h"
#include "TestDataSource.h"
#include "CRingBuffer.h"



//将字串按分割符cDivid分割成字串数组。
//返回数组个数
//注意：调用者释放此数组free(pszArray)
int Split2Array(const char* pszSrcString, char cDivid, char** &pszArray)
{
	int i;
	if (!pszSrcString || !pszSrcString[0])
	{
		pszArray = NULL;
		return 0;
	}

	int nArrySize = 1;
	char* p = (char*)pszSrcString;
	while (1)
	{
		p = strchr(p + 1, cDivid);
		if (p)
			nArrySize++;
		else
			break;
	}

	char** pTmplKeys = (char**)new char*[sizeof(char*) * nArrySize + sizeof(char) * (strlen(pszSrcString) + 1)];
	char* pszSrcStringCopy = (char*)&pTmplKeys[nArrySize];

	strcpy(pszSrcStringCopy, pszSrcString);

	p = pszSrcStringCopy;
	pTmplKeys[0] = p;
	for (i = 1; i < nArrySize; i++)
	{
		p = strchr(p + 1, cDivid);
		if (!p)
		{
			nArrySize = i;
			break;
		}
		*p = 0;
		if (p)
			pTmplKeys[i] = ++p;
	}

	pszArray = pTmplKeys;

	return nArrySize;
}

//字串替换
char *strreplace(char *str, char *oldstr, char *newstr)
{
	int len = strlen(str);
	char* bstr = new char[len];//转换缓冲区
	memset(bstr, 0, sizeof(bstr));

	for (int i = 0; i < len; i++) {
		if (!strncmp(str + i, oldstr, strlen(oldstr))) {//查找目标字符串
			strcat(bstr, newstr);
			i += strlen(oldstr) - 1;
		}
		else {
			strncat(bstr, str + i, 1);//保存一字节进缓冲区
		}
	}

	strcpy(str, bstr);
	delete bstr;
	return str;
}


//读csv成二维字串数组data.
//注意：data由调用者释放
int ReadStringArrayFromCsv(char* lpszPathName, char*** &data, int& nRows, int& nCols)
{
	int i, j;

	data = NULL;
	nRows = nCols = 0;

	FILE *file = fopen(lpszPathName, "r");
	if (file == NULL)
	{
		char str[100];
		sprintf(str, "没有找到文件%s", lpszPathName);
		::MessageBoxA(NULL, lpszPathName, "ReadStringArrayFromCsv", MB_OK);
		return 0;
	}

	fseek(file, 0, SEEK_END);
	int nLen = ftell(file);
	rewind(file);
	if (!nLen)
	{
		fclose(file);
		return 0;
	}

	char* pBuf = NULL;

	//计算二维数组尺寸
	char** pszRows = NULL;
	pBuf = (char*)malloc(nLen + 1);
	fread(pBuf, 1, nLen, file);
	fclose(file);

	pBuf[nLen] = '\0';
	//strreplace(pBuf, "\r\n", "\n");

	nRows = Split2Array(pBuf, '\n', pszRows);
	assert(nRows > 0);
	delete (pBuf);

	char** pszCols = NULL;
	nCols = Split2Array(pszRows[0], ',', pszCols);
	if (pszCols)
		delete (pszCols);

	assert(nCols > 0);

	int nRowStart = 0;

	//分配二维数组

	char* p = (char*)malloc( ( sizeof(char**) * nRows + sizeof(char*) * nCols * nRows + nLen ) * 2 );
	char*** m_ppList = (char***)p;

	p += sizeof(char**) * nRows;
	m_ppList[0] = (char**)p;

	for (j = 1; j < nRows; j++)
		m_ppList[j] = m_ppList[j - 1] + nCols;

	p += sizeof(char*) * nCols * nRows;	//p指向数据区
										//填写二维数组
	char* paaa = p;

	for (i = nRowStart; i < nRowStart + nRows; i++)
	{
		char** pszCols = NULL;
		int nCurCols = Split2Array(pszRows[i], ',', pszCols);
		if (nCurCols < nCols)
		{
			if (pszCols)
				delete (pszCols);
			break;
		}
		int cc = 0;

		for (int j = 0; j < nCols; j++)
		{
			int nTmp = strlen(pszCols[j]);
			strcpy(p, pszCols[j]);
			m_ppList[i - nRowStart][cc++] = p;
			p += nTmp + 1;
		}
		if (pszCols)
			free(pszCols);
	}
	nRows = i - nRowStart;

	if (pszRows)
		free(pszRows);

	data = m_ppList;

	return nRows / 2;
}


// CklineDlg 消息处理程序

time_t StringToDatetime(char *str)
{
	tm tm_;
	int year = 0;
	int month = 0;
	int  day = 0;
	int  hour = 0;
	int  minute = 0;
	int  second = 0;
	sscanf(str, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
	tm_.tm_year = year - 1900;
	tm_.tm_mon = month - 1;
	tm_.tm_mday = day;
	tm_.tm_hour = hour;
	tm_.tm_min = minute;
	tm_.tm_sec = second;
	tm_.tm_isdst = 0;
	time_t t_ = mktime(&tm_); //已经减了8个时区  
	return t_; //秒时间  
}

/*
例子：

char*** m_ppList = NULL;
int nRows, nCols;
ReadStringArrayFromCsv(文件名, m_ppList, nRows, nCols);

//返回的m_ppList是个二维字串数据，m_ppList[m][n]是个字串

free(m_ppList);
*/



struct tm GetDayTime(time_t time)
{
	struct tm * ptimeDetail;
	struct tm timeDetail;

	ptimeDetail = localtime(&time);
	memcpy(&timeDetail, ptimeDetail, sizeof(tm));

	return timeDetail;
}


CTestDataSource::CTestDataSource(char * fname)
{
	ReadStringArrayFromCsv(fname, m_ppList, m_iRows, m_iCols);
	
	m_iTtotalSize = (sizeof(int64_t) + sizeof(double) * 5) * m_iRows + 1024;
	m_pBuffer = new unsigned char[m_iTtotalSize];

	m_cRbk = new CRingBuffer((u8*)m_pBuffer, m_iTtotalSize);

	m_arDateArray = new int64_t[m_iRows];
	for (size_t i = 1; i < m_iRows; i++)
	{
		int64_t t = i; // 1450800000.0000000 + i * 10; // StringToDatetime(m_ppList[i][0]); //将字符串转换为tm时间  
		m_arDateArray[i - 1] = t;

		double d1 = atof(m_ppList[i][1]);
		double d2 = atof(m_ppList[i][2]);
		double d3 = atof(m_ppList[i][3]);
		double d4 = atof(m_ppList[i][4]);
		double d5 = atof(m_ppList[i][5]);

		m_cRbk->WriteInt64(t);
		m_cRbk->WriteDouble(d1);
		m_cRbk->WriteDouble(d2);
		m_cRbk->WriteDouble(d3);
		m_cRbk->WriteDouble(d4);
		m_cRbk->WriteDouble(d5);
	}
	/*
	m_cRbk->ResetPosition();

	for (size_t i = 1; i < m_iRows; i++)
	{
		int64_t t = 0;
		m_cRbk->ReadInt64(&t);
		struct tm tt = GetDayTime(t);
		//TRACE("add time key %d-%d-%d\n", tt.tm_year + 1900, tt.tm_mon + 1, tt.tm_mday);
		double d1 = 0;
		double d2 = 0;
		double d3 = 0;
		double d4 = 0;
		double d5 = 0;
		m_cRbk->ReadDouble(&d1);
		m_cRbk->ReadDouble(&d2);
		m_cRbk->ReadDouble(&d3);
		m_cRbk->ReadDouble(&d4);
		m_cRbk->ReadDouble(&d5);
	}
	*/
}


CTestDataSource::~CTestDataSource()
{
	free(m_ppList);
	delete m_pBuffer;
	delete m_cRbk;
	delete m_arDateArray;
}

unsigned char * CTestDataSource::GetBuffer(int64_t time)
{
	if (time== -1)
	{
		return m_pBuffer;
	}
	return NULL;
}