//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains1",
	"east":"/d/laerad/plains/plains12",
	"south":"/d/laerad/plains/plains6",
	"north":"/d/laerad/plains/plains4"
    ]) );
    reset();
}

void reset(){
    int r;
    ::reset();
    if(!present("hordling")){
//    new("/d/laerad/mon/hordling")->move(this_object());
//    new("/d/laerad/mon/hordling")->move(this_object());
    new("/d/laerad/mon/hordling")->move(this_object());
    }
    if(!present("chest")){
      r = random(2);
      if(r==0) new("/d/hm_quest/chests/chest15")->move(TO);
      else new("/d/hm_quest/chests/chest20")->move(TO);
    }
}
