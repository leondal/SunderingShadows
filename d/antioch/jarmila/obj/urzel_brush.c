#include <std.h>

#define MOBS "/realms/loki/random/mobs/"

inherit "/d/common/obj/weapon/sstaff.c";
int hit_func;
int wield_func;
int unwield_func;

create() {
   ::create();
   set_id(({"brush","paint brush","Urzel's Brush"}));
   set_name("Urzel's Brush");
   set_obvious_short("%^RESET%^%^ORANGE%^An oak%^BLACK%^%^BOLD%^e%^RESET%^%^ORANGE%^n paintbrush%^RESET%^");
   set_short("%^RESET%^%^RED%^Ur%^BOLD%^z%^RESET%^%^RED%^el's %^GREEN%^%^BOLD%^Bru%^RESET%^%^GREEN%^s%^BOLD%^h%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This seemingly simple and worn "+
   "oaken paintbrush would to most people be unremarkable and quite "+
   "average quality. However, instead of a %^RESET%^%^RED%^dried%^RESET%^%^GREEN%^ "+
   "caked %^RESET%^%^BLUE%^mess %^RESET%^%^ORANGE%^of %^RESET%^%^MAGENTA%^"+
   "paint%^RESET%^%^ORANGE%^, this brush seems to drip a constant %^RED%^%^BOLD%^"+
   "flow %^RESET%^%^ORANGE%^of %^YELLOW%^wet %^GREEN%^paint%^RESET%^%^ORANGE%^. "+
   "The handle itself is slim and countoured, tapering to a %^YELLOW%^brass "+
   "slip%^RESET%^%^ORANGE%^ that holds the mass of %^RESET%^trimmed "+
   "horsehairs%^RESET%^%^ORANGE%^. The paint flowing from the brush "+
   "is of every color and you wonder what magic could be "+
   "behind it.\n%^RESET%^");
   set_lore("%^GREEN%^%^BOLD%^Urzel as it is told, was a master painter, who was also the biggest con artist of "+
   "his time. While he COULD paint masterpeices, he prefered not to but instead cast extremely powerful "+
   "illusions on the canvas so that his clients would see exactly what they wanted to see in the "+
   "painting. While this worked for awhile, as word spread of his genius he found it harder and "+
   "harder to find time to be lazy. In the end he enchanted a set of his brushes so that he "+
   "could hire bums to paint his grand works for him while he sailed or drank%^RESET%^ ");
   set_property("lore difficulty",25);
   set_value(10000);
   set_property("enchantment",7);
   set_wc(0,0);
   set_large_wc(0,0);
   set_item_bonus("damage bonus",-5);
   set_property("able to cast",1);
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));

}

int wield_func(){
   if(ETO->query_level() < 25) {
     tell_object(ETO,"%^RESET%^%^ORANGE%^What would you do with a paint brush?!?%^RESET%^.");
     return 0;
   }
    tell_object(ETO,"%^YELLOW%^You hold the paint brush up and come to the sudden realization "+
	"that it has power no one could have guessed.%^RESET%^");
      tell_room(environment(ETO),""+ETO->query_cap_name()+" %^YELLOW%^brandishes the paintbrush "+
	  "like a weapon!%^RESET%^",ETO);
   return 1;
}


int unwield_func(){

      tell_object(ETO,"%^GREEN%^%^BOLD%^You lower the paintbrush, and wonder when you get to use it again.%^RESET%^");
      tell_room(environment(ETO),""+ETO->query_cap_name()+" %^GREEN%^%^BOLD%^lowers the paintbrush "+
	  "and "+ETO->query_subjective()+"%^GREEN%^%^BOLD%^ look contemplative.%^RESET%^",ETO);
      return 1;
   }

int hit_func(object target) {
            object ob, living_painting;
   if(!objectp(target)) return 0;
   if(random(1000) < 300){
      switch(random(12)){
        case 0..4:
            ETO->execute_attack();
            tell_room(environment(ETO),""+ETO->query_cap_name()+" %^RESET%^%^BOLD%^laughs "+
			"as "+ETO->query_subjective()+" %^RESET%^%^BOLD%^ whips paint "+
			"at "+target->query_cap_name()+"%^RESET%^%^BOLD%^!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^BOLD%^With a laugh, you whip paint "+
			"at "+target->query_cap_name()+"%^RESET%^%^BOLD%^ making "+
			"them stumble!%^RESET%^",({environment(ETO),target}));
            tell_object(target, ""+ETO->query_cap_name()+" %^RESET%^%^BOLD%^whips "+
			"the brush in your direction, making you stumble!",({environment(ETO),ETO}));
            target->set_paralyzed(3+random(4), "%^YELLOW%^You are trying to recover from the paint!");
        break;
			  
        case 5:
-
      		living_painting =new(MOBS"paint_monster");
            living_painting ->move(environment(ETO));
            ETO->add_protector(living_painting);
            ETO->add_follower(living_painting);
         case 6..11:
            tell_room(environment(ETO),"%^BLACK%^%^BOLD%^Suddenly "+ETO->query_cap_name()+"%^BLACK%^%^BOLD%^ "+
			"pauses in the battle and stepping forward quickly, seems to sign their "+
			"name on "+target->query_cap_name()+"%^BLACK%^%^BOLD%^!",({target,ETO}));
            tell_object(ETO,"%^BLACK%^%^BOLD%^You suddenly get a grand idea and decide to sign your "+
			"name on "+target->query_cap_name()+"%^BLACK%^%^BOLD%^!%^RESET%^",({environment(ETO),target}));
            tell_object(target, "%^BLACK%^%^BOLD%^With a smirk, "+ETO->query_cap_name()+" %^BLACK%^%^BOLD%^steps "+
			"forward and.. signs their name on you?!?%^RESET%^",({environment(ETO),ETO}));
            new("/cmds/spells/c/_charm_monster")->use_spell(ETO,target,20,100,"bard");
            break;
      }
   }
}
