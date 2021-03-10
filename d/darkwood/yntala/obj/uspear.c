#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";

void create() {
    ::create();
   set_id(({"spear","water spear","medium spear","coral spear","harpoon"}));
   set_name("%^BOLD%^%^CYAN%^F%^MAGENTA%^a%^RESET%^g%^BOLD%^a%^CYAN%^l%^RESET%^i%^BLUE%^c%^RESET%^");
   set_obvious_short("%^MAGENTA%^A %^BOLD%^c%^WHITE%^o%^RESET%^CYAN%^r%^RESET%^a%^BOLD%^%^MAGENTA%^l %^RESET%^%^MAGENTA%^spear%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^F%^MAGENTA%^a%^RESET%^g%^BOLD%^a%^CYAN%^l%^RESET%^i%^BLUE%^c%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^The long shaft of this exquisite spear is made entirely of knotty white"
" %^MAGENTA%^c%^WHITE%^o%^CYAN%^r%^RESET%^a%^BOLD%^%^MAGENTA%^l%^WHITE%^ that %^CYAN%^shimmers %^WHITE%^and"
" undulates in the light.  However, the most fascinating piece of this weapon is the speartip itself.  "
"The %^CYAN%^d%^WHITE%^i%^CYAN%^am%^WHITE%^o%^CYAN%^nd %^WHITE%^tip of the spear"
" has been carved most unusually...  Rather than being triangular in shape, it has been carved like a pyramid,"
" much like a harpoon rather than a spear.  Each face of the pyramid shaped tip dives down into deep facets that "
"reach the shaft of the spear, acting as deep blood grooves while the four sloping corners have been left razor sharp"
" as their serrated edges stagger towards the %^CYAN%^sp%^WHITE%^a%^CYAN%^rkl%^WHITE%^i%^CYAN%^ng%^WHITE%^,"
" piercing end that is just waiting to be used to rip out the entrails of some poor unsuspecting soul.%^RESET%^");
   set_lore("%^BOLD%^%^MAGENTA%^Rumor has it that this particular spear was named by a beautiful creature hidden within the depths of an ancient spring.  Shalarin are beautiful, mysterious, and apparently quite deadly by the looks of this lulling spear.  Forced into hiding by the evils that tainted their once prosperous forest, they relied heavily on the age old magics known to their people to create tools to protect their last hidden resort.");
   set("value",700);
   set_cointype("gold");
   set_property("enchantment",2);  
   set_item_bonus("attack bonus",1);
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   tell_object(ETO,"%^BOLD%^%^CYAN%^A surge of %^YELLOW%^electric energy %^CYAN%^courses through your veins as you wrap your hands around the shaft of the mighty %^WHITE%^spear!%^RESET%^");
   return 1;
}
int unwield_func(){
  tell_object(ETO,"%^CYAN%^You feel disappointed to release the spear from your grip.");
  return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 175){
      switch(random(7)){
         case 0..3:
            tell_room(environment(ETO),"%^RESET%^%^RED%^"+ETO->query_cap_name()+" thrusts the tip of the spear deep into "+target->query_cap_name()+"'s flesh and gives it a vicious twist before ripping it out in a %^BOLD%^spurt %^RESET%^%^RED%^of blood!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^RED%^You thrust the tip of your spear deep into "+target->query_cap_name()+"'s flesh and give it a vicious twist before ripping it out in a %^BOLD%^gory spurt %^RESET%^%^RED%^of blood!%^RESET%^",target);
            tell_object(target, "%^RESET%^%^RED%^"+ETO->query_cap_name()+" thrusts the tip of "+ETO->query_possessive()+" deep into your flesh and gives it a painful, vicious twist before ripping it out in a %^BOLD%^gory %^RESET%^%^RED%^display of your own %^BOLD%^spurting blood!%^RESET%^");
		  return roll_dice(1,10)+1;
 	   case 4:
            ETO->execute_attack();
  	      tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" lunges forward and repeatedly stabs  "+ETO->query_possessive()+" spear deeply into "+target->query_cap_name()+"'s flesh!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^RED%^You suddenly lunge forward and repeatedly stab "+target->query_cap_name()+"' with the tip of your spear!%^RESET%^");
            tell_object(target, "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" suddenly lunges forward and repeatedly stabs you with "+ETO->query_possessive()+" spear!%^RESET%^");
		  return roll_dice(1,8)+1;
         case 5..6:
            tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" quickly spins around and slaps "+target->query_cap_name()+"'s head with the butt of "+ETO->query_possessive()+" spear, knocking "+target->query_objective()+" senseless!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLUE%^You quickly spin around and slap "+target->query_cap_name()+"'s head with the butt of your spear, knocking "+target->query_objective()+" senseless!%^RESET%^",target);
            tell_object(target, "%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" quickly spins around and slaps the side of your head with the butt of "+ETO->query_possessive()+" spear, knocking you senseless!");
            target->set_paralyzed(20,"You groan as things still are fuzzy from the hit.");
                 return roll_dice(1,8)+1;
      }
   }
}
  
