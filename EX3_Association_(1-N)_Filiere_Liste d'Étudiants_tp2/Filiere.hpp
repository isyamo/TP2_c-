#ifndef FILIERE_EX3_HPP
#define FILIERE_EX3_HPP

#include <string>
#include <iostream>
#include <vector>

class Etudiant; // Déclaration anticipée

class Filiere {
private:
    std::string nomFiliere;
    std::vector<Etudiant*> etudiants; // Association 1-N (plusieurs étudiants)

public:
    Filiere(std::string nom);
    ~Filiere();

    void inscrireEtudiant(Etudiant* e);
    void retirerEtudiant(Etudiant* e);
    int getNombreEtudiants() const;
    std::string getNomFiliere() const;
    void afficherTous() const;
};

#endif
