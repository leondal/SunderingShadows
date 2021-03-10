// rank 1 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"rat","dire rat","ragged rat","ragged dire rat","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^rag%^RESET%^ge%^BOLD%^%^BLACK%^d dire rat%^RESET%^");
    set_long("Mangy gray fur, bald in a few spots, coats the hide of this ugly vermin.  The beast is huge, nearly four "
"feet in length to far outstrip the size of any normal rat.  Large ears lie back across its skull, while a hiss reveals "
"a mouth full of wicked fangs.  This particular specimen seems even more vicious than most, with a feral, almost demonic "
"gleam in its dark eyes. ");
    set_race("rat");
    set_body_type("quadruped");
    add_limb("teeth","head",0,0,0);
    set_attack_limbs(({"right forepaw","left forepaw","teeth"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^CYAN%^The rat darts forward, snapping at you with its sharp, grimy teeth!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^CYAN%^The rat darts forward, snapping at "+target->QCN+" with its sharp, grimy teeth!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(10)+mylevel);
    TO->remove_property("magic");
}