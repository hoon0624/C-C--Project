#include <stdio.h>
#include <stdlib.h>

void decToBinary(int n)
{
	int binaryNum[32];

	int i=0; 

	while (n > 0) {
		binaryNum[i] = n%2;
		n = n/2;
		i++;
	}

	for (int j = i-1; j>=0; j--) {
		printf("%d", binaryNum[j]);
	}

}

int main()
{
	int a;
	char *data = getenv("QUERY_STRING");
	sscanf(data, "decNum=%d", &a);

	printf("Content-Type:text/html\n\n");
	printf("<html>");
	printf("<body>");

	decToBinary(a);

	printf("</body>");
	printf("</html>");

	return 0;
}

