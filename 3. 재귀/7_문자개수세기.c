#pragma warning(disable:4996) 
#include <stdio.h>
#include <string.h>



int count(char ch[100], char a) {
	int l = strlen(ch);
	if (l == 1)
		return ch[0] == a;
	else {
		int tmp;

		tmp = ch[0] == a;

		for (int i = 0; i < l; i++) {
			ch[i] = ch[i + 1];
		}

		return tmp + count(ch, a);
	}


}

int main() {

	char ch[100], a;
	int l = strlen(ch);
	scanf("%s\n%c", ch, &a);

	printf("%d", count(ch, a));

	return 0;
};