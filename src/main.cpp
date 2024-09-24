#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>

// Constats
int WINDOW_WIDTH = 1200;
int WINDOW_HEIGHT = 800;

// Main function
int main() {
    srand(static_cast<unsigned>(time(nullptr)));  // Seed for random number generation

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Molecule Monster - MPS | Alex Grabski");

    // Clock for managing time
    sf::Clock clock;

    // Main loop
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Time step for smooth updates
        float deltaTime = clock.restart().asSeconds() * 1.f;

        // Clear the window
        window.clear();

        // Display the updated frame
        window.display();
    }

    return 0;
}
