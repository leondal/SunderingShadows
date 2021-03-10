// rank 5 beastie
// coded by ~Circe~ 4/27/13
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"nixie","sprite","natures ally"}));
    set_short("%^RESET%^%^CYAN%^a slender n%^GREEN%^i%^CYAN%^x%^BOLD%^i%^RESET%^%^CYAN%^e%^RESET%^");
    set_long("%^RESET%^%^CYAN%^This slim sprite is clothed in a dress "
       "woven from %^BOLD%^c%^BLUE%^o%^GREEN%^l%^YELLOW%^o%^CYAN%^r"
       "%^GREEN%^f%^BLUE%^u%^YELLOW%^l %^GREEN%^seaweed%^RESET%^%^CYAN%^.  "
       "Strands of %^RESET%^s%^BOLD%^e%^RESET%^a%^BOLD%^s%^MAGENTA%^h"
       "%^RESET%^e%^BOLD%^l%^RESET%^l%^BOLD%^s %^RESET%^%^CYAN%^and "
       "%^BOLD%^%^WHITE%^pe%^CYAN%^a%^WHITE%^rls%^RESET%^%^CYAN%^ have "
       "been woven into her %^GREEN%^gre%^BOLD%^e%^RESET%^%^GREEN%^n "
       "ha%^BOLD%^i%^RESET%^%^GREEN%^r%^CYAN%^, which echoes the %^GREEN%^"
       "greenish hue %^CYAN%^of her lightly scaled skin.  Her wide %^BOLD%^"
       "aqua eyes %^RESET%^%^CYAN%^are filled with fury, likely at being "
       "called so far from her lake home.%^RESET%^");
    set_race("nixie");
    set_gender("female");
    set_body_type("human");
    set_attack_limbs(({"right hand","left hand"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^CYAN%^The nixie lashes out, slashing you with her claw-like fingernails!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^CYAN%^The nixie lashes out, slashing "+target->QCN+" with her claw-like fingernails!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(50)+mylevel);
    TO->remove_property("magic");
}