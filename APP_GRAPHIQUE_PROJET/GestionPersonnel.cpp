#include "GestionPersonnel.h"

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
bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_ID_entry()
{
	String^ Personnel_ID = this->TXT_ID_PERSONNEL->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_ID)) {
		MessageBoxA(NULL, "Le champ ID client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string peronnelIDString = msclr::interop::marshal_as<std::string>(Personnel_ID);

	// On v�rifie que le texte ne contient que des chiffres
	for (char c : peronnelIDString) {
		if (!Char::IsDigit(c)) {
			MessageBoxA(NULL, "Le champ batiment client ne doit contenir que des chiffres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : peronnelIDString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}



//
// 2) M�thode pour checker les entr�es pour le nom du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_name_entry()
{
	String^ Personnel_Nom = this->TXT_NOM_PERSONNEL->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_Nom)) {
		MessageBoxA(NULL, "Le champ Nom client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string personnelNomStdString = msclr::interop::marshal_as<std::string>(Personnel_Nom);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : personnelNomStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ 'nom' client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelNomStdString) {
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

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_surname_entry()
{
	String^ Personnel_Prenom = this->TXT_PRENOM_PERSONNEL->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_Prenom)) {
		MessageBoxA(NULL, "Le champ Prenom client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string personnelPrenomStdString = msclr::interop::marshal_as<std::string>(Personnel_Prenom);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : personnelPrenomStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ pr�nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelPrenomStdString) {
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

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_mail_entry()
{
	String^ Personnel_Mail = this->TXT_MAIL_PERSONNEL->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_Mail)) {
		MessageBoxA(NULL, "Le champ Prenom client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string personnelMailStdString = msclr::interop::marshal_as<std::string>(Personnel_Mail);

	// On v�rifie que le texte ne contient que des caract�res alphanum�riques et l'@
	bool is_valid = true;
	for (char c : personnelMailStdString) {
		if (!isalnum(c) && c != '@') {
			is_valid = false;
			break;
		}
	}

	if (!is_valid) {
		MessageBoxA(NULL, "Le champ mail client ne doit contenir que des lettres, des chiffres et l'@.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelMailStdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ mail client ne doit pas contenir de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte contient un @
	int atIndex = Personnel_Mail->IndexOf('@');
	if (atIndex == -1 || atIndex == 0 || atIndex == Personnel_Mail->Length - 1) {
		MessageBoxA(NULL, "Le champ mail doit contenir un @ et ne peut pas commencer ou se terminer par @.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// On v�rifie que le texte contient une extension de mail valide
	String^ extension = Personnel_Mail->Substring(atIndex + 1);
	std::string clientExtensionStdString = msclr::interop::marshal_as<std::string>(extension);

	// Liste des extensions valides
	std::vector<std::string> valid_extensions = { "gmail.com", ".fr", ".net", ".org", ".edu" };

	bool is_valid_extension = false;

	for (const std::string& valid_extension : valid_extensions) {
		// Comparaison insensible � la casse
		if (_stricmp(clientExtensionStdString.c_str(), valid_extension.c_str()) == 0) {
			is_valid_extension = true;
			break;
		}
	}

	if (!is_valid_extension) {
		MessageBoxW(NULL, L"Le champ mail doit contenir une extension valide.", L"Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Le texte est valide -> on retourne true
	return true;
}


//
// 6) M�thode pour checker l' entr�e pour la ville du client + �viter les injections SQL
//

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_ville_entry()
{
	String^ Personnel_Ville = this->TXT_VILLE_PERSONNEL->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_Ville)) {
		MessageBoxA(NULL, "Le champ Ville client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string personnelVilleStdString = msclr::interop::marshal_as<std::string>(Personnel_Ville);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : personnelVilleStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ ville client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelVilleStdString) {
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

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_rue_entry()
{
	String^ Personnel_Rue = this->TXT_RUE_PERSONNEL->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_Rue)) {
		MessageBoxA(NULL, "Le champ Rue client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string personnelRueStdString = msclr::interop::marshal_as<std::string>(Personnel_Rue);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : personnelRueStdString) {
		if (!isalpha(c)) {
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelRueStdString) {
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

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_code_postal_entry()
{
	String^ Personnel_Code_Postal = this->TXT_CP_PERSONNEL->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_Code_Postal)) {
		MessageBoxA(NULL, "Le champ Code Postal client ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string personnelCodePostaldString = msclr::interop::marshal_as<std::string>(Personnel_Code_Postal);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : personnelCodePostaldString) {
		if (!isalnum(c)) { // VARIANTE AVEC DE l'ALPHANUMERIQUE
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelCodePostaldString) {
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

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_name_building_entry()
{
	String^ Personnel_Batiment = this->TXT_BAT_PERSONNEL->Text;

	// Convertir System::String^ en std::string
	std::string personnelBatimentdString = msclr::interop::marshal_as<std::string>(Personnel_Batiment);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : personnelBatimentdString) {
		if (!isalnum(c)) { // VARIANTE AVEC DE l'ALPHANUMERIQUE
			MessageBoxA(NULL, "Le champ nom client ne doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelBatimentdString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_floor_entry()
{
	String^ Personnel_Etage = this->TXT_ETAGE_PERSONNEL->Text;

	// Convertir System::String^ en std::string
	std::string clientEtageString = msclr::interop::marshal_as<std::string>(Personnel_Etage);

	// On v�rifie que le texte ne contient que des chiffres
	for (char c : clientEtageString) {
		if (!Char::IsDigit(c)) {
			MessageBoxA(NULL, "Le champ batiment client ne doit contenir que des chiffres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : clientEtageString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}


bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_role_entry()
{
	String^ Personnel_Role = this->TEXT_ROLE_PERSONNEL->Text;

	// Convertir System::String^ en std::string
	std::string personnelRoledString = msclr::interop::marshal_as<std::string>(Personnel_Role);

	// On v�rifie que le texte ne contient que des lettres
	for (char c : personnelRoledString) {
		if (!isalnum(c)) { // VARIANTE AVEC DE l'ALPHANUMERIQUE
			MessageBoxA(NULL, "Le champ role personnel doit contenir que des lettres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : personnelRoledString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ role personnel ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}

bool APPGRAPHIQUEPROJET::GestionPersonnel::check_personnel_ID_supperior_entry()
{
	String^ Personnel_ID_Supperieur = this->TXT_ID_SUP->Text;

	// V�rifier si l'entr�e est nulle ou non 
	if (String::IsNullOrEmpty(Personnel_ID_Supperieur)) {
		MessageBoxA(NULL, "Le champ ID sup�rieur personnel ne peut pas �tre vide.", "Erreur", MB_OK | MB_ICONERROR);
		return false;
	}

	// Convertir System::String^ en std::string
	std::string peronnelIDSuppString = msclr::interop::marshal_as<std::string>(Personnel_ID_Supperieur);

	// On v�rifie que le texte ne contient que des chiffres
	for (char c : peronnelIDSuppString) {
		if (!Char::IsDigit(c)) {
			MessageBoxA(NULL, "Le champ id sup�rieur personnel ne doit contenir que des chiffres.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// On v�rifie que le texte ne contient pas de caract�res sp�ciaux pouvant �tre utilis�s pour des injections SQL
	for (char c : peronnelIDSuppString) {
		if (c == '"' || c == '\'' || c == '\\' || c == ';' || c == '`' || c == '<' || c == '>') {
			MessageBoxA(NULL, "Le champ nom client ne doit pas contenir de caract�res sp�ciaux.", "Erreur", MB_OK | MB_ICONERROR);
			return false;
		}
	}

	// Le texte est valide -> on retourne true
	return true;
}