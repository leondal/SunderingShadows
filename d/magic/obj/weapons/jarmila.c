//Jarmila Weapon Spell

#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create()
{
::create();
set_name("%^WHITE%^%^%^BOLD%^T%^GREEN%^hor%^WHITE%^%^GREEN%^n%^BOLD%^k%^RED%^is%^WHITE%^%^RED%^s%^WHITE%^");
set_short("%^WHITE%^l%^BOLD%^anc%^WHITE%^e %^ORANGE%^e%^GREEN%^n%^BOLD%^twin%^WHITE%^%^GREEN%^e%^ORANGE%^d %^WHITE%^in %^BOLD%^r%^RED%^o%^GREEN%^se%^WHITE%^%^GREEN%^s%^WHITE%^");
set_id(({"weapon","lance","lance entwined in roses","thornkiss"}));
set_long("%^WHITE%^Not an e%^BOLD%^le%^WHITE%^g%^BOLD%^an%^WHITE%^t s%^BOLD%^h%^WHITE%^a%^BOLD%^f%^WHITE%^t perfectly carved out of p%^BOLD%^ures%^WHITE%^t w%^BOLD%^hit%^WHITE%^e b%^BOLD%^irc%^WHITE%^h, or engraved %^BOLD%^g%^ORANGE%^olde%^WHITE%^n %^ORANGE%^r%^WHITE%^i%^ORANGE%^ngs %^WHITE%^that enclose it every ten inches along its length, but numerous %^ORANGE%^t%^GREEN%^h%^BOLD%^orn%^WHITE%^%^GREEN%^e%^ORANGE%^d %^BOLD%^%^GREEN%^v%^WHITE%^%^GREEN%^ine%^BOLD%^s %^WHITE%^of %^RED%^l%^BOLD%^ivin%^WHITE%^%^RED%^g r%^BOLD%^o%^WHITE%^%^RED%^s%^BOLD%^e%^WHITE%^%^RED%^s %^WHITE%^that entwine this weapon leaving only the d%^BOLD%^oubl%^WHITE%^e e%^BOLD%^dge%^WHITE%^d %^ORANGE%^g%^BOLD%^old%^WHITE%^en b%^ORANGE%^lad%^WHITE%^%^ORANGE%^e %^WHITE%^fully exposed, are the main f%^BOLD%^e%^WHITE%^ature of this guardless lance. Peculiar %^RED%^r%^BOLD%^o%^WHITE%^%^RED%^s%^BOLD%^e%^WHITE%^%^RED%^s%^WHITE%^, you can tell, as they m%^BOLD%^o%^WHITE%^v%^BOLD%^e %^WHITE%^in%^BOLD%^s%^WHITE%^tantly out of the way when you grip the weapon. And the trace, %^CYAN%^faint %^WHITE%^and %^MAGENTA%^sweet%^WHITE%^, reaches out to you.%^WHITE%^");
set_value(0);
set_damage_type("piercing");
set_hit((:TO,"hit_func":));
}

int hit_func(object targ){
targ = ETO->query_current_attacker();
if(!objectp(ETO)) return 1;
if(!objectp(targ)) return 1;
if(!random(10)) {
//targ->QCN
        tell_object(ETO,"%^RESET%^%^GREEN%^The thorns on the vines wrapped around your lance snag "+targ->QCN+", scoring "+targ->QP+" flesh!%^RESET%^");
        tell_object(targ,"%^RESET%^%^GREEN%^The thorns on the lance wielded by "+ETO->QCN+"tear your flesh!%^RESET%^");
        tell_room(EETO,"%^RESET%^%^GREEN%^The thorns on the lance wielded by "+ETO->QCN+"tear "+targ->QCN+"'s flesh!%^RESET%^",({ETO,targ}));
        return random(4)+8;
}
}
