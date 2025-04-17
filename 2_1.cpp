#include<iostream>
using namespace std;

class plot {
public:
    float length;
    float width;

    void set_dimension(float l, float w) {
        length = l;
        width = w;
    }

    void update_dimension(float l, float w) {
        length = l;
        width = w;
    }

    void display_plot() {
        float area = length * width;
        float perimeter = 2 * (length + width);

        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
    }
};

int main() {
    plot plots[10];
    int num_plots;

    cout << "Enter the number of plots you want to enter (max 10): ";
    cin >> num_plots;

    if (num_plots < 1 || num_plots > 10) {
        cout << "Invalid number of plots. Please enter a number between 1 and 10" << endl;
        return 1;
    }

    int choice;
menu:
    cout << "\nMenu:\n";
    cout << "1. Set dimensions for plots\n";
    cout << "2. Update dimensions for a plot\n";
    cout << "3. Display a plot\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            for (int i = 0; i < num_plots; i++) {
                float l, w;
                cout << "Enter the length and width for Plot " << (i + 1) << ": ";
                cin >> l >> w;
                plots[i].set_dimension(l, w);
            }
            break;
        }

        case 2: {
            int plot_number;
            cout << "Enter the plot number to update (1 to " << num_plots << "): ";
            cin >> plot_number;
            if (plot_number < 1 || plot_number > num_plots) {
                cout << "Invalid plot number." << endl;
            } else {
                float l, w;
                cout << "Enter the new length and width for Plot " << plot_number << ": ";
                cin >> l >> w;
                plots[plot_number - 1].update_dimension(l, w);
            }
            break;
        }

        case 3: {
            int plot_number;
            cout << "Enter the plot number to display (1 to " << num_plots << "): ";
            cin >> plot_number;
            if (plot_number < 1 || plot_number > num_plots) {
                cout << "Invalid plot number." << endl;
            } else {
                cout << "Plot " << plot_number << ":" << endl;
                plots[plot_number - 1].display_plot();
            }
            break;
        }

        case 0:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
    }

    goto menu;
    return 0;
}
