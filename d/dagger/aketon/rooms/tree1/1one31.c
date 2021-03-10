#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Aketon Sparrow Inn");
   set_long("%^BOLD%^Aketon Sparrow Inn%^RESET%^
Here the people of Aketon and visiting adventurers come for some good "
      "food. When the waitress is around, she will happily serve you "
      "anything available from the kitchen here.\nA menu hanging on the "
      "wall at the far side.");
   set_items( (["inn":"The Aketon Sparrow Inn, oldest inn in the city of "
      "Aketon.",
      "wall":"The menu is hanging there.",
      "menu":"Read it to get the list of Aketon cuisines."]) );
   set_smell("default","You smell the odor of cooking food.");
   set_listen("default","You hear the sounds of plates clanging.");
   set_exits( (["west":RPATH1+"1one30"]) );
}

void init() {
   ::init();
   add_action("read_func","read");
}

void reset() {
   ::reset();
   if( !present("jilian") )
      new(MPATH+"jilian")->move(TO);
}

int read_func(string str) {
   object obj;
   string *items,list;
   int num;
   if(!str || str != "menu")
      return 0;
   obj = present("jilian");
   if(!obj) {
      write("You cannot read the menu, as it is splattered with blood.");
      return 1;
   }
   items = obj->query_menu();
   num = sizeof(items);
   write("%^BOLD%^%^MAGENTA%^The following cuisines are served here at "
      "the Aketon Sparrow Inn.\n%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-"
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
   while(num--) {
      list = sprintf("     %%^GREEN%%^ %-20s %%^YELLOW%%^ %2d %%^RESET%%^ "
      "%%^WHITE%%^ silver pieces.",capitalize(items[num]),
      (int)obj->get_price(items[num]) );
      write(list);
   }
   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
      "=-=-=-=-=-=-=-\n%^RESET%^%^GREEN%^To enjoy a dish, <buy dish_name> "
      "will get you a one.\n");
   return 1;
}
