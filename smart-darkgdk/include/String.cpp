#include "String.h"
#include "DarkGDK.h"

String::String(void)
{
}
String::~String(void)
{
}

void String::draw(int x,int y,char* string)
{
	dbText(x,y,string);
}
void String::draw3D(char* string)
{
	dbText3D(string);
}

void String::setColor(int alpha,int r,int g,int b)
{
	dbSetTextColor(alpha,r,g,b);
}

void String::setFont(char* typeface)
{
	dbSetTextFont(typeface);
}

void String::setOpaque()
{
	dbSetTextOpaque();
}

void String::setSize(int size)
{
	dbSetTextSize(size);
}

void String::setToBold()
{
	dbSetTextToBold();
}

void String::setToBoldItalic()
{
	dbSetTextToBoldItalic();
}

void String::setToItalic()
{
	dbSetTextToItalic();
}

void String::setToNormal()
{
	dbSetTextToNormal();
}

void String::setToOpaque()
{
	dbSetTextToOpaque();
}

void String::setToTransparent()
{
	dbSetTextToTransparent();
}

void String::setTransparent()
{
	dbSetTextTransparent();
}

char* String::convert(int v)
{
	return dbStr(v);
}
char* String::convert(float v)
{
	return dbStr(v);
}

int String::ascii(char * c)
{
	return dbAsc(c);
}
char* String::bin(int v)
{
	return dbBin(v);
}
char* String::chr(int ascii)
{
	return dbChr(ascii);
}
char* String::hex(int i)
{
	return dbHex(i);
}
char* String::left(char* c,int offset)
{
	return dbLeft(c,offset);
}
int String::length(char* string)
{
	return dbLen(string);
}
char* String::toLower(char* string)
{
	return dbLower(string);
}
char* String::toUpper(char* string)
{
	return dbUpper(string);
}
char* String::mid(char* string,int q)
{
	return dbMid(string,q);
}
char* String::right(char* c,int offset)
{
	return dbRight(c,offset);
}
float String::toFloat(char* c)
{
	return dbVal(c);
}
char* String::spaces(int num)
{
	return dbSpaces(num);
}