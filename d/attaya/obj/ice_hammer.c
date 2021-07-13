#include <std.h>
inherit "/d/common/obj/weapon/warhammer.c";

void create(){
	::create();
	set_name("gloomfrost");
     set_id(({ "hammer","gloomfrost","warhammer","frost hammer" }));
        set_short("%^RESET%^%^BLUE%^Gl%^BOLD%^%^CYAN%^oo%^RESET%^%^BLUE%^mf%^BOLD%^%^CYAN%^ro%^BOLD%^%^WHITE%^s%^BOLD%^%^CYAN%^t%^RESET%^");
     set_obvious_short("%^BOLD%^%^CYAN%^A warhammer caked with a %^WHITE%^frosty%^CYAN%^ rime%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This beautifully carved hammer looks to be made from solid %^RESET%^%^WHITE%^i%^BOLD%^%^CYAN%^c%^RESET%^%^WHITE%^e%^BOLD%^%^CYAN%^. The head of the hammer has a %^BOLD%^%^YELLOW%^gold %^BOLD%^%^CYAN%^reinforced pommel and has small indentions within it, maximizing force. The handle is wrapped in a thin layer of cloth, which seems to have melded within the weapon giving you a very steady grip. Despite being almost entirely made of ice, the hammer is not that cold to the touch.%^RESET%^

AVATAR
	);
	set_value(5000);
	set_lore(
@AVATAR
This was forged by the dwarf Teiral Stormhammer in the dwarven city of Kinaro almost 70 years ago. His personal weapon for many years, it won him many victories. About 30 years ago, however, the famed dwarf disappeared, as did his hammer, and was never heard from again.

AVATAR
	);
   //set_type("bludgeoning");
   //set_prof_type("medium hammer");
  //set_size(2);
   //set_wc(1.8);
   //set_large_wc(1,10);
        set_property("enchantment",5);
	set_wield((:TO,"wield_func":));
     set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
        tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" shivers slightly after taking hold of the handle.",ETO);
	tell_object(ETO,"%^BOLD%^%^BOLD%^%^CYAN%^Your hands feel slightly cold as you wield the weapon.");
	return 1;
}
int unwield_func(){
      tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" smiles a little after unwielding the weapon.",ETO);
	tell_object(ETO,"%^BOLD%^%^BOLD%^%^CYAN%^Your hands feel slightly %^BOLD%^%^RED%^warmer %^BOLD%^%^CYAN%^as you release the weapon.");
	return 1;
}
int hit_func(object targ){
	if(!random(5)){
   switch(random(3)){
      case 0..1:
        tell_room(environment(query_wielded()),"%^BOLD%^%^CYAN%^"+ETOQCN+" breathes deeply with a mighty swing of the hammer that connects violently.",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^A chill streaks into your body as you %^BOLD%^%^YELLOW%^SLAM %^BOLD%^%^CYAN%^into your opponent!");
        tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+" breathes deeply before %^BOLD%^%^RED%^violently%^BOLD%^%^CYAN%^ slamming you with the hammer!");
         return roll_dice(3,4)+2;
          break;
   case 2:
      tell_room(environment(query_wielded()),"%^RESET%^%^CYAN%^"+ETOQCN+" slams the hammer with force, sending chills down "+targ->QCN+"'s spine!%^RESET%^",({ETO,targ}));
      tell_object(ETO,"%^RESET%^%^CYAN%^You send a %^BOLD%^%^CYAN%^shockwave%^RESET%^%^CYAN%^ of ice into your opponent as you find your mark!%^RESET%^");
      tell_object(targ,"%^RESET%^%^CYAN%^"+ETOQCN+" sends a %^BOLD%^%^CYAN%^shockwave%^RESET%^%^CYAN%^ with the hit that freezes you to the bone!%^RESET%^");
      targ->set_paralyzed(10,"%^BOLD%^%^CYAN%^You are frozen stiff!%^RESET%^");
      return roll_dice(3,4)+-2;
     break;
      }
return 0;
}
}
