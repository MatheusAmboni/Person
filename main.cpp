#include "person.hpp"
#define DEBUG 0

int main() 
{
    vector < personPF > listPF;
    vector < personPJ > listPJ;

     if(LoadDatabase("database.dat", listPF, listPJ) == false)
     {
        if(DEBUG) cout << "File database.dat not found, creating a new one" << 
        endl;
     }
    for (;;)
    {
       //save
        SaveDatabase("database.dat", listPF, listPJ);
        
        if(DEBUG) cout << "MY PAPA'S COMPANY - SIG" << endl;
        if(DEBUG) cout << "1. Add PF" << endl;
        if(DEBUG) cout << "2. Add PJ..." << endl;
        if(DEBUG) cout << "3. Remove PF Index..." << endl;
        if(DEBUG) cout << "4. Remove PJ Index..." << endl;
        if(DEBUG) cout << "5. Print Names in Ascending Order" << endl;
        if(DEBUG) cout << "6. Exit" << endl;
        if(DEBUG) cout << "Enter an option:";

        char ch;
        cin >> ch;

        cin.ignore();

        if (ch == '1')
        {
            personPF p;
            getline(cin, p.nome);
            getline(cin, p.nomeMae);
            getline(cin, p.cpf);
            getline(cin, p.endereco);
            getline(cin, p.telefone);

            listPF.push_back(p);

            continue;
        }

        if (ch == '2')
        {
            personPJ p;
            getline(cin, p.razaoSocial);
            getline(cin, p.cnpj);
            getline(cin, p.endereco);
            getline(cin, p.telefone);
            getline(cin, p.capitalSocial);

            listPJ.push_back(p);

        }

        if (ch == '3')
        {
            if(DEBUG) cout << "Digite um indice de PF para ser excluido: " << endl;
            if(DEBUG) cout << listPF.size() << endl;
            int index;
            cin >> index;

            if (index < 0 || index >= listPF.size())
            {
                if(DEBUG) cout << "O indice indicado e invalido" << endl;
            }
            else if (index < listPF.size())
            {
                listPF.erase(listPF.begin() + index);
            }
            continue;
        }

        if (ch == '4')
        {
            if(DEBUG) cout << "Digite um indice de PJ para ser excluido: " << endl;
            if(DEBUG) cout << listPJ.size() << endl;
            int index;
            cin >> index;

            if (index < 0 || index >= listPJ.size())
            {
                if(DEBUG) cout << "O indice indicado e invalido" << endl;
            }
            else if (index < listPJ.size())
            {
                listPJ.erase(listPJ.begin() + index);
            }
            continue;
        }

        if (ch == '5')
        {
            vector<string> tmp;
            for (size_t i = 0; i < listPF.size(); i++)
            {
               tmp.push_back (listPF.at(i).nome);
            }
            for (size_t i = 0; i < listPJ.size(); i++)
            {
               tmp.push_back (listPJ.at(i).razaoSocial);
            }
            sort(tmp.begin(), tmp.end());
            cout << "Names in Ascending Order:" << endl;
            for (size_t i = 0; i < tmp.size(); i++)
            {
               cout << tmp[i] << endl;
            }
            continue;
        }

        if (ch == '6')
        {
            break;
        }

    }


    return 0;
}