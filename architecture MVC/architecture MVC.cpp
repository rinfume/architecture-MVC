#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// Клас, який зберігає дані
class UserModel {
private:
    string username;
public:
    void setUsername(const string& name) {
        username = name;
    }

    string getUsername() const {
        return username;
    }
};

// Клас, який відповідає за відображення даних
class UserView {
public:
    void showUserInfo(const string& username) {
        cout << "Ім'я користувача: " << username << endl;
    }

    void promptForUsername() {
        cout << "Введіть ім'я користувача: ";
    }
};

// Клас, який з'єднує Model та View
class UserController {
private:
    UserModel model;
    UserView view;
public:
    UserController(UserModel m, UserView v) : model(m), view(v) {}

    void setUserName(const string& name) {
        model.setUsername(name);
    }

    string getUserName() const {
        return model.getUsername();
    }

    void updateView() {
        view.showUserInfo(model.getUsername());
    }

    void promptForUserNameAndUpdate() {
        view.promptForUsername();
        string name;
        getline(cin, name);
        setUserName(name);
        updateView();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Створюємо екземпляри Model, View та Controller
    UserModel model;
    UserView view;
    UserController controller(model, view);

    // Запитуємо та відображаємо дані
    controller.promptForUserNameAndUpdate();

    return 0;
}
