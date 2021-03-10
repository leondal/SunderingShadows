#include <std.h>
#include "../barracks.h";
#include "../../../underdark.h";

inherit "/std/room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light", -3);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_short("%^RESET%^%^BLUE%^The Underdark%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^It is deathly silent here.%^RESET%^");
   set_smell("default","%^RESET%^%^GREEN%^There is no smell.%^RESET%^");
}
