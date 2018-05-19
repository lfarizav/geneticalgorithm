//public class Individual {
struct individual{
	unsigned long defaultGeneLength;
	char* genes;
	unsigned long fitness;
};

struct population{
	unsigned long defaultPopulationSize;
	unsigned long defaultGeneLength;
	unsigned long* fitness;
	unsigned long* randomindividual;
        unsigned long fittest;
	char** individuals;
};
struct random{
    char* individual;
};
//typedef enum { false, true } bool;
