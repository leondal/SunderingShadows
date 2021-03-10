#include <std.h>
#include "../theater.h"
inherit CROOM;
int FLAG;
	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun Theater - Backstage");
   	set_short("%^RED%^Desert Sun Theater - Backstage");
   	set_long("%^BOLD%^%^BLACK%^Climbing up through the"+
		" access platform, the backstage of the theater reveals"+
		" itself.  A wall of%^YELLOW%^ timber%^BLACK%^, %^CYAN%^"+
		"rubble%^BLACK%^, and%^WHITE%^ stone%^BLACK%^ has left "+
		"the stage shattered and broken, blocking off all access"+
		" to the auditorium. Hanging from the rafters is a massive"+
		" backdrop that dominates what remains of the stage.  The "+
		"large backdrop features a%^RED%^ r%^RESET%^%^RED%^e%^BOLD%^"+
		"d%^BLACK%^ sky that graduates from%^RED%^ lighter %^BLACK%^"+
		"shades at the top to%^RESET%^%^RED%^ darker%^BOLD%^%^BLACK%^"+
		" nearly black shades at the bottom.  Graduated black and dark"+
		" grey clouds have been painted across the red sky, adding a "+
		"malevolent feeling to the scene.  The wooden floor of the "+
		"backdrop is spotted with %^RESET%^%^ORANGE%^dried blood "+
		"%^BOLD%^%^BLACK%^stains, though no bodies are present.  "+
		"The backstage area is bathed by a single %^RED%^red%^BLACK%^"+
		" light, which serves to further highlight the red backdrop and"+
		" distort the dark shadows around you.  \n");
   	set_smell("default","%^RED%^A metallic scent lingers in the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^There is an eerie stillness around you.");
  	set_items(([
      	({"backdrop","red backdrop"}) : "%^BOLD%^%^BLACK%^Unlike "+
	"the other canvas backdrops you have seen in the theater, this "+
	"one seems to be made from silk.  %^WHITE%^G%^RED%^r%^WHITE%^a"+
	"%^RED%^d%^RESET%^%^RED%^u%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^"+
	"%^BLACK%^i%^RESET%^%^RED%^n%^BOLD%^%^BLACK%^g shades of red "+
	"create the sky of this backdrop that dominates the backstage "+
	"area.  The shades of red start out%^RED%^ lighter%^BLACK%^ at"+
	" the top and faded down into %^RESET%^%^RED%^deeper%^BOLD%^"+
	"%^BLACK%^ nearly black shades at the bottom.  %^RESET%^G%^BOLD%^"+
	"%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^"+
	"a%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^d%^BOLD%^%^BLACK%^ black "+
	"and dark gray wispy clouds have been painted across the red "+
	"background.  The backdrop is bathed in the glow from a %^RED%^"+
	"red%^BLACK%^ light, making the red colors seems to pop off the"+
	" fabric.  There seems to be some %^RESET%^%^ORANGE%^splotches"+
	"%^BOLD%^%^BLACK%^ on the silk.",
      	({"splotches"}) : "%^ORANGE%^It is hard to make out "+
	"what the splotches are in this lighting, though they seem "+
	"to be a different shade and color than the reds in the "+
	"backdrop.  They almost seem, brownish.  The texture of "+
	"the splotches seems thicker than the dye used to paint. "+
	"the backdrop, though now they have dried to hardened flecks",
		({"light","red light"}) : "%^BOLD%^%^RED%^A single red"+
	" light from high up in the theater bathes the backstage area"+
	" in a red glow.  They lighting is faint and only seems to "+
	"serve to illuminate the backdrop.  Though it seems to have "+
	"a good effect on deepening the shadows around you, to the "+
	"point where you can't make out the rest of the backstage area.",
		({"blood stains","stains"}) : "%^ORANGE%^Dried splatters"+
	" of blood stain the wooden stage.  The blood seems numerous "+
	"enough to suggest an attack of some kind, though there are "+
	"no pools of blood.  For that matter there are no bodies "+
	"either.  Very strange indeed.",
		({"wall","stones","timber","rubble"}) : "%^BOLD%^%^WHITE%^A "+
	"massive wall of %^YELLOW%^timber%^WHITE%^, rubble, and stone"+
	" blocks access to the auditorium, and the exit you know lays"+
	" on the other side.  It seems as if someone went to a great"+
	" deal of trouble to separate the stage from the auditorium.",
	]));
	set_exits(([ "platform" : ROOMDIR"under1",
			 "hole" : ROOMDIR"dso4",
	]));
	set_invis_exits(({"hole",}));
      set_pre_exit_functions(({"hole",}),({"hole_preExit",}));
	set_post_exit_functions(({"hole",}),({"hole_postExit",}));
}
int hole_postExit()
{
	write("%^YELLOW%^The timber cracks and snaps."+
		"  A mountain of rubble and stone seals the hole off.");
        	return 1;
}

void init(){
	::init();
		add_action("move","move");
}
int hole_preExit(){
    	if(!FLAG) {
     		tell_object(TP,"You cannot go that way.");
      return 0;
}
   	return 1;

}

int move(string str){
 	if(str != "rubble" && str != "wall" && str != "timber" && str !="stones") 
      return notify_fail("Move what?\n");

   	tell_object(TP,"%^BOLD%^%^RED%^You fight against the mountain"+
		" of stone to keep the hole from collapsing.  Grabbing a piece "+
		"of timber you are able to wedge it in the hole buying you just"+
		" enough time to get through.");
	tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" fights against the "+
		"mountain of stone to keep the hole from collapsing. Reaching "+
		"for a piece of timber "+TPQS+" wedges it in the collapsing"+
		" hole, buying just enough time to escape.  Hurry if you wish "+
		"to escape!",TP);
        		remove_invis_exit("hole");
			FLAG = 1;
	return 1;
} 
void reset()
{
    	::reset();
    	if(!present("marionette")) 
{
	new(MOB"marionette")->move(TO) ;
    	return;
}
	FLAG=0;
}