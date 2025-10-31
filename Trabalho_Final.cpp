//Simulador de Fila de Triagem Hospitalar

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct paciente{
    string senha;
    char prioridade;
    int chegada;
};

int conversorminutos(int h, int m) {
    return h * 60 + m;
}

int main(){

    queue<paciente> Emergencia;
    queue<paciente> Urgencia;
    queue<paciente> PoucoUrgente;
    queue<paciente> NaoUrgente;
    int pico = 0;
    int tempoMaxEspera = 0;
    int totalAtendimentos = 0;
    int atendidosV = 0;
    int atendidosA = 0;
    int atendidosD = 0;
    int atendidosB = 0;

    string entrada;
    while(cin >> entrada){
        if(entrada == "C"){
            int h,m;
            paciente aux;
            cin >> aux.senha >> aux.prioridade >> h >> m;
            aux.chegada = conversorminutos(h,m);

            if(aux.prioridade == 'V'){ 
                Emergencia.push(aux);
            }
            else if(aux.prioridade == 'A'){
                Urgencia.push(aux);
            }
            else if(aux.prioridade == 'D'){
                PoucoUrgente.push(aux);
            }
            else{
                NaoUrgente.push(aux);
            }
            
            int total = Emergencia.size() + Urgencia.size() + PoucoUrgente.size() + NaoUrgente.size();
            pico = max(pico, total);
        }
        
        if(entrada == "A"){
            int h, m;
            cin >> h >> m;
            int horarioatual = conversorminutos(h, m);
            paciente atendido;
            bool temPaciente = false;

            if(!Emergencia.empty()){
                atendido = Emergencia.front();
                Emergencia.pop();
                temPaciente = true;
            }
            else if(!Urgencia.empty()){
                atendido = Urgencia.front();
                Urgencia.pop();
                temPaciente = true;
            }
            else if(!PoucoUrgente.empty()){
                atendido = PoucoUrgente.front();
                PoucoUrgente.pop();
                temPaciente = true;
            }
            else if(!NaoUrgente.empty()){
                atendido = NaoUrgente.front();
                NaoUrgente.pop();
                temPaciente = true;
            }

            if(!temPaciente){
                cout << h << " " << m << " Sem pacientes aguardando atendimento" << endl;
            }
            else{
                int espera = horarioatual - atendido.chegada;
                tempoMaxEspera = max(tempoMaxEspera, espera);
                totalAtendimentos++;
                if(atendido.prioridade == 'V'){
                    atendidosV++;
                }
                else if(atendido.prioridade == 'A'){
                    atendidosA++;
                }
                else if(atendido.prioridade == 'D'){
                    atendidosD++;
                }
                else{
                    atendidosB++;
                }
            }
        }
        
        if(entrada == "D"){
            cout << "Emergência: " << Emergencia.size() << " Urgência: " << Urgencia.size() << " Pouco Urgente: " << PoucoUrgente.size() << " Não Urgente: " << NaoUrgente.size() << " | Atendidos: " << totalAtendimentos << endl;

        }
        if(entrada == "Q"){
            cout << "---- RELATÓRIO FINAL ----\n"
                << "Total atendidos: " << totalAtendimentos << "\n"
                << "Por prioridade: Emergência: " << atendidosV << " "
                << "Urgência: " << atendidosA << " "
                << "Pouco Urgente: " << atendidosD << " "
                << "Não Urgente: " << atendidosB << "\n"
                << "Pico de lotação: " << pico << "\n"
                << "Espera máxima: " << tempoMaxEspera << " min" << endl;
            break;
        }
    }


    return 0;
}