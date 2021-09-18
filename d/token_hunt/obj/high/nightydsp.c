//Original by Tsera, ported to high vendor by Octothorpe 4/29/10
// Modified to be balanced on the new item system, returned to the high vendor. N, 11/12.
#include <std.h>
#include <daemons.h>
#include <move.h>
#define WAIT_TIME 144000
inherit ARMOUR;

int used_time;
string place, where, *exits, dest_name;
object dest;

void create(){
   ::create();
   set_name("aura of shade");
   set_id(({"cape","halo","shadow cloak","aura of shade","Aura of shade","Aura of Shade","aura","shade","shadows","shadow","cloak","shadow cloak"}));
   set_short("%^BOLD%^%^BLACK%^A%^RESET%^%^RED%^u%^BLACK%^%^BOLD%^ra "+
      "of Sh%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^de%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This flickering, formless mass of "+
      "tenebrous shade undulates like a living thing.  A halo of "+
	  "darkness, it flows liquidly giving off an unearthly %^BLUE%^ch"+
	  "%^CYAN%^i%^BLUE%^ll%^BLACK%^ as small tentacles of shadow lance "+
	  "and curl outward, hungry to consume all %^YELLOW%^l%^WHITE%^i"+
	  "%^YELLOW%^ght%^BLACK%^ that comes near. Within the darkness, "+
	  "shapes form and disappear so quickly that you cannot be sure "+
	  "they were there, %^RESET%^%^BLUE%^serpentine%^BOLD%^%^BLACK%^ "+
	  "bodies slithering within, their eyes flashing a %^RESET%^%^RED%^"+
	  "blood red%^BOLD%^%^BLACK%^ before vanishing once more into the "+
	  "murk.%^RESET%^");
   set_lore("%^BOLD%^%^BLACK%^Staring into the unholy darkness before "+
      "you, you come to the startling realization that you are looking "+
	  "upon a fragment of a newborn god. Across the realms through the "+
	  "concerted efforts of many faiths of light and darkness, the "+
	  "knowledge of the upstart Durias has been locked away or outright "+
	  "destroyed in an attempt to keep his faith from gaining ground. "+
	  "It seems though the tidbits you have come across in your "+
	  "studies may be true after all. Sure to attract the eye of any "+
	  "with the proper appreciation of his charge, this essence is "+
	  "said to transform its wielder into a creature of darkness, "+
	  "able to %^WHITE%^<phase> %^BLACK%^through barriers as if they "+
	  "were nothing at all.");
   set_property("lore difficulty",30);	  
   set_weight(1);
   set_size(-1);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_property("evil item",1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_value(0);
   set_wear((:TO,"wear_it":));
   set_struck((:TO,"struck":));
   set_heart_beat(1);
   set_overallStatus(220);
   set_property("no disenchant",1);
}

void init(){
   ::init();
   add_action("shift","phase"); // changed keyword, was conflicting with Klauth's robes. N, 11/12.
   add_action("supplicate","supplicate");
   if(!interactive(ETO)) return;
   ETO->force_me("wear aura");
}

int wear_it(string str){
   string myrace;
   tell_object(ETO,"%^BOLD%^%^BLACK%^Dark shadows flow downwards along "+
      "your body, entwining themselves around you like a dark halo.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The shade flows "+
      "downward along "+ETO->query_cap_name()+"'s body, entwining "+
	  "itself about "+ETO->query_objective()+" like a dark halo.%^RESET%^",ETO);
   myrace = ETO->query_race();
   if(myrace != "shade") { // adding this as it makes no RP sense for a cloak of shadows to bother a shadow-shrouded shade. N, 1/16.
     if(member_array(ETO->query_race(),PLAYER_D->night_races()) != -1) set_item_bonus("sight bonus",3);
     else set_item_bonus("sight bonus",-3); // conveys the darkening effect regardless of race. N, 11/12
   }
   ETO->set_property("added short",({" %^BOLD%^%^BLACK%^(shrouded by shadows)%^RESET%^"}));
   return 1;
}

void unwear(){
   tell_object(query_worn(),"%^BOLD%^%^BLACK%^The aura is part of you, "+
      "it will not be discarded so easily!%^RESET%^");
   return 0;
}

void drop(){
   tell_object(query_worn(),"%^BOLD%^%^BLACK%^The aura will not part "+
      "from you so easily!%^RESET%^");
   return 1;
}

int struck(int damage, object what, object who){
   if(query_worn()){
      if(!random(3)){
         switch(random(3)){
            case 0:
               tell_room(EETO,"%^BLUE%^A serpentine tendril lances "+
			      "outward from "+ETO->query_cap_name()+"'s %^BOLD%^"+
				  "%^BLACK%^shroud %^RESET%^%^BLUE%^and deflects "+
				  ""+who->query_cap_name()+"'s blow harmlessly to "+
				  "the side.%^RESET%^",({who,ETO}));
               tell_object(who,"%^BLUE%^A serpentine tendril lances "+
			      "outward from "+ETO->query_cap_name()+"'s %^BOLD%^"+
				  "%^BLACK%^shroud, %^RESET%^%^BLUE%^deflecting your "+
				  "blow harmlessly to the side.%^RESET%^");
               tell_object(ETO,"%^BLUE%^A serpentine tendril lances "+
			      "outward from your %^BOLD%^%^BLACK%^shroud, %^RESET%^"+
				  "%^BLUE%^deflecting the incoming blow harmlessly to "+
				  "the side.%^RESET%^");
               break;
            case 1:
               tell_room(EETO,"%^BOLD%^%^BLACK%^Great black wings "+
			      "unfurl suddenly from "+ETO->query_cap_name()+"'s "+
				  "back, whipping around to parry "+
				  ""+who->query_cap_name()+"'s strike!%^RESET%^",({who,ETO}));
               tell_object(who,"%^BOLD%^%^BLACK%^Great black wings "+
			      "unfurl suddenly from "+ETO->query_cap_name()+"'s "+
				  "back, whipping around to parry your strike!%^RESET%^");
               tell_object(ETO,"%^BOLD%^%^BLACK%^Great black wings "+
			      "unfurl suddenly from your back, whipping around to "+
				  "parry "+who->query_cap_name()+"'s strike!%^RESET%^");
              break;
            case 3:
               tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+""+
			      "'s form suddenly flickers as "+who->query_cap_name()+""+
				  "'s strike passes through "+ETO->query_objective()+" "+
				  "as harmlessly as if "+ETO->query_subjective()+" "+
				  "were a shadow.%^RESET%^",({who,ETO}));
               tell_object(who,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"+
			      ""'s form suddenly flickers as your strike passes "+
				  "through "+ETO->query_objective()+" as harmlessly "+
				  "as if "+ETO->query_subjective()+" were a shadow.%^RESET%^");
               tell_object(ETO,"%^BOLD%^%^BLACK%^Your form suddenly "+
			      "flickers as "+who->query_cap_name()+"'s strike "+
				  "passes through you as harmlessly as if you were "+
                  "a shadow.%^RESET%^");
               break;
         }
         return 0;
      }
   }
   return damage;
}

