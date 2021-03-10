#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Before the gates of Tonovi");
    set_long(
      "You are standing just below the crest of one of the hills on the plains overlooking the city of Tonovi.  To the northwest you can see the city sprawl in a large valley that almost looks like it was created by the footprint of a giant being.  Behind the city you can see the legendary slave pens.  To the north and south high towers rise around the main gates.  The gates themselves are open night and day for those weary travellers, though ready to be shut at a moments notice."
    );
    set_smell("default", "The smell of wildflowers floats to you on a cool breeze.");
    set_listen("default", "You hear a hawk cry out in the distance.");

    set_items( ([
	({"pens", "slave pens", "slaves"}) : "These great pens hold in the enslaved elves of the Kilkean forest, ready to be auctioned off in the city square for various crimes, from treason to just being in the wrong place at the wrong time.",
	"towers" : "These great towers are manned night and day to protect the city against elven attacks.",
	"gates" : "These great wooden gates, reinforced with iron bands, are the last line of defense against the elven intruders.",
      ]) );

    set_exits( ([
	"southeast" : RPATH "road1",
	"northwest" : "/d/dagger/tonovi/town/maingate",
      ]) );
}

void init(){
   ::init();
   if(!present("sign")){
      new("/d/dagger/tonovi/obj/tonovi_sign")->move(TO);
   }
}