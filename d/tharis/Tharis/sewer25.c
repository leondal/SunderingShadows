//sewer25.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(SLICK_FLOOR);
    set_property("no sticks", 1);
	set_property("light",0);
	set_property("indoors",1);
	set("short","The sewers under Tharis");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The sewers under Tharis%^RESET%^
These sewers range under Tharis for miles. You need to find a place
to reach the surface. The dark walls are covered with slime mold from 
the many many years that sewage has flowed through here. The one thing
you do note is that there is remarkably little build up as if the
sewers have been cleaned frequently. You wonder what or who would get 
that task. Along this portion of the sewers you notice that alcoves have
been carved in the walls. The walls are smooth here and flat. You notice
that the noise from above has grown less. Then you notice why. The floor
has begun to slope downward. The water is deeper here. It gushes by you
forcefully. The water is still getting deeper.
OLI
	);
	set_exits(([
		"south":"/d/tharis/Tharis/sewer26",
		"north":"/d/tharis/Tharis/sewer24"
		
		]));
	set_listen("default","Your boots splash through the the water."+
				"You also hear murmurs from the town above");
	set_smell("default","The smell of decay and refuse reach your nostrils");
	set_items(([
		"walls":"The walls are dark. They are covered with a surprisingly thin layer of slime."
	]));
	call_out("dunk_people",20);
}

void init(){
	::init();
	
	do_random_encounters(({"/d/tharis/monsters/gcube"}),10,1);
	do_random_encounters(({"/d/shadow/mon/rat"}),30,11);
}

void dunk_people(){
	object *livings, *inven;
	int i,j;
	
	livings = ({});

	inven = all_inventory(TO);
	
	j= sizeof(inven);
	
	tell_room(TO,"%^BOLD%^%^BLUE%^The water Gushes past your legs trying to knock you down!");
	for(i = 0;i < j;i++){
		if(living(inven[i])) livings += ({inven[i]});
	}
	
	j = sizeof(livings);
	
	for(i=0;i<j;i++){
		if((random(20) - 5) > livings[i]->query_stats("strength")){
			tell_object(livings[i],"%^BOLD%^%^BLUE%^The water knocks you down!");
			tell_object(livings[i],"%^BOLD%^%^BLUE%^It washes you further down the hall!");
			tell_room(TO,"%^BOLD%^%^BLUE%^"+livings[i]->query_cap_name()+" is washed into the next room!");
			livings[i]->force_me("north");
		}
	}
	call_out("dunk_people",20);
}
