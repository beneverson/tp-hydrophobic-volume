#include <stdio.h>

#define kSequenceInputFilePath "/Users/bernardeverson/Desktop/Research/Koder Lab/4 Helix Bundle/TPHydrophobicVolume/sequence-input.data"

// this method gives the number of non-backbone carbon
// atoms in a given residue
int carbonCountForResidue(char residue) {
	
	switch (residue) {
		case 'F':
			return 7;
			break;
		case 'I':
			return 4;
			break;
		case 'L':
			return 4;
			break;
		case 'V':
			return 3;
			break;
		case 'M':
			return 3;
			break;
		default:
			return 0;
			break;
	}
	
	
	
}

int main (int argc, const char * argv[]) {
	
	FILE * input_data_file; 
	char * input_file_path = kSequenceInputFilePath;
	
	// show an error if file at path can't be opened
	if ((input_data_file = fopen(input_file_path, "r")) == NULL) {
		printf("\nError opening file at path: %s \n", input_file_path);
	}
	
	char current_char;
	
	// an int to keep track of the number of non-backbone 
	// hdrophobic c atoms of the sequence
	int hydrophobic_atoms = 0;
	
	while (!feof(input_data_file)) {
		
		current_char = fgetc(input_data_file);
		
		hydrophobic_atoms += carbonCountForResidue(current_char);
		
	}
	
	printf("\nTotal hydrophobic c-atoms of input sequence is: %d \n", hydrophobic_atoms);
	
	fclose(input_data_file);
		
    return 0;
}
