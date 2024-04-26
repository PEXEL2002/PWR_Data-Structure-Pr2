#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <random>
#include "ArrayPriorityQuoue.h"
#include "HeapPriorityQuoue.h"
#include "ui.h"

void generateToFile(int size, std::string fileName) {
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu.\n";
        return;
    }
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> value_dist(0, 1000); // Zakres wartości od 0 do 1000
    std::uniform_int_distribution<> priority_dist(0, RAND_MAX); // Zakres priorytetów od 0 do RAND_MAX
    int value, priority;
    for (int i = 0; i < size; ++i) {
        value = value_dist(gen);
        priority = priority_dist(gen);
        outFile << value << " " << priority << "\n";
    }
    outFile.close();
}
int generateRandomValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1000);
    return dist(gen);
}
int generateRandomPriority() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, RAND_MAX);
    return dist(gen);
}
void insertUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
    int e=0, p=0;
    std::cout << "Podaj wartość elementu: ";
    std::cin >> e;
    std::cout << "Podaj wartość prioryteru: ";
    std::cin >> p;

    auto start1 = std::chrono::high_resolution_clock::now();
    aPQ.insert(e, p);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    hPQ.insert(e, p);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout << "Dodawanie elementu do kolejki: " << std::endl;
    std::cout << "ArrayPriorityQueue | " << duration1.count() << std::endl;
    std::cout << "HeapPriorityQueue  | " << duration2.count() << std::endl;
}

void extractMaxUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
    int extract;
    if(aPQ.isEmpty()){
        std::cout << "Kolejki są pusta." << std::endl;
        return;
    }else{
        auto start1 = std::chrono::high_resolution_clock::now();
        extract = aPQ.extractMax();
        auto end1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

        auto start2 = std::chrono::high_resolution_clock::now();
        hPQ.extractMax();
        auto end2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
        std::cout << "Usunięcie elementu o nawyższm priorytecie: "<< std::endl;
        std::cout << "ArrayPriorityQueue | " << duration1.count() << std::endl;
        std::cout << "HeapPriorityQueue  | " << duration2.count() << std::endl;
        std::cout << "Wartość usuniętego elementu: " << extract << std::endl;
    }
}

void findMaxUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
    int extract;

    auto start1 = std::chrono::high_resolution_clock::now();
    extract = aPQ.extractMax();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    hPQ.extractMax();
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout << "Podejrzenie  elementu o nawyższm priorytecie: "<< std::endl;
    std::cout << "ArrayPriorityQueue | " << duration1.count() << std::endl;
    std::cout << "HeapPriorityQueue  | " << duration2.count() << std::endl;
    std::cout << "Wartość elementu o największym priorytecie: " << extract << std::endl;
}

void modyfiKeyUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
    int elem, priority;
    std::cout << "Podaja wartoś elementu którego szukasz: ";
    std::cin >> elem;
    std::cout << ">>Podaj wartość priorytetu na jaki chcesz zmienić: ";
    std::cin >> priority;
    int result;

    auto start1 = std::chrono::high_resolution_clock::now();
    result = aPQ.modyfiKey(elem,priority);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    hPQ.modyfiKey(elem,priority);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout << "Zmodyfikowanie priorytetu elementu: "<< std::endl;
    std::cout << "ArrayPriorityQueue | " << duration1.count() << std::endl;
    std::cout << "HeapPriorityQueue  | " << duration2.count() << std::endl;
    if(result){
        std::cout << "Zmieniono priorytet elementu " << elem << " na " << priority;
    }else{
        std::cout << "Nie znaleziono żadnego elementu o wartości " << elem;
    }
    std::cout << std::endl;
}
void increaseKeyUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
    int elem;
    std::cout << "Podaja wartoś elementu którego szukasz: ";
    std::cin >> elem;
    int result;

    auto start1 = std::chrono::high_resolution_clock::now();
    result = aPQ.increaseKey(elem);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    hPQ.increaseKey(elem);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout << "Zwiększenie priorytetu o 1 elementu: "<< std::endl;
    std::cout << "ArrayPriorityQueue | " << duration1.count() << std::endl;
    std::cout << "HeapPriorityQueue  | " << duration2.count() << std::endl;
    if(result){
        std::cout << "Zwiększono priorytet o 1 elementu o wartości: " << elem;
    }else{
        std::cout << "Nie znaleziono żadnego elementu o wartości " << elem;
    }
    std::cout << std::endl;
}
void reduceKeyUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
     int elem;
    std::cout << "Podaja wartoś elementu którego szukasz: ";
    std::cin >> elem;
    int result;

    auto start1 = std::chrono::high_resolution_clock::now();
    result = aPQ.reduceKey(elem);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    hPQ.reduceKey(elem);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout << "Zmniejszenie priorytetu o 1 elementu: "<< std::endl;
    std::cout << "ArrayPriorityQueue | " << duration1.count() << std::endl;
    std::cout << "HeapPriorityQueue  | " << duration2.count() << std::endl;
    if(result){
        std::cout << "Zmniejszenie priorytetu o 1 elementu o wartości: " << elem;
    }else{
        std::cout << "Nie znaleziono żadnego elementu o wartości " << elem;
    }
    std::cout << std::endl;
}
void getSizeUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
    std::cout << "Rozmiary struktór: " << std::endl;
    std::cout << "ArrayPriorityQueue | " << aPQ.getSize() << std::endl;
    std::cout << "HeapPriorityQueue  | " << hPQ.getSize() << std::endl;
}

void printUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ){
    int choose; 
    do{
        std::cout << "Którą strukture chcesz wyświetlić" << std::endl;
        std::cout << " 0 - ArrayPriorityQueue" << std::endl;
        std::cout << " 1 - HeapPriorityQueue" <<std::endl;
        std::cin >> choose;
    }while(choose !=0 && choose!=1);
    if(choose){
        hPQ.print();
    }else{
        aPQ.print();
    }
}

void tests(){
    int sizes[7] = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    int numberOfStructures = 100, value, priority;
    std::string file;
    for(int size = 0; size < 7; size++){ // Rozmiar danych
        for(int i = 1; i < 6;i++){ // Ilość różnych zestawów danych
            file += "data_" + std::to_string(i)+"_"+ std::to_string(sizes[size])+".txt";
            generateToFile(10,file);
            std::vector<HeapPriorityQueue<int>> VHPQ;
            for(int j = 0;j < numberOfStructures;j++){


            }
            file = "";
            return;
        }
    }
}