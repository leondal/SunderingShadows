//Coded by Bane//
#include <std.h>
inherit OBJECT;
void create(){
    ::create();
    set_id(({"note","torn note"}));
    set_name("note");
    set_short("A torn note");
    set_long(
	"The note has writing on it...perhaps you can read it."
    );
    set_weight(9999);
    set_value(0);
}
void init(){
    ::init();
    add_action("read","read");
}
void read(string str){
    if(!str) return notify_fail("Read what?\n");
    if(str != "note") return 0;
    write("Dear Jasmine..."
	"\nI have been wandering around in these damned caves for weeks now.  I am "+
	"writing this letter because I don't believe I am going to make it out of "+
	"here alive.  I am sending my squire to the surface in hopes that he can "+
	"make it back to civilization and warn Asgard of this hell on earth.  This "+
	"magical force holds me here, not allowing me to leave.  I don't totally "+
	"understand the force behind this but I'm not sure I would want to.  "+
	"The beasts here are gruesome indeed.  Ugly creatures with tentacles "+
	"that come out of their face.  Many of my companions had the brains "+
	"torn from their heads by these horrors.  They however are extremely "+
	"intelligent, we ran into some science experiments they have been doing.  "+
	"A creature that breed and aged at incredible speeds, and a kin of their "+
	"own combined with a vampire!"
	"\nPlease Jasmine if you receive this letter pray for my soul."
	"\n\nLove,"
	"\n	Gregor"
    );
    return 1;
}
