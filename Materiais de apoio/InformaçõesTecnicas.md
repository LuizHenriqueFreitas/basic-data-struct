## **1. Defina os seguintes conceitos relacionados a Grafos:**

- **Vértice (ou Nó):** Unidade fundamental de um grafo que representa entidades (pessoas, cidades, etc.).
- **Aresta:** Conexão entre dois vértices. Pode ser direcionada ou não.
- **Grafo Direcionado:** Grafo cujas arestas possuem direção, ou seja, vão de um vértice a outro específico.
- **Grafo Não Direcionado:** Grafo cujas arestas não possuem direção; a conexão é bidirecional.
- **Grafo Ponderado:** Grafo cujas arestas possuem um peso associado (custo, distância, etc.).

---

## **2. Diferença entre Matriz de Adjacência e Lista de Adjacência:**

### Matriz de Adjacência:
- Representada por uma matriz `n x n` onde `n` é o número de vértices.
- **Vantagem:** Acesso rápido (O(1)) para verificar existência de aresta.
- **Desvantagem:** Gasta muito espaço (O(n²)), mesmo em grafos esparsos.

### Lista de Adjacência:
- Cada vértice possui uma lista com seus vizinhos.
- **Vantagem:** Menor consumo de memória em grafos esparsos.
- **Desvantagem:** Verificar se há conexão entre dois vértices pode ser mais lento (O(n) no pior caso).

---

## **3. Funcionamento da Busca em Largura (BFS):**

- Explora os vértices em “camadas”.
- Utiliza uma **fila** para explorar primeiro os vizinhos mais próximos do vértice inicial.
- **Mais adequado para:** Encontrar o caminho mais curto em grafos não ponderados ou percorrer todos os vértices em largura.

---

## **4. Objetivo e funcionamento do Algoritmo de Dijkstra:**

- **Objetivo:** Encontrar o menor caminho de um vértice origem até os demais vértices em um grafo **ponderado com pesos não negativos**.
- **Funcionamento:**
  - Mantém um conjunto de distâncias mínimas atualizadas.
  - Usa uma fila de prioridade para visitar o próximo vértice com menor custo.
- **Aplicação típica:** Roteamento de redes, GPS, planejamento de rotas.

---

## **5. Funcionamento da Busca em Profundidade (DFS):**

- Explora o grafo o mais profundamente possível antes de retroceder.
- Utiliza **pilha** (explícita ou implícita via recursão).
- **Mais adequado para:** Verificar conectividade, ciclos, componentes conexas, etc.

---

## **6. Diferença entre Pesquisa Sequencial e Pesquisa Binária:**

- **Pesquisa Sequencial:** Percorre o array elemento por elemento (O(n)).
- **Pesquisa Binária:** Divide o array ao meio recursivamente (O(log n)), mas **exige que os dados estejam ordenados**.
- **Conclusão:** A binária é mais eficiente quando os dados estão ordenados, devido à sua baixa complexidade.

---

## **7. Funcionamento do Bubble Sort:**

- Compara pares de elementos adjacentes e os troca se estiverem fora de ordem.
- Repete esse processo até que o array esteja ordenado.
- **Pior caso:** O(n²) — quando a lista está completamente invertida.
- Muito ineficiente para grandes listas.

---

## **8. Dividir para conquistar (Merge Sort):**

- **Divide:** O array é dividido recursivamente em duas metades.
- **Conquista:** Cada metade é ordenada recursivamente.
- **Combina:** As duas metades ordenadas são intercaladas (merge).
- **Complexidade:** O(n log n) no melhor, médio e pior caso.

---
# ✅ Revisão Teórica – Estruturas de Dados (Questões 9 a 16)

---

### **9. Defina o conceito de Tabela Hash e sua finalidade.**

**Resposta:**  
Uma **tabela hash** armazena pares **chave-valor** e usa uma **função hash** para calcular o índice onde os dados serão inseridos ou buscados.

**Explicação breve:**  
É usada para **acesso rápido** a dados, com complexidade média de O(1) para inserção, busca e remoção. Muito usada em bancos de dados e dicionários.

---

### **10. Explique o que é complexidade de tempo e espaço de um algoritmo.**

**Resposta:**

- **Tempo:** Mede quanto tempo o algoritmo leva para executar conforme o tamanho da entrada.  
- **Espaço:** Mede quanta **memória adicional** o algoritmo utiliza.  
- Ambas são analisadas em **termos assintóticos** (ex: O(n), O(log n)).

**Explicação breve:**  
Ajuda a **comparar algoritmos** e escolher o mais eficiente, principalmente em aplicações com grandes volumes de dados ou recursos limitados.

---

### **11. Sobre Quick Sort e Bubble Sort, qual é a correta?**  
**Alternativa correta:** **C. O Quick Sort tende a ser mais eficiente para grandes conjuntos de dados.**

**Explicação breve:**  
Quick Sort tem complexidade média **O(n log n)** e se comporta muito melhor do que o Bubble Sort, que é **O(n²)**, especialmente para grandes listas.

---

### **12. Qual dos algoritmos é considerado não estável?**  
**Alternativa correta:** **D. Selection Sort**

**Explicação breve:**  
Um algoritmo **estável** mantém a ordem relativa de elementos iguais. O **Selection Sort** pode quebrar essa ordem, logo, **não é estável**.

---

### **13. Por que o Merge Sort tem complexidade de espaço O(n)?**  
**Alternativa correta:** **C. Ele cria subarrays temporários em cada etapa de intercalação.**

**Explicação breve:**  
Durante o “merge”, o algoritmo precisa de arrays auxiliares do mesmo tamanho que a entrada. Por isso, gasta **espaço extra proporcional a n**.

---

### **14. Qual o estado do array após a 1ª iteração do Insertion Sort com `[7, 3, 5, 1, 2]`?**  
**Alternativa correta:** **A. `[3, 7, 5, 1, 2]`**

**Explicação breve:**  
Na 1ª iteração, o 3 é inserido antes do 7. O resto ainda não foi ordenado.

---

### **15. Qual algoritmo tem desempenho linear (O(n)) no melhor caso, quando a lista já está ordenada?**  
**Alternativa correta:** **A. Bubble Sort com otimização**

**Explicação breve:**  
Com otimização (verificação de trocas), o Bubble Sort **termina após a primeira passada** se não houver trocas — **melhor caso O(n)**.

---

### **16. Vantagem do Insertion Sort sobre o Selection Sort**

**Resposta:**  
O **Insertion Sort é mais eficiente em listas quase ordenadas** e possui melhor caso O(n), enquanto o Selection Sort é sempre O(n²). Além disso, o Insertion Sort **é estável**.

**Explicação breve:**  
Em situações reais com dados quase organizados, o Insertion Sort é mais **rápido** e **conserva a ordem** de elementos iguais.

---
