#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// fibonacciyi hesaplayan fonksiyon
int fib(int b) {
    if (b == 1){
        return 1;
    }
    else if (b == 0) {
        return 0;
    }
    else {
        return fib(b-2) + fib(b-1);
    }
}

// fibonacciyi threadda çalıştıracak fonksiyon
void *fonksiyon(void *in) {
    int a = (int)in;
    int sonuc = fib(a);
    printf("%d ", sonuc);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
// for hesaplaması için değişken
    int j;

// thread içinde hesaplanacak fibonacci aralığını belirleyen değer
    int sayi;
    
//threadın özelliklerini tutmak için değişken
    pthread_attr_t özel;

// kullanıcının birden fazla sayı girip girmediğini kontrol eden fonksiyon
    if (argc != 2) {
        printf("ölçüm için tek bir sayi girin");
        return -1;
    }

// kullanıcının girdiği sayıyı integera çeviren kod
    sayi = atoi(argv[1]);

// kullanıcının girdiği sayı birden büyük mü ölçen fonksiyon
    if (sayi < 1) {
        printf("sayi 1 den büyük olmalidir");
        return -1;
    }

//thread özelliklerini başlatan fonksiyon
    pthread_attr_init(&özel);

// 0 dan sayı değerine kadar threadlar kullanarak fibonacci hesaplatacak fonksiyon
    for (int j = 0; j <= sayi; j++) {
        pthread_t thread;
        pthread_create(&thread, &özel, fonksiyon, (void *)j);
        pthread_join(thread, NULL);
    }
    return 0;
}
