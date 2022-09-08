#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>

int main(int argc, char** argv)
{
    std::cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << std::endl;
    std::cout << "█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█" << std::endl;
    std::cout << "█░░║║║╠─║─║─║║║║║╠─░░█" << std::endl;
    std::cout << "█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█" << std::endl;
    std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << std::endl;


//     std::cout << "Enter the path of folder you want to be copied" << std::endl;
    
//     std::string path_from;
//     getline(std::cin, path_from);

//     std::cout << "Enter the path to copy to" << std::endl;

//     std::string path_to;
//     getline(std::cin, path_to);

//     std::cout << "Enter backup interval" << std::endl;
    
//     int interval;
//     std::cin >> interval;

    time_t currenttime = time(NULL);

    char cstring[strlen(argv[1]) + strlen(argv[2]) + 20];

    sprintf(cstring, "xcopy \"%s\" \"%s\" /s /e /q /y", path_from.c_str(), path_to.c_str());
    std::cout << cstring << std::endl;

    while(true)
    {
        time_t time_ = time(NULL);

        if((time_ - currenttime) >= argv[3])
        {
            system(cstring);
            currenttime = time(NULL);
            std::cout << "Folder contents copied on " << unixTimeToHumanReadable(currenttime) << std::endl;
        }
    }
    return 0;
}


std::string unixTimeToHumanReadable(long int seconds) //https://www.geeksforgeeks.org/convert-unix-timestamp-to-dd-mm-yyyy-hhmmss-format/
{
 
    // Save the time in Human
    // readable format
    string ans = "";
 
    // Number of days in month
    // in normal year
    int daysOfMonth[] = { 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };
 
    long int currYear, daysTillNow, extraTime,
        extraDays, index, date, month, hours,
        minutes, secondss, flag = 0;
 
    // Calculate total days unix time T
    daysTillNow = seconds / (24 * 60 * 60);
    extraTime = seconds % (24 * 60 * 60);
    currYear = 1970;
 
    // Calculating current year
    while (daysTillNow >= 365) {
        if (currYear % 400 == 0
            || (currYear % 4 == 0
                && currYear % 100 != 0)) {
            daysTillNow -= 366;
        }
        else {
            daysTillNow -= 365;
        }
        currYear += 1;
    }
 
    // Updating extradays because it
    // will give days till previous day
    // and we have include current day
    extraDays = daysTillNow + 1;
 
    if (currYear % 400 == 0
        || (currYear % 4 == 0
            && currYear % 100 != 0))
        flag = 1;
 
    // Calculating MONTH and DATE
    month = 0, index = 0;
    if (flag == 1) {
        while (true) {
 
            if (index == 1) {
                if (extraDays - 29 < 0)
                    break;
                month += 1;
                extraDays -= 29;
            }
            else {
                if (extraDays
                        - daysOfMonth[index]
                    < 0) {
                    break;
                }
                month += 1;
                extraDays -= daysOfMonth[index];
            }
            index += 1;
        }
    }
    else {
        while (true) {
 
            if (extraDays
                    - daysOfMonth[index]
                < 0) {
                break;
            }
            month += 1;
            extraDays -= daysOfMonth[index];
            index += 1;
        }
    }
 
    // Current Month
    if (extraDays > 0) {
        month += 1;
        date = extraDays;
    }
    else {
        if (month == 2 && flag == 1)
            date = 29;
        else {
            date = daysOfMonth[month - 1];
        }
    }
 
    // Calculating HH:MM:YYYY
    hours = extraTime / 3600;
    minutes = (extraTime % 3600) / 60;
    secondss = (extraTime % 3600) % 60;
 
    ans += to_string(date);
    ans += "/";
    ans += to_string(month);
    ans += "/";
    ans += to_string(currYear);
    ans += " ";
    ans += to_string(hours);
    ans += ":";
    ans += to_string(minutes);
    ans += ":";
    ans += to_string(secondss);
 
    // Return the time
    return ans;
}
