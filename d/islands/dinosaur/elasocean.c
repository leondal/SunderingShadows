#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(DEEP_WATER);
   set_travel(FRESH_BLAZE);
   set_climate("tropical");
    set_name("Elasmosaurus trap");
    set_short("In the ocean");
    set_light(2);
    set_long(
      "You are in the slowly rising waters of the ocean.  You can see strange shapes swimming in the water off the rocky cliffs.  You can see up to where you fell, and can see a way to climb up among the rocks."
    );
    set_smell("default", "You smell the salt of the ocean");
    set_listen("default", "The waves are crashing against the cliffs");
    set_pre_exit_functions( ({"up"}), ({"up"}) );
}

int up(){
    if(present("dino")){
      write("As you try to climb the cliffs, the Elasmosaurus strikes you, forcing you back into the ocean.");
      return 0;
    }
    return 1;
}

void reset(){
    object ob;
    ::reset();

    if(!present("dino")){
      ob = new(MPATH "elas.c");
      ob->move(TO);
      ob->set_aggressive(25);
    }
    if(!present("dino 2") && !random(4)){
      ob = new(MPATH "elas.c");
      ob->move(TO);
      ob->set_aggressive(25);
    }
}
