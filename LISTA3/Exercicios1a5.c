#include <stdio.h>

struct ListaLigada
{
    int elemento;
    struct ListaLigada *proximo;
};

typedef struct ListaLigada ListaLigada;

struct ListaLigadaDupla
{
    int elemento;
    struct ListaLigadaDupla *proximo;
    struct ListaLigadaDupla *anterior;
};

typedef struct ListaLigadaDupla ListaLigadaDupla;

void AdicionarEmOrdem(ListaLigada **cabeca, int valor)
{
    ListaLigada *atual = *cabeca;

    if (atual->elemento == NULL)
    {
        atual->elemento = valor;
    }
    else
    {
        ListaLigada *novoElemento = (ListaLigada *)malloc(sizeof(ListaLigada));
        novoElemento->elemento = valor;
        novoElemento->proximo = NULL;

        if (valor < atual->elemento)
        {
            novoElemento->proximo = atual;
            *cabeca = novoElemento;
        }
        else
        {
            while (atual->proximo != NULL && valor > atual->proximo->elemento)
            {
                atual = atual->proximo;
            }

            novoElemento->proximo = atual->proximo;
            atual->proximo = novoElemento;
        }
    }
}

ListaLigada *FundirListas(ListaLigada **cabeca, ListaLigada **valores)
{
    ListaLigada *lista1 = *cabeca;
    ListaLigada *lista2 = *valores;

    printf("stop1");
    // Encontrar o último elemento da primeira lista
    while (lista1->proximo != NULL)
    {
        lista1 = lista1->proximo;
    }
    printf("stop2");

    lista1->proximo = lista2;

    ListaLigada *novalista = (ListaLigada *)malloc(sizeof(ListaLigada));
    novalista->elemento = NULL;
    novalista->proximo = NULL;

    return novalista;
}

void Imprimir(ListaLigada **cabeca)
{
    system("cls");
    ListaLigada *atual = *cabeca;
    printf("Lista:\n");
    while (atual != NULL)
    {
        printf(" %d |", atual->elemento);
        atual = atual->proximo;
    }

    printf("\n");
    system("pause");
}

void RemoverRepetidos(ListaLigada **cabeca)
{
    system("cls");

    if (*cabeca == NULL)
    {
        return;
    }

    ListaLigada *atual = *cabeca;
    ListaLigada *proxima = *cabeca;

    while (atual != NULL)
    {
        proxima = atual;

        while (proxima->proximo != NULL)
        {
            if (atual->elemento == proxima->proximo->elemento)
            {
                ListaLigada *temp = proxima->proximo;
                proxima->proximo = proxima->proximo->proximo;
                free(temp);
            }
            else
            {
                proxima = proxima->proximo;
            }
        }

        atual = atual->proximo;
    }

    printf("\n");
    system("pause");
}

void ImprimirDupla(ListaLigadaDupla **cabeca)
{
    system("cls");
    ListaLigada *atual = *cabeca;
    printf("Lista:\n");
    while (atual != NULL)
    {
        printf(" %d |", atual->elemento);
        atual = atual->proximo;
    }

    printf("\n");
    system("pause");
}

ListaLigada *InverterElemento(ListaLigada **cabeca)
{
    system("cls");

    if (*cabeca == NULL)
        return;

    ListaLigada *atual = *cabeca;
    ListaLigada *invertida = NULL;

    while (atual != NULL)
    {
        ListaLigada *NovoElemento = (ListaLigada *)malloc(sizeof(ListaLigada));

        NovoElemento->elemento = atual->elemento;
        if (invertida == NULL)
        {
            NovoElemento->proximo = NULL;
            invertida = NovoElemento;
        }
        else
        {
            NovoElemento->proximo = invertida;
            invertida = NovoElemento;
        }

        atual = atual->proximo;
    }

    printf("Lista Invertida com sucesso!\n");
    system("pause");
    return invertida;
}

