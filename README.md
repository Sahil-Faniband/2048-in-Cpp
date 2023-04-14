# 2048-in-C++


->Developed a popular tile-based puzzle game with a basic Interface
->Implemented using 2D Array and Game Logic

*)Gameplay:
A completed game. The 2048 tile is in the bottom-right corner.2048 is played on a plain 4×4 grid, with numbered tiles that slide when a player moves them using the four arrow keys.[3] Every turn, a new tile randomly appears in an empty spot on the board with a value of either 2 or 4.Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid. If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided. The resulting tile cannot merge with another tile again in the same move. Higher-scoring tiles emit a soft glow; the highest possible tile is 131,072.

      If a move causes three consecutive tiles of the same value to slide together, only the two tiles farthest along the direction of motion will combine. If all four spaces in a row or column are filled with tiles of the same value, a move parallel to that row/column will combine the first two and last two.
A scoreboard on the upper-right keeps track of the user's score. The user's score starts at zero, and is increased whenever two tiles combine, by the value of the new tile.

      The game is won when a tile with a value of 2048 appears on the board. Players can continue beyond that to reach higher scores.When the player has no legal moves (there are no empty spaces and no adjacent tiles with the same value), the game ends

*)Strategy:
Strategies in 2048 include keeping the highest tiles in a specific corner and to keep that tile in that corner and to fill the specified row with the highest numbers.
