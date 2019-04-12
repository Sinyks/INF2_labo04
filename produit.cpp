#include "produit.h"
#include "exceptions.h"
#include <iomanip>
#include <sstream>

using namespace std;

const double Produit::PRIX_MINIMAL = 0.05;

string Produit::prixNonValide(const char* nomFonction){
   stringstream os;

   os << "Erreur dans Produit::" << nomFonction << " : " << endl << "le prix doit etre >= " << PRIX_MINIMAL*100.0 << " cts !";

   return os.str(); 
}

Produit::Produit(unsigned no, const string& libelle, double prix) : no(no) {
   if (prix < PRIX_MINIMAL) {
      throw PrixNonValide(prixNonValide(__func__));
   }
   //(unsigned&) this->no = no;
   (string&) this->libelle = libelle;
   this->prix = prix;
}

Produit& Produit::operator=(const Produit& produit) {
   (unsigned&) this->no = produit.no;
   (string&) this->libelle = produit.libelle;
   this->prix = produit.prix;
   return *this;
}

void Produit::setPrix(double prix) {
   if (prix < PRIX_MINIMAL) {
      throw PrixNonValide(prixNonValide(__func__));
   }
   this->prix = prix;
}

double Produit::getPrix() const {
   return prix;
}

ostream& operator<<(ostream& os, const Produit& produit) {
   return os << '(' << produit.no << ", \"" << produit.libelle << "\", "
             << fixed << setprecision(2) << produit.prix << defaultfloat
             << setprecision(6) << ')';
}

// A voir si on compare uniquement par numero ou plus
bool operator==(const Produit& lhs, const Produit& rhs) {
   return lhs.no == rhs.no;
}