void AdicionarEmOrdemDecrescente(ListaLigadaDupla **cabeca, int valor)
{
    ListaLigadaDupla *atual = *cabeca;

    if (atual == NULL)
    {
        atual = (ListaLigadaDupla *)malloc(sizeof(ListaLigadaDupla));
        atual->elemento = valor;
        atual->proximo = NULL;
        atual->anterior = NULL;
        *cabeca = atual;
    }
    else if (valor >= atual->elemento)
    {
        ListaLigadaDupla *novoElemento = (ListaLigadaDupla *)malloc(sizeof(ListaLigadaDupla));
        novoElemento->elemento = valor;
        novoElemento->proximo = atual;
        novoElemento->anterior = NULL;
        atual->anterior = novoElemento;
        *cabeca = novoElemento;
    }
    else
    {
        while (atual->proximo != NULL && valor < atual->elemento)
        {
            atual = atual->proximo;
        }

        if (valor < atual->elemento)
        {
            ListaLigadaDupla *novoElemento = (ListaLigadaDupla *)malloc(sizeof(ListaLigadaDupla));
            novoElemento->elemento = valor;
            novoElemento->proximo = NULL;
            novoElemento->anterior = atual;
            atual->proximo = novoElemento;
        }
        else
        {
            ListaLigadaDupla *novoElemento = (ListaLigadaDupla *)malloc(sizeof(ListaLigadaDupla));
            novoElemento->elemento = valor;
            novoElemento->proximo = atual->proximo;
            novoElemento->anterior = atual;
            if (atual->proximo != NULL)
            {
                atual->proximo->anterior = novoElemento;
            }
            atual->proximo = novoElemento;
        }
    }
}

ListaLigada *Modificarlista(ListaLigada **cabeca)
{
    int opcao, elemento;

    do
    {
        system("cls");
        printf("Lista em Ordem Crescente | Escolha uma opção:\n");
        printf("1 - Adicionar elementos em Ordem Crescente\n");
        printf("2 - Lista Elementos\n");
        printf("3 - Remove Elementos Repetidos\n");
        printf("4 - Inverte Elementos da Lista\n");
        printf("0 - Voltar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("1 - Digite o elemento\n");
            scanf("%d", &elemento);
            AdicionarEmOrdem(&cabeca, elemento);
            break;
        case 2:
            Imprimir(&cabeca);
            break;
        case 3:
            RemoverRepetidos(&cabeca);
            break;
        case 4:
            cabeca = InverterElemento(&cabeca);
            break;
        case 0:
            printf("Voltando...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 0);
    return cabeca;
}

ListaLigadaDupla *ModificarlistaDuplaEnca(ListaLigadaDupla **cabeca)
{
    int opcao, elemento;

    do
    {
        system("cls");
        printf("Lista Duplamente encadeada | Escolha uma opção:\n");
        printf("1 - Adicionar elementos em Ordem decrescente \n");
        printf("2 - Lista Elementos\n");
        printf("0 - Voltar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("1 - Digite o elemento\n");
            scanf("%d", &elemento);
            AdicionarEmOrdemDecrescente(&cabeca, elemento);
            break;
        case 2:
            Imprimir(&cabeca);
            break;
        case 0:
            printf("Voltando...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 0);
    return cabeca;
}

int main()
{
    ListaLigada *listaArray[5]; // Array de ponteiros para as listas
    ListaLigadaDupla *listaDupla = NULL;
    int opcao, elemento, elemento2;

    // Criando as listas
    for (int i = 0; i < 5; i++)
    {
        listaArray[i] = (ListaLigada *)malloc(sizeof(ListaLigada));
        listaArray[i]->elemento = NULL;
        listaArray[i]->proximo = NULL;
    }

    do
    {
        system("cls");
        printf("Escolha uma opção:\n");
        printf("1 - Selecionar Listas encadeadas\n");
        printf("2 - Unir Listas\n");
        printf("3 - Selecionar Listas duplamente encadeadas\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Listas:\n\n");
            for (int i = 0; i < 5; i++)
            {
                printf("Lista: %d\n", i);
            }
            printf("\npressione 0 para voltar\n");
            printf("Escolha o numero da lista para modificar:\n");
            scanf("%d", &elemento);
            if (elemento == 0)
                break;

            listaArray[elemento] = Modificarlista(listaArray[elemento]);
            break;
        case 2:
            system("cls");
            printf("Listas:\n\n");
            for (int i = 0; i < 5; i++)
            {
                printf("Lista: %d\n", i);
            }
            printf("\npressione 0 para voltar\n");
            printf("Escolha o numero da lista Destino:\n");
            scanf("%d", &elemento);
            printf("Escolha o numero da lista:\n");
            scanf("%d", &elemento2);
            if (elemento == 0 || elemento2 == 0)
                break;
            listaArray[elemento2] = FundirListas(&listaArray[elemento], &listaArray[elemento2]);
            break;
        case 3:
            system("cls");
            printf("Listas:\n\n");
            printf("Lista: 1\n");
            printf("\npressione 0 para voltar\n");
            printf("Escolha o numero da lista:\n");
            scanf("%d", &elemento);
            if (elemento == 0)
                break;
            listaDupla = ModificarlistaDuplaEnca(listaDupla);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);

    return 1;
}