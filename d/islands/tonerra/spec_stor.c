#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_property("light", 1);
    set_short("A dark room");
    set_long(
      "This is a room you should not be in.  If you are, contact a wiz"
    );
    set_items(([]));
    set_exits(([]));
}

void reset(){
    ::reset();
    if(!present("cwarmorkey"))
	new("/d/dagger/armor/skey")->move(TO);
    if(!present("csarmorkey"))
	new("/d/dagger/armor/gkey")->move(TO);
    if(!present("red dust"))
	new("/d/islands/tonerra/redpowder.c")->move(TO);
}
