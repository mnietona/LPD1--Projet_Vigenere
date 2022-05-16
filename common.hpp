/**
 * @author Nieto Navarrete Matias
 * matricue : 502920
 */
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using std::string;
using namespace std;

const int LEN_ALPHABET = 26;
const char ASCII_A = 'A';
const char ASCII_E = 'E';
const double FREQUENCE_E = 0.17115;

struct Clef{
    char* clef;
    std::size_t longueur; 
    float erreur ;
};
