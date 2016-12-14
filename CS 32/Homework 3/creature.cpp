#include<iostream>
#include<string>

using namespace std;

class Creature
{
public:
	Creature(string name)
	{
		m_name = name;
	}
	virtual string name() const { return m_name; }
	virtual bool isMortal() const { return true; }
	virtual string move() const = 0;

	virtual ~Creature()
	{}

private:
	string m_name;
};

class Phoenix :public Creature
{
public:
	Phoenix(string name) :Creature(name)
	{
		//...Nothing		
	}
	virtual bool isMortal() const { return false; }
	virtual string move() const {return "Fly";}
	virtual ~Phoenix()
	{
		cout << "Destroying " << name() << " the Phoenix!"<<endl;
	}
private:
	//...Nothing
};

class Giant :public Creature
{
public:
	Giant(string name, int weight) :Creature(name), m_weight(weight)
	{}
	
	virtual string move() const
	{
		if(m_weight<20)
		{
			return "tromp";
		}
		else
		{
			return "lumber";
		}
	}
	
	virtual ~Giant()
	{
		cout << "Destroying " << name() << " the Giant!" << endl;
	}
private:
	int m_weight;
};

class Centaur : public Creature
{
public:
	Centaur(string name) :Creature(name)
	{}

	
	virtual string move() const { return "trot"; }
	virtual ~Centaur()
	{
		cout << "Destroying " << name() << " the Centaur!" << endl;
	}
	
private:
	//...Nothing
};


void animate(const Creature* c)
{
	cout << c->name() << ", who is ";
	if (c->isMortal())
		cout << "mortal";
	else
		cout << "immortal";
	cout << ", will now " << c->move() << ".\n";
}

int main()
{
	Creature* creatures[4];
	creatures[0] = new Phoenix("Squawkes");
	// Giants have a name and a weight in tons.  Giants under 20 tons
	// walk by tromping; giants weighing at least 20 tons lumber.
	creatures[1] = new Giant("Frawp", 17);
	creatures[2] = new Giant("Gridwulfa", 22);
	creatures[3] = new Centaur("Florence");

	cout << "Here are the creatures." << endl;
	for (int k = 0; k < 4; k++)
		animate(creatures[k]);

	// Clean up the creatures before exiting
	cout << "Cleaning up." << endl;
	for (int k = 0; k < 4; k++)
		delete creatures[k];
}