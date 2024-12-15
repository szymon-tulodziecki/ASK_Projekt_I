#include <stdio.h>
#include <stdlib.h>


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

void menu();
void pokazBajty();
void pokazBin();
void odejmowanieU2();
void konwersja();
int wybierzTyp();
int wczytajInt();
float wczytajFloat();
double wczytajDouble();
void drukujBajty(void *ptr, size_t size);
void drukujBin(void* data, size_t size);
void oddzielenie();

//----------------------------------------------
int main(){
    while(1){
        menu();
    }
}

//----------------------------------------------
void menu(){
    int opcja;
    printf("\n\n\n");
    printf(GREEN"------------------------- MENU -------------------------\n"RESET);
    printf("1. Drukowanie liczb INT, FLOAT, DOUBLE w postaci bajtowej\n");
    printf("2. Drukowanie liczb INT, FLOAT, DOUBLE w postaci binarnej\n");
    printf("3. Prezentacja zasady odejmowania w U2\n");
    printf("4. Konwersja FLOAT -> DEC i DEC -> FLOAT\n");
    printf("5. Wyjście\n");

    printf("-> ");
    
    scanf("%d", &opcja);

    switch(opcja){
        case 1:
            pokazBajty();
            break;
        case 2:
            pokazBin();
            break;
        case 3:
            odejmowanieU2();
            break;
        case 4: 
            konwersja();
            break;
        case 5:
            exit(0);
        default:
            printf("Nie ma takiej opcji\n");
            break;
    }
}

//----------------------------------------------

void pokazBajty(){
    oddzielenie();
    printf("\n-----------------REPREZENTACJA BAJTOWA----------------\n");

    int opcja = wybierzTyp();

    if(opcja == 1){
        int liczba = wczytajInt();
        printf("Liczba w reprezentacji bajtowej to: \n");
        drukujBajty(&liczba, sizeof(liczba));
    }else if (opcja == 2){
        float liczba = wczytajFloat();
        printf("Liczba w reprezentacji bajtowej to: \n");
        drukujBajty(&liczba, sizeof(liczba));
    }else if (opcja == 3){
        double liczba = wczytajDouble();
        printf("Liczba w reprezentacji bajtowej to: \n");
        drukujBajty(&liczba, sizeof(liczba));
    }
    oddzielenie();
}
//----------------------------------------------
int wybierzTyp(){
    int opcja, k;
    printf("\n\n");
    do{
        printf("Wybierz typ:\n");
        printf("1. INT\n");
        printf("2. FLOAT\n");
        printf("3. DOUBLE\n");
        printf("-> ");
        k = scanf("%d", &opcja);

        if(opcja < 1 || opcja > 3 || k != 1){
            system("clear");
            printf("Błędny wybór spróbuj jeszcze raz! \n");
            while (getchar() != '\n');
        }
    }while(opcja < 1 || opcja > 3 || k != 1);
    return opcja;
}

//----------------------------------------------
int wczytajInt(){
    int liczba, k;
    printf("\n\n");
    do{
        printf("Podaj liczbe: ");
        k = scanf("%d", &liczba);
        if(k != 1){
            system("clear");
            printf("Podano zly typ\n");
            while (getchar() != '\n');
        }
    }while(k != 1);
    return liczba;
}

//----------------------------------------------
float wczytajFloat(){
    float liczba;
    int k;
    printf("\n\n");
    do{
        printf("Podaj liczbe: ");
        k = scanf("%f", &liczba);
        if(k != 1){
            printf("Podano zly typ\n");
            while (getchar() != '\n');
        }
    }while(k != 1);
    return liczba;
}
//----------------------------------------------
double wczytajDouble(){
    double liczba;
    int k;
    printf("\n\n");
    do{
        printf("Podaj liczbe: ");
        k = scanf("%lf", &liczba);
        if(k != 1){
            printf("Podano zly typ\n");
            while (getchar() != '\n');
        }
    }while(k != 1);
    return liczba;
}

