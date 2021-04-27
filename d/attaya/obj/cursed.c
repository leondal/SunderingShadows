//Added minion summon on hit for fun - Octothorpe 1/28/12
//updated by Circe to new code, description, etc.  4/15/04

#include <std.h>
#include "../defs.h"
inherit "/d/common/obj/weapon/longsword";

object ob1;

void create(){
   ::create();
   set_name("cursed sword");
   set_id(({"cursed sword","cursed","titanium sword","sword","longsword","long sword"}));
   set_short("%^RESET%^%^RED%^cursed %^BOLD%^%^BLACK%^t%^WHITE%^i"+
      "%^BOLD%^%^BLACK%^tan%^WHITE%^i%^BOLD%^%^BLACK%^um %^RESET%^"+
      "%^RED%^sword%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^barbarous longsword%^RESET%^");
   set_long("This longsword is made of light-weight titanium.  The "+
      "metal is a %^BOLD%^%^BLACK%^dark gray %^RESET%^with hints of "+
      "%^BOLD%^silver%^RESET%^, and the razor-sharp cutting edge "+
      "reaches all the way from tip to hilt.  A deep %^RED%^blood "+
      "groove %^RESET%^has been scored into the blade and is stained "+
      "a faint %^RED%^red %^RESET%^from obvious use.  The hilt itself "+
      "has been carved from bone into the form of a disturbingly "+
      "life-like %^BOLD%^human skeleton%^RESET%^.");
    set_lore("This strange sword is said to house the mystical force "+
       "that animates the skeletal legionaries on the island of "+
       "Attaya.  Some say that the image of the skeleton in the hilt "+
       "matches that of each individual skeleton warrior, binding it to "+
       "to that soul forever.");
    set_value(1200);
    set_property("enchantment",4+random(2));
    set_property("lore difficulty",17);
    set_unwield((:TO,"unwieldme":));
    set_wield((: TO,"curse" :));
    set_hit((:TO,"hitme":));
}

int curse(){
   int align;
   align = ETO->query_alignment();
   if(ETO->query_level() < 25){
      tell_object(ETO,"%^BOLD%^%^RED%^You feel an intense pain "+
         "when you grasp the sword and are forced to release it!");
      tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" winces in pain "+
         "and releases the sword!",ETO);
      ETO->add_attacker(TO);
      ETO->do_damage("head",roll_dice(2,6));
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      return 0;
   }	
   if(align == 1 || align == 4 || align == 7){
      tell_object(ETO,"%^BOLD%^%^RED%^You hear an eerie "+
         "wail as a spectral force wrenches at your soul!");
      tell_room(EETO,"%^BOLD%^%^RED%^An eerie wail rises "+
         "from the sword and "+ETOQCN+" turns white as a "+
         "ghost!",ETO);
      ETO->add_attacker(TO);
	  ETO->do_damage("head",roll_dice(3,6));
      ETO->continue_attack();
      ETO->remove_attacker(TO);
	  return 1;
   } 
   if(!ETO->is_class("fighter")) {
      tell_object(ETO,"%^BOLD%^%^MAGENTA%^A spiritual "+
         "presence jumps from the sword and attempts to "+
         "strangle you!");
     tell_room(EETO,"%^BOLD%^%^MAGENTA%^A strange spectral "+
        "being pours out from the sword, strangling "+ETOQCN+"!",ETO);
     ETO->add_attacker(TO);
	 ETO->do_damage("head",roll_dice(3,6));
     ETO->continue_attack();
     ETO->remove_attacker(TO);
	 return 1;
   }
   tell_object(ETO,"%^BOLD%^The skeleton hilt is cool to your hand.");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" grips the skeleton hilt "+
      "of the sword tightly.",ETO);
   return 1;
}

int unwieldme(){
   tell_object(ETO,"%^RED%^You hear the echo of a laugh as you "+
      "release the sword with difficulty.");
   tell_room(EETO,"%^RED%^"+ETOQCN+" looks strangely amused as "+
      ""+ETO->QS+" sets aside the sword.",ETO);
   return 1;
}

int hitme(object targ){
   if(!living(ETO) || !living(targ)) return 0;
   if(!random(8)){
      switch(random(2)){
         case 0:
            tell_object(ETO,"%^BOLD%^As the sword strikes the flesh "+
               "of "+targ->QCN+", the weapon's spirit lashes out "+
               "with anger at the living!%^RESET%^");
            tell_object(targ,"%^BOLD%^You scream in terror as a spectral "+
               "entity lashes out at you from "+ETOQCN+"'s sword!%^RESET%^");
            tell_room(EETO,"%^BOLD%^"+targ->QCN+" screams as a "+
               "strange spirit lashes out at "+targ->QO+" from "+
               ""+ETOQCN+"'s sword!%^RESET%^",({ETO,targ}));
            set_property("magic",1);
            //targ->do_damage("torso",random(3)+4);
            set_property("magic",-1);
            break;
         case 1:
            tell_object(ETO,"%^BOLD%^%^BLACK%^Something leaps out of the "+
               "sword and defends you!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLACK%^Something leaps out of "+
               ""+ETOQCN+"'s sword and moves to attack you!%^RESET%^");
            tell_room(EETO,"%^BOLD%^%^BLACK%^Something leaps out of "+
               ""+ETOQCN+"'s sword and moves to attack "+targ->QCN+"!"+
               "%^RESET%^",({ETO,targ}));
            ob1=new(MON"cursed_entity");
            ob1->move(EETO);
            ob1->force_me("protect "+(string)ETO->query_name());
            ETO->add_follower(ob1);
            ETO->add_protector(ob1);
            break;
      }
      return roll_dice(1, 6);
   }
   return 0;
}