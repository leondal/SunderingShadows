#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You have entered a very large cave. Bones and a countless "+
	"number of various items litter the floor. Rusted armor, swords "+
	"and many other things lie amongst the mess. A large globe of light hovers near the ceiling keeping the "+
	"entire cave lit up."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","The air smells a little fresher in this cave.");
    set_listen("default","A massive roar comes from the northern cave.");
    set_items( ([
	({"bones"}):"The bones of previous unlucky adventurers.",
	({"globe"}):"A large globe of light that radiates brilliantly, keeping the room lit up constantly."
    ]) );
    set_exits( ([
	"southwest":"/d/tharis/caverns/cavern11",
	"north":"/d/tharis/caverns/cavern14"
    ]) );
    set_pre_exit_functions( ({"north"}), ({"north"}) );
}
void reset(){
    ::reset();
    if(!present("flail snail")){
	new("/d/tharis/caverns/mon/flsnail")->move(this_object());
    }
}
int north(){
    if(present("flail snail")){
	write("The snail blocks your way.");
	return 0;
    }
    return 1;
}
