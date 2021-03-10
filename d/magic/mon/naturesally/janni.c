// rank 5 beastie
// coded by ~Circe~ 4/27/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"janni","genie","natures ally"}));
    set_short("%^RESET%^%^CYAN%^a p%^RESET%^o%^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^er%^GREEN%^f%^CYAN%^ul j%^RESET%^a%^CYAN%^n%^BOLD%^n%^RESET%^%^CYAN%^i%^RESET%^");
    set_long("%^RESET%^%^CYAN%^At first glance, this "
       "creature appears to be a bare-chested human "
       "dressed in flowing pants of %^ORANGE%^gold silk "
       "%^RESET%^%^CYAN%^with a matching %^ORANGE%^turban "
       "%^CYAN%^atop his head.  A closer look reveals "
       "violent %^BOLD%^wi%^BLACK%^n%^CYAN%^dst%^BLACK%^o"
       "%^CYAN%^rms %^RESET%^%^CYAN%^where his eyes should "
       "be and hints of %^GREEN%^green scales %^CYAN%^in "
       "patches on his skin.  Although they are are known "
       "to be the weakest of the genies, janni are composed "
       "of all four elements and are fearsome foes in their own right.%^RESET%^");
    set_race("genie");
    set_gender("male");
    set_body_type("humanoid");
    set_attack_limbs(({"right hand","left hand"}));
    set_base_damage_type("bludgeoning");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_room(ETO,"%^YELLOW%^With a flash of light, the janni vanishes!%^RESET%^");
    tell_object(target,"%^BOLD%^%^WHITE%^Janni stabs you in the back!%^RESET%^");
    tell_room(ETO,"%^RESET%^%^ORANGE%^The janni reappears just behind "+target->QCN+".\n"
       "%^RESET%^%^BOLD%^You see Janni plunge a deep blow into "+target->QCN+"'s back.%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}