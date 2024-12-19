#include "Contact.hpp"

int	Contact::set_the_values(std::string str, char ind)
{
	if (ind == 0)
		firstname = str;
	else if (ind == 1)
		lastname = str;
	else if (ind == 2)
		nickname = str;
	else if (ind == 3)
		phone_number = str;
	else if (ind == 4)
		darkest_secret = str;
	return (0);
}

void Contact::set_index_value(int i)
{
	index = ((i % 8) + 48);
}

std::string	Contact::get_values(char ind)
{
	if (ind == 0)
		return (firstname);
	else if (ind == 1)
		return (lastname);
	else if (ind == 2)
		return (nickname);
	else if (ind == 3)
		return (phone_number);
	else if (ind == 4)
		return (darkest_secret);
	return (index.c_str());
}