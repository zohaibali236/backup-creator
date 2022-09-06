#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>

int main()
{
    std::cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << std::endl;
    std::cout << "█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█" << std::endl;
    std::cout << "█░░║║║╠─║─║─║║║║║╠─░░█" << std::endl;
    std::cout << "█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█" << std::endl;
    std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << std::endl;


    std::cout << "Enter the path of folder you want to be copied" << std::endl;
    
    std::string path_from;
    std::cin >> path_from;

    std::cout << "Enter the path to copy to" << std::endl;

    std::string path_to;
    std::cin >> path_to;

    std::cout << "Enter backup interval" << std::endl;
    
    int interval;
    std::cin >> interval;


    time_t currenttime = time(NULL);

    char cstring[path_from.length() + path_to.length() + 20];

    sprintf(cstring, "xcopy \"%s\" \"%s\" /s /e", path_from.c_str(), path_to.c_str());
    std::cout << cstring << std::endl;

    while(true)
    {
        time_t time_ = time(NULL);

        if((time_ - currenttime) >= interval)
        {
            system(cstring);
            currenttime = time(NULL);
        }
    }
    return 0;
}
