#include <std.h>
inherit "/d/common/obj/clothing/magerobe";
string place, where, *exits, dest_name;
int deception;
object dest;
void create()
{
  ::create(); 
      set_name("%^BOLD%^%^BLACK%^Sh%^RESET%^a%^BOLD%^%^BLACK%^dow R%^RESET%^o%^BOLD%^%^BLACK%^bes%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A long dark flowing robe%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^a%^BOLD%^%^BLACK%^dow R%^RESET%^o%^BOLD%^%^BLACK%^bes%^RESET%^");
      set_id(({"robe","robes","magerobes","shadowrobes","shadow robes","Shadowrobes"}));
set_long("%^BOLD%^%^BLACK%^These long black robes are exquisitely tailored from the finest of black"
"%^RESET%^ s%^BOLD%^%^BLACK%^i%^RESET%^l%^BOLD%^%^BLACK%^k%^RESET%^s %^BOLD%^%^BLACK%^with the slightest of hints of"
" %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld %^BLACK%^t%^YELLOW%^hr%^BLACK%^ea%^YELLOW%^d%^BLACK%^in%^YELLOW%^g"
" %^RESET%^%^BOLD%^sparkling %^BLACK%^within."
"  Almost %^RESET%^h%^BOLD%^a%^BLACK%^z%^RESET%^y %^BOLD%^%^BLACK%^in appearances, they are extremely %^RESET%^light weight %^BOLD%^%^BLACK%^and their %^RESET%^fl%^BOLD%^%^BLACK%^o%^RESET%^wing %^BOLD%^%^BLACK%^lengths would easily touch the floor when worn by even the tallest of men.  A tall, upturned collar dips into a %^RESET%^sw%^BOLD%^%^BLACK%^eep%^RESET%^ing %^BOLD%^%^BLACK%^v pattern about the torso and the robes are secured by unseen methods."
"  Hidden within the folds of the garment are several strategically placed pockets.%^RESET%^\n");
 set_lore("%^BOLD%^%^BLACK%^It is rumored that years ago a high priest of Mask was gifted with robes blessed from the Lord of Shadows himself.  It is said that a rogue of the rival lord Cyric, killed the priest of Mask and kept the sacred robes for himself until such a day he can be defeated and the robes reclaimed.%^RESET%^");
set_weight(4);
   set_value(0);
set_ac(0);
set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
set_item_bonus("intelligence",2);
set_item_bonus("sight bonus",2);
set_type("clothing");
set_limbs(({"torso"}));
set_wear((:this_object(),"wearme":));
set_remove((:this_object(),"unwearme":));
set_max_internal_encumbrance(21);
   deception = 0;
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wearme(string str){
 tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As if they were living, breathing beings, the shadows around "+ETOQCN+" begin to stir as "+ETO->query_subjective()+" slides into the dark robe, causing the area to feel much darker%^RESET%^.",ETO);
tell_object(ETO,"%^BOLD%^%^BLACK%^As you slip on the dark garment, living, breathing shadows seem to creep up from the darkest of recesses and curl around you, whispering %^RESET%^%^BLUE%^'%^RESET%^With us near, you may take on the form of shadows and <shift> through doorways, or decide whether you wish to <be truthful> or <be deceptive>.%^BLUE%^'%^RESET%^");

return 1;
}
int unwearme(string str){
tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" slowly slides off the dark garment, the shadows seem to slink back into the darkness%^RESET%^.",ETO);
  tell_object(ETO,"%^BOLD%^%^BLACK%^As you slide off the robe, the surrounding shadows seem to slink back into the darkness%^RESET%^.");
  return 1;
}
void init(){
  ::init();
add_action("shift","shift");
add_action("be","be");
}
void shift(string str){
  place = (environment(ETO));
if(!objectp(ETO)){
  return;
}
if(!TO->query_worn()){
  tell_object(TP,"%^BOLD%^%^BLACK%^You must be wearing the robes to use such gifts.%^RESET%^");
   return 1;
   }
   if(deception == 1){
   tell_object(ETO,"%^BOLD%^%^BLACK%^Do not expect the gifts of shadow while denying them so!%^RESET%^");
   return 1;
   }
   if(!str){
 tell_object(ETO,"Shift where?\n");
   return 1;
  }
   if(sscanf(str, "%s",where)!= 1){
  tell_object(ETO,"You cannot shift "+str+"!  Try <shift [direction]>.\n");
   return 1;
  }
  exits = place->query_exits();
 dest_name = place->query_exit(where);
dest = find_object_or_load(dest_name);
   if(member_array(where, exits) == -1){
   tell_object(ETO,"You can't shift without an exit.\n");
   return 1;
   }
   if(place->query_property("no phase")){
  tell_object(ETO,"You cannot shift there, it is magically protected!\n");
   return 1;
   }
   if(!place->query_door(where)){
  tell_object(ETO,"There is no door blocking the "+where+" exit!");
   return 1;
   }
  tell_room(place,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" melts into the shadows and disappears!",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You become as one with the shadows, and much like a dark fog, slip through the cracks around the door before reforming yourself on the other side!");
 ETO->add_exp(-1*(to_int((int)ETO->query_exp() * 0.03)));
 ETO->move_player(dest);
  tell_room(dest,"%^BOLD%^%^BLACK%^A dark fog of shadows seep through the door before swirling into the form of "+ETO->query_cap_name()+".",ETO);
  return 1;
}
void be(string str){
if(!str) return 0;
if(!TO->query_worn()){
   tell_object(TP,"%^BOLD%^%^BLACK%^You must be wearing the robes, my child.%^RESET%^");
return 1;
   }
   switch(str){
   case "truthful":
   TO->makecolor(str);
    tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As if they were living, breathing beings, the shadows begin to slip out of their dark recesses and surround "+ETOQCN+".",ETO);
tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows of the area seem to all whisper in soft hisses %^RESET%^'as you wish master' %^BOLD%^%^BLACK%^as they slip from their hiding places and gather around you.");
   deception = 0;
break;
   case "deceptive":
  TO->makecolor(str);
tell_room(environment(ETO),"%^BOLD%^%^BLACK%^All of the shadows surrounding "+ETOQCN+" suddenly slip away and disappear in nearby sheltered areas!",ETO);
tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows surrounding you hiss softly %^RESET%^'as you wish master' %^BOLD%^%^BLACK%^before melting away from you and disappearing into nearby crevices.");
   deception = 1;
   break;
   }
   return 1;
}
void makecolor(string str){
   string makemsg1, makemsg2, color;
  switch (str){
   case "truthful":
  TO->set_short("%^BOLD%^%^BLACK%^Sh%^RESET%^a%^BOLD%^%^BLACK%^dow R%^RESET%^o%^BOLD%^%^BLACK%^bes%^RESET%^");
  TO->set_obvious_short("%^BOLD%^%^BLACK%^A long dark flowing robe%^RESET%^");
   makemsg1 = "%^BOLD%^%^BLACK%^deceptive%^RESET%^";
  makemsg2 = "%^BOLD%^%^BLACK%^evil-hearted%^RESET%^";
   color = "%^BOLD%^%^BLACK%^black%^RESET%^";
   break;
  case "deceptive":
  TO->set_short("%^BOLD%^%^WHITE%^Robes %^RESET%^of the %^BOLD%^Pure-hearted%^RESET%^");
    TO->set_obvious_short("%^BOLD%^%^WHITE%^Long, flowing white robes%^RESET%^");
   makemsg1 = "%^BOLD%^%^WHITE%^honest and truthful%^RESET%^";
   makemsg2 = "%^BOLD%^%^WHITE%^pure-hearted%^RESET%^";
   color = "%^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^te%^RESET%^";
   break;
   }
   TO->set_long("%^BOLD%^%^BLACK%^These long "+color+" %^BOLD%^%^BLACK%^robes are exquisitely tailored from the finest of "+color+" %^RESET%^s%^BOLD%^%^BLACK%^i%^RESET%^l%^BOLD%^%^BLACK%^k%^RESET%^s %^BOLD%^%^BLACK%^with the slightest hints of %^YELLOW%^g%^BLACK%^o%^YELLOW%^ld %^BLACK%^t%^YELLOW%^hr%^BLACK%^ea%^YELLOW%^d%^BLACK%^in%^YELLOW%^g %^WHITE%^sparkling %^BLACK%^within.  Almost %^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^zy %^BOLD%^%^BLACK%^in appearances, they are extremely"
" %^RESET%^light weight %^BOLD%^%^BLACK%^and their %^RESET%^fl%^BOLD%^%^BLACK%^o%^RESET%^wing %^BOLD%^%^BLACK%^lengths would easily touch the floor when worn by even the tallest of men.   A tall, upturned collar dips into a %^RESET%^sw%^BOLD%^%^BLACK%^eep%^RESET%^ing %^BOLD%^%^BLACK%^v pattern about the torso and the robes are secured by unseen methods."
" Hidden within the folds of the garmet are several strategically placed pockets and the robes are designed so that only the most "+makemsg1+" %^BOLD%^%^BLACK%^of men could possibly wear them, proving that they are truly "+makemsg2+".%^RESET%^");
}
