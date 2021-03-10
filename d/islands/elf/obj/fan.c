// fancy fan for blade songstress
#include <std.h>
inherit "/d/common/obj/weapon/fan";

void create() {
    ::create();
   set_id(({"fan","bladed fan","fan of the elves"}));
   set_name("%^RESET%^%^MAGENTA%^elven fan%^RESET%^");
   set_obvious_short("%^RESET%^%^MAGENTA%^A bl%^CYAN%^a%^MAGENTA%^ded fan%^RESET%^");
   set_short("%^RESET%^%^MAGENTA%^A fan of the e%^GREEN%^l%^MAGENTA%^ves%^RESET%^");
   set_long("%^MAGENTA%^This is a masterwork fan that "+
   "looks like it could also be used as a "+
   "weapon.  It is crafted with %^GREEN%^thin blades"+
   "%^MAGENTA%^ of steel that protrude as points off of "+
   "the fan.  The fan has a symbol of %^GREEN%^seven "+
   "stars%^MAGENTA%^ painted on it and purple gems that"+
   " glimmer with a %^GREEN%^magical light.%^RESET%^");
   set_lore("This weapon was created by the high"+
   " elven wizards as a tribute to the old magic."+
   "  There are warriors who seek to use magic "+
   "and fight in close quarters.  The fan is one"+
   " such weapon.  Elves are trained to cast "+
   "their spells single-handed and to keep a "+
   "weapon to fend off attackers that would "+
   "seek to disrupt their spells.");
   set_property("lore difficulty",35);
   set("value",9000);
   set_property("enchantment",5);  
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}

int wield_func(){
 
     TO->set_property("able to cast",1);
      tell_room(environment(ETO),"%^CYAN%^The gems on "
           +ETOQCN+"'s weapon glow brightly.",ETO);
      tell_object(ETO,"%^CYAN%^The gems on the fan glow brightly.");
      return 1;
}
int unwield_func(){
  TO->set_property("able to cast",-1);
   tell_room(environment(ETO),"%^CYAN%^The weapon of "+ETOQCN+
   " stops glowing.",ETO);
   tell_object(ETO,"%^CYAN%^The gems stops glowing as you unwield the fan.");
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   if(random(1000) < 400){
     switch(random(6)){
      case 0..3:
        tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s fan penetrates into "
                  +target->QCN+", %^BOLD%^leaving%^RESET%^%^CYAN%^ a series of %^BOLD%^holes.",({target,ETO}));
        tell_object(ETO,"%^CYAN%^The fan penetrates "+target->QCN+
            ", %^BOLD%^leaving a series of holes.",target);
        tell_object(target, "%^CYAN%^"
         +ETO->QCN+"'s fan penetrates into"+
         " you, %^BOLD%^leaving a series of holes.");
         return roll_dice(2,8)+2;

     case 4:
            tell_room(EETO,"%^CYAN%^"+ETOQCN+" fan lets out a %^BOLD%^blast of wind%^RESET%^%^CYAN%^ that"+
                         " sends "+target->QCN+" %^BOLD%^tumbling over."
                         ,({target,ETO}));
            tell_object(ETO,"%^CYAN%^"+target->QCN+
                        " is sent tumbling from a %^BOLD%^blast of wind.",target);
            tell_object(target, "%^CYAN%^"+ETO->QCN+"'s fan "+
			"lets out a %^BOLD%^blast of wind%^RESET%^ that sends you %^BOLD%^tumbling over.");
            target->set_tripped(random(2)+1,
			"You try to get up, but the world is spinning.");
            return roll_dice(1,4)+1;
	  case 5:
            tell_room(EETO,"%^CYAN%^"+ETO->QCN+" swings the fan in a wide graceful motion at"+
                         " "+target->QCN+" and a gust of wind follows."
                         ,({target,ETO}));
            tell_object(ETO,"%^CYAN%^You swing the fan in a wide graceful motion at "
			   +target->QCN+" and a gust of wind follows.");
			tell_object(target,"%^CYAN%^"+ETO->QCN+
			  " swings the fan in a wide graceful motion at you and a gust of wind follows.");
			new("/cmds/spells/g/_gust_of_wind")->use_spell(ETO,target,15,100,"mage");
			return roll_dice(1,4)+1;
      }
   }
}
