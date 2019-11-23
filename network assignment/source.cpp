#include<iostream>
#include<ctime>
#include<cstdlib>
#include <time.h>
using namespace std;

#define Max_pkt 3

int main()
{
	clock_t start, end;
	int frame_nr;//number of frames
	int seq_nr;//max seq
	int no_tr = 0;
	srand(time(NULL));
	string data;
	cout << "Enter data: ";
	cin >> data;

	frame_nr = ceil(data.length() / Max_pkt);
	cout << "frame no" << frame_nr << endl;

	cout << "Enter the Max seq : ";
	cin >> seq_nr;
	int i = 1;
	int count = 0;
	while (i <= frame_nr)
	{
		int x = 0;

		for (int j = i; j < i + seq_nr && j <= frame_nr; j++)
		{

			cout << "Sent Data Frame " << j << " : ";
			for (int w=0;  w< 3 && count < data.length(); w++,count++)
			{
				cout << data[count];
			}
			cout << endl;
			//function start timer
			cout << "Start time of Frame " << j << endl;

			start = clock();
			no_tr++;

		}
		cout << ".............................................." << endl;
		int flag2=0;
		for (int j = i; j < i + seq_nr && j <= frame_nr; j++)
		{
			end = clock();
			double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			if (cpu_time_used > 0.03)
			{
				flag2 = 1;
			}


			int flag = rand() % 2;
			if ( (!flag2 ) && (!flag ))
			{
				count = (j - 1) * Max_pkt;
				cout << "Recieve Data Frame " << j << " : ";
				for (int w = 0; w < 3 && count < data.length(); w++, count++)
				{
					cout << data[count];
				}
				cout << endl;

				cout << "Acknowledgment for Frame " << j << endl;
				cout << "Stop timer for Frame "<< j<< endl;
				x++;
			}
			else
			{
				cout << "Time out for frame" << j << endl;
				cout << "Frame " << j << " Not Received" << endl;
				cout << "Retransmitting Window" << endl;
				count = (j - 1) * Max_pkt;
				break;
			}

		}
		cout << ".............................................." << endl;
		i += x;
	}
	cout << "Total number of transmissions : " << no_tr << endl;
	return 0;
}


