/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#include <math.h>
#include <assert.h>
#include "coordonnees.h"


double Coordonnees::distance(const Coordonnees& coor) const {
  double s1 = x-coor.x;
  double s2 = y-coor.y;
  return sqrt( s1*s1 + s2*s2 );
}

std::istream& operator >> (std::istream& is, Coordonnees& coor) {
  char po, virgule, pf;
  is >> po;
  if(is){
    is >> coor.x >> virgule >> coor.y >> pf;
    assert(po=='(');
    assert(virgule==',');
    assert(pf==')');
  }
  return is;
}

std::ostream& operator << (std::ostream& os, const Coordonnees& coor) {
  os << "(" << coor.x << "," << coor.y << ")";
  return os;
}

