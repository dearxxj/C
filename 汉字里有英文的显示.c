#include <stdio.h>
 char str[]="��������englishҲ����ȷ��ʾ";
 int main() {
  int i = 0;
  while (str[i] != '\0') {
    if(str[i] < 0) {
    	printf("%c%c", str[i], str[i+1]);
       	i++;
    }
    else 
    	printf("%c", str[i]);
    i++;
	}
  return 0;
}
