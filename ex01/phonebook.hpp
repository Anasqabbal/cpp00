#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <iomanip>

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

class PhoneBook
{
private :
	Contact contacts[8];
	int		i;
	std::string		get_contact_value(Contact *contacts, int index, int ind);

public :
	int			get_i_value(void);
	void		set_i_value(int val);
	Contact		*get_values(void);
	void		set_value_to_index(Contact *contact, int index, int inde);
	void		add_to_contact(int ind, Contact *contacts, int ft_index);
	void		print_basic_info(Contact *contacts, int ft_index);
	void		print_all_contacts(PhoneBook ph);
	int			print_specific_contact(PhoneBook ph, int index);
};

void	print10_right_alighed(std::string str, int len);
int		all_num(const char *str);

# endif