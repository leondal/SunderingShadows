//Cevahir by ~Circe~ 12/7/19
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns";

void create(){
   ::create();
   set_name("%^RESET%^%^MAGENTA%^Wa%^BOLD%^r%^WHITE%^l%^RESET%^%^MAGENTA%^or%^BOLD%^d%^RESET%^%^MAGENTA%^'s M%^BOLD%^%^WHITE%^i%^MAGENTA%^g%^RESET%^%^MAGENTA%^ht%^RESET%^");
   set_short("%^RESET%^%^MAGENTA%^a %^RESET%^cr%^BOLD%^y%^RESET%^st%^BOLD%^%^CYAN%^a%^RESET%^ll%^BOLD%^i%^RESET%^ne %^MAGENTA%^a%^BOLD%^m%^WHITE%^e%^MAGENTA%^t%^RESET%^%^MAGENTA%^h%^BOLD%^y%^WHITE%^s%^RESET%^%^MAGENTA%^t greatsword%^RESET%^");
   set_id(({"might","warlord's might","warlords might","greatsword","two-handed sword","sword","weapon"}));
   set_long("%^RESET%^%^MAGENTA%^The blade of this %^BOLD%^enormous sword %^RESET%^%^MAGENTA%^seems to have been fashioned from a single a%^BOLD%^m%^WHITE%^e%^MAGENTA%^t%^RESET%^%^MAGENTA%^h%^BOLD%^y%^WHITE%^s%^RESET%^%^MAGENTA%^t, though its light weight hints at a more %^CYAN%^mystical creation%^MAGENTA%^. Crystalline f%^BOLD%^a%^WHITE%^c%^MAGENTA%^e%^RESET%^%^MAGENTA%^ts catch the light, sending beams of %^BOLD%^%^WHITE%^white %^RESET%^%^MAGENTA%^and %^BOLD%^purple %^RESET%^%^MAGENTA%^light across the wielder's face, and the %^YELLOW%^golden pommel %^RESET%^%^MAGENTA%^is engraved with a precise formation of %^BOLD%^%^BLACK%^b%^YELLOW%^e%^BLACK%^e%^YELLOW%^s%^RESET%^%^MAGENTA%^.%^RESET%^");
   set_damage_type("slashing");
   set_value(0);
   set_size(3);
   set_hit((:TO,"hit_func":));
}

int hit_func(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(10)){
      tell_object(ETO,"%^RESET%^%^MAGENTA%^A beam of %^BOLD%^light %^RESET%^%^MAGENTA%^shoots forth from your sword, searing into "+targ->QCN+"!%^RESET%^");
      tell_object(targ,"%^RESET%^%^MAGENTA%^A beam of %^BOLD%^light %^RESET%^%^MAGENTA%^shoots forth from "+ETOQCN+"'s sword, searing into you!%^RESET%^");
      tell_room(EETO,"%^RESET%^%^MAGENTA%^A beam of %^BOLD%^light %^RESET%^%^MAGENTA%^shoots forth from "+ETOQCN+"'s sword, searing into "+targ->QCN+"!%^RESET%^",({ETO,targ}));

      return random(4)+8;
   }
}
