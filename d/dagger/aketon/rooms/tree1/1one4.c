#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("Aketon Jewelry");
   set_long("%^BOLD%^Aketon Jewelry%^RESET%^
This highly civilized city of Aketon with its wealthy merchants and "
      "traders, they all have plenty of money to spend. For that is one "
      "reason this jewel shop is so popular here and everyone in town has "
      "at least purchased something here. A large ornate glass decoration "
      "show cabin is sitting close to the east wall. A long glass counter "
      "which occupies the whole north wall displays all different "
      "kinds of jewels and ornaments. A few customers standing in front "
      "of the counter dealing with the shopkeeper.");
   set_items( (["shop":"This ornate shop is where people here and from "
      "other places come to buy some ornaments or jewels.",
      "cabin":"It is used to display all sorts of rare and gorgeous "
      "jewels that ever existed in this realm as well as different kinds "
      "of gemstones.",
      "counter":"It is long and occupied a large area. Different kinds of "
      "jewels and ornaments are displayed within the glasses.",
      "jewels":"You see all different kinds of jewels.",
      "ornaments":"You see all different kinds of ornaments.",
      "customers":"They are dealing with the shopkeeper."]) );
   set_smell("default","You smell the perfume of the women here.");
   set_listen("default","You hear customers dealing with the shopkeeper.");
   set_exits( (["south":RPATH1+"1one10"]) );
}

void reset() {
   ::reset();
   if( !present("boucheaden") )
      new(MPATH+"boucheaden")->move(TO);
   if( !present("security guard") )
      new(MPATH+"s_guard")->move(TO);
   if( !present("security guard 2") )
      new(MPATH+"s_guard")->move(TO);
}
