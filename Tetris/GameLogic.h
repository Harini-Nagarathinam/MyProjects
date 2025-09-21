/*
 * GameLogic.h
 *
 *  Created on: 21-Apr-2025
 *      Author: Harini Nagarathinam
 */

#ifndef GAMELOGIC_H_
#include <GameLogic.c>
#define GAMELOGIC_H_
// Types of Tetris blocks
typedef enum { I, O, T, Z, L } BlockType;

// A single block on the screen (type and position)
typedef struct {
    int x, y;             // grid position of the block
    uint8_t rotation;     // 0-3 rotation value
    BlockType type;       // block shape
} ActiveBlock;

//Game state
typedef struct {
    uint8_t grid[20][10];        // 20 rows x 10 columns of game area
    ActiveBlock currentBlock;    // block that is currently falling
    int score;                   // player's score
    int gameOver;                // flag to check if game is over (1 = yes, 0 = no)
} GameState;

void init_game(GameState *game);          // start a new game
int get_block_shape(BlockType type, int rotation, int row, int col); // to get shape of the falling block
int does_collide(GameState *game, ActiveBlock *block); // to check if there is collision
void update_gravity(GameState *game);     // drop the block down 1 row
void lock_block(GameState *game);         // fix the block in place after landing
void clear_full_lines(GameState *game);   // check and clear full rows
void spawn_new_block(GameState *game);    // drop a new block at the top
void rotate_block(GameState *game);       // rotate the block
void move_block(GameState *game, int dx); // move block left or right
