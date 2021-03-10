#include <std.h>
#include "../dojo.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(NEW_MOUNTS);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("A small path into the mountains");
    set_short("%^RESET%^%^ORANGE%^A small path into the mountains%^RESET%^");
    set_long("%^CYAN%^This simple path moves at a slight incline, up from the forest into the lower %^BLUE%^mountain"
"%^CYAN%^ rises.  It is surrounded on all sides by thick %^GREEN%^f%^ORANGE%^o%^GREEN%^rest%^CYAN%^, dancing with the surreal lights "
"and whispers of Parnelli.  The trail beneath your feet is strewn with pebbles and cracked %^BOLD%^%^BLACK%^s%^RESET%^ha"
"%^BOLD%^%^BLACK%^le %^RESET%^%^CYAN%^that protrudes from the dirt and undergrowth.  Visibility is fairly limited higher up, "
"though you can see several breaks in the trees that lead further into the heart of the forest.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The thick wooded smell of the forest hangs in the air.%^RESET%^");
    set_listen("default","%^GREEN%^It is quiet here.%^RESET%^");

    set_items(([
      ({"path","trail","pebbles","shale"}) : "%^ORANGE%^The path beneath your feet is relatively unremarkable, scattered with "
"fragments of stone amidst the dirt and undergrowth.  At first it seems like so many other such trails up into the mountains, "
"which tend usually to lead to nowhere, but this one seems a little too well trodden to be accidental.%^RESET%^",
      ({"forest","trees","undergrowth"}) : "%^GREEN%^The dense forest surrounds you on all sides, whispering and sparkling with "
"the fey energies that dance through Parnelli.%^RESET%^",
    ]));
    set_exits(([
      "north" : ROOMS"path5",
      "southeast" : "/d/laerad/parnelli/forest/for025",
      "south" : "/d/laerad/parnelli/forest/for016",
    ]));
}