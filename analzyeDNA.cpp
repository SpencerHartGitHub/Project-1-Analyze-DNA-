
#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: makes a full functioning menu for finding the sim score, best sim score, or best matched genome 
* 1. Put the three sets of code for each part of the menu
* 2. create your main wiht a loop with a menu and options when input is received
* 3. when user asks for one re route back to the code that finds the answer and output it
* 4 if the enter a none related number say invalid
* 5. if the want to quit hit 4
*/

double calcSimScore(string firstSeq , string secondSeq) // 1
{
    if (firstSeq.length() != secondSeq.length())
    {
        return 0;
    }
    
    else if (firstSeq == "" || secondSeq == "")
    {
        return 0;
    }
    
    else
    {
        if (firstSeq == secondSeq)
        {
            return 1;
        }
    }
    
    double misMatch = 0;
    for (int i = 0; i <= firstSeq.length(); i++)
    {
        if (firstSeq[i] != secondSeq[i])
        {
            misMatch++;
        }
    }
    double simScore = (firstSeq.length() - misMatch) / firstSeq.length();

    return simScore; 
}

double findBestSimScore(string genome , string sequence) // 2
{
    double bestSimScore = 0;
    double misMatch = 0;
    double length1 = genome.length();
    double length2 = sequence.length();

    if (genome == "" || sequence == "")
    {
        return 0;
    }
    else if(genome == sequence)
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
        
        double simScore = (length2 - misMatch) / length2;
                    
        if (bestSimScore < simScore)
        {
            bestSimScore = simScore;
        }
        misMatch = 0;
    }
    return bestSimScore;
}

void findMatchedGenome(string genome1 , string genome2 , string genome3 , string sequence) // 3
{
    double length1 = genome1.length();
    double length2 = genome2.length();
    double length3 = genome3.length();
    double length4 = sequence.length();
    
    if (genome1 == "" || genome2 == "" || genome3 == "" || sequence == "")
    {
        cout << "Genomes or sequence is empty." << endl;
        return;
    }
    if (length1 != length2 || length1 != length3 || length2 != length3)
    {
        cout << "Lengths of genomes are different." << endl;
        return;
    }
    
    double bestSimScore1 = 0;
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
            bestSimScore1 = simScore1;
        }
        misMatch1 = 0;
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
            bestSimScore2 = simScore2;
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
            bestSimScore3 = simScore3;
        }
        misMatch3 = 0;
    }
    
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


int main()
{
    int input = 1; // this makes the loop keep going after an answer is outputed
    
    while ( input == 1 || input == 2 || input == 3 || input == 4) // all available input
    {
    
        cout << "Select a numerical option:" << endl;
        cout << "=== menu ===" << endl;
        cout << "1. Find similarity score" << endl;
        cout << "2. Find the best similarity score" << endl;
        cout << "3. Analyze the genome sequences" << endl;
        cout << "4. Quit" << endl;
        
        cin >> input; // takes input
        
        if ( (input < 1) || (input > 4) ) // if less than 1 or more than 4 
        {
            cout << "Invalid option." << endl;
            
            return main(); // go back to main (menu)
        }
        
        if (input == 1)
        {
            
            string firstSeq; // initialize the strings
            string secondSeq;
            
            cout << "Enter sequence 1:" << endl; // output to get input
            cin >> firstSeq;
            cout << "Enter sequence 2:" << endl;
            cin >> secondSeq;
            
            cout << "Similarity score: " << calcSimScore(firstSeq , secondSeq) << endl; // routes back to the begining and plugs the input values into the function and outputs the return 
        }
        
        else if (input == 2)
        {
            
            string genome; // initialize the strings 
            string sequence;
            
            cout << "Enter genome:" << endl; // output to get input 
            cin >> genome;
            cout << "Enter sequence:" << endl;
            cin >> sequence;
            
            cout << "Best similarity score: " << findBestSimScore(genome , sequence) << endl; // calls the function and put in the inputs to get return 
           
        }
        
        else if (input == 3)
        {
            
            string genome1; // initilize strings 
            string genome2;
            string genome3;
            string sequence;
            
            cout << "Enter genome 1:" << endl; // get inputs 
            cin >> genome1;
            cout << "Enter genome 2:" << endl;
            cin >> genome2;
            cout << "Enter genome 3:" << endl;
            cin >> genome3;
            cout << "Enter sequence:" << endl;
            cin >> sequence;
            
            findMatchedGenome(genome1 , genome2 , genome3 , sequence); // since its void dont cout. but call the function with the inputs and get the couts 
            
        }
        
        else if (input == 4) 
        {
            cout << "Good bye!" << endl; // if 4 is entered output this 
            break;
        }
    }
    return 0;
}
