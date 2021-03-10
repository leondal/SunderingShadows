//  Created by Demonforce, for ShadowGate
//  Coded 20 November, 1995

inherit "/std/armour";

void create() {
    ::create();
    set_name("shadowscale");
  set_id(({"armor","scale","shadowscale"}));
    set_short("a suit of shadowscale armor");
    set("long", "This armor is the only armor that can protect a black demon.\n");
    set_weight(15);
set("value", 200);
    set_limbs(({"torso"}));
    set_ac(2);
}
