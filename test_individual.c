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

/* Include modules header we directly invoke here: 
#include "module1.h"
#include "module2.h"*/
#include"individual.h"

#define DEFAULTGENELENGTH 63
#define FITNESS 1

int i,j;
int sizeindividual;
struct individual *indivPtr, indiv, OneElementeIndividual,*OneElementeIndividualPtr;
void main (){
	indivPtr=&indiv;
	OneElementeIndividualPtr=&OneElementeIndividual;
	init_individual(OneElementeIndividualPtr,sizeindividual);
	generateIndividual(OneElementeIndividualPtr,OneElementeIndividualPtr,10);
	toStringIndividual(OneElementeIndividualPtr);

	generateIndividual(indivPtr,OneElementeIndividualPtr,10);
	toStringIndividual(indivPtr);

	printf("The Gene %d is: %c\n",2,getGene(indivPtr,2));
	setGene(indivPtr,2,'f');
	toStringIndividual(indivPtr);


    	generateIndividualZero(indivPtr,OneElementeIndividualPtr,10);
    	toStringIndividual(indivPtr);
}

