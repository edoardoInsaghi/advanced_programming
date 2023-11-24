#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Book {
public:
  std::string title;
  std::string author;
  std::string genre;
  unsigned int publication_year;
};

void print(std::vector<Book> &books) {
  for (Book &book : books) {
    std::cout << "  Title: " << book.title << " | Author: " << book.author
              << " | Genre: " << book.genre
              << " | Year: " << book.publication_year << std::endl;
  }
}

bool sort_by_asc_year(const Book &b1, const Book &b2){

  return b1.publication_year < b2.publication_year;
}

class CompareByName{

  bool operator()(const Book &b1, const Book &b2){return b1.author < b2.author;}
};

int main() {
  // Define a list of books.
  std::vector<Book> books = {
      {"Go set a watchman", "Harper Lee", "Fiction", 2015},
      {"Animal farm", "George Orwell", "Satire", 1945},
      {"To kill a mockingbird", "Harper Lee", "Fiction", 1960},
      {"1984", "George Orwell", "Science fiction", 1949},
      {"Pride and prejudice", "Jane Austen", "Romance", 1813},
      {"Sense and sensibility", "Jane Austen", "Romance", 1811}};

  std::cout << "Original list of books: \n" << std::endl;
  print(books);

  // Sort in ascending order by year.
  std::sort(books.begin(), books.end(), sort_by_asc_year);
  std::cout << "Ordered by ascending year: \n" << std::endl;
  print(books);

  // Sort in ascending order by author name.
  std::sort(books.begin(), books.end(), CompareByName{});
  std::cout << "Ordered by ascending author name: \n" << std::endl;
  print(books);

  return 0;
}