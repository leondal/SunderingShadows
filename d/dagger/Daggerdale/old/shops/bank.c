#include <std.h>
inherit BANK;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_short("Daggerdale Bank");
   set_long(
   "%^BOLD%^You are standing in the bank of Daggerdale.%^RESET%^\n"+
   "This is a large and very sturdy looking bank that has obviously"+
   " been made by dwarven craftsmen, who are notoriously good at"+
   " protecting their treasures. There is a desk stacked high with"+
   " records of transactions that a clerk sits behind. The thick"+
   " granite walls protect the gold, with a very heavy looking"+
   " vaulted door that is easily several feet deep. There is a small"+
   " chute in the wall for the clerk to deposit the coins through, but"+
   " it appears to be very craftily curved downwards with more than"+
   " a few turns, so the money could not easily come back out. This"+
   " bank will not be robbed anytime soon. There is a sign posted"+
   " on the front of the teller's desk that you can read.");
   set_smell("default","The scent of gold is intoxicating.");
   set_listen("default","The coins clink together pleasantly.");
   set_exits(([
   "west" : "/d/dagger/Daggerdale/streets/street11",
   ]));
}

void reset()
{
   ::reset();
   if(!present("bank teller")) {
     find_object_or_load("/d/dagger/Daggerdale/shops/npcs/bank_teller")->move(TO);
   }
}
