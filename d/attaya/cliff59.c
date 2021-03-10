
#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_short("Entrance to the shadowy rotunda.");
	set_property("indoors",1);
	set_property("light",2);
set_long("
    The passage opens out into a large circular room called the Rotunda here.  A few steps decend to the floor of the chamber.  A massive altar lies at the center.  This is a place of worship.
");
       set_exits(([
          "steps":"/d/attaya/cliff60",
          "east":"/d/attaya/cliff58",
]));
	
      set_listen("default", "Screams echo through this hall");
	}

void reset(){
	int num, i;
	::reset();
	
	if(!present("guardian")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/guardian")->move(TO);
	}
	
}
