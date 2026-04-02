#include <iostream>
#include "coordinate.h"
#include "main.h"
#include <random>
#include <iomanip>
#include <cmath>
#include <limits>   

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_coordinates>" << std::endl;
        return 1;
    }

    int numCoords = std::stoi(argv[1]);

    //  Setup Randomness
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distr(1.0f, 100.0f);

    Coordinate* head = nullptr;
    Coordinate* tail = nullptr;

    //  Build the List
    for (int i = 0; i < numCoords; ++i) {
        float rx = distr(gen);
        float ry = distr(gen);

        if (head == nullptr) {
            // First node: initialize both head and tail
            head = new Coordinate{rx, ry, 1, nullptr, nullptr};
            tail = head;
        } else {
            // Add to the end 
            add_coordinate(tail, rx, ry);
            // Move the tail pointer to the new last node
            tail = tail->next; 
        }
    }


    //  Display Length
    std::cout << "\nTotal Coordinates: " << list_length(head) << std::endl;

    //  Forward and Backward Display
    forward_display(head);
    backward_display(tail);

    //  Find Closest to a specific point (e.g., center 50,50)
    closest_to(head, 50.0f, 50.0f);

    //  Delete a specific ID (e.g., ID 2)
    std::cout << "\nDeleting ID 2..." << std::endl;
    delete_coordinate(head, 2);

    //  Final Display after deletion
    forward_display(head);

    //  CLEANUP
    Coordinate* current = head;
    while (current != nullptr) {
        Coordinate* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

void add_coordinate(Coordinate *list_end, float x, float y) {
    if (list_end == nullptr) return;

    Coordinate* newNode = new Coordinate;
    newNode->x = x;
    newNode->y = y;
    
    // Automatically increment ID based on the current tail's ID
    newNode->coord_id = list_end->coord_id + 1;
    
    newNode->next = nullptr;
    newNode->previous = list_end;
    
    // Link the old tail to the new node
    list_end->next = newNode;
}

//  Forward Display
void forward_display(Coordinate *list_beginning) {
    Coordinate* curr = list_beginning;
    std::cout << "Forward: ";
    while (curr != nullptr) {
        std::cout << "[" << curr->coord_id << ": " << std::fixed << std::setprecision(2) 
                  << curr->x << "," << curr->y << "] ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

//  Backward Display
void backward_display(Coordinate *list_end) {
    Coordinate* curr = list_end;
    std::cout << "Backward: ";
    while (curr != nullptr) {
        std::cout << "[" << curr->coord_id << ": " << curr->x << "," << curr->y << "] ";
        curr = curr->previous;
    }
    std::cout << "NULL" << std::endl;
}

//  List Length
int list_length(Coordinate *list_beginning) {
    int count = 0;
    Coordinate* curr = list_beginning;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}

//  Find Closest Coordinate
void closest_to(Coordinate *list_beginning, float x, float y) {
    if (list_beginning == nullptr) return;

    Coordinate* closest = nullptr;
    float min_dist = std::numeric_limits<float>::max();

    Coordinate* curr = list_beginning;
    while (curr != nullptr) {
        float dist = std::sqrt(std::pow(curr->x - x, 2) + std::pow(curr->y - y, 2));
        if (dist < min_dist) {
            min_dist = dist;
            closest = curr;
        }
        curr = curr->next;
    }

    if (closest) {
        std::cout << "Closest to (" << x << "," << y << ") is ID " << closest->coord_id
                  << " at (" << closest->x << "," << closest->y << ")" << std::endl;
    }
}

//  Delete Coordinate
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete) {
    Coordinate* curr = list_beginning;

    while (curr != nullptr) {
        if (curr->coord_id == coord_id_to_delete) {
            // Stitch the previous and next nodes together
            if (curr->previous != nullptr) {
                curr->previous->next = curr->next;
            }
            if (curr->next != nullptr) {
                curr->next->previous = curr->previous;
            }

            delete curr;
            std::cout << "Node " << coord_id_to_delete << " deleted." << std::endl;
            return;
        }
        curr = curr->next;
    }
    std::cout << "ID " << coord_id_to_delete << " not found." << std::endl;
}
