#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<string, vector<string>> directory_map;
    int choice;
    string folder_name, file_name;

    while (true) {
        cout << endl
             << "1. Create Folder" << endl
             << "2. Add File to Folder" << endl
             << "3. Display" << endl
             << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                getline(cin, folder_name);
                if (directory_map.count(folder_name) == 0) {
                    directory_map[folder_name] = {};
                    cout << "Folder created." << endl;
                } else {
                    cout << "Folder already exists." << endl;
                }
                break;

            case 2:
                cout << "Enter folder name: ";
                getline(cin, folder_name);
                cout << "Enter file name: ";
                getline(cin, file_name);
                directory_map[folder_name].push_back(file_name);
                cout << "File added to folder." << endl;
                break;

            case 3:
                cout << endl << "--- Directory Structure ---" << endl;
                for (map<string, vector<string>>::iterator it = directory_map.begin(); it != directory_map.end(); ++it) {
                    cout << "->" << it->first << endl;
                    vector<string>& file_list = it->second;
                    for (int i = 0; i < file_list.size(); ++i) {
                        cout << "  " << file_list[i] << endl;
                    }
                }
                break;

            case 4:
                cout << "Exiting..." << endl;
                cout << endl << "24CE076_PatelDarshan" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << endl << "24CE076_PatelDarshan" << endl;
        }
    }

    return 0;
}
