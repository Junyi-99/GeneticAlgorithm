#pragma once
#ifndef GEALG_H_
#define GEALG_H_
#include <vector>
#include <iostream>
#include "Chromosome.h"
using namespace std;
class GeAlg {
public:
	void select(); // 自然选择
	void fitness(); // 生物竞争
	void next_generation(); // 产生下一代
	void calc();
	int size() const { return pop.size(); }
	void print()
	{
		unsigned char a[100] = { 0 };
		vector<unsigned char> decode = best_one.decode();
		for (size_t i = 0; i<decode.size(); i++)
		{
			a[i] = decode[i];
		}
		cout << "进化代数:" << generation << " 适应度:" << best_fitness << " 表现型：" << a << endl;
	}
	GeAlg(int size, double mutation, double crossover, int mutation_max_step);
	virtual ~GeAlg();
private:
	double calc_fitness(std::vector<unsigned char> decoded);
	double total_fitness;// 种群总适应度（所有个体适应度的和）
	double best_fitness;// 最适应个体的适应度
	Chromosome best_one;// 最好的个体的基因
	double average_fitness;// 平均适应度
	double worst_fitness;// 最坏的个体
	double mutation;// 突变率
	int mutation_max_step;// 最多突变多少基因
	double crossover;// 交叉互换率
	int generation;// 进化代数
	std::vector<Chromosome> pop;
};

#endif /* GEALG_H_ */

