#include <cstddef>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"

int main(int argc, char** argv) {

    InitWindow(600, 700, "TODO APP");
    SetTargetFPS(30);

    SetExitKey(KEY_Q);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

    char active_input_buffer[255] = {0};
    std::vector<std::string> tasks;

    while (!WindowShouldClose()) {
        BeginDrawing();

        /*DrawRectangle(100, 35, 85, 85, DARKGREEN);*/
        /**/
        /*DrawTriangle(*/
        /*    (Vector2){ GetScreenWidth() / 4.0f * 3.0f + 60.0f, 80.0f },*/
        /*    (Vector2){ GetScreenWidth() / 4.0f * 3.0f - 60.0f, 150.0f },*/
        /*    (Vector2){ GetScreenWidth() / 4.0f * 3.0f + 60.0f, 150.0f },*/
        /*VIOLET);*/
        /**/
        /*DrawCircle(GetScreenWidth() / 2, 230, 45, DARKBLUE);*/

        ClearBackground(GRAY);

        /*int label_width = MeasureText("TODO App", 30);*/
        /*GuiLabel({10, 10, (float)label_width, 100}, "TODO APP");*/

        const char* title = "Todo List";
        const char* text = "Enter a New Task";

        const char* buttons = "Submit";
        bool secret_view = true;

        int result = GuiTextInputBox(
            {0, 0, 600, 300}, 
            title, text, buttons, 
            active_input_buffer, 255, &secret_view
        );

        if (result == 1)
            tasks.insert(tasks.begin(), std::string(active_input_buffer));
        GuiSetStyle(LABEL, TEXT_COLOR_NORMAL, 0x835d9);

        const int x_offset = 50;
        const int y_offset = 300;
        unsigned short i = 0;
        size_t pos_y = 0;

        while (i < tasks.size()) {
            const float text_width = (float)MeasureText(tasks[i].c_str(), 30);

            GuiLabel(
                {10, (float)(pos_y * 35) + y_offset + 5, text_width, 30}, 
                tasks[i].c_str()
            );

            if (GuiButton({x_offset + 360, (float)(pos_y * 35) + 305, 180, 30}, "Remove"))
                tasks.erase(tasks.begin() + i);
            else
                i++;
            pos_y++;
        }

        EndDrawing();
    }

    return EXIT_SUCCESS;
}
