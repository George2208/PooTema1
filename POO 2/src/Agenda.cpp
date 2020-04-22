#include "Agenda.h"
#include "Erori.h"

Agenda::Agenda(){}

Agenda::Agenda(Agenda &x){
    Lista=x.Lista;}

Agenda::Agenda(Abonat &x){
    Lista.push_back(x);}

istream &operator>> (istream &is, Agenda &x){
    Abonat y;
    is>>y;
    x.add(y);
    return is;}

ostream &operator<< (ostream &os, Agenda &x){
    for(unsigned int i=0; i<x.Lista.size(); i++)
        os<<x.Lista[i];
    return os;}

const Agenda& Agenda::operator= (const Agenda &x){
    Lista=x.Lista;
    return (*this);}

void Agenda::add(Abonat &x){
    Lista.push_back(x);}

Abonat Agenda::operator[] (string x){
    /*for(unsigned int i=0; i<Lista.size(); i++){
        if(Lista[i].getnume()==x){
            return Lista[i];}}
    Abonat nothing;
    return nothing;*/
    unsigned int i=0;
    try{
        while(true){
            if(i>=Lista.size())
                throw Erori();
            if(Lista[i].getnume()==x)
                return Lista[i];
            i++;}}
    catch(Erori e){
        cerr<<e.what();}
    Abonat nothing;
    return nothing;}

Agenda::~Agenda(){
    while(Lista.size())
        Lista.pop_back();
    /*cout<<"\n  ~Agenda";*/}
