/*
 *@Coded by Luis Felipe Ariza Vesga
 *@Universidad Nacional de Colombia
 *@EURECOM
 *@2017
 *@lfarizav@unal.edu.co, ariza@eurecom.fr
 *@('    .-. .-. .-. .-.   .--.   .-.
 *@('    | } { | |  \{ |  / {} \  } |
 *@('    \ `-' / | }\  { /  /\  \ } '--.
 *@('     `---'  `-' `-' `-'  `-' `----'
 *@('    ,----, ,-, ,-. ,---.  .----. .----.  .---.  .-.  .-.
 *@('    } |__} | } { | } }}_} } |__} | }`-' / {-. \ }  \/  {
 *@('    } '__} \ `-' / | } \  } '__} | },-. \ '-} / | {  } |
 *@('    `----'  `---'  `-'-'  `----' `----'  `---'  `-'  `-'
 */

/* Include standard headers: */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <stdbool.h>

/* Include modules header we directly invoke here:
 #include "module1.h"
 #include "module2.h"*/
#include"algorithm.h"
int i,j;
int main (){
    int i;
    long sizepopulation =30;
    long sizeindividual =24;
    char *newSolutionPtr, newSolution[]={'0','0','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1',};
    
    // Evolve our population until we reach an optimum solution
    int generationCount = 0;
    int sizetournament=5;
    int max=200;
	
    //newSolutionPtr=&newSolution[0];
    struct population population,newpopulation,tournament,OneElementePopulation,mypopulation, crossoverpopulation;
    struct population *populationPtr, *newpopulationPtr,*tournamentPtr,*OneElementePopulationPtr,*crossoverpopulationPtr,*mypopulationPtr;
    mypopulationPtr=&mypopulation;
    populationPtr=&population;
    newpopulationPtr=&newpopulation;
    tournamentPtr=&tournament;
    OneElementePopulationPtr=&OneElementePopulation;
    crossoverpopulationPtr=&crossoverpopulation;

    generatePopulation(populationPtr,newSolution,sizepopulation, sizeindividual,1);
    //toStringPopulation(populationPtr);

    generatePopulation(newpopulationPtr,newSolution,sizepopulation, sizeindividual,0);
    //toStringPopulation(newpopulationPtr);

    generatePopulation(tournamentPtr,newSolution,sizepopulation, sizeindividual,0);
    generatePopulation(mypopulationPtr,newSolution,sizepopulation,sizeindividual,0);
    //toStringPopulation(tournamentPtr);

    generatePopulation(crossoverpopulationPtr,newSolution,3,sizeindividual,0);

    //toStringPopulation(crossoverpopulationPtr);

    randomIndividual(OneElementePopulationPtr,newSolution,sizeindividual);

    mutate(populationPtr,0);
    //toStringPopulation(populationPtr);
    
    printf("Tournament element is: %d\n",tournamentSelection(populationPtr,tournamentPtr,newSolution,sizetournament));
    //toStringPopulation(tournamentPtr);

    crossover(populationPtr,crossoverpopulationPtr, 0, 1);
    //toStringPopulation(crossoverpopulationPtr);

    //transferdatapopulation(populationPtr,mypopulationPtr);
    //setSolution(OneElementePopulationPtr,newSolution,0);
    ////toStringPopulation(OneElementePopulationPtr);

    for(i=0;i<max;i++){

	generationCount++;
	printf(" Generation: %d, fittest: %d\n",generationCount,newpopulationPtr->fittest);
	evolvePopulation(populationPtr,newpopulationPtr,tournamentPtr, crossoverpopulationPtr,newSolution,sizetournament, 1);
	transferdatapopulation(newpopulationPtr,populationPtr);
        toStringPopulation(populationPtr);
        if (newpopulationPtr->fitness[newpopulationPtr->fittest]==newpopulationPtr->defaultGeneLength){
            printf("Find the following array:\n%s\n",newSolution);
	    printf("Solution found!\nGeneration %d\nThe array found is:\n",generationCount);
            printf("%s\n",newpopulationPtr->individuals[newpopulationPtr->fittest]);
            return 0;
        }
        
    }
}
