#include <iostream>
#include "CartManager.hh"

int main() {
    CartManager cart_manager;
    cart_manager.add_item(1, 1, 1);
    cart_manager.add_item(2, 1, 2);
    cart_manager.add_box(3);
    cart_manager.add_to_box(3, 1);
    cart_manager.add_to_box(3, 2);
    cart_manager.add_box(4);
    cart_manager.add_item(5, 10, 10);
    cart_manager.add_to_box(4, 5);
    std::cout << cart_manager.evaluate_cart() << '\n';
}