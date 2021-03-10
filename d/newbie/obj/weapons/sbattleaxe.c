// had same damage as medium battle axe, noticed by a player so I fixed it
// to be comparable to a hand axe.  Styx 6/30/02
//Updated to inherit from /d/common/obj/weapons - Octothorpe 12/16/09

#include <std.h>

inherit "/d/common/obj/weapon/handaxe.c";

void create(){
   ::create();
   set_id(({"axe", "battle axe", "small axe"}));
   set_name("battle axe");
   set_short("small battle axe");
   set_long("This is a small version of a battle axe with a curved-edge blade.");
   //set_size(1);
   //set_weight(7);
   set_value(10);
   //set_type("slashing");
   //set_prof_type("small axe");
   //set_weapon_speed(7);
   //set_wc(1,6);
   //set_large_wc(1,5);
}

