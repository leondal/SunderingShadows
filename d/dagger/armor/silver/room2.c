// fixed the .c on exits for peer *Styx*  2/2/05
// updated to use the VAULT code for the door. ~Circe~ 5/16/11

#include <std.h>

inherit VAULT;

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
	"south" : "/d/dagger/armor/silver/room1"
      ]) );
    set_door("door","/d/dagger/armor/silver/room1","south","cwarmorkey");
    set_door_description("door","This great door is made of a thick and "+
       "hard steel.  It has a silver keyhole under the handle to pull it open.");
    set_locked("door", 1);

}

void reset(){
    ::reset();
    if(!present("scrapmetal"))
	new("/d/dagger/armor/scrapmon.c")->move(TO);
}
