# Tasks

## TODO
- Move ideas about the engine from PalChat on my phone to this file
- Figure out how to structure entity component system:
    - I will have two paddles.I will have a ball. 
    - I need points going up when player scores.
- Figure out design of rendering system:
    - I need to have entities that have their own textures. 
    - I need to register entities with the renderer. 
- Figure out how to control gameplay behaviour of entities
- Add input manager system
    - Player can move paddles up and down. 
    - Game starts when player presses space bar. 
    - Game should be closable.
- Add physics system
    - Ball physical behaviour includes: 
        - bouncing off paddles. 
        - bouncing off walls. 
        - scoring points when it goes off screen on each side.
    - Paddles should have working collision detection with the ball. 
- Add game state system
    - start state. 
    - playing state. 
    - game over state.

## IN PROGRESS
- Force 60 fps in game loop.
    - debug why we have less than 60 fps. (must be some bug in time calculation)

## DONE
- check every second what amount of fps we have.

