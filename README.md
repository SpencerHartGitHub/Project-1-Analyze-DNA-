# Project-1-Analyze-DNA-
My first C++ project where we had to create three functions that allowed the user to enter genome and from there we calculate the similarity score, best similarity score, and then finding the matching genome. * Algorithm: makes a full functioning menu for finding the sim score, best sim score, or best-matched genome  * 1. Put the three sets of code for each part of the menu * 2. create your main with a loop with a menu and options when input is received * 3. when the user asks for one reroute back to the code that finds the answer and outputs it * 4 if the enter a none related number says invalid * 5. if the want to quit hit 4  *CALC BEST SIM SCORE* /* * Algorithm: Calculate the sim score given 2 sequences * 1. Establish restrictions for if they are different lengths or if the are equal  * 2. create a counter for mismatches * 3. make a for loop that for as long as i is less than the length of the first sequence keep adding 1 to i * 4. go through both sequences index by index and if there are mismatches add those to the counter * 5. Then plug the numbers into the equation to get sim score */  *FIND BEST SIM SCORE* /* * Algorithm: given a genome see what the best score is from the given sequence * 1. Add restrictions * 2. Do the code from countMatches to find the mismatches and add those to mismatches * 3. Calc the sim score and store it, then reset mismatch  * 4. repeat and then the best score will b outputted */  *FIND MATCHED GENOME* /* * Algorithm: See which genome is the best match for the given sequence * 1. set restrictions * 2. make 3 for loops for each genome to calc the best sim scores  * 3. compare the best sim scores of all the genomes and output the best matches to the sequence */
