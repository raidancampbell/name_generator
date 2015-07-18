#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include "name_generator.h"

#define LASTNAME_FILE "last_names.txt"
#define MFIRSTNAME_FILE "male_names.txt"
#define FFIRSTNAME_FILE "female_names.txt"
/* regardless of the number of names in the files,
 * in order to retain population fairness, choose a female
 * name with the below probability*/
#define PERCENT_FEMALE_POPULATION 0.508

using namespace std;

int main() {

    srand(time(NULL)); /* TODO: the seed should come from the input data to make this deterministic*/
    set<string> lastnames = split(read_text(LASTNAME_FILE));
    set<string> mfirstnames = split(read_text(MFIRSTNAME_FILE));
    set<string> ffirstnames = split(read_text(FFIRSTNAME_FILE));
    string firstname = is_female() ? get_random_element_from(ffirstnames) : get_random_element_from(mfirstnames);
    string lastname = get_random_element_from(lastnames);

    cout << firstname << " " << lastname << "\r\n";
    return EXIT_SUCCESS;
}

/*
 * read the text from a predetermined input file,
 * and return it as a string
 * */
string read_text(string filename){
    ifstream t(filename);
    stringstream buffer;
    buffer << t.rdbuf();
    string str = buffer.str();
    return str;
}

/* thanks, stackoverflow! */
set<string> split(string input) {
    set<string> return_var;
    stringstream ss(input);
    string s;
    while (getline(ss, s, '\n')) {
        return_var.insert(s);
    }
    return return_var;
}

/* can't be sexist now:
 * follow actual population distribution
 * Also, used is_female instead of is_male. Just to be different. */
bool is_female(){
    double rand_value = (double)rand() / RAND_MAX;
    if(rand_value > 1 || rand_value <= 0){
        cerr << "ERROR: creating random number between 0 and 1 yielded " << rand_value << "\r\n";
    }
    return rand_value < PERCENT_FEMALE_POPULATION;
}

/* self explainatory, but ugly */
string get_random_element_from(set<string> given_set){
    std::vector<string> output(given_set.begin(), given_set.end());
    unsigned long index = (unsigned long) ((double)rand() / (double)RAND_MAX)*given_set.size();
    cout << "retrieving element at index " << index << " from array of size "<< given_set.size() << "\r\n";
    return output.at(index);
}