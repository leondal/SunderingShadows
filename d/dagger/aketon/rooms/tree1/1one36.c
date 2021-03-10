#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Aketon Crossroad Bar");
   set_long("%^BOLD%^Aketon Crossroad Bar%^RESET%^
This is the most popular stopping place for adventurers in Aketon. Many "
      "people come here for a couple of drinks and chat with some others "
   "talking about their amazing stories and adventures. It is always "
      "crowded with drinkers and gets pretty noisy all the time, so you "
      "will have to speak up.\nA list of drinks hangs on the wall.");
   set_items( (["pub":"The most hopping place in Aketon.",
      "bar":"The Aketon Crossroad Bar",
      "list":"A list of drinks. Read it to see what sells here."]) );
   set_smell("default","You smell the odor of beer and sweat.");
   set_listen("default","You hear the sounds of glasses clanging.");
   set_exits( (["east":RPATH1+"1one37"]) );
}

void init() {
   ::init();
   add_action("read_func", "read");
}

void reset() {
   ::reset();
   if( !present("lealian") )
      new(MPATH+"lealian")->move(TO);
}

int read_func(string str) {
   object obj;
   string *items,list;
   int num;
   obj = present("lealian");
   if(!str || str != "list") {
      notify_fail("Read what?\n");
      return 0;
   }
   if(!obj) {
      write("You cannot read the list as it is splattered with blood.");
      return 1;
   }
   items = obj->query_menu();
   num = sizeof(items);
   tell_object(TP,"%^BOLD%^%^RED%^This is a list of the drinks sold at "
      "the Crossroads bar.\n%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-"
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
   while(num--) {
      list = sprintf("     %%^GREEN%%^ %-20s %%^YELLOW%%^ %2d %%^RESET%%^ "
      "%%^WHITE%%^ silver pieces.",capitalize(items[num]),
      (int)obj->get_price(items[num]) );
      write(list);
   }
   tell_object(TP,"%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
      "-=-=-=-=-=-=-=-=-=-=-=-=-\n%^RESET%^%^GREEN%^To enjoy a drink, "
      "<buy drinkname> will get you a one.\n");
   return 1;
}
