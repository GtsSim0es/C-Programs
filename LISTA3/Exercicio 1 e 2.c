#include <stdio.h>

struct ListaLigada
{
    int elemento;
    struct ListaLigada *proximo;
};

typedef struct ListaLigada ListaLigada;

void AdicionarEmOrdem(ListaLigada **cabeca, int valor)
{
    ListaLigada *novoElemento = (ListaLigada *)malloc(sizeof(ListaLigada));
    novoElemento->elemento = valor;
    novoElemento->proximo = NULL;

    if (*cabeca == NULL || valor < (*cabeca)->elemento)
    {
        novoElemento->proximo = *cabeca;
        *cabeca = novoElemento;
    }
    else
    {
        ListaLigada *atual = *cabeca;
        while (atual->proximo != NULL && valor > atual->proximo->elemento)
        {
            atual = atual->proximo;
        }

        novoElemento->proximo = atual->proximo;
        atual->proximo = novoElemento;
    }
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

void Modificarlista(ListaLigada **cabeca)
{
    int opcao, elemento;

    do
    {
        system("cls");
        printf("Lista em Ordem Crescente | Escolha uma opção:\n");
        printf("1 - Adicionar elemento\n");
        printf("2 - imprimir\n");
        printf("3 - Remove Repetidos\n");
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
        case 0:
            printf("Voltando...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 0);
}

void main()
{
    ListaLigada *listaArray[5]; // Array de ponteiros para as listas
    int opcao, elemento;

    // Criando as listas
    for (int i = 0; i < 5; i++)
    {
        listaArray[i] = (ListaLigada *)malloc(sizeof(ListaLigada));
        listaArray[i]->elemento = i + 1;
        listaArray[i]->proximo = NULL;
    }

    do
    {
        system("cls");
        printf("Listas:\n\n");
        for (int i = 0; i < 5; i++)
        {
            printf("Lista: %d\n", listaArray[i]->elemento);
        }
        printf("\npressione 0 para sair\n");
        printf("Escolha o numero da lista para modificar:\n");

        scanf("%d", &elemento);
        Modificarlista(listaArray[elemento]);

    } while (opcao != 0);
}