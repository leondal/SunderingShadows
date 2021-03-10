#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_short("%^BOLD%^The Aketon Treasury%^RESET%^");
   set_long("%^BOLD%^The Aketon Treasury%^RESET%^
This large building of business is known as the treasury of the elven "
      "city of Aketon. It is used to collect treasures that elven traders "
      "gain from business with the reset of the realm. The fund will be "
      "used for the building of the city, defense expenditure, training "
      "of the troops, road maintenance as well as others. The structure "
      "is made entirely of wood. A desk is over there to the eastern side "
      "of the room. Behind it sits the treasurer of Aketon.\nThere is a "
      "large sign hanging on the wall.");
   set_items( (["desk":"A large wooden desk with some stationary spread "
      "all over it.",
      "structure":"A large wooden structure sitting on one of the main "
      "branches of the Aketon trees.",
      "sign":"A sign with some words written on it, perhaps you should "
      "read it."]) );
   set_property("light",2);
   set_property("indoors",1);
   set_listen("default","You hear gold clinking.");
   set_smell("default","The smell of money fills the air.");
   set_exits( (["east":RPATH1+"1one33"]) );
}

void init() {
   ::init();
   add_action("donate_func","donate");
   add_action("read_func","read");
}

int read_func(string str) {
   if(str != "sign") {
      notify_fail("Read what?");
      return 0;
   }
   else {
      tell_object(TP,"Elven citizens come here to <donate> money in gold "
         "for the benefits of the elven civilization of Aketon.");
      return 1;
   }
}

int donate_func(string str) {
   string type;
   int amt;
   if(!str) {
      notify_fail("Donate what?\n");
      return 0;
   }
   if(sscanf(str,"%d %s",amt,type) != 2) {
      notify_fail("Donate <amount> gold.\n");
      return 0;
   }
   if(type != "gold") {
      notify_fail("Only gold please!\n");
      return 0;
   }
   if(amt < 100) {
      notify_fail("Donations shall be over 100 gold.\n");
      return 0;
   }
   if( (int)TP->query_money("gold") < amt ) {
      notify_fail("You do not have that much money!\n");
      return 0;
   }
   if (!present("maxian")) {
      notify_fail("The treasurer is not here right now.\n");
      return 0;
   }
   tell_object(TP,"You give the treasurer a "+amt+" gold of donations.\n"
      "%^RESET%^%^MAGENTA%^Maxian says: %^RESET%^The people of Aketon "
      "city thank you for your kindness.");
   tell_room(ETP,TPQCN+" gives some gold to the treasurer.\n"
      "%^RESET%^%^MAGENTA%^Maxian says: %^RESET%^The people of Aketon "
      "city thank you for your kindness, "+TPQCN+".",({TP}));
   TP->add_money("gold",-amt);
   return 1;
}

void reset() {
   ::reset();
   if( !present("maxian") )
      new(MPATH+"maxian")->move(TO);
}
