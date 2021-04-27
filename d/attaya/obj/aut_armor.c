/*Commented out the check_bounty() cuz I'm not sure if it's really necessary
to hit the wearer with a mycause over an IC transformation that is mostly
internalized in this case.  Plus I'm tired of seeing "Bob" getting the actions
need to be stopped echo every 10 min. - Octothorpe 1/11/12*/

//Octothorpe (2/4/10)
//Attaya, Abyssal Hide Armor

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/armour/hide.c";
#define WAIT_TIME 20000
int chaos;

void create(){
   ::create();
   set_name("abyssal hide");
   set_id(({"abyssal hide","armor","hide","abyssal","abyssal hide"}));
   set_obvious_short("%^BOLD%^%^BLACK%^h%^RESET%^i%^BOLD%^%^BLACK%^"+
      "deous l%^RESET%^ea%^BOLD%^%^BLACK%^thery ar%^RESET%^m%^BOLD%^"+
	  "%^BLACK%^or%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^a%^RESET%^by%^BOLD%^%^BLACK%^ssal h"+
      "%^RESET%^i%^BOLD%^%^BLACK%^de arm%^RESET%^o%^BOLD%^"+
	  "%^BLACK%^r%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This armor is composed of a thick jet "+
      "bl%^RESET%^a%^BOLD%^%^BLACK%^ck hide that is numbingly cold to "+
	  "the touch.  A dark h%^WHITE%^a%^BOLD%^%^BLACK%^ze permeates "+
	  "through the hide and clouds the air immediately around the "+
	  "armor.  Several undulating lines are carved all over the "+
	  "surface of the hide which have no discernable logic in their "+
	  "patterns.  A grotesque aura of evil pulses from the armor, "+
	  "poisoning the air with its stifling energy.%^RESET%^");
   set_lore("Objects made out of the remnants of destroyed demons can "+
      "be as dangerous as when its former host was alive.  Demon hides "+
	  "commonly form a 'symbiotic' relationship with the wearer.  Those "+
	  "that bear morals not compatible with those of the Abyss will soon "+
	  "become indoctrinated by the demonic taint.  Those that finally "+
	  "succumb to the posession will be granted considerable power, "+
	  "albeit in exchange for damnation.");
   set_size(-1);
   set_value(15000);
   set_property("lore",19);
   set_property("enchantment",5);
   set_property("no alter",1);
   set_item_bonus("strength",2);
   set_item_bonus("dexterity",2);
   set_heart_beat(1);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_struck((:TO,"struck_func":));
   chaos = 100;
}

void heart_beat(){
   int align;
   if(!living(ETO)) return;
   if(query_worn()){
      switch(random(1000)){
	     case 0..997:
		    break;
		 case 998:
            if(chaos > 0){
			   if(!random(20)){
			      chaos--;
			   }
			}   
			if(!chaos){
			   align = (int)ETO->query_alignment();
			   if(align != 9){
			      tell_object(ETO,"%^BOLD%^%^RED%^You are overcome with "+
				     "a torrent of chaotic urgings and psychotic "+
					 "outbursts.  %^RESET%^%^RED%^You feel as "+
					 "if something terrible has happened to you...%^RESET%^");
                  ETO->set_alignment(9);
                  KILLING_D->check_align(ETO);
			      //KILLING_D->check_bounty(ETO);
			   }			   
			}
            break;			
		 case 999:
            tell_object(ETO,"%^BOLD%^%^BLACK%^You feel an insidious "+
	           "twinge that begins deep within your chest, that causes "+
		       "your thoughts to be overcome with malice and chaos.%^RESET%^");
		    ETO->add_align_adjust(-2);
			KILLING_D->check_align(ETO);
			//KILLING_D->check_bounty(ETO);
			break;
	  }
   }
}

