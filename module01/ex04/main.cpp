#include "Config.hpp"

int main(int ac, char* av[]) {
    Config cfg = Config::from_sysargs(ac, av);
    cfg.log();
}
