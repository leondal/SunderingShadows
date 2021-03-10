//sewer13.c

#include <std.h>

inherit ROOM;
 object ob,ob2, ob3;
 int flag;
void create(){
	::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(SLICK_FLOOR);
    set_property("no sticks", 1);
	set_property("light",1);
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
been carved in the walls. Most of these are full of disgusting growths.
You worry of the possiblities of what lies in those alcoves.   
OLI
	);
	set_exits(([
		"east":"/d/tharis/Tharis/sewer15",
		"west":"/d/tharis/Tharis/sewer13"
		
		]));
	set_listen("default","Your boots splash through the the water."+
				"You also hear murmurs from the town above");
	set_smell("default","The smell of decay and refuse reach your nostrils");
	set_items(([
		"walls":"The walls are dark. They are covered with a surprisingly thin layer of slime."
	]));
	flag = 0;
}

void init(){
	::init();
	
	do_random_encounters(({"/d/tharis/monsters/gcube"}),10,1);
	do_random_encounters(({"/d/shadow/mon/rat"}),30,11);
	if(!flag && !present("ruffian") && interactive(TP)){
		
		ob = new("/d/tharis/monsters/iehater");
		ob->move(TO);
		ob->set("aggressive",3);
		ob2 = new("/d/tharis/monsters/iehater");
		ob2->move(TO);
		ob2->set("aggressive",3);

		ob3 = new("/d/tharis/monsters/iehater");
		ob3->move(TO);
		ob3->set("aggressive",3);		
	}
	if(!flag &&interactive(TP)){
		TP->add_follower(ob);
		TP->add_follower(ob2);
		TP->add_follower(ob3);
		flag = 1;
		call_out("set_back",40);
	}

}

void reset(){
	::reset();
	
	
	flag = 0;
}

void set_back(){
  if(objectp(ob))
	ob->set("aggressive",18);
  if(objectp(ob2))
	ob2->set("aggressive",18);
  if(objectp(ob3))
	ob3->set("aggressive",18);
	}