void heart_beat(){
   if(query_worn()){
      switch(random(1000)){
      case 0..998:
         break;
      default:
        switch(random(18)) {
	  case 0:
         if(WAIT_TIME < (time() - used_time)){
            tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
               "ripple as a voice conveys with cool confidence:\n"+
               "%^RESET%^%^RED%^You have been careless in your "+
			   "devotion to me, prepare to remedy that.%^RESET%^");	
            tell_object(ETO,"%^BLUE%^A dark serpent uncoils out of the "+
			   "%^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^and plunges "+
			   "deep into your chest causing excruciating pain!%^RESET%^");
            tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
			   "ripple as a voice conveys with cool confidence:\n"+	
               "%^RESET%^%^RED%^Perhaps you will remember your "+
			   "obligation to the Obisdian Throne in the future, and "+
			   "will provide sufficient supplication from now on...%^RESET%^");
			ETO->cause_typed_damage(ETO, "torso", (int)ETO->query_hp() / 2, "untyped");
			used_time = time();
            ETO->set_paralyzed(random(40)+20,"%^RED%^You are reeling "+
			   "from the pain!%^RESET%^");
         }
		 else{
		    tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
			   "ripple as a voice conveys with cool confidence:\n"+
			   "%^RESET%^%^RED%^Remember to %^BOLD%^%^WHITE%^supplicate "+
			   "%^RESET%^%^RED%^yourself to me...it is the price "+
			   "you pay for your newfound power.%^RESET%^");
		 }
         break;		 
	  case 1:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^Reserve death for the useless...the "+
			"worthy can be tempered through suffering.%^RESET%^");
		 break;		 
	  case 2:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^I do hope you enjoy games my "+
			"friend, because I am in the mood to play.%^RESET%^");
		 break;		 
	  case 3:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^More gods shall fall in the wake of "+
			"my rise.  Perhaps you will earn yourself a scrap of "+
			"that power...%^RESET%^");
		 break;		 
	  case 4:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^Spread my name and I will raise you "+
			"to heights unimagined.%^RESET%^");
		 break;		 
	  case 5:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^My darkness is your sanctuary...%^RESET%^");
		 break;		 
	  case 6:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^So much ambition...a shame you are "+
			"still so limited.%^RESET%^");
		 break;		 
	  case 7:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^You belong to me now, but that does "+
			"not mean we cannot enjoy our time together...%^RESET%^");
		 break;		 
	  case 8:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^I have no patience for parasites...%^RESET%^");
		 break;		 
	  case 9:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^Are you truly worth of this gift?%^RESET%^");
		 break;		 
	  case 10:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^As my srength grows, so too does "+
			"yours...%^RESET%^");
		 break;		 
	  case 11:
	     tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
		    "ripple as a voice conveys with cool confidence:\n"+
			"%^RESET%^%^RED%^All power comes with a price, child...%^RESET%^");
		 break;
      case 12:
         tell_object(ETO,"%^BOLD%^%^BLACK%^Tendrils of shade weave "+
		    "outward from your back, unfurling into gle%^WHITE%^a"+
			"%^BLACK%^ming black wings before collapsing back into "+
			"the darkness.%^RESET%^");
         if(!ETO->query_invis()){
            tell_room(EETO,"%^BOLD%^%^BLACK%^Tendrils of shade weave "+
			   "outward from "+ETO->query_cap_name()+"'s back, "+
			   "unfurling into gle%^WHITE%^a%^BLACK%^ming black "+
			   "wings before collapsing back into the "+
			   "darkness.%^RESET%^",ETO);
         }
         else{ 
		    tell_room(EETO,"%^BOLD%^%^BLACK%^Tendrils of shade weave "+
			   "outward from the dark and unfurl into gle%^WHITE%^a"+
			   "%^BLACK%^ming black wings before collapsing back "+
			   "into the darkness.%^RESET%^",ETO); }
         break;
     case 13:
        tell_object(ETO,"%^BLUE%^A dark serpent slithers out of "+
		   "the %^BOLD%^%^BLACK%^shadows%^RESET%^%^BLUE%^ and hisses "+
		   "as it entwines itself about your arm before dispersing "+
		   "into a fine %^BOLD%^%^BLACK%^black mist.%^RESET%^");
        if(!ETO->query_invis()){
           tell_room(EETO,"%^BLUE%^A dark serpent slithers out of "+
		      "the %^BOLD%^%^BLACK%^shadows%^RESET%^%^BLUE%^ and "+
			  "hisses as it entwines itself about "+
			  ""+ETO->query_cap_name()+"'s arm before dispersing into "+
			  "a fine %^BOLD%^%^BLACK%^black mist.%^RESET%^",ETO);
        }
        else{
		   tell_room(EETO,"%^BLUE%^A soft hiss echoes throughout "+
		      "the area.%^RESET%^",ETO); }
        break;
     case 14:
        tell_object(ETO,"%^BOLD%^%^BLACK%^The sh%^RESET%^a%^BOLD%^"+
		   "%^BLACK%^dows about you flicker and bend toward you as "+
		   "if wanting to touch you.%^RESET%^");
        if(!ETO->query_invis()){
           tell_room(EETO,"%^BOLD%^%^BLACK%^The sh%^RESET%^a%^BOLD%^"+
		      "%^BLACK%^dows about "+ETO->query_cap_name()+" flicker "+
			  "and bend toward "+ETO->query_objective()+" as if wanting "+
			  "to touch "+ETO->query_objective()+".%^RESET%^",ETO);
        }
        break;
     case 15:
        tell_room(EETO,"%^BOLD%^%^BLACK%^From within the darkness "+
		   "slitted %^RESET%^%^RED%^cr%^BOLD%^i%^RESET%^%^RED%^mson "+
		   "eyes%^BLACK%^%^BOLD%^ peer out at you before vanishing "+
		   "completely.%^RESET%^");
        break;
     case 16:
        if(!ETO->query_invis()){
           tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s "+
		      "shadow grows larger behind "+ETO->query_objective()+", "+
			  "a d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^mon%^RED%^i"+
			  "%^BLACK%^c silhouette with outstretched "+
			  "wings.%^RESET%^",ETO);
        }
        else{
		   tell_room(EETO,"%^BOLD%^%^BLACK%^A dark shadow grows from "+
		      "seemingly nowhere and transforms into the image of "+
			  "a d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^mon%^RED%^i"+
			  "%^BLACK%^c silhouette with outstretched "+
			  "wings.%^RESET%^",ETO); }
        break;
     case 17:
        tell_object(ETO,"%^BOLD%^%^BLACK%^Whisps of darkness whip "+
		   "violently about your body.%^RESET%^");
        if(!ETO->query_invis()){
           tell_room(EETO,"%^BOLD%^%^BLACK%^Whisps of darkness whip "+
		      "violently about "+ETO->query_cap_name()+"'s body.%^RESET%^",ETO);
        }
        break;
      }
     }
   }
   return;
}

