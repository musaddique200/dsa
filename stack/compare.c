#include <stdio.h>
#include <stdlib.h>

int compare(char str[])
{
        size_t size = 0;
        int i = 0;
        while(str[size] != '\0')
        {
                size++;
        }
        printf("%d\n", size);
        char buffer1[] = {'{', '[', '('};
        char buffer2[] = {'}', ']', ')'};
        int flag = 1;
        for(int i = 0; i < size/2; i++)
        {
                for(int j = 0; j < 3; j++)
                {
                        if(str[i] == buffer1[j])
                        {
                                if(str[size-1-i] != buffer2[j])
                                {
                                        flag = 0;
                                }
                        }
                }
        }
        return flag;
}

int main(void)
{
        int n_times = 0;
        scanf("%d", &n_times);
        int *t_table = (int *)malloc(sizeof(int)*n_times); 
        for(int i = 0; i < n_times; i++)
        {
                char *str;
                printf("[%d].Enter string: ", i+1);
                scanf("%[^\n]s", str);
                if(compare(str) == 1) 
                {
                        t_table[i] = 1;
                }
                else
                {
                        t_table[i] = 0;
                }
        }

        for(int i = 0; i < n_times; i++)
        {
                if(t_table[i] == 1)
                {
                        printf("YES!\n");
                }
                else
                {
                        printf("NO!\n");
                }
        }
}
