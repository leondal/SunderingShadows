#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Road in Aketon");
   set_long("%^GREEN%^Road in Aketon%^RESET%^
You are walking on the roads build on the tree branches of the elven "
      "city of Aketon. There is a house to the west. Some adventurers "
      "coming from that direction holds a brand new sword passes you. "
      "The road mark besides you reads: Aketon Weapon Shop to the west.");
   set_exits( (["west":RPATH1+"1one16",
      "east":RPATH1+"1one18"]) );
}
