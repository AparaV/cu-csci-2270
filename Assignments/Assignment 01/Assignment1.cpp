/** CSCI 2270-110  Data Structures
 ** Instructor: Rhonda Hoenigman
 ** TA: Yang Li
 ** Assignment 01
 ** Author: Aparajithan Venkateswaran
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//Item definition
struct Item{
    string type;
    bool wanted;
    unsigned int price;
};

//Prototypes
bool statusToBool(string);                      //Convert the item status into boolean
string boolToStatus(bool);                      //Convert boolean back to status
int findMatch(Item[], Item, int, int*);         //Find index of first match
void deleteItem(Item[], int, int*, int*);       //Delete item
void addItem(Item[], Item, int*, int*, int*);   //Add item

//Main function begins
int main(){

    //Opening file
    string filename;
    cin >> filename;
    ifstream file;
    file.open(filename.c_str());
    if(file.fail()){
        cout << "ERROR" << endl;
        return 1;
    }

    //Reading file
    Item messageBoard[100];
    string line;
    int length = 0;

    int fileCounter = 0;
    int searchCounter = 0;
    int shiftCounter = 0;

    while(getline(file, line, '\n')){
        Item temp;
        int categoryIndex = 0;
        stringstream ss;
        ss << line;

        while(getline(ss, line, ',')){
            if(categoryIndex == 0){
                temp.type = line;
            }
            if(categoryIndex == 1){
                temp.wanted = statusToBool(line);
            }
            if (categoryIndex == 2){
                temp.price = stoi(line);
            }
            categoryIndex++;
        }

        //Find first match in the existing message board
        //If match is found, display the match and delete item from board
        //If no match is found, add item to message board
        addItem(messageBoard, temp, &length, &searchCounter, &shiftCounter);

        fileCounter++;
    }

    cout << "#" << endl;

    //Items remaining after all lines are read
    for(int i = 0; i < length; ++i){
        cout << messageBoard[i].type << ", " << boolToStatus(messageBoard[i].wanted) << ", " << messageBoard[i].price << endl;
    }

    cout << "#" << endl;

    //Loop iterations
    cout << "file read:" << fileCounter << endl;
    cout << "search array:" << searchCounter << endl;
    cout << "shift array:" << shiftCounter << endl;

    cout << "Final length: " << length << endl;

    return 0;
}
//Main function ends

//Convert item status to boolean
bool statusToBool(string saleStatus){
    if (saleStatus == " wanted"){
        return true;
    }
    return false;
}

//Convert boolean status to string
string boolToStatus(bool wanted){
    if (wanted){
        return "wanted";
    }
    return "for sale";
}

//Find index of first match
int findMatch(Item messageBoard[], Item current, int length, int* searchCounter){
    int index = -1;

    for(int i = 0; i < length; ++i){
        (*searchCounter)++;
        //items are of different type
        if (messageBoard[i].type != current.type){
            continue;
        }
        //both items are up for sale or being wanted
        else if (messageBoard[i].wanted == current.wanted){
            continue;
        }
        //current item is up for sale
        else if (messageBoard[i].wanted && messageBoard[i].price >= current.price){
            index = i;
            cout << current.type << " " << current.price << endl;
            break;
        }
        //current item is being wanted
        else if (current.wanted && current.price >= messageBoard[i].price){
            index = i;
            cout << messageBoard[index].type << " " << messageBoard[index].price << endl;
            break;
        }
    }

    return index;
}

//Delete Item
void deleteItem(Item messageBoard[], int index, int* length, int* shiftCounter){
    //shifting elements and changing length of array
    int counter = 0;
    for(int i = index; i < (*length) - 1; ++i){
        messageBoard[i] = messageBoard[i + 1];
        (*shiftCounter)++;
        counter++;
    }
    (*length)--;
}

//Add Item
void addItem(Item messageBoard[], Item current, int* length, int* searchCounter, int* shiftCounter){
    int index = findMatch(messageBoard, current, *length, searchCounter);

    //add item and increase size if no match is found
    if (index == -1){
        messageBoard[*length] = current;
        (*length)++;
    }
    //delete item in message board if match is found
    else{
        deleteItem(messageBoard, index, length, shiftCounter);
    }

    return;
}
