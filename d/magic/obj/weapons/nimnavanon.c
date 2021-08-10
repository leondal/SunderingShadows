//Nimnavanon Weapon Spell

#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
   ::create();
        set_name("%^BOLD%^%^GREEN%^S%^ORANGE%^t"+
"%^RESET%^%^ORANGE%^a%^BOLD%^f%^RESET%^%^GREEN%^f %^YELLOW%^o%^RESET%^%^GREEN%^f "+
"%^BOLD%^N%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^u%^BOLD%^r%^RESET%^%^ORANGE%^e"+
"%^GREEN%^'%^ORANGE%^s %^BOLD%^%^GREEN%^T%^RESET%^%^GREEN%^o%^ORANGE%^u%^BOLD%^c%^RESET%^%^ORANGE%^h%^RESET%^");
        set_short("%^GREEN%^A %^BOLD%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^v"+
        "%^RESET%^%^GREEN%^i%^ORANGE%^n%^BOLD%^%^GREEN%^g %^RESET%^%^GREEN%^o%^ORANGE%^a"+
        "%^GREEN%^k %^YELLOW%^c%^GREEN%^u%^RED%^d%^GREEN%^g%^RED%^e%^ORANGE%^l%^RESET%^");
        set_id(({"cudgel","staff","living oak","weapon"}));
        set_long("%^RESET%^%^GREEN%^This short staff looks as though it grew "+
"naturally from the t%^ORANGE%^r%^BOLD%^%^GREEN%^u%^RESET%^%^ORANGE%^n%^GREEN%^k of "+
"an %^ORANGE%^o%^GREEN%^a%^ORANGE%^k%^GREEN%^-t%^ORANGE%^r%^GREEN%^e%^ORANGE%^e%^GREEN%^. "+
"Twigs and vibrant %^BOLD%^l%^RED%^e%^ORANGE%^a%^RESET%^%^ORANGE%^v%^GREEN%^e%^YELLOW%^s "+
"%^RESET%^%^GREEN%^curve its way along the k%^ORANGE%^n%^GREEN%^ot%^ORANGE%^t%^GREEN%^ed branch,"+
        " alive with nature's radiance. The handle is %^BOLD%^%^RED%^n%^GREEN%^a%^RED%^t%^ORANGE%^u"+
"%^RESET%^%^GREEN%^r%^BOLD%^a%^ORANGE%^l%^RED%^l%^GREEN%^y %^RESET%^%^GREEN%^shaped to provide "+
"an excellent grip without chafing. When %^ORANGE%^w%^GREEN%^ie%^ORANGE%^l%^GREEN%^d%^ORANGE%^e"+
"%^GREEN%^d, leaves twist around the hand for further protection, while all along the shaft, "+
"%^ORANGE%^twigs %^BOLD%^%^RED%^c%^GREEN%^ur%^RED%^l %^RESET%^%^GREEN%^upwards into the unison "+
"form of a sturdy cudgel. Upon the handle, just above the grip, is carved the image of a "+
"%^BOLD%^%^BLACK%^w%^WHITE%^o%^BLACK%^l%^WHITE%^f%^BLACK%^'s %^RESET%^%^GREEN%^pawprint upon "+
"a circle of %^BOLD%^g%^RESET%^%^GREEN%^r%^BOLD%^a%^RESET%^%^GREEN%^s%^BOLD%^s%^RESET%^");
        set_value(0);
        set_damage_type("bludgeoning");
        set_hit((:TO,"hit_func":));
        set_property("able to cast",1);
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;
        if(!random(10)) {
        tell_object(ETO,"%^GREEN%^V%^BOLD%^i%^RESET%^%^GREEN%^n%^BOLD%^e"+
"%^RESET%^%^GREEN%^s from the staff %^BOLD%^g%^ORANGE%^r%^GREEN%^o%^ORANGE%^w "+
"%^RESET%^%^GREEN%^and %^ORANGE%^l%^BOLD%^%^GREEN%^as%^RESET%^%^ORANGE%^h %^GREEN%^around"+
        "%^BOLD%^%^ORANGE%^ "+targ->QCN+"'s%^GREEN%^body and start to %^BOLD%^%^RED%^c"+
"%^RESET%^%^RED%^rus%^BOLD%^h %^BOLD%^%^ORANGE%^"+targ->QP+"!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^GREEN%^V%^RESET%^%^ORANGE%^in"+
"%^BOLD%^%^GREEN%^es %^RESET%^%^GREEN%^from %^BOLD%^%^RED%^ "+ETO->QCN+"'s %^YELLOW%^s"+
"%^GREEN%^t%^ORANGE%^a%^GREEN%^f%^ORANGE%^f %^GREEN%^lash %^RESET%^%^GREEN%^around your "+
"body and begin to %^RED%^c%^BOLD%^rus%^RESET%^%^RED%^h %^GREEN%^you!%^RESET%^");
        tell_room(environment(ETO),"%^BOLD%^%^GREEN%^V%^RESET%^%^ORANGE%^ine"+
"%^BOLD%^%^GREEN%^s %^RESET%^%^GREEN%^from %^BOLD%^%^RED%^"+ETO->QCN+"'s%^BOLD%^s%^ORANGE%^t"+
"%^GREEN%^a%^ORANGE%^f%^GREEN%^f %^RESET%^%^GREEN%^wrap around %^YELLOW%^"+targ->QCN+"'s"
    "body and begin to %^BOLD%^%^RED%^c%^RESET%^%^RED%^rus%^BOLD%^h%^YELLOW%^"+targ->QP+"!%^RESET%^",({ETO,targ}));

        return random(4)+8;
   }
}
