#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;


class Game {

    public:

        Game() {
            this->init();

            this->createWindow();
            this->createRenderer();
            
            this->loadImages();
            this->createBackground();
            
            this->createImage();
            
            this->runGameLoop();
            
            this->clear();
            
            SDL_Quit();
        }

    private:

        SDL_Window *window;
        SDL_Renderer* renderer;
        SDL_Texture *background = nullptr;
        SDL_Texture *image = nullptr;
        SDL_Event windowEvent;

        void init() {
            SDL_Init(SDL_INIT_EVERYTHING);
        }

        void runGameLoop() {
            SDL_RenderPresent(this->renderer );
            while (true) {
                if (SDL_PollEvent(&this->windowEvent)) {
                    if (SDL_QUIT == this->windowEvent.type) {
                        break;
                    }
                }
            }
        }

        SDL_Texture* loadImage(std::string file, SDL_Renderer* renderer){
            SDL_Surface *loadedImage = nullptr;
            SDL_Texture *texture = nullptr;
                loadedImage = SDL_LoadBMP(file.c_str());
            if (loadedImage != nullptr){
                texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
                SDL_FreeSurface(loadedImage);
            }
            else
                std::cout << SDL_GetError() << std::endl;
            return texture;
        }

        void applySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
            SDL_Rect pos;
            pos.x = x;
            pos.y = y;
            SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
            SDL_RenderCopy(rend, tex, NULL, &pos);
        }

        int createWindow() {
            this->window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
            if (NULL == this->window) {
                std::cout << "Could not create window: " << SDL_GetError() << std::endl;
                return 1;
            }
            return 0;
        }

        int createRenderer() {
            this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (this->renderer == nullptr){
                std::cout << SDL_GetError() << std::endl;
                return 2;
            }
            return 0;
        }

        int loadImages() {
            this->background = this->loadImage("assets/background.bmp", this->renderer );
            this->image = this->loadImage("assets/image.bmp", this->renderer );
            if (this->background == nullptr || this->image == nullptr) {
                return 4;
            }
            SDL_RenderClear(this->renderer);
            return 0;
        }

        void createBackground() {
            int bW, bH;
            SDL_QueryTexture(this->background, NULL, NULL, &bW, &bH);
            this->applySurface(0, 0, this->background, this->renderer );
        }

        void createImage() {
            int iW, iH;
            SDL_QueryTexture(this->image, NULL, NULL, &iW, &iH);
            int x = WIDTH / 2 - iW / 2;
            int y = HEIGHT / 2 - iH / 2;
            this->applySurface(x, y, this->image, this->renderer );
        }

        void clear() {
            SDL_DestroyTexture(this->background);
            SDL_DestroyTexture(this->image);
            SDL_DestroyRenderer(this->renderer );
            SDL_DestroyWindow(this->window);
        }
};
