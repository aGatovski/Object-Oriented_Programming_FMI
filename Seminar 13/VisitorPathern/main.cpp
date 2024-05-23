#include <iostream>
#include"Monster.h"
#include "Minotaur.h"


int main()
{
    Monster* t = new Minotaur();
    std::cout<<t->fightCentaver();
    std::cout << t->fightMinotaur();
    std::cout << t->fightSphinx();
}
