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

    // Create a random individual
    void generateIndividual(struct individual* indivPtr,struct individual* OneElementeIndividualPtr, long size);
    void generateIndividualZero(struct individual* indivPtr,struct individual* OneElementeIndividualPtr, long size);

    /* Getters and setters */
    // Use this if you want to create individuals with different gene lengths
    void setDefaultGeneLength(struct individual* indivPtr, long length);
    
    unsigned long getGene(struct individual* indivPtr, unsigned long index);

    void setGene(struct individual* indivPtr, unsigned long index, char value);

    /* Public methods */

	long sizeGenes(struct individual indiv);	
   	void getFitnessIndividual(struct individual* indivPtr,struct individual* OneElementeIndividualPtr);
	void toStringIndividual(struct individual* indivPtr);
	void init_individual(struct individual* indivPtr, long size);
