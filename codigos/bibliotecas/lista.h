typedef struct NO no; //criando a estrutura no
struct NO
{
    int v; //valor do no
    no *p; //ponteiro tipo no que aponta para o prox no
};

no *l=NULL; //lista tipo no como variavel global inicia como nula

//parametro: lista encadeada
void desalocaValores(no *lista) //dar um free na lista ao final do programa
{
    if (lista->p != NULL) //enquanto nao estiver vazia
    {
        desalocaValores(lista->p); //chama a propria funcao
    }
    free(lista);
    return;
}

//parametro: lista encadeada
void escrevertxt(no *l){ //escrever em um arquivo txt
    printf("\n\nESCREVENDO EM UM ARQUIVO TXT\n");
    typedef struct ARQUIVO arquivo; //criando a estrutura do arquivo
    struct ARQUIVO
    {
        int v; //valor do no
    };

    FILE *arq; //cria o arquivo
    char arqaux; //auxiliar para andar no arquivo

    if ((arq = fopen("lista.txt", "w")) == NULL) //nao consegue abrir o arquivo lista.txt
        printf("Não foi possivel abrir o arquivo!");
    else //consegue abrir o arquivo pra escrever
    {
        arquivo umvalor;
        int sair = 0;
        while (sair != -1) //vai adicionando ate sair ser diferente de -1
        {
            printf("\nInforme o numero que quer adicionar: ");
            scanf("%d", &umvalor.v);
            printf("Quer sair? Digite -1: ");
            scanf("%d", &sair);
            arqaux = fprintf(arq, "%d\n", umvalor.v); //escreve o valor no arquivo
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
            //lê do arquivo, adiciona na lista e mostra na tela os valores adicionados
            no *aux = NULL; //aux pra andar na lista
            aux = (no *)malloc(sizeof(no));
            aux->v = numAux;

            printf("\nNumero: %d", aux->v);
            aux->p = lnum;
            lnum = aux;
        }
        //ao final, desaloca a lista
        desalocaValores(lnum);
        }
    }
    fclose(arq);
}

//parametro: lista encadeada
int sizeL(no *l){ //retorna o tamanho da lista
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

//parametros: numero e posicao
void scanL(int N, int P){ //recebe os elementos para adicionar na lista
    int T;
    T=sizeL(l);//pega o tamanho da lista encadeada
    if(P>=0 && P<=T){//se a posicao for maior/igual a 0 e menor/igual que o tamanho
        no *novo=malloc(sizeof(no));//aloca um espaco na memoria
        novo->v=N;//no apontado valor é igual ao numero que a pessoa digitou
        novo->p=NULL;//no apontado proximo = a NULL

        //se a lista estiver vazia
        if(T==0){
            l=novo; //lista recebe o novo no
        }
        //se nao estiver vazia mas quer adicionar no inicio
        else if(P==0){
            novo->p=l;//
            l=novo;
        }
        //se for adicionar no meio ou no final
        else{
            no *aux=l;//auxiliar para andar na lista
            int i;
            for(i=0;i<P-1;i++){ //for para andar ate a posicao que a pessoa quer (-1)
                aux=aux->p;
            }
            //novo apontado proximo recebe o aux apontado proximo
            novo->p=aux->p;
            //1 -> 4 -> 2 3 -> 5 -> NULL
            aux->p=novo;
        }
    //se a posicao nao for valida
    }else{
        printf("\nPosicao invalida!\n\n");
    }
}

//parametros: lista, numero, tamanho da lista
int findnum(no *l, int N, int S){ //acha um numero da lista
    int F=-2, i; //flag para dizer se achou ou lista esta vazia
    //lista nao esta vazia
    if(l!=NULL){
        no *aux=l;//criar um auxiliar para perdorrer a lista
        for(i=0;i<S;i++){//percorre em relacao ao tamanho
            if(aux->v==N){ //se achar o numero, guarda a posicao
                F=i;
                return F; //retorna a posicao pelo flag
            }
            aux=aux->p;
        }
        //se nao achar, retorna -2
        if(F==-2){
            return F;
        }
    }
    //lista vazia, retorna -1
    else{
        F=-1;
        return F;
    }
}

//parametros: lista encadeada, posicao
int findpos(no *L, int P){ //mostra o numero pela posicao
    no *aux=L;
    int i=0,valor=-1, T; //valor = -1 se nao ahcar pela posicao e tamanho da lista
    T=sizeL(l);
    //se a lsita nao estiver vazia e a posicao for correspondente
    if(L!=NULL && (P>=0 && P<T)){
        while(aux!=NULL){
            if(P==i){
                valor=aux->v;
            }
            aux=aux->p;
            i++;
        }
    }
    //se a lista nao estiver vazia mas a posicao for invalida
    else if(L!=NULL){
        printf("\nPosicao invalida\n");
        return valor;
    }
    //se estiver vazia
    else{
        printf("\nLista vazia\n");
        return valor;
    }
    return valor;
}

//parametros: lista encadeada e tamanho da lista
void ordenaL(no *L, int S){ //ordena pelo metodo Bubble Sort
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

//parametro: numero para remover
void remL(int N){
    int T,f=0;
    T=sizeL(l); //pega o tamanho da lista
    //se a lista nao estiver vazia
    if(T>0){
        //se a lista tiver um so elemento e ele for o que o usuario digitou
        if(T==1 && l->v==N){
            l=NULL;
        }
        //se a lista tiver mais de um elemento e ele for o primeiro da lista
        else if(T>1 && l->v==N){
            l=l->p;
        }
        //se o elemto estiver no meio ou no final da lista
        else{
            f=findnum(l,N,T);//tenta encontrar o numero
            //se encontrar
            if(f!=-2){
                no *aux=l;
                //percorre ate o valor do proximo aux for N ou quando o proximo for NULL
                while(aux->p->v!=N || aux->p==NULL){
                    aux=aux->p;
                }
                //o proximo do aux aponta para o no depois do proximo dele
                aux->p=aux->p->p;
                printf("\nNumero removido!\n\n");
            }
            //se nao achar o numero
            else{
                printf("\nNumero nao encontrado!\n\n");
            }
        }
    //se a lista estiver vazia
    }else{
        printf("\nLista vazia!\n\n");
    }
}