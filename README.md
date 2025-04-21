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
 ```
```bash
 ./tp1 -i entrada.txt
```
## Entrada e Saída

### Formato do Arquivo de Entrada

#### Exemplo de Entrada

```txt
3 3
2 1 2 0 1
5 3
1 0 2 1 0 2 0 0
8 8
2 2 2 2 0 0 0 0 2 2 2 2 0 0 0 0 2 2 2 2 0 0 0 0 2 2 2 2 0 1 0 0
0 0
```

#### Exemplo de Saída

```txt
Força Bruta: 1 peças capturadas
Tempo de usuário: 0.000002s
Tempo de sistema: 0.000000s

Otimizada: 1 peças capturadas
Tempo de usuário: 0.000001s
Tempo de sistema: 0.000000s
---------------------------
Força Bruta: 2 peças capturadas
Tempo de usuário: 0.000001s
Tempo de sistema: 0.000000s

Otimizada: 2 peças capturadas
Tempo de usuário: 0.000001s
Tempo de sistema: 0.000000s
---------------------------
Força Bruta: 7 peças capturadas
Tempo de usuário: 0.000003s
Tempo de sistema: 0.000000s

Otimizada: 7 peças capturadas
Tempo de usuário: 0.000002s
Tempo de sistema: 0.000000s
---------------------------
```

## Limpeza

Para remover os arquivos compilados, utilize:

```bash
make clean
```

## Requisitos

- Compilador GCC
- Sistema operacional Linux

## Observações

- O programa foi testado e validado para uso nos laboratórios do DCOMP.
- Certifique-se de seguir o formato especificado para os arquivos de entrada e saída.
