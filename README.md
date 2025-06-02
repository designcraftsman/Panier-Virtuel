# Panier Virtuel

This project is a virtual shopping cart application implemented in C++. It allows users to manage articles, modify quantities, calculate totals, and perform various operations on a shopping cart.

## Features

- **Add Articles**: Add articles to the shopping cart with a specified quantity.
- **Modify Quantities**: Update the quantity of an article in the cart.
- **Remove Articles**: Remove specific articles from the cart.
- **Clear Cart**: Empty the shopping cart completely.
- **Display Articles**: View all articles in the cart, sorted by price.
- **Calculate Total**: Compute the total cost of items in the cart, with discounts for bulk purchases.
- **Find Most Expensive Article**: Identify the article with the highest price.
- **Filter Articles by Price Range**: Display articles within a specified price range.
- **Retrieve Article Information**: Get details of an article by its reference.

## Technologies Used

- **C++**: Core programming language.
- **Standard Template Library (STL)**: Used for containers like `std::vector` and algorithms like `std::sort`.

## Project Structure

```
Panier-Virtuel/
├── panier virtuel.sln
├── .vs/
│   ├── panier virtuel/
│   │   ├── FileContentIndex/
│   │   ├── v17/
│   │   └── ...
├── panier virtuel/
│   ├── Article.cpp
│   ├── Client.cpp
│   ├── Commande.cpp
│   ├── panier virtuel.cpp
│   ├── panier virtuel.vcxproj
│   ├── panier virtuel.vcxproj.filters
│   ├── panier virtuel.vcxproj.user
│   └── x64/
│       └── Debug/
│           ├── panier virtuel.exe
│           ├── panier virtuel.pdb
│           └── ...
└── x64/
    └── Debug/
        ├── panier virtuel.exe
        ├── panier virtuel.pdb
        └── ...
```

## How to Build and Run

1. Open the solution file `panier virtuel.sln` in Visual Studio.
2. Build the project using the `Debug` or `Release` configuration.
3. Run the executable located in `x64/Debug/panier virtuel.exe`.

## Key Classes and Methods

### `Panier`
- `ajouter_article(Article& article, int quantite)`: Add an article to the cart.
- `modifier_quantite(Article& article, int nouvelle_quantite)`: Update the quantity of an article.
- `enlever_article(Article& article)`: Remove an article from the cart.
- `vider_panier()`: Clear all articles from the cart.
- `afficher_articles()`: Display all articles, sorted by price.
- `montant_total()`: Calculate the total cost of items in the cart.
- `article_plus_cher()`: Find the most expensive article.
- `articles_prix_compris(double min, double max)`: Filter articles by price range.
- `informations_article(std::string reference)`: Retrieve details of an article by its reference.

## Example Usage

```cpp
Panier panier;
Article article1("A001", 50.0, 20);
Article article2("A002", 30.0, 15);

panier.ajouter_article(article1, 5);
panier.ajouter_article(article2, 10);

panier.afficher_articles();
std::cout << "Total: " << panier.montant_total() << std::endl;
```
