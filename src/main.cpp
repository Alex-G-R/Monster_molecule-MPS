#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>

#include "Molecule.h"

// Constats
int WINDOW_WIDTH = 1200;
int WINDOW_HEIGHT = 800;

void initializeMolecules(std::vector<Molecule>& molecules, int numMolecules, float starting_temp)
{
    molecules.clear();
    for(size_t i = 0; i < numMolecules; i++)
    {
        const auto x = static_cast<float>(rand() % (WINDOW_WIDTH - 10) + 5);
        const auto y = static_cast<float>(rand() % (WINDOW_HEIGHT - 10) + 5);
        molecules.emplace_back(x, y, starting_temp);
    }
}

// Main function
int main() {
    srand(static_cast<unsigned>(time(nullptr)));  // Seed for random number generation

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Molecule Monster - MPS | Alex Grabski");

    // Simulation parameters
    int numMolecules = 1000;       // Initial number of molecules
    float globalTemperature = 100.0f; // Initial temperature

    // Vector to hold molecules
    std::vector<Molecule> molecules;
    initializeMolecules(molecules, numMolecules, globalTemperature);

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

        // Draw all molecules
        for (const auto& molecule : molecules) {
            window.draw(molecule.shape);
        }

        // Display the updated frame
        window.display();
    }

    return 0;
}
