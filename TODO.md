# Tasks

## TODO
- Add input manager system
    - Use cases:
        - Player can move paddles up and down. 
        - Game starts when player presses space bar. 
        - Game should be closable.
    - For this project - Pong - I want to hardcode input keys and actions.
- Add physics system
    - Create basic physic components and systems.
    - Add collision detection functionality between entities with physics components.
    - Use cases:
        - Ball physical behaviour includes: 
            - bouncing off paddles. 
            - bouncing off walls. 
            - scoring points when it goes off screen on each side.
        - Paddles should have working collision detection with the ball. 
- Add game state system
    - start state. 
    - playing state. 
    - game over state.
- Basic UI:
    - Add Text Component to render text on the screen.
    - Add UI system update in engine tick.
    - Use cases:
        - Display points on the screen, game over screen, start screen, pause screen.
- Figure out approach to resource management
- Add game state manager on game side.
    - Use cases:
        - Game state, Pause state, Game over state, Menu state.
- [Stretch goal] Add sound system
    - Add physics system callback on collision detection 
        to jack in sound system.
    - Use cases:
        - Play sound when ball hits paddle. 
        - Play sound when ball hits wall. 
        - Play sound when player scores. 
        - Play sound when game is over.

## IN PROGRESS
- Figure out design of rendering system:
    - Use cases:
        - I need to have a renderer that will render entities on the screen. 
        - I need to have a texture manager that will load textures from files.
    - Entities will need to add Sprite Component with: texture path, size, rotation etc
        and system will handle rendering them to the screen.
        - Same thing with Text Component and other rendering related components.
- Figure out how to structure entity component system:
    - Use cases:
        - There will be two paddles, a ball, 
            UI with points going up when player scores, 
            menus, pause screen, etc.
    - It will be classic ECS:
        - Entities are unique IDs, and 
            bitmask value that will tell us what components entity has. 
        - Components are data implemented as structs. 
        - Systems are logic implemented as functions taking.
        - No object oriented designs as I write it in C.
    - For Pong project, no dynamic memory allocation.
- Move ideas about the engine from PalChat on my phone to this file
- Force 60 fps in game loop.
    - debug why we have less than 60 fps. (must be some bug in time calculation)

## DONE
- Figure out how to control gameplay behaviour of entities
    - I will have engine API that will allow registering custom, game-specific
        components, and systems using callbacks.
- check every second what amount of fps we have.

