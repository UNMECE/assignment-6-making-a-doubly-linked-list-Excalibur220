#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: ./main <number_of_coordinates>" << endl;
        return 1;
    }

    int num_coordinates = atoi(argv[1]);

    if (num_coordinates <= 0)
    {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    srand(time(0));

    Coordinate *list_beginning = nullptr;
    Coordinate *list_end = nullptr;

    for (int i = 0; i < num_coordinates; i++)
    {
        float x = static_cast<float>(rand() % 100);
        float y = static_cast<float>(rand() % 100);

        add_coordinate(list_beginning, list_end, x, y);
    }

    cout << "List length: " << list_length(list_beginning) << endl << endl;

    forward_display(list_beginning);
    backward_display(list_end);

    delete_coordinate(list_beginning, list_end, 3);

    cout << "List after deletion:" << endl;
    forward_display(list_beginning);
    backward_display(list_end);

    closest_to(list_beginning, 50.0f, 50.0f);

    delete_all(list_beginning, list_end);

    return 0;
}