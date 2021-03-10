#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

void create(){
   ::create();
   add_id("ring of sustenance");
   add_id("Ring of Sustenance");
   set_short("%^RESET%^%^ORANGE%^Ring of Su%^GREEN%^s%^ORANGE%^ten%^YELLOW%^a%^RESET%^%^ORANGE%^nce%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("camel");
   set_mylore("camel, which is known for its ability to go without food and water for weeks at a time");
}

int wear_fun() {
   if(owned && (string)ETO->query_name() != owner && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   ETO->set_property("sustenance",1);
   return 1;
}

int remove_fun() {
   ETO->set_property("sustenance",-1);
   return 1;
}