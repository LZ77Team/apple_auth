#ifndef ITUNESINTERFACE_H_
#define ITUNESINTERFACE_H_

#include <Windows.h>

//��֤RQ��RQ.SIG�ļ�
DWORD VerifyAfsyncRq(DWORD dwGrappaSessionId, 
	unsigned char* pszRq, 
	DWORD dwSizeRq, 
	unsigned char* pszRqSig, 
	DWORD dwSizeRqSig);

//����PrivateKey
DWORD GeneratePrivateKey(DWORD dwKbsyncId, 
	unsigned char* pszFairPlayCertificate, 
	DWORD dwFairPlayCertificateSize, 
	PVOID lpFairPlayGUID, //0x14
	INT64* pdwFairPlayDeviceTypeAndKeyType,//0x65
	DWORD dwType,//1
	DWORD* pdwPrivateKey);

//��PrivateKey��RQ�ļ�
DWORD SetAfSyncRq(DWORD dwPrivateKey, 
	const char* pszRqData, 
	DWORD dwRqSize, 
	const char* pszICInfoData, //0
	DWORD dwICInfoSize);//0

//����RQ�ļ�
DWORD ParseAfsyncRq(DWORD dwMod, //0
	PVOID lpFairPlayGUID,
	DWORD dwFairPlayDeviceType,
	const char* pszRqData, 
	DWORD dwRqSize,
	const char** ppszDisdList, 
	DWORD* pdwDisdCount);

//����APPID�˺�
DWORD AuthKeyByDSID(DWORD dwPrivateKey, 
	DWORD dwDsidLow, 
	DWORD dwDsidHigh, 
	DWORD dwUnkVaule/*0, 1*/,
	DWORD dwUnkVaule2/*0*/);

//����RS�ļ�
DWORD GenerateAfSyncRs(DWORD dwPrivateKey, 
	const char** ppszRsData, 
	DWORD* pdwRsSize, 
	const char** ppszICInfoData, 
	DWORD* pdwICInfoSize);

DWORD CalcHashSig(DWORD nGrappaSessionId,char* pInputBuf, DWORD nInputBufSize,
	char** ppOutputBuf, DWORD* pOutputBufSize);

DWORD GetSCInfoPath(char* Path);
DWORD GetKbsync_ID(char* path,DWORD UNKNOW1,DWORD UNKNOW2,DWORD UNKNOW3,DWORD* pdwKbsyncID);
DWORD GetKbsyncID(char* path,DWORD* pdwKbsyncID);


//ios8 iTunes.dll version 12.0.1.26

//��֤RQ��RQ.SIG�ļ�
DWORD VerifyAfsyncRq_8(DWORD dwGrappaSessionId, 
	unsigned char* pszRq, 
	DWORD dwSizeRq, 
	unsigned char* pszRqSig, 
	DWORD dwSizeRqSig);

//����PrivateKey
DWORD GeneratePrivateKey_8(DWORD dwKbsyncId, 
	unsigned char* pszFairPlayCertificate, 
	DWORD dwFairPlayCertificateSize, 
	PVOID lpFairPlayGUID, //0x14
	INT64* pdwFairPlayDeviceTypeAndKeyType,//0x65
	DWORD dwType,//1
	DWORD* pdwPrivateKey);

//��PrivateKey��RQ�ļ�
DWORD SetAfSyncRq_8(DWORD dwPrivateKey, 
	const char* pszRqData, 
	DWORD dwRqSize, 
	const char* pszICInfoData, //0
	DWORD dwICInfoSize);//0


//����RQ�ļ�
DWORD ParseAfsyncRq_8(DWORD dwMod, //0
	PVOID lpFairPlayGUID,
	DWORD dwFairPlayDeviceType,
	const char* pszRqData, 
	DWORD dwRqSize,
	const char** ppszDisdList, 
	DWORD* pdwDisdCount);

//����APPID�˺�
DWORD AuthKeyByDSID_8(DWORD dwPrivateKey, 
	DWORD dwDsidLow, 
	DWORD dwDsidHigh, 
	DWORD dwUnkVaule/*0, 1*/,
	DWORD dwUnkVaule2/*0*/);

//����RS�ļ�
DWORD GenerateAfSyncRs_8(DWORD dwPrivateKey, 
	const char** ppszRsData, 
	DWORD* pdwRsSize, 
	const char** ppszICInfoData, 
	DWORD* pdwICInfoSize);

DWORD CalcHashSig_8(DWORD nGrappaSessionId,char* pInputBuf, DWORD nInputBufSize,
	char** ppOutputBuf, DWORD* pOutputBufSize);

DWORD GetSCInfoPath_8(char* Path);
DWORD GetKbsyncID_8(char* path,DWORD* pdwKbsyncID);


DWORD GenerateKbsyncID(DWORD lpfnKbsyncID, const char* all_pc_md5, const char* local_pc_md5);

#endif