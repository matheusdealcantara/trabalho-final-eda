# Trabalho Final de EDA - 2025.1

## FCTE - Delivery

### Visão Geral

A **FCTE** (Federação das Comidas Transportadas com Eficiência) é uma empresa do ramo de delivery em plena expansão. Diante da crescente demanda por novos colaboradores, você foi convidado a fazer parte dessa equipe (e ainda garantir uma graninha extra).

Após receber seu kit completo de trabalho, você está pronto para iniciar sua jornada de entregas. Partindo da sua residência, é preciso planejar uma rota eficiente para coletar e entregar pedidos de diversos restaurantes, sempre retornando ao ponto de partida ao final do trajeto. As ruas possuem um custo fixo de deslocamento, e alguns pontos oferecem postos de combustível. Seu veículo possui um tanque com capacidade limitada, e há também uma quantidade máxima de pedidos que podem ser transportados simultaneamente. Cada pedido, uma vez coletado, deve obrigatoriamente ser entregue.

Seu programa será interativo, se comunicando com um árbitro via entrada e saída padrão. A cada ação, você imprime um comando e imediatamente lê a resposta do árbitro.

### Ações Possíveis

As ações são realizadas imprimindo uma linha na saída padrão. As opções são:

- `m X` → mover-se para o local X, se for um vizinho imediato;
- `a` → abastecer no local atual (caso haja posto de combustível);
- `p D` → pegar pedido com destino ao local D;
- `e D` → entregar pedido com destino ao local D;
- `x` → encerrar a entrega (caso o entregador esteja em casa ou não seja possível continuar).

**Importante:** Após cada ação, seu programa deve obrigatoriamente ler a entrada padrão para receber a resposta do árbitro.

⚠️ **Qualquer ação inválida resultará em WA (Wrong Answer).**

### Respostas do Árbitro

#### `m X` — Mover-se para o local X

- Se há uma rua válida até X e combustível suficiente: o árbitro retorna `1` caso a ação seja possível.
- Caso contrário:
  - Rua inexistente → WA;
  - Combustível insuficiente → WA.

#### `a` — Abastecer

- Se há posto no local atual:
  - Na primeira vez, o tanque será preenchido até a capacidade máxima;
  - O árbitro retornará a quantidade de combustível restante no posto;
  - Se o posto tiver pouco combustível, abastece o máximo possível.
- Caso não haja posto → WA.

#### `p D` — Pegar pedido com destino D

- Adiciona o pedido à mochila;
- Se estiver na capacidade máxima → árbitro retorna `-1` (pedido perdido);
- O entregador deve estar no local do restaurante.

#### `e D` — Entregar pedido com destino D

- Se houver pedido com destino D, o pedido é removido e o árbitro retorna `1`;
- Caso contrário → WA.

#### `x` — Encerrar entrega

- Encerra o programa imediatamente;
- Quando utilizado fora de casa irá receber uma penalidade de `mod = 1.7`, caso contrário `mod = 1`.

### Pontuação

A pontuação por mapa será calculada seguindo a seguinte fórmula:

```
PF = PB / (((F · SP) + 1) · max(1, K) · mod)
```

**Legenda:**

| Símbolo | Significado                        |
| ------- | ---------------------------------- |
| F       | Entregas faltantes                 |
| SP      | Soma dos pesos de todas as arestas |
| K       | Quilometragem                      |
| PB      | Pontuação base                     |

### Entrada

A primeira linha contém sete inteiros:

```
N M H T I C P
```

Onde:

- **N**: número de locais (vértices), numerados de 1 a N;
- **M**: número de ruas (arestas);
- **H**: índice do local onde o entregador começa e termina (casa);
- **T**: capacidade máxima do tanque (em km);
- **I**: combustível inicial no tanque (em km);
- **C**: capacidade máxima da mochila (número máximo de pedidos);
- **P**: quantidade de locais que possuem posto de gasolina.

A segunda linha contém P inteiros indicando os locais que possuem posto de gasolina:

```
p₁ p₂ ⋯ pₚ
```

Em seguida, M linhas descrevem as ruas, cada uma contendo três inteiros:

```
u v w
```

- **u** e **v**: locais conectados (rua dirigida de u para v);
- **w**: custo (distância em km) da travessia.

Depois, uma linha com um inteiro Q — a quantidade de restaurantes.

Seguem Q linhas, cada uma contendo:

```
r k d₁ d₂ ⋯ dₖ
```

- **r**: local do restaurante;
- **k**: número de pedidos disponíveis;
- **dᵢ**: destino do i-ésimo pedido.

### Exemplo de Entrada

```
6 9 1 10 5 2 1
2
1 3 1
1 5 2
6 1 1
5 2 1
2 6 2
3 4 3
3 5 1
5 6 2
4 6 1
1
6 3 3 4 5
```

### Resolvendo o Problema Iterativo

A primeira linha de cada iteração representa a saída que o seu programa retorna para o juiz. A segunda linha representa a resposta do juiz.

⚠️ **Atenção:** toda iteração terá uma resposta, mesmo que não tenha algum significado.

#### Exemplo de Execução

```
Comando: mover para o local 5
m 5
1

Comando: mover para o local 2
m 2
1

Comando: abastecer
a
10
```

Perceba que o juiz retornou qual é a capacidade de combustível do posto. Nessa primeira iteração com o posto local, o veículo sempre consegue encher até a capacidade do tanque.

```
Comando: mover para o local 6
m 6
1

Comando: pegar pedido 3
p 3
1

Comando: pegar pedido 4
p 4
1

Comando: mover para o local 1
m 1
1

Comando: mover para o local 3
m 3
1

Comando: entregar no local 3
e 3
1

Comando: mover para o local 4
m 4
1

Comando: entregar no local 4
e 4
1

Comando: mover para o local 6
m 6
1

Comando: mover para o local 1
m 1
1

Comando: encerrar entregas
x
1
```

---

**Autores:** Bruno Ribas, Bruno Ribeiro, Caio Felipe, Igor Penha, Arthur Ribeiro
