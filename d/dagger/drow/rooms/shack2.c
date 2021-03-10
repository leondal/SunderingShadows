#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Slave compound");
    set_long(
       	"%^BLACK%^%^BLUE%^You stand within one of the elven slave shacks. "
	"The shack is used as sleeping quarters for the elven slaves but "
	"contains nothing more than a pile of straw in the center of "
	"the floor. There are numerous holes in the ceiling which let "
	"the rain drip through and numerous holes in the walls "
	"allowing the cold wind to blow in.%^RESET%^"
    );
    set_listen("default",
	"You hear the rain's patter as it pelts the roof of the shack."
    );
    set_smell("default",
	"The smell of old straw fills the room."
    );
    set_items(([
	"shack":"%^BOLD%^%^YELLOW%^The shack is made of wheat and has "
	"no door...just a hole in the side wall of it. It has many holes "
	"in it.%^RESET%^",
	(({"slaves","slave","elf","elves"})):"%^MAGENTA%^The poor slaves "
	"are dressed in dirty rags. The elf seems to be nothing more than "
	"a skeleton draped with thin skin as the slaves are very "
	"underfed.%^RESET%^",
	"mud":"There is mud all about.",
	"rain":"%^BLUE%^The rain drizzles down upon the compound. "
	"Amazing how there was no rain in any other part of the "
	"city...%^RESET%^",
	"straw":"The straw is piled in the center of the room covering "
	"the wooden floor.",
	"floor":"Some of the floor boards appear loose but it is hard to "
	"tell because of the pile of straw.",
    ]));
    set_exits(([
	"east": RPATH "slave2"
    ]));
    set_search("straw", "You might want to lift the straw and look under it.");
}
void reset() {
    ::reset();
    remove_exit("hole");
    if(!present("slave")) {
	new( MPATH "slv")->move(TO);
	new( MPATH "slv")->move(TO);
    }
}
void init() {
    ::init();
    add_action("lift_straw","lift");
}
int lift_straw(string str) {
    if(str !="straw") {
    notify_fail("Lift what?");
    return 0;
    }
    message("my_action",
	"You lift the straw and discover a hole in the floor."
    ,TP);
    message("other_action",
	"After lifting the straw, "+TPQCN+"discovers a hole in the floor."
    ,environment(TP),TP);
    add_exit("/d/dagger/drow/rooms/healer","hole");
    return 1;
}

