//Coded by Bane//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_short("A globe of invulnerability");
    set_long(
	"You are trapped inside an invulnerable globe of force."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_smell("default","The air tingles of magic.");
    set_listen("default","The crackling of pure force echos throughout the globe.");
}
void init(){
    ::init();
    add_action("quit","quit");
    call_out("release",90);
}
int release(){
    if(!present(TP)) return 1;
    write("The globe shatters the very fabric of space and time as it collapses!");
    write("%^BOLD%^BLUE%^AN EXPLOSION ROCKS THE ROOM!");
    TP->move("/d/shadowgate/adv_main");
    TP->describe_current_room(1);
    return 1;
}
int quit(){
    write("You can't quit in here.");
    return 1;
}
