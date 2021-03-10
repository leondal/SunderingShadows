#include <std.h>
inherit "/std/armour";

create() {
    ::create();
  set_name("spectacles");
  set_id(({"spectacles","gold rimmed spectacles","glasses","eyeglasses"}));
  set_short("gold rimmed spectacles");
    set_long(
  "  A pair of finely ground crystal lenses are supported by a thin, weak looking gold frame."
    );
  set_weight(1);
    set_value(300);
  set_type("ring");
  set_limbs(({"head"}));
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
  object *stuff;
  int i,j,flag;
  stuff=TP->all_armour();
  j=sizeof(stuff);
  for(i=0;i<j;i++){
  if((string)stuff[i]->query_name()=="spectacles"){
  flag=1;
  break;
 }
 }
  if(flag){write("You find it a little hard to wear another set of spectacles on your nose at the same time.");
  return 0;
  }
    write(
 "You adjust the spectacles onto the end of your nose."
    );
    say(
  ""+ETO->query_cap_name()+" adjusts a set of spectacles on "+ETO->query_possessive()+" nose.");
    return 1;
}
int removeit() {
        write(
 "You squint a bit as you remove the glasses from your nose."
        );
   tell_room(environment(ETO),
  ""+ETO->query_cap_name()+" seems to squint a bit as "+ETO->query_subjective()+" removes "+ETO->query_possessive()+" glasses."
        ,ETO);
      return 1;
}
