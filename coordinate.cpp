#include <iostream>
#include <cmath>
#include "coordinate.h"

using namespace std;

int list_length(Coordinate *list_beginning)
{
    int count = 0;
    Coordinate *current = list_beginning;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

void add_coordinate(Coordinate *&list_beginning, Coordinate *&list_end, float x, float y)
{
    Coordinate *new_node = new Coordinate;

    new_node->x = x;
    new_node->y = y;
    new_node->coord_id = list_length(list_beginning) + 1;
    new_node->next = nullptr;
    new_node->previous = nullptr;

    if (list_beginning == nullptr)
    {
        list_beginning = new_node;
        list_end = new_node;
    }
    else
    {
        list_end->next = new_node;
        new_node->previous = list_end;
        list_end = new_node;
    }
}

void forward_display(Coordinate *list_beginning)
{
    Coordinate *current = list_beginning;

    cout << "Forward display:" << endl;

    while (current != nullptr)
    {
        cout << "ID: " << current->coord_id
             << "  x: " << current->x
             << "  y: " << current->y << endl;

        current = current->next;
    }

    cout << endl;
}

void backward_display(Coordinate *list_end)
{
    Coordinate *current = list_end;

    cout << "Backward display:" << endl;

    while (current != nullptr)
    {
        cout << "ID: " << current->coord_id
             << "  x: " << current->x
             << "  y: " << current->y << endl;

        current = current->previous;
    }

    cout << endl;
}

void delete_coordinate(Coordinate *&list_beginning, Coordinate *&list_end, int coord_id_to_delete)
{
    Coordinate *current = list_beginning;

    while (current != nullptr)
    {
        if (current->coord_id == coord_id_to_delete)
        {
            if (current->previous != nullptr)
            {
                current->previous->next = current->next;
            }
            else
            {
                list_beginning = current->next;
            }

            if (current->next != nullptr)
            {
                current->next->previous = current->previous;
            }
            else
            {
                list_end = current->previous;
            }

            delete current;
            cout << "Deleted coordinate with ID " << coord_id_to_delete << endl << endl;
            return;
        }

        current = current->next;
    }

    cout << "Coordinate ID " << coord_id_to_delete << " not found." << endl << endl;
}

void closest_to(Coordinate *list_beginning, float x, float y)
{
    if (list_beginning == nullptr)
    {
        cout << "List is empty. No closest coordinate can be found." << endl << endl;
        return;
    }

    Coordinate *current = list_beginning;
    Coordinate *closest = list_beginning;

    float dx = current->x - x;
    float dy = current->y - y;
    float smallest_distance = sqrt(dx * dx + dy * dy);

    current = current->next;

    while (current != nullptr)
    {
        dx = current->x - x;
        dy = current->y - y;
        float distance = sqrt(dx * dx + dy * dy);

        if (distance < smallest_distance)
        {
            smallest_distance = distance;
            closest = current;
        }

        current = current->next;
    }

    cout << "Target point: (" << x << ", " << y << ")" << endl;
    cout << "Closest coordinate is ID " << closest->coord_id
         << " at (" << closest->x << ", " << closest->y << ")" << endl;
    cout << "Distance: " << smallest_distance << endl << endl;
}

void delete_all(Coordinate *&list_beginning, Coordinate *&list_end)
{
    Coordinate *current = list_beginning;

    while (current != nullptr)
    {
        Coordinate *temp = current;
        current = current->next;
        delete temp;
    }

    list_beginning = nullptr;
    list_end = nullptr;
}