#include <std.h>

// inherit WEAPON;
inherit "/d/common/obj/weapon/mspear.c";

void create(){
   ::create();
   set_name("spear");
   set_id( ({"spear"}) );
   set("short","Spear");
   set("long","This is a medium spear with a very sharp point and serrated edge "
        "on the metal attached to the tip.  The wooden shaft is hewn to provide "
        "an excellent grip and make it a quite effective weapon.");
//   set_type("piercing");
//   set_prof_type("medium spear");
   set_wc(1,8);
   set_large_wc(1,12);
//   set_size(2);
//   set_weight(6);
   set_property("enchantment",3);
   set_value(500);
}
