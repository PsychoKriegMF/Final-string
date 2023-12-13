#include <iostream>
#include <string>

std::string spaces_str(std::string str);
bool is_spam(std::string str);

int main() {
	//setlocale(LC_ALL, "ru");
	system("chcp 1251>null");
	
	std::cout << "Задача 1.\nПробелы встроке.\n";
	std::cout << "Введите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";
	
	std::cout << "Задача 2.\nПроверка Спама.\n";
	std::cout << "Введите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаружен  спам!\n";
	else
		std::cout << "Спама не обнаружено!\n";

	
	return 0;
}

std::string spaces_str(std::string str) {
	std::string result(str.length() * 2 - 1, ' ');
	for (int i = 0; i < str.length(); i++)
		result[i * 2] = str[i];
	return result;
}

bool is_spam(std::string str) {
	//Возведение строки в нижний регистр для обеспечения не регистрозависимости функции
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);  
	const int spams_number = 4;
	static const std::string spams[spams_number]{
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};
	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true;
	return false;
}