void shift(string str){
   place = (environment(ETO));
   if(!objectp(ETO)) return;
   if(!objectp(place)) return;
   if(!str){
      tell_object(ETO,"%^RED%^Shift where?\n");
      return 0;
   }
   if(sscanf(str, "%s",where)!= 1){
      tell_object(ETO,"You cannot shift "+str+"!  Try <shift [direction]>.\n");
      return 0;
   }
   exits = place->query_exits();
   dest_name = place->query_exit(where);
   dest = find_object_or_load(dest_name);
   if(member_array(where, exits) == -1){
      tell_object(ETO,"You can't shift without an exit.\n");
      return 0;
   }
   if(place->query_property("no phase")){
      tell_object(ETO,"You cannot shift there, it is magically protected!\n");
      return 1;
   }
   if(!place->query_door(where)){
      tell_object(ETO,"There is no door blocking the "+where+" exit!");
      return 0;
   }
   tell_room(place,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" melts "+
      "into the shadows and disappears!%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You become as one with the "+
      "shadows, and much like a dark fog, slip through the cracks "+
	  "around the door before reforming yourself on the other side!%^RESET%^");
   ETO->add_exp(-1*(to_int((int)ETO->query_exp() * 0.02)));
   tell_object(ETO,"%^BOLD%^%^RED%^You feel a little weakened by the effort...%^RESET%^");
   ETO->move_player(dest);
   tell_room(dest,"%^BOLD%^%^BLACK%^A dark fog of shadows seep through "+
      "the door before swirling into the form of "+ETO->query_cap_name()+".",ETO);
   return 1;
}

