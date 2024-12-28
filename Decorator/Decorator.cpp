// Decorator.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

class ISubway
{
public : 
    virtual float Prix() const = 0;
    virtual std::string Type() const = 0;
    virtual ~ISubway(){}
};


class PainItalien : public ISubway
{
public:
    std::string Type() const override
    {
        return "Pain italien \n";
    }

    float Prix() const override
    {
        return 3;
    }
};

class PainBlanc : public ISubway
{
public :
    std::string Type() const override
    {
        return "Pain Blanc\n";
    }

    float Prix() const override
    {
        return 5;
    }
};

class PainParmesanOrigan : public ISubway
{
public:
    std::string Type() const override
    {
        return "Pain parmesan origan\n";
    }

    float Prix() const override
    {
        return 1;
    }
};

class Decorateur : public ISubway
{
public :
    Decorateur (ISubway* SANDWITCH) : sand(SANDWITCH){}
    virtual ~Decorateur() {
        delete sand;
    }

protected:
    ISubway* sand;
};

class Nugets : public Decorateur
{
    
public:
    Nugets(ISubway* sandwitch) : Decorateur(sandwitch) {}
    std::string Type() const override
    {
        return sand->Type() + " avec des nugets \n";
    }

    float Prix() const override
    {
        return sand->Prix() + 2;
    }
};

class PouletSucre : public Decorateur
{
public:

    PouletSucre(ISubway* sandwitch) : Decorateur(sandwitch) {}
    std::string Type() const override
    {
        return sand->Type() + " avec du poulet sucre\n";
    }

    float Prix() const override
    {
        return sand->Prix() + 3;
    }
};



int main()
{

    ISubway* sandwitch = new PouletSucre(new Nugets(new PainParmesanOrigan));
    std::cout << "Type: " << sandwitch->Type() << std::endl;
    std::cout << "Prix: " << sandwitch->Prix() << " euro" << std::endl;


    delete sandwitch;
}

