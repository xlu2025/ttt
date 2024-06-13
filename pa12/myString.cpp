#include <iostream>
#include <cstring>
#include <memory>  // For std::unique_ptr

class MyString {
    std::unique_ptr<char[]> str;  // Use smart pointer for automatic memory management

public:
    MyString() : str(new char[1]) { // Default Constructor
        str[0] = '\0';
    }

    MyString(const char* val) {  // Constructor with 1 argument
        if (val == nullptr) {
            str = std::unique_ptr<char[]>(new char[1]);
            str[0] = '\0';
        }
        else {
            str = std::unique_ptr<char[]>(new char[strlen(val) + 1]);
            strcpy(str.get(), val);
        }
        std::cout << "The given string is: " << str.get() << std::endl;
    }

    MyString(const MyString& source) {  // Copy Constructor
        str = std::unique_ptr<char[]>(new char[strlen(source.str.get()) + 1]);
        strcpy(str.get(), source.str.get());
    }

    MyString(MyString&& source) noexcept { // Move Constructor
        str = std::move(source.str);
    }

    ~MyString() = default; // Destructor (smart pointer handles cleanup)

    // Add other necessary member functions here, e.g., operator=, operator+=, etc.
};

int main(void) {
    std::cout << "Start!" << std::endl;

    MyString a;
    MyString b{ "Hello" };
    MyString c{ a };
    MyString d{ MyString{ "World" } };

    std::cout << "Bye" << std::endl;

    return 0;
}
