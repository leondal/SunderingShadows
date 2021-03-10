#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit ROOM;
 
void create() {
   object obj, money;
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("indoors",1);
    set_property("no castle", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin sanctum%^RESET%^");
    set_long( "%^BLUE%^"
        "Hidden within the bowels of the Goblin Stronghold a musty hidden chamber exists "
	"in quiet isolation. What heinous creature calls this rank place home is unknown. "
	"The stone chamber is very dark and a straw mat lays strewn in the corner. Empty vials "
	"litter the floor and bloody writing covers the wall. "
	"The walls are made of stone and have unlit torches hanging from them."
        "%^RESET%^"
    );
    set_smell("default","It smells of death.");
    set_listen("default","You hear nothing but your heart beating.");
    set_items(([
      "torches":"The torches have burned out long ago, as though the "
          "creature that lives here has no use for light.",
      "walls":"The walls are made of stone.",
      "chamber":"The chamber is dark and cold.",
      "writing":"The writings are theories of the ancient goblination art.  "
	     "They all deal with the methods of goblin assassination.",
      "mat":"The straw mat is laid in one corner of the chamber.",
      "vials":"The empty vials contained a lethal substance at one time.",
    ]));
   if(!random(2)) {
      new("/d/shadow/room/goblin/mon/gobass")->move(TO);
      obj = new("/d/shadow/obj/misc/schest");
      obj->move(present("goblin assassin",TO));
      obj->set_key("chestkey");
      money = new("/std/obj/coins");
      money->set_money("gold",random(200)+35);
      money->set_money("electrum",random(350)+50);
      money->set_money("silver",random(400)+75);
      money->set_money("copper",random(1000)+450);
      money->move(obj);
      obj->toggle_closed();
      obj->set_lock("locked");
      obj->set_lock_difficulty(30);
   }
    set_exits(([ "south": RPATH "inner8" ]));
}

void reset() {
    ::reset();
    if(!random(3))
    if(!present("goblin")) {
        new( MPATH "soldier.c" )->move(TO);
        new( MPATH "soldier.c" )->move(TO);
      if(!random(3))
        new( MPATH "soldier.c" )->move(TO);
      if(!random(5))
        new( MPATH "raider.c" )->move(TO);
      if(!random(10))
        new( MPATH "ranger.c" )->move(TO);
    }
}
