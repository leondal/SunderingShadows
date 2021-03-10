#include "/d/dagger/aketon/short.h"

inherit STABLE;

void create() {
   ::create();
   set_property("light",2);
   set_short("Aketon stables");
   set("long","%^BOLD%^Aketon stables%^RESET%^
Upon entering the place you see lines of aisles in front of you. There are rows of "
   "stalls down the length of the aisles in the barn. It obviously "
   "contains a great number of horses for sale.\nThere is a large sign "
   "hanging over the stall near the doorway.");
   set_items( (["horses":"You see a row of stalls down the length of the "
      "aisle of the barn. Over the top of many stall doors, you can see "
      "horses looking at you curiously.",
      "aisle":"The aisle is long and wide with a hard packed dirt floor "
      "that looks recently raked. You see stable hands tacking up mounts "
      "for customers.",
      "stalls":"The stalls all have split doors, an upper and a lower. "
      "During the day, the upper doors are generally open allowing the "
      "horses to look out.",
      "sign":"You can <buy horse> here for 80 gold each.\n        <buy "
      "heavy warhorse> here for 800 gold each.\n        <buy war horse> "
      "here for 600 gold each."]) );
   set_smell("default","You smell horses.");
   set_listen("default","You hear the whinny of horses occasionally.");
   set_animal( ({"horse","heavy warhorse","war horse"}),
      ({"/realms/tristan/horse","/d/koenig/town/mounts/heavy1",
      "/d/shadow/room/city/cguild/paladin/war_horse"}) );
   set_animal_price( ({"horse","heavy warhorse","war horse"}),
      ({80,800,600}) );
   set_exits( (["west":RPATH1+"1one41"]) );
}

void reset() {
   object obj;
   if( !present("stable hand") ) {
      obj = new(MONSTER);
      obj->set("long","This stable boy will sell you a mount.");
      obj->set("short","Stable hand");
      obj->set_level(20);
      obj->set_class("fighter");
      obj->set_id( ({"hand","stable hand","boy"}) );
      obj->set_gender("male");
      obj->set_race("elf");
      obj->set_name("stable hand");
      obj->set_body_type("human");
      obj->move(TO);
   }
}
