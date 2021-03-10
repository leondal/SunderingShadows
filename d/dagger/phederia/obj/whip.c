#include <std.h>
inherit "/std/weapon";
create(){
  ::create();
  set_id(({"whip","bloody whip"}));
  set_name("bladed whip");
  set_short("%^BOLD%^%^RED%^Bloody whip%^RESET%^");
  set_long(
  "%^YELLOW%^"
  "  This whip is made from tightly braided pale yellow leather."
  "  A brass skull adorns the pommel of the weapon and the end of the 9ft lash ends with a serries of dark steel blades woven into the leather."
  "   A single %^RED%^rune%^YELLOW%^ adorns the brass skull that glows brightly when fresh blood is tasted by the steel blades."
  "   Blood is crusted along the length of the length of the weapon and no amount of cleaning ever seems to take it out."
  );
  set_weight(5);
  set_size(1);
  set_value(1500);
  set_wc(1,4);
  set_large_wc(1,4);
  set_property("enchantment",4);
  set_type("slashing");
  set_prof_type("whip");
  set_hit((:TO,"extra_hit":));
}
int extra_hit(object ob){
  if(!random(5)){
   tell_object(ETO,"%^BLUE%^The blades slash at "+ob->query_cap_name()+" spraying blood across the room!");
  tell_object(ob,"%^BLUE%^"+ETO->query_cap_name()+" laughs as "+ETO->query_subjective()+" slashes a bloody line across you with the blades on "+ETO->query_possessive()+" whip!");
  tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+" laughs as "+ETO->query_subjective()+" slashes a bloody mark across "+ob->query_cap_name()+" with "+ETO->query_possessive()+" whip!",(({ETO,ob})));
  return (random(6)+6);
  }
  if(!random(20)){
  tell_object(ETO,"%^YELLOW%^The grinning skull on the brass pommel of the whip flashes as it bites into "+ob->query_cap_name()+"!");
  tell_object(ob,"%^YELLOW%^The grinning skull on the brass pommel of "+ETO->query_cap_name()+"s whip flashes as it bites into you!");
  tell_room(environment(ETO),"%^YELLOW%^The grinning skull on the brass pommel of "+ETO->query_cap_name()+"s whip flashes as it bites into "+ob->query_cap_name()+"!",(({ETO,ob})));
  set_property("magic",1);
  ob->do_damage("torso",random((int)ETO->query_level()));
  remove_property("magic");
  }
  return (random(6)+4);
}
