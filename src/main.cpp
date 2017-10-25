#include "core/Engine2D.h"

int main(int argc, char **argv) {
    Engine2D& engine = Engine2D::getInstance();
    engine.startUp();
    engine.run();
    return 0;
}
