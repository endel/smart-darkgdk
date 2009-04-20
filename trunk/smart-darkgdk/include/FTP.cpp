#include "FTP.h"
#include "DarkGDK.h"

FTP::FTP(void)
{
}

FTP::~FTP(void)
{
}

//setters
void FTP::connect(char* UrlString, char* UserString, char* PasswordString)
{
	
}
void FTP::disconnect()
{
}
void FTP::terminate()
{
}
void FTP::setDir(char* DirectoryString)
{
}
void FTP::putFile(char* FtpFilenameString)
{
}
void FTP::deleteFile()
{
}
void FTP::proceed()
{
}
void FTP::findFirst()
{
}
void FTP::findNext()
{
}

//getters
int FTP::getStatus()
{
	return dbGetFTPStatus();
}
char* FTP::getDir()
{
	return dbGetFTPDir();
}
int FTP::getProgress()
{
	return dbGetFTPProgress();
}
bool FTP::getFailure()
{
	return dbGetFTPFailure();
}
int FTP::getFileType()
{
	return dbGetFTPFileType();
}
char* FTP::getFileName()
{
	return dbGetFTPFileName();
}
int FTP::getFileSize()
{
	return dbGetFTPFileSize();
}