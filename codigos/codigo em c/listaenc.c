#include <stdio.h>
#include <stdlib.h>
#include "lista.h" //biblioteca que criei

int main(void)
{
    int op=100, n, size=0, find, pos;
    /*opcao para ser escolhida, numero para inserir/remover, tamanho da lista, variavel
    para achar um elemento, e posicao*/
    while(op!=11){
        //lista de opcoes
        printf("\n(1)Inserir elemento\n(2)Mostrar lista\n(3)Remover elemento\n(4)Mostrar tamanho da lista\n(5)Buscar elemento\n(6)Mostrar elemento por posicao\n(7)Escrever em um arquivo TXT\n(8)Ordenar lista\n(9)Sair\n\n");
        scanf("%d",&op);
        if(op==1){ //para adicionar
            printf("Digite o numero que deseja adicionar: ");
            scanf("%d",&n);
            printf("Agora, digite a posicao para adiciona-lo: ");
            scanf("%d",&pos);
            scanL(n,pos);
        }
        else if(op==2){ //para mostrar a lista
            impL(l);
        }
        else if(op==3){ //para remover algum elemento da lista
            printf("Digite o numero que deseja remover: ");
            scanf("%d",&n);
            remL(n);
        }
        else if(op==4){ //para saber o tamanho da lista
            printf("\nA lista possui %d elemento(s)\n\n",sizeL(l));
        }
        else if(op==5){ //para procurar um elemento na lista
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
        else if(op==6){ //procurar elemento por posicao
            printf("\nDigite a posicao para mostrar o numero correspondente: ");
            scanf("%d",&pos);
            n=findpos(l,pos);
            printf("\nNumero encontrado: %d\n\n",n);
        }
        else if(op==7){ //escrever em um arquivo
            printf("\nEscrevendo no arquivo:\n\n");
            escrevertxt(l);
            printf("\n\n");
        }
        else if(op==8){ //ordenar a lista por bubblesort
            printf("\nLista ordenada:");
            size=sizeL(l);
            ordenaL(l,size);
        }
        else if(op==9){ //finalizando o programa e desalocando a lista
            printf("\nFinalizando...");
            desalocaValores(l);
        }
        else{ //se a pessoa digitar uma opcao invalida
            printf("\nOpcao invalida...\n");
        }
    }

    return 0;
}