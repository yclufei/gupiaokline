#include "stdafx.h"
#include "CRingBuffer.h"


CRingBuffer::CRingBuffer(u8* buffer,int len)
{
	BUFFER_SIZE = len;
	pHead = buffer;
	pValid = pValidTail = pHead;
	pTail = pHead + BUFFER_SIZE;
	validLen = 0;
}


CRingBuffer::CRingBuffer(u8* buffer, int val, int len )
{
	BUFFER_SIZE = len;
	pHead = buffer;
	pValid = pHead;
	pValidTail = pHead + BUFFER_SIZE;
	pTail = pHead + BUFFER_SIZE;
	validLen = BUFFER_SIZE;
}

void CRingBuffer::ResetPosition()
{
	pValid = pHead;
	pValidTail = pHead + BUFFER_SIZE;
	pTail = pHead + BUFFER_SIZE;
	validLen = BUFFER_SIZE;
}

CRingBuffer::~CRingBuffer()
{
	pHead = NULL;
}

int CRingBuffer::WirteRingbuffer(u8* buffer, u32 addLen)
{
	if (addLen > BUFFER_SIZE) 
		return -2;
	if (pHead == NULL)
		return -1;
	assert(buffer);
	//��Ҫ���������copy��pValidTail��
	if (pValidTail + addLen > pTail)//��Ҫ�ֳ�����copy
	{
		int len1 = pTail - pValidTail;
		int len2 = addLen - len1;
		memcpy(pValidTail, buffer, len1);
		memcpy(pHead, buffer + len1, len2);
		pValidTail = pHead + len2;//�µ���Ч��������βָ��
	}
	else
	{
		memcpy(pValidTail, buffer, addLen);
		pValidTail += addLen;//�µ���Ч��������βָ��
	}
	//�����¼�����ʹ��������ʼλ��
	if (validLen + addLen > BUFFER_SIZE)
	{
		int moveLen = validLen + addLen - BUFFER_SIZE;//��Чָ�뽫Ҫ�ƶ��ĳ���
		if (pValid + moveLen > pTail)//��Ҫ�ֳ����μ���
		{
			int len1 = pTail - pValid;
			int len2 = moveLen - len1;
			pValid = pHead + len2;
		}
		else
		{
			pValid = pValid + moveLen;
		}
		validLen = BUFFER_SIZE;
	}
	else
	{
		validLen += addLen;
	}
	return 0;
}

int CRingBuffer::ReadRingbuffer(u8* buffer, u32 len)
{
	if (pHead == NULL) return -1;
	assert(buffer);
	if (validLen == 0) return 0;
	if (len > validLen) 
		len = validLen;
	if (pValid + len > pTail)//��Ҫ�ֳ�����copy
	{
		int len1 = pTail - pValid;
		int len2 = len - len1;
		memcpy(buffer, pValid, len1);//��һ��
		memcpy(buffer + len1, pHead, len2);//�ڶ��Σ��Ƶ������洢���Ŀ�ͷ
		pValid = pHead + len2;//������ʹ�û���������ʼ
	}
	else
	{
		memcpy(buffer, pValid, len);
		pValid = pValid + len;//������ʹ�û���������ʼ
	}
	validLen -= len;//������ʹ�û������ĳ���
	return len;
}

void CRingBuffer::IncReadPosition(int len)
{
	pValid = pValid + len;//������ʹ�û���������ʼ
	validLen -= len;//������ʹ�û������ĳ���
}
/*
* function:��ȡ��ʹ�û������ĳ���
* return  :��ʹ�õ�buffer����
* */
u32 CRingBuffer::GetRingbufferValidLen(void)
{
	return validLen;
}

u8 * CRingBuffer::GetBuffer()
{
	return pHead;
}


int CRingBuffer::WriteDouble(double a)
{
	return WirteRingbuffer((u8*)&a, sizeof(double));
}
int CRingBuffer::ReadDouble(double * a)
{
	return ReadRingbuffer((u8*)a, sizeof(double));
}

int CRingBuffer::WriteBool(bool a)
{
	return WirteRingbuffer((u8*)&a, sizeof(bool));
}
int CRingBuffer::ReadBool(bool * a)
{
	return ReadRingbuffer((u8*)a, sizeof(bool));
}

int CRingBuffer::WriteFloat(float a)
{
	return WirteRingbuffer((u8*)&a, sizeof(float));
}
int CRingBuffer::ReadFloat(float * a)
{
	return ReadRingbuffer((u8*)a, sizeof(float));
}

int CRingBuffer::WriteInt32(int32_t a)
{
	return WirteRingbuffer((u8*)&a, sizeof(int32_t));
}
int CRingBuffer::ReadInt32(int32_t * a)
{
	return ReadRingbuffer((u8*)a, sizeof(int32_t));
}

int CRingBuffer::WriteInt64(int64_t a)
{
	return WirteRingbuffer((u8*)&a, sizeof(int64_t));
}
int CRingBuffer::ReadInt64(int64_t * a)
{
	return ReadRingbuffer((u8*)a, sizeof(int64_t));
}



int CRingBuffer::WriteString(char * b)
{
	int len = strlen(b);
	int ret = WirteRingbuffer((u8*)&len, sizeof(int));
	ret += WirteRingbuffer((u8*)b, len);
	return ret;
}
char * CRingBuffer::ReadString()
{
	char * a = NULL;
	int len = 0;
	int ret = ReadRingbuffer((u8*)&len, sizeof(int));
	a = new char[len + 2];
	ret += ReadRingbuffer((u8*)a, len);
	a[len] = 0;
	return a;
}



int CRingBuffer::WriteFixString(char * a,int len)
{
	int srclen = strlen(a);
	if (srclen>len || srclen>1024)
	{
		TRACE("WriteFixString Error %d > %d\n", srclen, len);
		return 0;
	}
	char tmpstr[1024];
	tmpstr[0] = 0;
	if (srclen>0)
	{
		strcpy(tmpstr, a);
	}
	int ret = WirteRingbuffer((u8*)tmpstr, len);
	return ret;
}
char * CRingBuffer::ReadFixString(int len)
{
	char * tmp = new char[len + 1];
	ReadRingbuffer((u8*)tmp, len);
	return tmp;
}