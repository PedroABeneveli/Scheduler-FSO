# Scheduler FSO
Trabalho da disciplina Fundamentos de Sistemas Operacionais do semestre 2024.2

O tema escolhido foi:

>Scheduler de Processos que possa escolher SJF, Corrida, ou RR. (os processos devem ter os atributos necessários)

A implementação do _Scheduler_ foi inspirada na implementação presente em https://github.com/OmarAzizi/SKernel, adicionando a funcionalidade do _Scheduler_ utilizar uma forma diferente de escalonamento baseado em um parâmetro passado na chamada do escalonador. 

Para testar o código sem utilizar uma VM, foi feito uma simulação, onde os processos não são realmente executados e não possuem código, apenas os atributos necessários para serem escolhidos pelo _Scheduler_.

## Compilação

Para compilar, basta executar a linha de comando abaixo no terminal no diretório root do projeto:

```
make
```

Isso irá gerar o arquivo executável _scheduler_, que executa a simulação.

## Como utilizar

Com o arquivo executável, basta digitar no terminal:

```
./scheduler numero_de_processos tipo_de_escalonamento quantum
```

Onde:
- numero_de_processos: quantidade de processos que vão ser instanciados e colocados na fila circular.
- tipo_de_escalonamento: é o argumento que indica qual o tipo de escalonamento desejado nessa execução, em que:
    - 0: _First In First Out_ (FIFO)
    - 1: _Shortest Job First_ (SJF)
    - 2: _Round Robin_ (RR)
- quantum: obrigatório para a execução do _Round Robin_, não utilizado nos outros tipos de escalonamento.