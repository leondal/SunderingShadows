#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_name("Magistrate's Southern Road");
    set_short("%^RESET%^%^ORANGE%^M%^GREEN%^a%^ORANGE%^gist%^GREEN%^r%^ORANGE%^ate'%^GREEN%^s %^ORANGE%^So%^GREEN%^u%^GREEN%^t%^ORANGE%^hern %^ORANGE%^Road%^RESET%^");
set_long(
@THORN
%^RESET%^%^ORANGE%^M%^GREEN%^a%^ORANGE%^gist%^GREEN%^r%^ORANGE%^ate'%^GREEN%^s %^ORANGE%^So%^GREEN%^u%^GREEN%^t%^ORANGE%^hern %^ORANGE%^Road%^RESET%^
%^GREEN%^The forest seems very close now. From here, you see that the forest is very imposing in both size and spread.  The road seems to be almost swallowed by the dark mass of trees ahead.
THORN
);
    set_smell("default","The scent of pine is heavy in the air.");
    set_listen("default","Occasional bursts of laughter and song pierce the silence.");
    set_exits(
              (["northeast" : "/d/darkwood/room/road5",
                "south" : "/d/darkwood/room/road7",]) );
}
