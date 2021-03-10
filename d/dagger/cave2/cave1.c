#include "/d/dagger/cave2/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
    set_property("indoors",1);
    set_short("Ogre caverns");
    set_long(
      "   You have started on your journey deep into the caves of the ogres.  Here along the damp walls in this musty cave system, you can see where a few brave ogres came out far enough to brave the real world."
    );
    set_listen("default", "You hear the thunder of hundreds of huge footfalls as they race towards you through the dark.");
    set_smell("default", "You're not sure you want to know what that is.");

    set_exits( ([
    "north" : RPATH "cave2",
	"out" : "/d/dagger/keep/road/entrance2",
      ]));

    set_items( ([
	"fistmarks" : "   There are several marks gouged into the walls that were most likely made by the fist of enraged ogres.",
	"walls" : "   These walls are pockmarked and have been brutally abused",
	"eyes" : "   The glowing red eyes peer deep into you, deep into your soul, tormenting you with their deep hatred, instilling a great fear in your gut.",
      ]) );
}
