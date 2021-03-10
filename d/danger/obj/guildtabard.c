

#include <std.h>
#include <move.h>
inherit ARMOUR;
string place, where, *exits, dest_name;
object dest;

void create(){
   ::create();
   set_name("%^RESET%^%^BOLD%^Hunter's %^YELLOW%^Glory %^WHITE%^Guild Tabard");
   set_id(({"tabard","tunic","guild tabard","Guild tabard","Tabard","Tunic","Battle's Glory","battle's glory","battles glory","guild tabard" }));
   set_short("%^BOLD%^%^WHITE%^The Hunter's Glory guild tabard%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This is a fairly elaborate guilds tabard dyed a brilliant shade of white.  Sleeveless, the long tunic would hang just over"
" the wearers thighs and is bordered with a pattern of intertwined %^BLUE%^blue waves %^WHITE%^and %^RED%^red fl%^RESET%^%^RED%^am%^BOLD%^es%^WHITE%^."
"  Across the chest of the tabard is a boldly displayed image of a large %^BLACK%^bird of prey %^WHITE%^with two %^YELLOW%^gleaming swords %^WHITE%^crossed"
" in its %^BOLD%^%^BLACK%^talons%^RESET%^.");
   set_lore("%^BOLD%^%^WHITE%^This tabard belongs to the infamous guild of Hunter's Glory, a guild of famously skilled glory hunters that seek out the most"
" powerful adventurers of the realms to test their skill.  Known for the ruthless fighting technique and diverse specialties, this guild consists of only"
" the best of the best.  To have such a tabard is truly a mark of pride.");
   set_property("lore difficulty",30);	  
   set_weight(0);
   set_size(-1);
   set_type("ring");
   set_limbs(({"neck"}));
   set_value(0);
   set_ac(1);
   set_wear((:TO,"wear_it":));
}

void init(){
   ::init();
   add_action("shift","shift");
}

int wear_it(string str){
   tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel a sense of great accomplishment as you proudly slip the %^WHITE%^tabard %^YELLOW%^over your armor.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^"+ETO->query_cap_name()+" proudly dons the %^WHITE%^white %^YELLOW%^tabard.%^RESET%^",ETO);
   return 1;
}


void shift(string str){
   place = (environment(ETO));
   if(!objectp(ETO)){
      return;
   }
   if(!str){
      tell_object(ETO,"%^RED%^Shift where?\n");
      return 0;
   }
   if(sscanf(str, "%s",where)!= 1){
      tell_object(ETO,"You cannot shift "+str+"!  Try <shift "+
	     "[direction]>.\n");
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
   tell_room(place,"%^BOLD%^%^YELLOW%^A brilliant %^WHITE%^flash %^YELLOW%^of %^WHITE%^light %^YELLOW%^errupts around "+ETO->query_cap_name()+", leaving only empty space where "+ETO->query_subjective()+" once stood!%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^YELLOW%^A brilliant %^WHITE%^flash %^YELLOW%^of %^WHITE%^light %^YELLOW%^errupts around you, and when it dies, you find yourself on the other side of the doorway!%^RESET%^");
   ETO->add_exp(-1*(to_int((int)ETO->query_exp() * 0.02)));
   ETO->move_player(dest);
   tell_room(dest,"%^BOLD%^%^WHITE%^A brilliant flash of %^YELLOW%^light %^WHITE%^nearly blinds you before dying out, leaving "+ETO->query_cap_name()+" standing at the doorway.",ETO);
   return 1;
}

