#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";

void create() {
    ::create();
   set_id(({"spear","hunters spear","medium spear"}));
   set_name("%^RESET%^%^ORANGE%^Hunters spear");
   set_obvious_short("A medium spear");
   set_short("%^RESET%^%^ORANGE%^Hunters spear%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^The shaft of this spear has been carved of some sort of hard wood, though exactly"
" which sort is impossible to determine because the whole of the shaft has been wrapped in %^RED%^b%^ORANGE%^r"
"%^BLUE%^a%^RED%^i%^ORANGE%^d%^BLUE%^e%^RED%^d %^ORANGE%^leather that is so well worn, the exact colors of the"
" leather is impossible to make out, with the exception of an occassional glimpse of dull %^RED%^red%^ORANGE%^,"
" or washed-out %^BLUE%^blue%^ORANGE%^.  On one end of the spear, two %^RED%^f%^BOLD%^e%^BLUE%^a%^RESET%^"
"%^ORANGE%^t%^RED%^h%^BLUE%^e%^BOLD%^r%^RED%^s %^RESET%^%^ORANGE%^hang loose as decoration, while on the"
" other end, the %^RESET%^dull-colored %^ORANGE%^spear %^RESET%^tip %^ORANGE%^has been fastened in place by"
" many thin strands of tanned leather.%^RESET%^");
   set("value",700);
   set_cointype("gold");
   set_property("enchantment",3);  
   set_wield((:this_object(),"wield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   tell_object(ETO,"%^RESET%^%^RED%^You take the spear into your hands and can feel the excitement of the upcoming hunt boiling in your blood!%^RESET%^");     
   return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 215){
      switch(random(5)){
         case 0..1:
            tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" impales "+target->query_cap_name()+" with the spear!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^RED%^You impale "+target->query_cap_name()+" with the spear!%^RESET%^",target);
            tell_object(target, "%^RESET%^%^RED%^"+ETO->query_cap_name()+" impales you with the spear!%^RESET%^");
		  return roll_dice(1,8)+1;
 	   case 2..3:
  	      tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" lunges forward and thrusts "+ETO->query_possessive()+" spear deeply into "+target->query_cap_name()+"'s flesh!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^RED%^You suddenly lunge forward and thrust the tip of your spear deeply into "+target->query_cap_name()+"'s flesh!%^RESET%^");
            tell_object(target, "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" suddenly lunges forward and thrusts the tip of the spear into your flesh!%^RESET%^");
		  return roll_dice(1,8)+1;
         case 4:
            tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" quickly spins around and slaps "+target->query_cap_name()+"'s head with the butt of "+ETO->query_possessive()+" spear, knocking "+target->query_objective()+" senseless!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLUE%^You quickly spin around and slap "+target->query_cap_name()+"'s head with the butt of your spear, knocking "+target->query_objective()+" senseless!%^RESET%^",target);
            tell_object(target, "%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" quickly spins around and slaps the side of your head with the butt of "+ETO->query_possessive()+" spear, knocking you senseless!");
            target->set_paralyzed(20,"You groan as things still are fuzzy from the hit.");
                 return roll_dice(1,8)+1;
      }
   }
}
  
