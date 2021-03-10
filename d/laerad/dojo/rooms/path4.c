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
    set_long("%^CYAN%^This simple path moves at a moderate incline now, as it makes its way higher into the %^BLUE%^mountains"
"%^CYAN%^.  It is still surrounded on all sides by thick %^GREEN%^f%^ORANGE%^o%^GREEN%^rest%^CYAN%^, though the foliage seems to be "
"thinning somewhat as you travel higher.  The trail beneath your feet is strewn with pebbles and cracked %^BOLD%^%^BLACK%^s"
"%^RESET%^ha%^BOLD%^%^BLACK%^le %^RESET%^%^CYAN%^that protrudes from the dirt and undergrowth.  Visibility is fairly limited, "
"except as the path continues in either direction.  Only a little further up, a looming outcropping of stone overhangs the "
"path.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The thick wooded smell of the forest hangs in the air.%^RESET%^");
    set_listen("default","%^GREEN%^It is quiet here.%^RESET%^");

    set_items(([
      ({"path","trail","pebbles","shale"}) : "%^ORANGE%^The path beneath your feet is relatively unremarkable, scattered with "
"fragments of stone amidst the dirt and undergrowth.  At first it seems like so many other such trails up into the mountains, "
"which tend usually to lead to nowhere, but this one seems a little too well trodden to be accidental.%^RESET%^",
      ({"forest","trees","undergrowth"}) : "%^GREEN%^The dense forest still surrounds you on all sides, though it seems to be "
"thinning somewhat, perhaps struggling to grow as the earth grows more rocky this far up the mountainside.%^RESET%^",
      "outcropping" : "%^ORANGE%^A short way further up, the path curves away beneath an outcropping of rock and is lost to "
"view.%^RESET%^",
    ]));
    set_exits(([
      "northeast" : ROOMS"path3",
      "southwest" : ROOMS"path5",
    ]));
}