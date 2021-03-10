// rank 4 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"boar","dire boar","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^demo%^RED%^n%^BLACK%^ic-looking dire boar%^RESET%^");
    set_long("This vicious breed of pig bears curved tusks on either side of its snout, able to cause considerable damage "
"at close range.  Stiff bristles of a grizzled gray shade coat its compact, stocky frame.  This particular specimen seems "
"even more vicious than most, with a feral, almost demonic gleam in its dark eyes.");
    set_race("boar");
    set_body_type("quadruped");
    add_limb("tusks","head",0,0,0);
    set_attack_limbs(({"tusks"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^The dire boar charges forward, jerking its head to slash viciously upwards at you!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^The dire boar charges forward, jerking its head to slash viciously upwards at "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(40)+mylevel);
    TO->remove_property("magic");
}