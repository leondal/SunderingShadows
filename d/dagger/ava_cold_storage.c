//Garrett made this to fix part of charswitch,

#include <std.h>
inherit ROOM;
object ob;
void create(){
    ::create();
    set_short("%^B_BLUE%^%^CYAN%^A VERY COLD ROOM!%^RESET%^");
    set_long(
	"%^B_BLUE%^%^CYAN%^A VERY COLD ROOM!%^RESET%^\n"+
@GARRETT
This room is for the storage of charswitched avatars so they don't screw
other things up.
GARRETT
    );
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_smell("default","It smells of freshly fallen snow and ice");
    set_listen("default","You hear all the chattering of lots of teeth.");
    set_exits( ([
	"out":"/d/dagger/avalounge",
    ]) );
}

void init(){
    ::init();
    if(!wizardp(TP) && interactive(TP)){
	write("You aren't allowed in there mortal.");
        TP->move("/d/dagger/avalounge");
	return 1;
    }
}
int clean_up() { return 0;}
