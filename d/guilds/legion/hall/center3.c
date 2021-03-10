#include <std.h>
inherit "/std/members.c";

void create(){
    ::create();
    set_property("night light", 2);
    set_property("light", 2);
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_short("%^BOLD%^Listing of Members");
    set_long(
      "You have entered a small room, based around what looks like a large list on the west wall.  Below the list is a small sign that looks like it is to be read.  Other than that, this room is quite bare."
    );
    set_listen("default", "The silence is deafening.");
    set_smell("default", "You smell nothing.");
    set_exits( ([
	"south" : "/d/guilds/legion/hall/center1",
      ]) );
    set_items( ([
	"sign" : "try reading it.",
	"list" : "try reading it.",
      ]) );
    set_guild_name("Legion of Lost Soul");
}

void init(){
    ::init();
}
