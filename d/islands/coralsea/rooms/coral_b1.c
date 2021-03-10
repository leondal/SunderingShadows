#include <std.h>
#include "../defs.h"
inherit BASE"coraltower";

// Coral Sea Area - Created January 2009 by Ari

void init(){
	::init();
		add_action("lift_net","lift");
}

void create(){
	::create();
		
		set_long("%^RESET%^%^CYAN%^The open water stretches outward "+
			"from this ruined balcony.  Long since collapsed under the "+
			"weight and pressure of the %^BLUE%^water %^CYAN%^and "+
			"%^ORANGE%^coral%^CYAN%^, what remains is but a few stones "+
			"close to the structure's edge.  Balanced precariously "+
			"along the small portion of remaining balcony, the %^RESET%^"+
			"%^ORANGE%^wooden masthead %^CYAN%^of a ship peers "+
			"longingly at the doorway.  The single remaining arm "+
			"reaching toward the entry while the bowspirit's netting "+
			"twists away from her shoulders like braids of %^WHITE%^"+
			"webbed hair%^CYAN%^.  This netting extends over the only "+
			"egress and prevents swimming further out into the water."+
			"%^RESET%^");

		add_item(({"net","netting","web","hair"}),"%^BOLD%^%^WHITE%^"+
			"What appears to have been fine silk netting now lays "+
			"encircling the balcony and is part of the reason why "+
			"the masthead hasn't fallen away.  Like an extension of "+
			"her white hair, the netting almost blends into the "+
			"coral ledges where it has snagged.%^RESET%^");
		
		add_item(({"ledges","edge"}),"%^RESET%^%^ORANGE%^You look "+
			"closely along the balcony's edge and notice that a "+
			"bit of the netting is loose in one spot.  You might "+
			"be able to lift it if you were careful.");
			
		add_item(({"coral","stones"}),"%^RESET%^%^ORANGE%^Only a "+
			"small portion of the balcony remains intact after being "+
			"struck by part of a large ship. Coral and stone are "+
			"shorn away where the remainder of the ship struck and "+
			"then brought the balcony down. Only a small portion of "+
			"the bowspirit remains, that of the masthead.%^RESET%^");
			
		add_item(({"egress"}),"%^BOLD%^%^WHITE%^Beyond the netting "+
			"you can see a kelp forest extending out into the dark "+
			"waters.  The long strands waving back and forth with "+
			"the current that flows endlessly through the ocean.  "+
			"Parts of the ship can be seen hidden deep within it, "+
			"but there's no way to reach it from here without "+
			"finding a way past the netting.%^RESET%^");
			
		add_item(({"masthead"}),"%^RESET%^%^ORANGE%^The masthead is "+
			"a beautiful carving of a woman's upper torso, blending "+
			"perfectly into what little of the ship's wood remains.  "+
			"Her arms were once outstretched, though one has broken "+
			"away and left the other to support the majority of the "+
			"two hands and the clam shaped item they once held "+
			"outward.  Painted, she appears lovely with soft skin "+
			"and emerald green eyes.  White locks curl around her "+
			"shoulders and flow back into the ship's wood, helping "+
			"to disguise the joints.%^RESET%^");
			
		add_item(({"clam"}),"%^BOLD%^%^WHITE%^You peer closely at "+
			"the clam shell held in the masthead's outstretched "+
			"arms and notice that there is a thin line that might "+
			"mean it can be opened.  Perhaps if you searched around "+
			"it you could find a way to open it.%^RESET%^");
		
		set_exits(([
			"northeast":ROOMS"coral_b2"
		]));
		
		set_search("default","%^BOLD%^%^WHITE%^Search what?%^RESET%^");
		set_search("clam",(:TO,"search_clam":));
		set_search("line",(:TO,"search_clam":));
}

int search_clam(string str){
	object ob;
	if(str == "clam" || str == "line"){
		tell_object(TP,"%^BOLD%^%^WHITE%^You search along the edge of "+
			"the clamshell and reveal a small latch.\n"+
			"The shell opens, leaking a few bubbles and reveals a "+
			"%^YELLOW%^brass key.%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^WHITE%^A few bubbles escape as "+
			""+TP->QCN+" opens the clamshell.%^RESET%^");
		new(OBJ"coral_brasskey.c")->move(TO);
		return 1;
	}
}

void lift_net(string str){
	object ob;
	if(str == "net" || str == "netting"){
		tell_object(TP,"%^BOLD%^%^WHITE%^You search around and find a "+
			"loose piece of net to lift off the coral and create a "+
			"way out into the kelp.%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" searches along "+
			"the net's edge.%^RESET%^",TP);
				add_exit(ROOMS"coral_m8","hole");
		return 1;
	}
	else{
		tell_object(TP,"%^BOLD%^%^WHITE%^You can't seem to find a "+
			"loose piece of netting to lift.%^RESET%^");
		return 1;
	}
}

void reset(){
	::reset();
		remove_exit("coral_m8");
		tell_room(TO,"%^BOLD%^%^CYAN%^The current shifts, moving "+
			"the net.%^RESET%^");
}
	