#include <std.h>
inherit "d/common/obj/brewing/oils/weapon_oil_inherit.c";

int reversed;

void create() {
    ::create();
    set_name("wizard oil");
    set_id(({"jar","liquid","oil","wizard oil"}));
    set_obvious_short("%^CYAN%^A softly glowing jar of liquid%^RESET%^");
    set_short("%^CYAN%^W%^RESET%^i%^BOLD%^z%^CYAN%^a%^RESET%^r%^BOLD%^d%^RESET%^%^BOLD%^%^BLUE%^ oil%^RESET%^");
    set_long("%^RESET%^%^BOLD%^This jar is nearly as large as a small human head.  It is a "
        "square shape with a narrow neck that tapers up to a corked top.  "
        "Inside the jar an oozing %^CYAN%^blue liquid%^RESET%^%^BOLD%^ rolls back and forth as it is "
        "tilted.  The %^BLUE%^liquid%^RESET%^%^BOLD%^ seems to never actually touch the insides of the "
        "fortified glass but is kept apart from it by forces unknown.%^RESET%^");
    set_lore("%^CYAN%^It was said that the human mage Glanderia Linstad was so impressed by "
        "the tactics of an elven blade master that she witnessed in battle that she spent "
        "the next several years of her life researching a spell that would allow her "
        "to mimic their abilities.  She was never fully successful in her endeavor but she "
        "was able to create a magical oil, that when applied to a weapon, would impart the "
        "wielder with the ability to make the necessary gestures with their free hand which "
        "are necessary in shaping many divine, arcane and even psionic abilities.");
    set_weight(10);
    set_value(15000);
    reversed = 0;
}

int apply(string str) 
{
    object target;

    if(!objectp(TO) || !objectp(ETO)) return 0;
    if(!objectp(target = ::apply(str, 1))) return 1; //passing 1 here requires weapon only 

    tell_object(ETO,"%^CYAN%^You turn the jar up and the fluid seems to ooze out "
        "onto your "+target->query_short()+" of it's own accord.");
    tell_room(EETO,"%^CYAN%^"+ETO->QCN+" pours some glowing blue liquid out of a "
        "jar and onto "+ETO->QP+" "+target->query_short()+".",ETO);

    if(reversed) {
      tell_object(ETO,"%^BLUE%^Your "+target->query_short()+" is completely coated "
        "in the glowing goo before it hisses and fizzles away into nothing, leaving "
        "only an unpleasantly acrid smell behind.");
      tell_room(EETO,"%^BLUE%^The liquid on "+ETO->QCN+"'s "+target->query_short()+" "
        "hisses and fizzles away into nothing, leaving only an unpleasantly acrid "
        "smell behind.", ETO);
    }
    else  {
      tell_object(ETO,"%^BLUE%^Your "+target->query_short()+" is completely coated "
        "in the glowing goo before the liquid is absorbed into the material.");
      tell_room(EETO,"%^BLUE%^The liquid on "+ETO->QCN+"'s "+target->query_short()+" "
        "is quickly absorbed into the material.", ETO);
      target->set_property("able to cast",1);
    }
    TO->remove();
    return 1;
}

void set_reversed(int mystatus) { reversed = mystatus; }