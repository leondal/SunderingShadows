#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_name("tines");
   set_id( ({"tines"}) );
   set_short( "tines");
   set_long("A forks tines.");
   set_type("slashing");
   set_wc(2,7);
   set_value(7);
set_weight(1);
set_property("monsterweapon", 1);
}
