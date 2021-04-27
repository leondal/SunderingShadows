//Updated by ~Circe~ 2/16/09 based on comments from players that 
//it wasn't as good as lesser hammers
//created by shar and updated a little by Saide - 12/15/03
#include <std.h>
inherit "/d/common/obj/weapon/warhammer.c";

void create(){
   ::create();
   set_name("stormhammer");
   set_id(({"hammer","stormhammer","Stormhammer","storm hammer"}));
   set_short("%^BOLD%^%^BLUE%^S%^CYAN%^t%^RESET%^%^CYAN%^o%^BOLD%^r"+
      "%^YELLOW%^m%^BLUE%^h%^RESET%^%^CYAN%^a%^BOLD%^m%^YELLOW%^m"+
      "%^BLUE%^e%^CYAN%^r%^RESET%^");
   set_obvious_short("%^RESET%^%^BLUE%^A bl%^BOLD%^u%^RESET%^"+
      "%^BLUE%^e-ti%^BOLD%^n%^RESET%^%^BLUE%^ged medium hammer%^RESET%^");
   set_long("%^CYAN%^Forged from %^BOLD%^azu%^WHITE%^r%^CYAN%^e "+
      "cr%^WHITE%^y%^CYAN%^stal%^RESET%^%^CYAN%^, similiar to the "+
      "platemail, this medium hammer looks ancient.  The warhammer "+
      "is crafted in a typical fashion, with a stout thick blunt "+
      "head on one end which tappers off to a fine blunt tip on the "+
      "opposite end.  The shaft of the hammer seems to meld into "+
      "the crystal head, looking as if it were one solid piece of "+
      "crystal.  A braided, %^BOLD%^%^BLACK%^storm gray "+
      "leather%^RESET%^%^CYAN%^ cord twists and spirals down the "+
      "shaft of the hammer.  The end of the hammer features the "+
      "same leather fashioned into a loop that you can put your "+
      "hand through.  Looking deep into the crytal you can make "+
      "out %^BOLD%^%^CYAN%^fla%^WHITE%^s%^CYAN%^hes%^RESET%^"+
      "%^CYAN%^ of light within a cloudy substance.  It almost "+
      "seems that the hammer vibrates with each flash of "+
      "light.%^RESET%^");
   set_value(1500);
   set_lore("The Stormhammer was utilized by Mad Marigold "+
      "Methuzila, or Triple M as she was known.");
   set_property("enchantment",5);
   set_item_bonus("damage bonus",2);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
 if((int)ETO->query_highest_level() < 26) {
  tell_object(ETO,"%^BLUE%^You lack the understanding to control such a fine hammer!%^RESET%^");
  return 0;
 }
	tell_room(environment(ETO),"%^BLUE%^Flashes of %^BOLD%^%^CYAN%^light%^RESET%^%^BLUE%^ can be seen in "+ETOQCN+"'s shaking hammer.",ETO);
	tell_object(ETO,"%^BLUE%^The hammer vibrates in your hands as %^BOLD%^%^CYAN%^flashes%^RESET%^%^BLUE%^ of light can be seen within the azure crystal.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"%^BLUE%^A loud %^BOLD%^%^BLACK%^KRRRRBOOOOOM%^RESET%^%^BLUE%^ thunders through the area!",ETO);
	tell_object(ETO,"%^BLUE%^You release the hammer with a loud %^BOLD%^%^BLACK%^KRRRRBOOOOM%^RESET%^%^BLUE%^ that thunders through the area.");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 200 && (int)TO->query_property("enchantment") >= 1){
 switch(random(71)) {
  case 0..68:
	  tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" strikes "+targ->QCN+" soundly, sending an electrical jolt through "+targ->QP+"%^CYAN%^ body!%^RESET%^",({ETO,targ}));
	  tell_object(ETO,"%^BOLD%^%^CYAN%^The hammer glows with a brilliant %^WHITE%^white light%^CYAN%^ before you strike "+targ->QCN+".  As the hammer connects an electrial charge is released into "+targ->QO+".%^RESET%^");
	  tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s hammer glows with a brilliant %^WHITE%^white light%^CYAN%^ just before it connects with you.  As the hammer hits you a powerful electrical jolt courses through your body!");
        return roll_dice(2,4)+4;
   break;
  case 69..70: 
   tell_room(EETO,"%^BOLD%^%^WHITE%^Thunder echoes as "+ETOQCN+"%^BOLD%^%^WHITE%^ strikes "+targ->QCN+"%^BOLD%^%^WHITE%^ with "+ETO->QP+"%^BOLD%^%^WHITE%^ hammer!%^RESET%^",({ETO,targ}));
   tell_object(ETO,"%^BOLD%^%^WHITE%^Thunder echoes through the area as you strike "+targ->QCN+"%^BOLD%^%^WHITE%^ with your hammer!%^RESET%^");
   tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+"%^BOLD%^%^WHITE%^ strikes you with "+ETO->QP+"%^BOLD%^%^WHITE%^ hammer and a loud echo of thunder momentarily knocks you off balance!%^RESET%^");
   return targ->set_paralyzed(4 + random(6),"%^BOLD%^%^WHITE%^You are struggling to regain your balance!%^RESET%^");
   break;   
  }
 } 
}
