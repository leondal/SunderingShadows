#include <std.h>

inherit "/std/armour";

string OWNER;

void create(){
    ::create();
    set_name("Stone Robe");
    set_id( ({"robe", "stonecloak", "robe of stone", "stone robe" }) );
    set_short("%^BOLD%^Robe of Stone%^RESET%^");
    set_long(
      "   From a distance this cloak looks to be made of a stone resembling granite, but up close it is just made of a hard, grey thread. "
      "As you walk, small amounts of granite dust rub off the cloak and fall to the ground. "
      "There is an inscription on the inside of the robe's clasp. "
    );
    set_weight(15);
    set_value(3500);
    set_type("clothing");
    set_limbs( ({"torso"}) );
    set_ac(1);
    set_property("enchantment",2);
    set_wear( (:this_object(), "extra_wear":));
    set_remove("   The embrace of mother earth leaves you.");
}

void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
    add_action("read_cloak", "read");
    add_action("protect_me","stone");
}

int read_cloak(string str)  {
    if(!str) return notify_fail("read what?\n");
    if(str != "robe" && str != "clasp") return notify_fail("read what?\n");
    write(
      "This cloak was given the strength of the stones by mother earth.  To use that power for yourself, type <stone me>."
    );
    return 1;
}

int extra_wear() {
    if((string)TP->query_name() != OWNER) {
	notify_fail("You have not earned the respect of mother earth.");
   TO->remove();
   return 0;
    }
    write(
      "   You feel as if the stones themself are here to help you."
    );
      return 1;
}

int protect_me(string str)  {
    if(!str) return notify_fail("Protect whom?\n");
    if(str != "me") return notify_fail("Protect whom?\n");
    tell_room(environment(TP), TP->query_cap_name()+" mutters some words under his breath, and the robe he is wearing seems to harden around him.",TP);
    tell_object(TP, "You call upon the power of the robe and mother earth!");
    TP->set_stoneSkinned(20+random(TP->query_lowest_level()));
    TO->remove();
    return 1;
}
