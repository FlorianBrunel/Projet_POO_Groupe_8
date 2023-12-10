#include "GestionStock.h"
/*#include <iostream>
#include <stdexcept>
#include <Windows.h> 
#include <msclr/marshal_cppstd.h>
#include <regex>

#pragma comment(lib, "user32.lib")

using namespace std;

float Article_Prix = Convert::ToSingle(this->TXT_PRIX_ARTICLE->Text);
float Article_TVA = Convert::ToSingle(this->TXT_TVA_ARTICLE->Text);

bool check_article_price_entry();
bool check_article_TVA_entry();


bool APPGRAPHIQUEPROJET::GestionStock::check_article_ID_entry()
{
	String^ Article_ID = this->TXT_ID_ARTICLE->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Article_ID)) {
		MessageBoxA(NULL, "Le champ ID article ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string articleIDString = msclr::interop::marshal_as<std::string>(Article_ID);

	// On v�rifie que le texte ne contient que des chiffres
	for (char c : articleIDString) {
		if (!Char::IsDigit(c)) {
			MessageBoxA(NULL, "Le champs ID article client ne doit contenir que des chiffres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : articleIDString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ID article ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}



//
// 2) M�thode pour checker les entr�es pour le nom du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionStock::check_article_name_entry()
{
	String^ Article_Nom = this->TXT_NOM_ARTICLE->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Article_Nom)) {
		MessageBoxA(NULL, "Le champ Nom article ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string clientNomStdString = msclr::interop::marshal_as<std::string>(Article_Nom);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : clientNomStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ 'nom' article ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientNomStdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom article ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}




//
// 3) M�thode pour checker les entr�es pour le pr�nom du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionStock::check_article_color_entry();
{
	String^ Article_Couleur = this->TXT_COULEUR_ARTICLE->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Article_Couleur)) {
		MessageBoxA(NULL, "Le champ Prenom client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string articleColorStdString = msclr::interop::marshal_as<std::string>(Article_Couleur);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : articleColorStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ pr�nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : articleColorStdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ pr�nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}
//
// 4) M�thode pour checker l' entr�e pour la ville du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_mail_entry()
{
	String^ Client_Mail = this->TXT_PRENOM_CLIENT->Text;

	// Convertir System::String^ en std::string
	std::string emailStdString = msclr::interop::marshal_as<std::string>(this->TXT_MAIL_CLIENT->Text);

	// Expression r�guli�re pour valider une adresse e-mail simple
	std::regex regexPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

	// V�rifier si la cha�ne correspond � l'expression r�guli�re
	if (std::regex_match(emailStdString, regexPattern) == FALSE) {
		MessageBoxA(NULL, "Mail invalide.", "Erreur", MB_OK | MB_ICONERROR);
		return FALSE;
	}

	return true;

}
//
// 6) M�thode pour checker l' entr�e pour la ville du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_ville_entry()
{
	String^ Client_Ville = this->TXT_VILLE_CLIENT->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Client_Ville)) {
		MessageBoxA(NULL, "Le champ Ville client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string clientVilleStdString = msclr::interop::marshal_as<std::string>(Client_Ville);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : clientVilleStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ ville client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientVilleStdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ ville client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}
//
// 7) M�thode pour checker l' entr�e pour la rue du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_rue_entry()
{
	String^ Client_Rue = this->TXT_RUE_CLIENT->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Client_Rue)) {
		MessageBoxA(NULL, "Le champ Rue client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string clientRuedString = msclr::interop::marshal_as<std::string>(Client_Rue);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : clientRuedString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientRuedString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}
//
// 8) M�thode pour checker l' entr�e pour le code postal du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_code_postal_entry()
{
	String^ Client_Code_Postal = this->TXT_CP_CLIENT->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Client_Code_Postal)) {
		MessageBoxA(NULL, "Le champ Code Postal client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string clientCodePostaldString = msclr::interop::marshal_as<std::string>(Client_Code_Postal);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : clientCodePostaldString) {
		if (!isalnum(c)) { // VARIANTE AVEC DE l'ALPHANUMERIQUE
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientCodePostaldString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}
//
// 9) M�thode pour checker l' entr�e pour le nom du b�timent + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionClient::check_client_name_building_entry()
{
	String^ Client_Batiment = this->TXT_BAT_CLIENT->Text;

	// Convertir System::String^ en std::string
	std::string clientBatimentdString = msclr::interop::marshal_as<std::string>(Client_Batiment);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : clientBatimentdString) {
		if (!isalnum(c)) { // VARIANTE AVEC DE l'ALPHANUMERIQUE
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientBatimentdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}

bool APPGRAPHIQUEPROJET::GestionStock::check_article_quantity_entry();
{
	int Article_Stock = Convert::ToInt32(this->TXT_STOCK_ARTICLE->Text);

	// Convertir System::String^ en std::string
	std::string articleEtageString = msclr::interop::marshal_as<std::string>(Article_Stock);

	// On v�rifie que le texte ne contient que des chiffres
	for (char c : articleEtageString) {
		if (!Char::IsDigit(c)) {
			MessageBoxA(NULL, "Le champ batiment client ne doit contenir que des chiffres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : articleEtageString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}

*/