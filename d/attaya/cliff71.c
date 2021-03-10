#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
	::create();
	set_short("%^BOLD%^%^BLACK%^The end");
	set_property("indoors",0);
	set_property("light",2);
    set_long("%^BOLD%^%^BLACK%^The end
%^BOLD%^%^WHITE%^You seem to have taken a wrong direction. Undead warriors are rising from a nearby snowdrift and surrounding you! Blood discolors the %^RED%^snow%^WHITE%^ here. The %^BLACK%^body%^WHITE%^ of a young girl lies bleeding on the ledge.
");
    set_exits(([
                   "east":"/d/attaya/cliff72",
                   ]));
    set_items(([
                   "body" : "It is the body of a young girl, killed recently.",
                   "girl" : "She is a beautiful young girl, who has met an untimely end in the cold hights of the mountainside.",
                   "snow" : "It is littered with bones."
                   ]));
	
    set_listen("default", "The undead warriors scream horribly");
}

void reset(){
	int num, i;
	::reset();
	
	if(!present("entity")){
		num = random(5)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/uwarrior")->move(TO);
        new("/d/attaya/mon/guardian")->move(TO);
        new("/d/attaya/mon/phalanx")->move(TO);
	}
	
}