int wear_func(){
   int align;
   align = (int)ETO->query_alignment();
   if(base_name(ETO) == "/d/attaya/mon/autarkis") return 1;
   if(base_name(ETO) != "/d/attaya/mon/autarkis"){
      if((int)ETO->query_highest_level() < 25 || member_array("Life force of the Kinnesaruda has faded, Intruder and Autarkis are defeated",ETO->query_mini_quests()) == -1){
         tell_object(ETO,"%^BOLD%^%^BLACK%^The abyssal hide rejects you "+
	        "due to your pitiful weakness.");
	     return 0;
      }
   }
   if(align == 9){
      tell_object(ETO,"%^BOLD%^%^BLACK%^The hide cools to near freezing "+
	     "temperatures as you wear it, yet you find solace in its "+
		 "%^WHITE%^i%^CYAN%^c%^WHITE%^i%^BLUE%^ness%^BOLD%^%^BLACK%^.%^RESET%^");
	  tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" shivers momentarily as "+
	     ""+ETO->QS+" wears the hide.%^RESET%^",ETO);
	  return 1;
   }
   else{
      tell_object(ETO,"%^BOLD%^%^BLACK%^After you wear the hide it "+
	     "quickly %^RESET%^%^BLUE%^cools %^BOLD%^%^BLACK%^to below "+
		 "freezing temperatures, causing your entire body to go "+
		 "numb.%^RESET%^");
	  tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s face goes "+
	     "%^WHITE%^white %^BOLD%^%^BLACK%^and "+ETO->QS+" begins "+
		 "to shiver as "+ETO->QS+" wears the hide.%^RESET%^",ETO);	 
      return 1;
   }
}

int remove_func(){
   int align;
   align = (int)ETO->query_alignment();
   if(align == 9){
      tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the demonic hide "+
         "and your skin uncomfortably warms to room temperature.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" begins sweating as "+
         ""+ETO->QS+" removes the demonic hide.%^RESET%^",ETO);
	  return 1;
   }
   else{
      tell_object(ETO,"%^BOLD%^%^BLACK%^You begin to regain feeling throughout "+
         "your body as you remove the hide.%^RESET%^");
	  tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s face returns to "+
	     "its normal color as "+ETO->QS+" removes the hide.%^RESET%^",ETO);	 
      return 1;
   }
}

int struck_func(int damage, object what, object who){
   int align;
   align = (int)ETO->query_alignment();
   if(align == 9){
      if(!random(3)){
         tell_object(ETO,"%^BOLD%^%^BLACK%^The dark h%^WHITE%^a"+
            "%^BOLD%^%^BLACK%^ze that surrounds the hide causes "+
            ""+who->QCN+"'s attack to miss you.%^RESET%^");
         tell_object(who,"%^BOLD%^%^BLACK%^The dark h%^WHITE%^a"+
            "%^BOLD%^%^BLACK%^ze that surrounds "+ETO->QCN+"'s "+
            "hide armor causes you to miss your attack on them.%^RESET%^");
         tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^The dark "+
            "h%^WHITE%^a%^BOLD%^%^BLACK%^ze that surrounds "+ETO->QCN+"'s "+
            "hide armor causes "+who->QCN+" to miss their attack on "+
            "them.%^RESET%^",({who,ETO}));
        return 0;
      }
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^The dark h%^WHITE%^a"+
       "%^BOLD%^%^BLACK%^ze that surrounds the hide causes "+
       "part of "+who->QCN+"'s attack to miss you.%^RESET%^");
   tell_object(who,"%^BOLD%^%^BLACK%^The dark h%^WHITE%^a"+
       "%^BOLD%^%^BLACK%^ze that surrounds "+ETO->QCN+"'s "+
       "hide armor causes you to miss part of your attack on them.%^RESET%^");
   tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^The dark "+
       "h%^WHITE%^a%^BOLD%^%^BLACK%^ze that surrounds "+ETO->QCN+"'s "+
       "hide armor causes "+who->QCN+" to miss part of their attack on "+
       "them.%^RESET%^",({who,ETO}));
   return (damage * 3) / 4;
}