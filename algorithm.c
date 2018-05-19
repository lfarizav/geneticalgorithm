/*
 Coded by Luis Felipe Ariza Vesga
 Universidad Nacional de Colombia
 EURECOM
 2017
 lfarizav@unal.edu.co, ariza@eurecom.fr
 ('    .-. .-. .-. .-.   .--.   .-.
 ('    | } { | |  \{ |  / {} \  } |
 ('    \ `-' / | }\  { /  /\  \ } '--.
 ('     `---'  `-' `-' `-'  `-' `----'
 ('    ,----, ,-, ,-. ,---.  .----. .----.  .---.  .-.  .-.
 ('    } |__} | } { | } }}_} } |__} | }`-' / {-. \ }  \/  {
 ('    } '__} \ `-' / | } \  } '__} | },-. \ '-} / | {  } |
 ('    `----'  `---'  `-'-'  `----' `----'  `---'  `-'  `-'
 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
//#include "SIMULATION/TOOLS/xxx.h" user xxx.h file
#include"algorithm.h"
//define constant values
    
    /* GA parameters */
     static  double uniformRate = 0.5;
     static  double mutationRate = 0.015;
     static  int tournamentSize = 5;
     static  int elitism = 1;


    /* Public methods */
 
    // Evolve a population
    void evolvePopulation(struct population* populationPtr,struct population* newpopulationPtr,struct population* tournamentPtr,struct population* crossoverpopulationPtr,char OneElementePopulation[], int sizetournament, unsigned int elitism) {
        
        // Keep our best individual
        if (elitism) {
            saveIndividual(populationPtr,newpopulationPtr,populationPtr->fittest,0);
        }
        
        // Crossover population
        int elitismOffset;
        if (elitism) {
            elitismOffset = 1;
	    //printf("elitismOffset is%d\n",elitismOffset);
        } else {
            elitismOffset = 0;
	    //printf("elitismOffset is%d\n",elitismOffset);
        }
        // Loop over the population size and create new individuals with
        // crossover
        int i;

        for (i = elitismOffset; i < newpopulationPtr->defaultPopulationSize; i++) {
            
	    
	    crossoverpopulationPtr->individuals[0]=tournamentPtr->individuals[tournamentSelection(populationPtr,tournamentPtr,OneElementePopulation,sizetournament)];
	    
	    crossoverpopulationPtr->individuals[1]=tournamentPtr->individuals[tournamentSelection(populationPtr,tournamentPtr,OneElementePopulation,sizetournament)];

            crossover(crossoverpopulationPtr,crossoverpopulationPtr, 0, 1);

            saveIndividual(crossoverpopulationPtr,newpopulationPtr, 2, i);
        }
        
        // Mutate population
        for (i = elitismOffset; i < newpopulationPtr->defaultPopulationSize; i++) {
            mutate(newpopulationPtr,i);
        }
	getFitnessPopulation(newpopulationPtr,OneElementePopulation);
    }

    // Crossover individuals
    void crossover(struct population* populationPtr, struct population* crossoverpopulationPtr, unsigned int firstlocation, unsigned int secondlocation) {
	int seed = time(0);
	unsigned int randomtemp,uniformraterandmax;
        srand(seed*rand());
        // Loop through genes
	crossoverpopulationPtr->individuals[0]=populationPtr->individuals[firstlocation];
 	crossoverpopulationPtr->individuals[1]=populationPtr->individuals[secondlocation];
	uniformraterandmax=uniformRate*RAND_MAX;
        int i;
        for (i = 0; i < populationPtr->defaultGeneLength; i++) {
            // Crossover
		randomtemp=rand();
            if (randomtemp <= uniformraterandmax){
		//printf("gen from individual first location %c\n",populationPtr->individuals[firstlocation][i]);
                 crossoverpopulationPtr->individuals[2][i]=populationPtr->individuals[firstlocation][i];
}
	    else {
                crossoverpopulationPtr->individuals[2][i]=populationPtr->individuals[secondlocation][i];
		//printf("gen from individual second location %c\n",populationPtr->individuals[secondlocation][i]);
}

        }
//printf("\n");
//for (i = 0; i < populationPtr->defaultGeneLength; i++) {
//		printf("%c",crossoverpopulationPtr->individuals[2][i]);
//}
//printf("\n");

    }
    
    // Mutate an individual
    void mutate(struct population* populationPtr, unsigned int individualLocation) {
	//printf("Mutation\n");
        // Loop through genes
        int i;
        int seed = time(0);
        srand(seed*rand());
	unsigned int randomlocation, randmaxmutation=RAND_MAX*mutationRate;
        for (i = 0; i < populationPtr->defaultGeneLength; i++) {
        
        randomlocation=rand();
	//printf("rand: %d, rand_max: %d, randmax*mutation%d\n",randomlocation,RAND_MAX,randmaxmutation);
            if (randomlocation <= randmaxmutation) {
                 //printf("rand i is %d\n",i);
                // Create random gene
                if(populationPtr->individuals[individualLocation][i]=='1')
                    populationPtr->individuals[individualLocation][i]='0';
                else
                    populationPtr->individuals[individualLocation][i]='1';
                    }
        }

    }

    // Select individuals for crossover
    int tournamentSelection(struct population* populationPtr, struct population* tournamentPtr, char OneElementePopulation[], int sizetournament) {
        // Create a tournament population
        // For each place in the tournament get a random individual
        int i;
        unsigned int randomlocation;
        int seed = time(0);
        srand(seed*rand());
	//printf("Tournament selection\n");
        for (i = 0; i < sizetournament; i++) {
            randomlocation=rand();
            //printf("Randomlocation is %d\n",randomlocation*tournamentPtr->defaultPopulationSize/RAND_MAX);
            saveIndividual(populationPtr,tournamentPtr,randomlocation*tournamentPtr->defaultPopulationSize/RAND_MAX,i);
        }
        // Get the fittest
        getFitnessPopulation(tournamentPtr,OneElementePopulation);
	//printf("Tournament population is \n");
        return tournamentPtr->fittest;
}
   void transferdatapopulation(struct population* populationsrcPtr,struct population* populationdstPtr){
	int i,j;

	for(i=0;i<populationsrcPtr->defaultPopulationSize;i++){
		populationdstPtr->individuals[i]=populationsrcPtr->individuals[i];
		populationdstPtr->fitness[i]=populationsrcPtr->fitness[i];

	}

}
