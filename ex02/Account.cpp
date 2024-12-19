#include "Account.hpp"
#include <iostream>
#include <sys/time.h>

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex;
    std::cout<<";amount:"<<_amount;
    std::cout<<";deposits:"<<_nbDeposits;
    std::cout<<";withdrawals:"<<_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout.write("accounts:", 9);
    std::cout << getNbAccounts();
    std::cout.write(";total:", 7);
    std::cout << getTotalAmount();
    std::cout.write(";deposits:", 10);
    std::cout << getNbDeposits();
    std::cout.write(";withdrawals:", 13);
    std::cout << getNbWithdrawals() << std::endl;
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex;
    std::cout<<";p_amount:"<<_amount;
    _totalAmount += deposit;
    _amount += deposit;
    std::cout<<";deposit:"<< deposit;
    _nbDeposits++;
    std::cout<<";amount:"<<_amount;
    std::cout<<";nb_deposits:"<< _nbDeposits << std::endl;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex;
    std::cout<<";p_amount:"<<_amount;
    std::cout<<";withdrawal:";
    if (withdrawal > _amount)
        return (std::cout << "refused\n", false);
    else
        std::cout << withdrawal;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    _nbWithdrawals++;
    std::cout<<";amount:"<<_amount;
    std::cout<<";nb_withdrawals:"<< _nbWithdrawals << std::endl;
    _totalNbWithdrawals++;
    return (true);
}

Account::Account( int initial_deposit )
{
    Account::_displayTimestamp();
    static int index;
    _nbAccounts = index + 1;
    _nbDeposits = 0;
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _accountIndex = index;
    _totalAmount += initial_deposit;
    std::cout << "index:" << index << ";amount:" << initial_deposit << ";created\n";
    index++;

}

Account::~Account()
{
    static char arr[7][50];
    static int i;
    int len = 0;
    std::string str;
    if (_accountIndex != 0)
    {
        strncpy(arr[i], "index:", 7);
        len = strlen("index:");
        str = std::to_string(_accountIndex);
        strncpy(arr[i] + len, str.c_str(), strlen(str.c_str()));
        len += strlen(str.c_str());
        strncpy(arr[i] + len, ";amount:", 8);
        len +=  strlen(";amount:");
        str = std::to_string(_amount);
        strncpy(arr[i] + len, str.c_str(), strlen(str.c_str()));
        len += strlen(str.c_str());
        strncpy(arr[i] + len, ";closed", 7);
        i++;
    }
    else
    {
        Account::_displayTimestamp();
        std::cout<<"index:"<<_accountIndex;
        std::cout<<";amount:"<<_amount;
        std::cout<<";closed\n";
        int i = 7;
        while (--i >= 0)
        {
            Account::_displayTimestamp();
            std::cout << arr[i] << std::endl;
        }
    }
}

void	Account::_displayTimestamp( void )
{
    struct timeval time;

    gettimeofday(&time, NULL);
    std::cout<<"["<<time.tv_sec % 100000000<<"_"<<time.tv_usec<<"] ";
}

/*

            INITIALISATION IN C++
    -1) copy initialization ----> var_name = value;
    -1) parenthese initialization ----> var_name(value);
    -1) braces initialization ----> var_name{value};

            VECTORS
    DEFINE AND CREATE ONE
    -1) first include the specific header for vector #include<vector>
    -2) std::vector<int>   var_name; // 


    BASIC_FUNCTIONS
    ADD TO BACK =+>  .push_back();
    EDIT AT INDEX =+> .at(index_num);
    REMOVE THE LAST ONE =+> pop_back();

    ITERATING
    we can iterate through the objects using the loops (while, for, ...)
    and in c++ there is also another iterator we can use to iterate over our container like iterator


*/


// static variables cannot initialised inside constructors
