# Scheduler FSO
Trabalho da disciplina Fundamentos de Sistemas Operacionais do semestre 2024.2

O tema escolhido foi:

>Scheduler de Processos que possa escolher SJF, Corrida, ou RR. (os processos devem ter os atributos necessários)

A implementação do _Scheduler_ foi inspirada na implementação presente em https://github.com/OmarAzizi/SKernel, adicionando a funcionalidade do _Scheduler_ utilizar uma forma diferente de escalonamento baseado em um parâmetro passado na chamada do escalonador. 

Para testar o código sem utilizar uma VM, foi feito uma simulação, onde os processos não são realmente executados e não possuem código, apenas os atributos necessários para serem escolhidos pelo _Scheduler_.