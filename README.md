# ProjectoExame-Algoritmos-2021
## Editor de texto

1. Objectivo
   -   Este programa tem por objectivo aprofundar os conhecimentos no desenvolvimento de software com o tipo abstrato de dados, e na consolidação dos seguintes temas:
       -   Cadeias de caracteres
       -   Listas duplamente ligadas
2. Problema
   - Desenvolva um programa para implementar um pequeno editor de texto, baseado em linha de comando. 
   - Por definição, um editor de texto é um programa que processa texto, linha por linha. Suponhamos que cada linha tenha exatamente 80 caracteres. 
   - Cada comando de edição começa com o caracter cifrão (e nenhuma outra linha começa com esse caracter).
   - Este editor possui 8 comandos:
     - $inserir
       - Permite inserir uma porção de texto depois da linha corrente;
       - A linha é indicada pelo caracter "->". 
     - $remover m,n
       - Cada linha no texto, entre as linhas m e n, inclusive, devem ser removidas;
       - Se a linha corrente estiver neste intervalo, a nova linha corrente deve ser a linha m-1 (pode ser a linha zero).
     - $linha m
       - A linha m deve tornar-se a linha corrente.
     - $localizar %x
       - Localizar no texto, todas ocorrências da cadeia de caracteres x.

