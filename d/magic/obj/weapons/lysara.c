//Lysara Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^CYAN%^Sword of %^BOLD%^R%^RESET%^%^CYAN%^e"+
"%^WHITE%^p%^CYAN%^o%^WHITE%^s%^BOLD%^%^CYAN%^e%^RESET%^");
        set_short("g%^BOLD%^le%^RESET%^a%^BOLD%^m%^RESET%^i%^BOLD%^n"+
"%^RESET%^g s%^BOLD%^i%^RESET%^l%^BOLD%^ve%^RESET%^r b%^BOLD%^as%^RESET%^ta"+
"%^BOLD%^r%^RESET%^d s%^BOLD%^w%^RESET%^o%^BOLD%^r%^RESET%^d%^BOLD%^%^RESET%^");
        set_id(({"sword","sword of repose","blade","weapon"}));
        set_long("%^CYAN%^This %^BOLD%^m%^BLUE%^a%^CYAN%^g%^BLUE%^n"+
"%^CYAN%^i%^BLUE%^f%^CYAN%^i%^BLUE%^c%^CYAN%^e%^BLUE%^n%^CYAN%^t "+
"%^RESET%^%^CYAN%^bastard sword %^WHITE%^s%^BOLD%^hin%^RESET%^es %^CYAN%^with "+
"a dim light. The one handed %^BOLD%^%^WHITE%^b%^RESET%^a%^BOLD%^sta%^RESET%^r%^BOLD%^d "+
"%^RESET%^%^CYAN%^sword has been created from pure %^WHITE%^s%^BOLD%^i%^RESET%^l%^BOLD%^v"+
"%^RESET%^e%^BOLD%^r%^RESET%^%^CYAN%^. The sword retains an antiquated feel to it, looking "+
"more like an ancient relic than anything modern. The hilt of the %^BOLD%^%^WHITE%^b"+
"%^RESET%^la%^BOLD%^d%^RESET%^e %^CYAN%^features a %^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^a"+
"%^BOLD%^%^BLACK%^v%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^n %^RESET%^%^CYAN%^made from "+
"%^BOLD%^%^BLACK%^e%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^y%^RESET%^%^CYAN%^, "+
"with the wings jutting out on each side of the blade. The symmetrical and orderly flow of the "+
"%^WHITE%^d%^BOLD%^%^CYAN%^i%^RESET%^v%^BOLD%^%^CYAN%^i%^RESET%^n%^BOLD%^%^CYAN%^e "+
"%^RESET%^%^CYAN%^blade radiates a feeling of strength.%^WHITE%^");
        set_value(0);
        set_damage_type("slashing");
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^BOLD%^%^CYAN%^The %^BLACK%^r%^RESET%^a"+
"%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^n %^CYAN%^begins to "+
"%^ORANGE%^g%^WHITE%^lo%^ORANGE%^w %^CYAN%^as you slash through %^BLUE%^"+targ->QCN+"%^CYAN%^.%^RESET%^");
        tell_object(targ,"%^CYAN%^The %^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^v"+
"%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^n %^RESET%^%^CYAN%^on %^ORANGE%^"+ETO->QCN+"'s %^CYAN%^blade "+
"begins to glow as %^ORANGE%^"+ETO->QS+" %^CYAN%^slashes through you!%^WHITE%^");
        tell_room(environment(ETO),"%^CYAN%^The %^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^e"+
"%^BOLD%^%^BLACK%^n %^RESET%^%^CYAN%^on %^YELLOW%^"+ETO->QCN+"'s %^RESET%^%^CYAN%^blade begins to "+
"%^YELLOW%^g%^WHITE%^lo%^ORANGE%^w %^RESET%^%^CYAN%^as %^YELLOW%^"+ETO->QS+" %^RESET%^%^CYAN%^slashes "+
"through %^BOLD%^%^WHITE%^"+targ->QCN+"%^RESET%^%^CYAN%^!",({ETO,targ}));

        return random(4)+8;
   }
}
