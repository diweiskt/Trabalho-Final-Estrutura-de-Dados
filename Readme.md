### Integrantes do grupo: Diwei V. Nicolay (193014) | Rafael Pizarro (207749)


# Simulador de Fila de Triagem Hospitalar

Este projeto acadêmico, desenvolvido em C++, demonstra a implementação de um sistema de fila de prioridade utilizando múltiplas filas FIFO (std::queue).  
O simulador gerencia um fluxo de pacientes em uma triagem hospitalar, tratando eventos de chegada e atendimento. A lógica de prioridade é implementada verificando sequencialmente quatro filas distintas (Emergência, Urgência, Pouco Urgente e Não Urgente). O programa também calcula e exibe estatísticas em tempo real e em um relatório final, como o tempo máximo de espera e o pico de lotação do sistema.


## Tecnologias Utilizadas

**Linguagem:** C++  
**Extensão:** Live Share(para editar código simultaneamente)  
**Controle de Versão:** Git  
**Hospedagem de Código:** GitHub


## Funcionalidades

O simulador processa 4 comandos principais:

**`C` (Chegada):** Adiciona um novo paciente a uma das quatro filas de prioridade.  
**`A` (Atendimento):** Atende o paciente com a maior prioridade disponível no momento.  
**`D` (Diagnóstico):** Exibe um relatório instantâneo da lotação de cada fila.  
**`Q` (Sair):** Encerra a simulação e exibe um relatório final completo, incluindo:  
* Total de pacientes atendidos.
* Detalhamento de atendidos por prioridade.
* Pico de lotação (maior número de pacientes em espera).
* Tempo máximo de espera em minutos.