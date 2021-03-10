//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Guardsman armor

inherit "/std/armour";

void create() {
    ::create();
    set_name("chestplate");
    set ( "id",
        ({ "armor", "chestplate", "guardsmans armor" })
        );
    set("short", "Guardsmans armor");
    set("long", 
       "This armor belongs to a member of the village guard.\n"
       );
    set_weight(10);
    set("value", 9);
    set_type("armor");
    set_limbs( ({ "torso" }) );
    set_ac(5);
}
