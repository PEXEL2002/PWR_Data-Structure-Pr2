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
    std::uniform_int_distribution<> priority_dist(0, 100); // Zakres priorytetów od 0 do RAND_MAX
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
    int sizes[8] = {1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000};
    std::string file;
    std::ofstream saveFile("research.csv");
    saveFile << "Set;Rozmiar;Struktura;Operacja;Czas\n";
    std::cout << "Set;Rozmiar;Struktura;Operacja;Czas\n";
    int val, prior;
    long long int sumHeap, sumArray;
    if (!saveFile.is_open()) {
        std::cerr << "Nie można otworzyć pliku research.csv do zapisu." << std::endl;
        return;
    }
    //Generacja plików do struktór
    for(int set = 0 ; set<10;set++){
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            generateToFile(size,file);
        }
    }
    //insert
    for(int set = 0 ; set<10;set++){
        val = generateRandomValue();
        prior = generateRandomPriority();
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            sumHeap = 0;
            sumArray = 0;
            for(int i = 0; i < 100;i++){
                HeapPriorityQueue<int>* queue = new HeapPriorityQueue<int>(file);
                auto start1 = std::chrono::high_resolution_clock::now();
                queue->insert(val,prior);
                auto end1 = std::chrono::high_resolution_clock::now();
                sumHeap += (std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1)).count();
                delete queue;

                ArrayPriorityQueue<int>* array = new ArrayPriorityQueue<int>(file);
                auto start2 = std::chrono::high_resolution_clock::now();
                array->insert(val,prior);
                auto end2 = std::chrono::high_resolution_clock::now();
                sumArray += (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2)).count();
                delete array;
            }
            saveFile << set << ";" << size << ";HeapPriorityQueue" << ";insert" << ";" <<  (sumHeap/100) << "\n";
            saveFile << set << ";" << size << ";ArrayPriorityQueue" << ";insert" <<";" << (sumArray/100) << "\n";
            std::cout << set << ";" << size << ";HeapPriorityQueue" << ";insert" <<";" << (sumHeap/100) << "\n";
            std::cout << set << ";" << size << ";ArrayPriorityQueue" << ";insert" <<";" << (sumArray/100) << "\n";
        }
    }
    //extractMax  
    for(int set = 0 ; set<10;set++){
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            sumHeap = 0;
            sumArray = 0;
            for(int i = 0; i < 100;i++){
                HeapPriorityQueue<int>* queue = new HeapPriorityQueue<int>(file);
                auto start1 = std::chrono::high_resolution_clock::now();
                queue->extractMax();
                auto end1 = std::chrono::high_resolution_clock::now();
                sumHeap += (std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1)).count();
                delete queue;

                ArrayPriorityQueue<int>* array = new ArrayPriorityQueue<int>(file);
                auto start2 = std::chrono::high_resolution_clock::now();
                array->extractMax();
                auto end2 = std::chrono::high_resolution_clock::now();
                sumArray += (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2)).count();
                delete array;
            }
            saveFile << set << ";" << size << ";HeapPriorityQueue" << ";extractMax" << ";" <<  (sumHeap/100) << "\n";
            saveFile << set << ";" << size << ";ArrayPriorityQueue" << ";extractMax" <<";" << (sumArray/100) << "\n";
            std::cout << set << ";" << size << ";HeapPriorityQueue" << ";extractMax" <<";" << (sumHeap/100) << "\n";
            std::cout << set << ";" << size << ";ArrayPriorityQueue" << ";extractMax" <<";" << (sumArray/100) << "\n";
        }
    }
    //findMax
    for(int set = 0 ; set<10;set++){
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            sumHeap = 0;
            for(int i = 0; i < 100;i++){
                HeapPriorityQueue<int>* queue = new HeapPriorityQueue<int>(file);
                    auto start1 = std::chrono::high_resolution_clock::now();
                    queue->findMax();
                    auto end1 = std::chrono::high_resolution_clock::now();
                    sumHeap += (std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1)).count();
                delete queue;
            }
            saveFile << set << ";" << size << ";HeapPriorityQueue" << ";findMax" << ";" <<  (sumHeap/100) << "\n";
            std::cout << set << ";" << size << ";HeapPriorityQueue" << ";findMax" <<";" << (sumHeap/100) << "\n";
        }
    }
    for(int set = 0 ; set<10;set++){
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            sumArray = 0;
            for(int i = 0; i < 100;i++){
                ArrayPriorityQueue<int>* array = new ArrayPriorityQueue<int>(file);
                auto start2 = std::chrono::high_resolution_clock::now();
                array->findMax();
                auto end2 = std::chrono::high_resolution_clock::now();
                sumArray += (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2)).count();
                delete array;
            }
           
            saveFile << set << ";" << size << ";ArrayPriorityQueue" << ";findMax" <<";" << (sumArray/100) << "\n";
            std::cout << set << ";" << size << ";ArrayPriorityQueue" << ";findMax" <<";" << (sumArray/100) << "\n";
        }
    }
    //increaseKey
    for(int set = 0 ; set<10;set++){
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            val = generateRandomValue();
            for(int i = 0; i < 100;i++){
                HeapPriorityQueue<int>* queue = new HeapPriorityQueue<int>(file);
                auto start1 = std::chrono::high_resolution_clock::now();
                queue->increaseKey(val);
                auto end1 = std::chrono::high_resolution_clock::now();
                sumHeap += (std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1)).count();
                delete queue;

                ArrayPriorityQueue<int>* array = new ArrayPriorityQueue<int>(file);
                auto start2 = std::chrono::high_resolution_clock::now();
                array->increaseKey(val);
                auto end2 = std::chrono::high_resolution_clock::now();
                sumArray += (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2)).count();
                delete array;
            }
            saveFile << set << ";" << size << ";HeapPriorityQueue" << ";increaseKey" << ";" <<  (sumHeap/100) << "\n";
            saveFile << set << ";" << size << ";ArrayPriorityQueue" << ";increaseKey" <<";" << (sumArray/100) << "\n";
            std::cout << set << ";" << size << ";HeapPriorityQueue" << ";increaseKey" <<";" << (sumHeap/100) << "\n";
            std::cout << set << ";" << size << ";ArrayPriorityQueue" << ";increaseKey" <<";" << (sumArray/100) << "\n";
        }
    }
    //reduceKey
    for(int set = 0 ; set<10;set++){
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            val = generateRandomValue();
            for(int i = 0; i < 100;i++){
                HeapPriorityQueue<int>* queue = new HeapPriorityQueue<int>(file);
                auto start1 = std::chrono::high_resolution_clock::now();
                queue->reduceKey(val);
                auto end1 = std::chrono::high_resolution_clock::now();
                sumHeap += (std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1)).count();
                delete queue;

                ArrayPriorityQueue<int>* array = new ArrayPriorityQueue<int>(file);
                auto start2 = std::chrono::high_resolution_clock::now();
                array->reduceKey(val);
                auto end2 = std::chrono::high_resolution_clock::now();
                sumArray += (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2)).count();
                delete array;
            }
            saveFile << set << ";" << size << ";HeapPriorityQueue" << ";reduceKey" << ";" <<  (sumHeap/100) << "\n";
            saveFile << set << ";" << size << ";ArrayPriorityQueue" << ";reduceKey" <<";" << (sumArray/100) << "\n";
            std::cout << set << ";" << size << ";HeapPriorityQueue" << ";reduceKey" <<";" << (sumHeap/100) << "\n";
            std::cout << set << ";" << size << ";ArrayPriorityQueue" << ";reduceKey" <<";" << (sumArray/100) << "\n";
        }
    }
    //modyfiKey
    for(int set = 0 ; set<10;set++){
        for(int size: sizes){
            file = "data_" + std::to_string(set+1) + "_" + std::to_string(size) + ".txt";
            val = generateRandomValue();
            prior = generateRandomPriority();
            for(int i = 0; i < 100;i++){
                HeapPriorityQueue<int>* queue = new HeapPriorityQueue<int>(file);
                auto start1 = std::chrono::high_resolution_clock::now();
                queue->modyfiKey(val,prior);
                auto end1 = std::chrono::high_resolution_clock::now();
                sumHeap += (std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1)).count();
                delete queue;

                ArrayPriorityQueue<int>* array = new ArrayPriorityQueue<int>(file);
                auto start2 = std::chrono::high_resolution_clock::now();
                array->modyfiKey(val,prior);
                auto end2 = std::chrono::high_resolution_clock::now();
                sumArray += (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2)).count();
                delete array;
            }
            saveFile << set << ";" << size << ";HeapPriorityQueue" << ";modyfiKey" << ";" <<  (sumHeap/100) << "\n";
            saveFile << set << ";" << size << ";ArrayPriorityQueue" << ";modyfiKey" <<";" << (sumArray/100) << "\n";
            std::cout << set << ";" << size << ";HeapPriorityQueue" << ";modyfiKey" <<";" << (sumHeap/100) << "\n";
            std::cout << set << ";" << size << ";ArrayPriorityQueue" << ";modyfiKey" <<";" << (sumArray/100) << "\n";
        }
    }
    saveFile.close();
}