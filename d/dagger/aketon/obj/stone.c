#include <std.h>

inherit OBJECT;

void create() {
   ::create();
   set_name("stone");
   set_id( ({"stone","skin","sheet"}) );
   set_short("A sheet of stoneskin");
   set_long("This is a sheet of odd looking stoneskin.");
   set_weight(1);
   set_value(100000);
   set_property("magic",1);
   set_property("no animate",1);
   set_property("no steal",1);
}

void init() {
   ::init();
   TP->set_stoneSkinned(1000);
   write("You feel you skin are stone-like hard!");

   TP->set_max_hp(278);
   TP->set_hp(278);
}
