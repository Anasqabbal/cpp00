#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <unistd.h>

class Contact
{
public :
	std::string	firstname;
	std::string 	lastname;
	std::string 	nickname;
	std::string 	phone_number;
	std::string 	darkest_secret;
	std::string	index;
};

class PhoneBook
{
public :
	Contact contacts[8];
	int		i;

	void ft_add(Contact *contacts, int i, const std::string str, int ind);
	void ft_read(int ind, Contact *contacts,  int ft_index);
	void ft_search(Contact *contacts, int ft_index, int ii);
};

void PhoneBook::ft_search(Contact *contacts, int ft_index, int ii)
{
	const char	*to_display;
	int			ind;

	ind = -1;
	if (ft_index == 0)
	{
		puts("the index can't start from 0");
		return ;
	}
	else if (ft_index > 8)
	{
		puts("your index is out of the range");
		return ;
	}
	else
	{
		if (ft_index > ii)
		{
			printf("your have only %d at this time\n", ii);
			return ;
		}
		int i = 0;
		while(++ind < 4)
		{
			if (ind == 0)
				to_display = contacts[ft_index - 1].index.c_str();
			else if (ind == 1)
				to_display = contacts[ft_index - 1].firstname.c_str();
			else if (ind == 2)
				to_display = contacts[ft_index - 1].lastname.c_str();
			else if (ind == 3)
				to_display = contacts[ft_index - 1].nickname.c_str();
			i = -1;
			while(++i < 10)
			{
				if (i < 10 && i < strlen(to_display))
				{
					if (i == 9 && strlen(to_display) > 10)
						write(1, ".", 1);
					else
						write(1, &to_display[i], 1);
				}
				else if (i < 10)
					write(1, " ", 1);
			}
			if (i == 10 && ind <= 2)
				write(1, "|", 1);
		}
		write(1, "\n", 1);
	}
}

void PhoneBook::ft_add(Contact *contacts, int i, std::string str, int ind)
{
	if (ind == 0)
		contacts[i % 8].firstname = str;
	else if (ind == 1)
		contacts[i % 8].lastname = str;
	else if (ind == 2)
		contacts[i % 8].nickname = str;
	else if (ind == 3)
		contacts[i % 8].phone_number = str;
	else if (ind == 4)
		contacts[i % 8].darkest_secret = str;
}

void PhoneBook::ft_read(int ind, Contact *contacts,  int ft_index)
{
	std::string line;
	const char	*res;
	const char	*input;
	int			i;
	static int	e;

    if (std::cin.eof())
            exit(0);
	if (e++ == 0)
		std::getline(std::cin, line, '\n');
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
	std::cin.clear();
	while(1)
	{
		std::cout << input;
		std::getline(std::cin, line, '\n');
		if (std::cin.eof() && write(1, "\n", 1))
            return ;
		res = line.c_str();
		if (!res)
            return ;
		if (++i && (!strcmp(res, "")))
			continue;
		ft_add(contacts, ft_index, line, ind);
		break ;
	}
	if (e == 5)
		e = 0;
}
# endif