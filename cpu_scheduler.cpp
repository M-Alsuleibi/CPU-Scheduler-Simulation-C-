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

/*
	This function compares two processes pased on arrival time
	It takes two parameters
	First one is the first process
	Second one is the second process
	return boolean
	true if the second processs is bigger than the first process
	false if the second processs is smaller than the first process
*/
bool compareFCFS(const Process &a, const Process &b)
{
	return a.AT < b.AT;
}


	/*This function compares two processes pased on arrival time and CPU bursed time
	It takes two parameters
	First one is the first process
	Second one is the second process
	return boolean
	true if the second processs is bigger than the first process
	false if the second processs is smaller than the first process
*/
bool compareSFJ(const Process &a, const Process &b)
{
	return a.AT + a.CPUB < b.AT + a.CPUB;
}

/*
	This function applies FCFS algorithm (First Come First Serve)
	Takes two parameter PCB -> Process Contol Block,
						testFile -> Test File Number
	returns void
*/


void FCFS(vector<Process> PCB, int testFile)
{
	/*
			FCFS Algorithm
			FCFS is a struct that includes all the served processes based on FCFS algorithm
		*/

	vector<Process> FCFS(5);
	FCFS = PCB;

	// Sorting the vector by Arrival Time
	sort(FCFS.begin(), FCFS.end(), compareFCFS);

	// Calculating starting time and completion time
	// First process startes at time 0
	if (FCFS[0].AT > 0)
		FCFS[0].ST = FCFS[0].AT;
	else
		FCFS[0].ST = 0;

	FCFS[0].CT = FCFS[0].CPUB;

	for (int i = 1; i < 5; i++)
	{
		if (FCFS[i].AT > FCFS[i - 1].CT)
			FCFS[i].ST = FCFS[i].AT - FCFS[i - 1].CT;

		else
			FCFS[i].ST = FCFS[i - 1].CT;
		FCFS[i].CT = FCFS[i].ST + FCFS[i].CPUB;
	}

	// Calculating waiting time
	// First process has waiting time = 0
	FCFS[0].WT = 0;

	for (int i = 1; i < 5; i++)
	{
		// If the arrival time of the process is greater than or equal the starting
		// time of the process then waiting time is zero
		if (FCFS[i].AT >= FCFS[i].ST)
			FCFS[i].WT = 0;

		// otherwise it will equal to starting time - arrival time
		else
			FCFS[i].WT = FCFS[i].ST - FCFS[i].AT;
	}

	// Calculating turnaround time = completion time - arrival time
	for (int i = 0; i < 5; i++)
	{
		FCFS[i].TA = FCFS[i].CT - FCFS[i].AT;
	}

	// Calculating average waiting time
	double waitSum = 0;
	for (int i = 0; i < 5; i++)
	{
		waitSum += FCFS[i].WT;
	}
	double avarageWaitingTime = waitSum / 5.0;

	// Calculating average turnaround time Thus, CT – AT = TAT

	double turnSum = 0;
	for (int i = 0; i < 5; i++)
	{
		turnSum += FCFS[i].TA;
	}
	double avarageTurnTime = turnSum / 5.0;

	cout << endl
		 << endl;
	cout << "                         TEST FILE #" << testFile << endl;
	cout << endl
		 << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "                    FCFS ALGORITHM RESULT         " << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl
		 << endl;

	cout << "                    Process Control Block " << endl;
	cout << "         +-------------+--------------+-----------+" << endl;
	cout << "         | Process ID  | Arrival Time | CPU Burst |" << endl;
	cout << "         +-------------+--------------+-----------+" << endl;

	FCFS[3].PID = 3;
	FCFS[4].PID = 4;
	for (int i = 0; i < 5; i++)
	{

		cout << "                " << FCFS[i].PID << "              " << FCFS[i].AT << "           " << FCFS[i].CPUB << "     " << endl;
		cout << "         +-------------+--------------+-----------+" << endl;
	}

	// Printing finishing time, waiting time and turnaround time

	cout << endl
		 << endl;

	cout << "   +-------------+--------------+--------------+---------+" << endl;
	cout << "   | Process ID  | Finish Time  | Waiting Time | TA Time |" << endl;
	cout << "   +-------------+--------------+--------------+---------+" << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "          " << FCFS[i].PID << "            " << FCFS[i].CT << "              ";
		cout << FCFS[i].WT << "            " << FCFS[i].TA << endl;
		cout << "   +-------------+--------------+--------------+---------+" << endl;
	}

	// Printing Gnatt Chart

	cout << endl
		 << endl;
	cout << "                          Gnatt Chart" << endl
		 << endl;
	cout << "                    +----+----+----+----+----+" << endl;
	cout << "                    ";
	for (int i = 0; i < 5; i++)
	{
		cout << "  P" << FCFS[i].PID << " ";
	}
	cout << endl
		 << "                    ";
	cout << 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "---" << FCFS[i].CT;
	}

	cout << endl
		 << endl
		 << endl;
	cout << "Average Waiting Time: " << avarageWaitingTime << endl;
	cout << "Average TurnAround Time: " << avarageTurnTime << endl;
}

