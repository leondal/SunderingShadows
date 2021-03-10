#include <std.h>
inherit "d/common/obj/brewing/oils/weapon_oil_inherit.c";

void create() {
    ::create();
    set_name("frost oil");
    set_id(({"jar","liquid","oil","frost oil"}));
    set_obvious_short("%^BOLD%^%^WHITE%^A small jar of %^CYAN%^fr%^WHITE%^o%^CYAN%^sty %^WHITE%^liquid");
    set_short("%^BOLD%^%^CYAN%^Fr%^WHITE%^o%^CYAN%^st %^WHITE%^O%^CYAN%^i%^WHITE%^l%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This long, slender vial is cold to the touch and seems to "
    "constantly be surrounded by a thin veil of %^CYAN%^frosty h%^RESET%^a%^BOLD%^%^CYAN%^ze"
    "%^WHITE%^.  The liquid inside constantly %^CYAN%^sw%^RESET%^%^CYAN%^i%^BOLD%^rls %^WHITE%^"
    " as though within the bottle an eternal %^BLACK%^bl%^RESET%^i%^BOLD%^z%^CYAN%^z"
    "%^WHITE%^a%^RESET%^r%^BOLD%^%^BLACK%^d%^WHITE%^ were at"
    " war to escape.  An elegant square %^RESET%^cr%^BOLD%^y%^RESET%^stal %^BOLD%^stopper keeps"
    " the liquid within.%^RESET%^");
    set_lore("Stories abound about the mysterious frost oil, but there is no "
       "single definitive legend counted as true. The most credible is that an "
       "apprentice to Tiergaina the Enchantress crafted the first stable frost oil "
       "sometime after the first War of Intruder. Sadly, the apprentice's name has "
       "been lost to time, thought he process survived.");
//Lore added by ~Circe~ after bug reports. Feel free to change it if this doesn't fit.
    reversed = 0; 

}

int apply(string str) {
    object target;
    if(!objectp(TO) || !objectp(ETO)) return 0;
    if(!objectp(target = ::apply(str, 1))) return 1;

    tell_object(ETO, "%^RESET%^%^BOLD%^You turn the jar up and the fluid seems eager to "
        "engulf your "+target->query_short()+" %^BOLD%^%^WHITE%^with it's"
        " %^CYAN%^fr%^WHITE%^o%^CYAN%^sty %^WHITE%^touch.%^RESET%^");
    tell_room(EETO,"%^RESET%^%^BOLD%^"+ETO->QCN+" pours some %^CYAN%^fr%^WHITE%^o%^CYAN%^sty"
        " %^BOLD%^%^WHITE%^liquid out of a jar and onto "+ETO->QP+" "+target->query_short()+".",ETO);

    if(reversed) {
      tell_object(ETO,"%^WHITE%^Your "+target->query_short()+" is completely coated "
        "in the glowing goo before it hisses and fizzles away into nothing, leaving "
        "only an unpleasantly acrid smell behind.");
      tell_room(EETO,"%^BOLD%^%^WHITE%^The liquid on "+ETO->QCN+"'s "+target->query_short()+" "
        "%^BOLD%^%^WHITE%^hisses and fizzles away into nothing, leaving only an unpleasantly"
        " acrid smell behind.", ETO);
    }
    else  {
      tell_object(ETO, "%^BOLD%^%^WHITE%^Your "+target->query_short()+" %^BOLD%^%^WHITE%^is"
        " completely coated in the %^CYAN%^fr%^WHITE%^o%^CYAN%^sty %^WHITE%^liquid before it"
        " %^CYAN%^ices %^WHITE%^over!");
      tell_room(EETO,"%^BOLD%^%^WHITE%^The liquid on "+ETO->QCN+"'s "+target->query_short()+" "
        "%^BOLD%^%^CYAN%^ices %^WHITE%^over!%^RESET%^", ETO);
      target->set_property("oiled","damage bonus cold 5");
      target->remove_property("added short string");
      target->set_property("added short string",({" %^BOLD%^%^WHITE%^{{%^CYAN%^FROSTY%^WHITE%^}}%^RESET%^"}));
      target->set_property("added short",target->query_property("added short string"));

    }
    TO->remove();
    return 1;
}

void set_reversed(int mystatus) { reversed = mystatus; }