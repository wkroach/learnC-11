#pragma once
#define NDEBUG
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<initializer_list>
using namespace std;

void Problem6_22(int**, int**);
void Problem6_22(int*&, int*&);

void Problem6_24(const int ia[10]);

int & Problem6_32(int * arry, int index);


string(&Problem6_36(int i))[5];
auto Problem6_37(int i)->string(&)[5];
int Problem6_54(int a, int b);
int Problem6_55(int a, int b);
int Problem6_56(int a, int b);
int Problem6_57(int a, int b);
void Problem6_58();
void Problem6_47(const vector<int>& arr, int depth);