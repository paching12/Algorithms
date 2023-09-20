#include <iostream>



inline auto doesPlayerOneWin(const int numberStones) -> bool {
    if (isOdd(numberStones)) return false;

    const auto zerosAtBeginning = static_cast<int>(log2(numberStones & -numberStones));
    return isOdd(zerosAtBeginning);
}

int main () {
    int stones = 5;
    std::cout << "stones:" << stones << std:: << std::endl;
}