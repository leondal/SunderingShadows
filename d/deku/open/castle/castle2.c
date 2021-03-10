//	castle2.c
//	Pator@ShadowGate
//	Tue Apr 11 05:25:17 1995

#include <castle.h>

inherit ROOM;

void create() {
	::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
	set_indoors(0);
	set_author("pator");
    set_light(2);
    set_short("Between the castle gates");
    set("day long",
@DAY
You are standing between the gates. You see the guardhouse at your left. To the west there are some guardquarters and to the east there are the stables.
DAY
    );
    set("night long",
@NIGHT
You are standing between the gates. Some torches light this area and so you can see all there is to see : The stables to the east and the guardquarters to your west.
NIGHT
    );
set_smell("default","You smell the stables here and a scent of beans");
set_listen("default","Nothing much except some birds singing.");
set_listen("quarters","You hear distinct sleeping noises coming from the quarters !");
    set_exits(([
"south" : CASTLE+"castle1",
"north" : CASTLE+"castle3",
"east" : CASTLE+"castleE1",
"west" : CASTLE+"castleW1"
    ] ));
   
}
reset(){
	::reset();
	if (!present("guard"))	{
	new(CASTLE+MONSTERS+"cas_guard1")->move(this_object());
				}
	}
