// rank 6
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","bear","dire bear"}));
    set_short("%^RESET%^%^BOLD%^%^BLACK%^dire %^RED%^bear%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This creature is larger than an "
        "ordinary bear, with a more pronounced bulge of muscle over its "
        "shoulders.  Thick, ragged bro%^RED%^w%^ORANGE%^ni%^RED%^s"
        "%^ORANGE%^h-%^RED%^r%^ORANGE%^ed fur covers the whole of "
        "his several thousand pound bulk.  The "
        "dire bear looks as if it could rend steel with its long claws.");
    set_race("dire bear");
    set_body_type("quadruped");
    set_fake_limbs(({"head","torso","right front leg","right rear leg","left front leg","left rear leg","right claw","left claw","maw" }));
    set_attack_limbs(({"maw","right claw","left claw"}));
    set_base_damage_type("slashing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^RESET%^%^RED%^With a mighty %^BOLD%^roar%^RESET%^%^RED%^, the dire bear viciously mauls you!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^RED%^With a mighty %^BOLD%^roar%^RESET%^%^RED%^, the dire bear viciously mauls "+target->QCN+"!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(60)+mylevel);
    TO->remove_property("magic");
}