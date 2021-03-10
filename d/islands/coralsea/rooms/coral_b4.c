#include <std.h>
#include "../defs.h"
inherit BASE"coraltower";

// Coral Sea Area - Created January 2009 by Ari

int FLAG;

void create(){
	::create();
		set_exits(([
			"west":ROOMS"coral_b3",
			"out":ROOMS"coral_s18"
		]));

		set_search("default","%^BOLD%^%^BLACK%^Perhaps the rubble hides "+
			"something interesting.%^RESET%^");
			set_search("rubble",(:TO,"search_trash":));
}

int search_trash(string str){
	object ob;
	if(FLAG == 1){
		tell_room(ETO,"%^BOLD%^%^BLUE%^The rubble appears to already have "+
			"been sifted through.%^RESET%^");
		return 1;
	}

	if(str == "rubble"){
		switch(random(10)){

			case 0..3:
			tell_room(ETP,"%^BOLD%^%^WHITE%^Some rubble shifts and reveals "+
				"a hard shell clam. Maybe there's a p%^MAGENTA%^e%^RESET%^a"+
				"%^BOLD%^%^WHITE%^rl inside!%^RESET%^");
				new(OBJ"coral_clam")->move(TO);
			break;

			case 4:
			tell_room(ETP,"%^RESET%^%^ORANGE%^"+TP->QCN+" pulls a bit of "+
				"trash from a pile of rubble.%^RESET%^");
				ob = new("/d/magic/scroll");
					ob->set_spell(random(2)+3);
					ob->move(ETP);
			break;
			
			case 5..8:
			tell_room(ETP,"%^BOLD%^%^BLACK%^The rubble shifts and casts "+
				"a cloud of debris into the water.%^RESET%^");
			break;

			case 9:
			tell_room(ETP,"%^YELLOW%^Some rubble shifts and a few coins "+
				"spill from the remains.%^RESET%^");
				ob = new("/std/obj/coins");
					ob->set_money("gold",random(50)+random(100));
					ob->move(ETP);
			break;

			}
	FLAG = 1;
	}
return 1;
}

void reset(){
	::reset();
		FLAG = 0;
}