
#include <std.h>
inherit "std/weapon";

void create() {
    ::create();
    set_name("heavy horse lance");
    set_id(({"lance","heavy horse lance", "heavy lance"}));
    set_short("heavy horse lance");
    set_long("This is a heavy horse lance. It is an effective weapon with which to charge an opponent.");
    set_weight(15);
    set("value",15);
    set_wc(1,12);
    set_large_wc(1,21);
    set_size(1);
    set_type("piercing");
   set_prof_type("lance");
    set_property("lance",1);
    set_hit((:TO,"check":));
}

int check(object targ){
   if(!objectp(ETO)) return 0;
   if(!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle()))
      ETO->force_me("drop lance");
   return 0;
}


int query_size(){
  if(objectp(ETO)&&living(ETO))
    return (int)ETO->query_size()  ;
  return ::query_size();
}
