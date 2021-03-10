#include <std.h>
#include <daemons.h>
inherit OBJECT;

int tracker;

void create(){
        ::create();
        set_name("bowyer kit");
        set_id(({"kit","bowyer's kit","bowyers kit","bowyer kit"}));
        set_short("%^RESET%^%^ORANGE%^A bowyer's kit%^RESET%^");
        set_long("%^RESET%^%^ORANGE%^Contained within this leather pouch is a set of tools most likely used "
"for working with a bow and arrows.  Inside you see some polish, an oilcloth, a small sturdy knife and many "
"colored feathers, plus several spare bowstrings and such that one would expect to need for day to day "
"repairs.  With the right training and some wood, you imagine you could %^YELLOW%^<fletch>%^RESET%^%^ORANGE%^ "
"some spare arrows using this kit.%^RESET%^");
        set_weight(1);
        set_value(250);
        tracker = 0;
}

void init() {
   ::init();
   add_action("fletch","fletch");
}

int fletch(string str) {
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!present("firewood",TP)) {
     notify_fail("You will need to gather some wood first.\n");
     return 0;
   }
   if(!str) {
     notify_fail("What kind of arrows are you trying to fletch? Try to <fletch shortbow arrows> or <fletch "
"longbow arrows>.\n");
     return 0;
   }
   if(str != "shortbow arrows" && str != "longbow arrows") {
     notify_fail("What kind of arrows are you trying to fletch? Try to <fletch shortbow arrows> or <fletch "
"longbow arrows>.\n");
     return 0;
   }
   if(!TP->is_class("ranger") && !TP->query_nwp("weaponsmithing")) {
     notify_fail("You don't have the skills to attempt that.\n");
     return 0;
   }
   if(tracker > time()) {
     notify_fail("You should probably rest the tools a while so they don't wear out from use.\n");
     return 0;
   }
   tracker = time() + 1200;
   present("firewood",TP)->remove();
   if(str == "shortbow arrows") new("/d/common/obj/lrweapon/arrows")->move(ETP);
   else new("/d/common/obj/lrweapon/larrows")->move(ETP);
   if(present("arrows",ETP)) present("arrows",ETP)->set_value(0);
   tell_object(TP,"%^ORANGE%^You settle down on the ground and carefully whittle some arrows from the wood, "
"fletching each with feathers to direct their flight and discarding the loose wooden shavings.  Finally, you "
"have a small bundle of arrows laid out on the ground before you.%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TP->QCN+" settles down on the ground and carefully whittles some arrows from a "
"few sticks of wood.  Then "+TP->QS+" fletches each with feathers, until finally "+TP->QS+" has a small bundle "
"of arrows laid out on the ground before "+TP->QO+".%^RESET%^",TP);
   return 1;
}