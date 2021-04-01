#include<stdio.h>


typedef struct pagina{
    int bv;
    char contentDISCO;
    frame *pv;
}page;
    frame RAM[2];
    page DISCO[20];
int i,j;
int main() {
    //Inicializando da RAM
    for (i=0; i<2; i++ )
        RAM[i].bv=0;
    //paginacao
    for(i=0; i<20; i++ ) {
        DISCO[i].contentDISCO='a' + i;
        DISCO[i].bv=1;
        DISCO[i].pv= NULL;
        //simulacao que a 5a e a 10a paginas sao mais usadas entao sobe a RAM
        if ((DISCO[i].contentDISCO == 'e') || (DISCO[i].contentDISCO == 'j'))
            for (j=0; j<2; j++) //aloca mais usado no 1o espaco da RAM disponivel
                if (RAM[j].bv==0) {
                    RAM[j].bv=1;
                    DISCO[i].pv=&RAM[j];//ponteiro do DISCO tem endereco da RAM que guarda a pagina
                    RAM[j].contentRAM=DISCO[i].contentDISCO;j=2;

                }
    }    
    printf("visualizacao DISCO\n");
    for (i=0; i<20;i++){
        printf("%d page [content:%c",i + 1,DISCO[i].contentDISCO);
        printf("BV:%d",DISCO[i].bv);
        printf("RAM:%d]\n",DISCO[i].pv );
    }
    printf("\nvisualizaco RAM\n");
    for (j=0; j<2 ; j++) {
        printf("%d frame [content:%c",j+1 ,RAM[j].contentRAM);
        printf("BV:%d]\n",RAM[j].bv);
    }
    return(0);
    }    

