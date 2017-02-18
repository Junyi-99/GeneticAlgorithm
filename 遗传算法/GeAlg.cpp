#include "stdafx.h"
#include "GeAlg.h"
#include <cmath>

void GeAlg::next_generation()
{
	generation++;

	int rand_pos1 = random(pop.size());
	int rand_pos2 = random(pop.size());
	if (rand_pos1 == rand_pos2)
		rand_pos2++;

	Chromosome father = best_one;
	Chromosome mother = best_one;
	/*Chromosome child1, child2;
	for(int i=0; i<father.gene_length/2; i++)
	{
	child1.gene[i] = father.gene[i];
	child2.gene[i] = mother.gene[i];
	}
	for(int i=mother.gene_length; i<mother.gene_length; i++)
	{
	child1.gene[i] = mother.gene[i];
	child2.gene[i] = father.gene[i];
	}*/
	double mut_rand = (double)random(100) / 100.0;
	if (mut_rand > mutation)
	{
		father.mutation(father, mutation_max_step);
	}
	mut_rand = (double)random(100) / 100.0;
	if (mut_rand > mutation)
	{
		mother.mutation(mother, mutation_max_step);
	}


	pop.push_back(father);
	//pop.push_back(mother);
	//pop.push_back(child1);
	//pop.push_back(child2);
}

void GeAlg::select()
{
	int slice = random((int)total_fitness);
	double fitness = 0;
	for (vector<Chromosome>::iterator it = pop.begin(); it != pop.end(); it++)
	{
		fitness += it->fitness;
		if (fitness > slice)
		{
			pop.erase(it);
			break;
		}
	}
}
void GeAlg::calc()
{
	best_fitness = 99999;
	total_fitness = 0;
	worst_fitness = 0;
	best_one = Chromosome();
	for (size_t i = 0; i<pop.size(); i++)
	{
		pop[i].fitness = calc_fitness(pop[i].decode());
		total_fitness += pop[i].fitness;
		if (pop[i].fitness < best_fitness)
		{
			best_fitness = pop[i].fitness;
			best_one = pop[i];
		}
		if (pop[i].fitness > worst_fitness)
		{
			worst_fitness = pop[i].fitness;
		}
	}
	average_fitness = total_fitness / pop.size();
}

double GeAlg::calc_fitness(std::vector<unsigned char> decoded)
{
	//unsigned char text[] = "Hello world! I am fine thank you and you???";
	unsigned char text[] = "The quick brown fox jumps over the lazy dog";
	double fitness = 0;
	for (size_t i = 0; i<decoded.size(); i++)
	{
		fitness += std::abs(decoded[i] - text[i]);
	}
	return fitness;
}

GeAlg::GeAlg(int size, double mutation, double crossover, int mutation_max_step) {
	// TODO Auto-generated constructor stub
	this->total_fitness = 0;
	this->best_fitness = 0;
	this->average_fitness = 0;
	this->worst_fitness = 999999;
	this->mutation = mutation;
	this->mutation_max_step = mutation_max_step;
	this->crossover = crossover;
	this->generation = 0;
	pop.clear();
	for (int i = 0; i<size; i++)
	{
		pop.push_back(Chromosome());
	}
}

GeAlg::~GeAlg() {
	// TODO Auto-generated destructor stub
}

