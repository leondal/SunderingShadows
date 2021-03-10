//Minor updates - Octothorpe 12/27/09
//Circe 5/3/04

#include <std.h>
inherit "/d/common/obj/weapon/scourge";

void create(){
  ::create();
  set_name("chain whip");
  set_id(({"chain","whip","chain whip","lash"}));
  set_short("%^BOLD%^%^BLACK%^Ch%^WHITE%^a%^BLACK%^i%^RESET%^n "+
     "%^BOLD%^%^BLACK%^W%^WHITE%^h%^RESET%^i%^BOLD%^%^BLACK%^p%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This segmented chain is made up of short "+
     "lengths of %^RESET%^ti%^BOLD%^%^BLACK%^ta%^RESET%^ni%^BOLD%^"+
     "%^BLACK%^um chained together, ending in a tip made of "+
     "a kite-shaped prism of solid %^RESET%^%^ORANGE%^ad%^RESET%^am"+
     "%^BOLD%^an%^RESET%^ti%^ORANGE%^um%^BOLD%^%^BLACK%^.  The "+
     "handle is made of solid %^RESET%^%^ORANGE%^ad%^RESET%^am"+
     "%^BOLD%^an%^RESET%^ti%^ORANGE%^um%^BOLD%^%^BLACK%^ embossed "+
     "with grooves to aid in its grip.");
  set_lore("Legends tell of ghosts in rattling chains that haunt "+
     "places long after their earthly demise.  This chain whip is "+
     "the physical manifestation of such hatred, being born as a "+
     "weapon on this plane.");
  set_property("enchantment",2);
  set_wield((:TO,"wield_me":));
  set_unwield((:TO,"unwield_me":));
  set_hit((:TO,"extra_hit":));
}

int wield_me(){
   if((int)ETO->query_highest_level() < 10){
      tell_object(ETO,"%^BOLD%^%^BLACK%^%^The whip rejects your touch!%^RESET%^");
	  return 0;
   }
   tell_object(ETO,"%^RESET%^%^ORANGE%^The %^RESET%^chain %^ORANGE%^"+
      "makes a %^RESET%^metallic %^ORANGE%^rustle as you unfurl it.");
   tell_room(EETO,"%^RESET%^%^ORANGE%^The %^RESET%^chain %^ORANGE%^"+
      "makes a %^RESET%^metallic %^ORANGE%^rustle as "+ETOQCN+" "+
      "unfurls it.",ETO);
   return 1;
}

int unwield_me(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^The bars on the %^RESET%^chain "+
      "%^ORANGE%^ring steadily as you roll up the whip.");
   tell_room(EETO,"%^RESET%^%^ORANGE%^The bars on the %^RESET%^chain "+
      "%^ORANGE%^ring steadily as "+ETOQCN+" rolls up the whip.",ETO);
   return 1;
}

int extra_hit(object ob){
   if(!objectp(ETO)) return 1;
   if(!objectp(ob)) return 1;
   if(!random(6)){
      tell_object(ETO,"%^RESET%^%^ORANGE%^You swing the chain in "+
         "a wide arc before striking "+ob->QCN+" soundly!");
      tell_object(ob,"%^RESET%^%^ORANGE%^"+ETOQCN+" swings the chain in "+
         "a wide arc before striking you soundly!");
      tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" swings the chain in "+
         "a wide arc before striking "+ob->QCN+" soundly!",({ETO,ob}));
      if(!random(4)){
         tell_object(ETO,"%^YELLOW%^The chain wraps around "+ob->QCN+"'s "+
            "ankle and you yank, pulling "+ob->QO+" off balance!");
         tell_object(ob,"%^YELLOW%^The chain wraps around your "+
            "ankle and "+ETOQCN+" yanks, pulling you off balance!");
         tell_room(EETO,"%^YELLOW%^The chain wraps around "+ob->QCN+"'s "+
            "ankle and "+ETOQCN+" yanks, pulling "+ob->QO+" off "+
            "balance!",({ETO,ob}));
         ob->set_tripped(1,"%^BOLD%^You're trying to find your feet!");
      }
   return random(8)+5;
   }
}
