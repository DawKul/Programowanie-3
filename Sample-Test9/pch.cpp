// 
// pch.cpp
//

#include "pch.h"
//Konstruktor
SortowaniePrzezScalanie::SortowaniePrzezScalanie(int* wejscieTablica, int wejscieRozmiar)
    : rozmiar(wejscieRozmiar) {
    if (rozmiar > 0) {
        tablica = new int[rozmiar];
        for (int i = 0; i < rozmiar; i++) {
            tablica[i] = wejscieTablica[i];
        }
    }
    else {
        tablica = nullptr;
    }
}

// Destruktor - zwalnia dynamicznie alokowaną pamięć
SortowaniePrzezScalanie::~SortowaniePrzezScalanie() {
    delete[] tablica;
}

// Metoda sortująca
void SortowaniePrzezScalanie::sortuj() {
    if (rozmiar > 0) {
        scalanieSort(0, rozmiar - 1);
    }
}

// Pobranie posortowanej tablicy
int* SortowaniePrzezScalanie::getTablica() const {
    return tablica;
}

// Rekurencyjna metoda do sortowania
void SortowaniePrzezScalanie::scalanieSort(int lewy, int prawy) {
    if (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        // Sortujemy lewą i prawą część
        scalanieSort(lewy, srodek);
        scalanieSort(srodek + 1, prawy);

        // Scalanie posortowanych części
        scal(lewy, srodek, prawy);
    }
}

// Metoda scalająca dwie części tablicy
void SortowaniePrzezScalanie::scal(int lewy, int srodek, int prawy) {
    int rozmiarLewy = srodek - lewy + 1;
    int rozmiarPrawy = prawy - srodek;

    // Dynamiczne tablice pomocnicze
    int* lewaTablica = new int[rozmiarLewy];
    int* prawaTablica = new int[rozmiarPrawy];

    // Kopiowanie danych do tablic pomocniczych
    for (int i = 0; i < rozmiarLewy; i++) {
        lewaTablica[i] = tablica[lewy + i];
    }
    for (int i = 0; i < rozmiarPrawy; i++) {
        prawaTablica[i] = tablica[srodek + 1 + i];
    }

    // Indeksy do iteracji po lewaTablica, prawaTablica i głównej tablicy
    int i = 0, j = 0, k = lewy;

    // Scalanie dwóch posortowanych podtablic
    while (i < rozmiarLewy && j < rozmiarPrawy) {
        if (lewaTablica[i] <= prawaTablica[j]) {
            tablica[k++] = lewaTablica[i++];
        }
        else {
            tablica[k++] = prawaTablica[j++];
        }
    }

    // Dodanie pozostałych elementów z lewej tablicy
    while (i < rozmiarLewy) {
        tablica[k++] = lewaTablica[i++];
    }

    // Dodanie pozostałych elementów z prawej tablicy
    while (j < rozmiarPrawy) {
        tablica[k++] = prawaTablica[j++];
    }

    // Zwolnienie pamięci pomocniczych tablic
    delete[] lewaTablica;
    delete[] prawaTablica;
}
