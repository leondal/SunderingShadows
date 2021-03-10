#include <std.h>
#include <objects.h>



inherit "/d/attaya/base/spec/oubliette";

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Wandering around in the oubliette.");
    set_long("
    %^BLUE%^
    This horrible place is the oubliette.  It is a labyrinth of dark stone tunnels buried beneath the tower of the Black Dawn.  Many of the world's greatest heroes and warriors lie in bone heaps, all but forgotten down here.
    The walls are cold stone bricks stacked against the natural rock that was tunneled through eons ago.  You are cold and alone.
    Bones are strewn everywhere.
");

    set_listen("default", "You are being hunted...");
 
    set_exits(([

       "west" : "/d/attaya/base/oubliette5",
       "east" : "/d/attaya/base/oubliette7",

    ] ));
    set_items(([
          "walls" : "The cold stone brick walls show years of corrosion.",
          "ceiling" : "The ceiling is stone like the walls and floor and shows no means of escape.",
        "floor" : "The floor is made of well worn stone slabs.",
        "bones" : "The bones have been gnawed at, perhaps by rats.",
    ] ));
}
