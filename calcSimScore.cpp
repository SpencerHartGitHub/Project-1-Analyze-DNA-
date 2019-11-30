#include <iostream>
#include <string>
using namespace std;

/*
* Algorithm: Calculate the sim score given 2 sequences
* 1. Establish restrictions for if they are different lengths or if the are equal 
* 2. create a counter for mismatches
* 3. make a for loop that for as long as i is less than the length of the first sequence keep adding 1 to i
* 4. go through both sequences index by index and if there are mismatches add those to the counter
* 5. Then plug the numbers into the equation to get sim score
*/

double calcSimScore(string firstSeq , string secondSeq)
{
    if (firstSeq.length() != secondSeq.length()) // if they are not the same length
    {
        return 0;
    }
    
    else if (firstSeq == "" || secondSeq == "") // if nothing was entered 
    {
        return 0;
    }
    
    else
    {
        if (firstSeq == secondSeq) // if they are the exact same
        {
            return 1;
        }
    }
    
    double misMatch = 0; // initialize this "counter"
    
    for (int i = 0; i <= firstSeq.length(); i++) // makes loop for if i is less than or equal to the length of the first sequence
    {
       if (firstSeq[i] != secondSeq[i]) // if the index of the first sequence doesnt equal the index of the second add one to mismatch
        {
            misMatch++;
        }
    }
    double simScore = (firstSeq.length() - misMatch) / firstSeq.length(); // takes the values and computes them 

    return simScore; 
}
