#include <iostream>

class ParkingSystem {
   public:
    ParkingSystem(int big, int medium, int small) : slots{big, medium, small} {}

    bool addCar(int carType) {
        if (slots[carType - 1] > 0) {
            slots[carType - 1]--;
            return true;
        }
        return false;
    }

   private:
    int slots[3];
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ParkingSystem ps(1, 1, 0);
    std::cout << ps.addCar(1) << std::endl;
    std::cout << ps.addCar(2) << std::endl;
    std::cout << ps.addCar(3) << std::endl;
    std::cout << ps.addCar(1) << std::endl;

    return 0;
}
