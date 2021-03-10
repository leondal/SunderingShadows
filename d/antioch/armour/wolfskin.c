//  Created by Ignatius, for ShadowGate
//  Coded 04 March, 1995
//  Wolf Armor

inherit "/std/armour";

void create() {
    ::create();
    set_name("wolfskin");
  set("id", ({
    "wolkskin", "armor", "armour"
    }) );
  set("short",
      "A grimy wolfskin"
     );
    set("long", 
      "This is the skin of a wolf.  You guess it provides SOME protection "
      "from attack.\n"
       );
    set_weight(15);
    set("value", 4);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(1);
}
