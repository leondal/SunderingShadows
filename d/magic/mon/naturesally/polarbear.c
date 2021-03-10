// rank 5 beastie
// coded by ~Circe~ 3/25/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"bear","polar bear","natures ally"}));
    set_short("%^BOLD%^%^WHITE%^pol%^CYAN%^a%^WHITE%^r bear%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Standing slightly taller than its "
       "brown bear cousins, this polar bear has the lean, hungry "
       "look of a predator.  Its fur appears to glisten %^RESET%^w"
       "%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e%^BOLD%^ in the light, "
       "shimmering with a faint tra%^RESET%^n%^BOLD%^slu%^CYAN%^c"
       "%^WHITE%^en%^RESET%^c%^BOLD%^e.  The bear's nose and eyes "
       "glitter %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^ck"
       "%^WHITE%^, as do its claws.  Its form is powerful and "
       "intimidating, revealing its nature as a fierce foe.%^RESET%^");
    set_race("polar bear");
    set_body_type("quadruped");
    set_attack_limbs(({"right forepaw","left forepaaw"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^CYAN%^With a mighty roar, the polar bear crushes you in a hug as it bites you viciously!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^CYAN%^With a mighty roar, the polar bear crushes you in a hug as it bites "+target->QCN+" viciously!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}
