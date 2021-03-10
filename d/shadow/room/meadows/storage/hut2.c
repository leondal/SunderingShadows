#include <std.h>
#include "../meadow.h"
inherit HEALER;

void create()
{
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("light",3);
   set_property("indoors",1);
   set_property("training",1);
   set_short("A little hut");
   set_long(
   "This small little hut is kept very tidy and clean. There is a %^YELLOW%^welcome"+
  " mat%^RESET%^ as you enter for wiping your feet off of, and you notice a broom"+
   " in one corner that obviously gets a lot of use since you don't see"+
   " any dust on the floor. There are a few %^BOLD%^%^GREEN%^plants%^RESET%^ growing on the window"+
   " sills, and many shelves filled with %^GREEN%^dried herbs%^RESET%^ and poultices. A small"+
   " bed is setup in the back corner, but there is also a larger mattress"+
   " on the floor with clean linen sheets. There is a table in the center"+
   " of the room with many %^BOLD%^clean bandages%^RESET%^ on it and some medicinal salves,"+
   " along with a sign that lists the services provided here."
   );
   set_smell("default","The smell of herbs is strong in this room.");
   if(query_night() == 1) {
      set_listen("default","The crickets are noisy outside.");
   }
   else {
      set_listen("default","The birds are singing merrily outside.");
   }
   set_items(([
   ({"window","window sill","windows","plants"}) : "There are several"+
   " %^BOLD%^%^GREEN%^plants%^RESET%^ growing in pots along the window"+
   " sills. They appear to be doing quite well and have probably been"+
   " placed there so they can enjoy the sunlight.",
   ({"welcome matt","matt"}) : "%^YELLOW%^There is a cheery thatch welcome"+
   " matt that has been dyed a bright yellow and embroidered with flowers"+
   " for you to wipe your feet on as you come into the hut.%^RESET%^",
   "floor" : "The floor is remarkably clean. There is a welcome matt as"+
   " you enter, and a mattress laid out along the east wall.",
   "broom" : "%^ORANGE%^There is a broom leaning against the southwest"+
   " corner that probably gets a lot of use, judging by how clean this"+
   " place is.%^RESET%^",
   ({"bed","small bed"}) : "There is a small bed on the northeast corner"+
   " that looks like it would probably fit a young child.",
   ({"mattress","sheets","linen","clean linen"}) : "%^BOLD%^On the floor"+
   " along the eastern wall is a mattress that would probably hold a normal"+
   " sized person. It has clean white sheets and looks servicable if not"+
   " overly luxurious.%^RESET%^",
   ({"shelves","herbs","dried herbs","poultices"}) : "There are many shelves"+
   " all around the room that are stocked with bottles and jars of dried"+
   " herbs and poultices, as well as other healing items.",
   "table" : "There is a simple but sturdy wooden table in the center of"+
   " the room with several bandages, medicinal salves, and other healing"+
   " tools on it. There is also a sign listing the services you can purchase"+
   " here. There are two chairs, one on either side of the table.",
   "bandages" : "%^BOLD%^There are several clean cotton bandages laid out"+
   " on the table in the center of the room.%^RESET%^",
   "sign" : "You can <list> the prices here.",
   ({"chair","chairs"}) : "There are two chairs in the room, the one on"+
   " the far side of the table is for a smaller person, but has been raised"+
   " so that it elevates them to sit at the table normally. The other one"+
   " would easily fit a large human.",
   ({"salves","medicinal salves"}) : "Several medicinal salves are laid out"+
   " on the table, ready to be used if the customer has the coin to pay"+
   " for them.",
   ]));
   set_exits(([
   "south" : ROOMS+"meadow5",
   ]));
   set_post_exit_functions(({"south"}),({"GoThroughDoor"}));
   set_name("Maniela");
   set_cl_price(15);
   set_cs_price(40);
   set_cc_price(100);
   set_np_price(100);
   set_cb_price(200);
   if(query_night() == 1) {
      set_bp_price(30);
   }
   else {
      set_bp_price(25);
   }
}

void reset()
{
   ::reset();
   if(!present("maniela")) {
      new(MONS+"maniela")->move(TO);
   }
}

int GoThroughDoor()
{
   if(TP->query_size() > 2) {
      tell_object(TP,"You're relieved to stand up right once more!");
   }
   return 1;
}

/*void init()
{
   ::init();
   add_action("list","list");
}

void list(string str)
{
   if(!str) {
      tell_object(TP,"%^BOLD%^%^WHITE%^The available services here are:\n"+
      "cl : cure light wounds for 15 gold\n"+
      "cs : cure serious wounds for 40 gold\n"+
      "cc : cure critical wounds for 100 gold\n"+
      "np : neutralize poison for 100 gold\n"+
      "cb : cure blindness for 200 gold\n"+
      "bp : buy a kit, normally 25 gold but the price goes up at night\n");
      return 1;
   }
}*/
