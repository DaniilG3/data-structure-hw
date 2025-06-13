#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>
#include <string>

class WordCount {
private:
    std::string word;
    int count;

public:
    WordCount(const std::string& w) : word(w), count(1) {}

    std::string getWord() const { return word; }
    int getCount() const { return count; }
    void addCount() { ++count; }

    bool operator>(const WordCount& other) const { return word > other.word; }
    bool operator<(const WordCount& other) const { return word < other.word; }
    bool operator==(const WordCount& other) const { return word == other.word; }
    bool operator!=(const WordCount& other) const { return word != other.word; }
    
};
#endif  // WORDCOUNT_H
