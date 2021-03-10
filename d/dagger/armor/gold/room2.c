// fixed the .c on exits for peer *Styx*  2/2/05

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_property("no teleport", 1);
    set_property("light", 1);
    set_property("indoors", 1);
    set_short("End of the line");
    set_long(
      "You are behind the geat door that created the prison for the creature that was held here.  There is much blood here, from countless sacrifices of innocents, and the occasional adventurer that wasn't lucky enough to have a quick death."
    );
    set_smell("default", "It smells of rotten corpses and %^BOLD%^%^RED%^blood.%^RESET%^");
    set_listen("default", "You hear your heart pounding in your chest.");

    set_items( ([
	"blood" : "It is old and stale blood.",
      ]) );

    set_exits( ([
	"south" : "/d/dagger/armor/gold/room1",
      ]) );
}

void reset(){
    ::reset();
    if(!present("implementor"))
	new("/d/dagger/armor/implementor.c")->move(TO);
}
