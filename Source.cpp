#include<iostream>
#include<string>
using namespace std;

const int sizeTaskManager = 20;
string planner[sizeTaskManager];
string planPriority[sizeTaskManager];
string tempstring;
int sizeIndex = 0; 
int planDate[sizeTaskManager][3]; 
int temp = 0;
string plannerCopy[sizeTaskManager];
string planPriorityCopy[sizeTaskManager];
int planDateCopy[sizeTaskManager][3];

void showTasks() {
	bool isEmpty = true;
	for (int i = 0; i < sizeIndex; i++) 
	{
		if (planDate[i][0] != 0) {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2];
			if (planPriority[i] == "c")
				cout << " => important" << endl;
			else if (planPriority[i] == "b")
				cout << " => middle priority" << endl;
			else if (planPriority[i] == "a")
				cout << " => not an priority" << endl;
		}
		isEmpty = false;
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}

void sortTasksbyPriority() {
	bool isEmpty = true;
	for (int i = 0; i < sizeTaskManager; i++) 
	{
		if (planPriority[i] == "c") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  high priotity" << endl;
			isEmpty = false;
		}
	}
	for (int i = 0; i < sizeTaskManager; i++) 
	{
		if (planPriority[i] == "b") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  medium priority" << endl;
			isEmpty = false;
		}
	}
	for (int i = 0; i < sizeTaskManager; i++) 
	{
		if (planPriority[i] == "a") {
			cout << planner[i] << "  " << planDate[i][0] << "." << planDate[i][1] << "." << planDate[i][2] << " --  low priority" << endl;
			isEmpty = false;
		}
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}

