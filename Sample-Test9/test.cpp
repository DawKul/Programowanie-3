#include "pch.h"

#include "gtest/gtest.h"


TEST(SortowaniePrzezScalanieTest, TablicaJuzPosortowana) {
    int tablica[] = { 1, 2, 3, 4, 5 };
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int* wynik = sortowanie.getTablica();
    for (int i = 0; i < rozmiar; i++) {
        EXPECT_EQ(wynik[i], i + 1);
    }
}

TEST(SortowaniePrzezScalanieTest, TablicaPosortowanaOdwrotnie) {
    int tablica[] = { 5, 4, 3, 2, 1 };
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int* wynik = sortowanie.getTablica();
    for (int i = 0; i < rozmiar; i++) {
        EXPECT_EQ(wynik[i], i + 1);
    }
}

TEST(SortowaniePrzezScalanieTest, TablicaLosowa) {
    int tablica[] = { 38, 27, 43, 3, 9, 103, 10 };
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int oczekiwany[] = { 3, 9, 10, 27, 38, 43, 103 };
    int* wynik = sortowanie.getTablica();
    for (int i = 0; i < rozmiar; i++) {
        EXPECT_EQ(wynik[i], oczekiwany[i]);
    }
}

TEST(SortowaniePrzezScalanieTest, TablicaZLiczbamiUjemnymi) {
    int tablica[] = { -5, -1, -3, -2, -4 };
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int oczekiwany[] = { -5, -4, -3, -2, -1 };
    int* wynik = sortowanie.getTablica();
    for (int i = 0; i < rozmiar; i++) {
        EXPECT_EQ(wynik[i], oczekiwany[i]);
    }
}

TEST(SortowaniePrzezScalanieTest, TablicaMieszana) {
    int tablica[] = { 3, -2, 5, -1, 0 };
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int oczekiwany[] = { -2, -1, 0, 3, 5 };
    int* wynik = sortowanie.getTablica();
    for (int i = 0; i < rozmiar; i++) {
        EXPECT_EQ(wynik[i], oczekiwany[i]);
    }
}

TEST(SortowaniePrzezScalanieTest, TablicaPusta) {
    int* tablica = nullptr;
    int rozmiar = 0;

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int* wynik = sortowanie.getTablica();
    EXPECT_EQ(wynik, nullptr);
}

TEST(SortowaniePrzezScalanieTest, TablicaJednoelementowa) {
    int tablica[] = { 42 };
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int* wynik = sortowanie.getTablica();
    EXPECT_EQ(wynik[0], 42);
}

TEST(SortowaniePrzezScalanieTest, TablicaZDuplikatami) {
    int tablica[] = { 5, 1, 3, 3, 2, 1 };
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int oczekiwany[] = { 1, 1, 2, 3, 3, 5 };
    int* wynik = sortowanie.getTablica();
    for (int i = 0; i < rozmiar; i++) {
        EXPECT_EQ(wynik[i], oczekiwany[i]);
    }
}

TEST(SortowaniePrzezScalanieTest, DuzaTablica) {
    const int rozmiar = 200;
    int tablica[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = rozmiar - i;
    }

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int* wynik = sortowanie.getTablica();
    for (int i = 0; i < rozmiar; i++) {
        EXPECT_EQ(wynik[i], i + 1);
    }
}

TEST(SortowaniePrzezScalanieTest, MieszanaDuzaTablicaZDuplikatami) {
    const int rozmiar = 150;
    int tablica[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = (i % 20) - 10; // Liczby od -10 do 9 z powtórzeniami
    }

    SortowaniePrzezScalanie sortowanie(tablica, rozmiar);
    sortowanie.sortuj();

    int* wynik = sortowanie.getTablica();
    for (int i = 1; i < rozmiar; i++) {
        EXPECT_LE(wynik[i - 1], wynik[i]);
    }
}
