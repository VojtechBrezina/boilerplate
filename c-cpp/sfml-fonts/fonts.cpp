#include "fonts.hpp"
#ifdef __unix__

#include <cstdio>
#include <stdexcept>

sf::Font findFont(const std::string &name) {

    std::string path;
    std::string command = "fc-match --format='%{file}' '" + name + "'";

    std::FILE *fcPipe = popen(command.c_str(), "r");
    int c;
    while((c = std::fgetc(fcPipe)) != EOF)
        path.push_back(static_cast<char>(c));

    if(pclose(fcPipe) != 0) {
        throw std::runtime_error(
            "Failed to find fonts on the system. Tried using fonntconfig (fc-match)."
        );
    }

    return sf::Font(path);
}

const sf::Font regularFont = findFont("sans");
const sf::Font monospaceFont = findFont("monospace");

#else

#error "Please provide the fonts yourself if you are not on Unix."
// const sf::Font regularFont = sf::Font("/path/to/font");
// const sf::Font monospaceFont = sf::Font("/path/to/font");

#endif
