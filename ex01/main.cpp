#include "Phonebook.hpp"

int main()
{
    const char 			*str;
    std::string			strl;
    const char 			*res;
    std::string			line;
    PhoneBook  			ph;
    int					index;
    int					flag;
    bool				isnum;

    index = 0;
    ph.set_i_value(index - 1);
    (void)res;
    std::cout << "enter one of these commands (ADD, SEARCH, EXIT): " << std::endl;
    while(1)
    {
        flag = 0;
        std::cout << "> ";
        std::getline(std::cin, strl);
        str = strl.c_str();
        if (!str)
            return(std::cout.write("error: fatal\n", 13), 1);
        if (std::cin.eof())
            exit(0);
        if (str && !strcmp(str, "ADD"))
        {
            ph.add_to_contact(0, ph.get_values(), index);
            ph.add_to_contact(1, ph.get_values(), index);
            ph.add_to_contact(2, ph.get_values(), index);
            ph.add_to_contact(3, ph.get_values(), index);
            ph.add_to_contact(4, ph.get_values(), index);
			ph.set_value_to_index(ph.get_values(), index % 8, index);
	        if (ph.get_i_value() < 7)
                ph.set_i_value(index % 8);
            index++;
        }
        else if (str && !strcmp(str, "SEARCH"))
        {
			ph.print_all_contacts(ph);
            while(1 && ph.get_i_value() != -1)
            {
                if (!flag)
			        std::cout.write("enter index number: ", 20);
                else
                    std::cout.write("your index out of the range, try another one: ", 46);
                std::getline(std::cin, line, '\n');
                res = line.c_str();
				if (std::cin.eof())
            		exit(0);
                if (!res)
                    break ;
                if ((!strcmp(res, "")))
                    continue ;
                isnum = all_num(line.c_str());
				if (isnum &&  ph.print_specific_contact(ph, atoi(res)))
					break ;
                else
                    flag = 1;
            }
        }
        else if (str && !strcmp(str, "EXIT"))
            exit(0);
    }
    return (0);
}