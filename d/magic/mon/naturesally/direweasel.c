// rank 3 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"wolf","dire weasel","feral weasel","feral dire weasel","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^fe%^RESET%^ra%^ORANGE%^l dire w%^RED%^e%^ORANGE%^asel%^RESET%^");
    set_long("The small predator before you has a long, slender body with short legs and a pointed, whiskered snout.  "
"Mostly of a chestnut-brown coat, it bears a stripe of white along the length of its underside and tail.  Though small, "
"such beasts are known for their guile in stalking prey.  This particular specimen seems even more vicious than most, "
"with a feral, almost demonic gleam in its dark eyes.");
    set_race("wolf");
    set_body_type("quadruped");
    add_limb("teeth","head",0,0,0);
    set_attack_limbs(({"teeth"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^CYAN%^The weasel latches onto you and sinks its sharp teeth into your skin!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^CYAN%^The weasel latches onto "+target->QCN+" and sinks its sharp teeth into "+target->QP+" skin!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(30)+mylevel);
    TO->remove_property("magic");
}