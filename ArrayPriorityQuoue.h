#pragma once
#include "PriorityQueue.h"
#include "element.h"
#include <string>
#include <sstream>
#include <fstream>
template<typename T>
class ArrayPriorityQueue: public PriorityQueue<T>{
    private:
        int _size;
        int _capacity;
        element<T>* _array;
/**
 * @brief extendedArray - Powiększenie 2 krotne tablicy
*/
    void extendArray(){
        element<T>* tempArray = new element<T>[_size*2];
        for(int i=0;i<_size;i++){
            tempArray[i] = _array[i];
        }
        delete[] _array;
        _array = tempArray;
        _size = _size*2;
    }
/**
 * @brief reduceArray - zmniejszenie tablicy
*/
    void reduceArray(){
        _size = _size / 2;
        element<T>* tempArray = new element<T>[_size];
        for (int i = 0; i < _capacity; i++) {
            tempArray[i] = _array[i];
        }
        delete[] _array;
        _array = tempArray;
    }
    public:
/**
 * @brief Sprawdzenie czy kolejka nie jest pusta
 * @return 1 - kolejka jest pusta
 * 0 - kolejka jest pełna
*/
    bool isEmpty(){
        return !_capacity;
    }
/** 
 * @brief Konstruktor domyślny
*/
    ArrayPriorityQueue(){
        _size = 2;
        _capacity = 0;
        _array = new element<T>[_size];
    }
/**
 * @brief Konstruktor z parametrem
 * @param file nazwa pliku
*/
    ArrayPriorityQueue(std::string data){
        _size = 2;
        _capacity = 0;
        _array = new element<T>[_size]; 
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
    ~ArrayPriorityQueue(){
        delete[] _array;
    }
/**
 * @brief insert(e,p) – dodanie elementu e o priorytecie p,
*/
    void insert(T e, int p) override{
        if(_capacity+1 >= _size){
            extendArray();
        }
        element<T> newItem(e,p);
        _array[_capacity] = newItem;
        _capacity++;
    }
/**
 * @brief extract-max() – usunięcie i zwrócenie elementu o największym priorytecie,
*/
    T extractMax() override{
        int index = 0;
        for(int i=0;i<_capacity;i++){
            if(_array[index].priority < _array[i].priority){
                index = i;
            }
        }
        T temp = _array[index].value;
        for(int i = index;i<_capacity-1;i++){
            _array[i] = _array[i+1];
        }
        _capacity--;
        if ((_capacity*2)+2 == _size) {
            reduceArray();
        }
        return temp;
    }
/**
 * @brief find-max()/peek() – zwrócenie (podejrzenie) elementu o największym priorytecie
*/
    T findMax() override{
        int index =0;
        for(int i=0;i<_capacity;i++){
            if(_array[index].priority < _array[i].priority){
                index = i;
            }
        }
        T temp = _array[index].value;
        return temp;
    }
/**
 * @brief modify-key(e,p) – zmiana priorytetu elementu e na p. 
 * @param e - wartość elementu p - nowy priorytet
 * @return 0 - nie ma takiego elementu w stukturze 1 - zmieniono priorytet
*/
    int modyfiKey(T e, int p) override{
        for(int i = 0;i<_capacity;i++){
            if(_array[i].value == e){
                _array[i].priority = p;
                return 1;
            }
        }
        return 0;
    }
/**
 * @brief zwiększenie priorytetu o 1 
 * @param e - wartość elementu dla którego zwiększamy priorytet
 * @return 0 - nie ma takiego elementu w stukturze 1 - zmieniono priorytet
*/
    int increaseKey(T e) override{
        for(int i = 0;i<_capacity;i++){
            if(_array[i].value == e){
                _array[i].priority ++;
                return 1;
            }
        }
        return 0;
    }
/**
 * @brief zmniejsza priorytetu o 1 
 * @param e - wartość elementu dla którego zwiększamy priorytet
 * @return 0 - nie ma takiego elementu w stukturze 1 - zmieniono priorytet
*/
    int reduceKey(T e) override{
        for(int i = 0;i<_capacity;i++){
            if(_array[i].value == e){
                _array[i].priority --;
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
            std::cout << _array[i].value << " " << _array[i].priority << std::endl;
        }
        std::cout << std::endl;
    }
};