#include "metodos.cpp"

int main(int argc, char const *argv[])
{
    ListaDoble * clientes = new ListaDoble(); //lista creada pn es null
	Cliente * ptPaco = new Cliente(1, "Paco", 10000);
	clientes->insertarAlInicio(ptPaco);
	clientes->insertarAlInicio(new Cliente(2, "Hugo", 5000));
	clientes->insertarAlInicio(new Cliente(3, "Luisa", 12000));
	clientes->insertarAlInicio(new Cliente(4, "Paula", 9000));

	ptPaco->hijos->insertar(new Hijo(1,"Paco Jr", 10));
	ptPaco->hijos->insertar(new Hijo(2,"Paquita", 8));
	ptPaco->hijos->insertar(new Hijo(3,"Paquete", 6));

	clientes->insertarHijo("Paco", 4,"Paquinha", 11);
	clientes->insertarHijo("Luisa", 4,"Luisita", 11);
	clientes->insertarHijo("Paula", 4,"Paulie", 11);


	clientes->insertarHobby(1, "Paquinha", new Hobby("tennis", 2));
	clientes->insertarHobby(1, "Paquinha", new Hobby("PS4", 4));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("futbol", 6));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("tennis", 8));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("PS4", 8));
	clientes->insertarHobby(1, "Paquita", new Hobby("tennis", 9));
	clientes->insertarHobby(1, "Paquita", new Hobby("ajedrez", 3));
	clientes->insertarHobby(1, "Paquete", new Hobby("tennis", 3));
	clientes->insertarHobby(3, "Luisita", new Hobby("tennis", 2));
	clientes->insertarHobby(3, "Luisita", new Hobby("futbol", 2));
	clientes->insertarHobby(4, "Paulie", new Hobby("tennis", 5));

	clientes->imprimir();
	cout << clientes->promedioFrecuenciaDeHobby("tennis")<<endl;
	cout << "No entiendo que pasaaaa" <<endl;
    return 0;
}
