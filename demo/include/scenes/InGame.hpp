/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** InGame.hpp
*/

#ifndef IN_GAME_HPP_
    #define IN_GAME_HPP_

    #include <map>
    #include <vector>

    #include "scenes/AScene.hpp"

    
    #define PLAYER_SPRITE_PATH "assets/test.png"
    
enum IG_entities_e : ECS::Entity {
    MAIN_WINDOW = 0,
    PLAYER,
};
    
    #define MAIN_WIN_EXIST (this->_reg.getComponents<Window>().size() > MAIN_WINDOW && this->_reg.getComponents<Window>()[MAIN_WINDOW].has_value())
    #define MAIN_WIN_ISOPEN (this->_reg.getComponents<Window>()[MAIN_WINDOW].value().isOpen())
  
class InGame : public AScene {
    public:
        InGame();
        ~InGame() = default;

        void run(void) override;

    private:
        void setECS(void);
        void setEntities(void);
};

#endif