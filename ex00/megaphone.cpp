#include <iostream>
#include <cstring>

int   ex00_skip_spaces(char *c)
{
    int i = 0;

    while(c[i] && c[i] == ' ')
        i++;
    if (!c[i])
        return (0);
    return (i);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int c;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
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
            if (av[i][j] != ' ')
                std::cout.put(toupper(av[i][j]));
            c = ex00_skip_spaces(av[i] + j);
            if (c)
            {
                std::cout << " ";
                j += c;
            }
            else
                j += 1;
            c = 0;
        }
        if ((i + 1) != ac)
            std::cout << " ";
    }
    std::cout << "\n";
}
