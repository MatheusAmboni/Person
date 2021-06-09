#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct personPF
{
    string 
    nome,
    nomeMae,
    cpf,
    endereco,
    telefone;
};

struct personPJ
{
    string 
    razaoSocial, 
    cnpj,
    endereco, 
    telefone,
    capitalSocial;
};

//funcao load
bool LoadDatabase(string path, 
vector < personPF > &listPF, 
vector < personPJ > &listPJ);

//funcao save
bool SaveDatabase(string path, 
const vector<personPF> &listPF, 
const vector<personPJ> &listPJ);

#endif