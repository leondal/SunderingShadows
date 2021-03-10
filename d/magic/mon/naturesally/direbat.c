// rank 2 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"bat","dire bat","fierce bat","fierce dire bat","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^f%^RED%^i%^BLACK%^erce dire b%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^");
    set_long("This flighted mammal bears the appearance of a rodent with wings, its large black ears protruding above a "
"pointed face furred with lighter russet hairs.  Its wingspan alone is nearly fifteen feet when fully spread, each "
"leathery black wing threaded with thin bones that provide support and structire.  This particular specimen seems even "
"more vicious than most, with a feral, almost demonic gleam in its dark eyes.");
    set_race("bat");
    set_body_type("quadruped");
    add_limb("teeth","head",0,0,0);
    add_limb("wings","torso",0,0,0);
    add_limb("right claws","right forepaw",0,0,0);
    add_limb("left claws","left forepaw",0,0,0);
    set_attack_limbs(({"teeth","right claws","left claws"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The bat dives suddenly upon you from above, letting out an earsplitting shriek!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The bat dives suddenly upon "+target->QCN+" from above, letting out an earsplitting shriek!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(20)+mylevel);
    TO->remove_property("magic");
}