#include "fdf.h"

static int parse_file(char *file)
{
  int   fd;
  int   ret;
  char  *line;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (ft_error_retint("File not found\n", 1));
  while ((ret = get_next_line(fd, &line)) == 1)
  {
    ft_printf("Line: %s\n", line);
  }
  return (0);
}

int     init_data(t_env *env, int ac, char **av)
{
  int ret;

  if (ac != 2)
      return (ft_error_retint("Invalid args\nUsage: ./fdf file.fdf\n", 1));
  if ((ret = parse_file(av[1])))
      return (1);
  (void)env;
  return (0);
}
