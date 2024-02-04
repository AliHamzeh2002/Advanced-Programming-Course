#include <iostream>
#include "CartManager.hh"

int main()
{
    CartManager cart_manager;
    cart_manager.add_item(1, 2, 3);
    cart_manager.add_item(1, 4, 5);
    std::cout << cart_manager.evaluate_cart() << '\n';
}