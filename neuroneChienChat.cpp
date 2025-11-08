#include <iostream>
#include <vector>
#include <cmath>

// Fonction d'activation sigmoïde
float sigmoide(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}

// Dérivée de la sigmoïde (utile pour l'apprentissage)
float derivee_sigmoide(float x) {
    float s = sigmoide(x);
    return s * (1 - s);
}

int main() {
    // Poids initiaux du neurone (3 caractéristiques)
    std::vector<float> poids = {0.1, 0.2, 0.3};

    // Biais initial
    float biais = 0.1;

    // Exemples d'apprentissage : [poil long, aboie, grimpe]
    std::vector<std::vector<float>> exemples = {
        {1.0, 0.0, 1.0},  // Chat
        {0.0, 1.0, 0.0}   // Chien
    };

    // Cibles associées : 0 = chat, 1 = chien
    std::vector<float> cibles = {0.0, 1.0};

    // Paramètres d'apprentissage
    int nombre_iterations = 1000;
    float taux_apprentissage = 0.1;
    float seuil_erreur = 0.001;

    // Boucle d'apprentissage
    for (int tour = 0; tour < nombre_iterations; tour++) {
        float erreur_totale = 0.0;

        for (int e = 0; e < exemples.size(); e++) {
            std::vector<float> entree = exemples[e];
            float cible = cibles[e];

            // Étape 1 : propagation avant
            float sortie_brute = 0.0;
            for (int i = 0; i < 3; i++) {
                sortie_brute += poids[i] * entree[i];
            }
            sortie_brute += biais;

            // Étape 2 : activation
            float sortie = sigmoide(sortie_brute);

            // Étape 3 : calcul de l'erreur
            float erreur = sortie - cible;
            erreur_totale += erreur * erreur;

            // Étape 4 : rétropropagation
            float gradient = erreur * derivee_sigmoide(sortie_brute);

            for (int i = 0; i < 3; i++) {
                poids[i] -= taux_apprentissage * gradient * entree[i];
            }
            biais -= taux_apprentissage * gradient;
        }

        // Affichage de l'erreur à chaque tour
        std::cout << "Tour " << tour << " - Erreur totale : " << erreur_totale << std::endl;

        if (erreur_totale < seuil_erreur) {
            std::cout << "Apprentissage terminé au tour " << tour << std::endl;
            break;
        }
    }

    // Test final
    std::cout << "\n--- Test après apprentissage ---" << std::endl;
    for (int e = 0; e < exemples.size(); e++) {
        float sortie_brute = 0.0;
        for (int i = 0; i < 3; i++) {
            sortie_brute += poids[i] * exemples[e][i];
        }
        sortie_brute += biais;
        float sortie = sigmoide(sortie_brute);
        std::cout << "Exemple " << e << " - Sortie : " << sortie << " (Cible : " << cibles[e] << ")" << std::endl;
    }

    // Affichage des poids finaux
    std::cout << "\n--- Poids appris ---" << std::endl;
    std::cout << "Poil long : " << poids[0] << std::endl;
    std::cout << "Aboie     : " << poids[1] << std::endl;
    std::cout << "Grimpe    : " << poids[2] << std::endl;
    std::cout << "Biais     : " << biais << std::endl;

    std::cout << "\n--- Test interactif ---" << std::endl;
    float poil_long, aboie, grimpe;

    std::cout << "Poil long (0 ou 1) : ";
    std::cin >> poil_long;
    std::cout << "Aboie (0 ou 1) : ";
    std::cin >> aboie;
    std::cout << "Grimpe (0 ou 1) : ";
    std::cin >> grimpe;

    float sortie_brute = poids[0]*poil_long + poids[1]*aboie + poids[2]*grimpe + biais;
    float sortie = sigmoide(sortie_brute);

    std::cout << "Sortie du neurone : " << sortie << std::endl;

    if (sortie < 0.3)
        std::cout << "→ Probablement un chat" << std::endl;
    else if (sortie > 0.7)
        std::cout << "→ Probablement un chien" << std::endl;
    else
        std::cout << "→ Ni clairement un chat, ni clairement un chien" << std::endl;


    return 0;
}

