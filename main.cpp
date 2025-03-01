#include <iostream>
#include <fstream>
#include <string>

#define N 999

using namespace std;

ifstream fin("salon.in");
ofstream fout("salon.out");

int key, nrOre, ora;
string clienti[N];
int n;

void choices(int ore[]) {
    do {
        cout << "\nSelecteaza optiune: ";
        cin >> key;

        switch (key) {
            case 1:
                cout << "Ora programarii: ";
                cin >> ora;
                if (ora < 1 || ora > nrOre) {
                    cout << "Ora invalida!\n";
                    break;
                }
                if (ore[ora - 1] == 1) {
                    cout << "Ora " << ora << " este deja rezervata!\n";
                    break;
                }
                cin.ignore();
                cout << "Numele pentru rezervare: ";
                getline(cin, clienti[ora - 1]);
                ore[ora - 1] = 1;
                cout << "Rezervare realizata cu succes!\n";
                break;

            case 2:
                cout << "Ora programarii: ";
                cin >> ora;
                if (ora < 1 || ora > nrOre || ore[ora - 1] == 0) {
                    cout << "Ora " << ora << " nu este ocupata!\n";
                    break;
                }
                ore[ora - 1] = 0;
                clienti[ora - 1] = "";
                cout << "Rezervare stearsa cu succes!\n";
                break;

            case 3:
                cout << "Lista programari:\n";
                for (int i = 0; i < nrOre; i++) {
                    if (ore[i] == 0)
                        cout << "Ora " << i + 1 << " este libera.\n";
                    else
                        cout << "Ora " << i + 1 << " este rezervata de " << clienti[i] << ".\n";
                }
                break;

            case 4:
                cout << "Ora programarii de modificat: ";
                cin >> ora;
                if (ora < 1 || ora > nrOre || ore[ora - 1] == 0) {
                    cout << "Nu exista programare la ora " << ora << "!\n";
                    break;
                }
                cin.ignore();
                cout << "Noul nume pentru rezervare: ";
                getline(cin, clienti[ora - 1]);
                cout << "Rezervare modificata cu succes!\n";
                break;

            case 5:
                cout << "Ora programarii: ";
                cin >> ora;
                if (ora < 1 || ora > nrOre) {
                    cout << "Ora invalida!\n";
                    break;
                }
                if (ore[ora - 1] == 0)
                    cout << "Ora " << ora << " este libera.\n";
                else
                    cout << "Ora " << ora << " este rezervata de " << clienti[ora - 1] << ".\n";
                break;

            case 6:
                {
                    int total = 0;
                    for (int i = 0; i < nrOre; i++)
                        if (ore[i] == 1)
                            total++;
                    cout << "Numar total de programari: " << total << "\n";
                }
                break;

            case 7:
                {
                    string nume;
                    cin.ignore();
                    cout << "Introdu numele clientului: ";
                    getline(cin, nume);
                    bool gasit = false;
                    for (int i = 0; i < nrOre; i++) {
                        if (clienti[i] == nume) {
                            cout << "Clientul " << nume << " are programare la ora " << i + 1 << ".\n";
                            gasit = true;
                        }
                    }
                    if (!gasit)
                        cout << "Clientul " << nume << " nu are programari.\n";
                }
                break;

            case 8:
                cout << "Lista clientilor cu programari:\n";
                for (int i = 0; i < nrOre; i++) {
                    if (ore[i] == 1)
                        cout << clienti[i] << "\n";
                }
                break;

            case 9:
                cout << "Ore libere:\n";
                for (int i = 0; i < nrOre; i++) {
                    if (ore[i] == 0)
                        cout << "Ora " << i + 1 << " este libera.\n";
                }
                break;

            case 10:
                {
                    int start, sfarsit;
                    cout << "Introdu intervalul (start sfarsit): ";
                    cin >> start >> sfarsit;
                    if (start < 1 || sfarsit > nrOre || start > sfarsit) {
                        cout << "Interval invalid!\n";
                        break;
                    }
                    bool liber = true;
                    for (int i = start - 1; i < sfarsit; i++) {
                        if (ore[i] == 1) {
                            cout << "Ora " << i + 1 << " este ocupata.\n";
                            liber = false;
                        }
                    }
                    if (liber)
                        cout << "Intervalul este complet disponibil.\n";
                }
                break;

            case 0:
                return;

            default:
                cout << "Tasta invalida!\n";
        }
    } while (key != 0);
}

int main() {
    cout << "Introduceti nr. de ore: ";
    cin >> nrOre;
    int ore[nrOre] = {0};

    cout << "\nSalon Management:\n";
    cout << "1. Adauga programare\n2. Sterge programare\n3. Afiseaza programari\n";
    cout << "4. Modifica programare\n5. Verifica ora\n6. Numar total programari\n";
    cout << "7. Cauta client\n8. Lista clienti\n9. Ore libere\n10. Interval disponibil\n";
    cout << "0. Iesire\n";

    choices(ore);
    return 0;
}

