#ifndef FILIERE_HPP
#define FILIERE_HPP

#include <iostream>
#include <string>

class Etudiant;

class Filiere {
private:
    std::string nomFiliere;
    Etudiant* etudiantInscrit;

public:
    Filiere(std::string nom);

    ~Filiere(); // Destructeur pour libérer la mémoire si nécessaire

    void inscrireEtudiant(Etudiant* e);

    Etudiant* getEtudiantInscrit() const;
    std::string getNomFiliere() const ;

    void afficherInfo() const;
};



#endif
