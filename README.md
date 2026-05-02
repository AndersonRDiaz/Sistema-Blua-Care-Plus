# 🏥 Sistema de Gerenciamento de Teleconsultas - Blua (Care Plus)

Este projeto foi desenvolvido como parte do desafio de **Estrutura de Dados**, simulando o fluxo de atendimento da plataforma **Blua** da **Care Plus**. O sistema gerencia solicitações de teleconsultas, prioriza ações administrativas e mantém um histórico para auditoria.

## 🚀 Funcionalidades

O sistema utiliza estruturas de dados dinâmicas para oferecer:
- **Fila de Espera (FIFO):** Pacientes são atendidos na ordem de chegada.
- **Histórico de Atendimentos (LIFO):** Registro das últimas consultas usando uma pilha para auditoria rápida.
- **Ação de Desfazer:** Permite cancelar o último atendimento e devolver o paciente ao topo da fila com prioridade imediata.
- **Painel de Visualização:** Exibição do próximo paciente e da listagem completa da fila.

## 🛠️ Requisitos Técnicos Atendidos

Para demonstrar o domínio de gerenciamento de memória em baixo nível, o projeto foi construído **sem bibliotecas prontas** de fila ou pilha, utilizando apenas:
- **Linguagem:** C
- **Gerenciamento de Memória:** Alocação dinâmica com `malloc` e `free`.
- **Estrutura Base:** Listas Encadeadas (Nós/Nodes)
- **Complexidade:** Operações principais implementadas em tempo constante **O(1)**

- ## 📂 Como Executar o Projeto

Para facilitar a avaliação, o projeto pode ser executado diretamente no navegador via **OnlineGDB**:

1. Copie todo o conteúdo do arquivo `main.c` deste repositório.
2. Acesse o [OnlineGDB (C Compiler)](https://www.onlinegdb.com/online_c_compiler).
3. Cole o código no editor central.
4. No canto superior direito, certifique-se de que a linguagem selecionada é **C**.
5. Clique no botão verde **Run** (ou pressione `F9`).
6. O menu interativo aparecerá no console na parte inferior da tela.

### Execução Local (Alternativa)
Caso possua o compilador GCC instalado:
```bash
gcc main.c -o sistema_blua
./sistema_blua
