#pragma once
#include "ArrayPriorityQuoue.h"
#include "HeapPriorityQuoue.h"

/**
 * @brief Generuje plik z danymi.
 * @param size Rozmiar danych do wygenerowania.
*/
void generateToFile(int size, std::string fileName = "data.txt") ;
/**
 * @brief Generuje liczbę z zakresu od 0 do 1000
 * @return wygenerowana liczba
*/
int generateRandomNumber();
/**
 * @brief Generuje priorytet z zakresu od 0 do RAND_MAX
 * @return wygenerowany priorytet
*/
int generateRandomPriority();
/**
 * @brief Wstawia element do kolejek priorytetowych.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void insertUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Usinięcie maksymalnego elementu z kolejek priorytetowych.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void extractMaxUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Znajduje maksymalny element w kolejce priorytetowej.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void findMaxUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Modyfikuje klucz elementu w kolejce priorytetowej.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void modyfiKeyUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Zwiększa klucz elementu w kolejce priorytetowej.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void increaseKeyUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Zmniejsza klucz elementu w kolejce priorytetowej.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void reduceKeyUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Zwraca rozmiar kolejek priorytetowych.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void getSizeUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Wypisuje elementy kolejek priorytetowych.
 * @param aPQ Obiekt ArrayPriorityQueue.
 * @param hPQ Obiekt HeapPriorityQueue.
*/
void printUi(ArrayPriorityQueue<int> &aPQ, HeapPriorityQueue<int> &hPQ);
/**
 * @brief Prowadzi badania
 * @return plik .csv
*/
void tests();