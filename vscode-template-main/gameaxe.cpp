#include "raylib.h"

int main(){


// windows dimension
int height{500};
int width{500};
InitWindow(height, width, "axe game window by furkancicek @skyrosina");

// circle coordinates

int circle_x{180};
int circle_y{180};
int circle_radius{25};

//circle edges 

int l_circle_x{circle_x - circle_radius};
int r_circle_x{circle_x + circle_radius};
int u_circle_y{circle_y - circle_radius};
int b_circle_y{circle_y + circle_radius};

int axe_y{250};
int axe_x{300};
int axe_length{40};


// axe edges
int l_axe_x{axe_x};
int r_axe_x{axe_x + axe_length};
int u_axe_y{axe_y};
int b_axe_y{axe_y+axe_length};



bool collision_with_axe = 
                (b_axe_y >= u_circle_y) && 
                (u_axe_y <= b_circle_y) && 
                (r_axe_x >= l_circle_x) && 
                (l_axe_x <= r_axe_x);


int direction{20};


SetTargetFPS(60);
while (WindowShouldClose() == false)

{
    BeginDrawing();
    ClearBackground(WHITE);
    
    EndDrawing();


    if (collision_with_axe){

    DrawText("Game Over",200,200,30,RED);

    }
    else{

        // game logic begins

        //update the edges

        l_circle_x = circle_x - circle_radius;
        r_circle_x = circle_x + circle_radius;
        u_circle_y = circle_y - circle_radius;
        b_circle_y = circle_y + circle_radius;

        l_axe_x = axe_x;
        r_axe_x = axe_x + axe_length;
        u_axe_y = axe_y;
        b_axe_y = axe_y + axe_length;

        //update collision with axe

       collision_with_axe = 
                (b_axe_y >= u_circle_y) && 
                (u_axe_y <= b_circle_y) && 
                (r_axe_x >= l_circle_x) && 
                (l_axe_x <= r_circle_x);

        
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x,axe_y, axe_length, axe_length,RED);
        
        axe_y += direction;

        if(axe_y > 500 || axe_y < 0 ){

            direction = -direction;
        }



        if (IsKeyDown(KEY_D) && circle_x < 470){

            circle_x = circle_x + 5;
        }
        if (IsKeyDown(KEY_A) && circle_x > 30){

            circle_x = circle_x - 5;
        }
        if (IsKeyDown(KEY_W) && circle_y > 30 ){

            circle_y = circle_y - 5;
        }
        if (IsKeyDown(KEY_S)&& circle_y < 470 ){

            circle_y = circle_y + 5;
        }
    
    
    



        // game logic ends
    }

    }



}