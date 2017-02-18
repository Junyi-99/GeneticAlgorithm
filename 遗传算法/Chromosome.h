#pragma once
#ifndef Chromosome_H_
#define Chromosome_H_
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#define GENE_LENGTH 344
#define random(x) (rand()%x)
using namespace std;
class Chromosome {
public:
	bool gene[GENE_LENGTH];
	size_t gene_length;
	Chromosome()
	{
		for (int i = 0; i<344; i++)
		{
			gene[i] = random(2);
		}
		gene_length = GENE_LENGTH;
		fitness = 999;
	}
	int getGeneLength()
	{
		return GENE_LENGTH;
	}
	void mutation(Chromosome &chrom, int mutation_max_step)
	{
		int mut_pos = 0;
		int mut_num = 0;
		mut_pos = random(chrom.getGeneLength());
		mut_num = random(mutation_max_step);
		if ((unsigned int)(mut_pos + mut_num) > chrom.gene_length)
		{
			for (int i = mut_pos + mut_num; i>mut_pos; i--)
			{
				chrom.gene[i] = !chrom.gene[i];
			}
		}
		else
		{
			for (int i = mut_pos; i<mut_pos + mut_num; i++)
			{
				chrom.gene[i] = !chrom.gene[i];
			}
		}

	}
	void crossover(Chromosome &chrom1, Chromosome &chrom2)
	{
		int rand_pos = 0;
		int rand_num = 0;

		rand_pos = random(chrom1.gene_length); // 发生交叉互换的位置
		rand_num = random(32); // 交叉互换的基因片段长度

		bool type = 0; // 0 - 向后交叉; 1 - 向前交叉
		if ((unsigned int)(rand_pos + rand_num) > chrom1.gene_length)
			type = 1;

		bool tempA = 0, tempB = 0, tempC = 0;
		if (type == 0)
			for (int i = rand_pos; i<rand_pos + rand_num; i++)
			{
				tempA = chrom1.gene[i];
				tempB = chrom2.gene[i];
				tempC = tempA;
				tempA = tempB;
				tempB = tempC;
			}
		else
			for (int i = rand_pos + rand_num; i>rand_pos; i--)
			{
				tempA = chrom1.gene[i];
				tempB = chrom2.gene[i];
				tempC = tempA;
				tempA = tempB;
				tempB = tempC;
			}
	}
	std::vector<unsigned char> decode()
	{
		// 8 bit
		std::vector<unsigned char> result;
		for (unsigned int i = 0; i<(GENE_LENGTH / 8); i++)
		{
			bool a[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
			for (int j = 0; j<8; j++)
				a[j] = gene[i * 8 + j];

			result.push_back(bin2dec(a, 8));
		}
		return result;
	}
	virtual ~Chromosome();
	double fitness;
private:
	int bin2dec(bool a[], int a_length)
	{
		int result = 0;
		for (int i = a_length - 1; i >= 0; i--)
		{
			if (a[i])
				result += pow(2, i - 1);
		}
		return result;
	}
	// The quick brown fox jumps over the lazy dog

};

#endif /* Chromosome_H_ */
