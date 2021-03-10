#include <std.h>
#include <daemons.h>
inherit "std/room";

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_short("Fighter Store");
    set_long(
"%^BOLD%^WHITE%^Welcome to the Fighters Store.%^RESET%^\n"
"The store is very large and often busy.  There are several fighters "
"lined up in a line to buy what they need.  There is a large fighter who "
"sits behind the counter who is taking care of buying and selling things.  "
"There is another fighter who is very busy cleaning and polishing all the "
"things that are placed around the room."
);

    set_items(
    (["store" : "It is very busy is filled with many things.",
      "fighters" : "They are lined up behind the register.",
"counter" : "There is a man who is taking care of all the sales behind it.",
    "shelves" : "The shelvers are stocked with many things.",
]) );
     set_exits( (["out" : "/d/shadow/room/city/cguild/fighter/fighter"]) );
    set_property("no castle", 1);
   set_smell("default","You smell fresh iron.");
    set_listen("default","You hear many fighters talking prices over with the man behind the counter.");
 }


void reset(){
   ::reset();
   if(!present("jacob",TO))
      find_object_or_load("/d/shadow/room/city/cguild/mons/jacob")->move(TO);

}
