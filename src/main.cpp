#include "core/Engine2D.h"

#include "utils/log.h"

#include <exception>


int main(int argc, char **argv) {
    try {
        LOG_TRACE("Start game");
        Engine2D& engine = Engine2D::getInstance();
        engine.startUp();
        engine.run();
        LOG_TRACE("End game");
    }
    catch (const std::exception& ex) {
        LOG_ERROR("Crashed with exception: %s", ex.what());
        return -41;
    }
    catch (...) {
        LOG_ERROR("Crashed with unknown exception");
        return -42;
    }
    return 0;
}
