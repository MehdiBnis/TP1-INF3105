/* Squelette de départ TP1
 * TP1 - Mission lunaire
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/tp1/
 */

#include "carte.h"
#include <cmath>
#include <istream>
#include <limits>
#include <string> 
#include <sstream>

void Mission::ajouter_site(const Coordonnees& site) {
  _vSite.ajouter(site);
}

int Mission::nombre_sites() const {
  return _vSite.taille();
}

const Coordonnees& Mission::retourner_site(int index) const {
  assert(index >= 0 && index < _vSite.taille());
  return _vSite[index];
}

void Carte::ajouter_mission(const Mission& mission) {
  _vMission.ajouter(mission);
}

int Carte::nombre_missions() const {
  return _vMission.taille();
}

const Mission& Carte::retourner_mission(int index) const {
  assert(index >= 0 && index < _vMission.taille());
  return _vMission[index];
}

Tableau<unsigned int> Carte::topOrder(const Coordonnees& depart) const
{
  int dist = 0, mindist = 100000000, index_mission = 0;  // initialisation des valeurs, mindist initié à une très grande valeur pour simuler l'infini
  Tableau<unsigned int> result;  // result: ordre final des sites à visiter
  Tableau<unsigned int> ordre_sites;  // ordre_sites: parcourt toutes les combinaisons possibles

  parcourir_sites(index_mission, depart, dist, mindist, ordre_sites, result);

  return result;
}

void Carte::parcourir_sites(int index_mission, Coordonnees position, int dist, int& mindist, Tableau<unsigned int>& ordre_sites, Tableau<unsigned int>& result) const {

  // Vérifier si nous avons parcouru toutes les missions
  if (index_mission == _vMission.taille()) {
    // Mettre à jour si la distance calculée est plus petite que le dernier plus petit résultat
    if (dist < mindist) {
      mindist = dist;
      result = ordre_sites;
    }
    return;
  }

  // Parcourir la mission actuelle
  const Mission& mission = _vMission[index_mission];

  // Parcourir les sites de la mission actuelle
  for (int i = 0; i < mission.nombre_sites(); i++) {
    Coordonnees site = mission.retourner_site(i);
    double dist_vers_site = position.distance(site);

    // Ajouter un site dans la liste provisoire
    ordre_sites.ajouter(i + 1);

    // Passer à la mission suivante
    parcourir_sites(index_mission + 1, site, dist + dist_vers_site, mindist, ordre_sites, result);

    // Enlever le dernier site utilisé de la liste provisoire
    ordre_sites.enlever(ordre_sites.taille() - 1);
  }
}


std::istream& operator >> (std::istream& is, Mission& mission)
{

    std::string name;
    is >> name;

    int nb;
    is >> nb;

    for (int i = 0; i < nb; i++) {
      Coordonnees site;
      is >> site;
      mission.ajouter_site(site);
    }
    
    return is;
}

std::istream& operator >> (std::istream& is, Carte& carte)
{
    int n;
    is >> n;
    if(!is || !(n > 0)) { // détecter une anomalie
        assert(false);
        return is;
    }

    for(int i=0; i<n; i++) {
        Mission mission;
        is >> mission;
        carte.ajouter_mission(mission);
    }

    return is;
}

