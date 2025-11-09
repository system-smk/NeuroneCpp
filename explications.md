


# 🧠 neuroneChienChat.cpp — README pédagogique

Ce programme simule un neurone artificiel capable d’apprendre à distinguer un **chat** d’un **chien** à partir de trois caractéristiques :

- Poil long
- Aboie
- Grimpe

Il utilise un apprentissage supervisé : on lui donne des exemples avec une entrée et une cible, et il ajuste ses poids pour mieux répondre.

---

## 🧱 Structure du neurone

### 1. Entrées

```cpp
std::vector<float> entree = {1.0, 0.0, 1.0}; // exemple : poil long, n’aboie pas, grimpe
```

Chaque valeur représente une caractéristique encodée en 0 ou 1.

---

### 2. Poids

```cpp
std::vector<float> poids = {0.1, 0.2, 0.3}; // 1 poids par entrée
```

Chaque poids indique l’importance de l’entrée correspondante.

---

### 3. Biais

```cpp
float biais = 0.1;
```

Valeur ajoutée à la fin du calcul, comme un seuil ou une intuition du neurone.

---

### 4. Sortie brute (somme pondérée)

```cpp
float sortie_brute = 0.0;
for (int i = 0; i < entree.size(); i++) {
    sortie_brute += poids[i] * entree[i];
}
sortie_brute += biais;
```

Le neurone additionne les entrées pondérées + le biais.

---

### 5. Activation (sigmoïde)

```cpp
float sortie = 1.0f / (1.0f + std::exp(-sortie_brute));
```

Transforme la sortie brute en probabilité entre 0 et 1.

---

### 6. Cible

```cpp
float cible = 0.0; // exemple : chat
```

La bonne réponse attendue.

---

### 7. Erreur

```cpp
float erreur = sortie - cible;
```

Différence entre la sortie du neurone et la cible.

---

### 8. Dérivée de la sigmoïde

```cpp
float derivee = sortie * (1 - sortie);
```

Sensibilité de la sortie par rapport à la sortie brute.

---

### 9. Gradient

```cpp
float gradient = erreur * derivee;
```

Quantité de correction à appliquer.

---

### 10. Taux d’apprentissage

```cpp
float taux_apprentissage = 0.1;
```

Contrôle la vitesse de correction.

---

### 11. Mise à jour des poids

```cpp
for (int i = 0; i < poids.size(); i++) {
    poids[i] -= taux_apprentissage * gradient * entree[i];
}
```

Chaque poids est ajusté selon l’erreur et l’entrée.

---

### 12. Mise à jour du biais

```cpp
biais -= taux_apprentissage * gradient;
```

Le biais est corrigé comme les poids.

---

## 🔁 Boucle d’apprentissage

Le neurone répète ces étapes pour chaque exemple, pendant plusieurs tours :

```cpp
int nombre_iterations = 1000;
float seuil_erreur = 0.001;
```

Il s’arrête quand l’erreur devient très faible.

---

## 🧪 Test interactif (optionnel)

Tu peux ajouter une entrée manuelle pour tester :

```cpp
std::cin >> poil_long >> aboie >> grimpe;
```

Et afficher :

```cpp
std::cout << "Sortie : " << sortie << std::endl;
```

---

## 🧩 Résumé

| Élément              | Rôle dans le neurone                        |
|----------------------|---------------------------------------------|
| Entrées              | Données encodées (0 ou 1)                   |
| Poids                | Importance de chaque entrée                 |
| Biais                | Décalage global                             |
| Sortie brute         | Somme pondérée + biais                      |
| Activation           | Transformation en probabilité               |
| Cible                | Réponse attendue                            |
| Erreur               | Écart entre sortie et cible                 |
| Dérivée              | Sensibilité de la sortie                    |
| Gradient             | Correction à appliquer                      |
| Taux d’apprentissage | Vitesse de correction                       |
| Mise à jour poids    | Ajustement de chaque poids                  |
| Mise à jour biais    | Ajustement du seuil                         |

---

Ce README est conçu pour aider à comprendre.

