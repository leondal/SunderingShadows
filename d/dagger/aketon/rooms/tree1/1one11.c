#include "/d/dagger/aketon/short.h"

inherit STABLE;

void create() {
   ::create();
   set_property("light",2);
   set_short("Aketon Exotic Mounts");
   set("long","%^BOLD%^Aketon Exotic Mounts%^RESET%^
This place stretch for quite a distance. It obviously contains a number "
   "of mounts for sale. Here is where citizens of Aketon who set out on "
   "new adventures will get the mounts that will carry them. Posted "
   "around the stable are small notices of returning adventurer's stories "
   "of how their mounts were priceless during their trials. The aisle is "
   "lined with stalls.\nThere is a large sign hanging over the stall near "
   "the doorway.");
   set_items( (["mounts":"You see a row of stalls down the length of the "
      "aisle of the barn. Over the top of many stall doors, you can see "
      "hippogriffs looking at you curiously.",
      "aisle":"The aisle is long and wide with a hard packed dirt floor "
      "that looks recently raked. You see stable hands tacking up mounts "
      "for customers.",
      "stalls":"The stalls all have split doors, an upper and a lower. "
      "During the day, the upper doors are generally open allowing the "
      "hippogriffs to look out.",
      "sign":"You can <buy hippogriff> here for 1000 gold each. These "
      "hippogriffs will only serve elves!"]) );
   set_smell("default","The bad smell of animals fills the whole room.");
   set_listen("default","You hear sounds from hippogriffs here some sort "
      "of a snort or so.");
   set_animal( ({"hippogriff"}),({MPATH+"hippogriff"}) );
   set_animal_price( ({"hippogriff"}),({1000}) );
   set_exits( (["south":RPATH1+"1one19"]) );
}

void reset() {
   object obj;
   if( !present("toron") ) {
      obj = new(MONSTER);
      obj->set("long","Toron the mount seller will sell you a mount.");
      obj->set("short","Toron the mount seller");
      obj->set_level(20);
      obj->set_class("fighter");
      obj->set_id( ({"toron","seller","boy","mount seller"}) );
      obj->set_gender("male");
      obj->set_race("elf");
      obj->set_name("toron");
      obj->set_body_type("human");
      obj->move(TO);
   }
}
