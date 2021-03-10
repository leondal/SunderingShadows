#include <std.h>
#include <objects.h>
#include "/d/islands/coralsea/defs.h"
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void init(){
	::init();
		add_action("read_warning","read");
}

void create() {
	::create();
		set_property("light",3);
		set_property("no teleport",1);
		set_property("indoors",0);
		set_terrain(BARREN);
		set_travel(DECAYED_FLOOR);
		
		set_short("Coralsea Reef");
		set_long("%^RESET%^%^CYAN%^Just under the water's surface a "+
			"%^ORANGE%^coral shelf %^CYAN%^can be seen.  It appears "+
			"to have sustained a good deal of damage in recent years "+
			"as you can see that parts of it have been broken away, "+
			"leaving %^BOLD%^%^BLACK%^jagged edges%^RESET%^%^CYAN%^ "+
			"and %^RESET%^torn foundations%^CYAN%^.  This has the "+
			"benefit of creating a flat surface upon which you can "+
			"stand and dock your boat in the shallow water, but it "+
			"deters from the overall beauty of the reef.  The shelf "+
			"extends down deep into the sea, perhaps growing up "+
			"from some under water %^BOLD%^%^BLACK%^structure%^RESET%^"+
			"%^CYAN%^.  A recent addition to the shelf is a %^BOLD%^"+
			"%^BLACK%^metal pole%^RESET%^%^CYAN%^ upon which someone "+
			"has placed a %^RESET%^sign %^CYAN%^with directions.  "+
			"Oddly, on the back, it seems another person scribbled a "+
			"%^RED%^warning%^CYAN%^, perhaps you should read it."+
			"%^RESET%^");
		
		set_smell("default","\nYou smell the salty air of the ocean.");
		set_listen("default","The waves splash against the reef.");
		
		add_item(({"water","sea"}),"%^BOLD%^%^BLUE%^The water "+
			"stretches all around you, filing your vision with its "+
			"emptiness.  Maybe you should think about returning to "+
			"your boat before you're swept too far away.%^RESET%^");
		
		add_item(({"shelf","coral","coral shelf","reef"}),"%^RESET%^"+
			"%^ORANGE%^The shelf seems well developed and healthy, "+
			"despite the damage done to it in certain spots.  You "+
			"imagine that the underwater structure that it has grown "+
			"up upon is very old indeed.%^RESET%^");
		
		add_item(({"damage","edges","edge","foundation","surface"}),""+
			"%^BOLD%^%^BLACK%^A portion of the coral reef has been "+
			"damaged recently.  A wide flat trough has been carved "+
			"the top level, cutting a mostly smooth area out of the "+
			"otherwise rough coral.  From the size and shape of it, "+
			"its likely a ship ran aground here.%^RESET%^");
		
		add_item(({"pole","metal pole"}),"%^BOLD%^%^BLACK%^Someone "+
			"has hammered a long metal pole down into the coral reef "+
			"and affixed a sign atop of it.  The metal has begun to "+
			"oxidize, though you can still make out the words on the "+
			"sign. You could probably also secure your craft here so "+
			"that it doesn't drift off.%^RESET%^");
		
		add_item(({"structure"}),"%^BOLD%^%^BLACK%^It's hard to tell "+
			"what it is exactly, as covered in %^RESET%^%^ORANGE%^"+
			"coral %^BOLD%^%^BLACK%^as it is, but you think it might "+
			"be part of an underwater mountain system.  Maybe there "+
			"is a cave further down, though diving so close to the "+
			"reef would probably be suicide. Maybe you should swim "+
			"further out.%^RESET%^");
		
		set_exits(([
			"north":ROOMS"coral_s6",
			"east":ROOMS"coral_s9"
		]));
		
		set_pre_exit_functions(({"north"}),({"go_swimming"}));
		set_pre_exit_functions(({"east"}),({"go_swimming"}));
}

int read_warning(string str){
if(str == "warning"){
	tell_object(TP,"%^BOLD%^%^WHITE%^Please Take Note:%^RESET%^\n\n"+
			"%^YELLOW%^This area is intended for small groups "+
			"in their early twenties.  Much below that and you "+
			"may die.  Anything much over that and you'll probably "+
			"be driven off by the Guardian.  The area is located "+
			"almost completely under water, though prizes await "+
			"those bold enough to explore.  There might even be a "+
			"job or two for those clever enough to find them.  If "+
			"you get into a panic, you may %^WHITE%^<surface> "+
			"%^YELLOW%^but you will likely leave something of "+
			"yours behind! Also, be sure not to speak under water, "+
			"it might hurt. - You have been warned.%^RESET%^");
return 1;
}
return 0;
}

int go_swimming() {
    if(TP->query_highest_level() < 18) {
        tell_object(TP,"%^YELLOW%^The sea seems pretty turbulent. "+
			"You're not sure you are ready to go for this kind of "+
			"a swim yet.  If you haven't read the warning, maybe "+
			"now would be a good time to do so.%^RESET%^");
    }
	if(TP->query_highest_level() > 26) {
		tell_object(TP,"%^YELLOW%^What was that huge thing that "+
			"just vanished under water?  If you haven't read the "+
			"warning yet, maybe now would be a good time to do "+
			"so.%^RESET%^");
	}
    return 1;
}
