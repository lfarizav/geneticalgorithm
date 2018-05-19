/* 
 *Coded by Luis Felipe Ariza Vesga
 *Universidad Nacional de Colombia
 *EURECOM
 *2017
 *lfarizav@unal.edu.co, ariza@eurecom.fr
 *('    .-. .-. .-. .-.   .--.   .-.                
 *('    | } { | |  \{ |  / {} \  } |                        
 *('    \ `-' / | }\  { /  /\  \ } '--.                     
 *('     `---'  `-' `-' `-'  `-' `----'                     
 *('    ,----, ,-, ,-. ,---.  .----. .----.  .---.  .-.  .-.    
 *('    } |__} | } { | } }}_} } |__} | }`-' / {-. \ }  \/  {    
 *('    } '__} \ `-' / | } \  } '__} | },-. \ '-} / | {  } |    
 *('    `----'  `---'  `-'-'  `----' `----'  `---'  `-'  `-' 
 */

#include <math.h> 
#include <stdlib.h>
#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <stdbool.h>
//#include "SIMULATION/TOOLS/xxx.h" user xxx.h file
//#include"individual.h"
#include"population.h"

    /*sizeof(indiv.genes)/sizeof(indiv.genes[0]
     * Constructors
     */
    // Create a population
     void generatePopulation(struct population* populationPtr,char OneElementPopulation[],unsigned long sizepopulation, unsigned long sizeindividual, unsigned int initialise) {
        int i;        
        struct individual tempindiv,temponeindividual, *tempindivPtr, *temponeindividualPtr;
        tempindivPtr=&tempindiv;
	temponeindividualPtr=&temponeindividual;
	init_individual(temponeindividualPtr,sizeindividual);
	temponeindividualPtr->genes=OneElementPopulation;
        init_population(populationPtr,sizepopulation,sizeindividual);
       if (initialise) {
            //printf("the value of initialise is :%d\n",initialise);
            // Loop and create population
            for (i = 0; i <sizepopulation ; i++) {
                //printf("the value of i is :%d\n",i);
                //Individual newIndividual = new Individual();
                generateIndividual(tempindivPtr,temponeindividualPtr,sizeindividual);
                populationPtr->individuals[i]=tempindivPtr->genes;
                populationPtr->fitness[i]=0;
            }
        }
       else {
           //printf("the value of initialise is :%d\n",initialise);
           // Loop and create population
           for (i = 0; i <populationPtr->defaultPopulationSize ; i++) {
               //printf("the value of i is :%d\n",i);
               //Individual newIndividual = new Individual();
               generateIndividualZero(tempindivPtr,temponeindividualPtr,sizeindividual);
               populationPtr->individuals[i]=tempindivPtr->genes;
               populationPtr->fitness[i]=0;
           }
       }
    getFitnessPopulation(populationPtr,OneElementPopulation);
    }

void toStringPopulation(struct population* populationPtr) {
    int i,j;
    printf("\nPopulation is:\n");
    for (i = 0; i<populationPtr->defaultPopulationSize; i++) {
        for (j=0; j<populationPtr->defaultGeneLength; j++) {
            
        
            printf("%c",populationPtr->individuals[i][j]);
        }
        printf("\n");
    }
	printf("\nFitness values are:\n");
	for (i = 0; i<populationPtr->defaultPopulationSize; i++) {   
            printf("%d\n",(int)populationPtr->fitness[i]);
    }
    getFittest(populationPtr);
}
    void init_population(struct population* populationPtr,unsigned long sizepopulation, unsigned long sizeindividual){
	populationPtr->defaultPopulationSize=sizepopulation;
	populationPtr->defaultGeneLength=sizeindividual;
    populationPtr->fittest= 0;
	populationPtr->individuals = (char**)malloc(sizepopulation *  sizeof(char*));
	populationPtr->fitness= (unsigned long*)malloc(sizepopulation*sizeof(unsigned long));
    populationPtr->randomindividual= (char*)malloc(sizeindividual*sizeof(char));
	//printf("defaultPopulationSize %d\n",populationPtr->defaultPopulationSize=sizepopulation);
    //printf("defaultGeneLength %d\n",populationPtr->defaultGeneLength=sizeindividual);
}
    /* Getters */
    //struct individual getIndividual(struct population population, int index) {
    //    return population.population[index];
    //}

    void getFittest(struct population* populationPtr) {
        int i;
        // Loop through population to find fittest
        for (i = 0; i < populationPtr->defaultPopulationSize; i++) {
            if (populationPtr->fitness[i]>=populationPtr->fitness[populationPtr->fittest]) {
                populationPtr->fittest = i;
            }
            
        }
        //printf("The location of the fittest is %d\n",(int)populationPtr->fittest);
    }
 
    /* Public methods */
    // Get population size
    //int sizepopulation(struct population population) {
    //    return sizeof(population.population)/sizeof(population.population[0]);
    //}

    // Save individual
    void saveIndividual(struct population* populationPtr,struct population* newpopulationPtr, unsigned int locationIndividualSource, unsigned int locationIndividualDestination) {
        int i;
        for (i=0;i<populationPtr->defaultGeneLength;i++){
            newpopulationPtr->individuals[locationIndividualDestination][i]=populationPtr->individuals[locationIndividualSource][i];
        }
        //toStringPopulation(populationPtr);
        //toStringPopulation(newpopulationPtr);
}

// Calculate inidividuals fittness by comparing it to our candidate solution
void getFitnessPopulation(struct population* populationPtr, char OneElementPopulation[]) {
    int i,j;
    unsigned long fitness;
    //printf("The defaultGeneLength is %d\n",populationPtr->defaultGeneLength);
    //printf("The defaultPopulationSize is %d\n",populationPtr->defaultPopulationSize);
    for(i=0;i<populationPtr->defaultPopulationSize;i++){
        fitness = 0;
        // Loop through our individuals genes and compare them to our cadidates
        for (j = 0; j < populationPtr->defaultGeneLength; j++) {
            //printf("individual is %c random is %c\n",populationPtr->individuals[i][j],crossoverpopulationPtr[j]);
		//printf("one element %d is %c\n",j,OneElementPopulation[j]);
            if (populationPtr->individuals[i][j] == OneElementPopulation[j])
                fitness++;
        }
        populationPtr->fitness[i]=fitness;

        //printf("The fitness of individual %d is %d\n",i,fitness);
        
    }

	//printf("New fitness value are :\n");
    //return fitness;
}
void randomIndividual (struct population *OneElementPopulationPtr,char OneElementPopulation[], unsigned int size){
    int i,randtemp,halfrandmaxtemp;
    int seed = time(0);
    srand(seed*rand());
    generatePopulation(OneElementPopulationPtr,OneElementPopulation,1,size,0);
}
    void setSolution(struct population* populationPtr, char newSolution[], unsigned int individualslocation) {
		//printf("Set the following solution:\n");
                populationPtr->individuals[individualslocation]=newSolution;
		//printf("%s\n",populationPtr->individuals[individualslocation]);

    }
