#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

//test leaks
// void test() {
// 	system("leaks ex03");
// }

int main()
{
	//atexit(test); //test leaks
    {
        // subject test case
        std::cout << "---------------------------" << std::endl;
        std::cout << "subject test case" << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter *me = new Character("me");
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
	{
        // learnMateria test case
        std::cout << "---------------------------" << std::endl;
        std::cout << "error Test 1 : learnMateria" << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        ICharacter *me = new Character("me");
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure"); //Unknown type
        me->equip(tmp); //cannot equip this materia
        ICharacter *bob = new Character("bob");
        me->use(0, *bob); //ice bolt
        me->use(1, *bob); //Nothing happen
        delete bob;
        delete me;
        delete src;
    }
    {
		// index test case
        std::cout << "---------------------------" << std::endl;
        std::cout << "error Test 2 : index" << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter *me = new Character("me");
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(-1, *bob); //Wrong index
        me->use(100, *bob); //Wrong index
        delete bob;
        delete me;
        delete src;
    }
    {
		//slot test case
        std::cout << "---------------------------" << std::endl;
        std::cout << "error Test 3 : slot test" << std::endl;
        IMateriaSource *src = new MateriaSource();
		for (int i = 0; i < 10; i++) {
			std::cout << i << " : ";
    	    src->learnMateria(new Ice());
		}
        ICharacter *me = new Character("me");
        AMateria *tmp;
		for (int i = 0; i < 10; i++) {
			std::cout << i << " : ";
      		tmp = src->createMateria("ice");
      		me->equip(tmp);
     		tmp = src->createMateria("cure"); //unknown type
     		me->equip(tmp); //cannot equip
		}
        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
	{
		// NULL test case
        std::cout << "---------------------------" << std::endl;
        std::cout << "error Test 4 : NULL test" << std::endl;
        IMateriaSource *src = new MateriaSource();
		src->learnMateria(NULL);
        ICharacter *me = new Character("me");
        AMateria *tmp;
		tmp = src->createMateria("sss");
		tmp = src->createMateria("");
		me->equip(NULL);
	    delete me;
		delete src;
	}
	{
		//Unequip test case
        std::cout << "---------------------------" << std::endl;
        std::cout << "error Test 5 : Unequip test" << std::endl;
        IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
        ICharacter *me = new Character("me");
        AMateria *tmp;
		for (int i = 0;i < 110;i++){
			tmp = src->createMateria("ice");
			me->equip(tmp);
			me->unequip(0);
		}
	    delete me;
		delete src;
	}
	{
		//Equip same materia test
        std::cout << "---------------------------" << std::endl;
        std::cout << "error Test 6 : Unequip test" << std::endl;
        IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
        ICharacter *me = new Character("me");
        AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->equip(tmp); //already equip
	    delete me;
		delete src;
	}
    return 0;
}
