#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
   set_name("%^BOLD%^%^WHITE%^A floating little %^CYAN%^bubble%^RESET%^");
  setenv("MIN", "$N %^BOLD%^%^CYAN%^floats in.");
  setenv("MOUT", "$N %^BOLD%^%^CYAN%^floats $D.");
   set_id(({"bubble"}));
   set_short("%^BOLD%^%^WHITE%^A floating little %^CYAN%^bubble%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a tiny little irredescent %^CYAN%^bubble %^WHITE%^that floats effortlessly through the air.");
  set_hd(1,1);
  set_max_hp(1);
  set_hp(1);
  set_race("bubble");
  set_gender("male");
  set_body_type("snake");
  remove_limb("head");
  remove_limb("tail");
  remove_limb("mouth");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_attacks_num(1);
  set_damage(1,3);
  set_property("knock unconscious",1);
   set_emotes(1, ({"%^BOLD%^%^WHITE%^The little bubble swirls effortlessly in the air.%^RESET%^",
      "%^BOLD%^%^CYAN%^The small bubble is caught on an air current and flies high into the air, spiralling around before gently floating back down.","%^BOLD%^%^WHITE%^Irredescent %^RESET%^%^WHITE%^%^c%^CYAN%^o%^WHITE%^l%^CYAN%^o%^RESET%^%^CYAN%^r%^BLUE%^s %^BOLD%^%^WHITE%^shimmer on the surface of the %^CYAN%^bubble %^WHITE%^as it floats around.%^RESET%^","%^BOLD%^%^WHITE%^The bubble quivers, changes shape, and reforms again as a gentle breeze hits it.%^RESET%^",
}), 0);
}
void init() {
   ::init();
   add_action("pop","pop");
}
void die(object ob) {
   tell_room(ETO,"%^BOLD%^%^WHITE%^The little %^CYAN%^bubble %^WHITE%^pops!%^RESET%^");
   TO->move("/d/shadowgate/void");
:: die(ob);
}
void pop(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!str) {             
	tell_object(TP,"%^BOLD%^%^CYAN%^Pop what?%^RESET%^");
   return 1;
   }
   if(str == "bubble"||str=="the bubble"){
	tell_object(TP,"%^BOLD%^%^CYAN%^You reach up and push your finger through the little %^WHITE%^b%^CYAN%^u%^WHITE%^bb%^CYAN%^l%^WHITE%^e%^CYAN%^!%^RESET%^");
     tell_room((ETO),"%^BOLD%^%^CYAN%^"+TPQCN+" reaches up and pushes "+TP->query_possessive()+" finger through the bubble!%^RESET%^",TP);
    TO->die();
    return 1;
    }
}
