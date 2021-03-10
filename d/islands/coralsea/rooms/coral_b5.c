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
	
		set_long("%^RESET%^%^CYAN%^This room is surprisingly sound, "+
			"which is a bit of a mystery since the rest of the "+
			"structure is in such poor shape, yet the painted walls "+
			"still display the rich %^BOLD%^%^MAGENTA%^pastel pink "+
			"hues %^RESET%^%^CYAN%^with %^BOLD%^%^WHITE%^white clouds "+
			"%^RESET%^%^CYAN%^and small %^BOLD%^%^MAGENTA%^b%^CYAN%^"+
			"u%^YELLOW%^t%^RESET%^%^ORANGE%^t%^MAGENTA%^%^BOLD%^erf"+
			"%^YELLOW%^l%^CYAN%^i%^RESET%^%^ORANGE%^e%^BOLD%^"+
			"%^MAGENTA%^s %^RESET%^%^CYAN%^frozen mid-flitter.  A "+
			"child sized %^ORANGE%^four-poster bed %^CYAN%^sits in "+
			"the center of the room, its mattress and drapes both "+
			"gone except for a few tattered strips hanging off "+
			"%^BOLD%^%^WHITE%^silver rings%^RESET%^%^CYAN%^.  A "+
			"%^ORANGE%^writing desk %^CYAN%^is pushed up against "+
			"one wall, and against the other is a %^ORANGE%^wardrobe"+
			"%^CYAN%^.  The final wall holds a beautiful and very "+
			"well preserved %^BOLD%^tapestry %^RESET%^%^CYAN%^of a "+
			"small village setting.  It seems quiet inviting and "+
			"based on where it's hung, the child that likely lived "+
			"in this room woke each morning to the smiling faces of "+
			"the villagers.%^RESET%^");
			
		add_item(({"tapestry"}),"%^BOLD%^%^CYAN%^The tapestry shows "+
			"a village setting with people coming and going in a "+
			"market square.  Vivid and life like it makes you want "+
			"to %^WHITE%^study %^CYAN%^it further to see all the "+
			"little details.%^RESET%^");

		add_item(({"walls","hues","clouds","butterflies"}),"%^BOLD%^"+
			"%^MAGENTA%^The walls of this room are painted a pale "+
			"pastel shade of pink.  Though a bit faded, especially "+
			"at the joints, the color still is eye catching in light "+
			"of how drab the rest of the place has been.  %^WHITE%^"+
			"Clouds %^MAGENTA%^and b%^CYAN%^u%^YELLOW%^t%^RESET%^"+
			"%^ORANGE%^t%^MAGENTA%^%^BOLD%^erf%^YELLOW%^l%^CYAN%^i"+
			"%^RESET%^%^ORANGE%^e%^BOLD%^%^MAGENTA%^s have been "+
			"painted here and there, giving a bit of contrast to "+
			"the pink as well as brightening the room further with "+
			"their fanciful designs.%^RESET%^");

		add_item(({"bed","four-poster bed","curtains","rings",
			"silver rings"}),"%^RESET%^%^ORANGE%^ Situated in the "+
			"center of the room, this small bed is meant to "+
			"accommodate a young child.  The wooden posts rise up "+
			"at each corner and are carved like small trees whose "+
			"branches fan out over the top creating a canopy of "+
			"wooden leaves.  Here and there small silver rings can "+
			"be seen along the edges from which a few scraps of "+
			"cloth hang, likely the remains of the curtains that "+
			"could be drawn open or closed around the bed.%^RESET%^");

		add_item(({"wardrobe"}),"%^RESET%^%^ORANGE%^The wardrobe "+
			"is a simple affair with two dresser drawers on the "+
			"bottom and a cabinet on top.  Though it seems to have "+
			"the same forest motif as the bed, the cabinet has begun "+
			"to crumble and break apart and appears to hold nothing "+
			"of interest.%^RESET%^");

		add_item(({"desk"}),"%^RESET%^%^ORANGE%^There isn't much "+
			"left of the desk and certainly nothing of interest "+
			"within the drawers.  A couple empty ink bottles suggest "+
			"that the child that lived here enjoyed writing or "+
			"drawing, but all other evidence of such behavior has "+
			"drifted away on the currents.%^RESET%^");
	
	
		set_exits(([
			"north":ROOMS"coral_b3"
		]));
}

int ready_movie(string str) {
	if (!str) {
		notify_fail("%^BOLD%^%^WHITE%^What did you want to study? "+
			"Maybe the tapestry?%^RESET%^");
     return 0;
	}
	if (str != "tapestry" && str != "wall hanging") {
		notify_fail("%^BOLD%^%^WHITE%^Studying the "+str+" doesn't "+
		"seem like a wise use of your time.%^RESET%^");
     return 0;
	}
	tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" swims up to the "+
		"tapestry and begins to study it intently.%^RESET%^",TP);
	
	write(""+CHILDSROOM[0]+"\n\n");
	TP->set_property("childsroom",1);
	call_out("domsg",1,TP);
	return 1;
}

void domsg(object ob){
	int flag;
	flag = ob->query_property("childsroom");
	ob->remove_property("childsroom");
	if(flag < sizeof(CHILDSROOM) && environment(ob) == TO){
		tell_object(ob,""+CHILDSROOM[flag]+"\n\n");
		flag++;
		ob->set_property("childsroom",flag);
		call_out("domsg",5,ob);
	}
	else {
		tell_object(ob,"%^BOLD%^%^WHITE%^You shake your head and shiver. "+
			"That seemed almost real.  \nAmazing how good some magic can "+
			"be. %^RESET%^");
		tell_room(environment(ob),"%^BOLD%^%^WHITE%^"+ob->QCN+" swims "+
			"back from the tapestry.%^RESET%^",ob);
   }
}