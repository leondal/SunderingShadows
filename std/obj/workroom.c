//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The workroom of a new immortal");
    set("night long", "It is night outside.\nA new immortal works here.\n");
    set("day long", "It is day outside.\nA new immortal works here.\n");
    set_exits( ({ "/d/shadowgate/adv_main" }), ({ "hall" }) );
    set_items((["item" : "This is an item in your room." ]));
    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");
}
