#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -100000000

struct dugum{
   int icerik;
   struct dugum *link;
};

struct dugum *dugum_olustur(int icerik){
    struct dugum *d;
    d=(struct dugum*)malloc(sizeof(struct dugum));
    if(d==NULL){
        printf("Yer ayrilamadi... exit...");
        exit(1);
    }
    d->icerik=icerik;
    d->link =NULL;
    return d;
}

void ekle(int icerik, struct dugum **dugum_gostergesi){
    struct dugum *d=dugum_olustur(icerik);
    d->link = *dugum_gostergesi;
    *dugum_gostergesi=d;
}

void yazdir(struct dugum *yigin_gostergesi){
    while(yigin_gostergesi){
        printf("%4d ",yigin_gostergesi->icerik);
        yigin_gostergesi=yigin_gostergesi->link;
    }
    printf("\n");
}

 /* void yazdir_yanlis(struct dugum **yigin_gostergesi){
    while(*yigin_gostergesi){
        printf("%4d ",(*yigin_gostergesi)->icerik);
        *yigin_gostergesi=(*yigin_gostergesi)->link;
    }
    printf("\n");
} */

int cikar(struct dugum **yigin_gostergesi){
    struct dugum *d;
    int icerik;

    if(*yigin_gostergesi == NULL) return SENTINEL;
    d=*yigin_gostergesi;
    *yigin_gostergesi=(*yigin_gostergesi)->link;
    icerik=d->icerik;

    free(d);
    return icerik;
}

int yigin_bosmu(struct dugum *yigin_isaretcisi){
    if(yigin_isaretcisi == NULL) return 1;
    else return 0;
}

int main(int argc, char** argv) {

    int a;
    struct dugum *yigin_gostergesi=NULL;

    ekle(100,&yigin_gostergesi);
    ekle(20,&yigin_gostergesi);
    ekle(60,&yigin_gostergesi);

    yazdir(yigin_gostergesi);
    yazdir(yigin_gostergesi);
    
    a=cikar(&yigin_gostergesi);

    if(a!==SENTINEL) printf(" %4d \n",a);
    yazdir(yigin_gostergesi);
    
    return (EXIT_SUCCESS);
}
