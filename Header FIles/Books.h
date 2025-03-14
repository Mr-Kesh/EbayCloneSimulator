#ifndef BOOKS_H_
#define BOOKS_H_



#include "Product.h"



class Books : public Product {
public:
  Books(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& author, const std::string& genre)
    : Product(productId, name, "Books", base_price, quality, seller), author_(author), genre_(genre) {}

  std::string getAuthor() const { return author_; }
  std::string getGenre() const { return genre_; }
  void displayProductInfo() const override;

private:
  std::string author_;
  std::string genre_;
};



class Fiction : public Books {
public:
  Fiction(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& author)
  : Books(productId, name, base_price, quality, seller, author, "Fiction") {}
};



class Novel : public Fiction {
public:
  Novel(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& author)
  : Fiction(productId, name, base_price, quality, seller, author) {}
};



class NonFiction : public Books {
public:
  NonFiction(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& author)
  : Books(productId, name, base_price, quality, seller, author, "Non-Fiction") {}
};



class Textbook : public NonFiction {
public:
  Textbook(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& author)
  : NonFiction(productId, name, base_price, quality, seller, author) {}
};



class Comic : public Books {
public:
  Comic(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& author)
  : Books(productId, name, base_price, quality, seller, author, "Comic") {}
};



class GraphicNovel : public Comic {
public:
  GraphicNovel(const int productId, const std::string& name, const double base_price, const Quality quality, Seller* seller, const std::string& author)
  : Comic(productId, name, base_price, quality, seller, author) {}
};

#endif // BOOKS_H_