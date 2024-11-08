#include <iostream>

using namespace std;
const int SIZE = 10;
const int GARE_SIZE = 5;

struct atleta {
    int id = -1;
    string name;
    string cognome;
    int punteggio = 0;
};

struct gara {
    int id;
    string name;
    atleta arrivo[SIZE];
};



int checkFull(atleta atleta[], int SIZE);
void addAtleta(atleta atleta[], int i);
void showAll(atleta atleta[], int SIZE);
void inizializeGare(gara gara[]);
void showGare(gara gara[]);
void setArrivi(gara gara[], int indice, atleta atleta[], int quantiIscritti);
bool isInArray(int array[], int littleSize, int value);
void stampaClassificaSingolaGara(gara gara[], int quantita);
void stampaClassifica(atleta atleta[], int quantita);


int main() {
    bool flagMenu = true;
    char scelta = ' ';
    int indice = -1;
    int quantiIscritti = 0;
    atleta atleta[SIZE];
    gara gare[GARE_SIZE];

    inizializeGare(gare);

    do {
        cout << "Cosa vuoi fare:\n-[1] Iscrivere un nuovo atleta\n"
                "-[2] Stampa Atleti\n"
                "-[3] Modifica Gara\n"
                "-[4] Stampa Classifica\n"
                "-[5] Esci" << endl;

        cin >> scelta;
        switch (tolower(scelta)) {
            case '1':
                indice = checkFull(atleta, SIZE);
                if (indice != -1) {
                    addAtleta(atleta, indice);
                    quantiIscritti++;
                }

                else
                    cout << "Le iscrizioni sono finite!" << endl;

                break;

            case '2':

                if (quantiIscritti == 0)
                    cout << "Non hai inserito nessun iscritto!" << endl;
                else
                    showAll(atleta, SIZE);
                break;
            case '3':
                if (quantiIscritti == 0)
                    cout << "Non hai inserito nessun iscritto! Non puoi modificare le gare" << endl;
                else {
                    showGare(gare);
                    cout << "Inserisci ID per scegliere la gara!" << endl;
                    cin >> indice;

                    if (indice <= 0 || indice > GARE_SIZE) {
                        cout << "Indice Errato" << endl;
                    } else
                        setArrivi(gare, indice-1, atleta, quantiIscritti);
                }
                break;
            case '4':
                stampaClassificaSingolaGara(gare, quantiIscritti);
                stampaClassifica(atleta, quantiIscritti);
                break;

            default:
                flagMenu = false;
                cout << "Sto uscendo..." << endl;
        }
    }while (flagMenu);

    return 0;
}

int checkFull(atleta atleta[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        if (atleta[i].id == -1)
            return i;
    }
    return -1;
}

void addAtleta(atleta atleta[], int i) {
    cout << "Stai inserendo l'atleta, iscritto numero " << i + 1 << endl;
    cout << "Inserisci Nome: "; cin >> atleta[i].name;
    cout << "Inserisci Cognome: "; cin >> atleta[i].cognome;
    atleta[i].id = i;
}

void showAll(atleta atleta[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        if (atleta[i].id != -1) {
            cout << "- - - Id: " << atleta[i].id + 1 << " - - -" << endl;
            cout << "Nome: " << atleta[i].name << endl;
            cout << "Cognome: " << atleta[i].cognome << endl;
            cout << "Punteggio: " << atleta[i].punteggio << endl;
            cout << "- - - - - - - - - - -" << endl;
        }
    }
}

void inizializeGare(gara gara[]) {
    for (int i = 0; i < GARE_SIZE; i++) {
        gara[i].id = i;
        cout <<  "Inserisci nome gara n. " << (i) +1 << endl;
        getline(cin, gara[i].name);
    }
}

void showGare(gara gara[]) {
    for (int i = 0; i < GARE_SIZE; i++) {
        if (gara[i].id != -1) {
            cout << "- - - Id: " << gara[i].id + 1 << " - - -" << endl;
            cout << "Nome Gara: " << gara[i].name << endl;
        }
    }
}

void setArrivi(gara gara[], int indice, atleta atleta[], int quantiIscritti) {
    showAll(atleta, SIZE);
    int giaInseriti[quantiIscritti];
    bool flag = true;
    int pettorina = -1;

    for (int i = 0; i < quantiIscritti; i++) {
        giaInseriti[i] = -1;
    }

    for (int i = 0; i < quantiIscritti; i++) {
        do {
            cout << "Inserisci la pettorina arrivata in posizione numero: " << (i) + 1 << endl;
            cin >> pettorina;
            if (pettorina > quantiIscritti || pettorina <= 0 || isInArray(giaInseriti, quantiIscritti, pettorina)) {
                cout << "Inserimento non valido, ripeti" << endl;
                flag = true;
            } else {
                giaInseriti[i] = pettorina;
                flag = false;

                switch (i) {
                    case 0:
                        atleta[pettorina-1].punteggio += 100;
                        break;
                    case 1:
                        atleta[pettorina-1].punteggio += 70;
                        break;
                    case 2:
                        atleta[pettorina-1].punteggio += 60;
                        break;
                    case 3:
                        atleta[pettorina-1].punteggio += 50;
                        break;
                    case 4:
                        atleta[pettorina-1].punteggio += 40;
                        break;
                    case 5:
                        atleta[pettorina-1].punteggio += 30;
                        break;
                    case 6:
                        atleta[pettorina-1].punteggio += 20;
                        break;
                    case 7:
                        atleta[pettorina-1].punteggio += 10;
                        break;
                    case 8:
                        atleta[pettorina-1].punteggio += 5;
                        break;
                    case 9:
                        atleta[pettorina-1].punteggio += 1;
                        break;
                    default: cout << "Errore" << endl;
                }

                gara[indice].arrivo[i] = atleta[pettorina-1];
            }
        } while (flag);
    }

    cout << "Salvato punteggio con successo";
}

bool isInArray(int array[], int littleSize, int value) {
    for (int i = 0; i < littleSize; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

void stampaClassificaSingolaGara(gara gara[], int quantita) {
    for (int i = 0; i < GARE_SIZE; i++) {
        cout << "\t- -\t Gara: " << gara[i].name << "- -" << endl;
        cout << "POS\t" << "\tNOME\t " << endl;
        for (int j = 0; j < quantita; j++) {
            //cout << atleta[i].punteggio << " ";
            cout << "[" << j +1 << "]\t" << "\t" << gara[i].arrivo[j].name << "\t" << endl;
        }
    }
}

void stampaClassifica(atleta atleta[], int quantita) {

    for (int i = 0; i < quantita - 1; i++) {
        for (int j = 0; j < quantita - 1 - i; j++) {
            if (atleta[j].punteggio <= atleta[j + 1].punteggio) {
                std::swap(atleta[j], atleta[j + 1]);
            }
        }
    }

    cout << "Classifica:\n";
    cout << "Posizione\tNome\tPunteggio\n";
    for (int i = 0; i < quantita; i++) {
        cout << (i + 1) << "\t\t" << atleta[i].name << "\t" << atleta[i].punteggio << std::endl;
    }
}