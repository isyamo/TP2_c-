#include "Filiere.hpp"
#include "Etudiant.hpp"

Filiere::Filiere(std::string nom) : nomFiliere(nom), etudiantInscrit(nullptr) {}

Filiere::~Filiere() {

	if (etudiantInscrit != nullptr) {
	        delete etudiantInscrit;
	        etudiantInscrit = nullptr; // Éviter les pointeurs pendants
	    }
}

void Filiere::inscrireEtudiant(Etudiant* e) {
    if (etudiantInscrit != nullptr) {
        std::cerr << "Filière déjà occupée." << std::endl;
        return;
    }
    etudiantInscrit = e;
    e->setFiliere(this); // Mise à jour réciproque
}

Etudiant* Filiere::getEtudiantInscrit() const { return etudiantInscrit; }

std::string Filiere::getNomFiliere() const {
    return nomFiliere;
}
void Filiere::afficherInfo() const {
    std::cout << "Filière : " << nomFiliere << std::endl;
    if (etudiantInscrit) {
        std::cout << "Étudiant inscrit : " << etudiantInscrit->getNom() << std::endl;
    } else {
        std::cout << "Aucun étudiant inscrit." << std::endl;
    }
}
