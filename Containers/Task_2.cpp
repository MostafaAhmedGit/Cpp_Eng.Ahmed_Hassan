#include <iostream>
#include <stdint.h>
#include <map>

typedef struct
{
    uint32_t Command;
    int16_t Control;
    int16_t Status0;
    uint16_t Options;
}Register_t;

int main() {
    
    std::map <int,Register_t> Register_Bank;
    
 //   Register_Bank[128];
    
    Register_Bank[0] = 
    {
        .Command = 1,
        .Control = 2,
        .Status0 = 3,
        .Options = 4,
    };
    
    std::cout<<Register_Bank[0].Command<<std::endl;
    std::cout<<Register_Bank[0].Control<<std::endl;
    std::cout<<Register_Bank[0].Status0<<std::endl;
    std::cout<<Register_Bank[0].Options<<std::endl;

    return 0;
}