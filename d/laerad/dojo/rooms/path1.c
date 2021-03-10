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
    set_long("%^CYAN%^This simple path winds its way higher into the %^BLUE%^mountains%^CYAN%^, surrounded on all sides by "
"sparse %^GREEN%^f%^ORANGE%^o%^GREEN%^rest %^CYAN%^and jagged outcroppings of rock.  The trail beneath your feet is strewn "
"with pebbles and cracked %^BOLD%^%^BLACK%^s%^RESET%^ha%^BOLD%^%^BLACK%^le %^RESET%^%^CYAN%^that protrudes from the dirt and "
"undergrowth.  Visibility is limited except to the south, where the ascent of the path allows a view out over the tops of the "
"Parnelli forest for some distance.  Just up ahead to the northeast, you can make out what appears to be a larger %^RESET%^"
"clearing%^CYAN%^.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The thick wooded smell of the forest hangs in the air.%^RESET%^");
    set_listen("default","%^GREEN%^It is quiet here.%^RESET%^");

    set_items(([
      ({"path","trail","pebbles","shale"}) : "%^ORANGE%^The path beneath your feet is relatively unremarkable, scattered with "
"fragments of stone amidst the dirt and undergrowth.  At first it seems like so many other such trails up into the mountains, "
"which tend usually to lead to nowhere, but this one seems a little too well trodden to be accidental.%^RESET%^",
      ({"forest","trees","undergrowth"}) : "%^GREEN%^The forest still surrounds you on all sides, though it is a little more "
"sparse here, perhaps struggling to grow as the earth grows more rocky this far up the mountainside.  Through the trees to the "
"south, you can see out over the top of part of Parnelli forest, where a little ways to the southeast rise the tiny spires and "
"towers of Asgard.%^RESET%^",
      "clearing" : "%^CYAN%^Just a little further up, the trees seem to part in a clearing of sorts.%^RESET%^",
    ]));
    set_exits(([
      "north" : ROOMS"garden",
      "southeast" : ROOMS"path2",
    ]));
}