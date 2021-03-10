//large club for clubbing humans
#include <std.h>

inherit "/d/common/obj/weapon/club_lg.c";

int frenzy = 0;

void create() {
    ::create();
   set_id(({"club","large club","bone club","human bane","bone","mass of bones","mass"}));
   set_name("%^RESET%^%^ORANGE%^Human B%^RED%^a%^ORANGE%^ne%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A mass of b%^RED%^o%^ORANGE%^nes%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^A mass of b%^RED%^o%^ORANGE%^nes%^RESET%^");
   set_long("A rather sickly club seems made from crusted "+
   "%^RED%^gore%^RESET%^ and %^BOLD%^bones%^RESET%^.  Closer"+
   " inspection shows this club is made from a mass "+
   "of %^BOLD%^human spines%^RESET%^ and %^BOLD%^skulls%^RESET%^"+
   " that are somehow braided together with dry %^RED%^gore%^RESET%^ in"+
   " a sickly display of morbid art.  A %^BOLD%^%^BLACK%^blackened"+
   " rod%^RESET%^ protrudes from one end for the user to grasp. ");
   set_property("lore difficulty",21);
   set_lore("There have been many humans that arrived at the "+
   "island of the dinosaurs.  Some of these men and women were "+
   "found dead, some were never found.  This rather disturbing"+
   " weapon might shed some light on their fate.  The mass of "+
   "bones seems to give off a feeling of self loathing.  For "+
   "some reason just looking at it makes one feel angst for "+
   "the entire human race.");
   set_property("enchantment",4);  
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((int)ETO->query_level() < 20 ) {
      tell_object(ETO,"You drop the club on yourself.");
      ETO->do_damage("torso",random(25)+25);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
   return 0;
   }
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+"'s club chatters as it is lifted.",ETO);
      tell_object(ETO,"%^BOLD%^%^WHITE%^The club chatters as it is lifted.");
      return 1;
}
int unwield_func(){
    tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" released the club and looks more relaxed.",ETO);
    tell_object(ETO,"%^RED%^You release your grip on the bones and feel more at ease.");   
    return 1;
}
int hit_func(object target) {
 int i;
 string race;
 race = target->query_race();
   if(!objectp(target)) return 0;
   if(race == "human" && frenzy == 0 )
     { frenzy = 1;
      tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+
       "%^BOLD%^frenzies%^RESET%^RED%^ after hitting a human!",({ETO}));
      tell_object(ETO,"%^RED%^You hit the %^BOLD%^human%^RESET%^%^RED%^ and the "+
	    "blood causes you to %^BOLD%^frenzy!",target);
     }
 if( random(100) < 20 && frenzy == 1){	    
      tell_room(environment(ETO),"%^RED%^With incredible speed " 
	  +ETO->query_cap_name()+" thwacks "
	  +target->query_cap_name()+" %^BOLD%^repeatedly with his club.",({target,ETO}));
      tell_object(ETO,"%^RED%^You club "+target->query_cap_name()+
              " with a %^ORANGE%^mass of bones %^RED%^%^BOLD%^repeatedly%^RESET%^.",target);
      tell_object(target, "%^RED%^"
	  +ETO->query_cap_name()+" blurs as %^BOLD%^bone crushing%^RESET%^%^RED%^ blows"+
	  " repeatedly strike you!");
    //add random extra attacks
      for (i = 0; i < random(3)+1; i++){
         ETO->execute_attack(); }
      return 1;}
    
     if (race != "human") frenzy = 0;
      switch(random(200)){
         case 0..40:
            tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+
	      " brutally %^RESET%^%^ORANGE%^clubs%^RED%^ "
	      +target->query_cap_name()+" %^RESET%^as the club rattles %^RED%^earily.",({target,ETO}));
            tell_object(ETO,"%^RED%^Your %^RESET%^mass of bones%^RED%^ bashes "+target->query_cap_name()+
              " with the sound of %^RED%^bones rattling%^RED%^.",target);
            tell_object(target, "%^RED%^"
	      +ETO->query_cap_name()+" clubs you brutally as %^RESET%^mass of bones"+
	      " %^BOLD%^rattles%^RESET%^ after the blow%^RED%^.");
              return roll_dice(2,8)+5;

    
         case 41..49:
            tell_room(environment(ETO),"%^ORANGE%^There is a %^WHITE%^clatter of bones%^ORANGE%^ as "+
			 target->query_cap_name()+" is driven to the ground."
			 ,({target,ETO}));
            tell_object(ETO,"%^ORANGE%^A downward smash on "+target->query_cap_name()+
			" drives them into the ground.  The club's %^RESET%^bones clatter%^ORANGE%^"+
			" from the brutal strike.",target);
            tell_object(target, "%^ORANGE%^"+ETO->query_cap_name()+"'s mass of bones"+
			  " strikes you.  You hear it clatter as you are sent sprawling.");
            target->set_tripped(1,"%^BLUE%^You try to get up, but the world is spinning.");
			target->set_paralyzed(roll_dice(2,6),"%^BLUE%^You are regaining your breath.%^RESET%^");
            return roll_dice(2,4)+1;
      }
   
}
