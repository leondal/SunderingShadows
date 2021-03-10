/* need this to have the Offestry exit as an option for non-newbies that are still under level 7 - Styx 5/18/03  
I tried adding the exit in init based on level but it bugged if there was someone else above level 7 in the room because it would re-init and loop back and forth adding and removing the exit
*/

#include <std.h>

#define OFFESTRY_CHURCH "/d/newbie/rooms/town/church"
inherit "/d/shadowgate/death/death_exit.c";

void create() {
    ::create();
    add_exit(OFFESTRY_CHURCH, "offestry");
}