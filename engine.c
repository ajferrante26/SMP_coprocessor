#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	system("bash /root/threadmonster/libfiles/getIPcount.sh");
	system("bash /root/threadmonster/libfiles/getFilecount.sh");

	int numIPint;
	int numFILEint;
	int i=10;
	FILE* numIP;
	FILE* numFILE;

	printf("Priming file search engine\n");

	numIP = fopen("/root/threadmonster/files/numIP.txt", "r");
	fscanf(numIP, "%d", &numIPint);
	fclose(numIP);

	numFILE = fopen("/root/threadmonster/files/numFILE.txt", "r");
	fscanf(numFILE, "%d", &numFILEint);
	fclose(numFILE);

	while (numIPint>numFILEint && i<60)
	{
		printf("(%d seconds)Searching for files\n", i);
		i = i + 10;
		wait(10);
		system("bash /root/threadmonster/libfiles/getFilecount.sh");

		numFILE = fopen("/root/threadmonster/files/numFILE.txt", "r");
		fscanf(numFILE, "%d", &numFILEint);
		fclose(numFILE);
	}

	if (numIPint>numFILEint)
		printf("ERROR: Not all clients responded\n");

	system("ls /root/threadmonster/inbound >> /root/threadmonster/files/clientlist.txt");
	system("wc -l /root/threadmonster/files/clientlist.txt | cut -b 1 >> /root/threadmonster/files/numCLIENT.txt");
	system("> /root/threadmonster/files/tmp.txt");
	system("cat /root/threadmonster/files/clientlist.txt >> /root/thredmonster/files/tmp.txt");

	int numCLIENTint;
	FILE* numCLIENT;
	numCLIENT = fopen("/root/threadmonster/files/numCLIENT.txt", "r");
	fscanf(numCLIENT, "%d", &numCLIENTint);

	for (int j=0; j<numCLIENTint; j++)
	{
		system("bash /root/threadmonster/libfiles/transformlist.sh");
	}

	printf("START ENGINE HERE: /ROOT/THREADMONSTER/LIBFILES/COUNT.OUT");

	return 0;
}
