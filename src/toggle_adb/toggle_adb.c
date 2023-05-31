#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <msettings.h>

#include "defines.h"
#include "utils.h"
#include "api.h"

int main(int argc, char* argv[]) {
    POW_setCPUSpeed(CPU_SPEED_MENU);

    SDL_Surface* screen = GFX_init(MODE_MAIN);
    POW_init();
    InitSettings();

    SDL_Event event;
    int quit = 0;
    int save_changes = 0;
    int adb_enabled = 0;

    // Show confirmation message
    // GFX_blitHardwareGroup(screen, show_setting);
    FILE *file = fopen(ADB_FLAG_PATH, "r");
    if (file) {
		adb_enabled = 1;
		GFX_blitMessage(font.large, "ADB is currently enabled\nDisable and reboot?", screen, NULL);
		GFX_blitButtonGroup((char*[]){ "B","CANCEL", "A","DISABLE", NULL }, screen, 1);
    } else {
		GFX_blitMessage(font.large, "ADB is not enabled\nEnable and reboot?", screen, NULL);
		GFX_blitButtonGroup((char*[]){ "B","CANCEL", "A","ENABLE", NULL }, screen, 1);
    }
    
    GFX_flip(screen);

    // Wait for user's input
    while (!quit) {
        PAD_poll();
        if (PAD_justPressed(BTN_A)) {
            save_changes = 1;
            quit = 1;
        } else if (PAD_justPressed(BTN_B)) {
            quit = 1;
        } else {
            GFX_sync();
        }
    }

    // Execute main program based on user's input
    if (save_changes) {
        if (!adb_enabled){
		  fclose(fopen(ADB_FLAG_PATH, "w"));
		} else {
		  remove(ADB_FLAG_PATH);
		}
        LOG_info("Rebooting to save changes\n");
        POW_reboot();
    }

    QuitSettings();
    POW_quit();
    GFX_quit();
	
    return EXIT_SUCCESS;
}
