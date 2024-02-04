#ifndef __CART_MANAGER_HH__
#define __CART_MANAGER_HH__

class CartManager {
public:
    CartManager();
    ~CartManager();
    void add_item(int id, int cost, int weight);
    void add_box(int id);
    void add_to_box(int box_id, int id);
    int evaluate_cart();
private:
    // private implementation
};

#endif
