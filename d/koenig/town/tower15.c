#include <std.h>
inherit VAULT;

void create(){
  	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  	set_name("tower15");
  	set_property("light", 1);
  	set_property("indoors", 1);
  	set_short("A Huge Room");
  	set_long("%^BOLD%^%^WHITE%^In this part of the room there is only an %^RESET%^%^CYAN%^overstuffed chair%^BOLD%^%^WHITE%^ and "+
                "several large %^RESET%^%^CYAN%^cushions%^BOLD%^%^WHITE%^ thrown about the foot of the chair.  "+
  		"%^MAGENTA%^Tapestries%^BOLD%^%^WHITE%^ hang from the wall, and as you gaze to the east you "+
  		"notice a %^RESET%^%^ORANGE%^door%^BOLD%^%^WHITE%^ that may lead you out of the tower and to safety.%^RESET%^"+
  		"%^RESET%^\n"
  	);
  	set_smell("default", "You can smell many things here.");
  	set_smell("things", "You can smell the burning wood in the "+
                "fireplace, burning incense, and if you're not mistaken you can "+
  		"even smell some flowers.");
  	set_listen("default", "You hear the crackling and occassional pop from "+
  		"the burning wood in the fireplaces.");
  	set_items( ([
     		"chair" : "It is very large and looks so very comfortable...maybe "+
     			"you can sit in it...",
     		"cushions" : "These cushions vary in color but all of them are large "+
     			"enough to sit on.",
     		"tapestries" : "There are only two tapestries hanging on the wall here. Maybe you can look at them individually.",
     		"tapestry 1" : "This tapestry is of two lovers enjoying a moment...a very "+
     			"intimate moment it looks like...%^RED%^You feel yourself begin to "+
			"blush%^RESET%^...finally you look away.",
     		"tapestry 2" : "%^GREEN%^This one shows a beautiful clearing backed "+
     			"by snow covered mountains.%^RESET%^"
	]) );
  	set_exits( ([
     		"east" : "/d/koenig/town/tower16",
     		"west" : "/d/koenig/town/tower14",
     		"south" : "/d/koenig/town/tower12"
	]) );
  	set_trap_functions( ({"cushions"}),({"meditate_healing"}),({"sit"}) );
}
void meditate_healing() {
  	int meditate, healing;
  	tell_object(TP,"You feel yourself sink back into the cushions.");
        tell_object(TP,"You can't help yourself from closing your eyes...");
  	tell_object(TP,"You feel your body relax...and your tensions ease...");
  	tell_object(TP,"You slip into a meditating state of relaxation...");
  	tell_room(ETP,"You see "+TPQCN+" begin to close their eyes...",TP);
  	tell_room(ETP,"Your mouth gaps open as you see "+TPQCN+" drop "+
  		"into a meditating state and drift inches above the floor "+
  		"on one of the cushions.",TP);
  	tell_room(ETP,"You see "+TPQCN+" slowly lower back down, open their "+
  		"eyes and get up as if nothing strange just occured.",TP);
        tell_object(TP,"%^BOLD%^%^CYAN%^You feel as if you're floating on "+
  		"air...you feel refreshed somehow.");
  	meditate = random(4)+1;
  	healing = random(5)+1;
  	TP->heal(healing*meditate/2);
}
void init(){
  	::init();
  	add_action("sit_chair", "sit");
  	add_action("sit_cushions", "sit");
}
int sit_chair(string str){
  	if(!str)return notify_fail("Try again bub.");
  	if(lower_case(str) != "chair")return notify_fail("You cant sit there fool!");
  	tell_object(TP,"You sit down in the big comfortable chair.");
  	tell_room(ETP,"You see "+TPQCN+" sit down in the big comfortable chair.",TP);
}
int sit_cushions(string str){
  	if(!str)return notify_fail("Try again bub.");
  	if(lower_case(str) != "cushions")return notify_fail("You cant sit there fool!");
  	tell_object(TP,"You sit down on one of the many large colorful cushions here.");
  	tell_room(ETP,"You see "+TPQCN+" sit down on one of the many large "+
  		"colorful cushions here.",TP);
  	return 1;
}
