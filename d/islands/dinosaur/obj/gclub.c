// really big club for giants
#include <std.h>
inherit "/d/common/obj/weapon/giant_club.c";

void create() {
    ::create();
   set_id(({"club","giant club","bone club","dino club","bone"}));
   set_name("%^BOLD%^%^WHITE%^Dino Sm%^RED%^a%^WHITE%^sher%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A giant d%^RED%^i%^WHITE%^no bone%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Giant Club%^RESET%^");
   set_long("This masterfully crafted club made from"+
   " a giant dinosaur bone.  It has several dark "+
   "%^RED%^runes%^RESET%^ carved all around the club.  A crusted "+
   "%^RED%^red paint%^RESET%^ fills the grooves.  Several %^RED%^dark red "+
   "gems%^RESET%^ are embedded in the business end of the club."+
   "  The other end of the bone club is shaved down "+
   "enough for a giant to hold it with both hands firmly.  ");
   set_property("lore difficulty",21);
   set_lore("This large bone appears "+
   "is crafted from the remains of a "+
   "large dinosaur.  The dark red runes"+
   " appear to be remains of various beasts."+
   "  The club is said to been filled with"+
   " the rampage of a cornered dinosaur by "+
   "a mysterious hermit mage.  Rumors of "+
   "this mage are not verified but stories "+
   "have be told of an old man seen doing "+
   "strange experements on the dinosaur island.");
   set_property("enchantment",4);  
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
   if((int)ETO->query_level() < 20 ) {
      tell_object(ETO,"%^RED%^You drop the club on yourself.");
      ETO->do_damage("torso",random(25)+25);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
   return 0;
   }
      tell_room(environment(ETO),"%^RED%^The club's runes flash dimly as "
	   +ETOQCN+" wields it.",ETO);
      tell_object(ETO,"%^RED%^The bone's runes flash dimly as you wield it.");
      return 1;
}
int unwield_func(){
   tell_room(environment(ETO),"%^RED%^"+ETOQCN+" releases the dinosaur bone.",ETO);
    tell_object(ETO,"%^RED%^You release your grip on the bone.");
         
                return 1;
}
int hit_func(object target) {
   int max;
   if(!objectp(target)) return 0;
   max = ETO->query_max_hp();
   // send them to rage if hp is 50%
   if(ETO->query_hp() < max / 2 && !ETO->query_property("raged") && !ETO->query_casting())
     {
	  tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+" breaks into a %^BOLD%^rage!",({ETO}));
      tell_object(ETO,"%^RED%^You see your %^BOLD%^injuries%^RESET%^%^RED%^ and the "+
	    "blood causes you to break into a desperate %^BOLD%^rage!",target);
	 new("/cmds/spells/r/_rage")->use_spell(ETO,ETO,25,100,"cleric");
	 return 1;
	 }
   if(random(400) < 100){
      switch(random(50)){
         case 0..30:
            tell_room(environment(ETO),"%^RED%^The ground %^RESET%^%^ORANGE%^shakes%^RED%^ as "
			  +ETO->query_cap_name()+"'s club crushes "
			  +target->query_cap_name()+" with a sickening crack.",({target,ETO}));
              tell_object(ETO,"%^RED%^You club "+target->query_cap_name()+
              " with a %^BOLD%^sickening%^RESET%^%^RED%^ crack.",target);
            tell_object(target, "%^RED%^"
			  +ETO->query_cap_name()+" lands a %^BOLD%^bone crushing%^RESET%^%^RED%^ blow"+
			  " as the club strikes you!");
              return roll_dice(3,8)+5;

           case 31..40:
            tell_room(environment(ETO),"%^RED%^The runes in the bone "+
			"%^BOLD%^glow%^RESET%^%^RED%^ durning a sickening strike.",({target,ETO}));
            tell_object(ETO,"%^RED%^The lines in the club glow as the club smashes into "+
              target->query_cap_name()+"!");
            tell_object(target, "%^RED%^The lines in the club glow"+
			  " as the wind is knocked out of you!");
			target->set_paralyzed(roll_dice(2,6),"%^BLUE%^You are regaining your breath.%^RESET%^");
            return roll_dice(1,8)+2;
         case 41..49:
            tell_room(environment(ETO),"%^BOLD%^%^RED%^The club's powerful"+
			 " strike drives "+target->query_cap_name()+" to the ground."
			 ,({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^RED%^A downward smash on "+target->query_cap_name()+
			" drives them into the ground.",target);
            tell_object(target, "%^BOLD%^%^RED%^"+ETO->query_cap_name()+"'s giant club"+
			  " throws you into the ground!");
            target->set_tripped(1,"%^BLUE%^You try to get up, but the world is spinning.");
			target->set_paralyzed(roll_dice(2,6),"%^BLUE%^You are regaining your breath.%^RESET%^");
            return roll_dice(2,4)+1;
      }
   }
}
