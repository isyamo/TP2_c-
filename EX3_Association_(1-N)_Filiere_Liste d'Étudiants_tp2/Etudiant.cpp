#include "Etudiant.hpp"
#include "Filiere.hpp"


Etudiant::Etudiant() : nom("Inconnu"), cin("000000000000000"), note1(0), note2(0), note3(0) {}

Etudiant::Etudiant(std::string n, std::string c, double n1, double n2, double n3)
    : nom(n), cin(c), note1(n1), note2(n2), note3(n3) {}

std::string Etudiant::getNom() const { return nom; }
std::string Etudiant::getCin() const { return cin; }
double Etudiant::getNote1() const { return note1; }
double Etudiant::getNote2() const { return note2; }
double Etudiant::getNote3() const { return note3; }
Filiere* Etudiant::getFiliere() const {
    return filiere;
}
void Etudiant::setNom(std::string n) { nom = n; }
void Etudiant::setCin(std::string c) { cin = c; }

// Validation des notes
void Etudiant::setNote1(double n) {
    if (n >= 0 && n <= 20) note1 = n;
    else std::cout << "Note invalide : " << n << std::endl;
}

void Etudiant::setNote2(double n) {
    if (n >= 0 && n <= 20) note2 = n;
    else std::cout << "Note invalide : " << n << std::endl;
}

void Etudiant::setNote3(double n) {
    if (n >= 0 && n <= 20) note3 = n;
    else std::cout << "Note invalide : " << n << std::endl;
}

void Etudiant::setFiliere(Filiere* f){
	filiere = f;
}

double Etudiant::calculerMoyenne() const {
    return (note1 + note2 + note3) / 3.0;
}

void Etudiant::changerDeFiliere(Filiere* nouvelleFiliere) {
    if (nouvelleFiliere == nullptr) {
        std::cerr << "Nouvelle filière invalide." << std::endl;
        return;
    }

    // 1. Se retirer de l'ancienne filière
    if (filiere != nullptr) {
        filiere->retirerEtudiant(this);
    }

    // 2. S'inscrire dans la nouvelle filière
    nouvelleFiliere->inscrireEtudiant(this);

    // 3. Mettre à jour le pointeur
    filiere = nouvelleFiliere;

    std::cout << nom << " a changé de filière." << std::endl;
}
