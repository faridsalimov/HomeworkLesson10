#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

class Student {
public:
	static int idCounter;
	int id;
	string name;
	string surname;
	int average;

	Student() {
		id = idCounter++;
		name = "";
		surname = "";
		average = 0;
	}

	Student(string name, string surname, int average) {
		id = idCounter++;
		this->name = name;
		this->surname = surname;
		this->average = average;
	}

	void Show() {
		cout << "====================\n";
		cout << "ID: " << id << "\nName: " << name << "\nSurname: " << surname << "\nAverage: " << average << "\n";
		cout << "====================\n";
	}
};

int Student::idCounter = 1;

class StudentQueue {
public:
	vector<Student> students;

	bool IsEmpty() const { return students.empty(); }

	void Enqueue(const Student& student) {
		students.push_back(student);
	}

	void Dequeue() {
		if (!students.empty())
			students.erase(students.begin());
	}

	Student& Front() { return students.front(); }
};

class Printer {
public:
	StudentQueue queue;

	void AddStudent(const Student& student) {
		queue.Enqueue(student);
	}

	void Start() {
		while (!queue.IsEmpty())
		{
			Student student = queue.Front();
			system("cls");
			student.Show();
			Sleep(1000);
			queue.Dequeue();
		}
	}
};

void main() {
	Printer st;
	st.AddStudent(Student("Ferid", "Selimov", 100));
	st.AddStudent(Student("Rinat", "Qedimov", 95));
	st.AddStudent(Student("Yusif", "Seyidov", 92));

	st.Start();
}