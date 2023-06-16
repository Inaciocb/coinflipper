#include <iostream>
#include <random>

#define ROUNDS 10

bool flip_coin()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1); 

    return (dis(gen) ==1);
}

  

int flips(int whr)
{
    int flips = 0, hr = 0;
    
    while(hr < whr)
    {
        flips++;
        if(flip_coin() == 1)
            hr++;
        else
            hr = 0;
    }
    return flips;
}
int main(){

    int heads_in_a_row = 0, wanted_heads_in_a_row;

    std:: cout << "how many heads in a row do you want?" << std:: endl;
    std:: cin >> wanted_heads_in_a_row;

    std:: cout 
    << "it took " << flips(wanted_heads_in_a_row) 
    << " to get " 
    << wanted_heads_in_a_row 
    << " heads in a row." 
    << std:: endl;

    return 0;
}
