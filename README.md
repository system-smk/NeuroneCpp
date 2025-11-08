

### Neurone C++ simple avec poids, biais et activation

Ce projet montre comment simuler une couche neuronale en C++ avec :

- Une matrice de poids
- Un vecteur d’entrée
- Un vecteur de biais
- Deux fonctions d’activation : ReLU et Sigmoid

---

### Fonctionnement

Chaque neurone calcule :

```
sortie = somme(poids × entrée) + biais
```

Puis applique une fonction d’activation.

---

### Définitions pédagogiques

#### Biais

Le biais est une valeur ajoutée à la sortie linéaire d’un neurone.  
Il permet au neurone de s’activer même si les entrées sont faibles ou nulles.  
Sans biais, certains neurones peuvent rester bloqués à zéro.

#### ReLU (Rectified Linear Unit)

Formule :  
```
ReLU(x) = max(0, x)
```

Utilité :  
- Activation simple et rapide  
- Conserve les valeurs positives  
- Bloque les négatives à zéro  
- Utilisée dans les couches cachées

#### Sigmoid

Formule :  
```
Sigmoid(x) = 1 / (1 + exp(-x))
```

Utilité :  
- Compresse les valeurs entre 0 et 1  
- Interprétable comme une probabilité  
- Utilisée en sortie pour les classifications binaires

---

### Exemple de sortie

```
Sorties brutes (linéaires + biais) :
1.5
3

Sorties après ReLU :
1.5
3

Sorties après Sigmoid :
0.817575
0.952574
```

---

Apres :
- Ajouter une fonction d’erreur (ex : MSE)
- Tester avec d’autres entrées ou poids
- Étendre vers une rétropropagation artisanale
