#include <stdio.h>
#include <string.h>

int main()
{
   char *str1 = "abcd efgh ijkl";
   // const char str2[] = "\t";
   char *ret;

   ret = strpbrk(str1, " ");
   ret++;
   ret++;
   // ret += strspn(ret, " ");
   printf("%s\n", ret);

   return (0);
}
