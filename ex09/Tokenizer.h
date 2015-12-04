#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer {
 public:
  Tokenizer(const std::string &filename, const std::string & sep);
  const std::vector<std::string> & getTokens();
  
 private:
  std::vector<std::string> tokens;
};

#endif // TOKENIZER_H
