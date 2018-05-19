
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
void evolvePopulation(struct population* populationPtr,struct population* newpopulationPtr,struct population* tournamentPtr,struct population* crossoverpopulationPtr,char OneElementePopulation[],int sizetournament, unsigned int elitism);
void crossover(struct population* populationPtr, struct population* crossoverpopulationPtr, unsigned int firstlocation, unsigned int secondlocation);
void mutate(struct population* populationPtr, unsigned int individualLocation);
int tournamentSelection(struct population* populationPtr, struct population* tournamentPtr, char OneElementePopulation[], int sizetournament);
void transferdatapopulation(struct population* populationsrcPtr,struct population* populationdstPtr);
