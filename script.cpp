#include <iostream>
#include <map>
#include <string>

class CurrencyConverter {
public:
    CurrencyConverter() {
        // Инициализация курсов валют
        exchangeRates["USD"] = 1.0;       // Базовая валюта (доллар США)
        exchangeRates["EUR"] = 0.85;      // Евро
        exchangeRates["JPY"] = 110.0;     // Японская иена
        exchangeRates["GBP"] = 0.75;      // Британский фунт
        exchangeRates["AED"] = 26.42;
        exchangeRates["VND"] = 0,004013;
    }

    double convert(double amount, const std::string& fromCurrency, const std::string& toCurrency) {
        if (exchangeRates.find(fromCurrency) == exchangeRates.end() || exchangeRates.find(toCurrency) == exchangeRates.end()) {
            std::cerr << "Ошибка: неверная валюта." << std::endl;
            return 0.0;
        }
        
        // Конвертация суммы в базовую валюту (USD)
        double amountInUSD = amount / exchangeRates[fromCurrency];
        // Конвертация из базовой валюты в целевую валюту
        return amountInUSD * exchangeRates[toCurrency];
    }

    void displayAvailableCurrencies() {
        std::cout << "Доступные валюты:" << std::endl;
        for (const auto& pair : exchangeRates) {
            std::cout << pair.first << std::endl;
        }
    }

private:
    std::map<std::string, double> exchangeRates; // Словарь с курсами валют
};

int main() {
    CurrencyConverter converter;

    double amount;
    std::string fromCurrency, toCurrency;

    converter.displayAvailableCurrencies();
    
    std::cout << "Введите сумму: ";
    std::cin >> amount;
    std::cout << "Введите валюту, из которой конвертируете (например, USD, EUR): ";
    std::cin >> fromCurrency;
    std::cout << "Введите валюту, в которую конвертируете (например, JPY, GBP): ";
    std::cin >> toCurrency;

    double convertedAmount = converter.convert(amount, fromCurrency, toCurrency);
    if (convertedAmount != 0.0) {
        std::cout << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << std::endl;
    }

    return 0;
}