//----------------------------------------------
void drukujBajty(void *ptr, size_t size) {
    unsigned char *bajty = (unsigned char *)ptr;
    for (size_t i = size; i > 0; i--) { 
        printf("%02X ", bajty[i - 1]);
    }
    printf("\n");
}
//----------------------------------------------
void pokazBin(){
    oddzielenie();
    printf("\n-----------------REPREZENTACJA BINARNA----------------\n");
    int opcja = wybierzTyp();

    if(opcja == 1){
        int liczba = wczytajInt();
        printf("Liczba w reprezentacji binarnej to: \n");
        drukujBin(&liczba, sizeof(liczba));
    }else if (opcja == 2){
        float liczba = wczytajFloat();
        printf("Liczba w reprezentacji binarnej to: \n");
        drukujBin(&liczba, sizeof(liczba));
    }else if (opcja == 3){
        double liczba = wczytajDouble();
        printf("Liczba w reprezentacji binarnej to: \n");
        drukujBin(&liczba, sizeof(liczba));
    }
    oddzielenie();
}
//----------------------------------------------
void drukujBin(void* data, size_t size) {
    unsigned char* bytes = (unsigned char*)data;
    for (size_t i = size; i > 0; --i) { 
        unsigned char byte = bytes[i - 1];
        
        for (int j = 7; j >= 0; --j) { 
            printf("%d", (byte >> j) & 1);
        }
        printf(" ");
    }
}
//----------------------------------------------
void odejmowanieU2() {
    oddzielenie();
    printf("\n--------------------ODEJMOWANIE U2--------------------\n");

    printf("\nWczytywanie pierwszej liczby: ");
    int a = wczytajInt();


    printf("\nWczytywanie drugiej liczby: ");
    int b = wczytajInt();

    
    int b_hlp = ~b + 1;
    int wynik = a + b_hlp;

    printf("\n\nWzór odejmowania U2: \n");
    printf("A - B = A + (~B + 1) \n");

    printf("\n\nDziesiętnie: \n");
    printf("%d - %d = %d + (%d) = %d \n", a, b, a, b_hlp, wynik);


    printf("\n\nBinarnie: \n");
    drukujBin(&a, sizeof(a));
    printf("(bin)\n");
    printf("                   + \n"); 
    drukujBin(&b_hlp, sizeof(b_hlp));
    printf("(bin)\n");
    printf("--------------------------------------------------------\n");
    printf("                   = \n");  
    drukujBin(&wynik, sizeof(wynik));
    printf("(bin)\n");


    oddzielenie();
}

void konwersja() {
    oddzielenie();
    printf("\n-----------------------KONWERSJA----------------------\n");
    printf("\n-------------FLOAT -> DEC lub DEC -> FLOAT------------\n");
    int opcja, k;
    
    printf("\n\n");
    do{
        printf("Wybierz typ konwersji:\n");
        printf("1. DEC -> FLOAT\n");
        printf("2. FLOAT -> DEC\n");
        printf("-> ");
        k = scanf("%d", &opcja);

        if(opcja < 1 || opcja > 3 || k != 1){
            system("clear");
            printf("Błędny wybór spróbuj jeszcze raz! \n");
            while (getchar() != '\n');
        }
    }while(opcja < 1 || opcja > 3 || k != 1);

    if(opcja == 1){
        int liczba = wczytajInt();
        float fliczba = (float) liczba;

        printf("\n\nDziesiętnie: \n");
        printf("%d(DEC)   ->  %f(FLOAT) \n", liczba, fliczba);

        printf("\nBinarnie: \n");
        drukujBin(&liczba, sizeof(liczba));
        printf("(DEC)\n");
        printf("-> \n");
        drukujBin(&fliczba, sizeof(fliczba));
        printf("(FLOAT)\n");
    }else{
        float liczba = wczytajFloat();
        int iliczba = (int) liczba;

        printf("\n\nDziesiętnie: \n");
        printf("%f(FLOAT)   ->  %d(DEC) \n", liczba, iliczba);

        printf("\nBinarnie: \n");
        drukujBin(&liczba, sizeof(liczba));
        printf("(FLOAT)\n");
        printf("-> \n");
        drukujBin(&iliczba, sizeof(iliczba));
        printf("(DEC)\n");
    }
        oddzielenie();
}
//----------------------------------------------
void oddzielenie(){

    printf(RED "\n======================================================\n" RESET);
}