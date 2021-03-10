#include <std.h>
#include <objects.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;
void create() {
  room::create();
  set_light(2);
  set_indoors(1);
set_short("Elvanta's Armour Shop");
set_long("%^ORANGE%^You have stepped into D'gorins Armour Shop.  D'gorin awaits to help you buy or sell many forms or armour, as well as accessories, such as helmets and gloves.  Should you wish to see any items, type <help shop> and D'gorin will be happy to show you his wares.");
  set_smell("default","The smell of oil and iron pervades in this area.");
  set_property("no attack",1);
set_exits(([
"out" : PROOM+"room57.c"
]));
      set_items(([
"walls":"The walls are covered with various pieces of iron work -- some quite fancy",
 ] ));
  }
 void reset(){
 ::reset();
if(!present("d'gorin"))
new("/d/ptalkin/mon/d'gorin")->move(TO);
}