void sortTasksbyDate() {			
	bool isEmpty = true;
	for (int i = 0; i < sizeIndex; i++)
	{
		for (int j = 0; j < sizeIndex; j++)
		{
			if (planDateCopy[j][2] > planDateCopy[i][2]) {		
				temp = planDateCopy[i][2];						
				planDateCopy[i][2] = planDateCopy[j][2];
				planDateCopy[j][2] = temp;
				temp = planDateCopy[i][1];						
				planDateCopy[i][1] = planDateCopy[j][1];
				planDateCopy[j][1] = temp;
				temp = planDateCopy[i][0];						
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
			else if (planDateCopy[j][1] > planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {			
				temp = planDateCopy[i][1];						
				planDateCopy[i][1] = planDateCopy[j][1];
				planDateCopy[j][1] = temp;
				temp = planDateCopy[i][0];						
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
			else if (planDateCopy[j][0] > planDateCopy[i][0] && planDateCopy[j][1] == planDateCopy[i][1] && planDateCopy[j][2] == planDateCopy[i][2]) {		
				temp = planDateCopy[i][0];						
				planDateCopy[i][0] = planDateCopy[j][0];
				planDateCopy[j][0] = temp;
				tempstring = plannerCopy[i];
				plannerCopy[i] = plannerCopy[j];
				plannerCopy[j] = tempstring;
			}
		}
	}

	for (int i = 0; i < sizeIndex; i++)
	{
		if (planDateCopy[i][0] != 0) {
			cout << plannerCopy[i] << "  " << planDateCopy[i][0] << "." << planDateCopy[i][1] << "." << planDateCopy[i][2];
			if (planPriorityCopy[i] == "c")
				cout << " --  high priotity" << endl;
			else if (planPriorityCopy[i] == "b")
				cout << " --  medium priority" << endl;
			else if (planPriorityCopy[i] == "a")
				cout << " --  low priority" << endl;
		}
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}

void sortTaskABC() {  
	bool isEmpty = true;
	int lenA, lenB, lenLow; 
	for (int i = 0; i < sizeIndex; i++)
	{
		for (int j = i; j < sizeIndex; j++)
		{
			string a = plannerCopy[i];		
			string b = plannerCopy[j];
			lenA = plannerCopy[i].length();
			lenB = plannerCopy[j].length();
			if (lenA > lenB) {			
				lenLow = lenB;
			}
			else {
				lenLow = lenA;
			}
			

			for (int l = 0; l < lenLow;)
			{
				
				if (a[l] == b[l]) {
					l++;
				}
				else if (a[l] > b[l]) {
					temp = planDateCopy[i][2];						
					planDateCopy[i][2] = planDateCopy[j][2];
					planDateCopy[j][2] = temp;
					temp = planDateCopy[i][1];						
					planDateCopy[i][1] = planDateCopy[j][1];
					planDateCopy[j][1] = temp;
					temp = planDateCopy[i][0];					
					planDateCopy[i][0] = planDateCopy[j][0];
					planDateCopy[j][0] = temp;
					tempstring = plannerCopy[i];					
					plannerCopy[i] = plannerCopy[j];
					plannerCopy[j] = tempstring;
					l = lenLow;
				}
			}

		}
	}
	for (int i = 0; i < sizeTaskManager; i++)
	{
		if (planDateCopy[i][0] != 0) {
			cout << plannerCopy[i] << "  " << planDateCopy[i][0] << "." << planDateCopy[i][1] << "." << planDateCopy[i][2];
			if (planPriorityCopy[i] == "c")
				cout << " --  high priotity" << endl;
			else if (planPriorityCopy[i] == "b")
				cout << " --  medium priority" << endl;
			else if (planPriorityCopy[i] == "a")
				cout << " --  low priority" << endl;
		}
		isEmpty = false;
	}
	if (isEmpty == true) {
		cout << "List is empty!" << endl;
	}
}

void addtask(string nameOftask, int date, string priority) {
	int day, month, year;
	year = date % 10000;
	day = date / 1000000;
	month = (date / 10000) % 100;

	if (sizeIndex < sizeTaskManager) {			
		planner[sizeIndex] = nameOftask;
		planDate[sizeIndex][0] = day;
		planDate[sizeIndex][1] = month;
		planDate[sizeIndex][2] = year;
		planPriority[sizeIndex] = priority;
		plannerCopy[sizeIndex] = nameOftask;
		planDateCopy[sizeIndex][0] = day;
		planDateCopy[sizeIndex][1] = month;
		planDateCopy[sizeIndex][2] = year;
		planPriorityCopy[sizeIndex] = priority;
		sizeIndex++;
	}
	else {
		cout << "planner is full" << endl;
	}
	cout << endl;
}

void removeTask(int indexOftask) {
	planner[indexOftask] = "";
	string tempArray[sizeTaskManager];
	int tempIndex = 0;
	for (string item : planner)
	{
		if (item != "") {
			tempArray[tempIndex] = item;
			tempIndex++;
		}
	}
	for (int i = 0; i < sizeTaskManager; i++)
	{
		planner[i] = tempArray[i];
	}
	cout << endl;
}

void managerTasks() {
	int action = 0;

	do
	{
		cout << "1.Show all tasks" << endl;
		cout << "2.Remove task" << endl;
		cout << "3.Add task" << endl;
		cout << "4.Exit" << endl;
		cout << endl;
		cout << "Select option -> ";
		cin >> action;

		switch (action)
		{
		case 1: {
			action = 0;
			system("cls");
			cout << "What sorting would you prefer?" << endl;
			cout << "1. By priority." << endl;
			cout << "2. By date." << endl;
			cout << "3. Show as added." << endl;
			cout << endl;
			cout << "Select option -> ";
			cin >> action;
			switch (action)
			{
			case 1: {
				system("cls");
				sortTasksbyPriority();
			}break;

			case 2: {
				system("cls");
				sortTasksbyDate();
			}break;

			case 3: {
				system("cls");
				showTasks();
			}break;
			}

		}break;

		case 2: {
			system("cls");
			int tempNumber = 0;
			cout << "Enter number for delete: ";
			cin >> tempNumber;
			removeTask(tempNumber - 1);
		}break;

		case 3: {
			system("cls");
			string temp, temp3;
			int temp2;
			cout << "Enter event name: ";
			cin.ignore();
			getline(cin, temp);
			cout << "Enter date: ";
			cin >> temp2;
			cout << "Enter event priority: ";
			cin >> temp3;
			addtask(temp, temp2, temp3);
		}break;

		case 4: {
			cout << "Goodbye" << endl;
		}break;

		}
	} while (action != 4);
}

int main() {

	managerTasks();

	return 0;
}