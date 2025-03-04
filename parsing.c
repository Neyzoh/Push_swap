#include "push_swap.h"
//faire la distinction d'un tableau de chaine de charactere 
char **create_args_tab(int ac, char **av, int *malloc_flag)
{
    char **tab;

    tab = NULL;
    if (ac == 2)
    {
        tab = ft_split(av[1], ' ');
        *malloc_flag = 1;
    }
    else if (ac > 2)
        tab = av + 1;
    return (tab);
}
void    ft_exit_error(char **args, int malloc_flag)
{
    //affiche l'erreur libft
    ft_putstr_fd("Error\n", 2); // 2 = sortie erreur
    //free tout ce qui a ete malloc args tab + liste chainee ou int tab
    if (malloc_flag)
        ft_free_tab(args);
    //exit error
    exit(1);
}
int *parsing(int ac, char **av)
{
    int malloc_flag;
    char **args_tab;
    int i;

    malloc_flag = 0;
    args_tab = create_args_tab(ac, av, &malloc_flag);
    i = 0;
    //parcourir args_tab et verifier si il y a des erreurs si oui exit_error
    while (args_tab[i])
    {
        if (!is_numeric(args_tab[i]) || !is_int_limit(args_tab[i]))
            ft_exit_error(args_tab, malloc_flag);
        i++;
    }
    if (!is_doublon(args_tab))
        ft_exit_error(args_tab, malloc_flag);
    if (malloc_flag)
        ft_free_tab(args_tab);
    return(0);
}
int main(int argc, char **argv)
{
    if (argc < 2)
        ft_exit_error(argv, 0);
    parsing(argc, argv);
    // Continuer avec le reste de votre programme
    // ...
    return (0);
}