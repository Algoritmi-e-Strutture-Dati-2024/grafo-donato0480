#include <iostream>
#include "Grafo.cpp" 

int main() {
    // Creazione del grafo (con nodi rappresentanti pianeti)
    Grafo<std::string> grafo;

    // Aggiunta dei nodi (pianeti)
    grafo.aggiungiNodo("Terra");
    grafo.aggiungiNodo("Marte");
    grafo.aggiungiNodo("Giove");
    grafo.aggiungiNodo("Venere");
    grafo.aggiungiNodo("Saturno");

    // Aggiunta degli archi con i pesi (distanze tra i pianeti in milioni di km)
    grafo.aggiungiArco("Terra", "Venere", 42000000);  // Distanza media Terra-Venere
    grafo.aggiungiArco("Venere", "Marte", 41000000);  // Distanza media Venere-Mar, per esempio
    grafo.aggiungiArco("Marte", "Giove", 550000000); // Distanza Marte-Giove
    grafo.aggiungiArco("Giove", "Saturno", 120000000); // Distanza Giove-Saturno
    grafo.aggiungiArco("Saturno", "Terra", 1200000000); // Distanza Saturno-Terra

    // Visualizzazione del grafo (matrice di adiacenza)
    grafo.stampa();

    // Verifica se un nodo esiste
    std::cout << "\nEsiste il nodo 'Terra'? " << (grafo.verificaNodo("Terra") ? "Sì" : "No") << "\n";
    std::cout << "Esiste il nodo 'Plutone'? " << (grafo.verificaNodo("Plutone") ? "Sì" : "No") << "\n";

    // Verifica se esiste un arco tra due nodi
    std::cout << "\nEsiste un arco tra Terra e Venere? " << (grafo.verificaArco("Terra", "Venere") ? "Sì" : "No") << "\n";
    std::cout << "Esiste un arco tra Saturno e Giove? " << (grafo.verificaArco("Saturno", "Giove") ? "Sì" : "No") << "\n";

    // Verifica la connessione tra due nodi
    std::cout << "\nSono connessi Terra e Marte? " << (grafo.sonoConnessi("Terra", "Marte") ? "Sì" : "No") << "\n";
    std::cout << "Sono connessi Giove e Venere? " << (grafo.sonoConnessi("Giove", "Venere") ? "Sì" : "No") << "\n";

    // Trova l'arco con il peso minore da Terra
    grafo.arcoMinimo("Terra");

    // Nodi adiacenti a Terra
    grafo.nodiAdiacenti("Terra");

    // Rimozione di un nodo e dei suoi archi
    grafo.rimuoviNodo("Marte");
    std::cout << "\nDopo la rimozione di Marte:\n";
    grafo.stampa();

    // Rimozione di un arco specifico
    grafo.rimuoviArco("Terra", "Venere");
    std::cout << "\nDopo la rimozione dell'arco Terra-Venere:\n";
    grafo.stampa();

    // Aggiunta di un nuovo nodo e arco
    grafo.aggiungiNodo("Plutone");
    grafo.aggiungiArco("Plutone", "Saturno", 5500000000); // Distanza Plutone-Saturno (distanza ipotetica)
    std::cout << "\nDopo l'aggiunta di Plutone e l'arco Plutone-Saturno:\n";
    grafo.stampa();

    // Applicazione dell'algoritmo di Dijkstra (cammini minimi da Terra)
    grafo.dijkstra("Terra");

    return 0;
}
