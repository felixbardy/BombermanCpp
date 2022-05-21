#pragma once

#include "BombermanCore.h"


namespace BombermanCore {

    /// The amount a player moves each frame
    const float PLAYER_MOVE_SPEED = 0.06;

    /// A useful alias to make use of the already existing 'BONUS' masks
    typedef tile_mask BonusMask;
    /// A useful alias to make use of the already existing 'BONUS' masks
    namespace Bonuses = TileContent;

    /// A mask describing the actions of a Player
    typedef uint8_t ActionMask;

    /**
     * @brief Contains ActionMask s describing the actions of a Player
     * 
     */
    namespace ActionMasks {
        /// Empty mask
        const ActionMask CLEAR =      0b00000000; //0
        /// [DEV] Available value
        const ActionMask __AVAILABLE = 1; // [DEV] Available value
        /// Standard action (usually bomb/go back)
        const ActionMask ACTION =     0b00000010; //2
        /// Pause/unpause/select command
        const ActionMask PAUSE =      0b00000100; //4
        /// Going up
        const ActionMask GO_UP =      0b00001000; //8
        /// Going down
        const ActionMask GO_DOWN =    0b00010000; //16
        /// Going left
        const ActionMask GO_LEFT =    0b00100000; //32
        /// Going right
        const ActionMask GO_RIGHT =   0b01000000; //64
    };

    /**
     * @brief A player in a match
     * 
     */
    class Player
    {
    private:
        /// Position of the Player
        float m_x,m_y;
        /// Direction of the Player
        Direction m_dir;
        /// Actions of the Player ( see ActionMasks )
        ActionMask m_action;
        /// Max simultaneous bombs from the Player
        int m_max_bombs;
        /// Current power of Player bombs
        int m_power;
        /// Current bonuses of the Player ( see BonusMask )
        BonusMask m_bonuses;
        /// Death state of the Player
        bool m_is_dead;
    public:
        /**
         * @brief Constructs a new Player at coordinates (x,y)
         * 
         * @param x x coordinate
         * @param y y coordinate
         */
        Player(float x, float y);
        /**
         * @brief Destroys the Player
         * 
         */
        ~Player();

        /**
         * @brief Returns the position of the Player in two given ints
         * 
         * @param x pointer to the x coordinate
         * @param y pointer to the y coordinate
         */
        void getPos(float *x, float *y) const;
        /**
         * @brief Sets the position of the Player
         * 
         * @param x x coordinate
         * @param y y coordinate
         */
        void setPos(float x, float y);
        /**
         * @brief Moves the player in the given direction 
         * at speed PLAYER_MOVE_SPEED
         * 
         * @param dir 
         */
        void move(Direction dir);

        /**
         * @brief Returns the Player's Direction
         * 
         * @return the Player's Direction 
         */
        Direction getDir() const;
        /**
         * @brief Sets the Player's Direction
         * 
         * @param dir The new Direction
         */
        void setDir(Direction dir);

        void kill();
        bool isDead() const;

        ActionMask getActions() const;
        void setAction(ActionMask action);
        void addAction(ActionMask action);
        void simplifyActions();
        void clearAction(ActionMask action);
        void clearActions();

        int getMaxBombs() const;
        void addMaxBombs(int mod);

        int getPower() const;
        void addPower(int mod);

        BonusMask getBonuses() const;
        void setBonuses(BonusMask bonus);
        void addBonus(BonusMask bonus);
    };

}