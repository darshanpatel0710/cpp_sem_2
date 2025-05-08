#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare_scores(const pair<string, int>& student1, const pair<string, int>& student2) {
    return student1.second > student2.second;
}

int main() {
    vector<pair<string, int>> student_list;
    int num_students;
    string student_name;
    int student_score;

    cout << "Enter the number of students: ";
    cin >> num_students;

    cout << "Enter student name and score:\n";
    for (int i = 0; i < num_students; ++i) {
        cin >> student_name >> student_score;
        student_list.push_back(make_pair(student_name, student_score));
    }

    sort(student_list.begin(), student_list.end(), compare_scores);

    cout << "\nRanked List of Students (Highest Score First):\n";
    int rank = 1;
    for (vector<pair<string, int>>::iterator it = student_list.begin(); it != student_list.end(); ++it) {
        cout << "Rank " << rank << ": " << it->first << " - Score: " << it->second << endl;
        ++rank;
    }

    cout << "24CE076_PatelDarshan";
    return 0;
}
