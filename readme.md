# ASK_Projekt_I

Ten projekt jest programem napisanym w języku C, który spełnia następujące wymagania:
- Drukuje postać bajtową danych typu INT, FLOAT, DOUBLE
- Drukuje postać binarną dla liczb INT, FLOAT, DOUBLE
- Prezentuje zasadę wykonywania odejmowania w U2 (kod uzupełnień do dwóch)
- Prezentuje konwersję FLOAT -> DEC i DEC -> FLOAT

## Funkcje programu

Program oferuje menu z następującymi opcjami:

1. Drukowanie liczb INT, FLOAT, DOUBLE w postaci bajtowej
2. Drukowanie liczb INT, FLOAT, DOUBLE w postaci binarnej
3. Prezentacja zasady odejmowania w U2
4. Konwersja FLOAT -> DEC i DEC -> FLOAT
5. Wyjście z programu

## Jak używać

1. Skompiluj program używając kompilatora C, np. gcc:
    ```sh
    gcc -o ask_projekt_I ask_projekt_I.c
    ```

2. Uruchom program:
    ```sh
    ./ask_projekt_I
    ```

3. Postępuj zgodnie z instrukcjami wyświetlanymi w menu.

## Przykładowe funkcje

### Funkcja `pokazBajty`

Drukuje reprezentację bajtową liczby INT, FLOAT lub DOUBLE.

### Funkcja `pokazBin`

Drukuje reprezentację binarną liczby INT, FLOAT lub DOUBLE.

### Funkcja `odejmowanieU2`

Prezentuje zasadę odejmowania w kodzie uzupełnień do dwóch (U2).

### Funkcja `konwersja`

Prezentuje konwersję liczby z systemu dziesiętnego na zmiennoprzecinkowy (DEC -> FLOAT) i odwrotnie (FLOAT -> DEC).

## Struktura kodu

Kod jest modularny i podzielony na funkcje, co ułatwia jego zrozumienie i modyfikację. Każda funkcja odpowiada za konkretną część funkcjonalności programu.

## Autor

[Szymon Tułodziecki](https://github.com/szymon-tulodziecki)