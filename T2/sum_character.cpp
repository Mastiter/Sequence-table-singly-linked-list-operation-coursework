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
/*�������ͨ����ζ�����Ĵ��볢��д�볬������߽���ڴ�λ�ã����¶�ջ�ƻ��������Ĵ����У�����������������ַ������������� input �Ĵ�С����ġ�

Ϊ�˽��������⣬�������������� input �Ĵ�С����ȷ���㹻���������ַ��������⣬����ʹ�ø���ȫ�����뺯�� fgets���Ա���Ǳ�ڵĻ�����������⡣

�������޸ĺ�Ĵ��룺

c
����
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
���޸ĺ�Ĵ����У�����ʹ�� fgets ��������ȡ�����ַ�������ָ���������ַ�������󳤶�Ϊ 50���������ַ�������������ȷ�������ַ������ᳬ������ input �Ĵ�С��

��ע�⣬fgets �����Ὣ�����ַ����Ļ��з� \n Ҳ��ȡ���ַ����С��������ϣ���������з���������ͳ���ַ�֮ǰ����ȥ��������ʹ�� strcspn ������

c
����
// ...
fgets(input, sizeof(input), stdin);
input[strcspn(input, "\n")] = '\0'; // ȥ�����з�
n = strlen(input);
// ...
��������ȷ�������ַ������������з������Ҳ��ᳬ������ input �Ĵ�С��*/
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
/*�������ж�����У���ʹ���˸�ֵ������=��������ȱȽϲ�����==�����ж��ַ����ʱ��Ӧ��ʹ��˫�Ⱥ�==���бȽϡ���ˣ���if (input[i] = 'a')��else if (input[i] = 'd')�޸�Ϊif (input[i] == 'a')��else if (input[i] == 'd')��

������ʹ����gets_s��������ȡ�����ַ����������ڴ��뿪ͷû�а�����Ӧ��ͷ�ļ�#include <string.h>�������Ҫ��Ӹ�ͷ�ļ���ʹ��strlen������*/