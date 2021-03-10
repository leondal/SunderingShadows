#include <std.h>
#include "/d/antioch/areadefs.h"
inherit ROOM;

void create() {
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_climate("arctic");
   set_property("light", 1);
   set_property("indoors", 0);
   set_listen("default","An occasional whisper of wind breaks the heavy silence.");
   set_smell("default","The crisp, chill scent of snow mingles with the earthy smell of stone.");
   set_short("%^WHITE%^A %^WHITE%^n%^WHITE%^a%^BOLD%^%^WHITE%^rrow %^RESET%^%^WHITE%^m%^BOLD%^%^WHITE%^ou%^RESET%^%^WHITE%^n%^WHITE%^t%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^n %^WHITE%^trail%^RESET%^");
   set_long(query_short() + "\n%^CYAN%^This narrow trail comes to an end here, at the foot of a naturally-formed temple nestled between the mountain peaks. The path continues downward, winding between the tall walls of stone to the south. An occasional icy wind whistles through the passageway, chilling you to the bone.\n");
   set_exits(([
                  "south": MOUNT+"trail2",
                  "cave":"/d/antioch/wild/mount/muln/rooms/atrium"
   ]));
   set_items( ([
                   "mountains" : "The mountains extend as far as the eye can see.",
   ]));
}
