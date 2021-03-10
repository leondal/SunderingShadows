#include <std.h>
inherit "/d/shadow/room/beastvillage/rings/base_inherit";

void create(){
   ::create();
   add_id("ring of spider climb");
   add_id("Ring of Spider Climb");
   set_short("%^RESET%^%^ORANGE%^Ring of Sp%^GREEN%^i%^ORANGE%^der Cl%^YELLOW%^i%^RESET%^%^ORANGE%^mb%^RESET%^");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_mylong("spider");
   set_mylore("spider, which can scale any surface effortlessly");
}

int wear_fun() {
   if(owned && (string)ETO->query_name() != owner && !avatarp(ETO)) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
   ETO->set_property("spiderclimb",1);
   return 1;
}

int remove_fun() {
   ETO->set_property("spiderclimb",-1);
   return 1;
}