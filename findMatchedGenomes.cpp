#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: See which genome is the best match for the given sequence
* 1. set restrictions
* 2. make 3 for loops for each genome to calc the best sim scores 
* 3. compare the best sim scores of all the genomes and output the best matches to the sequence
*/

void findMatchedGenome(string genome1 , string genome2 , string genome3 , string sequence)
{
    double length1 = genome1.length(); //initializes all the lengths as doubles
    double length2 = genome2.length();
    double length3 = genome3.length();
    double length4 = sequence.length();
    
    if (genome1 == "" || genome2 == "" || genome3 == "" || sequence == "") // if there are any empty responses
    {
        cout << "Genomes or sequence is empty." << endl;
        return;
    }
    if (length1 != length2 || length1 != length3 || length2 != length3) // if the lengths of any of the genomes are different 
    {
        cout << "Lengths of genomes are different." << endl;
        return;
    }
    // Below each set of for loops is for each given genome
    double bestSimScore1 = 0; // initializes these as 0
    double misMatch1 = 0;
    
    for (int i = 0; i <= length1 - length4; i++) // a loop that goes through word with subWord one by one
    {
        
        int j; // initialize an int for j for the upcoming statements
        
        for (j = 0; j < length4; j++) // for the current index of i, checks for a pattern match
        {
            
            if(genome1[i + j] != sequence[j]) // checks if the letter from the word does not equal the same as the letter from the subWord
            {
                misMatch1++;
            }
        }
        
        double simScore1 = (length4 - misMatch1) / length4;
                    
        if (bestSimScore1 < simScore1)
        {
            bestSimScore1 = simScore1; // finds best score for 1st genome
        }
        misMatch1 = 0; // resets mismatch
    }
    
    double bestSimScore2 = 0;
    double misMatch2 = 0;
    
    for (int i = 0; i <= length2 - length4; i++) // a loop that goes through word with subWord one by one
    {
        
        int j; // initialize an int for j for the upcoming statements
        
        for (j = 0; j < length4; j++) // for the current index of i, checks for a pattern match
        {
            
            if(genome2[i + j] != sequence[j]) // checks if the letter from the word does not equal the same as the letter from the subWord
            {
                misMatch2++;
            }
        }
        
        double simScore2 = (length4 - misMatch2) / length4;
                    
        if (bestSimScore2 < simScore2)
        {
            bestSimScore2 = simScore2; // finds best score for 2nd genome
        }
        misMatch2 = 0;
    }
    
    double bestSimScore3 = 0;
    double misMatch3 = 0;
    
    for (int i = 0; i <= length3 - length4; i++) // a loop that goes through word with subWord one by one
    {
        
        int j; // initialize an int for j for the upcoming statements
        
        for (j = 0; j < length4; j++) // for the current index of i, checks for a pattern match
        {
            
            if(genome3[i + j] != sequence[j]) // checks if the letter from the word does not equal the same as the letter from the subWord
            {
                misMatch3++;
            }
        }
        
        double simScore3 = (length4 - misMatch3) / length4;
                    
        if (bestSimScore3 < simScore3)
        {
            bestSimScore3 = simScore3; // finds best score for 3rd genome
        }
        misMatch3 = 0;
    }
    // all responses are below
    if ( (bestSimScore1 == bestSimScore2) && (bestSimScore1 == bestSimScore3) && (bestSimScore2 == bestSimScore3) )
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
        return;
    }
    
    else if ( (bestSimScore1 > bestSimScore3) && (bestSimScore2 > bestSimScore3) && (bestSimScore1 == bestSimScore2) )
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 2 is the best match." << endl;
        return;
    }
    
    else if ( (bestSimScore1 > bestSimScore2) && (bestSimScore3 > bestSimScore2) && (bestSimScore1 == bestSimScore3) )
    {
        cout << "Genome 1 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
        return;
    }
    
    else if ( (bestSimScore2 > bestSimScore1) && (bestSimScore3 > bestSimScore1) && (bestSimScore2 == bestSimScore3) )
    {
        cout << "Genome 2 is the best match." << endl;
        cout << "Genome 3 is the best match." << endl;
        return;
    }
    
    else if ( (bestSimScore1 > bestSimScore2) && (bestSimScore1 > bestSimScore3) )
    {
        cout << "Genome 1 is the best match." << endl;
        return;
    }
    
    else if ( (bestSimScore2 > bestSimScore1) && (bestSimScore2 > bestSimScore3) )
    {
        cout << "Genome 2 is the best match." << endl;
        return;
    }
    
    else if ( (bestSimScore3 > bestSimScore1) && (bestSimScore3 > bestSimScore2) )
    {
        cout << "Genome 3 is the best match." << endl;
        return;
    }
}
