//forest137.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_name("Forest Path");
	set_short("A small path through the forest");
	set_property("indoors",0);
	set_property("light",1);
	set_long(
@OLI
	%^BOLD%^%^GREEN%^A small twisting path through the forest%^RESET%^
As you enter the forest you notice a quiet all around you. Tall trees
loom over you almost basking in their grandure. Around you you
sense a horrible feeling of pain. Nature's work is here but that
work is being hurt. Small plants grow around the floor of the forest,
fighting for sunshine as it creeps sparcely through the thick canopy.
OLI
	);
	set_items((["floor":"The ground is cluttered  with twigs and leaves.",
				"trees":"These grand creatures range from oak and hickory to Pine and spruce."
				]));
	set_exits(([
				"southeast":"/d/tharis/forest/forest136",
				"northwest":"/d/tharis/forest/forest138"
				]));
	set_smell("default","The lush fragrances of the forest quell your worries.");
	set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
	
}

