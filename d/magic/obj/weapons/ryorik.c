//Ryorik Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^BLUE%^E%^RED%^l%^ORANGE%^e%^CYAN%^m%^WHITE%^e"+
"%^RED%^n%^ORANGE%^t%^BLUE%^a%^WHITE%^l %^CYAN%^S%^RED%^p%^ORANGE%^e"+
"%^RED%^a%^CYAN%^r%^WHITE%^");
        set_short("%^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^ac%^RESET%^k"+
"%^BOLD%^%^BLACK%^en%^RESET%^d %^BOLD%^%^BLACK%^spear %^RESET%^%^ORANGE%^s"+
"%^RED%^w%^BOLD%^%^CYAN%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^CYAN%^l%^RESET%^%^ORANGE%^i"+
"%^RED%^n%^ORANGE%^g %^BOLD%^%^BLACK%^with %^WHITE%^e%^RESET%^%^CYAN%^l%^ORANGE%^e%^RED%^m"+
"%^BLUE%^e%^RED%^n%^CYAN%^t%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^power%^RESET%^");
        set_id(({"spear","small spear","lightning spear","weapon"}));
        set_long("%^BOLD%^%^BLACK%^Blackened charred wood makes up the "+
"shaft of this spear. Scorched into the surface of the wood are "+
"%^RESET%^c%^RED%^h%^BOLD%^%^BLACK%^a%^ORANGE%^o%^RESET%^t%^BOLD%^%^RED%^i"+
"%^RESET%^%^RED%^c %^WHITE%^a%^CYAN%^r%^BOLD%^%^BLACK%^c%^RESET%^h%^BOLD%^%^BLACK%^i"+
"%^RESET%^%^CYAN%^n%^WHITE%^g %^BOLD%^%^BLACK%^patterns, traveling in random directions. "+
"The tip of the spear is made up of crackling %^RESET%^%^RED%^e%^CYAN%^l%^ORANGE%^e%^BLUE%^m"+
"%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^n%^ORANGE%^t%^RED%^a%^CYAN%^l %^BOLD%^%^BLACK%^power. The "+
"mystical spear head %^RESET%^%^BLUE%^r%^BOLD%^%^RED%^a%^BLACK%^n%^RESET%^%^CYAN%^d%^BOLD%^%^BLACK%^o"+
"m%^RED%^l%^BLACK%^y changes shapes, never seeming to settle on one form for long.%^RESET%^");
        set_value(0);
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The spear head %^ORANGE%^f%^RESET%^%^RED%^l"+
"%^BOLD%^a%^ORANGE%^s%^RESET%^%^RED%^h%^YELLOW%^e%^RED%^s %^BLACK%^and bursts into%^RESET%^"+
        " %^BOLD%^%^BLUE%^"+targ->QCN+"%^BLACK%^.%^RESET%^");
        tell_object(targ,"%^BOLD%^%^BLACK%^The crackling %^RESET%^%^RED%^e%^ORANGE%^l"+
"%^BLUE%^e%^ORANGE%^m%^CYAN%^e%^ORANGE%^n%^BLUE%^t%^ORANGE%^a%^RED%^l %^BOLD%^%^BLACK%^tip "+
"of %^ORANGE%^"+ETO->QCN+"%^BLACK%^'s spear %^ORANGE%^f%^RED%^l%^ORANGE%^a%^RESET%^%^RED%^s"+
"%^YELLOW%^h%^RED%^e%^ORANGE%^s %^BLACK%^and bursts into you!%^RESET%^");
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The crackling "+
"%^RESET%^%^RED%^e%^BLUE%^l%^ORANGE%^e%^RED%^m%^CYAN%^e%^RED%^n"+
"%^ORANGE%^t%^BLUE%^a%^RED%^l %^BOLD%^%^BLACK%^tip of %^RESET%^%^ORANGE%^"+ETO->QCN+"%^BOLD%^%^BLACK%^'s "+
"spear %^RED%^f%^ORANGE%^l%^RED%^a%^RESET%^%^RED%^s%^BOLD%^h%^ORANGE%^e%^RED%^s %^BLACK%^and "+
"bursts into %^CYAN%^"+targ->QCN+"%^BLACK%^.%^RESET%^",({ETO,targ}));
     
        return random(4)+8;
   }
}
