#include <std.h>
#include <objects.h>



inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Wandering around in the oubliette.");
    set_long(
      "%^BLUE%^This horrible place is the oubliette.  It is a labyrinth of dark stone tunnels buried beneath the tower of the Black Dawn.  Many of the world's greatest heroes and warriors lie in bone heaps, all but forgotten down here.\n   The walls are cold stone bricks stacked against the natural rock that was tunneled through eons ago.  You are cold and alone.\n   Bones are strewn everywhere."
    );

    set_listen("default", "You are being hunted...");

    set_exits(([

	"north" : "/d/attaya/base/oubliette12",
	"south" : "/d/attaya/base/oubliette28",
	"west" : "/d/attaya/base/oubliette19",
	"east" : "/d/attaya/base/oubliette21",
	"down" : "/d/dagger/armor/gold/room1",

      ] ));
set_pre_exit_functions( ({"down"}), ({"no_down"}) );
set_items(([
    "walls" : "The cold stone brick walls show years of corrosion.",
    "ceiling" : "The ceiling is stone like the walls and floor and shows no means of escape.",
    "floor" : "The floor is made of well worn stone slabs.",
    "bones" : "The bones have been gnawed at, perhaps by rats.",
  ] ));
}
void reset(){
    ::reset();
    if(!present("hunter"))
	new("/d/attaya/mon/hunter")->move(TO);
}

int no_down(){
    if(present("hunter")){
	tell_object(TP, "The hunter grabs you as you try to go down and throws you back!");
	tell_room(ETP, "The hunter grabs "+TPQCN+" as they try to go down and throws them back!");
	return 0;
    } else {
	return 1;
    }
}
