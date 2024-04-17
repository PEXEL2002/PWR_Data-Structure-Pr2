#pragma once
#include "PriorityQueue.h"
#include "element.h"
#include <string>
#include <sstream>
#include <fstream>
template<typename T>
class HeapPriorityQueue: public PriorityQueue<T>{
private:
    int _size;
    int _capacity;
    element<T>* _heap;
/**
 * @brief powiekszenie tablicy
*/
    void extendArray() {
        element<T>* tempArray = new element<T>[_size * 2];
        for (int i = 0; i < _capacity; i++) {
            tempArray[i] = _heap[i];
        }
        delete[] _heap;
        _heap = tempArray;
        _size = _size*2;
    }
/**
 * @brief Zmniejszenia tablicy
*/
    void reduceArray() {
        int newSize = _size / 2;
        element<T>* tempArray = new element<T>[newSize];
        for (int i = 0; i < _capacity; i++) {
            tempArray[i] = _heap[i];
        }
        delete[] _heap;
        _heap = tempArray;
        _size = newSize;
    }
/**
 * @brief Przywraca właściwości kopca, przesuwając element w górę drzewa
*/
    void heapifyUp(int index) {
        while (index != 0 && _heap[(index - 1) / 2].priority < _heap[index].priority) {
            std::swap(_heap[(index - 1) / 2], _heap[index]);
            index = (index - 1) / 2;
        }
    }
/**
 * @brief Przywraca właściwości kopca, przesuwając element w dół drzewa
*/
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < _capacity && _heap[left].priority > _heap[largest].priority)
            largest = left;
        if (right < _capacity && _heap[right].priority > _heap[largest].priority)
            largest = right;

        if (largest != index) {
            std::swap(_heap[index], _heap[largest]);
            heapifyDown(largest);
        }
    }

    public:
/**
 * @brief Sprawdzenie czy kolejka nie jest pusta
 * @return 0 - kolejka jest pusta
 * 1 - kolejka jest pełna
*/
    bool isEmpty(){
        return _capacity;
    }
/**
 * @brief Konstruktor domyślny
*/
    HeapPriorityQueue() {
        _size = 10;
        _capacity = 0;
        _heap = new element<T>[_size];
    }
/**
 * @brief Konstruktor z parametrem
 * @param file nazwa pliku
*/
    HeapPriorityQueue(std::string data){
        _size = 10;
        _capacity = 0;
        _heap = new element<T>[_size]; 
        std::ifstream file(data);
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            T value;
            int priority;
            if (iss >> value >> priority) {
                insert(value,priority);
            }
        }
    }
/**
 * @brief Dekonstruktor
*/
    ~HeapPriorityQueue() {
        delete[] _heap;
    }
/**
 * @brief insert(e,p) – dodanie elementu e o priorytecie p,
*/
    void insert(T e, int p) override{
        if (_capacity == _size) {
            extendArray();
        }
        _heap[_capacity] = element<T>(e, p);
        heapifyUp(_capacity);
        _capacity++;
    }
/**
 * @brief extract-max() – usunięcie i zwrócenie elementu o największym priorytecie,
*/
    T extractMax() override{
        T maxValue = _heap[0].value;
        _heap[0] = _heap[_capacity - 1];
        _capacity--;
        heapifyDown(0);
        if ((_capacity*2)+2 == _size) {
            reduceArray();
        }
        return maxValue;
    }
/**
 * @brief find-max()/peek() – zwrócenie (podejrzenie) elementu o największym priorytecie
*/
    T findMax() override{
        return _heap[0].value;
    }
/**
 * @brief modify-key(e,p) – zmiana priorytetu elementu e na p. 
 * @param e - wartość elementu p - nowy priorytet
 * @return 0 - nie ma takiego elementu w stukturze 1 - zmieniono priorytet
*/
    int modyfiKey(T e, int p) override{
        for(int i = 0;i<_capacity;i++){
            if(_heap[_capacity].value == e){
                _heap[_capacity].priority = p;
                return 1;
            }
        }
        return 0;
    }
/**
 * @brief getSize() - zwrócenie rozmiaru tablicy
*/
    int getSize() override{
        return _capacity;
    }
/**
 * @brief Wyświetlenie struktury
*/
    void print() override{
        for(int i=0;i<_capacity;i++){
            std::cout << _heap[i].value << " " << _heap[i].priority << std::endl;
        }
        std::cout << std::endl;
    }
};