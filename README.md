# So_long

`so_long` is a small 2D game built using the MiniLibX graphics library. The main goal is to guide a player through a map, collecting items and reaching the exit, while avoiding walls and possibly enemies.

The project introduces basic game development concepts such as textures, sprites, animations, and player movement within a grid-based map.

## Project Goal

- Load and render a map from a `.ber` file
- Handle player input and movement
- Display textures (walls, floor, player, collectables, and exit)
- Track the number of moves taken
- Ensure the map is valid and solvable

## Learning Outcomes

- Working with the **MiniLibX graphics library**
- Loading and handling **2D textures and sprites**
- Managing a **grid-based game world**
- **Reading and parsing maps** from files
- Handling **keyboard input** for movement
- Basic **pathfinding validation** (e.g., ensuring the player can reach all collectables and the exit)
- Structuring a game loop and separating logic from rendering

## Project Challenges

- Limited use of external libraries (only MiniLibX and standard C functions allowed)
- Enforcing strict map rules (e.g., rectangular shape, valid characters, one exit, at least one collectable and player)
- Preventing memory leaks and ensuring clean resource management
- Real-time player input handling and smooth visual updates
- Validating map reachability using algorithms like **flood fill** or **DFS**

## Map Example

Example of a valid `.ber` map file:

- 11111
- 1P0C1
- 10001
- 1C0E1
- 11111

- `1` = Wall  
- `0` = Floor  
- `P` = Player  
- `C` = Collectable  
- `E` = Exit

## Usage

make
./so_long maps/map1.ber
