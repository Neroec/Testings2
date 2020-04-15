#include <stdio.h>
#include <string.h>

int main()
{
    char line[255] = {"\0"};
    
    printf("%d\n", (int) strlen(line));
    
    return 0;
}
