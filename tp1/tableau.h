/* Squelette pour classe générique Tableau<T>.
 * Lab3 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/lab3/
 */

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>

template <class T>
class Tableau{

  public:
    Tableau(int capacite_initiale=4);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // Redimensionner le tableau
    void           redimensionner(int nouvelle_capacite);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;

    // Insère element à position index. Les éléments à partir de index sont décalés d'une position.
    void           inserer(const T& element, int index=0);

    // Enlève l'element à position index. Les éléments après index sont décalés d'une position.
    void           enlever(int index=0);

    // Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    int            chercher(const T& element);

    const T&       operator[] (int index) const;
    T&             operator[] (int index);

    bool           operator == (const Tableau<T>& autre) const;
    Tableau<T>&    operator = (const Tableau<T>& autre);

  private:
    T*             elements;
    int            capacite;
    int            nbElements;
};


// ---------- Définitions -------------


template <class T>
Tableau<T>::Tableau(int capacite_initiale)
    : elements(new T[capacite_initiale]), capacite(capacite_initiale), nbElements(0)
{
}

template <class T>
Tableau<T>::Tableau(const Tableau& autre)
    : capacite(autre.capacite), nbElements(autre.nbElements)
{
    elements = new T[capacite];
    for(int i = 0; i < nbElements; i++) {
      elements[i] = autre.elements[i];
    }
}

template <class T>
Tableau<T>::~Tableau()
{
  delete[] elements;
}

template <class T>
int Tableau<T>::taille() const
{
    return nbElements;
}

template <class T>
void Tableau<T>::ajouter(const T& item)
{
    if (nbElements >= capacite) {
      redimensionner(capacite * 2);
    }
    elements[nbElements++] = item;
}

template <class T>
void Tableau<T>::redimensionner(int nouvelle_capacite) {
  T* temp = new T[nouvelle_capacite];
  for(int i = 0; i < nbElements; i++) {
    temp[i] = elements[i];
  }
  delete[] elements;
  elements = temp;
  capacite = nouvelle_capacite;
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
    assert(nbElements <= capacite);
    if (index >= nbElements) {
      redimensionner(capacite * 2);
    }
    for (int i = nbElements; i > index; i--) {
      elements[i] = elements[i - 1];
    }
    elements[index] = element;
    nbElements++;
}

template <class T>
void Tableau<T>::enlever(int index)
{
    assert(index <= nbElements);
    for (int i = index; i < nbElements; i++) {
      elements[i] = elements[i + 1];
    }
    nbElements--;
}

template <class T>
int Tableau<T>::chercher(const T& element)
{
    // Voir la fonction Tableau<T>::contient() dans les notes de cours (Section 4.7).
    // Il suffit de l'adapter pour retourner la position au lieu d'un booléen.
    for (int i = 0; i < nbElements; i++) {
      if (elements[i] == element) {
        return i;
      }
    }
    return -1;
}

template <class T>
void Tableau<T>::vider()
{
    nbElements = 0;
    delete[] elements;
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    assert(index >= 0 && index < nbElements);
    return elements[index];
}

template <class T>
T& Tableau<T>::operator[] (int index)
{
    assert(index >= 0 && index < nbElements);
    return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    if (this != &autre) {
      delete[] elements;
      capacite = autre.capacite;
      nbElements = autre.nbElements;
      elements = new T[capacite];
      for(int i = 0; i < nbElements; i++) {
        elements[i] = autre.elements[i];
      }
    }
    return *this;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    if (capacite != autre.capacite || nbElements != autre.nbElements) {
      return false;
    }
    for (int i = 0; i < nbElements; i++) {
      if (elements[i] != autre.elements[i]) {
        return false;
      }
    }
    return true;
}

#endif //define _TABLEAU___H_
