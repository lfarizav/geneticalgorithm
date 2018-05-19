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

//#include "SIMULATION/TOOLS/xxx.h" user xxx.h file
#include"defs.h"

 void generatePopulation(struct population* populationPtr,char OneElementPopulation[],unsigned long sizepopulation, unsigned long sizeindividual, unsigned int initialise);
//struct individual getIndividual(struct individuals population, int index);
//int sizeindividuals(struct individuals population);
//struct individual saveIndividual(int index, struct individual indiv);
void toStringPopulation(struct population* populationPtr);
void init_population(struct population* populationPtr,unsigned long sizepopulation, unsigned long sizeindividual);
void getFittest(struct population* populationPtr);
void saveIndividual(struct population* populationPtr,struct population* newpopulationPtr, unsigned int locationIndividualSource,unsigned int locationIndividualDestination);
// Calculate inidividuals fittness by comparing it to our candidate solution
void getFitnessPopulation(struct population* populationPtr, char randomindividualPtr[]);
void randomIndividual (struct population *OneElementPopulationPtr,char OneElementPopulation[], unsigned int size);
void setSolution(struct population* populationPtr, char newSolution[], unsigned int individualslocation);
