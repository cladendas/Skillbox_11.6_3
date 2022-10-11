#include <iostream>

//проверка самого октета
bool checkOctette(std::string octette) {
    if (octette.length() != 1 && octette[0] == '0') {
        return false;
    } else if (octette.length() >= 1) {
        int tmp = std::stoi(octette);
        return tmp > 255 ? false : true;
    } else {
        return false;
    }
}

//проверка ip на общие требования
void checkIP(std::string ip) {
    if (ip.length() >= 7
        && ip.length() <= 15
        && ip[0] >= '0'
        && ip[0] <= '9'
        && ip[ip.length() - 1] >= '0'
        && ip[ip.length() - 1] <= '9') {

        //получаем индексы точек
        int firstDot = ip.find('.' , 0);
        int secondDot = ip.find('.', firstDot + 1);
        int thirdDot = ip.find('.', secondDot + 1);

        //получаем значения между точками: октеты
        std::string first = ip.substr(0, firstDot);
        std::string second = ip.substr(firstDot + 1, secondDot - firstDot - 1);
        std::string third = ip.substr(secondDot + 1, thirdDot - secondDot - 1);
        std::string fourth = ip.substr(thirdDot + 1);

        //вызов проверки каждого октета: результат вывод коректности ip
        if (checkOctette(first)
            && checkOctette(second)
            && checkOctette(third)
            && checkOctette(fourth)) {
            std::cout << "Valid";
        } else {
            std::cout << "Invalid";
        }
    } else {
        std::cout << "Invalid";
    }
}

//проверить все примеры из задания
void checkAll() {
    std::string correct[] {
            "127.0.0.1",
            "255.255.255.255",
            "1.2.3.4",
            "55.77.213.101"
    };

    std::string uncorrect[] {
            "255.256.257.258",
            "0.55.33.22.",
            "10.00.000.0",
            "23.055.255.033",
            "65.123..9",
            "a.b.c.d"
    };

    std::cout << " **Checkin correct ********\n";
    for (int i = 0; i < 4; i++) {
        checkIP(correct[i]);
        std::cout << " " << correct[i] << " \n";
    }

    std::cout << " **Checkin uncorrect ********\n";
    for (int i = 0; i < 2; i++) {
        checkIP(uncorrect[i]);
        std::cout << " " << uncorrect[i] << " \n";
    }
}

int main() {
    std::string ip = "55.77.213.101";
    std::cout << "Enter ip for checking:\n" << std::endl;
    std::cin >> ip;

    //проверить введённый ip
    checkIP(ip);

    //проверить все ip из задания
//    checkAll();

    return 0;
}
