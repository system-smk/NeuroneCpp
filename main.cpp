#include <iostream>
#include <vector>
#include <cmath>



float relu(float x ){
    return x > 0 ? x : 0;
}

float sigmoid(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}

int main(){
    // matrice de poid avec 2 neurones chacun avec 3 connexions 
    std::vector<std::vector<float>> longueur = {
        {0.1, 0.2, 0.3}, //Neurone 1
        {0.4, 0.5, 0.6}  //Neurone 2
    };
    std::vector<float> entree  ={1.0, 2.0 , 3.0};

    std::vector<float> sortie(2, 0.0);

    std::vector<float> biais = {0.1, -0.2};

    for (int i = 0; i < 2 ; i++){
        for (int j = 0; j < 3; j++){
            sortie[i] += longueur[i][j] * entree[j];
        }
        sortie[i] += biais[i];
    }

    std::cout << "Sorties brutes (linéaires + biais) :" << std::endl;
    for (float val : sortie) {
        std::cout << val << std::endl;
    }

    std::cout << "\nSorties apres ReLU :" << std::endl;
    for (float val : sortie){
        std::cout << relu(val) << std::endl;
        }

    std::cout << "\nSorties apres Sigmoid  :" << std::endl;
    for (float val : sortie){
        std::cout << sigmoid(val) << std::endl;
    }

    return 0;
}