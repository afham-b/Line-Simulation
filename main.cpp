#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

int main () {

	const int SIMULATION_TIME = 720;
	cout << fixed << setprecision(1);
	srand(time(0));

	queue<int> line;		// Queue of customer arrival times.
	int finish_time = -1;	// Time at which current customer will be finished.
						         	// -1 = no customer is in line.

	// For statistics about customers served
	int count_served = 0;
	int sum_wait_time = 0;
	int max_wait_time = 0;
	double average_wait_time;

	// For gathering line length statistics.
	int max_line_length = 0;
	int sum_line_length = 0;
	double average_line_length;

	for (int t = 0; t < SIMULATION_TIME; t++) {
		// Is current customer (if any) finished?
		if (t == finish_time) {
      finish_time= rand()%3 +1;  
		  sum_wait_time= sum_wait_time +finish_time; 	// TODO: Gather statistics about customer.
			line.pop();// TODO: Remove customer from queue.
			finish_time = -1;} // Reset finish time


		// Set up next customer? (Might not be a customer in line)
		if (finish_time == -1 && line.size() > 0)
			; // TODO: Set up customer...

		// 1 in 4 chance a customer arrives
		if (rand() % 4 == 0)
      count_served++; 
      line.push(t); 
      
		// TODO: Gather statistics about the line.
		//	(longest line, sum for average line length)
	}

	// Report the statistics
	average_wait_time = 1.0 * sum_wait_time / count_served;
	average_line_length = 1.0 * sum_line_length / SIMULATION_TIME;
	cout << "Customers served: " << count_served << endl;
	cout << "Average wait time: " << average_wait_time << endl;
	cout << "Longest wait time: " << max_wait_time << endl;
	cout << "Average line length: " << average_line_length << endl;
	cout << "Longest line: " << max_line_length << endl;

#ifdef _MSC_VER
	system("pause");
#endif
	return 0;
}



