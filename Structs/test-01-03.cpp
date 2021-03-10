#include <iostream>
#include <cstring>

struct Currency {
    char name[5];
    float buyRate;
    float sellRate;
    float amount;
    char type;
};

struct CurrencyExchange {
    char name[21];
    char address[51];
    char bulstat[14];
    int currenciesCount;
    Currency currencies[10];
};

struct Exchange {
    Currency *currency_buy;
    float buy_amount;
    Currency *currency_sell;
    float sell_amount;
};

void inputCurrency(Currency &currency) {
    std::cout << "Name: ";
    std::cin >> currency.name;
    std::cout << "Buy rate (BGN): ";
    std::cin >> currency.buyRate;
    std::cout << "Sell rate (BGN): ";
    std::cin >> currency.sellRate;
    std::cout << "Amount: ";
    std::cin >> currency.amount;
    std::cout << "Type: ";
    std::cin >> currency.type;
}

void inputCurrencyExchange(CurrencyExchange &currencyExchange) {
    std::cout << "Name: ";
    std::cin.getline(currencyExchange.name, 21);
    std::cout << "Address: ";
    std::cin.getline(currencyExchange.address, 51);
    std::cout << "Bulstat: ";
    std::cin.getline(currencyExchange.bulstat, 14);
    std::cout << "Currencies count: ";
    std::cin >> currencyExchange.currenciesCount;
    std::cout << "Currencies: " << std::endl;
    for (int i = 0; i < currencyExchange.currenciesCount; i++) {
        std::cout << '(' << i + 1 << '/' << currencyExchange.currenciesCount << ')' << std::endl;
        inputCurrency(currencyExchange.currencies[i]);
    }
    return;
}

void printCurrencyExchangeDataHeader() {
    std::cout.width(15); std::cout << std::left << "Name";
    std::cout.width(30); std::cout << std::left << "Address";
    std::cout.width(15); std::cout << std::left << "Bulstat";
    std::cout.width(5); std::cout << std::left << "C.#" << std::endl;
    return;
}

void printCurrencyDataHeader() {
    std::cout.width(3); std::cout << std::left << "#";
    std::cout.width(6); std::cout << std::left << "Name";
    std::cout.width(6); std::cout << std::left << "Buy";
    std::cout.width(6); std::cout << std::left << "Sell";
    std::cout.width(8); std::cout << std::left << "Amount";
    std::cout.width(6); std::cout << std::left << "Type" << std::endl;
    return;
}

void printExchangeDataHeader() {
    std::cout.width(3); std::cout << std::left << "#";
    std::cout.width(6); std::cout << std::left << "Buy";
    std::cout.width(6); std::cout << std::left << "Amo";
    std::cout.width(6); std::cout << std::left << "Sell";
    std::cout.width(6); std::cout << std::left << "Amo" << std::endl;
    return;
}

void printCurrency(Currency &currency) {
    std::cout.width(6); std::cout << std::left << currency.name;
    std::cout.width(6); std::cout << std::left << currency.buyRate;
    std::cout.width(6); std::cout << std::left << currency.sellRate;
    std::cout.width(8); std::cout << std::left << currency.amount;
    std::cout.width(6); std::cout << std::left << currency.type << std::endl;
    return;
}

void printCurrencyExchange(CurrencyExchange &currencyExchange) {
    printCurrencyExchangeDataHeader();
    std::cout.width(15); std::cout << std::left << currencyExchange.name;
    std::cout.width(30); std::cout << std::left << currencyExchange.address;
    std::cout.width(15); std::cout << std::left << currencyExchange.bulstat;
    std::cout.width(5); std::cout << std::left << currencyExchange.currenciesCount << std::endl;
    std::cout << "Currencies:" << std::endl;
    printCurrencyDataHeader();
    for (int i = 0; i < currencyExchange.currenciesCount; i++) {
        std::cout.width(3); std::cout << std::left << i + 1;
        printCurrency(currencyExchange.currencies[i]);
    }
    return;
}

bool makeExchange(Exchange &exchange, CurrencyExchange &currencyExchange) {
    std::cout << "Currency buy: ";
    char currency_buy_name[5];
    std::cin >> currency_buy_name;
    std::cout << "Amount: ";
    std::cin >> exchange.buy_amount;
    std::cout << "Currency sell: ";
    char currency_sell_name[5];
    std::cin >> currency_sell_name;
    if (strcmp(currency_buy_name, currency_sell_name) == 0) {
        std::cout << "ERROR: Buy currency and sell currency cannot be the same" << std::endl;
        return false; 
    }
    bool found_buy = false, found_sell = false;
    for (int i = 0; i < currencyExchange.currenciesCount; i++) {
        if (strcmp(currencyExchange.currencies[i].name, currency_buy_name) == 0) {
            found_buy = true;
            exchange.currency_buy = &currencyExchange.currencies[i];
            break;
        }
    }
    for (int i = 0; i < currencyExchange.currenciesCount; i++) {
        if (strcmp(currencyExchange.currencies[i].name, currency_sell_name) == 0) {
            found_sell = true;
            exchange.currency_sell = &currencyExchange.currencies[i];
            break;
        }
    }
    if (!(found_buy && found_sell)) {
        std::cout << "ERROR: Currency not found!" << std::endl;
        return false;
    }
    float ratio = exchange.currency_buy->buyRate / exchange.currency_sell->sellRate;
    if (exchange.currency_sell->amount < ratio * exchange.buy_amount) {
        std::cout << "ERROR: Not enough sell currency!" << std::endl;
        return false;
    }
    exchange.sell_amount = exchange.buy_amount * ratio;
    exchange.currency_buy->amount += exchange.buy_amount;
    exchange.currency_sell->amount -= exchange.sell_amount;
    return true;
}

void printExchange(Exchange &exchange) {
    std::cout.width(6); std::cout << std::left << exchange.currency_buy->name;
    std::cout.width(6); std::cout << std::left << exchange.buy_amount;
    std::cout.width(6); std::cout << std::left << exchange.currency_sell->name;
    std::cout.width(6); std::cout << std::left << exchange.sell_amount << std::endl;
    return;
}

int main() {
    CurrencyExchange currencyExchange;
    inputCurrencyExchange(currencyExchange);
    printCurrencyExchange(currencyExchange);
    int n;
    std::cout << "n= ";
    std::cin >> n;
    Exchange exchanges[n];
    int i = 0;
    for (int i = 0; i < n; i++) {
        std::cout << "Transaction (" << i + 1 << '/' << n << ')' << std::endl;
        if (makeExchange(exchanges[i], currencyExchange)) {
            std::cout << "Transaction successfull!" << std::endl;
        }   
    }
    printCurrencyExchangeDataHeader();
    printCurrencyExchange(currencyExchange);
    char currency_name[5];
    std::cout << "Select currency to see transactions: ";
    std::cin >> currency_name;
    int found = 0;
    printExchangeDataHeader();
    for (int i = 0; i < n; i++) {
        if (strcmp(exchanges[i].currency_buy->name, currency_name) == 0 || strcmp(exchanges[i].currency_sell->name, currency_name) == 0) {
            found++;
            std::cout.width(3); std::cout << found;
            printExchange(exchanges[i]);
        }
    }
    std::cout << "Total "<< found << " transactions with " << currency_name << " found." << std::endl;
    return 0;
}