//changed to add exit to Tymora's temple.  Circe 4/13/04
#include <std.h>
//#include "meadow.h"
#include "/d/shadow/room/meadows/meadow.h"
inherit "/std/pier";

int count;

void create()
{
   ::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_property("light",1);
   set_property("indoors",0);
   set_short("%^BOLD%^%^CYAN%^A peaceful pond%^RESET%^");
   set_long(
   "%^CYAN%^You have come to the edge of a pleasant little "+
   "pond. The waters are a %^BOLD%^clear blue%^RESET%^%^CYAN%^ "+
   "and you can see the fish swimming in the depths, trying to "+
   "stay in the shady areas. %^GREEN%^Reeds%^CYAN%^ are growing along"+
   " the edges of the pond and you see a %^YELLOW%^peach "+
   "tree%^RESET%^%^CYAN%^ on the far side, with a small windchime"+
   " hanging from a branch. There is a little "+
   "hut to the east that looks rather small. To the west, a pathway "+
   "leads to an open field beyond.\n"
   );
   set("night long",
   "%^BOLD%^%^BLUE%^The moon reflects off the surface of the pond"+
   " before you, making it seem as though it's made out of %^WHITE%^liquid silver%^BLUE%^."+
   " The wind barely touches the surface of the waters, but you can see"+
   " it gently blowing the %^RESET%^%^GREEN%^reeds%^BOLD%^%^BLUE%^ around"+
   " the edges of the pond. You can make out a %^YELLOW%^peach tree%^BLUE%^"+
   " on the far side of the pond, with a small windchime hanging from a"+
   " branch. Directly to the east is a small little"+
   " hut pouring out warm light. To the west, a pathway "+
   "leads to an open field beyond.\n"
   );
   set_smell("default","The water smells fresh and clean.");
   if(query_night() == 1) {
       set_listen("default","The wind blows through the reeds.");
   }
   else {
      set_listen("default","The wind swirls the waters and the fish splash.");
   }
   set_items(([
   "pond" : "%^BOLD%^%^CYAN%^The pond is filled with fresh clear water"+
   " and you can see fish swimming lazily around in the depths. The pond"+
   " has been carefully lined with round pebbles, probably to help"+
   " maintain the water level.%^RESET%^",
   "reeds" : "%^GREEN%^Reeds grow around the edges of the pond, providing"+
   " shadows for the fish.%^RESET%^",
   "pebbles" : "Rounded pebbles have been placed around the edges of the"+
   " pond, most likely to help maintain the water level when it gets hot,"+
   " preventing the water from escaping into the ground.",
   "peach tree" : "There is a peach tree on the far side of"+
   " the pond with a couple of ripe %^YELLOW%^golden peaches%^RESET%^ on it.",
   "peaches" : "%^YELLOW%^Some delicious looking peaches are hanging"+
   " from the tree, just waiting for someone to pick them.",
   "hut" : "There is a small hut to the east. The doorway is barely"+
   " large enough for someone of average height, whoever lives in there"+
   " must be small.",
   ({"windchime","wind chime","chime"}) : "%^BOLD%^%^GREEN%^A %^BOLD%^%^RED%^b"+
   "%^BOLD%^%^GREEN%^e%^BOLD%^%^RED%^a%^BOLD%^%^GREEN%^u%^BOLD%^%^RED%^t"+
   "%^BOLD%^%^GREEN%^i%^BOLD%^%^RED%^f%^BOLD%^%^GREEN%^u%^BOLD%^%^RED%^l"+
   "%^RESET%^%^CYAN%^ w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^nd ch%^BOLD%^%^CYAN%^i"+
   "%^RESET%^%^CYAN%^me %^BOLD%^%^GREEN%^sings a %^RESET%^%^MAGENTA%^gentle "+
   "%^YELLOW%^melody.%^BOLD%^%^GREEN%^ A small %^BOLD%^%^BLACK%^plaque "+
   "%^BOLD%^%^GREEN%^attached to the %^RESET%^%^ORANGE%^peach tree%^BOLD%^%^GREEN%^ "+
   "reads: %^BOLD%^%^CYAN%^Dedicated to the Temple of Tymora by %^YELLOW%^Amberly"+
   "%^BOLD%^%^CYAN%^ who won second place in the %^BOLD%^%^WHITE%^test of mithril.",
   ]));
   set_exits(([
   "south" : ROOMS+"meadow3",
   "east" : ROOMS+"storage/hut1",
   "northwest" : "/d/shadow/room/kildare/rooms/roads/wroad30",
   "temple" : "/d/magic/temples/callamir/callamir"
   ]));
   set_max_fishing(6);
   set_chance(12);
   set_max_catch(8);
   set_fish((["Big Kahuna" : 10, "Issaquah Trout" : 3 ]));
   set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));
   count = 3;
}

void init()
{
   ::init();
   add_action("pick","pick");
}

int GoThroughDoor()
{
   if(TP->query_size() > 2) {
       tell_object(TP,"You have to duck low to avoid hitting your head.");
   }
   return 1;
}

void pick(string str)
{
   if(str != "peach" && str != "peaches") {
      tell_object(TP,"Pick what?");
      return 1;
   }
   if(count < 1) {
      tell_object(TP,"There don't seem to be any peaches left to pick.");
      return 1;
   }
   else {
      tell_object(TP,"%^YELLOW%^You pick a ripe peach from the tree.");
      tell_room(ETP,"%^YELLOW%^"+TPQCN+" picks a peach from the tree.",TP);
      new("/d/darkwood/obj/peach")->move(TP);
      count -= 1;
      if(count < 1) {
         add_item("peach tree","The peach tree is growing tall"+
         " on the other side of the pond, but there only appear to be"+
         " some unripe peaches right now.");
         add_item("peaches","%^YELLOW%^It appears as though all the ripe peaches"+
         " have been picked.%^RESET%^");
      }
      return 1;
   }
}
