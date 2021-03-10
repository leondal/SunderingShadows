#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_short("Leatherworker's shop");
    set_property("light", 2);
    set_property("night light", 2);
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_long(
      "%^YELLOW%^You are in the shop of the guild leatherworker.  An old man sits here working the leather together with the magic and power of the guild into gloves for the guild to wear.  To get a new pair of gloves, just <order gloves>"
    );
    set_smell("default", "You smell the leather and oils the leatherworker uses.");
    set_listen("default", "You hear the little man humming to himself as he works on the gloves.");

    set_items( ([
	"gloves" : "there is a rack on the wall covered with gloves.",
	"leather" : "there are strips of leather waiting to be worked into gloves.",
	"oils" : "There is a rack on the wall holding the various oils the leatherworker uses.",
      ]) );

    set_exits( ([
	"west" : "/d/guilds/legion/hall/center1"
      ]) );

}

void reset(){
    ::reset();
    if(!present("chest")) {
	new("/d/guilds/legion/npcs/barkan.c")->move(TO);
    }
}
