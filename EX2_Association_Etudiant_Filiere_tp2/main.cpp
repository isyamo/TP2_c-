#include "Etudiant.hpp"
#include "Filiere.hpp"
#include <iostream>


int main() {
    // Création de la filière
    Filiere* f1 = new Filiere("Informatique");

    // Création de l'étudiant
    Etudiant* e1 = new Etudiant("Alice", "123", 15, 16, 17);

    // Association
    f1->inscrireEtudiant(e1);

    // Affichage
    f1->afficherInfo();

    // Vérification depuis l'étudiant
    if (e1->getFiliere() != nullptr) {
        std::cout << "Étudiant " << e1->getNom() << " est dans la filière : "
                  << e1->getFiliere()->getNomFiliere() << std::endl;
    }

    // Nettoyage
    delete f1; // Supprime aussi e1 si Filiere possède e1
    // delete e1; // NE PAS FAIRE si f1 a déjà supprimé e1

    return 0;
}
