//Callamir Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^BOLD%^%^CYAN%^L%^RESET%^u%^BOLD%^%^CYAN%^c%^RESET%^k%^BOLD%^y "+
"%^RESET%^R%^BOLD%^%^CYAN%^a%^RESET%^b%^BOLD%^%^CYAN%^b%^RESET%^i%^BOLD%^t'%^RESET%^s "+
"F%^BOLD%^%^CYAN%^o%^RESET%^o%^BOLD%^%^CYAN%^t%^RESET%^");
        set_short("%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^h%^BOLD%^%^BLUE%^in "+
"%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r %^BOLD%^%^BLUE%^sh"+
"%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^rt sw%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^rd%^RESET%^");
        set_id(({"sword","lucky rabbit's foot","blade","weapon"}));
        set_long("%^BOLD%^%^CYAN%^This thin "+
"%^RESET%^s%^BOLD%^t%^RESET%^il%^BOLD%^le%^RESET%^t%^BOLD%^t"+
"%^RESET%^o%^BOLD%^%^CYAN%^-type blade is a length somewhere in the "+
"middle of a short sword is a dagger. The slender blade is made up of pure "+
"arandur. The hilt is made of %^WHITE%^d%^GREEN%^l%^WHITE%^ar%^GREEN%^u%^WHITE%^n%^CYAN%^, "+
"and is engraved with a running %^WHITE%^r%^RESET%^a%^BOLD%^bb%^RESET%^i%^BOLD%^t%^CYAN%^. "+
"The crossgaurd is made of a %^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^pa%^RESET%^%^ORANGE%^r"+
"%^BOLD%^%^BLACK%^ro%^RESET%^%^ORANGE%^w %^BOLD%^%^CYAN%^in flight, it's %^RESET%^%^ORANGE%^w"+
"%^BOLD%^%^BLACK%^ing%^RESET%^%^ORANGE%^s %^BOLD%^%^CYAN%^wrapped around the blade. ");
        set_damage_type("slashing");
        set_value(0);
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^BOLD%^%^CYAN%^The rabbit on the hilt "+
"%^ORANGE%^g%^CYAN%^l%^GREEN%^o%^CYAN%^w%^ORANGE%^s%^CYAN%^, then hops off "+
"of the hilt and slams into %^WHITE%^"+targ->QCN+"%^RESET%^.");
        tell_object(targ,"%^BOLD%^%^CYAN%^The %^WHITE%^r%^RESET%^ab%^BOLD%^b%^RESET%^i%^BOLD%^t "+
"%^CYAN%^on the hilt of %^GREEN%^"+ETO->QCN+"'s %^ORANGE%^g%^CYAN%^l%^GREEN%^o%^CYAN%^w%^ORANGE%^s"+
"%^CYAN%^, then hops off of the hilt and slams into %^WHITE%^you!%^RESET%^");
        tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The %^WHITE%^r%^RESET%^ab"+
"%^BOLD%^b%^RESET%^i%^BOLD%^t %^CYAN%^on the hilt of %^GREEN%^"+ETO->QCN+"'s "+
"%^CYAN%^sword %^GREEN%^g%^CYAN%^l%^ORANGE%^o%^CYAN%^w%^GREEN%^s%^CYAN%^, then "+
"hops from the hilt and slams into %^WHITE%^"+targ->QCN+"%^RESET%^",({ETO,targ}));


        return random(4)+4;;
   }
}
