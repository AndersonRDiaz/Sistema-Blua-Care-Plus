#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Paciente
typedef struct {
    int id;
    char nome[100];
    int urgencia; // 1: Baixa, 2: Media, 3: Alta
} Paciente;

// Nó da lista encadeada
typedef struct Node {
    Paciente dado;
    struct Node *proximo;
} Node;

// Estruturas de controle
typedef struct {
    Node *inicio;
    Node *fim;
} Fila;

typedef struct {
    Node *topo;
} Pilha;

// Funções da Fila (FIFO - First In, First Out)
void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Adiciona um paciente ao final da fila
void enqueue(Fila *f, Paciente p) {
    // Aloca memória dinamicamente para um novo nó
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->dado = p;
    novo->proximo = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
}

// Remove o primeiro paciente da fila (quem chegou antes)
int dequeue(Fila *f, Paciente *p) {
    if (f->inicio == NULL) return 0;

    // Ponteiro temporário para não perder o endereço do nó que será removido
    Node *temp = f->inicio;
    *p = temp->dado;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) f->fim = NULL;
    free(temp);
    return 1;
}

// Funções da Pilha (LIFO)
void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

// Adiciona um paciente ao topo da pilha (Empilhar)
void push(Pilha *p, Paciente pac) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->dado = pac;
    novo->proximo = p->topo;
    p->topo = novo;
}

// Remove o paciente do topo da pilha (Desempilhar)
int pop(Pilha *p, Paciente *p_sai) {
    if (p->topo == NULL) return 0;

    // Guarda o endereço do topo atual para poder liberar a memória depois
    Node *temp = p->topo;
    *p_sai = temp->dado;
    p->topo = p->topo->proximo;
    free(temp);
    return 1;
}

// Verifica se a fila está vazia
int fila_is_empty(Fila *f) {
    return (f->inicio == NULL);
}

// Retorna os dados do próximo da fila sem remover (Peek)
Paciente* fila_peek(Fila *f) {
    if (fila_is_empty(f)) return NULL;
    return &(f->inicio->dado);
}

// Menu e Lógica
int main() {
    Fila fila;
    Pilha historico;
    inicializarFila(&fila);
    inicializarPilha(&historico);

    int opcao, idContador = 1;

    do {
        printf("\n--- SISTEMA BLUA CARE PLUS ---\n");
        printf("1. Novo Paciente\n");
        printf("2. Chamar Proximo (Atender)\n");
        printf("3. Mostrar Fila\n");
        printf("4. Historico (Pilha)\n");
        printf("5. Desfazer Ultimo Atendimento\n");
        printf("6. Sair\n");
        printf("Escolha: ");
        // Tenta ler um número. Se retornar 0, significa que o usuário digitou texto.
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: Digite apenas os numeros do menu.\n");
            opcao = 0; // Reseta a opção para não repetir a anterior
        }
        
        // Limpa TODO o lixo que sobrou no buffer do teclado até o próximo Enter
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (opcao == 1) {
            Paciente novo;
            novo.id = idContador++;
            printf("Nome: ");
            fgets(novo.nome, 100, stdin);
            novo.nome[strcspn(novo.nome, "\n")] = 0;
            printf("Urgencia (1-Baixa, 2-Media, 3-Alta): ");
            scanf("%d", &novo.urgencia);
            enqueue(&fila, novo);
            printf("Paciente enfileirado!\n");

        } else if (opcao == 2) {
            Paciente atendido;
            if (dequeue(&fila, &atendido)) {
                printf("---------- ATENDIMENTO EM CURSO ----------\n");
                printf("  Paciente: %s | ID: %d\n", atendido.nome, atendido.id);
                printf("------------------------------------------\n");
                
                push(&historico, atendido);
            } else {
                printf("\nAlerta: Nao ha pacientes aguardando na fila.\n");
            }
        } else if (opcao == 3) {
            // Usando a função PEEK
            Paciente *proximo = fila_peek(&fila);
            
            if (proximo == NULL) {
                printf("Fila vazia.\n");
            } else {
                printf("\n--- PROXIMO A SER ATENDIDO ---\n");
                printf("ID: %d | Nome: %s | Urgencia: %d\n", 
                        proximo->id, proximo->nome, proximo->urgencia);
                printf("------------------------------\n");
                
                // Agora percorremos o restante da fila para mostrar a sequência
                printf("SEQUENCIA DA FILA:\n");
                Node *atual = fila.inicio;
                int posicao = 1;
                while (atual != NULL) {
                    printf("%d. ID: %d | %s\n", posicao, atual->dado.id, atual->dado.nome);
                    atual = atual->proximo;
                    posicao++;
                }
                printf("------------------------------------------\n");
            }
            
        } else if (opcao == 4) {
            Node *atual = historico.topo;
            if (!atual) {
                printf("\nO historico de atendimentos esta vazio.\n");
            } else {
                printf("\n--- HISTORICO DE CONSULTAS (Auditoria) ---\n");
                while (atual) {
                    printf("PACIENTE ATENDIDO -> ID: %d | Nome: %s\n", 
                            atual->dado.id, atual->dado.nome);
                    atual = atual->proximo;
                }
                printf("------------------------------------------\n");
            }

        } else if (opcao == 5) {
            Paciente cancelado;
            if (pop(&historico, &cancelado)) {
                // Devolve para o inicio da fila
                Node *novo = (Node *)malloc(sizeof(Node));
                novo->dado = cancelado;
                novo->proximo = fila.inicio;
                fila.inicio = novo;
                if (fila.fim == NULL) fila.fim = novo;
                printf("Atendimento de %s desfeito.\n", cancelado.nome);
            } else {
                printf("Nada para desfazer.\n");
            }
        }

    } while (opcao != 6);

    return 0;
}
