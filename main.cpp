#include <iostream>
#include <string>
#include "ArrayPriorityQuoue.h"
#include "HeapPriorityQuoue.h"
#include "PriorityQueue.h"
#include "ui.h"
using namespace std;
int main(){
    int tests = 0;
    do{
        cout << "Czy przeprowadzić badania 1 - tak 0 - nie: ";
        cin >> tests;
    }while (tests != 0 && tests != 1);
    if(tests){
        cout << "Start Badań";
    }else{
        int start = 1, operation = 1, size = 0;
        while(start){
            do{
                cout << "Ile danych w struktórach chcesz przechowywać: ";
                cin >> size;
            }while(size < 0);
            generateToFile(size,4);
            HeapPriorityQueue<int> heapQueue("data.txt");
            ArrayPriorityQueue<int> arrayQueue("data.txt");
            while(operation){
                cout << "1. Dodaj element do kolejki\n";
                cout << "2. Uzuń element o najwyższym priorytecie\n";
                cout << "3. Podejrzyj element o najwyższym priorytecie\n";
                cout << "4. Zmodyfikuj priorytet elementu\n";
                cout << "5. Zwróć rozmiar struktury\n";
                cout << "6. Wyświetl zawartośc struktór\n";
                cout << "0. Wygeneruj dane na nowo\n";
                cout << "Podaj operacje do wykoaniania: ";
                cin >> operation;
                switch (operation)
                {
                case 1:
                    insertUi(arrayQueue,heapQueue);
                    break;
                case 2:
                    extractMaxUi(arrayQueue,heapQueue);
                    break;
                case 3:
                    findMaxUi(arrayQueue,heapQueue);
                    break;
                case 4:
                    modyfiKeyUi(arrayQueue,heapQueue);
                    break;
                case 5:
                    getSizeUi(arrayQueue,heapQueue);
                    break;
                case 6:
                    printUi(arrayQueue,heapQueue);
                    break;
                case 0:
                    break;
                default:
                    cout << "Nie ma takiej operacji.";
                    break;
                }
            }
            do{
                cout << "Chcesz kontunuować program? 1 - tak 0 - nie: ";
                cin >> start;
            }while(start != 0 && start != 1);
        }
    }
}