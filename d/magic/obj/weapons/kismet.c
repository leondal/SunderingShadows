//Kismet Spell Weapon

#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^YELLOW%^S%^CYAN%^t"+
"%^RESET%^%^BLUE%^a%^YELLOW%^r%^RESET%^%^BLUE%^f%^CYAN%^i%^BOLD%^r"+
"%^ORANGE%^e %^RESET%^%^CYAN%^C%^BLUE%^h%^CYAN%^a%^BLUE%^i%^CYAN%^n%^WHITE%^");
        set_short("%^BOLD%^%^CYAN%^A stunning %^RESET%^%^CYAN%^c"+
"%^BOLD%^r%^WHITE%^y%^CYAN%^s%^RESET%^%^CYAN%^t%^BOLD%^al"+
"%^WHITE%^l%^RESET%^%^CYAN%^i%^BOLD%^ne %^WHITE%^c%^CYAN%^h%^WHITE%^ai%^CYAN%^n%^RESET%^");
        set_id(({"chain","starfire chain","weapon"}));
        set_long("%^BOLD%^Links made of pure %^CYAN%^c%^BLUE%^r"+
"%^RESET%^%^CYAN%^y%^BOLD%^%^BLUE%^st%^CYAN%^a%^RESET%^%^CYAN%^l "+
"%^BOLD%^%^WHITE%^are strung together to create this %^RESET%^c%^BOLD%^h"+
"%^RESET%^a%^BOLD%^i%^RESET%^n%^BOLD%^. The slender %^RESET%^c%^BOLD%^h%^RESET%^a"+
"%^BOLD%^i%^RESET%^n %^BOLD%^appears to be on the short side, about two feet long "+
"at most. Within each crystal link a whirling mass of midnight blue can be seen. "+
"Motes of %^CYAN%^b%^RESET%^%^CYAN%^lu%^BOLD%^e%^WHITE%^-%^RESET%^w%^BOLD%^h%^RESET%^i"+
"%^BOLD%^t%^RESET%^e %^YELLOW%^l%^WHITE%^i%^ORANGE%^g%^WHITE%^h%^ORANGE%^t %^WHITE%^wink "+
"in and out of existence within the dark blue mist, each one looking like a miniat%^RESET%^u"+
"%^BOLD%^re %^ORANGE%^s%^RED%^ta%^ORANGE%^r%^WHITE%^. This divine chain radiates an aura of raw "+
"%^CYAN%^magic%^WHITE%^.%^RESET%^");
        set_value(0);
        set_damage_type("bludgeoning");
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^BOLD%^%^CYAN%^The motes of light begin to spin faster "+
"within each link, releasing a %^RED%^f%^ORANGE%^i%^RESET%^%^RED%^e%^YELLOW%^r%^RED%^y "+
"%^CYAN%^busrt into %^YELLOW%^ "+targ->QCN+".%^RESET%^");
        tell_object(targ,"%^BOLD%^%^CYAN%^Motes of light within %^RED%^"+ETO->QCN+"%^CYAN%^'s"+
" crystal chain begin to spin faster before releasing a %^RED%^f%^ORANGE%^i%^RESET%^%^RED%^e"+
"%^YELLOW%^r%^RED%^y %^CYAN%^burst into you!%^RESET%^");
        tell_room(environment(ETO),"%^BOLD%^%^CYAN%^Motes of light within %^RED%^"+ETO->QCN+"%^CYAN%^'s "+
"crystal chain begin to spin faster before releasing a %^RED%^f%^ORANGE%^i%^RESET%^%^RED%^e%^YELLOW%^r"+
"%^RED%^y %^CYAN%^burst into %^ORANGE%^"+targ->QCN+"%^CYAN%^!%^RESET%^",({ETO,targ}));

        return random(4)+8;
   }
}
