#include <std.h>
#include "../dragon.h";

inherit BGRAVE;


void create() {
   ::create();
   set_property("light",0);
   set_property("indoors",0);
   set_short("Graveyard of Sanctuary");
   set_long(
      "%^BOLD%^%^BLUE%^You are within the city's graveyard. Old tombstones are strewn about in"+
      " a haphazard fashion. Most were placed here ages ago, and only a few still"+
      " now have writing or dates that can be made out. It seems unusually dark"+
      " and gloomy here, because of the overwhelming shadow of the church. To"+
      " the south you see the huge hole that leads to the Temple of Alphonsus, and to"+
      " the east are signs of a large iron fence that once divided the graveyard from the city."
   );
   set_exits(([
      "north" : TOWN+"grave6",
      "hole" : TOWN+"church"
   ] ));
   set_items(([
   ] ));
}
