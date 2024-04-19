#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <random>
#include "ArrayPriorityQuoue.h"
#include "HeapPriorityQuoue.h"
#include "ui.h"

void generateToFile(int size, int multiply) {
    std::ofstream outFile("data.txt");
    if (!outFile.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu.\n";
        return;
    }

    // Ustawiamy generator i dystrybucję dla dużo większego zakresu.
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> value_dist(1, 1000000); // Zakres wartości od 1 do 1,000,000
    std::uniform_int_distribution<> priority_dist(1, size*multiply); // Zakres priorytetów od 1 do size*multyply

    for (int i = 0; i < size; ++i) {
        int value = value_dist(gen); // Losowa wartość z dużego zakresu
        int priority = priority_dist(gen);
        outFile << value << " " << priority << "\n";
    }

    outFile.close();
    std::cout << "Dane zostały wygenerowane i zapisane do pliku 'data.txt'.\n";
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

void tests();
