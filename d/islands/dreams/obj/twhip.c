//upddated to current code and to remove references to old gods ~Circe~ 9/21/19

#include <std.h>
inherit "/d/common/obj/weapon/whip.c";

void create(){
   ::create();
   set_name("whip of torrents");
   set_short("%^BOLD%^%^CYAN%^Whip of %^BLUE%^T%^CYAN%^o%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^r%^CYAN%^e%^RESET%^%^CYAN%^n%^BOLD%^%^BLUE%^t%^CYAN%^s%^RESET%^");
   set_obvious_short("%^BOLD%^%^CYAN%^An aquamarine base whip%^RESET%^");
   set_id(({"whip","whip of torrents","torrents whip"}));
   set_long("%^CYAN%^The whip consists of a solid base of %^BOLD%^aquamarine%^RESET%^%^CYAN%^. Extending from the base is a swirling mass of %^BLUE%^%^BOLD%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^r%^RESET%^%^CYAN%^ that seems to be barely contained into the shape of a whip by an invisible force.%^RESET%^");
   set_lore("Attributed to a priest of Ryorik by the name of Landon Ramark, the Whip of Torrents first came into history around the year 576.  Landon quested in the name of the Tempest to search for the legendary Seven Pearls of the Sea, artifacts of immense power.  Wishing to gain the upper hand over the flame-devoted sect of Ryorik's faithful and to strengthen the power of his water aspect in the lands, Landon thought the Seven Pearls would be the saving grace of the faith.  Landon created the Whip of Torrents to use in battle on his quest.  Around the year 585, Landon was said to have found a clue where one of the Pearls may be found.  Upon entering a mystical portal with Razashasa the sorceress, Kensung the warrior, and the ranger Nathaniel, the four were never seen or heard from again. - Tales of the Tides - Martyrs, Saints, and People of Importance withing Istishia's Faith - Meru Seaspray");
   set_property("lore difficulty",16);
   set_value(1000);
   set_property("enchantment",3);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   set_hit((:TO,"hit_func":));
}

int wieldme(){
   if((string)ETO->query_diety() == "ryorik"){
      tell_object(ETO,"%^CYAN%^Confidence flows into your heart as you wield the sacred whip.%^RESET%^");
	tell_room(EETO,"%^CYAN%^"+ETOQCN+" grasps the whip with ease.%^RESET%^",ETO);
	return 1;
   }else{
      tell_object(ETO,"%^BOLD%^%^BLUE%^The whip is cool in your grasp but you can feel the quivering power it contains.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" seems barely able to contain the power of the whip.%^RESET%^",ETO);
      return 1;
   }
}
	
int hit_func(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
    	
   if(random(1000) < 200){
      switch(random(65)){
         case 30..49:
            tell_object(ETO,"%^BOLD%^%^BLUE%^Your whip snakes around "+targ->QCN+"'s neck, choking "+targ->QO+"!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s whip snakes around your neck, choking you!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s whip snakes around "+targ->QCN+"'s neck, choking "+targ->QO+"!%^RESET%^",({targ,ETO}));
            set_property("magic",1);
            targ->set_tripped(1,"You're still weak from being choked.");
            targ->do_damage("torso",random(5)+6);
            remove_property("magic");
            break;
            
         case 50..64:
            tell_object(ETO,"%^BOLD%^%^CYAN%^Your whip blasts "+targ->QCN+" with a frothy spray of barely controlled power.%^RESET%^");
            tell_object(targ,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s whip strikes you, knocking you over as you are suddenly drenched in frigid and frothy water!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" strikes "+targ->QCN+" with "+ETO->QP+" whip, and "+targ->QCN+" is knocked over from a sudden blast of frothy water!%^RESET%^",({ETO,targ}));
            set_property("magic",1);
            targ->do_damage("torso",random(7)+10);
            remove_property("magic");
            break;
         default:
            tell_object(ETO,"%^BLUE%^The raging water within your whip lashes out at "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^BLUE%^"+ETOQCN+"'s whip strikes you with the power of a raging waterfall!%^RESET%^");
            tell_room(EETO,"%^BLUE%^"+ETOQCN+" strikes "+targ->QCN+" with "+ETO->QP+" whip.%^RESET%^",({ETO,targ}));
            set_property("magic",1);
            targ->do_damage("torso",random(6)+4);
            remove_property("magic");
            break;
                
      }
   }
   return 1;
}

int removeme(){
   if((string)ETO->query_diety() == "ryorik"){
      tell_object(ETO,"%^CYAN%^The confidence slowly trickles away as you release the whip.%^RESET%^");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+" releases the whip with a soft sigh.%^RESET%^",ETO);
      return 1;
   }else{
      tell_object(ETO,"%^CYAN%^You release the whip and immediately feel relief. You didn't realize the strain that containing such power caused.%^RESET%^");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+" seems to fight with the whip as "+ETO->QS+" unwields it.%^RESET%^",ETO);
      return 1;
   }
}
