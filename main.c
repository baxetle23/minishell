#include <stdlib.h>
#include <unistd.h>
 
void    infinit_pipe(char ***cmd)
{
  int   p[2];
  pid_t pid;
  int   fd_in = 0;
  int   i = 0;
 
 while (cmd[i] != NULL)
    {
      pipe(p);
      if ((pid = fork()) == -1)
        {
          exit(1);
        }
      else if (pid == 0)
        {
          dup2(fd_in, 0);
          if (cmd[i+1] != NULL)
            dup2(p[1], 1);
          close(p[0]);
          execvp((cmd)[i][0], cmd[i]);
          exit(2);
        }
      else
        {
          wait(NULL);
          close(p[1]);
          fd_in = p[0];
          i++;
        }    }
}
 
int main()
{
  char *ls[] = {"ls", NULL};
  char *grep[] = {"find", ".", "-name", "*", NULL};
  char *wc[] = {"wc", NULL};
  char **cmd[] = {ls, grep, wc, NULL};
 
  infinit_pipe(cmd);
}