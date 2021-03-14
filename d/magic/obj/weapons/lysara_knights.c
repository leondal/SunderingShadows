//Lysara Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
        set_name("%^CYAN%^F%^MAGENTA%^a%^BLUE%^t%^MAGENTA%^e "+
"%^CYAN%^W%^MAGENTA%^e%^BLUE%^a%^MAGENTA%^v%^BLUE%^e%^CYAN%^r%^RESET%^");
        set_short("%^BOLD%^%^MAGENTA%^s%^RESET%^%^CYAN%^t%^MAGENTA%^u%^CYAN%^nn"+
"%^MAGENTA%^i%^CYAN%^n%^BOLD%^%^MAGENTA%^g %^BLACK%^t%^RESET%^r%^BOLD%^i-"+
"%^RESET%^c%^BOLD%^%^BLACK%^ol%^RESET%^or%^BOLD%^ed %^BLACK%^b%^RESET%^l"+
"%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^");
        set_id(({"blade","sword","fate weaver","weapon"}));
        set_long("%^CYAN%^This %^BOLD%^%^BLACK%^t%^WHITE%^r%^RESET%^i-%^BOLD%^%^BLACK%^m%^WHITE%^a"+
"%^RESET%^t%^BOLD%^%^BLACK%^er%^RESET%^i%^BOLD%^a%^BLACK%^l b%^WHITE%^l%^RESET%^ad%^BOLD%^%^BLACK%^e "+
"%^RESET%^%^CYAN%^is composed of three different substances, %^BOLD%^%^WHITE%^ivory, %^BLACK%^ebony, "+
"%^RESET%^%^CYAN%^and %^WHITE%^st%^BOLD%^%^BLACK%^ee%^RESET%^l. %^CYAN%^They are fused together using ma"+
"gic, and the edge of this blade is finely honed to a sharp cutting edge. The hilt of the blade is compose"+
"d of three interlocking rings of %^BOLD%^%^WHITE%^ivory, %^BLACK%^ebony, %^RESET%^%^CYAN%^and %^WHITE%^st"+
"%^BOLD%^%^BLACK%^ee%^RESET%^l %^CYAN%^that form a wrist guard. The handle is made of pure silver wrapped i"+
"n %^BOLD%^%^BLACK%^bl%^RESET%^%^ORANGE%^ac%^BOLD%^%^BLACK%^k %^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^e"+
"%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^CYAN%^. "+
"Etched into the leather itself is an image of an %^ORANGE%^o%^WHITE%^w%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^, "+
"it's wings spread in flight. ");
        set_damage_type("slashing");
        set_value(0);
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%%^CYAN%^The %^WHITE%^t%^BOLD%^h%^BLACK%^r%^WHITE%^e%^BLACK%^e "+
"r%^RESET%^i%^BOLD%^ng%^RESET%^s %^CYAN%^that form the wrist guard %^YELLOW%^g%^RESET%^%^ORANGE%^l"+
"%^BOLD%^o%^RESET%^%^ORANGE%^w %^CYAN%^and shoot at %^BOLD%^%^BLACK%^"+targ->QCN+".%^RESET%^");
        tell_object(targ,"%^CYAN%^The %^WHITE%^t%^BOLD%^h%^BLACK%^r%^WHITE%^e%^BLACK%^e r%^RESET%^i%^BOLD%^ng"+
"%^RESET%^s %^CYAN%^on %^BOLD%^"+ETO->QCN+"'s %^RESET%^%^CYAN%^wrist guard %^YELLOW%^g%^RESET%^%^ORANGE%^l"+
"%^BOLD%^o%^RESET%^%^ORANGE%^w %^CYAN%^and shoot out at you!%^WHITE%^");
        tell_room(environment(ETO),"%^CYAN%^The %^WHITE%^t%^BOLD%^h%^BLACK%^r%^WHITE%^e"+
"%^BLACK%^e r%^RESET%^i%^BOLD%^ng%^RESET%^s %^CYAN%^on %^BOLD%^"+ETO->QCN+"'s %^RESET%^%^CYAN%^wrist "+
"guard %^YELLOW%^g%^RESET%^%^ORANGE%^l%^BOLD%^o%^RESET%^%^ORANGE%^w %^CYAN%^and shoot out at %^BOLD%^%^BLACK%^"+targ->QCN+"%^RESET%^%^CYAN%^!%^WHITE%^",({ETO,targ}));

        return random(4)+8;
   }
}
