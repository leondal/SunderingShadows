#include <std.h>
#include "../theater.h"
inherit ROOM;
int FLAG;

	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun - ");
   	set_short("%^RED%^Desert Sun - Catwalk");
   	set_long("%^ORANGE%^Wooden planks create small platforms along"+
		" the support beams of the theater. "+
		"Numerous ropes and pulleys support backdrops, special lighting,"+
		" and props used in theatrical productions.  Because of the amount"+
		" of space these items require the catwalk has a cramped confining"+
		" feeling to it.  A backdrop has been cut from its ropes and propped"+
		" up against the western wall.  Thin strips of wood connect "+
		"together to create a"+
		" narrow walkway.  Careful though, it's a long way down from here. \n");   
   	set_smell("default","%^BOLD%^%^GREEN%^A sickening sweet smell fills the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^A feminine voice can be heard singing.");
  	set_items(([
      	({"walkway","planks","boards"}) : "%^ORANGE%^Dusty strips of wood create"+
	" the narrow walkway, the boards laying across the wooden beams.  The beams"+
	" don't look like they would hold much weight.",
		({"backdrops","props","prop","lights"}) : "%^BOLD%^%^RED%^"+
	"Cloth backdrops in a dazzling array of"+
	" somber and bright colors fill the majority of the catwalk area.  The "+
	"fabric backdrops are stretched on wooden frames and held afloat by "+
	"ropes and sandbags.  Intermixed with backdrops are smaller props, "+
	"such as trees, bushes and even a bookcase or two, which are lowered"+
	" onto the stage.  Special orbs of light are suspended on rope harnesses."+
	"  These lights are now dim, but at one time were used to bath the stage "+
	"in colors, helping to add to the mood of the scene.  A large backdrop that"+
	" depicts a cloudy mountain top scene has been cut from its ropes and propped"+
	" up against the west wall.",
      	({"mountain top","mountain","backdrop"}) : "%^CYAN%^The background of this scene"+
	" features %^BOLD%^%^BLACK%^dark gray%^RESET%^%^CYAN%^ clouds that cover the"+
	" %^BLUE%^dark blue%^CYAN%^ sky.  A craggy %^ORANGE%^mountain top%^CYAN%^"+
	" dominates the scene, set dead center in the canvas.  Thin wispy %^RESET%^"+
	"clouds%^CYAN%^ have been painted in the foreground, giving a three dimensional"+
	" effect to the painting.  This backdrop is propped up against the western wall"+
	", cut from its ropes.",
		({"floor"}) : "%^YELLOW%^Though the floor of the catwalk is covered by the "+
	"ceiling of the theater, you get the feeling that it won't hold much weight.  "+
	"Best not to fall and test if the ceiling will hold.  That would be a long way "+
	"down.",
		({"ropes","pulley","pulleys"}) : "%^ORANGE%^The system used to store"+
	" these items is rather ingenious.  Instead of allowing the items to only be "+
	"raised or lower, the hardware allows the items to move horizontally as well."+
	"  This allows stagehands to push unused items back in the holding area to clear"+
	" up the space behind to stage.",
	]));
	set_exits(([ "north" : ROOMDIR"cat7",
			 "south" : ROOMDIR"cat9",
			 "east" : ROOMDIR"cat5",
	]));
}


void init(){
	::init();
		add_action("move","move");
		add_action("move","lift");
}
int move(string str){
 	if(str != "backdrop" && str != "mountain backdrop") 
      return notify_fail("Move what?\n");
	
		tell_object(TP,"%^CYAN%^You push the backdrop of the "+
			"mountain top aside and find a large opening to the west.");
		tell_room(ETP,"%^CYAN%^"+TPQCN+" pushes the backdrop of"+
			" the mountain top aside, revealing a large opening to the"+
			" west.",TP);
				add_exit(ROOMDIR"nest","west");
					FLAG = 1;
		return 1;
}
void reset() { 
	::reset(); 
		FLAG=0; 
	return; 
}
