#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// PCB
struct process
{

	int at, bt, pr, pno, wt;
};

process proc[5];
/*
	This struct identifies the process
	 PID: Process ID,
	 AT: Arrival Time,
	 CPUB: CPU Burst,
	 size: Size in Bytes,
	 ST: Starting Time,
	 CT: Completion Time,
	 WT: Waiting Time,
	 TA: Turn Around
*/
struct Process // process control block
{
	int PID;
	int AT;
	int CPUB;
	int WT;
	int TA;
	int ST;
	int CT;
	int priority;
};

// Using FCFS Algorithm to find Waiting time
void get_wt_time(int wt[], int processNum)
{
	// declaring service array that stores cumulative burst time
	int service[10];

	// Initilising initial elements of the arrays
	service[0] = proc[0].at;
	wt[0] = 0;

	for (int i = 1; i < processNum; i++)
	{
		service[i] = proc[i - 1].bt + service[i - 1];

		wt[i] = service[i] - proc[i].at;

		// If waiting time is negative, change it into zero

		if (wt[i] < 0)
		{
			wt[i] = 0;
		}
	}
}

void get_tat_time(int tat[], int wt[], int processNum)
{
	// Filling turnaroundtime array

	for (int i = 0; i < processNum; i++)
	{
		tat[i] = proc[i].bt + wt[i];
	}
}

int main()
{

	ifstream fin;
	ofstream fout;

	//// Saving text files into array
	// string Test_Files[4];
	// for (int i = 0; i < 4; i++)
	//{
	//	Test_Files[i] = "E:\\TT\\testfile_" + to_string(i + 1) + ".txt";
	// }

	for (int i = 0; i < 4; i++)
	{
		fin.open("processes.txt");
		if (!fin)
		{
			cerr << "Unable to open file";
			exit(1); // terminate with error
		}

		/*
			This vector is from process type that includes all information needed in this project
		*/
		vector<Process> PCB(5);

		/*
			Reading file content from the input files
			msize: Physical Memory Size,
			psize: Page size,
			Q: Round Robin Quantum,
			CS:Context Switch,
			PCB: Process Control Block that includes all processes
		*/

		int  Q, CS;
		while (fin)
		{

			fin >> Q >> CS;
			for (int i = 0; i < 5; i++)
			{
				fin >> PCB[i].PID;
				fin >> PCB[i].AT;
				fin >> PCB[i].CPUB;
                // Initially for debugging testing
                cout << "Process " << i + 1 << ": PID=" << PCB[i].PID << ", AT=" << PCB[i].AT << ", CPUB=" << PCB[i].CPUB  << endl;

			}
		}
    
		fin.close();

		
	}
}