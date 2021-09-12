#ifndef SNAZE_MANAGER_H
#define SNAZE_MANAGER_H

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <chrono>
using std::chrono::system_clock;
using std::chrono::milliseconds;
#include <thread>
#include <queue>
using std::queue;
#include <iomanip>

#include "level.h"

/// This the main class that represents the Snaze manager.
class SnazeManager {
    public:
        using number_type = unsigned int;

        enum GameState{
            START,          //!< Initial game state.
            WELCOME,        //!< Print welcome message.
            READING,        //!< Reading data files.
            CREATING_LEVEL, //!< Setting up the level
            THINKING,       //!< Deciding next move
            MOVING,         //!< Moving the snake
            NEW_LEVEL,      //!< New level
            CRASH,          //!< Handling snake crash
            WIN_GAME,       //!< Handling the case where the player wins
            LOSE_GAME,      //!< Handling the case where the player loses
            END,            //!< Final game state.
        };
        
        // Constructor
        SnazeManager(int argc, char *argv[]);

        // Public methods
        bool has_ended() const { return m_state == END; }
        void process();
        void update();
        void render() const;
  
    private:
        // Private methods
        void print_usage() const;
        void print_message() const;
        void print_summary() const;
        void print_map() const;
        void error(const std::string& error_message) const;

        // Attributes
        GameState m_state {START};
        std::queue<Level> m_levels;
        number_type m_fps {24};
        number_type m_quant_food {10};
        number_type m_total_lives {5};
        number_type m_remaing_lives;
        std::string m_filename;
        PlayerType m_player_type {BACKTRACKING};
        std::deque<Snake::Instruction> m_instructions;
};
#endif