int supplicate(){
   if(!objectp(ETO)) return 0;
   if(!(query_worn())){
      tell_object(ETO,"%^BOLD%^You need to wear the aura to be able "+
	     "to supplicate to Durias.%^RESET%^");
      return 1;
   }
   if(ETO->query_property("supplicated")){
      tell_object(ETO,"%^BOLD%^%^BLACK%^You instinctively know that "+
	     "Durias is satisfied with your devotion, for the "+
		 "moment...%^RESET%^");
      return 1;
   }
   tell_object(ETO,"%^BLUE%^You slowly drop to your knees and "+
      "bow your head.  The %^BOLD%^%^BLACK%^shadows %^RESET%^"+
	  "%^BLUE%^around you billow expectantly...%^RESET%^");
   tell_room(EETO,"%^BLUE%^"+ETO->QCN+" drops to "+ETO->QP+" knees "+
      "and bows "+ETO->QP+" head.  The %^BOLD%^%^BLACK%^shadows "+
	  "%^RESET%^%^BLUE%^around "+ETO->QCN+" begin to "+
	  "billow...%^RESET%^",ETO);
   tell_object(ETO,"%^BLUE%^A dark serpent uncoils out of the "+
      "%^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^and plunges "+
      "deep into your chest causing excruciating pain!%^RESET%^");
   tell_room(EETO,"%^BLUE%^A dark serpent uncoils out of the "+
      "%^BOLD%^%^BLACK%^shadows %^RESET%^%^BLUE%^around "+
	  ""+ETO->query_cap_name()+" and plunges deep into "+
	  ""+ETO->QP+" chest!%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^The tendrils of shade "+
      "ripple as a voice conveys with cool confidence:\n"+
	  "%^RESET%^%^RED%^So painfully delicious...%^RESET%^");
   ETO->cause_typed_damage(ETO, "torso", (int)ETO->query_hp() / 4, "untyped");
   used_time = time();
   ETO->set_paralyzed(random(4)+4,"%^RED%^You are reeling "+
      "from the pain!%^RESET%^");
   ETO->add_attack_bonus(2);
   ETO->add_damage_bonus(2);
   ETO->set_property("supplicated",1);
}
