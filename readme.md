# ANS w Elblągu  
## Instytut Informatyki Stosowanej  
## im. Krzysztofa Brzeskiego  

### Architektura Systemów Komputerowych  
### Studium stacjonarne, sem. 3, 2024/  

### Zadanie Semestralne - Projekt I  

#### Nazwisko i imię: **Tułodziecki Szymon**  
#### Nr albumu: **21312**  

---

## 1. Opis działania głównych funkcji oraz metod  

### a) Program opiera się na zapętlającym się menu, w którym można wybrać 5 opcji:  

Każda opcja wywołuje odpowiednią metodę lub funkcję prezentującą daną operację:  
1. Drukowanie liczb `INT`, `FLOAT`, `DOUBLE` w postaci bajtowej,  
2. Drukowanie liczb `INT`, `FLOAT`, `DOUBLE` w postaci binarnej,  
3. Prezentacja zasady odejmowania w U2,  
4. Konwersja `FLOAT` → `DEC` → `FLOAT`,  
5. Wyjście z programu.  

---

### b) Opcja 1: Drukowanie liczb `INT`, `FLOAT`, `DOUBLE` w postaci bajtowej  

Po wybraniu pierwszej opcji uruchamiana jest metoda: **`void pokazBajty()`**, która wyświetla bajtową reprezentację wybranej liczby typu `INT`, `FLOAT`, `DOUBLE`.  

**Działanie funkcji:**  
1. Użytkownik wybiera typ danych (`INT`, `FLOAT`, `DOUBLE`).  
2. Następnie wprowadza wartość liczby.  
3. Program wyświetla jej reprezentację w postaci bajtowej.  

**Przykłady:**  
- Liczba `128` (typ `uint`) → bajtowo: `00000080`  
- Liczba `-128` (typ `uint`) → bajtowo: `FFFFFF80`  
- Liczba `256.1024` (typ `float`) → bajtowo: `43800D1B`  
- Liczba `-1024.256` (typ `float`) → bajtowo: `C4800831`  
- Liczba `1410.966` (typ `double`) → bajtowo: `40960BDD2F1A9FBE`  
- Liczba `-1866.2005` (typ `double`) → bajtowo: `C09D28CD35A85879`  

#### Zestawienie wyników:  

| Liczba        | Typ       | Rozmiar (w bajtach) | Bajtowa Reprezentacja     |  
|---------------|-----------|---------------------|---------------------------|  
| 128           | `int`     | 4                   | `00000080`                |  
| -128          | `int`     | 4                   | `FFFFFF80`                |  
| 256.1024      | `float`   | 4                   | `43800D1B`                |  
| -1024.256     | `float`   | 4                   | `C4800831`                |  
| 1410.966      | `double`  | 8                   | `40960BDD2F1A9FBE`        |  
| -1866.2005    | `double`  | 8                   | `C09D28CD35A85879`        |  

**Uwagi techniczne:**  
Metoda **`void pokazBajty()`** wykorzystuje funkcję pomocniczą **`void drukujBajty(void *ptr, size_t size)`**, która "wyciąga" dane z pamięci wskazywanej przez wskaźnik `ptr` i wypisuje je w formie bajtów, w kolejności od najstarszego do najmłodszego.  

---

### c) Opcja 2: Drukowanie liczb `INT`, `FLOAT`, `DOUBLE` w postaci binarnej  

Opcja działa analogicznie do pierwszej, z tą różnicą, że "wyciągane" wartości z pamięci są prezentowane w postaci binarnej.  
Metoda **`void pokazBin()`** wywołuje funkcję pomocniczą **`void drukujBin(void *data, size_t size)`**, która drukuje binarne reprezentacje liczby.  

**Przykłady:**  
- Liczba `255` (typ `uint`) → binarnie: `00000000 00000000 00000000 11111111`  
- Liczba `-512` (typ `uint`) → binarnie: `11111111 11111111 11111110 00000000`  
- Liczba `2003.09` (typ `float`) → binarnie: `01000100 11111010 01100010 11100001`  
- Liczba `-5465.124` (typ `float`) → binarnie: `11000101 10101010 11001000 11111110`  

---

### d) Opcja 3: Prezentacja zasady odejmowania w U2  

Metoda **`void odejmowanieU2()`** pozwala na zobaczenie zasady odejmowania liczb w systemie U2 (dzięki operacji dodawania).  

- Wzór: **`A - B = A + (~B + 1)`**  
- Metoda wyświetla wynik operacji w systemie dziesiętnym i binarnym.  

**Przykład dla liczb:**  
- `128 - 64` → Dziesiętnie: `64`, Binarne: `00000000 00000000 00000000 01000000`  
- `255 - 1` → Dziesiętnie: `254`, Binarne: `11111111 11111111 11111111 11111110`  

---

### e) Opcja 4: Konwersja `FLOAT` → `DEC` i `DEC` → `FLOAT`  

Metoda **`void konwersja()`** ilustruje, jak na poziomie bitów zmieniane są typy:  
- Z rzeczywistego (`FLOAT`) na całkowity (`DEC`),  
- Z całkowitego (`DEC`) na rzeczywisty (`FLOAT`).  

---

### f) Opcja 5: Wyjście  

Opcja pozwala zakończyć program.  

---

## 2. Opis działania pomocniczych funkcji i metod  

- **`int wczytajInt()`**, **`float wczytajFloat()`**, **`double wczytajDouble()`**  
  Funkcje pozwalają na wczytanie wartości określonego typu z zabezpieczeniem przed błędami formatu.  

- **`void oddzielenie()`**  
  Funkcja drukuje czerwoną linię oddzielającą, poprawiającą czytelność wyników.  

---

