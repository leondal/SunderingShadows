//Coded by Bane for the Fallen Angels//
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_name("Abandoned castle");
    set_short("An old abandoned castle hall");
    set_long(
	"You appear to have walked into an old abandoned castle hall.  The walls "+
	"are covered in dirt and are falling apart.  The floor is caked in mud "+
	"and dust.  The few windows are shattered and broken.  Cracked pillars "+
	"rise up about 10 feet before they come to a broken end."
    );
//    set_property("no teleport",1);
//    set_property("no steal",1);
    set_smell("default","The faint smell of blood is present.");
    set_listen("default","A deadly silence echoes throughout the halls.");
//    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_exits( ([
	"south":"/d/shadow/guilds/angels/tmp/cave",
	"north":"/d/shadow/guilds/angels/tmp/hall1"
    ]) );
}

void reset(){
    ::reset();
// Removed as per Tristan's request, through JF's request.
// - Garrett.
//    if(!present("tera-sin")){
//	new("/d/shadow/guilds/angels/tmp/mon/guardian")->move(this_object());
//    }
//    if(!present("Josul")){
//	new("/d/shadow/guilds/angels/tmp/mon/guardian1")->move(this_object());
//    }
}
/*
void init(){
    ::init();
    add_action("read","read");
    if((string)TP->query_guild() == "Fallen Angel"){
    set_name("Fallen Angels Guild Hall");
    set_short("Fallen Angels Guild Hall");
    set_long(
        "You have walked into a massive castle hall.  Huge stone pillars "+
        "rise up into darkness holding up a ceiling that seems miles above "+
        "you.  Stained glass windows depict the guild history and stream "+
        "light into the tremendous room.  The stone floor is old and "+
        "weathered.  A large statue of a warrior sits in the center of the "+
        "hall."
    );
    set_items( ([
        ({"pillars"}):"Gigantic stone pillars nearly 10 feet in diameter.  They
reach way up into nothingness.",
        ({"windows"}):"Beautiful stained glass windows.  They appear to show the
history of the guild from its birth to the present time.  Each window holds a
certain time of triumph for the guild but all the scenes are dominated by a
tremendous figure easily "+
        "20 feet tall, enveloped in solid black armor and carrying two swords that
are bathed in pure energy and power.",
        ({"statue"}):"A statue made from onyx.  It stands roughly 10 feet tall and
is probably the founder of this beloved guild.  A plaque can be seen at the
statues base."
    ]) );
    } else {
    set_name("Abandoned castle");
    set_short("An old abandoned castle hall");
    set_long(
	"You appear to have walked into an old abandoned castle hall.  The walls "+
	"are covered in dirt and are falling apart.  The floor is caked in mud "+
	"and dust.  The few windows are shattered and broken.  Cracked pillars "+
	"rise up about 10 feet before they come to a broken end."
    );
    }
}
void read(string str){
    if((string)TP->query_guild() == "Fallen Angel"){
    if((str) == "plaque"){
    tell_object(TP,"The plaque reads:
	May this wonderful guild prosper and grow 
	for all of eternity.  Lord Nihilus will
	destroy all in his path and bring about 
	a new order! LONG LIVE THE FALLEN ANGELS!"
    );
    return 1;
    }
    return 0;
    }
}
int go_north(){
    if((string)TP->query_guild() != "Fallen Angel"){
    if(present("tera-sin")){
	write("Tera-sin blocks your way.");
	return 0;
    }
    if(present("Josul")){
	write("Josul blocks your way.");
	return 0;
    }
    }
    return 1;
}
*/