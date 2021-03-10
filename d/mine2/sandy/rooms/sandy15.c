#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, south road");
    set_long(""
"%^BOLD%^WHITE%^You are on a paved road.\n%^RESET%^"
"You are on the south road of Sandy.  This road leads to many different places.  "
"There is a large gold road to the east, which winds around a few bends, and "
"leads to who knows where.  To the west is the center of Sandy, where all the "
"local people meet to talk about many things of great importance to them.  "
"To the south, are many buildings, which may be to very helpfull to you. "
""
"");

     set_listen("default","You hear people talking to the north.");
     set_smell("default","The smell nothing strange.");
    set_exits(([
       "north" : "/d/mine2/sandy/room/sandy14",
       "south" : "/d/mine2/sandy/room/sandy16",
       "east" : "/d/mine2/sandy/room/sandy7",

    ] ));
    set_items(([
         "gold road" : "It is made out of gold, so the owners must be rich people.",
         "road" : "This road is a nicly paved road.",
         "buildings" : "They are in great number, to help you.",
         "town" : "The town is very busy.",
    ] ));
}
