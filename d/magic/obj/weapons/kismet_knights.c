//Kismet Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
        set_name("%^BOLD%^%^CYAN%^W%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^a%^WHITE%^ve-T"+
"%^CYAN%^o%^WHITE%^u%^CYAN%^c%^RESET%^%^BLUE%^h%^BOLD%^%^CYAN%^ed %^RESET%^%^BLUE%^B"+
"%^BOLD%^%^CYAN%^l%^WHITE%^a%^RESET%^%^BLUE%^d%^BOLD%^%^CYAN%^e%^RESET%^");
        set_short("%^CYAN%^e%^YELLOW%^t%^RESET%^%^CYAN%^h%^BOLD%^e%^RESET%^%^CYAN%^r"+
"%^YELLOW%^e%^RESET%^%^CYAN%^a%^BOLD%^l %^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v"+
"%^BOLD%^e%^RESET%^r %^CYAN%^l%^YELLOW%^o%^RESET%^%^CYAN%^ngsw%^YELLOW%^or%^RESET%^%^CYAN%^d%^WHITE%^");
        set_id(({"blade","sword","weave-touched blade","weapon"}));
        set_long("%^BOLD%^%^CYAN%^Fashioned out of pure %^WHITE%^s%^RESET%^i"+
"%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^%^CYAN%^, this long sword "+
"shines with a blue-white glow. An %^WHITE%^e%^ORANGE%^t%^CYAN%^h%^WHITE%^e"+
"%^CYAN%^re%^ORANGE%^a%^WHITE%^l %^CYAN%^mesh of silver threads seems to wrap "+
"around the blade, as if infused with the silver metal.  The hilt of the blade is "+
"crafted to look like a %^RESET%^%^BLUE%^s%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^n"+
"%^BOLD%^g%^RESET%^%^BLUE%^b%^CYAN%^i%^BOLD%^r%^RESET%^%^BLUE%^d %^BOLD%^%^CYAN%^in "+
"flight, it's wings wrapped to form a knuckle-guard. A smooth pommel made of a coiled "+
"length of %^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^er %^CYAN%^supports the "+
"%^RESET%^d%^BOLD%^ia%^CYAN%^m%^WHITE%^on%^RESET%^d %^BOLD%^%^CYAN%^set into the base of the sword.%^RESET%^");
        set_value(0);
        set_damage_type("slashing");
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^BOLD%^The silver mesh around the blade blazes with a %^YELLOW%^b"+
"%^CYAN%^r%^WHITE%^i%^CYAN%^g%^ORANGE%^h%^CYAN%^t g%^WHITE%^l%^ORANGE%^o%^CYAN%^w%^RESET%^ as you "+
"slash into %^CYAN%^"+targ->QCN+".%^RESET%^");
        tell_object(targ,"%^BOLD%^The silver mesh around %^ORANGE%^"+ETO->QCN+"'s %^WHITE%^blade blazes "
"w%^RESET%^i%^BOLD%^th a %^YELLOW%^b%^CYAN%^r%^WHITE%^i%^CYAN%^g%^ORANGE%^h%^CYAN%^t g%^WHITE%^l%^ORANGE%^o%^CYAN%^w%^RESET%^ as %^ORANGE%^"+ETO->QS+" %^WHITE%^slashes into %^CYAN%^you%^WHITE%^!%^RESET%^");
        tell_room(environment(ETO),"%^BOLD%^The silver mesh around %^ORANGE%^"+ETO->QCN+"'s %^WHITE%^blade "+
"blazes with a %^YELLOW%^b%^CYAN%^r%^WHITE%^i%^CYAN%^g%^ORANGE%^h%^CYAN%^t g%^WHITE%^l%^ORANGE%^o%^CYAN%^w%^RESET%^ as %^ORANGE%^"+ETO->QS+" %^WHITE%^slashes into %^CYAN%^"+targ->QCN+"%^WHITE%^!%^RESET%^",({ETO,targ}));

        return random(4)+8;
   }
}
