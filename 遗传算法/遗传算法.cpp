// 遗传算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "GeAlg.h"
#include "Chromosome.h"
#define random(x) (rand()%x)
void start()
{
	GeAlg *ga = new GeAlg(100, 0.2, 0.0001, 8);
	ga->calc();
	
	while (1)
	{
		
		//while (ga->size() - 100 > 0)
		//{
			//ga->select();
			ga->select();
			ga->calc();
		//}
		ga->print();
		ga->next_generation();
	}
}
int main()
{
	srand(time(0));
	start();
	return 0;
}

