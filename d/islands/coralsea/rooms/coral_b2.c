#include <std.h>
#include "../defs.h"
inherit BASE"coraltower";

// Coral Sea Area - Created January 2009 by Ari



void init(){
	::init();
		add_action("ready_movie","study");
}

void create(){
	::create();
	
		set_long("%^RESET%^%^CYAN%^Once a plush and well appointed room, "+
			"what remains is little more then piles of %^ORANGE%^rotted "+
			"wood %^CYAN%^covered by the %^GREEN%^algae %^CYAN%^that "+
			"grows thickly within this darkness.  Tiny %^RED%^"+
			"crustaceans %^CYAN%^dart in and out of holes within the "+
			"sprawling mass.  Making their homes amongst the %^BOLD%^"+
			"%^BLACK%^metal slivers %^RESET%^%^CYAN%^that still remain "+
			"after the wooden beams have surrendered to the currents.  "+
			"On one wall, the ragged tatters of a %^RESET%^wall "+
			"hanging %^CYAN%^drift, all but chewed up by the %^RESET%^"+
			"fish %^CYAN%^that dart about this room.  Another chamber "+
			"lays beyond as does the collapsed hall behind you.%^RESET%^");

		add_item(({"metal","slivers","wood","rubble","remains"}),""+
			"%^RESET%^%^ORANGE%^Judging by where the remains of wood "+
			"and metal are located, this was once a bedroom. Though "+
			"there is little left of the bed or other furniture, "+
			"there is some shape to it that suggests it was a plush "+
			"and comfortable apartment at one point.");
			
		add_item(({"crustations","fish"}),"%^RESET%^%^RED%^Living "+
			"within the remains of this room are tiny fish and the "+
			"crabs, lobster and other animals which feed upon such "+
			"prey.  Most dart away into crevices as soon as you "+
			"approach.%^RESET%^");
			
		add_item(({"hanging","wall hanging","wall"}),"%^BOLD%^"+
			"%^WHITE%^Hanging from the back wall are the %^RESET%^"+
			"%^CYAN%^algae eaten tatters %^BOLD%^%^WHITE%^of a wall "+
			"hanging.  Looking close you can see what appears to be "+
			"a tall %^BLACK%^tower %^WHITE%^on top of a %^GREEN%^"+
			"island plateau%^WHITE%^.  In front of the tower a "+
			"%^GREEN%^garden maze %^WHITE%^extends in a half circle "+
			"around the building.  Curiously, you think you "+
			"can see %^RED%^horrific creatures %^WHITE%^roaming within "+
			"the maze.  So lifelike is the image, that you feel drawn to "+
			"%^GREEN%^study%^WHITE%^ it.%^RESET%^");
		
		add_item(({"algae"}),"%^RESET%^%^GREEN%^Algae grows over most "+
			"of the room, covering it in a thin layer of living green "+
			"carpet.%^RESET%^");
			
		set_exits(([
			"south":ROOMS"coral_b3",
			"southwest":ROOMS"coral_b1"
		]));
}

int ready_movie(string str) {
	if (!str) {
		notify_fail("%^BOLD%^%^WHITE%^What did you want to study? "+
			"Maybe the wall hanging?%^RESET%^");
     return 0;
	}
	if (str != "wall hanging" && str != "hanging") {
		notify_fail("%^BOLD%^%^WHITE%^Studying the "+str+" doesn't "+
		"seem like a wise use of your time.%^RESET%^");
     return 0;
	}
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" swims up to the wall "+
		"hanging and begins to study it intently.%^RESET%^",TP);
	
	write(""+MASTERBEDROOM[0]+"\n\n");
	TP->set_property("masterbedroom",1);
	call_out("domsg",1,TP);
	return 1;
}

void domsg(object ob){
	int flag;
	flag = ob->query_property("masterbedroom");
	ob->remove_property("masterbedroom");
	if(flag < sizeof(MASTERBEDROOM) && environment(ob) == TO){
		tell_object(ob,""+MASTERBEDROOM[flag]+"\n\n");
		flag++;
		ob->set_property("masterbedroom",flag);
		call_out("domsg",5,ob);
	}
	else {
		tell_object(ob,"%^BOLD%^%^WHITE%^You blink and swim back "+
			"from the wall hanging.  Maybe it was just an effect "+
			"of the water that made it seem like things were "+
			"moving.%^RESET%^");
		tell_room(environment(ob),"%^BOLD%^%^WHITE%^"+ob->QCN+" shakes "+
			"their head and swims away from the wall hanging."+
			"%^RESET%^",ob);
   }
}