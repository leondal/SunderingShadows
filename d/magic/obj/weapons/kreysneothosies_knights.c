//Kreysneothosies Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
        set_name("%^YELLOW%^Blade of %^RED%^B%^CYAN%^r%^ORANGE%^av%^CYAN%^e%^ORANGE%^r%^RED%^y%^RESET%^");
        set_short("%^BOLD%^%^CYAN%^g%^ORANGE%^l%^WHITE%^e%^ORANGE%^a%^CYAN%^m%^ORANGE%^i"+
"%^WHITE%^ng %^RESET%^t%^BOLD%^ita%^RESET%^n%^BOLD%^iu%^RESET%^m %^BOLD%^blade%^RESET%^");
        set_id(({"blade","blade of bravery","sword", "weapon"}));
        set_long("%^BOLD%^This %^RESET%^g%^BOLD%^lea%^RESET%^m%^BOLD%^i"+
"%^RESET%^n%^BOLD%^g white blade is shaped from pure titanium. The "+
"one handed bastard sword is neither slender or thick, but somehow a perfect "+
"balance between the two. A yellow %^RESET%^%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^ld "+
"%^BOLD%^%^WHITE%^figurine forms the pommel and handle of this divine blade. This figure "+
"is in the shape of a gold dragon. The head of the %^ORANGE%^dr%^RESET%^%^ORANGE%^ag%^BOLD%^on "+
"%^WHITE%^rest upon the blade, with its claws curling outwards. %^RESET%^%^BLUE%^B%^BOLD%^l"+
"%^RESET%^%^BLUE%^u%^BOLD%^e %^RESET%^%^BLUE%^s%^BOLD%^ap%^RESET%^%^BLUE%^ph%^BOLD%^i"+
"%^RESET%^%^BLUE%^re%^BOLD%^s %^WHITE%^have been inlaid into the eyes of the dragon. The "+
"white blade s%^ORANGE%^h%^WHITE%^in%^ORANGE%^e%^WHITE%^s brightly in the light, almost as "+
"it was a %^ORANGE%^b%^WHITE%^eaco%^ORANGE%^n%^WHITE%^.%^RESET%^");
        set_value(0);
        set_damage_type("slashing");
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^BOLD%^%^RED%^You %^RESET%^%^RED%^s%^YELLOW%^l%^RED%^a%^RESET%^%^ORANGE%^s%^BOLD%^%^RED%^h "+
"%^ORANGE%^the %^WHITE%^b%^ORANGE%^l%^RED%^a%^ORANGE%^d%^WHITE%^e %^ORANGE%^through %^WHITE%^"+targ->QCN+"%^ORANGE%^, with "+
"a steady and true hand.%^RESET%^");
        tell_object(targ,"%^BOLD%^"+ETO->QCN+" %^RESET%^%^RED%^s%^YELLOW%^l%^RED%^a%^RESET%^%^ORANGE%^s"+
"%^BOLD%^%^RED%^h%^ORANGE%^e%^RESET%^%^RED%^s %^BOLD%^%^WHITE%^"+ETO->QP+"'s %^ORANGE%^b%^WHITE%^l"+
"%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^d%^ORANGE%^e through %^RESET%^%^RED%^you %^YELLOW%^with a steady "+
"and true hand!%^RESET%^");
        tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" %^RED%^sl%^ORANGE%^a%^RESET%^%^ORANGE%^s%^RED%^h"+
"%^YELLOW%^e%^RED%^s %^WHITE%^"+ETO->QP+"'s b%^ORANGE%^l%^RESET%^%^ORANGE%^a%^BOLD%^d%^WHITE%^e "+
"%^ORANGE%^through %^RESET%^%^RED%^"+targ->QCN+" %^YELLOW%^with a steady and true hand.%^RESET%^",({ETO,targ}));

        return random(4)+8;
   }
}
