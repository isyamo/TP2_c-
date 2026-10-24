#include "Etudiant.hpp"
#include <iostream>

int main() {
    // Création d'un étudiant avec le constructeur par défaut

    Etudiant e1;
    e1.setNom("Alice Dupont");
    e1.setCin("123456789012345");
    e1.setNote1(15.5);
    e1.setNote2(12.0);
    e1.setNote3(18.5);

    std::cout << "Étudiant 1 : " << e1.getNom() << std::endl;
    std::cout << "Moyenne : " << e1.calculerMoyenne() << std::endl;

    // Test de validation

    std::cout << "\nTest de validation :" << std::endl;
    e1.setNote1(25.0); //  affiche une erreur
    std::cout << "Note1 après tentative d'erreur : " << e1.getNote1() << std::endl;

    // Création d'un deuxième étudiant avec le constructeur paramétré

    Etudiant e2("Bob Martin", "987654321098765", 10.0, 14.0, 16.0);
    std::cout << "\nÉtudiant 2 : " << e2.getNom() << std::endl;
    std::cout << "Moyenne : " << e2.calculerMoyenne() << std::endl;

    return 0;
}
