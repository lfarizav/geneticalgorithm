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

#include"defs.h"

    //static byte[] solution = new byte[64];

    /* Public methods */
    // Set a candidate solution as a byte array from struct individual
    struct individual setSolution(struct individual newSolution) {
	int solution[sizeof(newSolution.genes)/sizeof(newSolution.genes[0])];
        solution = newSolution.genes;
	return solution;
    }

  /*  // Set a candidate solution as a byte array from char
   char setSolution(char newSolution) {
	char solution[sizeof(newSolution)];
        // Loop through each character of our string and save it in our byte
        // array
        for (int i = 0; i < sizeof(newSolution); i++) {
            char character = newSolution.substring(i, i + 1);
            if (character.contains("0") || character.contains("1")) {
                solution[i] = Byte.parseByte(character);
            } else {
                solution[i] = 0;
            }
        }
    }*/

    // Calculate inidividuals fittness by comparing it to our candidate solution
    int getFitness(struct individual individual) {
        int fitness = 0;
        // Loop through our individuals genes and compare them to our candidates
        for (int i = 0; i < sizeof(individual.genes)/sizeof(individual.genes[0]); i++) {
            if (individual.getGene(i) == solution[i]) {
                fitness++;
            }
        }
        return fitness;
    }
    
    // Get optimum fitness
    int getMaxFitness() {
        int maxFitness = solution.length;
        return maxFitness;
    }
