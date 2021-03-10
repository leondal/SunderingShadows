#include <std.h>
#include <arena.h>
#define BASE "/d/guilds/legion/hall/arena/"
int i;
string *rooms;

inherit ARENA;

void create(){
    ::create();
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("arena", 1);
    set_property("deathmove", "/d/guilds/legion/hall/arena/arenah.c");
    set_short("%^BOLD%^%^BLUE%^Arena of the Ancients");
    set_long(
      "Here in the middle of the bottom floor of the arena a great shimmering portal floats a foot off the ground.  Glowing blue, as you peer into the portal you can see visions of several of the rooms of this arena flash past you.  Perhaps if you %^BOLD%^%^BLUE%^dive portal%^RESET%^ you will be taken somplace new."
    );
    set_smell("default", "The arena is filled with a dark smoke.");
    set_listen("default", "In the dark smoke, it is eerily silent.");

    set_items( ([
	"walls" : "These walls are pockmarked and battle damaged.",
      ]) );
    set_exits( ([
    "south" : "/d/guilds/legion/hall/arena/arena21.c",
      ]) );

}

void init() {
    ::init();
    add_action("dive", "dive");
}

int dive(string str) {
    if(!str) return notify_fail("dive where?");
    if(str != "portal") return notify_fail("dive where?");

    tell_room(ETP, "%^BLUE%^"+TPQCN+" dives into the portal and is gone!", TP);
    tell_object(TP, "%^BLUE%^You dive into the portal and are whisked away!");
    rooms = get_dir("/d/guilds/legion/hall/arena/");
    i = random(sizeof(rooms));
    TP->move_player(BASE+rooms[i]);


      return 1;
  }
