//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

#include <iostream>

class SortowaniePrzezScalanie {
private:
    int* tablica;   // Dynamiczna tablica przechowująca dane
    int rozmiar;    // Rozmiar tablicy

public:
    // Konstruktor
    SortowaniePrzezScalanie(int* wejscieTablica, int wejscieRozmiar);

    // Destruktor
    ~SortowaniePrzezScalanie();

    // Metoda publiczna do sortowania
    void sortuj();

    // Pobranie posortowanej tablicy
    int* getTablica() const;

private:
    // Rekurencyjna metoda sortowania
    void scalanieSort(int lewy, int prawy);

    // Metoda scalająca dwie części tablicy
    void scal(int lewy, int srodek, int prawy);
};

