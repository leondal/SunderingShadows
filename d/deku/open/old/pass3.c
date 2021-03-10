#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(LIGHT_FOREST);
    set_travel(FOOT_PATH);
    set_short("%^BOLD%^%^BLACK%^Shadowlord forest");
    set_long(
@KAYLA
%^BOLD%^%^BLACK%^The grounds toward the Fortress rise and fall in a series of soft, rolling downs.  The downs are wrapped in a thick, gray blanket of fog, reducing
clear visibility to a matter of yards.  There is a continual interruption of lightning overhead, turning the thick mist briefly into walls of solid gray but any thunder is lost in the sound of the crashing water of the river to the southwest.
KAYLA
    );
    set_smell("default","The mist carries the smell of death and decay.");
    set_listen("default","Sounds of running water come from the river to the southwest.");
    set_exits(([
       "north" : "/d/deku/open/pass5",
       "south" : "/d/deku/open/pass2"
    ] ));
    set_items(([
    ] ));
}
