//Jarmila Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create()
{
   ::create();
        set_name("%^BOLD%^%^RED%^P%^CYAN%^h%^ORANGE%^o%^RED%^e%^CYAN%^n"+
"%^ORANGE%^i%^RED%^x %^RESET%^%^RED%^Sword%^WHITE%^");
        set_short("%^BOLD%^s%^RESET%^l%^BOLD%^e%^RESET%^n%^BOLD%^d%^RESET%^e%^BOLD%^r "+
"ivory %^RESET%^%^RED%^r%^BOLD%^%^WHITE%^a%^RESET%^%^RED%^p%^BOLD%^%^WHITE%^ie%^RESET%^%^RED%^r%^WHITE%^");
        set_id(({"rapier","blade","sword","flaming rose rapier","weapon"}));
        set_long("%^BOLD%^Crafted out of %^RESET%^i%^BOLD%^v%^RESET%^o%^BOLD%^r"+
"%^RESET%^y%^BOLD%^, this %^RESET%^s%^BOLD%^l%^RESET%^%^RED%^e%^BOLD%^%^WHITE%^n"+
"%^RESET%^%^RED%^d%^BOLD%^%^WHITE%^e%^RESET%^r %^BOLD%^rapier has an aesthetically "+
"appealing quality to it. The slender blade of the rapier has been polished smooth, "+
"letting the brilliant white of the i%^RESET%^v%^BOLD%^o%^RESET%^r%^BOLD%^y shine forth. "+
"Etched around the base of the blade is a %^RED%^p%^RESET%^%^RED%^h%^YELLOW%^o%^RESET%^%^ORANGE%^e"+
"%^CYAN%^n%^BOLD%^i%^RED%^x %^WHITE%^wreathed in %^RESET%^%^RED%^f%^BOLD%^l%^ORANGE%^a%^WHITE%^m"+
"%^RED%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^. The hand guard of the rapier is crafted from gracefully "+
"curved lines of %^RESET%^%^RED%^rose %^BOLD%^%^WHITE%^and white %^ORANGE%^g%^WHITE%^o%^ORANGE%^l%^WHITE%^d, "+
"offering protection to the wielder's hand.  The pommel of the blade has been wrapped with deep "+
"%^RESET%^%^RED%^c%^MAGENTA%^rims%^RED%^on %^BOLD%^%^WHITE%^silk, adding to the beauty of this divine "+
"rapier.%^RESET%^");
        set_damage_type("slashing");
        set_value(0);
        set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
        targ = ETO->query_current_attacker();
        if(!objectp(ETO)) return 1;
        if(!objectp(targ)) return 1;

        if(!random(10)) {
        tell_object(ETO,"%^RED%^A burst of %^YELLOW%^f%^RED%^l%^CYAN%^a"+
"%^RESET%^%^RED%^m%^BOLD%^e%^RESET%^%^RED%^s covers the ivory rapier and burns "+
"%^BOLD%^%^GREEN%^"+targ->QCN+"%^RESET%^%^RED%^.%^WHITE%^");
        tell_object(targ,"%^RED%^A burst of %^BOLD%^f%^ORANGE%^l%^RESET%^%^RED%^a"+
"%^BOLD%^%^CYAN%^m%^RED%^e%^ORANGE%^s %^RESET%^%^RED%^covers %^YELLOW%^"+ETO->QCN+"'s"+
"%^RESET%^%^RED%^ivory rapier and burns you.%^WHITE%^");
        tell_room(environment(ETO),"%^RED%^A burst of %^BOLD%^f%^ORANGE%^l"+
"%^RED%^a%^CYAN%^m%^RED%^e%^ORANGE%^s %^RESET%^%^RED%^covers %^YELLOW%^"+ETO->QCN+"'s "+
"%^RESET%^%^RED%^ivory rapier and burns %^BOLD%^%^GREEN%^"+targ->QCN+"%^RESET%^%^RED%^.%^RESET%^.",({ETO,targ}));

        return random(4)+8;
   }
}
