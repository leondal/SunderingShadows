//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Guardsman armor

inherit "/std/armour";

void create() {
    ::create();
    set_name("saddle");
    set ( "id",
        ({"saddle", "leather saddle" })
        );
    set("short", "Leather saddle");
    set("long", 
       "The saddle of a horse.\n"
       );
    set_weight(20);
    set("value", 3);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(2);
}
