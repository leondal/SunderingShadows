#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

object ob;

void create(){ 
   ::create();
   set_property("indoors",1);
   set_property("light",3);
//    set_property("no teleport",1);
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);
   set_short(
    "Thieves' Guild Store"
   );

   set_long(
            "%^BOLD%^Thieves' Store%^RESET%^\n"
            "This is a cramped little shop. "
             "On the counter lie several vials "
            "of poison."
            "This shop seems to be directed towards " 
             "the art of assassination. Rather than " 
            "thievery."
            "\n"
);

    set_smell("default","You smell weapon oil and leather.");
    set_listen("default","It's pretty quiet here.");

   set_items(([
   "counter":"The counter looks worn.",
    "vials":"These vials contain poisons of various descriptions.",
    ]));

   set_exits(([
   "west":CAVES"thief3"
]));

}

void reset(){
::reset();
if (!present("krinten")){
   new(MON"krinten")->move(TO);
}
}