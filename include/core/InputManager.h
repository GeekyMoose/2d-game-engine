#pragma once


class InputManager : private Singleton<InputManager> {
    private:
        friend Singleton<InputManager>;
    public:
        using Singleton<InputManager>::getInstance;
};
