#include "fdf.h"

int       init_display(t_env *env)
{
    if(!(env->mlx = mlx_init()) ||
        !(env->win = mlx_new_window(env->mlx, 1366, 768, "fdf")))
            return (1);
    mlx_expose_hook(env->win, expose_hook, env);
    mlx_loop(env->mlx);
    return (0);
}
