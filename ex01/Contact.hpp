#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
private:
	std::string		firstname;
	std::string 	lastname;
	std::string 	nickname;
	std::string 	phone_number;
	std::string 	darkest_secret;
	std::string		index;
public :
	std::string		get_values(char ind);
	int				set_the_values(std::string str, char ind);
	void			set_index_value(int index);
};

#endif