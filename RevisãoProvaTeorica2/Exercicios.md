1. Conceitos de Grafos
- vertice: é tipo um ponto  
- aresta: ligação entre pontos  
- grafo direcionado: tem setinha  
- grafo n direcionado: sem direção  
- ponderado: tem peso

2. Matriz vs Lista de Adjacência
matriz: usa matriz quadrada, ocupa espaço mas é rapida  
lista: usa lista p/ cada nó, economiza memória mas é + lenta pra ver ligação

3. BFS
usa fila  
vai em camada  
bom p/ caminho + curto em grafo sem peso

4. Dijkstra
acha menor caminho  
funciona só com peso positivo  
usa fila de prioridade  
usado em GPS e rede

5. DFS
vai fundo antes de voltar  
usa pilha ou recursão  
bom pra ver conexão, ciclo, etc

6. Sequencial vs Binária
sequencial: vai um por um  
binária: divide no meio (precisa estar ordenado)  
binária = mais rápida se estiver ordenado

7. Bubble Sort
troca vizinho até ficar certo  
pior caso é n²  
lento pra listas grandes

8. Merge Sort
divide em dois  
ordena separado  
junta  
sempre n log n

9. Hash
tabela que guarda chave-valor  
usa função hash  
rápida (O(1)) p/ inserir e buscar

10. Complexidade
tempo: quanto tempo gasta  
espaço: quanta memória gasta  
serve p/ saber qual algoritmo é melhor

11. Quick vs Bubble
resp: C  
quick sort é mais rápido p/ listas grandes

12. Estabilidade
resp: D  
selection sort não é estável

13. Espaço Merge Sort
resp: C  
usa arrays temporários no merge

14  
resp: A → [3, 7, 5, 1, 2]

15  
resp: A – bubble sort com otimização é linear no melhor caso

16  
insertion sort é melhor q selection p/ lista quase ordenada, e é estável  
selection é sempre n² e não é estável

