#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered the lair of some wretched beast. Old corpses "+
	"lie all over the cave. A hole in the ceiling blows a nice "+
	"breeze through the room. The cave is lit by a few torches."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","A fresh breeze blows through the room.");
    set_listen("default","A deafening roar fills the cavern.");
    set_items( ([
	({"corpses"}):"The corpses of a few foolish treasure hunters lie here."
    ]) );
    set_exits( ([
	"south":"/d/tharis/caverns/cavern12"
    ]) );
}
void reset(){
    ::reset();
    if(!present("behir")){
	new("/d/tharis/monsters/behir")->move(this_object());
    }
}
