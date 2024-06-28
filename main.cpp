//
// Created by rrivas on 28/06/2024.
//

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <vector>
#include <algorithm>

void ejemplo_pair() {
    std::pair<std::string, std::string> p1 = {"nombre", "Jose"};
    std::cout << p1.first << " - " << p1.second << std::endl;
}

void ejemplo_map() {
    std::map<std::string, std::string> m1;
    // Agregar valores
    m1["nombre"] = "Jose";
    m1["apellido"] = "Calle";

    // Acceder a los valores (Recorrido)
    for (auto item : m1) {
        std::cout << item.first << " - " << item.second << std::endl;
    }
    for (auto& [key, value]: m1) {
        std::cout << key << " - " << value << std::endl;
    }
}

void ejemplo_map_2() {
    std::map<std::string, int> m1 =
            {
                    {"d", 10},
                    {"a", 50},
                    {"z", 30},
                    {"e", 40},
                    {"a", 20},
                    {"d", 60},
            };

    // Acceder a los valores (Recorrido)
    for (auto& [key, value]: m1) {
        std::cout << key << " - " << value << std::endl;
    }
}

void ejemplo_map_3() {
    std::map<int, std::string> m1 =
            {
                    {10, "d"},
                    {50, "a"},
                    {2, "z"},
                    {5, "e"},
                    {1, "a"},
                    {30, "d"},
            };

    std::cout << m1[2] << std::endl;

    // Acceder a los valores (Recorrido)
    for (auto& [key, value]: m1) {
        std::cout << key << " - " << value << std::endl;
    }
}

struct Rectangulo {
    int base;
    int altura;
};

struct Point {
    int x;
    int y;
};

void ejemplo_map_4() {
    auto compare_rectangulos = [](auto a, auto b) {
        auto k_a = a.base * 1000 + a.altura;
        auto k_b = b.base * 1000 + b.altura;
        return k_a < k_b;
        // return a.base < b.base && a.altura < b.altura;
    };
    std::map<
        Rectangulo, // Tipo del Key
        Point,      // Tipo del Value
        std::function<bool(Rectangulo, Rectangulo)>     // Tipo del Comparador (Tipo de Callable)
        > m1(compare_rectangulos);
    m1 = {
            {{10, 20}, {1, 1}},
            {{30, 40}, {2, 2 }},
            {{20, 10}, {111, 111 }},
    };

    auto p1 = m1[{20, 10}];

    std::cout << p1.x << " " << p1.y;
}

void ejemplo_set_1() {
    // Creando el conjunto 1
    std::vector<int> v1 = {1, 1, 2, 3, 3, 3, 3, 4, };
    std::set<int> s1(v1.begin(), v1.end());       // n log n
    // Creando el conjunto 2
    std::set<int> s2({5, 6, 6, 7, 8, 5, 1, 1});         // n log n
    // Resultado de la union
    std::vector<int> v2;
    // Resultado de la interseccion
    std::vector<int> v3;
    std::set_union(
            s1.begin(), s1.end(),
            s2.begin(), s2.end(), std::back_inserter(v2));
    std::set_intersection(
            s1.begin(), s1.end(),
            s2.begin(), s2.end(), std::back_inserter(v3));
    for (auto item : v2)
        std::cout << item << " ";
    std::cout << std::endl;
    for (auto item : v3)
        std::cout << item << " ";
}
void ejemplo_set_1() {
    std::set<int> s1;
    s1.insert(1);       // log (n)
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);

    // n log (n)

}

int main() {
//    ejemplo_pair();
//    ejemplo_map();
//    ejemplo_map_2();
//    ejemplo_map_3();
//    ejemplo_map_4();
    ejemplo_set_1();
    return 0;
}