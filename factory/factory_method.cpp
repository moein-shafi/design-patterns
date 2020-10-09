#include <iostream> 

using namespace std; 

enum class AnimalType
{
  LION,
  SHEEP
};

class Animal
{
  public:
    static Animal* create_animal(AnimalType type);
    virtual string get_food() = 0;
};

class Sheep : public Animal
{
  public:
    virtual string get_food() override
    {
      return "Grass";
    };
};

class Lion : public Animal
{
  public:
    virtual string get_food() override
    {
      return "Meet";
    };
};

Animal* Animal::create_animal(AnimalType type)
{
    if (type == AnimalType::LION) 
        return new Lion(); 
    else if (type == AnimalType::SHEEP) 
        return new Sheep(); 
    else return nullptr; 
}

class Client { 
  public: 
    Client(AnimalType type) 
    { 
      p_animal = Animal::create_animal(type); 
    }

    ~Client() 
    { 
      if (p_animal) {
        delete[] p_animal;
        p_animal = nullptr;
      } 
    }

    Animal* get_animal()
    { 
      return p_animal; 
    } 

  private: 
    Animal *p_animal; 
}; 


int main()
{
  Client client(AnimalType::LION);
  Animal* animal = client.get_animal();
  cout << "Food: " << animal->get_food() << endl;
  return 0;
}
