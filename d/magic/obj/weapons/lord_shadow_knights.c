//Lord Shadow Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
        set_name("%^BOLD%^%^BLACK%^S%^RESET%^%^MAGENTA%^hado%^BOLD%^%^BLACK%^w's "
"Su%^RESET%^%^MAGENTA%^p%^BOLD%^%^BLACK%^re%^RESET%^%^MAGENTA%^m%^BOLD%^%^BLACK%^ac"+
"%^RESET%^%^MAGENTA%^y ");
        set_short("%^BOLD%^s%^BLACK%^w%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^rd "+
"m%^WHITE%^a%^RESET%^%^MAGENTA%^d%^BOLD%^%^BLACK%^e from %^RESET%^%^MAGENTA%^un"+
"%^BOLD%^%^BLACK%^d%^WHITE%^u%^BLACK%^la%^WHITE%^t%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^ng "+
"sh%^WHITE%^a%^BLACK%^d%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^WHITE%^s%^RESET%^");
        set_id(({"blade","shadow supremacy","sword","weapon"}));
        set_long("%^BOLD%^%^BLACK%^Shaped from pure %^RESET%^d%^BOLD%^%^BLACK%^ar%^RESET%^k"+
"%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^ss this bl%^RESET%^%^MAGENTA%^a"+
"%^BOLD%^%^BLACK%^de has an ev%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^rsh%^RESET%^%^MAGENTA%^i"+
"%^BOLD%^%^BLACK%^fting shape to it. The inky black d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rkn"+
"%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ss is opaque and thick. It appears to drink in the "+
"%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^ur%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^oun%^RESET%^%^MAGENTA%^d"+
"%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^g light, as if wishing to quench it. Staring at "+
"the i%^RESET%^%^MAGENTA%^nk%^BOLD%^%^BLACK%^y d%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^k%^BOLD%^%^BLACK%^n"+
"%^RESET%^e%^BOLD%^%^BLACK%^ss of the blade long enough, one could see minute %^MAGENTA%^v%^RESET%^%^MAGENTA%^io"+
"%^BOLD%^l%^RESET%^%^MAGENTA%^e%^BOLD%^t %^BLACK%^disks briefly before the darkness absorbs each one. A black aura "
"radiates around thi%^RESET%^%^MAGENTA%^s d%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^v%^BOLD%^%^BLACK%^i"+
"%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^e blade.%^RESET%^");
        set_value(0);
        set_damage_type("slashing");
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^MAGENTA%^D%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^r"+
"%^BOLD%^%^BLACK%^k %^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^a%^RESET%^%^BLUE%^m"+
"%^MAGENTA%^e%^BOLD%^s %^RESET%^%^MAGENTA%^flare up off the surface of the sword and "+
"burn %^BOLD%^%^BLACK%^"+targ->QCN+"%^RESET%^%^MAGENTA%^.%^WHITE%^");
        tell_object(targ,"%^BOLD%^%^MAGENTA%^D%^RESET%^%^MAGENTA%^ar%^BOLD%^k "+
"f%^RESET%^%^MAGENTA%^l%^BLUE%^am%^MAGENTA%^e%^BOLD%^s %^RESET%^%^MAGENTA%^flare up "+
"off the surface of %^BOLD%^%^BLACK%^"+ETO->QCN+"'s %^RESET%^%^MAGENTA%^sword and burn you!%^WHITE%^");
        tell_room(environment(ETO),"%^MAGENTA%^Dark flames flare up off the surface of "+
"%^BOLD%^%^BLACK%^"+ETO->QCN+"'s %^RESET%^%^MAGENTA%^sword and burn "+
"%^BOLD%^"+targ->QCN+"%^RESET%^%^MAGENTA%^.%^WHITE%^",({ETO,targ}));

        return random(4)+8;
   }
}
