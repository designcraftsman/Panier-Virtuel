#include "Commande.h"


Commande::Commande(int num, Client& clt) : numero(num), client(clt), panier(clt.panier) {}