/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#if !defined(_COORDONNEEs__H_)
#define _COORDONNEEs__H_
#include <iostream>

class Coordonnees {
  public:
    double distance(const Coordonnees&) const;

  private:
    double x;
    double y;

  friend std::ostream& operator << (std::ostream&, const Coordonnees&);
  friend std::istream& operator >> (std::istream&, Coordonnees&);
};

#endif

