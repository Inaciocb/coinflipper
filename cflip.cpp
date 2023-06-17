    #include <iostream>
    #include <random>

    #define AVG_PRECISION 5

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
            {
                std:: cout << "Heads!" << std:: endl;
                    hr++;
            }
            else
            {
                std:: cout << "Crosses!" << std:: endl;
                    hr = 0;
            } 
        }
        return flips;
    }
    int main(){

        int flipss = 0, wanted_heads_in_a_row, amount_of_flips_log[AVG_PRECISION];
        
        char want = 'y';
        
        double flipsavg = 0;


        while(want == 'y'|| want == 'Y')
        {
            std:: cout << "how many heads in a row do you want?" << std:: endl;
            std:: cin >> wanted_heads_in_a_row;
            flipss = flips(wanted_heads_in_a_row);

            for(int i = 0; i < AVG_PRECISION; i++)
            {
                amount_of_flips_log[i] = flips(wanted_heads_in_a_row);
                flipsavg += amount_of_flips_log[i];

            }

            std:: cout 
            << "\n---------\nit took an average of " 
            << (int)(flipsavg/(AVG_PRECISION)+(1))
            << " flips to get " 
            << wanted_heads_in_a_row 
            << " heads in a row.\n" 
            << "Flips log:\n" << std:: endl;

            for(int i = 0; i < AVG_PRECISION; i++)
            {
                std:: cout << "Flip " << i+1 << ": " << amount_of_flips_log[i] << std:: endl;  
            }


            std:: cout << "Do you want to flip again? (y/n)" << std:: endl;
            std:: cin >> want;
        }
        return 0;
    }
