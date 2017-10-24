#include "core/App.h"
#include "core/Engine2D.h"

int main(int argc, char **argv) {
    Engine2D& engine = Engine2D::getInstance();
    engine.startUp();
    engine.run();
    //App app;
    //return app.executeApp();
    return 0;
}
