#ifndef _SERVER_TEST_1203_H_
#define _SERVER_TEST_1203_H_


#define MAXBUF 256

// clear array
void cleararr(char buf[]);
// int to ascii
void _itoa(int val, int base, char *arr);
// ascii to int
int _atoi(char* str);
// 
void parsing(char* buf,char* x,char* y,char* z);
//
void scaledata(char* arr);
//
void clickMouse(int _d);
//
void MoveMouse(char* x,char* y);

#endif
