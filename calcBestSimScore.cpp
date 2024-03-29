#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: given a genome see what the best score is from the given sequence
* 1. Add restrictions
* 2. Do the code from countMatches to find the mismatches and add those to mismatches
* 3. Calc the sim score and store it, then reset mismatch 
* 4. repeat and then the best score will b outputed
*/

double findBestSimScore(string genome , string sequence)
{
    double bestSimScore = 0; // initialize everything here as doubles
    double misMatch = 0;
    double length1 = genome.length();
    double length2 = sequence.length();

    if (genome == "" || sequence == "") // if nothing is entered
    {
        return 0;
    }
    else if(genome == sequence) // if they equal the same thing 
    {
        return 1;
    }
    
    for (int i = 0; i <= length1 - length2; i++) // a loop that goes through word with subWord one by one
    {
        
        int j; // initialize an int for j for the upcoming statements
        
        for (j = 0; j < length2; j++) // for the current index of i, checks for a pattern match
        {
            
            if(genome[i + j] != sequence[j]) // checks if the letter from the word does not equal the same as the letter from the subWord
            {
                misMatch++;
            }
        }
        
        double simScore = (length2 - misMatch) / length2; // calculates equation but with length 2 instead of 1 because we are seeing the score of the whole sequence compared to genome
                    
        if (bestSimScore < simScore) // best was set to 0 to start it off and if the sim score is bigger 
        {
            bestSimScore = simScore; // it will take the place of the current best sim score
        }
        misMatch = 0; // reset mismatch to 0 so you can fin the rest of the words scores
    }
    return bestSimScore;
}
