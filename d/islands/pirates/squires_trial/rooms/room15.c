#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;

void create(){
  if(!random(3)){
    set_repop(50);
    set_monsters( ({SQUIREMOBS+"minielemental"}), ({random(2) + 2}) );
  }
  ::create();
  set_name("Squire's Trial Room 15");
  set_short("A carved tunnel");
  set_long( 
          "It is utterly " + 
          "%^BOLD%^%^BLACK%^dark%^RESET%^%^WHITE%^ here.  " +
          (string) TO->stonedesc() +
          "  The hallway splits here, with paths to the northwest, northeast, and southwest." 
  );
          
  set_exits(([
            "northeast" : SQUIREROOMS+"room18",
            "northwest" : SQUIREROOMS+"room16",
            "southwest" : SQUIREROOMS+"room14"
  ]));
}

void init(){
  object room;
  int spawn;
  room = find_object_or_load(SQUIREROOMS+"room17");
  spawn = room->get_spawn_elemental();
  ::init();
  if( spawn && !present("rock elemental")){
    new(SQUIREMOBS"elemental")->move(TO);
  }
  room->reset_spawn_elemental();
}

void reset(){
  ::reset();
}
