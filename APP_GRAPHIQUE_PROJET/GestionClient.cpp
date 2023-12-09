#include "GestionClient.h"
#include <iostream>
#include <stdexcept>
#include <Windows.h> 
#include <msclr/marshal_cppstd.h>

#pragma comment(lib, "user32.lib")

using namespace std;
// 
// I) Pour checker les entr�es de l'interface Client
// 

//
// 1) M�thode pour checker les entr�es pour le id du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_ID_entry()
{
	String^ Client_ID = this->TXT_ID_CLIENT->Text;

	// Convertir System::String^ en std::string
	std::string clientIDStdString = msclr::interop::marshal_as<std::string>(Client_ID);

	// On v�rifie que le texte ne contient que des chiffres
	for (char c : clientIDStdString) {
		if (!Char::IsDigit(c)) {
			MessageBoxA(NULL, "Le champ ID client ne doit contenir que des chiffres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientIDStdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ID client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}



//
// 2) M�thode pour checker les entr�es pour le nom du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_name_entry()
{
	String^ Client_Nom = this->TXT_NOM_CLIENT->Text;

	// Convertir System::String^ en std::string
	std::string clientNomStdString = msclr::interop::marshal_as<std::string>(Client_Nom);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : clientNomStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientNomStdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}




//
// 3) M�thode pour checker les entr�es pour le pr�nom du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_surname_entry()
{
	String^ Client_Prenom = this->TXT_PRENOM_CLIENT->Text;

	// Convertir System::String^ en std::string
	std::string clientPrenomStdString = msclr::interop::marshal_as<std::string>(Client_Prenom);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : clientPrenomStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientPrenomStdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}




/*
//
// 4) M�thode pour checker l' entr�e pour la ville du client + �viter les injections SQL
//

bool check_client_mail_entry()
{
	string^ Client_Mail = this->TXT_MAIL_CLIENT->Text;

	// On v�rifie que le texte ne contient que des caract�res alphanum�riques
	bool is_valid = true;
	for (char c : Client_Mail) {
		if (!isalpha(c) && !isdigit(c) && c != '@') {
			is_valid = false;
			break;
		}
	}

	if (!is_valid) {
		MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres, des chiffres et l'@.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : Client_Mail) {
		if (c == '"' || c == "'" || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ville client ne doit pas contenir de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL.", "Erreur", MB_OK | MB_ICONERROR);
			return 1;
		}
	}

	// On v�rifie que le texte contient un @
	if (Client_Mail.IndexOf('@') == -1) {
		MessageBoxA(NULL, "Le champ mail doit contenir un @.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// On v�rifie que le texte contient une extension de mail valide
	string^ extension = Client_Mail.Substring(Client_Mail.IndexOf('@') + 1);
	bool is_valid_extension = false;
	for (string^ extension_valide : { ".com", ".fr", ".net", ".org", ".edu" }) {
		if (extension == extension_valide) {
			is_valid_extension = true;
			break;
		}
	}

	if (!is_valid_extension) {
		MessageBoxA(NULL, "Le champ mail doit contenir une extension valide.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// Le texte est valide -> on retourne le texte
	char Mail = Client_Mail;
	return 0;
}

//
// 6) M�thode pour checker l' entr�e pour la ville du client + �viter les injections SQL
//

bool check_client_ville_entry()
{
	string^ Client_ville = this->TXT_VILLE_CLIENT->Text;

	// On v�rifie que le texte ne contient que des caract�res alphanum�riques
	bool is_valid = true;
	for (char c : Client_Ville) {
		if (!isalpha(c)) {
			is_valid = false;
			break;
		}
	}

	if (!is_valid) {
		MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : Client_Ville) {
		if (c == '"' || c == "'" || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ville client ne doit pas contenir de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL.", "Erreur", MB_OK | MB_ICONERROR);
			return 1;
		}
	}

	// Le texte est valide -> on retourne le texte
	char Ville = Client_Ville;
	return 0;
}

//
// 7) M�thode pour checker l' entr�e pour la rue du client + �viter les injections SQL
//

bool check_client_rue_entry()
{
	string^ Client_Rue = this->TXT_RUE_CLIENT->Text;

	// On v�rifie que le texte ne contient que des caract�res alphanum�riques
	bool is_valid = true;
	for (char c : Client_Rue) {
		if (!isalpha(c)) {
			is_valid = false;
			break;
		}
	}

	if (!is_valid) {
		MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : Client_Rue{
		if (c == '"' || c == "'" || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ville client ne doit pas contenir de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL.", "Erreur", MB_OK | MB_ICONERROR);
			return 1;
		}
		}

		// Le texte est valide -> on retourne le texte
	char Rue = Client_Rue;
		return 0;
}

//
// 8) M�thode pour checker l' entr�e pour le code postal du client + �viter les injections SQL
//

bool check_client_code_postal_entry()
{
	string^ Client_Code_Postal = this->TXT_CP_CLIENT->Text;

	// On v�rifie que le texte ne contient que des caract�res alphanum�riques
	bool is_valid = true;
	for (char c : Client_Code_Postal) {
		if (!isalnum(c)) {
			is_valid = false;
			break;
		}
	}

	if (!is_valid) {
		MessageBoxA(NULL, "Le champ code postal ne doit contenir que des lettres et des chiffres.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// On v�rifie que le texte contient 5 caract�res
	if (Client_Code_Postal.Length != 5) {
		MessageBoxA(NULL, "Le champ code postal doit contenir 5 caract�res.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// Le texte est valide -> on retourne le texte
	char Code_Postal = Client_Code_Postal;
	return 0;
}

//
// 9) M�thode pour checker l' entr�e pour le nom du b�timent + �viter les injections SQL
//

bool check_client_name_building_entry()
{
	string^ Client_Building_Name = this->TXT_NOM_BATIMENT_CLIENT->Text;

	// On v�rifie que le texte ne contient que des caract�res alphanum�riques
	bool is_valid = true;
	for (char c : Client_Building_Name) {
		if (!isalpha(c)) {
			is_valid = false;
			break;
		}
	}

	if (!is_valid) {
		MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
		return 1;
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : Client_Building_Name) {
		if (c == '"' || c == "'" || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ville client ne doit pas contenir de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL.", "Erreur", MB_OK | MB_ICONERROR);
			return 1;
		}
	}

	// Le texte est valide -> on retourne le texte
	char Nom_Bat = Client_Building_Name;
	return 0;
}

bool check_client_floor_entry()
{
	string^ Client_Floor = this->TXT_ETAGE_CLIENT->Text;

	// On v�rifie que le texte est un entier / ne ocmporte que de chiffres

	try {
		int ID_Client = stoi(Client_Floor); // stoi c'est pour transformer une cha�ne de caract�re en int
	}
	catch (invalid_argument& e) {
		MessageBoxA(NULL, "Le champ ID client doit �tre un entier.", "Erreur", MB_OK | MB_ICONERROR); 		// Le texte n'est pas un entier donc on ouvre une fen�tre d'erreur
		return 1;
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : Client_Floor) {
		if (c == '"' || c == "'" || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ID client ne doit pas contenir de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL.", "Erreur", MB_OK | MB_ICONERROR); 			// Le texte contient des caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL donc on ouvre une fen�tre d'erreur
			return 1;
		}
	}

	int Etage = stoi(Client_Floor); // Le texte est valide -> on convertit le texte en int
	return 0;
}
*/