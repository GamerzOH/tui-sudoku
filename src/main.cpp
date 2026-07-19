#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

int main() {
    auto screen = ftxui::ScreenInteractive::Fullscreen();

    auto renderer = ftxui::Renderer([&] {
        return vbox(ftxui::text("Hello World!") | ftxui::border | ftxui::center);
    });

    auto quitEvent = ftxui::CatchEvent(renderer, [&] (ftxui::Event event) {
        if (event == ftxui::Event::Character('q') || event == ftxui::Event::Character('Q')) {
            screen.Exit();
            return true;
        }
        return false;
    });

    screen.Loop(quitEvent);

    return 0;
}
