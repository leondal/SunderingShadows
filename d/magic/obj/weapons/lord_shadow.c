//Lord Shadow Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^MAGENTA%^S%^BOLD%^%^BLACK%^hado%^RESET%^%^MAGENTA%^w "+
"D%^BOLD%^o%^RESET%^%^MAGENTA%^m%^BOLD%^i%^RESET%^%^MAGENTA%^n%^BOLD%^a"+
"%^RESET%^%^MAGENTA%^n%^BOLD%^c%^RESET%^%^MAGENTA%^e%^WHITE%^");
        set_short("%^BOLD%^%^BLACK%^obsidian gl%^WHITE%^ad%^BLACK%^ius "+
"%^RESET%^%^MAGENTA%^e%^BOLD%^n%^RESET%^%^MAGENTA%^t%^BOLD%^w"+
"%^RESET%^%^MAGENTA%^i%^BOLD%^n%^RESET%^%^MAGENTA%^e%^BOLD%^d %^RESET%^%^MAGENTA%^i"+
"%^BOLD%^n %^RESET%^%^MAGENTA%^s%^BOLD%^hadow%^RESET%^%^MAGENTA%^s%^WHITE%^");
        set_id(({"gladius","shadow dominance","blade","weapon"}));
        set_long("%^MAGENTA%^A long %^BOLD%^%^BLACK%^moonless night "+
"%^RESET%^%^MAGENTA%^or %^BOLD%^%^BLACK%^the s%^RESET%^%^MAGENTA%^h"+
"%^BOLD%^%^BLACK%^ado%^RESET%^%^MAGENTA%^w%^BOLD%^%^BLACK%^s of the d"+
"%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^epe%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^t "+
"cave %^RESET%^%^MAGENTA%^would describe the color of this blade. It is a sword of old Zin'Charu "+
"which was %^BOLD%^%^BLACK%^cast o%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^t of utter blackness, "+
"%^RESET%^%^MAGENTA%^that you can tell. A bit o%^BOLD%^l%^RESET%^%^MAGENTA%^d-f%^BOLD%^a"+
"%^RESET%^%^MAGENTA%^shi%^BOLD%^o%^RESET%^%^MAGENTA%^n%^BOLD%^e%^RESET%^%^MAGENTA%^d "+
"g%^BOLD%^l%^RESET%^%^MAGENTA%^a%^BOLD%^d%^RESET%^%^MAGENTA%^i%^BOLD%^u%^RESET%^%^MAGENTA%^s "+
"is what the d%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^rkness f%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^rms. "+
"The sharp long blade doesn't even sh%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^ne, it just "+
"c%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^s%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^m"+
"%^RESET%^%^MAGENTA%^es the v%^BOLD%^%^BLACK%^ery %^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^ight "+
"%^RESET%^%^MAGENTA%^around it. A handle on the other side seems normal. A p%^BOLD%^%^BLACK%^i"+
"%^RESET%^%^MAGENTA%^ece of %^BOLD%^%^BLACK%^ebon%^RESET%^%^MAGENTA%^y forms its body and round pommel, "+
"while fine %^WHITE%^wh%^BOLD%^i%^RESET%^te i%^BOLD%^vo%^RESET%^ry %^MAGENTA%^encases hand's rest. With "+
"each swing%^WHITE%^, %^MAGENTA%^or turn, or just a move the b%^BOLD%^%^BLACK%^lad%^RESET%^%^MAGENTA%^e "+
"leaves a trail of s%^BOLD%^%^BLACK%^hadow%^RESET%^%^MAGENTA%^s behind.%^WHITE%^");
        set_value(0);
        set_damage_type("slashing");
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;
        if(!random(10)) {
        tell_object(ETO,"%^MAGENTA%^As you %^BOLD%^slice %^RESET%^%^MAGENTA%^your "+
"%^BOLD%^%^BLACK%^opponent %^RESET%^%^MAGENTA%^with calm intent the s%^BOLD%^%^BLACK%^h"+
"%^RESET%^%^MAGENTA%^adow of your %^BOLD%^%^BLACK%^blade %^RESET%^%^MAGENTA%^follows you "+
"and %^BOLD%^strikes %^BLACK%^"+targ->QCN+" %^MAGENTA%^again.%^RESET%^");
        tell_object(targ,"%^MAGENTA%^With a serene look, %^BOLD%^%^BLACK%^"+ETO->QCN+" %^MAGENTA%^strikes "+
"%^RESET%^%^MAGENTA%^you. The s%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^adow of %^BOLD%^%^BLACK%^"+ETO->QP+" "+
"%^RESET%^%^MAGENTA%^b%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^ade follows %^BOLD%^%^BLACK%^"+ETO->QP+" "+
"%^RESET%^%^MAGENTA%^and %^BOLD%^lashes %^RESET%^%^MAGENTA%^out at you %^BOLD%^again%^RESET%^%^MAGENTA%^!%^RESET%^");
        tell_room(environment(ETO),"%^MAGENTA%^With a serene look, %^BOLD%^%^BLACK%^"+ETO->QCN+" %^MAGENTA%^strikes "+
"%^WHITE%^"+targ->QCN+"%^RESET%^%^MAGENTA%^. The s%^BOLD%^%^BLACK%^h%^RESET%^%^MAGENTA%^adow o%^BOLD%^f "+
"%^BLACK%^"+ETO->QCN+" 's %^RESET%^%^MAGENTA%^b%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^ade follows "+
"%^BOLD%^%^BLACK%^"+ETO->QP+" %^RESET%^%^MAGENTA%^and %^BOLD%^lashes %^RESET%^%^MAGENTA%^out at "+
"%^BOLD%^%^WHITE%^"+targ->QCN+" %^MAGENTA%^again!%^RESET%^",({ETO,targ}));

        return random(4)+8;
   }
}
