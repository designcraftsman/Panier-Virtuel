#include "Article.h"


Article::Article(std::string ref, double prx, int qte) : reference(ref), prix(prx), quantite_stock(qte) {}

bool Article::operator==(const Article& a) const {
    return reference == a.reference;
}