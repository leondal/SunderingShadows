
#include <std.h>
inherit "std/room";
void create() {
  ::create();
    set_properties((["light":1, "indoors":1]));
   set_short("guild storage");
   set_long("guild things are kept here.\n");

}


