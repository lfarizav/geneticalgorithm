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
#include"individual.h"

	//get the fitness value
        void getFitnessIndividual(struct individual* indivPtr,struct individual* OneElementeIndividualPtr) {
	int i,fitness=0;
	for(i=0;i<indivPtr->defaultGeneLength;i++){
		        if (indivPtr->genes[i]==OneElementeIndividualPtr->genes[i]) {
				fitness++;
        		}
	}
	indivPtr->fitness=fitness;
}

	
    // Create a random new individual in individual.genes//ok
    void generateIndividual(struct individual* indivPtr,struct individual* OneElementeIndividualPtr, long size) {
	int i;
        int j=0;
        j++;
        int seed = time(0);
	    init_individual(indivPtr,size);
        srand(j*seed*rand());
        for (i = 0; i < indivPtr->defaultGeneLength; i++) {
       
		if((unsigned long)rand()<=((unsigned long) RAND_MAX/2))
			setGene(indivPtr, i, '1');
		else
         		setGene(indivPtr, i, '0');

		//printf("Gen %d: %c\n",i,indivPtr->genes[i]);
        }
        //free(indivPtr->genes);
	getFitnessIndividual(indivPtr,OneElementeIndividualPtr);
    }
// Create a random new individual in individual.genes//ok
void generateIndividualZero(struct individual* indivPtr,struct individual* OneElementeIndividualPtr, long size) {
    int i;
    init_individual(indivPtr,size);
    for (i = 0; i < size; i++) {
            setGene(indivPtr, i, '0');
        //printf("Gen %d: %c\n",i,indivPtr->genes[i]);
    }
    //free(indivPtr->genes);
	getFitnessIndividual(indivPtr,OneElementeIndividualPtr);
}

    // Modify the default number of genes into indiv.genes//ok
    void setDefaultGeneLength(struct individual* indivPtr, long length) {
	//printf("New defaultGeneLength is: %d\n",length);
	indivPtr->defaultGeneLength = length;
	
    }
    //get the gen [i] from genes//ok
    unsigned long getGene(struct individual* indivPtr, unsigned long index) {
	//printf("The Gene %d is: %c\n",index,indivPtr->genes[index]);
        return indivPtr->genes[index];
    }

    void setGene(struct individual* indivPtr, unsigned long index, char value) {
        indivPtr->genes[index] = value;
	//printf("The Gen %d is settled to: %c\n",index,indivPtr->genes[index]);
    }
	//get the size of genes//ok
	long sizeGenes(struct individual indiv){
	long size = sizeof(indiv.genes)/sizeof(indiv.genes[0]);
	//printf("The size of genes is: %d\n",size);

}
    void toStringIndividual(struct individual* indivPtr) {
	long j;
	printf("Individual's genes are:\n");
        for (j = 0; j<indivPtr->defaultGeneLength; j++) {
	printf("%c",indivPtr->genes[j]);
        }
	printf("\nThe fitness is: %d\n",(int)indivPtr->fitness);
    }
	void init_individual(struct individual* indivPtr, long size){
	indivPtr->defaultGeneLength = size;
	indivPtr->fitness=0;
	indivPtr->genes= (char*)malloc(size*sizeof(char));
	//printf("The size of genes is settled to  %d\n",indivPtr->defaultGeneLength);
	//printf("The fitness value is settled to  %d\n",indivPtr->fitness);
}
