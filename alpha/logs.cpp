#include "logs.h"

Logs::Logs(QList<Message>& logs):logs(logs)
{
    //this->logs = logs;
}

Message Logs::message(int i){
    return this->logs.at(i);
}

void Logs::sortByN(){

}

void Logs::sort(int i)
{
    switch (i) {
    case 6:
        sortById();
    }

}

bool Logs::srt(const Message & a, const Message & b){
    return a.id()<b.id();
}

void Logs::sortById(){
    std::sort(this->logs.begin(), this->logs.end(), srt);
}

int Logs::size(){
    return this->logs.size();
}

void Logs::sortByDate(){

}

Logs::~Logs()
{

}
