// set to inherit from lance.c, nienne 08/07.
#include <std.h>
inherit "/d/common/obj/weapon/lance.c";

void create() {
    ::create();
  set_name("mithril lance");
  set_id(({"lance","mithril lance","mithril tipped lance"}));
  set_short("a mithril tipped lance");
  set_long(
  "This lance is tipped with a bright silvery mithril head."
  "  It was forged by the Dwarves of Mt. Sholkum in the Dagger Reaches."
  "  Dwarven runes line the center of the spearhead and the long oak shaft is polished to a high shine."
  "  Engraved on the shaft is the crest of the Army of the Dagger Reaches.");
//  set_weight(10);
  set_value(100);
//  set_wc(1,10);
//  set_large_wc(3,6);
//    set_size(1);
//    set_type("piercing");
//   set_prof_type("lance");
//    set_property("lance",1);
//    set_hit((:TO,"check":));
  set_property("enchantment",1);
}

/*int check(object targ){
   if(!objectp(ETO)) return 0;
   if(!ETO->query_in_vehicle() || !objectp(ETO->query_in_vehicle()))
      ETO->force_me("drop lance");
   return 0;
}


int query_size(){
  if(objectp(ETO)&&living(ETO))
    return (int)ETO->query_size();
  return ::query_size();
}*/
