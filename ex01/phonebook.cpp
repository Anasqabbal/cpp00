#include "Phonebook.hpp"

Contact *PhoneBook::get_values(void)
{
	return (contacts);
}

void	PhoneBook::set_value_to_index(Contact *contact, int index, int inde)
{
	contact[index].set_index_value(inde);
}

int	PhoneBook::get_i_value(void)
{
	return (i);
}

void PhoneBook::set_i_value(int val)
{
	i = val;
}

std::string PhoneBook::get_contact_value(Contact *contacts, int index, int ind)
{
	return ((contacts[index].get_values(ind)));
}

void print10_right_alighed(std::string str, int len)
{
	if (len <= 10)
		std::cout << std::setw(10) << std::right << str.substr(0, 10);
	else
	{
		std::cout << std::setw(9) << std::right << str.substr(0, 9);
		std::cout << '.';
	}
	std::cout << "|";
	std::cout << std::flush;
}

int	PhoneBook::print_specific_contact(PhoneBook ph, int index)
{
	std::string str;

	if (index > 8 || index > ph.get_i_value() || index < 0)
		return (0);
	{
		str = ph.get_contact_value(ph.get_values(), index, 0);
		std::cout.write("firstname: ", 11);
		std::cout.write(str.c_str() , strlen(str.c_str()));
		std::cout.write("\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 1);
		std::cout.write("lastname: ", 10);
		std::cout.write(str.c_str() , strlen(str.c_str()));
		std::cout.write("\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 2);
		std::cout.write("nickname: ", 10);
		std::cout.write(str.c_str() , strlen(str.c_str()));
		std::cout.write("\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 3);
		std::cout.write("phonenumber: ", 13);
		std::cout.write(str.c_str() , strlen(str.c_str()));
		std::cout.write("\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 4);
		std::cout.write("darket secret: ", 15);
		std::cout.write(str.c_str() , strlen(str.c_str()));
		std::cout.write("\n", 1);
	}
	return (1);
}

void PhoneBook::print_basic_info(Contact *contacts, int ft_index)
{
	std::string to_display;	
	int			ind;

	ind = -1;
	while(++ind < 4)
	{
		if (ind == 0)
			to_display = contacts[ft_index].get_values(5);
		else if (ind == 1)
			to_display = contacts[ft_index].get_values(0);
		else if (ind == 2)
			to_display = contacts[ft_index].get_values(1);
		else if (ind == 3)
			to_display = contacts[ft_index].get_values(2);
		print10_right_alighed(to_display, strlen(to_display.c_str()));
	}
	std::cout.write("\n", 1);
}

static int all_alphanum(const char *str, int ind)
{
	int i = -1;
	while(str[++i])
	{
		if (ind == 1 && !(std::isalnum(str[i])))
			return (0);
		else if (ind == 0 && !(std::isalnum(str[i])) && !(std::isspace(str[i])))
			return (0);
	}
	return (1);
}

 int all_num(const char *str)
{
	int i = -1;
	while(str[++i])
	{
		if (!(std::isdigit(str[i])))
			return (0);
	}
	return (1);
}

void PhoneBook::add_to_contact(int ind, Contact *contacts,  int ft_index)
{
	std::string line;
	const char	*res;
	const char	*input;
	int			i;
	int		check;

    if (std::cin.eof())
            exit(0);
	if (ind == 0)
		input = "firstname: ";
	else if (ind == 1)
		input = "lastname: ";
	else if (ind == 2)
		input = "nickname: ";
	else if (ind == 3)
		input = "phonenumber: ";
	else if (ind == 4)
		input = "darkest secret: ";
	i = 0;
	while(1)
	{
		std::cout << input;
		std::getline(std::cin, line, '\n');
		if (std::cin.eof() && std::cout.write("\n", 1))
            return ;
		res = line.c_str();
		if (!res)
            return ;
		if (ind == 4)
			check = all_alphanum(line.c_str(), 0);
		else if (ind != 3)
			check = all_alphanum(line.c_str(), 1);
		else if (ind == 3)
			check = all_num(line.c_str());
		if ((++i && (!strcmp(res, ""))) || (!check) || (!check && ind == 3))
			continue ;
		contacts[ft_index % 8].set_the_values(line, ind);
		break ;
	}
}

void	PhoneBook::print_all_contacts(PhoneBook ph)
{
	int i  = -1;
	std::cout.write("--------------------------------------------\n", 45);
	print10_right_alighed("index", 5);
	print10_right_alighed("firstname", 9);
	print10_right_alighed("lastname", 8);
	print10_right_alighed("nickname", 8);
	std::cout.write("\n", 1);
	std::cout.write("|------------------------------------------|\n", 45);
	while(i++ < ph.get_i_value())
		ph.print_basic_info(ph.get_values(), i);
}