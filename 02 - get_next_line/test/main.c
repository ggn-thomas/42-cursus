#include "get_next_line_bonus.h"
#include <stdio.h>
/*int main()
{
	char	*str1;
	char	*str2;
	int 	fd1;
	int	fd2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	do 
	{
		str1 = get_next_line(fd1);
		str2 = get_next_line(fd2);
		if((str1 != NULL) && (str2 != NULL))
		{
			printf("%s",str1);
			printf("%s",str2);
			free(str1);
			free(str2);
		}
	}while ((str1 != NULL) && (str2 != NULL));
	close(fd1);
	close(fd2);
}*/

int	main(void)
{
	char *str;
	int fd1 = 42;//open("test.txt", O_RDONLY);
	//int fd2 = open("test2.txt", O_RDONLY);
	str = get_next_line(fd1);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		//str = get_next_line(fd2);
		//printf("%s", str);
		//free(str);
		str = get_next_line(fd1);
	}
	free(str);
	close(fd1);
	//close(fd2);
}
