// rank 5 beastie
// coded by ~Circe~ 3/25/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"griffon","majestic griffon","natures ally"}));
    set_short("%^RESET%^%^ORANGE%^ma%^MAGENTA%^j%^ORANGE%^es%^YELLOW%^t"
       "%^RESET%^%^ORANGE%^ic gr%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^ff"
       "%^YELLOW%^o%^RESET%^%^ORANGE%^n%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This majestic creature combines the "
       "features of a %^YELLOW%^lion %^RESET%^%^ORANGE%^with those of "
       "an %^BOLD%^%^WHITE%^eagle%^RESET%^%^ORANGE%^.  From the tip of "
       "its %^YELLOW%^hooked beak%^RESET%^%^ORANGE%^ to the %^RED%^tuft "
       "%^ORANGE%^of its slender tail, this griffon measures nearly eight "
       "feet in length.  With the powerful lower body of a lion and the "
       "%^RESET%^f%^BOLD%^e%^RESET%^a%^BOLD%^t%^RESET%^h%^BOLD%^e%^RESET%^"
       "r%^BOLD%^e%^RESET%^d %^BOLD%^h%^RESET%^e%^BOLD%^a%^RESET%^d %^ORANGE%^"
       "and %^BOLD%^%^WHITE%^wings %^RESET%^%^ORANGE%^of an eagle, the beast "
       "looks to be a fearsome foe.%^RESET%^");
    set_race("griffon");
    set_body_type("quadruped");
    add_limb("left talon","left forepaw",0,0,0);
    add_limb("right right talon","right forepaw",0,0,0);
    add_limb("beak","head",0,0,0);
    set_attack_limbs(({"right talon","left talon","beak"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^WHITE%^With a flurry of feathers, the griffon takes to the sky, raking you with its talons!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^WHITE%^With a flurry of feathers, the griffon takes to the sky, raking "+target->QCN+" with its talons!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}