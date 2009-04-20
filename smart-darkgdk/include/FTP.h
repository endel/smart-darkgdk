#pragma once

class FTP
{
public:
	FTP(void);
	~FTP(void);
	
	//setters
	static void connect(char* UrlString, char* UserString, char* PasswordString);
	static void disconnect();
	static void terminate();
	static void setDir(char* DirectoryString);
	static void putFile(char* FtpFilenameString);
	static void deleteFile();
	static void proceed();
	static void findFirst();
	static void findNext();
	
	//getters
	static int getStatus();
	static char* getDir();
	static int getProgress();
	static bool getFailure();
	static int getFileType();
	static char* getFileName();
	static int getFileSize();

};