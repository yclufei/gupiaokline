#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>


#define u32 uint32_t
#define u8 char

class CRingBuffer
{
public:
	CRingBuffer(u8* buffer, int len );
	CRingBuffer(u8* buffer,int val, int len);
	~CRingBuffer();

	int WirteRingbuffer(u8* buffer, u32 addLen);
	int ReadRingbuffer(u8* buffer, u32 len);

	int WriteDouble(double a);
	int ReadDouble(double * a);

	int WriteBool(bool a);
	int ReadBool(bool * a);

	int WriteFloat(float a);
	int ReadFloat(float * a);

	int WriteInt32(int32_t a);
	int ReadInt32(int32_t * a);

	int WriteInt64(int64_t a);
	int ReadInt64(int64_t * a);

	int WriteString(char * a);
	char * ReadString();

	int WriteFixString(char * a,int len = 64);
	char * ReadFixString( int len = 64);

	void IncReadPosition(int pos);

	u32 GetRingbufferValidLen(void);
	u8 * GetBuffer();

	void ResetPosition();
private:
	int BUFFER_SIZE;
	u32 validLen;//��ʹ�õ����ݳ���
	u8* pHead;//���δ洢�����׵�ַ
	u8* pTail;//���δ洢���Ľ�β��ַ
	u8* pValid;//��ʹ�õĻ��������׵�ַ
	u8* pValidTail;//��ʹ�õĻ�������β��ַ
};

