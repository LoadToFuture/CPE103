#include "hashtablechk.h"
#include <iostream>
#include <vector>
#include <algorithm> // for std::random_shuffle
#include <cstdlib>   // for std::rand and std::srand
using namespace std;
void waitForEnter()
{
    cout << endl;
    cout << "Please enter to continue...";
    cin.ignore();
    cin.get();
    cout << "\x1B[2J\x1B[H";
}
string randomword(const string &input_word)
{
    // List of possible words starting with each letter
    vector<vector<string>> words_by_letter = {
        {"Apple", "Apricot", "Avocado", "Acai", "Ackee", "Almond", "Amla", "Appleberry", "Apron", "Arracacha"},                                                          // A
        {"Banana", "Blackberry", "Blueberry", "Bilberry", "Boysenberry", "Breadfruit", "Barberry", "Bearberry", "Bergamot", "Bignay"},                                   // B
        {"Cherry", "Cantaloupe", "Cranberry", "Coconut", "Clementine", "Cloudberry", "Cucumber", "Currant", "Cherry-plum", "Crabapple"},                                 // C
        {"Date", "Durian", "Dragonfruit", "Damson", "Dewberry", "Duku", "Dasher", "Dabber", "Dais", "Dewlap"},                                                           // D
        {"Elderberry", "Eggfruit", "Elaeagnus", "Elephant-apple", "Emblica", "Endive", "Ensete", "Entawak", "Etaerio", "Exocarp"},                                       // E
        {"Fig", "Feijoa", "Fruit", "Foxberry", "Farkleberry", "False mastic", "Fingerlime", "Farkleberry", "Figwort", "Fupped"},                                         // F
        {"Grape", "Guava", "Grapefruit", "Gooseberry", "Ginkgo", "Goldenberry", "Genip", "Granadilla", "Grapple", "Garcinia"},                                           // G
        {"Honeydew", "Horned melon", "Hackberry", "Huckleberry", "Hog plum", "Huito", "Hawthorn", "Hala fruit", "Hala pepe", "Hemlock"},                                 // H
        {"Icaco", "Imbe", "Indian prune", "Indian fig", "Indian jujube", "Imbe", "Imbu", "Irga", "Isau", "Irpex"},                                                       // I
        {"Jackfruit", "Jambul", "Jujube", "Jostaberry", "Jaboticaba", "Japanese plum", "Japanese persimmon", "Japanese raisin tree", "Jelly melon", "Jerusalem cherry"}, // J
        {"Kiwi", "Kiwifruit", "Kumquat", "Kaffir lime", "Kakadu lime", "Kandis", "Kei apple", "Kiwano", "Kepel", "Kokum"},                                               // K
        {"Lemon", "Lime", "Lychee", "Longan", "Loquat", "Lingonberry", "Lilli pilli", "Lulo", "Luo han guo", "Lingonberry"},                                             // L
        {"Mango", "Melon", "Mulberry", "Mandarin orange", "Mamey sapote", "Mangosteen", "Miracle fruit", "Medlar", "Musk melon", "Monstera deliciosa"},                  // M
        {"Nance", "Nectarine", "Nance", "Naranjilla", "Neem fruit", "Nutmeg", "Nungu", "Nashi pear", "Nance", "Nere"},                                                   // N
        {"Orange", "Olive", "Olive", "Oliveberry", "Orangelo", "Oregon grape", "Otaheite gooseberry", "Ogeechee lime", "Ogeechee tupelo", "Osage orange"},               // O
        {"Papaya", "Pineapple", "Plum", "Peach", "Pear", "Persimmon", "Passionfruit", "Pawpaw", "Pepino", "Pomelo"},                                                     // P
        {"Quince", "Queen pineapple", "Quandong", "Queensland nut", "Queen Anne's pocket melon", "Quandong", "Quince", "Quartz melon", "Qazvin", "Quince apple"},        // Q
        {"Raspberry", "Rambutan", "Redcurrant", "Rose hip", "Rowan", "Rhubarb", "Rose apple", "Rose hip", "Rutabaga", "Raspberry"},                                      // R
        {"Strawberry", "Star fruit", "Sugar-apple", "Salak", "Satsuma", "Sharon fruit", "Soursop", "Sapodilla", "Sapote", "Salmonberry"},                                // S
        {"Tomato", "Tamarillo", "Tamarind", "Tangelo", "Tayberry", "Thimbleberry", "Tangerine", "Tigernut", "Tonka bean", "Tormentil"},                                  // T
        {"Uvaia", "Uvaia", "Ume", "Ugni", "Umbu", "Umbrella fruit", "Uchuva", "Uvaria", "Uvaria", "Umbu"},                                                               // U
        {"Vanilla", "Vanilla", "Velvet tamarind", "Velvet apple", "Velvet bean", "Viburnum", "Voavanga", "Voavanga", "Velvet bean", "Velvetleaf"},                       // V
        {"Watermelon", "Wax jambu", "White currant", "White sapote", "Wolfberry", "Wampee", "Waxberry", "Wax apple", "Wineberry", "Winged bean"},                        // W
        {"Xigua", "Xylocarp", "Xylosma", "Xylophone", "Ximenia", "Xylocarp", "Xylopia", "Xylooligosaccharide", "Xanthoceras", "Xylan"},                                  // X
        {"Yuzu", "Yumberry", "Yellow passionfruit", "Yamamomo", "Yew", "Yangmei", "Yew", "Yew", "Yam", "Yam bean"},                                                      // Y
        {"Zucchini", "Zante currant", "Zabaglione", "Zaqqum", "Zigzag vine fruit", "Zinfandel grape", "Zalzalak", "Zalzalak", "Zampone", "Zigzag vine fruit"}            // Z
    };
    // Get the first character of the input word
    char letter = input_word.empty() ? 'A' : toupper(input_word[0]);
    // Find the corresponding vector of words for the first letter
    vector<string> fruits = words_by_letter[letter - 'A'];
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));
    // Shuffle the words to ensure randomness
    random_shuffle(fruits.begin(), fruits.end());
    // Initialize a string to store the result
    string result;
    // Concatenate the first 10 words to the result string
    for (int i = 0; i < min(10, static_cast<int>(fruits.size())); ++i)
        result += fruits[i] + " ";
    // Return the result string
    return result;
}
int main()
{
    hashtablechk hash(26);

    string addword, randomword2;
    do
    {
        cout << "\n\n\033[1;33m == CPE113 Lab12 66044768 Saranphat Treepien ==  \033[0m\n";
        cout << "           ------  Hash Table  ------\n";
        hash.display();
        cout << "Enter your word to add to the hash table: ";
        string addword;
        cin >> addword;
        randomword2 = randomword(addword);
        // Check if the input contains any digits
        // cout << randomword2 << endl;
        hash.add(randomword2);
        waitForEnter(); // Assuming this is a function to wait for user input
    } while (1);

    return 0;
}