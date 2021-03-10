#include <std.h>
inherit "std/weapon";

void create() {
    ::create();
    set_name("light horse lance");
    set_id(({"lance","light horse lance", "light lance"}));
    set_short("light horse lance");
    set_long("This is a light horse lance. It is an effective weapon with which to charge an opponent.");
    set_weight(5);
    set("value",6);
    set_wc(1,6);
    set_large_wc(1,8);
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
    return (int)ETO->query_size();
  return ::query_size();
}