/*
	This function applies SJF algorithm (Shortest Job First)
	Takes one parameter PCB -> Process Contol Block
	returns void
*/
void SJF(vector<Process> PCB)
{
	/*
			SJF Algorithm
			SJF is a struct that includes all the served processes based on FCFS algorithm
		*/

	vector<Process> SJF(5);
	SJF = PCB;

	// Sorting the vector by Arrival Time
	sort(SJF.begin(), SJF.end(), compareSFJ);

	// Calculating starting time and completion time
	// First process startes at time 0
	if (SJF[0].AT > 0)
		SJF[0].ST = SJF[0].AT;
	else
		SJF[0].ST = 0;

	SJF[0].CT = SJF[0].CPUB;

	for (int i = 1; i < 5; i++)
	{
		if (SJF[i].AT > SJF[i - 1].CT)
			SJF[i].ST = SJF[i].AT - SJF[i - 1].CT;

		else
			SJF[i].ST = SJF[i - 1].CT;
		SJF[i].CT = SJF[i].ST + SJF[i].CPUB;
	}

	// Calculating waiting time
	// First process has waiting time = 0
	SJF[0].WT = 0;

	for (int i = 1; i < 5; i++)
	{
		// If the arrival time of the process is greater than or equal the starting
		// time of the process then waiting time is zero
		if (SJF[i].AT >= SJF[i].ST)
			SJF[i].WT = 0;

		// otherwise it will equal to starting time - arrival time
		else
			SJF[i].WT = SJF[i].ST - SJF[i].AT;
	}

	// Calculating turnaround time = completion time - arrival time
	for (int i = 0; i < 5; i++)
	{
		SJF[i].TA = SJF[i].CT - SJF[i].AT;
	}

	// Calculating average waiting time
	double waitSum = 0;
	for (int i = 0; i < 5; i++)
	{
		waitSum += SJF[i].WT;
	}
	double avarageWaitingTime = waitSum / 5.0;

	// Calculating average turnaround time
	double turnSum = 0;
	for (int i = 0; i < 5; i++)
	{
		turnSum += SJF[i].TA;
	}
	double avarageTurnTime = turnSum / 5.0;

	cout << endl
		 << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "                    SJF ALGORITHM RESULT         " << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl
		 << endl;

	// Printing finishing time, waiting time and turnaround time

	cout << endl
		 << endl;

	cout << "   +-------------+--------------+--------------+---------+" << endl;
	cout << "   | Process ID  | Finish Time  | Waiting Time | TA Time |" << endl;
	cout << "   +-------------+--------------+--------------+---------+" << endl;

	SJF[3].PID = 3;
	SJF[4].PID = 4;
	for (int i = 0; i < 5; i++)
	{
		cout << "          " << SJF[i].PID << "            " << SJF[i].CT << "              ";
		cout << SJF[i].WT << "            " << SJF[i].TA << endl;
		cout << "   +-------------+--------------+--------------+---------+" << endl;
	}

	// Printing Gnatt Chart

	cout << endl
		 << endl;
	cout << "                          Gnatt Chart" << endl
		 << endl;
	cout << "                    +----+----+----+----+----+" << endl;
	cout << "                    ";
	for (int i = 0; i < 5; i++)
	{
		cout << "  P" << SJF[i].PID << " ";
	}
	cout << endl
		 << "                    ";
	cout << 0;

	for (int i = 0; i < 5; i++)
	{
		cout << "---" << SJF[i].CT;
	}

	cout << endl
		 << endl
		 << endl;
	cout << "Average Waiting Time: " << avarageWaitingTime << endl;
	cout << "Average TurnAround Time: " << avarageTurnTime << endl;
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

	// for (int i = 0; i < 4; i++)
	// {
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
	
			Q: Round Robin Quantum
			CS:Context Switch,
			PCB: Process Control Block that includes all processes
		*/

		int Q, CS;
		while (fin)
		{

			fin >> Q >> CS;
			for (int i = 0; i < 5; i++)
			{
				fin >> PCB[i].PID;
				fin >> PCB[i].AT;
				fin >> PCB[i].CPUB;
				// Initially for debugging testing
				cout << "Process " << i + 1 << ": PID=" << PCB[i].PID << ", AT=" << PCB[i].AT << ", CPUB=" << PCB[i].CPUB << endl;
			}
		}

		fin.close();

		// Applying FCFS
		// FCFS(PCB, i + 1);
		FCFS(PCB,  1);


		// Applying SFJ
		SJF(PCB);
	// }
}