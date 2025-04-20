# # Dama com Vovô 🧓♟️  com Estratégias de Força Bruta e Otimizada

Este projeto implementa um jogo de **Damas** com duas estratégias para capturar peças: uma **estratégia de força bruta** e uma **estratégia otimizada**. O código simula um jogo de damas onde o jogador tenta capturar o maior número de peças adversárias possível, usando duas abordagens de cálculo de movimentos.

## Funcionalidades

- **Estratégia de Força Bruta**: Tenta todas as possibilidades de movimentos e captura para encontrar a solução com o maior número de peças capturadas.
- **Estratégia Otimizada**: Utiliza uma abordagem mais eficiente, onde tenta otimizar os movimentos de captura.
- O programa lê o estado inicial do tabuleiro a partir de um arquivo de entrada, calcula o número máximo de peças que podem ser capturadas em uma sequência de movimentos e imprime o resultado.
- Os tempos de execução das funções são calculados para análise de desempenho.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

### `main.c`
- Arquivo principal do programa.
- Lê a entrada a partir de um arquivo (`entrada.txt`).
- Processa o tabuleiro com as duas estratégias e imprime o resultado.
- Mede e exibe o tempo de execução (tempo de usuário e sistema).

### `tabuleiro.c`
- Contém as funções de manipulação do tabuleiro, como leitura e liberação de memória.
- A função `ler_entrada` é responsável por ler o estado do tabuleiro a partir do arquivo de entrada.
- A função `liberar_tabuleiro` libera a memória alocada para o tabuleiro após a execução.

### `estrategia.c`
- Contém a implementação das estratégias de captura (força bruta e otimizada).
- A estratégia de **força bruta** percorre todas as possibilidades de captura.
- A estratégia **otimizada** tenta reduzir o número de movimentos, usando uma abordagem de busca mais inteligente.

### `tempo.c`
- Contém a função `imprimir_tempos`, que calcula e imprime o tempo de execução das funções em termos de tempo de usuário e sistema.

### `tabuleiro.h`, `estrategia.h`, `tempo.h`
- Arquivos de cabeçalho que declaram as funções e estruturas utilizadas nos arquivos `.c`.

## Compilação e Execução

### Compilação

Para compilar o programa, utilize o seguinte comando no terminal:

```bash
make

./tp1 -i entrada.txt


