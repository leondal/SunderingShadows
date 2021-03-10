// rank 3 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"lion","ferocious lion","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^ferocious lion%^RESET%^");
    set_long("Powerful muscles ripple beneath the golden coat of this sleek feline, coiled and ready to pounce in an "
"instant.  A tufted tail-tip matches the russet shade of its shaggy mane, framing a predator's face with sharp eyes and a "
"mouth of sharper fangs.  Its lip draws back in an occasional rumbled snarl, its paws flexing to reveal deadly claws "
"sheathed within.");
    set_race("lion");
    set_body_type("quadruped");
    add_limb("left claws","left forepaw",0,0,0);
    add_limb("right claws","right forepaw",0,0,0);
    set_attack_limbs(({"right claws","left claws"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^YELLOW%^Its haunches bunch and suddenly the lion springs forward, sinking its fangs into your arm!%^RESET%^");
    tell_room(ETO,"%^YELLOW%^Its haunches bunch and suddenly the lion springs forward, sinking its fangs into "+target->QCN+"'s arm!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(30)+mylevel);
    TO->remove_property("magic");
}