#include "phonebook.hpp"

using namespace std;

/*
    in c++ you can still use the syntax of c++ but it is different in some ways like when you declara an 
    array of char arr[10], in c we was assing this array with the operator = but in c++ this syntax esspecialy with
    arrays does't work if want to assign an array you need to use strcpy,
    but if you still want to use the operator = you can declare the yours array as 
                    str::string name = "some_thing";
    
    Good luck with the next;
*/

int main()
{
    char        *str;
    const char  *res;
    string      line;
    PhoneBook   ph;
    int         index;
    int         i;

    i = 0;
    index = 0;
    ph.i = 0;
    while(1)
    {
        cin >> str;
        if (std::cin.eof())
            exit(0);
        if (str && !strcmp(str, "ADD"))
        {
            ph.ft_read(0, ph.contacts, index);
            ph.ft_read(1, ph.contacts, index);
            ph.ft_read(2, ph.contacts, index);
            ph.ft_read(3, ph.contacts, index);
            ph.ft_read(4, ph.contacts, index);
            ph.contacts[index % 8].index = ((index % 8) + 48) + 1;
            if (ph.i < 7)
                ph.i++;
            index++;
        }
        else if (str && !strcmp(str, "SEARCH"))
        {
            while(1)
            {
                getline(cin, line, '\n');
                res = line.c_str();
                if (!res)
                    break ;
                if (++i && (!strcmp(res, "")))
                    continue;
                ph.ft_search(ph.contacts, atoi(res), (ph.i));
                    break ;
            }
        }
        else if (str && !strcmp(str, "EXIT"))
            exit(0);
        sleep(1);
    }
    return 0;
}