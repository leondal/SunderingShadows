// rank 6
#include <std.h>


inherit "/d/magic/mon/naturesally/natureally.c";


void create()
{
    ::create();
    set_id(({"natures ally","salamander"}));
    set_short("%^RESET%^%^RED%^sm%^YELLOW%^o%^RESET%^%^RED%^ld%^BOLD%^e%^RESET%^%^RED%^ring s%^YELLOW%^a%^RESET%^%^RED%^la%^BOLD%^m%^RESET%^%^RED%^an%^ORANGE%^d%^RED%^er%^RESET%^");
    set_long("%^RESET%^%^RED%^This serpentine creature stands "
       "over eight feet tall, even with an equally long tail "
       "trailing behind.  Its scales %^BOLD%^g%^YELLOW%^l%^RESET%^"
       "%^ORANGE%^i%^RED%^s%^BOLD%^t%^YELLOW%^e%^RESET%^%^ORANGE%^n "
       "%^BOLD%^%^RED%^red %^RESET%^%^RED%^in the light, making it "
       "seem slimy despite the faint hint of %^BOLD%^%^BLACK%^smoke "
       "%^RESET%^%^RED%^that rises on the air around it.  Despite "
       "its snake-like resemblance, the creature has two arms near "
       "where a human's would be, though both are covered in the "
       "same %^BOLD%^red scales%^RESET%^%^RED%^.  Wielding a "
       "%^BOLD%^f%^YELLOW%^i%^WHITE%^e%^YELLOW%^r%^RED%^y%^RESET%^%^RED%^ "
       "spear, this creature attacks all enemies with zeal.%^RESET%^");
    set_race("salamander");
    set_body_type("human");
    set_fake_limbs(({"head","torso","mouth","right arm","left arm","tail"}));
    set_attack_limbs(({"mouth","right arm","left arm"}));
    set_base_damage_type("slashing");
}


void my_special(object target) 
{
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^RED%^The salamander impales you with its spear!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^RED%^The salamander impales "+target->QCN+" with its spear!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(60)+mylevel);
    TO->remove_property("magic");
}