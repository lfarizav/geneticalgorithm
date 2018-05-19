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
#include"population.h"


int i,j;
int main (){
char OneElementPopulation[]={'1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','0',};
    struct population population,newpopulation,OneElementePopulation;
    struct population *populationPtr;
    struct population *newpopulationPtr;
    struct population *OneElementePopulationPtr;

    OneElementePopulationPtr=&OneElementePopulation;
    populationPtr=&population;
    newpopulationPtr=&newpopulation;

    int sizeindividual=24,sizepopulation=10;

    generatePopulation(populationPtr,OneElementPopulation,sizepopulation,sizeindividual,1);
    toStringPopulation(populationPtr);

    randomIndividual(OneElementePopulationPtr,OneElementPopulation,sizeindividual);
    toStringPopulation(OneElementePopulationPtr);

    generatePopulation(newpopulationPtr,OneElementPopulation,sizepopulation,sizeindividual,0);
    toStringPopulation(newpopulationPtr);

    saveIndividual(populationPtr,newpopulationPtr, 3,4);
    saveIndividual(populationPtr,newpopulationPtr, 0,9);
    toStringPopulation(newpopulationPtr);

}
