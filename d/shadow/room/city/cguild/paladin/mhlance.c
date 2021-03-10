// Do not use, use the /d/common/obj/weapon/...  *Styx*  10/28/02

#include <std.h>
inherit "std/weapon";

void create() {
    ::create();
    set_name("medium horse lance");
    set_id(({"lance","medium horse lance", "medium lance"}));
    set_short("medium horse lance");
    set_long("This is a medium horse lance. It is an effective weapon with which to charge an opponent.");
    set_weight(10);
    set("value",10);
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
