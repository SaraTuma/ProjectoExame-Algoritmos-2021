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
   - Este editor possui os segintes comandos:
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
     - $alterar % x % y %
       - Na linha corrente, cada ocorrência da cadeia x deve ser substituida pela cadeia y.
     - $ultimo
       - Deve imprimir o número da última linha do texto
     - $imprimir m,n
       - Devem ser impresas todas as linhas do texto, e o número de linhas, das linhas m até n, inclusive n.
       - Deve ser emitido um erro se :
         - For omitido um número ou a virgula no comando ;
         - n for menor que m ;
         - m for menor que 1 ou n maior que o último número de linha do texto.
       - $fim
         - Termina a execução do editor de texto;
         - Uma mensagem de erro deve ser impressa para qualquer comando incorrecto, como sendo $end, $insere, etc.
  3. Novos comandos
     1. $prnenv
         -  Serve para imprimir a lista em ordem decrescente;
         -  Recebe dois parametros (números) separados por uma virgula;
         -  O primeiro identifica a linha por onde começar;
         -  O segundo, quantas linhas a cima devem ser impresas.
        <code>
        $prnenv 4,2
        
        </code>

