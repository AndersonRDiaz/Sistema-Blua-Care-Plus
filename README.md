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
