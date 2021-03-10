// rank 2 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"hippogriff","majestic hippogriff","natures ally"}));
    set_short("%^BOLD%^%^WHITE%^ma%^YELLOW%^j%^WHITE%^estic hippog%^YELLOW%^ri%^WHITE%^ff%^RESET%^");
    set_long("Such a beast as this was said to be the very essence of impossibility, though it seems at one point or "
"another magic ensued its creation.  It bears the hindquarters and tale of a horse, dappled pale chestnut down to its "
"graying hooves.  However, its forelegs, chest and head are all that of a griffin, complete with golden feathers and a "
"massive wingspan that serves to lift the beast at startling speed.  Its talons and hooked beak show clearly that this "
"creature is not one to be trifled with.");
    set_race("hippogriff");
    set_body_type("equine");
    remove_limb("right fore hoof");
    remove_limb("left fore hoof");
    add_limb("wings","torso",0,0,0);
    add_limb("right claws","right foreleg",0,0,0);
    add_limb("left claws","left foreleg",0,0,0);
    set_attack_limbs(({"right claws","left claws"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^Rearing back on its hooves, the hippogriff lashes out at you with both claws!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^Rearing back on its hooves, the hippogriff lashes out at "+target->QCN+" with both claws!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(20)+mylevel);
    TO->remove_property("magic");
}