#include <iostream>

 char ft_toupper(char *c)
{
    if (*c >= 97 && *c <= 122)
        return (*c -= 32, 1);
    return (0);
}

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    i = 0;
    while(++i < (ac))
    {
        j = 0;
        while (av[i][j] && av[i][j] == ' ')
            j++;
        while(av[i][j] && i < ac)
        {
            if (!av[i][j])
                break ;
            ft_toupper(&av[i][j]);
            std::cout << av[i][j];
            j++;
        }
        if ((i + 1) != ac)
            std::cout << " ";
    }
    std::cout << "\n";
}
