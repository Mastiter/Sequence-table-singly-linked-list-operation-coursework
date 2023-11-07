#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a=0,d=0,n;
	char input[51] = {0};
	gets_s(input,50);
    if (strlen(input) >= 50)
    {
        printf("daimei");
        return 1;
    }
    else{
        n = strlen(input);
        for (int i = 0; i < n; i++)
        {
            if (input[i] == 'a')
            {
                a += 1;
            }
            else if (input[i] == 'd')
            {
                d += 1;
            }
        }
        printf("a:%d,d:%d", a, d);
        system("pause");
        return 0;
    }
}
/*这个错误通常意味着您的代码尝试写入超出数组边界的内存位置，导致堆栈破坏。在您的代码中，这可能是由于输入字符串超过了数组 input 的大小引起的。

为了解决这个问题，您可以增加数组 input 的大小，以确保足够容纳输入字符串。另外，建议使用更安全的输入函数 fgets，以避免潜在的缓冲区溢出问题。

以下是修改后的代码：

c
复制
#include <stdio.h>
#include <string.h>

int main()
{
    int a = 0, d = 0, n;
    char input[51];
    fgets(input, sizeof(input), stdin);
    n = strlen(input);
    
    for (int i = 0; i < n; i++)
    {
        if (input[i] == 'a')
        {
            a += 1;
        }
        else if (input[i] == 'd')
        {
            d += 1;
        }
    }
    
    printf("a:%d,d:%d", a, d);
    return 0;
}
在修改后的代码中，我们使用 fgets 函数来读取输入字符串，并指定了输入字符串的最大长度为 50（包括空字符）。这样可以确保输入字符串不会超出数组 input 的大小。

请注意，fgets 函数会将输入字符串的换行符 \n 也读取到字符串中。如果您不希望包含换行符，可以在统计字符之前将其去除，例如使用 strcspn 函数：

c
复制
// ...
fgets(input, sizeof(input), stdin);
input[strcspn(input, "\n")] = '\0'; // 去除换行符
n = strlen(input);
// ...
这样可以确保输入字符串不包含换行符，而且不会超出数组 input 的大小。*/
/*#include <stdio.h>
#include <string.h>

int main()
{
    int a = 0, d = 0, n;
    char input[51];
    gets_s(input, sizeof(input));
    n = strlen(input);
    
    for (int i = 0; i < n; i++)
    {
        if (input[i] == 'a')
        {
            a += 1;
        }
        else if (input[i] == 'd')
        {
            d += 1;
        }
    }
    
    printf("a:%d,d:%d", a, d);
    system("pause");
    return 0;
}*/
/*在条件判断语句中，您使用了赋值操作符=而不是相等比较操作符==。在判断字符相等时，应该使用双等号==进行比较。因此，将if (input[i] = 'a')和else if (input[i] = 'd')修改为if (input[i] == 'a')和else if (input[i] == 'd')。

由于您使用了gets_s函数来读取输入字符串，但是在代码开头没有包含相应的头文件#include <string.h>，因此需要添加该头文件以使用strlen函数。*/