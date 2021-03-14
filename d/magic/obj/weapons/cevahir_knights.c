//Cevahir Weapon Spell
#include <std.h>
inherit "/d/magic/obj/weapons/godwpns_knights";

void create(){
   ::create();
   set_name("%^YELLOW%^Str%^RESET%^%^ORANGE%^a%^YELLOW%^te%^WHITE%^g%^YELLOW%^ic St%^WHITE%^r%^RESET%^%^ORANGE%^i%^YELLOW%^ke%^RESET%^");
   set_short("%^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d%^WHITE%^e%^YELLOW%^n-b%^RESET%^%^ORANGE%^l%^YELLOW%^a%^WHITE%^d%^YELLOW%^ed gl%^WHITE%^a%^YELLOW%^ive%^RESET%^");
   set_id(({"blade","sword","glaive","polearm","weapon"}));
   set_long("%^RESET%^%^ORANGE%^This seven-foot shaft of %^BOLD%^%^BLACK%^ash %^RESET%^%^ORANGE%^has been carved with intricate geometric designs interspersed with nearly hidden scenes of %^RED%^battle%^ORANGE%^. %^RESET%^Weapons %^ORANGE%^and %^BOLD%^%^WHITE%^shields %^RESET%^%^ORANGE%^stand out in stark contrast to the paler wood, which ends with a blade on either end. One end features a small %^RESET%^spike%^ORANGE%^ of %^BOLD%^%^WHITE%^steel %^RESET%^%^ORANGE%^topped with %^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^den f%^RESET%^%^ORANGE%^i%^YELLOW%^lig%^RESET%^%^ORANGE%^r%^YELLOW%^ee %^RESET%^%^ORANGE%^while the other supports a curved two-foot %^BOLD%^%^WHITE%^blade %^RESET%^%^ORANGE%^so sharp that the edge seems to disappear until it catches the %^YELLOW%^light%^RESET%^%^ORANGE%^. Long streamers of %^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^p%^BOLD%^l%^RESET%^%^MAGENTA%^e %^ORANGE%^and %^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e %^ORANGE%^flutter on the %^CYAN%^breeze%^ORANGE%^, untouched by blood or muck.%^RESET%^");
   set_damage_type("slashing");
   set_value(0);
   set_hit((:TO,"hit_func":));
}
int hit_func(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(!random(10)) {
      tell_object(ETO,"%^YELLOW%^With a quick flick of your wrist, you stab "+targ->QCN+" with the spiked end of your glaive!%^RESET%^");
      tell_object(targ,"%^YELLOW%^With a quick flick of "+ETO->QP+" wrist, "+ETOQCN+" stabs you with the spiked end of "+ETO->QP+" glaive!%^RESET%^");
      tell_room(EETO,"%^YELLOW%^With a quick flick of "+ETO->QP+" wrist, "+ETOQCN+" stabs "+targ->QCN+" with the spiked end of "+ETO->QP+" glaive!%^RESET%^",({ETO,targ}));

      return random(4)+8;
   }
}
