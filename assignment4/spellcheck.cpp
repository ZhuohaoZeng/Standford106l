#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  std::vector<std::string::iterator> Iterators = find_all(source.begin(), source.end(), [](char charc) {return std::isspace(static_cast<int>(charc));} );
  Corpus Tokens;
  auto outputInserter = std::inserter(Tokens, Tokens.end());
  std::transform(Iterators.begin(), --Iterators.end(), ++Iterators.begin(), outputInserter, 
    [&source](std::string::iterator iter1, std::string::iterator iter2){return Token(source, iter1, iter2);});
  std::erase_if(Tokens, [](const Token& token){return token.content.empty();});
  return Tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  std::set<Misspelling> misspellings;
  namespace rv = std::ranges::views;
  auto v = source | rv::filter([&dictionary](const Token& t){return !dictionary.contains(t.content);})
                  | rv::transform([&dictionary](const Token& token){
                    auto sug = dictionary | rv::filter([&token](const std::string& tFromDic){
                      return levenshtein(token.content, tFromDic) == 1;
                    });//Working at it 
                    std::set<std::string> suggestions(sug.begin(), sug.end());
                    return Misspelling { token, suggestions };
                  })
                  | rv::filter([&dictionary](const Misspelling& m){return !m.suggestions.empty();});
                  
  return std::set<Misspelling>(v.begin(), v.end());
};

/* Helper methods */

#include "utils.cpp"