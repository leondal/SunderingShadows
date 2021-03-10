//  Created by Demonforce, for ShadowGate
//  Coded 20 November, 1995
//  Nymph Armor

inherit "/std/armour";

void create() {
    ::create();
set_name("barkback");
  set("id", ({
"barkback", "bark", "armor", "armour"
    }) );
   set_property("monsterweapon",1);
  set("short",
"A thin barkback"
     );
    set("long", 
"This is the bark from a nymph.  It should give you a lot of protection
.\n"
       );
    set_weight(15);
set("value", 20);
set_limbs( ({ "torso", "left leg", "left arm", "right leg", "right arm"}) );
  set_ac(12);
}
