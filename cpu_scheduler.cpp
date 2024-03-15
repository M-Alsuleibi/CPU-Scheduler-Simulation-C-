#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

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
	int Size;
	int WT;
	int TA;
	int ST;
	int CT;
	int priority;
};


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

		int mSize, pSize, Q, CS;
		while (fin)
		{

			fin >> mSize >> pSize >> Q >> CS;
			for (int i = 0; i < 5; i++)
			{
				fin >> PCB[i].PID;
				fin >> PCB[i].AT;
				fin >> PCB[i].CPUB;
				fin >> PCB[i].Size;
                // Initially for debugging testing
                cout << "Process " << i + 1 << ": PID=" << PCB[i].PID << ", AT=" << PCB[i].AT << ", CPUB=" << PCB[i].CPUB << ", Size=" << PCB[i].Size << endl;

			}
		}
    
		fin.close();

		
	}
}