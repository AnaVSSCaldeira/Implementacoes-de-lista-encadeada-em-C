typedef struct NO no; //criando a estrutura no
struct NO
{
    int v; //valor do no
    no *p; //ponteiro tipo no que aponta para o prox no
};

no *l=NULL;

void desalocaValores(no *lista) //dar um free na lista
{
    if (lista->p != NULL)
    {
        desalocaValores(lista->p);
    }
    free(lista);
    return;
}

void escrevertxt(no *l){
    printf("\n\nESCREVENDO EM UM ARQUIVO TXT\n");
    typedef struct ARQUIVO arquivo; //criando a estrutura no
    struct ARQUIVO
    {
        int v; //valor do no
    };

    FILE *arq; //cria o arquivo
    char arqaux;

    if ((arq = fopen("lista.txt", "w")) == NULL) //nao consegue abrir o arquivo
        printf("Não foi possivel abrir o arquivo!");
    else //consegue abrir o arquivo pra escrever
    {
        arquivo umvalor;
        int sair = 0;
        while (sair != -1)
        {
        printf("\nInforme o numero que quer adicionar: ");
        scanf("%d", &umvalor.v);
        printf("Quer sair? Digite -1: ");
        scanf("%d", &sair);
        arqaux = fprintf(arq, "%d\n", umvalor.v);
        }

        fclose(arq); //fecha o arquivo

        no *lnum = NULL; //cria lista pra receber os registros do arquivo

        if ((arq = fopen("lista.txt", "r")) == NULL) //nao consegue abrir o arquivo
        printf("Não foi possivel abrir o arquivo!");
        else //consegue abrir o arquivo para leitura
        {
        printf("\n**********************\n");
        int numAux = 0;
        while (fscanf(arq, "%d", &numAux) != EOF){
            no *aux = NULL; //aux pra andar na lista
            aux = (no *)malloc(sizeof(no));
            aux->v = numAux;

            printf("\nNumero: %d", aux->v);
            aux->p = lnum;
            lnum = aux;
        }
        desalocaValores(lnum);
        }
    }
    fclose(arq);
}

void lertxt(no *l){
    printf("\n\nLENDO EM UM ARQUIVO TXT\n");
    FILE *arq;
    if ((arq = fopen("lista.txt", "r")) == NULL) //nao consegue abrir o arquivo
        printf("Não foi possivel abrir o arquivo!");
        else //consegue abrir o arquivo para leitura
        {
        printf("\n**********************\n");
        no *lnum = NULL;
        int numAux = 0;
        while (fscanf(arq, "%d", &numAux) != EOF){
            no *aux = NULL; //aux pra andar na lista
            aux = (no *)malloc(sizeof(no));
            aux->v = numAux;

            printf("\nNumero: %d", aux->v);
            aux->p = lnum;
            lnum = aux;
        }
        desalocaValores(lnum);
        }
    
    fclose(arq);
}

int sizeL(no *l){
    if(l!=NULL){
        int cont=0;
        while(l!=NULL){
            cont++;
            l=l->p;
        }
        return cont;
    }
    else{
        return 0;
    }
}

void impL(no *l){//IMPRIME LISTA
    no *aux=l;
    printf("\nLista: ");
    while(aux!=NULL){
        printf("%d ",aux->v);
        aux=aux->p;
    }
    printf("\n\n");
}

void scanL(int N, int P){
    int T;
    T=sizeL(l);
    if(P>=0 && P<=T){
        no *novo=malloc(sizeof(no));
        novo->v=N;
        novo->p=NULL;
        if(T==0){
            l=novo;
        }
        else if(P==0){
            novo->p=l;
            l=novo;
        }
        else{
            no *aux=l;
            int i;
            for(i=0;i<P-1;i++){
                aux=aux->p;
            }
            novo->p=aux->p;
            //1 -> 4 -> 2 3 -> 5 -> NULL
            aux->p=novo;
        }
    }else{
        printf("\nPosicao invalida!\n\n");
    }
}

int findnum(no *l, int N, int S){ //lista, numero, tamanho da lista
    int F=-2, i;
    if(l!=NULL){
        no *aux=l;
        for(i=0;i<S;i++){
            if(aux->v==N){
                F=i;
                return F;
            }
            aux=aux->p;
        }
        if(F==-2){
            return F;
        }
    }
    else{
        F=-1;
        return F;
    }
}

int findpos(no *L, int P){
    no *aux=L;
    int i=0,valor=-1, T;
    T=sizeL(l);
    if(L!=NULL && (P>=0 && P<T)){
        while(aux!=NULL){
            if(P==i){
                valor=aux->v;
            }
            aux=aux->p;
            i++;
        }
    }
    else if(L!=NULL){
        printf("\nPosicao invalida\n");
        return valor;
    }
    else{
        printf("\nLista vazia\n");
        return valor;
    }
    return valor;
}

void ordenaL(no *L, int S){
    if(L!=NULL){
        int cont=1, i, recebe;
        no *aux;
        while(cont>0){
            aux=L;
            cont=0;
            for(i=0;i<S;i++){
                if(i<(S-1) && aux->v>aux->p->v){
                    cont+=1;
                    recebe=aux->v;
                    aux->v=aux->p->v;
                    aux->p->v=recebe;
                }
                aux=aux->p;
            }
        }
        impL(L);
    }
    else{
        printf("\nLista vazia!\n\n");
    }
}

void remL(int N){
    int T,f=0;
    T=sizeL(l);
    if(T>0){
        if(T==1 && l->v==N){
            l=NULL;
        }
        else if(T>1 && l->v==N){
            l=l->p;
        }
        else{
            f=findnum(l,N,T);
            if(f!=-2){
                no *aux=l;
                while(aux->p->v!=N || aux->p==NULL){
                    aux=aux->p;
                }
                aux->p=aux->p->p;
                printf("\nNumero removido!\n\n");
            }
            else{
                printf("\nNumero nao encontrado!\n\n");
            }
        }
    }else{
        printf("\nLista vazia!\n\n");
    }
}