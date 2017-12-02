#include "core/Engine2D.h"

#include "utils/log.h"

#include <chrono>
#include <thread>
#include <stdexcept>


Engine2D::Engine2D()
    : m_timeManager(TimeManager::getInstance()),
      m_fpsManager(FPSManager::getInstance()),
      m_inputManager(InputManager::getInstance()),
      m_textureManager(TextureManager::getInstance()),
      m_spriteManager(SpriteManager::getInstance()),
      m_sceneManager(SceneManager::getInstance()),
      m_renderEngine(RenderEngine::getInstance()) {
}

Engine2D::~Engine2D() {
    this->shutdown();
}

void Engine2D::startup() {
    this->m_isRunning = true;

    this->m_timeManager.startup();
    this->m_fpsManager.startup();
    this->m_inputManager.startup();
    this->m_textureManager.startup();
    this->m_spriteManager.startup();
    this->m_sceneManager.startup();
    this->m_renderEngine.startup();

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        LOG_ERROR("Unable to start SDL: %s", SDL_GetError());
        throw std::runtime_error(SDL_GetError());
    }

    // Create the window used for display (new)
    this->m_window = this->m_renderEngine.getRenderSystem()->newRenderWindow();
    this->m_renderEngine.getRenderSystem()->setRenderWindow(*m_window);
    this->m_window->show();
}

void Engine2D::shutdown() {
    this->m_window->hide();
    this->m_isRunning = false;
    this->m_timeManager.shutdown();
    this->m_fpsManager.shutdown();
    this->m_inputManager.shutdown();
    this->m_textureManager.shutdown();
    this->m_spriteManager.shutdown();
    this->m_sceneManager.shutdown();
    this->m_renderEngine.shutdown();
    delete this->m_window;
}

// The actual main game loop!
void Engine2D::run() {
    while(this->m_isRunning) {
        this->m_timeManager.update();
        this->m_fpsManager.update();
        this->m_inputManager.update();

        //LOG_DEBUG("FPS: %d", this->m_fpsManager.getFPS());
        if (this->m_inputManager.isKeyDown("quit")) {
            break;
        }

        // Physics update
        while(this->m_timeManager.hasNextFixedFrame()) {
            this->m_timeManager.updateFixedFrame();
            // TODO Call update (FixedUpdate)
        }

        // Render update
        this->m_window->clear();
        this->m_renderEngine.update();
        this->m_window->update();
    }
}
