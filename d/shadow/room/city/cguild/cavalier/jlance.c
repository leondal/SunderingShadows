#include <std.h>
inherit "std/weapon";

void create() {
    ::create();
    set_name("jousting lance");
    set_id(({"lance", "jousting lance"}));
    set_short("jousting lance");
    set_long("This is a jousting lance. It is an effective weapon with which to charge an opponent.");
    set_weight(20);
    set("value",20);
    set_wc(1,6);
    set_large_wc(1,12);
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
