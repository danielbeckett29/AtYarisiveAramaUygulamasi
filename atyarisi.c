#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void menu();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max); //Fonksiyonlar tanımlandı
void horseRacingGame();
void countOccurence();
void triangleOfSequences();


int main()
{
    menu();
}

void menu()
{
    int secim;
    do{
        printf("1. Horse Racing Game\n");
        printf("2. Occurence Counter\n");
        printf("3. Triangle of Sequences\n");
        printf("0. Exit\n");
        scanf("%d", &secim);
        switch(secim){
            case 1:
                horseRacingGame();
                break;
            case 2:
                countOccurence();
                break;
            case 3:
                triangleOfSequences();
                break;
            case 0:
                break;
            default:
                printf("Menudeki rakamlardan birini giriniz");
                break;
        }
        printf("\n--------------------------\n");
    }while(secim != 0);
}


int getInt(int mini, int maxi)
{
    int input;
    do{
        scanf("%d", &input);                //istenen aralikta bir sayi girilmezse yeniden sayi girilmesini isteyen fonksiyon
    }while(input < mini || input > maxi);
    return input;
}


int numberGeneratorBetweenRange(int min, int max)
{
    int number, i;
    srand(time(NULL));                              //Belirlenen aralikta zamana bagli rastgele sayi ureten fonksiyon
    number = min + rand()%((max + 1) - min);
    return number;
}

void horseRacingGame()
{
    int p, secilen, enkucuk = 21, numberOfHorse, horse_number;
    numberOfHorse = numberGeneratorBetweenRange(3,5);
    printf("Number of Horse: %d\n", numberOfHorse);
    printf("Horse Number: ");
    secilen = getInt(1, numberOfHorse);
    printf("Racing starts...\n");                                       
    for(int i = 1; i <= numberOfHorse; i++){
        printf("Horse %d: ", i);
        int time = numberGeneratorBetweenRange(10,20);
        for(int j = 1; j <= time; j++){
            printf("-");
        }
        if(time < enkucuk){
            enkucuk = time;
            p = i;                                      // p degiskeni, zamani en az olan atin sirasini tutan degisken
        }
        if(secilen == i && time == enkucuk){
            p  = i;
        }

        printf("\n");
        for(int k = 1; k < 500000000; k++){            /*rastgele sayi zamana bagli olarak uretiliyor.Program 1 saniyenin altında */
        }                                              /*bir hizda calistigi icin tum atlar ayni yolu kosmus oluyordu. Soldaki donguyu*/
    }                                                  /*tamamlamak 1 sn kadar surdugu ve zamani degistirdigi ıcın ekledim. */
    
    if(secilen == p){
        printf("You win! Winner is Horse %d\n", secilen);
    }
    else if(secilen != p){
        printf("You lose! Winner is Horse %d\n", p);
    }
}


void countOccurence()
{
    int son, occurence = 0, control, a, us, mod, bigNumber, searchNumber;
    printf("Big Number: ");
    scanf("%d", &bigNumber);
    printf("Search Number: ");
    scanf("%d", &searchNumber);
    a = searchNumber;
    for(us = 0; a > 0; us++){                        /*searchNumber degiskeni baska yerde de lazim oldugundan kullandigim halde degismemesi icin*/
        mod = a % 10;                                /*"a" degiskenine de ayni degeri atadim */
        a = (a - mod) / 10;
    }
    while(bigNumber >= searchNumber){
        control = bigNumber % (int)pow(10, us);
        if(control == searchNumber){
            occurence = occurence + 1;
        }
        son = bigNumber % 10;
        bigNumber = ((bigNumber - son) / 10);
    }
    printf("Occurence: %d\n", occurence);
  
}


void triangleOfSequences()
{
    int sayi;
    sayi = numberGeneratorBetweenRange(2, 10);
    printf("Output(for %d)\n", sayi);
    for(int i = 1; i <= sayi; i++){
        for(int j = 1; j <=i; j++){
            printf("%d ", (j*i));
        }
        printf("\n");
    }
}
  