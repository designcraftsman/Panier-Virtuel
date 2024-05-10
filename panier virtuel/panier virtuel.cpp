#include <iostream>
#include <vector>
#include <algorithm>

class Article {
public:
    std::string reference;
    double prix;
    int quantite_stock;

    Article(std::string ref, double prx, int qte) : reference(ref), prix(prx), quantite_stock(qte) {}

    bool operator==(const Article& a) const {
        return reference == a.reference;
    }
};

class Panier {
public:
    std::vector<std::pair<Article, int>> articles;

    void ajouter_article(Article& article, int quantite) {
        if (article.quantite_stock >= quantite) {
            articles.push_back(std::make_pair(article, quantite));
            article.quantite_stock -= quantite;
        }
        else {
            std::cout << "Quantité en stock insuffisante.\n";
        }
    }

    void modifier_quantite(Article& article, int nouvelle_quantite) {
        for (auto& a : articles) {
            if (a.first == article) {
                if (nouvelle_quantite <= a.first.quantite_stock + a.second) {
                    a.first.quantite_stock += a.second - nouvelle_quantite;
                    a.second = nouvelle_quantite;
                }
                else {
                    std::cout << "Quantité en stock insuffisante.\n";
                }
                break;
            }
        }
    }

    void enlever_article(Article& article) {
        articles.erase(std::remove_if(articles.begin(), articles.end(),
            [&article](const auto& a) { return a.first == article; }),
            articles.end());
    }


    void vider_panier() {
        articles.clear();
    }

    void afficher_articles() {
        std::sort(articles.begin(), articles.end(),
            [](const auto& a, const auto& b) { return a.first.prix < b.first.prix; });
        for (const auto& a : articles) {
            std::cout << "Référence: " << a.first.reference << ", Prix: " << a.first.prix << ", Quantité commandée: " << a.second << "\n";
        }
    }


    double montant_total() {
        double total = 0;
        for (const auto& a : articles) {
            total += a.first.prix * a.second;
            if (a.second > 10) {
                total *= 0.8;
            }
        }
        return total;
    }

    Article article_plus_cher() {
        return std::max_element(articles.begin(), articles.end(),
            [](const auto& a, const auto& b) { return a.first.prix < b.first.prix; })
            ->first;
    }


    void articles_prix_compris(double min, double max) {
        for (const auto& a : articles) {
            if (a.first.prix >= min && a.first.prix <= max) {
                std::cout << "Référence: " << a.first.reference << ", Prix: " << a.first.prix << ", Quantité commandée: " << a.second << "\n";
            }
        }
    }

    Article informations_article(std::string reference) {
        for (const auto& a : articles) {
            if (a.first.reference == reference) {
                return a.first;
            }
        }
        return Article("", 0, 0);
    }
};

class Client {
public:
    std::string email;
    std::string nom;
    Panier panier;

    Client(std::string eml, std::string nm) : email(eml), nom(nm) {}
};

class Commande {
public:
    int numero;
    std::string etat;
    Client client;
    Panier panier;

    Commande(int num, Client& clt) : numero(num), etat("en attente de traitement"), client(clt), panier(clt.panier) {}

    void mise_a_jour_etat(std::string nouvel_etat) {
        etat = nouvel_etat;
    }
};


void afficher_menu() {
    std::cout << "===== Menu =====" << std::endl;
    std::cout << "1. Afficher le panier" << std::endl;
    std::cout << "2. Ajouter un article au panier" << std::endl;
    std::cout << "3. Modifier la quantité d'un article dans le panier" << std::endl;
    std::cout << "4. Supprimer un article du panier" << std::endl;
    std::cout << "5. Vider le panier" << std::endl;
    std::cout << "6. Afficher le montant total du panier" << std::endl;
    std::cout << "7. Passer une commande" << std::endl;
    std::cout << "8. Quitter" << std::endl;
    std::cout << "================" << std::endl;
}

void ajouter_article_au_panier(Client& client) {
    std::string reference;
    double prix;
    int quantite_stock;

    std::cout << "Entrez la référence de l'article : ";
    std::cin >> reference;
    std::cout << "Entrez le prix de l'article : ";
    std::cin >> prix;
    std::cout << "Entrez la quantité en stock de l'article : ";
    std::cin >> quantite_stock;

    Article nouvel_article(reference, prix, quantite_stock);
    int quantite;
    std::cout << "Entrez la quantité à ajouter au panier : ";
    std::cin >> quantite;

    client.panier.ajouter_article(nouvel_article, quantite);
}

void modifier_quantite_article_dans_panier(Client& client) {
    std::string reference;
    std::cout << "Entrez la référence de l'article à modifier : ";
    std::cin >> reference;

    Article article = client.panier.informations_article(reference);
    if (article.reference.empty()) {
        std::cout << "Article non trouvé dans le panier." << std::endl;
        return;
    }

    int nouvelle_quantite;
    std::cout << "Entrez la nouvelle quantité pour cet article : ";
    std::cin >> nouvelle_quantite;

    client.panier.modifier_quantite(article, nouvelle_quantite);
}

void supprimer_article_du_panier(Client& client) {
    std::string reference;
    std::cout << "Entrez la référence de l'article à supprimer : ";
    std::cin >> reference;

    Article article = client.panier.informations_article(reference);
    if (article.reference.empty()) {
        std::cout << "Article non trouvé dans le panier." << std::endl;
        return;
    }

    client.panier.enlever_article(article);
}

void passer_commande(Client& client) {
    // Ici vous pouvez ajouter le code pour passer une commande, 
    // par exemple en créant une nouvelle instance de Commande avec le panier du client
}

int main() {
    // Création d'un client
    Client client("client@example.com", "Jean Dupont");

    int choix;
    do {
        afficher_menu();
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;

        switch (choix) {
        case 1:
            std::cout << "===== Panier de " << client.nom << " =====" << std::endl;
            client.panier.afficher_articles();
            std::cout << "===========================" << std::endl;
            break;
        case 2:
            ajouter_article_au_panier(client);
            break;
        case 3:
            modifier_quantite_article_dans_panier(client);
            break;
        case 4:
            supprimer_article_du_panier(client);
            break;
        case 5:
            client.panier.vider_panier();
            std::cout << "Le panier a été vidé." << std::endl;
            break;
        case 6:
            std::cout << "Montant total du panier : " << client.panier.montant_total() << " EUR" << std::endl;
            break;
        case 7:
            passer_commande(client);
            break;
        case 8:
            std::cout << "Merci et au revoir !" << std::endl;
            break;
        default:
            std::cout << "Choix invalide. Veuillez entrer un numéro de choix valide." << std::endl;
            break;
        }
    } while (choix != 8);

    return 0;
}
