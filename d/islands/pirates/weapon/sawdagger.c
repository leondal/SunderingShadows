#include <std.h>
#include "../piratedefs.h"
inherit "/std/weapon";
create(){
    ::create();
    set_id(({"saw","sawtoothed","sawtoothed dagger","dagger"}));
    set_name("Sawtoothed dagger");
    set_short("Sawtoothed dagger");
     set_long("This dagger is wickedly sawtoothed, the wounds it would create would be awesome to behold.");
    set_wc(1,6);
    set_large_wc(1,4);
    set_weight(3);
    set_size(1);
    set("value",1000);
    set_type("piercing");
    set_wield((:TO,"wield_func":));
    set_hit((: TO,"extra_hit" :));
    set_prof_type("small blades");
}
int wield_func(string str){
    tell_object(TP,"%^RED%^You grip the sawtoothed dagger and admire its serrated blade!%^RESET%^!");
     tell_room(ETP,"%^RED%^"+TPQCN+"'s eyes light up as they land on the blade of a sawtoothed dagger.%^RESET%^",TP);
    return 1;
}
int extra_hit(object victem){
   if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
   if(!objectp(victem)) return 1;
    if((roll_dice(1,20))>10){
     tell_object(ETO,"%^RED%^You tear into "+victem->query_cap_name()+"'s flesh with your sawtoothed dagger!%^RESET%^");
	tell_object(victem,"%^RED%^"+ETO->query_cap_name()+" tears your flesh open with a sawtoothed dagger!%^RESET%^");
message("other_action","%^RED%^" +ETO->query_cap_name()+" rips into "+victem->query_cap_name()+"'s flesh with "+ETO->query_possessive()+" sawtoothed dagger!%^RESET%^",environment(victem),(({ETO,victem})));
  victem->do_damage("torso",random(5)+3);
  return 0;
    }else return 0;
}
