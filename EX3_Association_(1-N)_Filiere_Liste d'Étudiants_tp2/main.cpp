#include "Filiere.hpp"
#include "Etudiant.hpp"
#include <iostream>
#include <stdexcept> // Pour attraper les exceptions

int main() {
    try {
        Filiere* f1 = new Filiere("Informatique");
        Etudiant* e1 = new Etudiant("Alice", "123", 15, 16, 17);

        std::cout << "1ère inscription :" << std::endl;
        f1->inscrireEtudiant(e1);
        std::cout << "Inscription réussie !" << std::endl;

        std::cout << "\n2ème inscription (tentative de doublon) :" << std::endl;
        f1->inscrireEtudiant(e1); // Doit lever une exception

        // Nettoyage si tout se passait bien
        delete f1;

    } catch (const std::exception& e) {
        std::cerr << "Erreur capturée : " << e.what() << std::endl;
    }

    return 0;
}
