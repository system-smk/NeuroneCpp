
## Objectif du programme

Ce programme simule un **neurone artificiel** capable d’apprendre à distinguer un **chat** d’un **chien** à partir de trois caractéristiques :

- Poil long
- Aboie
- Grimpe

Il utilise un **apprentissage supervisé** : on lui donne des exemples avec une **entrée** (caractéristiques) et une **cible** (chat = 0, chien = 1), et il ajuste ses **poids** pour mieux répondre.

---

## Concepts fondamentaux du neurone

### 🔹 1. Activation sigmoïde

```cpp
float sigmoide(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}
```

- Fonction mathématique qui transforme une valeur brute en **probabilité entre 0 et 1**
- Elle permet au neurone de dire : “je pense que c’est un chien à 80%”
- Elle est **lisse** et **dérivable**, donc idéale pour l’apprentissage

 **Analogie** : comme un variateur de lumière, elle transforme une tension brute en intensité douce.

---

### 🔹 2. Dérivée de la sigmoïde

```cpp
float derivee_sigmoide(float x) {
    float s = sigmoide(x);
    return s * (1 - s);
}
```

- Permet de savoir **à quel point la sortie change** quand on modifie les poids
- Utilisée pour **calculer le gradient** lors de la correction

**Analogie** : comme la pente d’une colline, elle indique dans quelle direction descendre pour corriger.

---

### 🔹 3. Biais initial

```cpp
float biais = 0.1;
```

- Valeur ajoutée à la somme pondérée des entrées
- Permet au neurone de **s’activer même si toutes les entrées sont nulles**
- C’est comme un **seuil de déclenchement**

**Analogie** : comme un thermostat qui démarre le chauffage à partir de 18°C.

---

## Paramètres d’apprentissage

```cpp
int nombre_iterations = 1000;
float taux_apprentissage = 0.1;
float seuil_erreur = 0.001;
```

| Paramètre             | Rôle pédagogique                                      |
|-----------------------|--------------------------------------------------------|
| `nombre_iterations`   | Nombre de tours d’apprentissage (maximum)             |
| `taux_apprentissage`  | Vitesse de correction des poids                       |
| `seuil_erreur`        | Niveau d’erreur acceptable pour arrêter l’apprentissage |

**Analogie** : comme un élève qui répète un exercice jusqu’à ce que l’erreur soit très faible.

---

## La boucle d’apprentissage

```cpp
for (int tour = 0; tour < nombre_iterations; tour++) {
    ...
}
```

Elle fait :

1. **Propagation avant** : calcule la sortie du neurone
2. **Activation** : transforme la sortie brute en probabilité
3. **Calcul de l’erreur** : compare avec la cible
4. **Rétropropagation** : ajuste les poids et le biais
5. **Affichage** : montre l’évolution de l’erreur

🔧 **Analogie** : comme un artisan qui ajuste son outil à chaque essai pour mieux sculpter.

---

## Résultat final

À la fin, le neurone a appris à :

- Répondre “chat” si les caractéristiques correspondent
- Répondre “chien” si elles sont typiques d’un chien
- Répondre “ni l’un ni l’autre” si c’est ambigu


---

Souhaites-tu que je t’aide à transformer ce README en fiche imprimable, ou à l’intégrer dans ton projet comme documentation ?  
Tu es en train de bâtir une pédagogie technique claire, vivante et transmissible 💡
