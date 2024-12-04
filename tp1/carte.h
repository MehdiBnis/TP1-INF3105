/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#if !defined(__CARTE_)
#define __CARTE_

#include <string>
#include "coordonnees.h"
#include "tableau.h"

class Mission {
  public:
    void ajouter_site(const Coordonnees& site);
    int nombre_sites() const;
    const Coordonnees& retourner_site(int index) const;

  private:
    Tableau<Coordonnees> _vSite;
};

class Carte {
  public:
    void ajouter_mission(const Mission& mission);
    int nombre_missions() const;
    const Mission& retourner_mission(int index) const;

    Tableau<unsigned int> topOrder(const Coordonnees& depart) const;
    void parcourir_sites(int index_mission, Coordonnees position, int dist, int& mindist, Tableau<unsigned int>& ordre_sites, Tableau<unsigned int>& result) const;
  
  private:
    Tableau<Mission> _vMission;
    
  friend std::istream& operator >> (std::istream&, Carte&);
};

#endif

