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
