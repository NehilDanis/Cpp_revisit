#include <iostream>

class Game {
    public: 
        Game(int number_of_players): _number_of_players(number_of_players), _current_player(0) {}
        void run() {
            start();
            while(!have_winner())
                take_turn();
            std::cout << "Player " << get_winner() << " wins.\n";
        }
    protected:
        virtual void start() = 0;
        virtual bool have_winner() = 0;
        virtual void take_turn() = 0;
        virtual int get_winner() = 0;
        int _number_of_players;
        int _current_player;
};

class Chess : public Game {
    public:
        Chess(): Game(2) {}
    
    void start() override {
        std::cout << "Starting of a game of chess with " << _number_of_players << "players.\n";
    }
    bool have_winner() override {
        return _turn == _max_turns;
    }
    void take_turn() override {
        std::cout << "Turn " << _turn << " taken but the player " << _current_player << std::endl;
        _current_player = (_current_player + 1) % _number_of_players;
        _turn += 1;
    }   
    int get_winner() override {
        return _current_player;
    }

    private:
        int _turn{0}, _max_turns{10};

};

int main() {
    Chess chess;
    chess.run();
    return 0;
}