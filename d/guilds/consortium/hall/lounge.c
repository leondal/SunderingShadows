#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("indoors", 1);
    set_light(2);
    set_short("The Lounge");
    set_long(
   "This is the lounge for the Consortium mage guild.  Here members once came to sit, relax, and to discuss their different adventures of the day.  Instead of chairs and tables as a normal tavern or pub would have, this lounge is filled with cozy padded couches sided with end tables."
    );
    set_listen("default", "Hushed murmers circulate the room.");
    set_smell("default", "Pipe smoke lingers in the air.");
    set_items( ([
      "couches" : "Mmmmm  comfy looking",
      "end table" : "This end table holds the glass of someone too lazy to take it away.",
    ]) );
    set_exits( ([

       "east":"/d/guilds/consortium/hall/main",

    ]) );
}
