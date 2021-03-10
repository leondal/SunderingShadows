#include "area_stuff.h"
inherit "/d/common/inherit/wpn_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set("short", "Verbobone's Weapon Store Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits((["up": ELROOMS+"weapon_shop"]));
}

void reset() {
  ::reset();
}

