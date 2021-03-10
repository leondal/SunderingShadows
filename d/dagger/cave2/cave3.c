#include "/d/dagger/cave2/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
    set_property("indoors",1);
    set_short("Ogre caverns");
    set_long(
      "   You are in a dark damp cavern system descending deep under the mountain.  All around you you see signs of ogre habitation, from fistmarks in the walls to the unmistakable odor.  As you peer into the dark abyss before you you see many glowing eyes peering back at you."
    );
    set_listen("default", "You hear the thunder of hundreds of huge footfalls as they race towards you through the dark.");
    set_smell("default", "You're not sure you want to know what that is.");
    set_exits( ([
	"south" : RPATH "cave2",
	"northeast" : RPATH "cave4",
      ]));
    set_items( ([
	"fistmarks" : "   There are several marks gouged into the walls that were most likely made by the fist of enraged ogres.",
	"walls" : "   These walls are pockmarked and have been brutally abused",
	"eyes" : "   The glowing red eyes peer deep into you, deep into your soul, tormenting you with their deep hatred, instilling a great fear in your gut.",
      ]) );
}

void reset() {
    ::reset();
    if(!present("ogre escapee"))
      new(MPATH "escapee")->move(TO);
}
