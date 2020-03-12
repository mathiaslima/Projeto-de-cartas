/*
 * Exercicio:
 * 
 * 1) Ler cartas da entrada padrão.
 * 2) Implementar alg. find_if()
 * 3) Implementar alg. filter()
 * 4) Aplicar nas situações:
 *      4A) Usar find_if para: Achar a primeira carta cujo valor da face seja uma figura (valete, dama, rei).
 *      4B) Usar find_if para: Achar a primeira carta que seja vermelha.
 *      4C) Usar filter para: Selecioar em um vetor apenas as cartas de "hearts"
 *      4C) Usar filter para: Selecioar apenas as cartas com figuras.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


struct Card {
    enum class suit : int
    {
        clubs    = 0,
        diamonds = 1,
        hearts   = 2,
        spades   = 3,
    };

    suit s;
    unsigned short r; // rank
};

typedef bool (*Predicado)(Card);

void readFile(std::vector<Card> & cards){
    short unsigned int num;
    short unsigned int num2;
    std::ifstream file("input.txt", std::ios::in); 

    while(file >> num){
        
        switch (num)
        {
        case 0:
            file >> num2;
            cards.push_back({Card::suit::clubs, (num2 - 1)});
            break;
        case 1:
            file >> num2;
            cards.push_back({Card::suit::diamonds, (num2 - 1)});
            break;
        case 2:
            file >> num2;
            cards.push_back({Card::suit::hearts, (num2 - 1)});
            break;
        case 3:
            file >> num2;
            cards.push_back({Card::suit::spades, (num2 - 1)});
            break;
        
        default:
            break;
        }
    }

    file.close();

    
}
bool is_figure(Card e){
    return (e.r >= 11);
}
bool is_red(Card e){
    return (e. >= 11);
}


Card * find_if(std::vector<Card> cards, Predicado predicad){

    for (Card card : cards)
    {
        if(predicad(card)){
            return & card; 
        }
    }

}


std::ostream& operator<<( std::ostream& os, const Card & c )
{
    std::string ranks_to_str[]{"as", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king", "joker"};
    std::string suits_to_str[]{ "clubs", "diamonds", "hearts", "spades" };
    os << ranks_to_str[c.r];
    if ( c.r < 13 ) os << " of " << suits_to_str[static_cast<int>(c.s)];

    return os;
}

int main(void)
{
    std::vector<Card> cards;

    Card hand[] { {Card::suit::clubs, 2},
                  {Card::suit::hearts, 8},
                  {Card::suit::spades, 11} };


    Card c1{Card::suit::spades, 11}, c2{Card::suit::diamonds, 10};
    readFile(cards);

    for ( const auto& e : cards )
    {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    return 0;
}
