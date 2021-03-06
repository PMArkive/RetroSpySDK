///////////////////////////////////////////////////////////////////////////////
// File:	gpiBuffer.h
// SDK:		GameSpy Presence and Messaging SDK
//
// Copyright (c) IGN Entertainment, Inc.  All rights reserved.  
// This software is made available only pursuant to certain license terms offered
// by IGN or its subsidiary GameSpy Industries, Inc.  Unlicensed use or use in a 
// manner not expressly authorized by IGN or GameSpy is prohibited.

#ifndef _GPIBUFFER_H_
#define _GPIBUFFER_H_

//INCLUDES
//////////
#include "gpi.h"

//TYPES
///////
// A buffer.
////////////
typedef struct
{
	char * buffer;
	int size;
	int len;
	int pos;
} GPIBuffer;

typedef struct GPIPeer_s * GPIPeer_st;

//FUNCTIONS
///////////
GPResult
gpiAppendCharToBuffer(
  GPConnection * connection,
  GPIBuffer * outputBuffer,
  char c
);

GPResult
gpiAppendStringToBufferLen(
  GPConnection * connection,
  GPIBuffer * outputBuffer,
  const char * string,
  int stringLen
);

GPResult
gpiAppendStringToBuffer(
  GPConnection * connection,
  GPIBuffer * outputBuffer,
  const char * buffer
);

GPResult gpiAppendShortToBuffer(
	GPConnection * connection,
	GPIBuffer * outputBuffer, 
	short num
);

GPResult gpiAppendUShortToBuffer(
	GPConnection * connection,
	GPIBuffer * outputBuffer, 
	unsigned short num
);

GPResult
gpiAppendIntToBuffer(
  GPConnection * connection,
  GPIBuffer * outputBuffer,
  int num
);

GPResult
gpiAppendUIntToBuffer(
  GPConnection * connection,
  GPIBuffer * outputBuffer,
  unsigned int num
);

GPResult
gpiSendOrBufferChar(
  GPConnection * connection,
  GPIPeer_st peer,
  char c
);

/*
GPResult
gpiSendOrBufferStringLen(
  GPConnection * connection,
  GPIPeer_st peer,
  const char * string,
  int stringLen
);
*/
GPResult
gpiSendOrBufferStringLenToPeer(
	GPConnection * connection,
	GPIPeer_st peer,
	const char * string,
	int stringLen
);

GPResult
gpiSendOrBufferString(
  GPConnection * connection,
  GPIPeer_st peer,
  char * string
);

GPResult
gpiSendOrBufferInt(
  GPConnection * connection,
  GPIPeer_st peer,
  int num
);

GPResult
gpiSendOrBufferUInt(
  GPConnection * connection,
  GPIPeer_st peer,
  unsigned int num
);

GPResult
gpiSendFromBuffer(
  GPConnection * connection,
  SOCKET sock,
  GPIBuffer * outputBuffer,
  GPIBool * connClosed,
  GPIBool clipSentData,
  char id[3]
);

GPResult
gpiRecvToBuffer(
  GPConnection * connection,
  SOCKET sock,
  GPIBuffer * inputBuffer,
  int * bytesRead,
  GPIBool * connClosed,
  char id[3]
);

GPResult
gpiReadMessageFromBuffer(
  GPConnection * connection,
  GPIBuffer * inputBuffer,
  char ** message,
  int * type,
  int * len
);

GPResult
gpiClipBufferToPosition(
  GPConnection * connection,
  GPIBuffer * buffer
);

GPResult gpiSendBufferToPeer(GPConnection * connection, unsigned int ip, unsigned short port, 
							 GPIBuffer * outputBuffer, GPIBool *closed, GPIBool clipSentData);
#endif
