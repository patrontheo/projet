#include<iostream>
#include <vector>

using namespace std;

typedef vector<double> coord;

class Vecteur {
private:

public:
	coord vec;

	void augmente(double x) 
	{
		vec.push_back(x);
	}

	void set_coord(int i, double x)
	{
		int j(vec.size());
		if (j > i)
		{
			vec[i - 1] = x;
		}
		else 
		{
			cout << "Erreur de dimension : la case " << i << " n'existe pas !";
		}
	}

	void affiche() const
	{
		for (size_t i(0); i < vec.size(); ++i)
		{
			cout << vec[i] << " ";
		}
	}
	
	bool compare(Vecteur autre)
	{
		size_t i(vec.size());
		size_t j(autre.vec.size());
		if (j == i) 
		{
			for (size_t k(0); k < i; ++k)
			{
				if (vec[k] != autre.vec[k])
				{
					return false;
				}
			}
		}
		else 
		{
			return false;
		}
		return true;
	}

	Vecteur addition(Vecteur autre) const
	{

	}

	
};

int main() 
{
	Vecteur vect1;
	Vecteur vect2;
	Vecteur vect3;

	/* Cette partie
	* (1) pourrait être écrite autrement, par exemple avec des
	*     manipulateurs (set_coord) ;
	* (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
	*/
	// v1 = (1.0, 2.0, -0.1)
	vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
	vect1.set_coord(2, 2.0); // pour tester set_coord()

							 // v2 = (2.6, 3.5,  4.1)
	vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);

	vect3 = vect1;

	cout << "Vecteur 1 : ";
	vect1.affiche();
	cout << endl;

	cout << "Vecteur 2 : ";
	vect2.affiche();
	cout << endl;

	cout << "Le vecteur 1 est ";
	if (vect1.compare(vect2)) {
		cout << "égal au";
	}
	else {
		cout << "différent du";
	}
	cout << " vecteur 2," << endl << "et est ";
	if (not vect1.compare(vect3)) {
		cout << "différent du";
	}
	else {
		cout << "égal au";
	}
	cout << " vecteur 3." << endl;

	system("pause");
}