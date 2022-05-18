#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
#include<time.h>

using namespace std;


int valoresAleatorios(int vetor[], int qtdNumero){

        for (int i = 0; i < qtdNumero; i++){
        vetor[qtdNumero] = rand() % qtdNumero + 1;
        }
            return(vetor[qtdNumero]);

}
void troca(int vetor[], int a, int b) {
    int aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
}
int particiona(int vetor[], int s, int e) {

    int pivot = vetor[s];
    int i = s;
    for (int j = s + 1; j <= e; j++) {
        if (vetor[j] <= pivot) {
            i++;
            troca(vetor, i, j);
        }
    }
    troca(vetor, s, i);
    return i;
}
int quickSort(int vetor[], int s, int e) {
    if (s < e) {
        int p = particiona(vetor, s, e);

        quickSort(vetor, s, p - 1);
        quickSort(vetor, p + 1, e);
    }
}
void merge(int vetor[], int s, int m, int e) {
    int tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (vetor[i] < vetor[j]) {
            tmp[k++] = vetor[i++];
        } else {
            tmp[k++] = vetor[j++];
        }
    }
    for (; i <= m; i++, k++) {
        tmp[k] = vetor[i];
    }
    for (; j <= e; j++, k++) {
        tmp[k] = vetor[j];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        vetor[i] = tmp[k];
    }
}
void mergeSort(int vetor[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(vetor, s, m);
        mergeSort(vetor, m + 1, e);
        merge(vetor, s, m, e);
    }
}

int ordenarValores(int vetor[], int qtdNumero){
    for (int i = 0; i < qtdNumero; i++){
        printf("\t %d",vetor[qtdNumero]);
    }
}

int buscaSequencial(int vetor[], int qtdNumero, int buscar) {
    for (int i = 0; i < qtdNumero; i++) {
        if (vetor[i] == buscar) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int vetor[], int n, int buscar) {
    int inicio = 0, fim = buscar - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (buscar == vetor[meio]) {
            return meio;
        } else if (buscar > vetor[meio]) {
            inicio = meio + 1;
        } else if (buscar < vetor[meio]) {
            fim = meio - 1;
        }
    }
}

void imprimirVetor(int vetor[], int qtdNumero) {
    for (int i = 0; i < qtdNumero; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
void menu(){
    printf("       MENU       \n");
    printf("1 - Gerar Vetor \n");
    printf("2 - Ordena Vetor \n");
    printf("3 - Busca Sequencial \n");
    printf("4 - Busca Binaria \n");
    printf("5 - Fechar Programa \n");
}
int escolha(int vetor[],int qtdNumero, bool quit_menu){
char opcao , mous;
    menu();
    while(!quit_menu){
    scanf("%d", &opcao);
    opcao = tolower(opcao);
        switch (opcao){
             case '1':
                        printf("Digite a quantidade de valor que deseja gerar: ");
                        scanf("%d",&qtdNumero);
                        printf("\n\n\t\t\t Valores aleatorios\n");
                        valoresAleatorios(vetor,qtdNumero);
                        imprimirVetor(vetor, qtdNumero);

                        break;
            case '2':
                            printf("\n\n\t\t\t Ordenando vetores\n");
                            printf("\n\t\t\tq Ordenacao pelo metodo quick");
                            printf("\n\t\t\tm Ordenacao pelo metodo marge");
                            scanf("%s", &mous);
                            mous = tolower(mous);
                                switch(mous)
                                case 'q':
                                        quickSort(vetor, 0, 1);
                                        imprimirVetor(vetor, qtdNumero);

                                    break;
                                case 'm':
                                        mergeSort(vetor, 0, qtdNumero - 1);
                                        imprimirVetor(vetor, qtdNumero);

                                    break;
                            ordenarValores(vetor, qtdNumero);
                            break;


            case '3':
                            printf("\n\n\t\t\t Busca sequencial\n");
                            break;


            case '4':
                            printf("\n\n\t\t\t Busca binaria\n");

                            break;

            case '5':
                            printf("\n\n\t\t\t Fechando programa\n");
                            quit_menu= true;
                            break;

                }

    }
}

int main(){
    srand(time(NULL));
    int qtdNumero;
    char opcao;
    bool quit_menu;
    int vetor[qtdNumero];
    escolha(vetor,qtdNumero,quit_menu);

}


