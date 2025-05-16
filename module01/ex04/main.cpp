#include <fstream>
#include <sstream>
#include <string>

#include "Config.hpp"

namespace {
std::string load_entire_file(const std::string& path);
}  // namespace

typedef std::string::size_type Size;

int main(int ac, char* av[]) {
    const Config cfg = Config::from_sysargs(ac, av);
    // cfg.log();

    const std::string data = load_entire_file(cfg.file);
    // std::cout << data;

    const std::string path = cfg.file + ".replace";
    std::ofstream out(path.c_str());

    for (Size start = 0;;) {
        Size match = data.find(cfg.before, start);
        out << data.substr(start, match);
        if (match == std::string::npos) {
            break;
        }
        out << cfg.after;
        start = match + cfg.before.size();
    }
}

namespace {
std::string load_entire_file(const std::string& path) {
    std::ifstream file(path.c_str());
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
}  // namespace
