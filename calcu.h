#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<sstream>
#include<stack>
using namespace std;
class equation
{
public:
	void print(int v, int c);//���ڽ�������
	int test(int total, char *p1);
	int generateExpression(int x);
	float calcusum(int a, int b, string sig);
	float calcusum_fra(float a, float b, string sig);
	string combine(string a, string b, string sign);
	string int_string(int number);
	void set_p(char *p1);
private:
	char *p;
	int wrong;
	int right;
};
class file
{
public:
	void boundary(equation &cp, char *p2);//���ڽ����ɽ�������ļ�
	int fileread(char *p1);//�����ļ���������Ŀ��ֵ
	void writefile(char *str, char *p);//д���ļ�
private:
	char *pr;//����ָ��
	int num;
	char *pw;//д��ָ��

};
class Random
{
public:
	virtual void random() {}//�����麯��
	Random() { tempf = 1; }
private:
	int tempf;
	string tempo;
};
class RandomNumber :public Random
{
public:
	void random();//������RandomNumber�ĸ���
	void get_n(int &a, int &b, int &c, int &d);
private:
	int tempa, tempb, tempc, tempd;

};
class RandomOperation :public Random
{
public:
	void random();//������RandomOperation�ĸ���
	void get_o(string &temp);
private:
	string tempo;
};