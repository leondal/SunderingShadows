#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_long("%^RED%^"
	"The inner hallway of the tower is decorated similar to other parts of the tower. "
	"The stone is more subdued in tone here however; almost as though the strange force "
	"which runs through it is being slowly drained out, devoured by an evil "
	"greater than that which twisted it's shape into existance. "
	"\n"
	"%^BOLD%^%^RED%^A voice deep in the back of your head, begins to howl in fear!"
	"%^RESET%^" 
    );
    set_short("%^RED%^Inner Hallway%^RESET%^");
    set_listen("default",
        "A faint murmur is occasionally emitted through the floor."
    );
    set_smell("default",
        "The smell of gothic death on a sweltering summer eve surrounds you."
    );
    set_items(([
	"stone":"%^RED%^The stone used to form the chamber is made from an unknown "
	"material and seems to glow in it's blood-red colour. As you gaze upon it, "
	"you hear the distant laughter of Grazzt.%^RESET%^",
    ]));
    set_exits(([
        "northwest": RPATH "c4",
	"northeast": RPATH "c6",
	"south": RPATH "c1",
    ]));

    set_pre_exit_functions(({"south"}),({"exita_fun"}));
}
void reset(){
   ::reset();
   if(!present("reaver"))
    new("/d/dagger/marsh/swamp/mon/reaver")->move(TO);
  }
int exita_fun() {
     write("%^BOLD%^%^BLUE%^"
	"An evil cackle echoes down the hall as you head south.%^RESET%^"
    );
    say("%^BOLD%^%^BLUE%^"
	"An evil cackle comes from the south."
    ,TP);
    return 1;
}
