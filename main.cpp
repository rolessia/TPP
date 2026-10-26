#include <SFML/Graphics.hpp>
#include <optional>
#include <cmath>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML Pendulum Variant 19");

    // Фізичні параметри
    float L = 300.f; // Довжина підвісу
    float g = 980.f; // Гравітація 
    float theta = 0.5f; // Кут відхилення
    float omegaVel = 0.f; // Кутова швидкість
    float A = 0.f; // Амплітуда зовнішньої сили
    float omegaForce = 0.f; // Частота зовнішньої сили
    float t = 0.f; // Час
    bool isPaused = false; // Стан симуляції

    // Завантаження шрифту
    sf::Font font;
    if (!font.openFromFile("../resources/fonts/arial.ttf")) return 1;
    sf::Text infoText(font, "", 20);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition({ 20.f, 20.f });

    sf::Clock clock;

    while (window.isOpen())
    {
        // 1. Оброблення введення
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if (event->is<sf::Event::KeyPressed>())
            {
                const auto key = event->getIf<sf::Event::KeyPressed>();
                if (key->code == sf::Keyboard::Key::Up) A += 0.5f;
                if (key->code == sf::Keyboard::Key::Down) A -= 0.5f;
                if (key->code == sf::Keyboard::Key::Right) omegaForce += 0.5f;
                if (key->code == sf::Keyboard::Key::Left) omegaForce -= 0.5f;
                if (key->code == sf::Keyboard::Key::Space) isPaused = !isPaused;
            }
        }

        float dt = clock.restart().asSeconds();
        if (dt > 0.1f) dt = 0.1f; // Запобігання стрибкам при паузі програми

        // 2. Оновлення фізичної моделі
        if (!isPaused)
        {
            t += dt;
            // Обчислення кутового прискорення з урахуванням періодичної сили
            float alpha = -(g / L) * std::sin(theta) + A * std::cos(omegaForce * t);
            omegaVel += alpha * dt;
            theta += omegaVel * dt;
        }

        // 3. Відображення сцени
        window.clear(sf::Color::Black);

        // Обчислення координат маятника
        sf::Vector2f anchor(400.f, 50.f);
        sf::Vector2f bob(anchor.x + L * std::sin(theta), anchor.y + L * std::cos(theta));

        // Малювання нитки
        sf::VertexArray line(sf::PrimitiveType::Lines, 2);
        line[0].position = anchor;
        line[1].position = bob;
        window.draw(line);

        // Малювання вантажу
        sf::CircleShape circle(20.f);
        circle.setFillColor(sf::Color::Red);
        circle.setOrigin({ 20.f, 20.f });
        circle.setPosition(bob);
        window.draw(circle);

        // Виведення параметрів
        infoText.setString(
            "Amplitude (Up/Down): " + std::to_string(A) + "\n" +
            "Frequency (Left/Right): " + std::to_string(omegaForce) + "\n" +
            "Space to Pause/Play"
        );
        window.draw(infoText);

        window.display();
    }
    return 0;
}