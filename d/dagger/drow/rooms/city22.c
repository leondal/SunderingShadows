// made a little more friendly to realize it's special *Styx* 5/26/06

#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding "
	"through the existing structures around you. The wind blows "
	"back your hair as you wander through the city pathways. "
	"The lake still continues to the south, while to the north lies "
	"a chain link fence. From here you can see the poor slaves that "
	"are locked within the fence compound.%^RESET%^"
    );
    set_listen("default",
	"The wind howls a strangled cry which causes you to feel nervous "
	"about being here."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_search("default", (: "search_it" :) );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the "
	"city pathways.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones "
	"which must have been mined in the caverns near here.",
	"fence":"%^BLUE%^You can see the poor slaves locked within the "
	"compound. There are two shacks made of wheat obviously for "
	"the slaves to use. It is quite a "
	"depressing sight to behold.%^RESET%^",
	"shacks":"The shacks are made of wheat and look as though they "
	"are ready to collapse.",
	({"slave","slaves","elf","elves"}):"The elven slaves look "
	"miserable and through the dirt on their faces you notice "
	"some have shed many tears.",
	"lake":"%^BLUE%^The lake is dark and the water is black. From time to time you catch strange ripples on the surface.%^RESET%^",
	"water":"%^BLUE%^With enough nerve one could perhaps dive in the water here.%^RESET%^",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets.",
	"ripples" : "The ripples appear to be made by something moving under the water's surface."
    ]));
    set_exits(([
    	"east":"/d/dagger/drow/rooms/city21"
    ]));
}
void init() {
    ::init();
    add_action("dive_water","dive");
    if(!random(5) && interactive(TP))
	tell_object(TP, "You notice some ripples in the %^BLUE%^dark water %^RESET%^of the lake.");
}

int dive_water(string str) {
    if(str !="lake") {
        notify_fail("Dive where?\n");
    return 0;
    }
    message("my_action",
	"%^BLUE%^You dive in a fluid motion into the lake!%^RESET%^"
    ,TP);
    message("other_action",
	"%^BLUE%^"+TPQCN+" dives into the lake in a fluid "
	"motion.%^RESET%^"
    ,environment(TP),TP);
    TP->move_player("/d/dagger/drow/rooms/lake");
    return 1;
}
