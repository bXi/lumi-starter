#include "main.h"

int main() {
    Input::Init();

    Window::InitWindow("Luminoveau - start", 1280, 720, 1);

    while (!Window::ShouldQuit()) {
        Window::StartFrame(); //sets up the frame

        Text::DrawText(AssetHandler::GetDefaultFont(), {10, 10}, "Hello, world!", WHITE); //draws text

        Window::EndFrame(); // render everything and push to screen
    }
}