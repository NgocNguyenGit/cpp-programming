//
//  main.cpp
//  cpp_Final Project
//
//  Created by Nguyen Le Khanh Ngoc on 14/12/2020.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <array>
#include <random>
using namespace std;

#define ROLLS 36000000 //Your program should roll the two dice 36,000,000 times
int main(int argc, const char * argv[]) {
    int first_dice;
    int second_dice;
    //time_t tstart, tend;
    //The sum of the two values will vary from 0 to 12
    const size_t arraySize{13};
    
    //Initialize all elements to zero
    array <unsigned int, arraySize> frequency {};
    
    //Contains counts for the expected number of times
    //each sum occurs in 36 rolls of the dice
    array <int, arraySize> expected{0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    
    //Use the default random-number generation engine to
    //produce uniformly distributed pseudorandom int values from 1 to 6
    default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomInt(1,6);
    
    //tstart = time(0);
    //Roll dice 36,000,000 times
    for (unsigned int roll{0}; roll < ROLLS; ++roll) {
        first_dice = randomInt(engine);    //Generates a random number from 1 to 6
        second_dice = randomInt(engine);   //Generates a random number from 1 to 6
        //Increment the appropriate counter in array sum that
        //corresponds to the sum of the first dice and the second dice
        ++frequency[first_dice + second_dice];
    }

    cout << setw(12) << "Sum| " << setw(12) << "Frequency| " << setw(12) << "Theory| " << setw(15) << "In program" << fixed << showpoint<<endl;
    cout<<"––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    
    //Display results of rolling dice
    for (size_t j{2}; j < frequency.size(); ++j){
        cout << setw(10) << j <<"| "<< setw(10) << frequency[j] << setprecision(3) <<"| "<< setw(9) << 100.0 * expected[j] / 36 << "%" <<"| "<< setprecision(3) << setw(14) << 100.0 * frequency[j] / ROLLS << "%"<<endl;
    }
    /*
    tend = time(0);
    cout<<tend - tstart<<endl;
    
    tstart = time(0);
    const int SIZE = 13;
    int frequency_1[SIZE] = {0}; //Array sum.

    srand(time(0));
   
    //Roll dice 36,000 times
    for (int i = 0; i < ROLLS; i++) {
        first_dice = rand() % 6+1; //Generates a number between 0 and 7
        second_dice = rand() % 6+1; //Generates a number between 0 and 7

        frequency_1[first_dice+second_dice]++; //Find's the sum of the dice roll, and increments that's count.
    }

    cout << setw(10) << "Sum" << setw(10) << "Frequency" << setw(10)
         << "Theory" << setw(10) << "In Program\n" << fixed << showpoint;

    //Display results of rolling dice
    for (int j = 2; j < SIZE; j++) {
        cout << setw(10) << j << setw(10) << frequency_1[j]
             << setprecision(3) << setw(9)
             << 100.0 * expected[j] / 36 << "%" << setprecision(3)
             << setw(9) << 100.0 * frequency_1[j] / ROLLS << "%\n";
    }
    tend = time(0);
    cout<<tend - tstart<<endl;
     */
    return 0;
}
