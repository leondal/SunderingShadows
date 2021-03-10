//  Created by Ignatius, for ShadowGate
//  Coded 19 February, 1995
//  Village guard robes

inherit "/std/armour";

void create() {
    ::create();
    set_name("robe");
      set("id", ({ "robe", "armor" }) );
    set("short", "A robe");
    set("long", 
       "This robe seems made for members of the village guard of Antioch. "
       " It is oddly free of dirt and grime, and seems to almost glow with "
       "strength.\n"
       );
    set_weight(10);
    set("value", 17);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
       set_ac(2);
}
