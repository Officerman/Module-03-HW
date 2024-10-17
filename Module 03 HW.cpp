#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Применение принципа DRY
class Logger {
public:
    enum class Level { Error, Warning, Info };

    void log(const std::string& msg, Level level) {
        std::string prefix;
        switch (level) {
            case Level::Error: 
                prefix = "ERROR: "; 
                break;
            case Level::Warning: 
                prefix = "WARNING: "; 
                break;
            case Level::Info: 
                prefix = "INFO: "; 
                break;
        }
        std::cout << prefix << msg << std::endl;
    }
};

// Пример с использованием общих cfg настроек
class Config {
public:
    static std::string getConnectionString() {
        return "Server=myServer;Database=myDb;UserId=myUser;Password=myPass;";
    }
};

class DatabaseService {
public:
    void connect() {
        std::string connStr = Config::getConnectionString();
        // Логика подключения к базе данных
        std::cout << "Connecting to DB with: " << connStr << std::endl;
    }
};

class LoggingService {
public:
    void log(const std::string& msg) {
        std::string connStr = Config::getConnectionString();
        // Логика записи лога в базу данных
        std::cout << "Logging to DB with: " << connStr << std::endl;
    }
};

// Применение принципа KISS
void processNumbers(const std::vector<int>& nums) {
    for (int num : nums) {
        if (num > 0) {
            std::cout << num << std::endl;
        }
    }
}

void printPositiveNumbers(const std::vector<int>& nums) {
    std::vector<int> positives;
    for (int num : nums) {
        if (num > 0) {
            positives.push_back(num);
        }
    }
    std::sort(positives.begin(), positives.end());
    for (int num : positives) {
        std::cout << num << std::endl;
    }
}

int divide(int a, int b) {
    return b == 0 ? 0 : a / b;
}

// Применение принципа YAGNI
class User {
public:
    std::string name;
    std::string email;

    void save() {
        // Логика сохранения пользователя в базу данных
        std::cout << "User " << name << " saved to DB" << std::endl;
    }
};

class EmailService {
public:
    void send(const User& user) {
        // Логика отправки email
        std::cout << "Email sent to " << user.email << std::endl;
    }
};

class ReportGenerator {
public:
    void generate(const std::string& format) {
        if (format == "PDF") {
            std::cout << "Generating PDF report" << std::endl;
        } else if (format == "Excel") {
            std::cout << "Generating Excel report" << std::endl;
        } else if (format == "HTML") {
            std::cout << "Generating HTML report" << std::endl;
        }
    }
};

// Функция для демонстрации
int main() {
    // Демонстрация работы логгера
    Logger logger;
    logger.log("File not found", Logger::Level::Error);
    logger.log("Low disk space", Logger::Level::Warning);
    logger.log("User logged in", Logger::Level::Info);

    // Работы с базой данных
    DatabaseService dbService;
    dbService.connect();

    LoggingService logService;
    logService.log("Application started");

    // Обработки чисел
    std::vector<int> numbers = {1, -3, 5, 0, 7, -2};
    processNumbers(numbers);
    printPositiveNumbers(numbers);

    // Демонстрация деления
    std::cout << "10 / 2 = " << divide(10, 2) << std::endl;
    std::cout << "10 / 0 = " << divide(10, 0) << std::endl;

    // Демонстрация работы с пользователем
    User user{"John Doe", "john@example.com"};
    user.save();

    EmailService emailService;
    emailService.send(user);

    // Генерация отчетов
    ReportGenerator reportGen;
    reportGen.generate("PDF");
    reportGen.generate("Excel");

    return 0;
}
