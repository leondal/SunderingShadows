#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/fan.c";
int w;
object ob;

create() {
    ::create();
   set_id(({ "sai","shining sai","sai" }));
   set_name("%^BOLD%^%^WHITE%^A shining sai%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Sai of the Senshi%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a shining sai made from gleaming %^RESET%^m%^BOLD%^%^WHITE%^i"
"%^RESET%^thr%^BOLD%^%^WHITE%^a%^RESET%^l%^BOLD%^%^WHITE%^.  Looking somewhat like a smaller"
" version of a fork, the longest tine of this weapon is only slightly longer than seven inches, with the two side"
" tines being only about three and a half inches long each.  The handle is straight and wrapped"
" in %^RESET%^%^ORANGE%^leather, %^BOLD%^%^WHITE%^ending in a pommel that has been embedded with an"
" unpolished %^GREEN%^emer%^WHITE%^a%^GREEN%^ld.  %^WHITE%^Overall this weapon looks like it could deal"
" a great deal of damage if held by the right hands.%^RESET%^");
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
//   set_property("enchantment",5);
   set_item_bonus("armor bonus",2);
   set_item_bonus("damage bonus",2);
   set_item_bonus("attack bonus",2);
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   w = 0;
   set_overallStatus(220);
   set_property("no disenchant",1);
   set_value(0);   
}
int wield_func(){
   int i;

   if(!living(ETO)) return 0;
   i = 1;
   while(ob = present("sai "+i,ETO)){
      if(ob != TO && ob->query_wielded()) w = 1;
      i++;
   }
   if(w) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^An overwhelming surge of power pulses through your body as you raise each sai over your head and clash them together while letting out a great battle cry.%^RESET%^");
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" lets loose a long battle cry as "+ETO->query_subjective()+" raises each sai over "+ETO->query_possessive()+" head and clashes them together, creating %^YELLOW%^sparks %^WHITE%^of pure %^YELLOW%^energy %^WHITE%^that rain down around "+ETO->query_objective()+". %^RESET%^",ETO);
      return 1;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The sai spins easily in your expert hands.. Yes, you are ready for anything.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" spins the sai expertly before gripping the handle, ready for anything.%^RESET%^",ETO);
   return 1;
}
int unwield_func(){
   if(w){
      tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the disappointment of the ending battle flow through your veins as you unwield the sai.%^RESET%^");
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" reluctantly lets loose the sai as the energy around "+ETO->query_objective()+" seems to die down.%^RESET%^",ETO);
      w = 0;
      return 1;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^You spin the sai once more before unwielding it.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" spins the sai once more before unwielding it.%^RESET%^",ETO);
   return 1;
}
int hit_func(object target){
   string targname, targpos, attname;
   if(w==1){
      if(random(1000) < 155){
          targname = target->query_cap_name();
          targpos = target->query_possessive();
          attname = ETO->query_cap_name();
          switch(random(100)){
              case 0..60:
                tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ attname +" spins and boxes both sides of "+ targname +"'s head with a sai, leaving "+target->query_objective()+" in a daze!%^RESET%^",({target,ETO}));
                tell_object(ETO,"%^RESET%^%^ORANGE%^You spin quickly and bring each sai up to slap against either side of "+ targname +"'s head, leaving "+target->query_objective()+" in a daze!%^RESET%^",({environment(ETO),target}));
                tell_object(target,"%^RESET%^%^ORANGE%^"+ attname +" spins quickly and slaps a sai against either side of your head, leaving you in a daze!%^RESET%^",({environment(ETO),ETO}));
                target->set_paralyzed(20, "You are still trying to stand!");
	          return roll_dice(1,9)+1;
                break;
              case 61..98:
                ETO->execute_attack();
                tell_room(environment(ETO),"%^RESET%^%^RED%^"+ attname +" plunges one sai deep into "+ targname +"'s flesh and then quickly follows it up with a stab from the other!%^RESET%^",({target,ETO}));
                tell_object(ETO,"%^RESET%^%^RED%^You plunge one sai deep into "+ targname +"'s flesh and follow it up with another quick stab from the other sai!%^RESET%^",({environment(ETO),target}));
                tell_object(target,"%^RESET%^%^RED%^"+ attname +" plunges one sai deep into your flesh before quickly following it up with another quick stab from the second sai!%^RESET%^",({environment(ETO),ETO}));
	          return roll_dice(1,9)+1;
                break ;
              case 99:
                tell_room(environment(ETO),"%^RESET%^%^RED%^With one fluid, viscious movement, "+ attname +" plunges the tines of each sai deep into each of "+ targname +"'s ears, causing "+ targpos +" body to spasm before "+ attname +" withdraws the bloodied blades and allows "+ targpos +" body to fall limply to the ground.%^RESET%^",({target,ETO}));
                tell_object(ETO,"%^RESET%^%^RED%^With one fluid, viscious movement, you plunge the tines of each sai deep into each of "+ targname +"'s ears and watch "+ targpos +" body spasm before you pull out the blades and watch "+ targpos +" body fall limply to the ground!%^RESET%^",({environment(ETO),target}));
                tell_object(target,"%^RESET%^%^RED%^Everything fades to black as "+ attname +" uses one fluid, viscious movement to plunge the tines of each sai deep into either side of your head.\n%^BOLD%^%^BLACK%^As your body falls limply to the ground you cannot help but think about how much more you had to do... How could it end like this?%^RESET%^",({environment(ETO),ETO}));
                target->cause_typed_damage(target, "torso", 10000000, "piercing");
                break;
         }
      }
   }
   else{
   return 1;
   }
}