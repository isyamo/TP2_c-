#include "Filiere.hpp"
#include "Etudiant.hpp"
#include <algorithm> // Nécessaire pour std::find
#include <iostream>

Filiere::Filiere(std::string nom) : nomFiliere(nom) {}

Filiere::~Filiere() {
    // Libérer la mémoire de tous les étudiants si la filière les possède
    for (auto* e : etudiants) {
        delete e;
    }
    etudiants.clear();
}

void Filiere::inscrireEtudiant(Etudiant* e) {
    if (e == nullptr) {
        throw std::invalid_argument("Étudiant nul");
    }

    // Vérifier si l'étudiant est déjà inscrit
    for (const auto* et : etudiants) {
        if (et == e) {
            throw std::runtime_error("Étudiant déjà inscrit dans cette filière");
        }
    }

    // Vérifier si l'étudiant est déjà dans une autre filière
    if (e->getFiliere() != nullptr) {
        throw std::runtime_error("Étudiant déjà inscrit dans une autre filière");
    }

    etudiants.push_back(e);
    e->setFiliere(this);
}
void Filiere::retirerEtudiant(Etudiant* e) {
    auto it = std::find(etudiants.begin(), etudiants.end(), e);
    if (it != etudiants.end()) {
        (*it)->setFiliere(nullptr); // Délier l'étudiant
        etudiants.erase(it);
    }
}

int Filiere::getNombreEtudiants() const {
    return etudiants.size();
}

std::string Filiere::getNomFiliere() const {
    return nomFiliere;
}

void Filiere::afficherTous() const {
    std::cout << "Étudiants de la filière " << nomFiliere << " :" << std::endl;
    if (etudiants.empty()) {
        std::cout << "  (Aucun étudiant)" << std::endl;
    } else {
        for (const auto* e : etudiants) {
            std::cout << "  - " << e->getNom() << " (Moyenne: " << e->calculerMoyenne() << ")" << std::endl;
        }
    }
}
