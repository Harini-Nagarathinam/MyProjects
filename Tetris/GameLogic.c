/*
 * GameLogic.c
 *
 *  Created on: 21-Apr-2025
 *      Author: Harini Nagarathinam
 */
#include<stdlib.h>
void init_game(GameState *game)         // start a new game
{
    for (int i=0;i<20; i++)
    {
    	for (int j=0;j<10;j++)
    	{
    		game -> grid[i][j] = 0;
    		game -> score = 0;
    		game -> gameOver = 0;
    		spawn_new_block(*game);
    	}

    }
}
int get_block_shape(BlockType type, int rotation, int row, int col)
{
	// T
	static const uint8_t TShape[4][4][4]={
			{{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
			{{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
			{{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
			{{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}} };
	// I
	static const uint8_t IShape[4][4][4] = {
	        {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
	        {{0,0,1,0},{0,0,1,0},{0,0,1,0},{0,0,1,0}},
	        {{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
	        {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}} };
	// O
	static const uint8_t OShape[4][4][4] = {
	        {{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
	        {{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
	        {{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
	        {{0,1,1,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}} };
	// Z
	static const uint8_t ZShape[4][4][4] = {
	        {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
	        {{0,0,1,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
	        {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
	        {{0,0,1,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}} };
	// L
	static const uint8_t LShape[4][4][4] = {
	        {{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
	        {{0,1,0,0},{0,1,0,0},{0,1,1,0},{0,0,0,0}},
	        {{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
	        {{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}} };
	if (row < 0 || row >= 4 || col < 0 || col >= 4) return 0;
	switch (type)
	{
	    case T: return TShape[rotation % 4][row][col];
	    case I: return IShape[rotation % 4][row][col];
	    case O: return OShape[rotation % 4][row][col];
	    case Z: return ZShape[rotation % 4][row][col];
	    case L: return LShape[rotation % 4][row][col];
	    default: return 0;
	}
}
int does_collide(GameState *game, ActiveBlock *block)
{
	for(int i=0; i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(get_block_shape(block->type,block->rotation,i,j))
			{
				int gridX = block->x + j;
				int gridY =  block->y + i;
				if(gridX<0 || gridX>10 || gridY<0 || gridY>20)
					return 1; //Out of bound
				if(game->grid[gridX][gridY])
					return 1; // Collision
			}
		}
	}
	return 0;
}
void spawn_new_block(GameState *game)    // drop a new block at the top
{
	game->currentBlock.type = rand()%5;
	game->currentBlock.x=3;
	game->currentBlock.y=0;
	game->currentBlock.rotation=0;
	if(does_collide(game, &game->currentBlock))
		game->gameOver=1;
	// Update screen here =>
}
void update_gravity(GameState *game)     // drop the block down 1 row
{
	game->currentBlock.y++;
	if(does_collide(game, &game->currentBlock))
	{
		game->currentBlock.y--; // no empty block in next line
		lock_block(game); // lock position and update grid
		clear_full_lines(game); // check and clear full lines if any
		spawn_new_block(game); // release next block
		// Update screen here =>
	}
}
void lock_block(GameState *game)         // fix the block in place after landing
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(get_block_shape(game->currentBlock.type,game->currentBlock.rotation,i,j))
			{
				int gridX = game->currentBlock.x + j;
				int gridY = game->currentBlock.y + i;
				if(gridX>=0 && gridX<10 && gridY>=0 && gridY<20)
					game->grid[gridY][gridX]=1; //Locking position
			}
		}
	}
	game->currentBlock.x=-1;
	game->currentBlock.y=-1;
	game->currentBlock.rotation=0;
}
void clear_full_lines(GameState *game)    // check and clear full rows
{
	int temp[4],k=0;
	for(int i=19;i>=0;i--)
	{
		int isFull=1;
		for(int j=0;j<10;j++)
		{
			if(game->grid[i][j]==0)
			{
				isFull=0;
				break;
			}
		}
		if(isFull)
		{
			game->score=game->score+100;
			// Update score here =>
			temp[k]=i;
			k++;
			for (int j=0;j<10;j++) //Clearing the full rows
				game->grid[i][j]=0;
		}
	}
	for(int i=0;i<k;i++)
	{
		int row=temp[i];
		for(int j=row-1;j>=0;j--)
		{
			for(int r=0;r<10;r++)
				game->grid[r][j]=game->grid[r-1][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
	    for (int j = 0; j < 10; j++)
	    	game->grid[i][j] = 0;  // Clearing top rows
	}
}
void rotate_block(GameState *game)      // rotate the block
{
	int previousRotation = game->currentBlock.rotation;
	game->currentBlock.rotation=(game->currentBlock.rotation+1)%4;
	if(does_collide(game,&game->currentBlock))
		game->currentBlock.rotation=previousRotation;
	//Update display here =>
}
void move_block(GameState *game, int dx) // move block left or right
{
	int previousX=game->currentBlock.x;
	game->currentBlock.x+dx;
	if(does_collide(game,&game->currentBlock))
		game->currentBlock.x=previousX;
	//Update display here =>
}