#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void)
{
    int op=100, n, size=0, find, pos;

    while(op!=11){
        printf("\n(1)Inserir elemento\n(2)Mostrar lista\n(3)Remover elemento\n(4)Mostrar tamanho da lista\n(5)Buscar elemento\n(6)Mostrar elemento por posicao\n(7)Escrever em um arquivo TXT\n(8)Ordenar lista\n(9)Sair\n\n");
        scanf("%d",&op);
        if(op==1){
            printf("Digite o numero que deseja adicionar: ");
            scanf("%d",&n);
            printf("Agora, digite a posicao para adiciona-lo: ");
            scanf("%d",&pos);
            scanL(n,pos);
        }
        else if(op==2){
            impL(l);
        }
        else if(op==3){
            printf("Digite o numero que deseja remover: ");
            scanf("%d",&n);
            remL(n);
        }
        else if(op==4){
            printf("\nA lista possui %d elemento(s)\n\n",sizeL(l));
        }
        else if(op==5){
            printf("Digite o numero que deseja procurar na lista: ");
            scanf("%d",&n);
            size=sizeL(l);
            find=findnum(l,n,size);
            if(find==-1){
                printf("\nLista vazia!\n\n");
            }
            else if(find==-2){
                printf("\nElemento nao se encontra na lista\n\n");
            }
            else{
                printf("\n%d se encontra na posicao %d\n\n",n,find);
            }
        }
        else if(op==6){
            printf("\nDigite a posicao para mostrar o numero correspondente: ");
            scanf("%d",&pos);
            n=findpos(l,pos);
            printf("\nNumero encontrado: %d\n\n",n);
        }
        else if(op==7){
            printf("\nEscrevendo no arquivo:\n\n");
            escrevertxt(l);
            printf("\n\n");
        }
        else if(op==8){
            printf("\nLista ordenada:");
            size=sizeL(l);
            ordenaL(l,size);
        }
        else if(op==9){
            printf("\nFinalizando...");
            desalocaValores(l);
        }
        else{
            printf("\nOpcao invalida...\n");
        }
    }

    return 0;
}