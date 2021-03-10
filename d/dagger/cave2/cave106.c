#include "/d/dagger/cave2/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
   set_property("no teleport",1);
    set_property("indoors",1);
    set_property("light",1);
    set_short("Ogre caverns");
    set_long(
    "You have entered the center of this labrynthian cavern system.  In the middle of the room you can see several minor demons standing around an ogre chained to a great stone tablet in the middle of a stone pentagram carved in a stone pillar in the middle of a great glowing red chasm.  Suddenly the ogre stops struggling and stiffens, then its eyes snap open, glowing red.  It is then released and led away.  As you watch in horror, the largest of the demons turns to look at you, and smiles evilly at you."
    );
    set_listen("default", "You hear the thunder of hundreds of huge footfalls as they race towards you through the dark.");
    set_smell("default", "You're not sure you want to know what that is.");
    set_exits( ([
	"west" : "/d/dagger/cave2/cave105",
	"northwest" : "/d/dagger/cave2/cave116",
	"northeast" : "/d/dagger/cave2/cave118",
	"east" : "/d/dagger/cave2/cave107",
	"southeast" : "/d/dagger/cave2/cave97",
	"south" : "/d/dagger/cave2/cave96",
	"southwest" : "/d/dagger/cave2/cave95",
      ]));
    set_items( ([
	"fistmarks" : "   There are several marks gouged into the walls that were most likely made by the fist of enraged ogres.",
	"walls" : "   These walls are pockmarked and have been brutally abused",
	"eyes" : "   The glowing red eyes peer deep into you, deep into your soul, tormenting you with their deep hatred, instilling a great fear in your gut.",
      ]) );
}

void reset() {
    ::reset();
    if(present("player")) return;
    if(!present("vakoth")) {
	new("/d/dagger/cave2/mon/vakoth")->move(TO);
	set_exits(([
	    "west" : "/d/dagger/cave2/cave105",
	    "northwest" : "/d/dagger/cave2/cave116",
	    "northeast" : "/d/dagger/cave2/cave118",
	    "east" : "/d/dagger/cave2/cave107",
	    "southeast" : "/d/dagger/cave2/cave97",
	    "south" : "/d/dagger/cave2/cave96",
	    "southwest" : "/d/dagger/cave2/cave95",
	  ]));
    }
}

void lockdown(){
    add_exit("/d/dagger/cave2/cave117", "north");
    remove_exit("northeast");
    remove_exit("east");
    remove_exit("southeast");
    remove_exit("south");
    remove_exit("southwest");
    remove_exit("west");
    remove_exit("northwest");
}
