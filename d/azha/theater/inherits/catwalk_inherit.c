#include <std.h>
#include "../theater.h"
inherit CROOM;
int FLAG;  
	void make_creatures();
	void create(){
	object obj;
   	::create();
      make_creatures();
      set_repop(55);
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun - Catwalk");
   	set_short("%^RED%^Desert Sun - Catwalk");
   	set_long("%^ORANGE%^Wooden planks create small platforms along"+
		" the support beams of the theater. "+
		"Numerous ropes and pulleys support backdrops, special lighting,"+
		" and props used in theatrical productions.  Because of the amount"+
		" of space these items require the catwalk has a cramped confining"+
		" feeling to it.  Thin strips of wood connect together to create a"+
		" narrow walkway.  Careful though, it's a long way down from here. \n");  
   	set_smell("default","%^BOLD%^%^GREEN%^A sickening sweet smell fills the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^A feminine voice can be heard singing.");
  	set_items(([
      	({"walkway","planks","boards"}) : "%^ORANGE%^Dusty strips of "+
	"wood create"+
	" the narrow walkway, the boards laying across the wooden beams.  "+
	"The beams don't look like they would hold much weight.",
		({"backdrops","props","prop","lights"}) : "%^BOLD%^%^RED%^"+
	"Cloth backdrops in a dazzling array of"+
	" somber and bright colors fill the majority of the catwalk area.  The "+
	"fabric backdrops are stretched on wooden frames and held afloat by "+
	"ropes and sandbags.  Intermixed with backdrops are smaller props, "+
	"such as trees, bushes and even a bookcase or two, which are lowered"+
	" onto the stage.  Special orbs of light are suspended on rope harnesses."+
	"  These lights are now dim, but at one time were used to bath the stage "+
	"in colors, helping to add to the mood of the scene.  Strange there seem to"+
	" be quite a few %^BOLD%^%^BLACK%^darker shapes%^RED%^ higher up.",
      	({"shapes"}) : "%^BOLD%^%^BLACK%^The shapes have a vague humanoid shape"+
	" to them.  Occasionally they will sway in a breeze, but for the most part they"+
	" seem still and lifeless.  Wonder if you can %^CYAN%^lower%^BLACK%^ one to get"+
	" a better look",
		({"floor"}) : "%^YELLOW%^Though the floor of the catwalk is covered by the "+
	"ceiling of the theater, you get the feeling that it won't hold much weight.  "+
	"Best not to fall and test if the ceiling will hold.  That would be a long way "+
	"down.",
		({"ropes","pulley","pulleys","rope","sandbags"}) : "%^ORANGE%^The system used to store"+
	" these items is rather ingenious.  Instead of allowing the items to only be "+
	"raised or lowered, the hardware allows the items to move horizontally as well."+
	"  This allows stagehands to push unused items back in the holding area to clear"+
        " up the space behind the stage."
	]));
	set_search("corpse", (: TO, "search_corpse" :) );
    	set_search("body", (: TO, "search_corpse" :) );
	make_creatures();

}
void init()
{	::init();
   		add_action("lower_fun","lower");
     	return;
}
int lower_fun(string str) {
if(!str) {
     	tell_object(TP,"%^YELLOW%^Lower what?\n");
      return 1;
}
if(str != "rope") {
   	tell_object(TP,"%^YELLOW%^After studying the rope"+
		" you find that, yes it is rope.\n");
     	return 1;
}
    	tell_object(TP,"%^YELLOW%^You find the rope that connects to the"+
		" strange shape and give it a pull.\n\n\n\nAs you keep "+
		"pulling on the rope the strange shape reveals"+
		" itself to be a body!");
    	tell_room(ETP,"%^YELLOW%^"+TPQCN+" finds the rope that connects"+
		" to the strange shape and gives it a pull.\n\n\n\nAs the"+
		" strange shape lowers into view it is "+
		"revealed to be a body!",TP);
    			new(OBJ"bodies")->move(TO);	
	return 1;
}
	void search_corpse() 
{
    	if(!present("special_corpse",TO)) {
		tell_object(TP,"You find nothing odd.");
    	return; 
	}
	if(present("theater_mon")){
   		tell_object(TP,"Yeah, right, they won't let you search that.");
   	return 1;
	}
	if(FLAG) { 
		tell_object(TP,"The corpse has already been searched");
	return; 
	}
		switch(random(20)){
case 1..2:
   	tell_object(TP,"%^ORANGE%^You search through the body"+
		" and discover a pendant around it's neck.\n");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
		"the body and discovers something.",TP);
      		new("/d/tharis/obj/rings/pendant_three.c")->move(TO);
break;
case 3..4:
     	tell_object(TP,"%^ORANGE%^You search through the body "+
		"and discover a ring attached to a finger.\n");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
		"the body and discovers something.",TP);
			new("/d/antioch/antioch2/obj/r_ring.c")->move(TO);
break;
case 5..6:
    	tell_object(TP,"%^ORANGE%^You search through the body"+
		" and discover a bracelet attached to an arm.\n");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
		"the body and discovers something.",TP);
			new("/d/tharis/obj/rings/bangle_bracelet.c")->move(TO);
break;
case 7..8:
    	tell_object(TP,"%^ORANGE%^You search through the body"+
		" and discover a circlet on it's head.");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
		"the body and discovers something.",TP);
			new("/d/antioch/antioch2/obj/r_circlet.c")->move(TO);
break;
case 9..10:
     	tell_object(TP,"%^ORANGE%^You search through the body"+
		" and discover a clasp pinned to it's rotting clothes.");
     	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
		"the body and discovers something.",TP);
			new("/d/dagger/Daggerdale/shops/items/r_clasp.c")->move(TO);
break;
default:
	tell_object(TP,"%^ORANGE%^You search through the body"+
		" and discover a handful of %^BOLD%^%^WHITE%^maggots"+
		"%^RESET%^%^ORANGE%^!");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
		"the body and finds a handful of %^BOLD%^%^WHITE%^"+
		"maggots%^RESET%^%^ORANGE%^.",TP);
break;
		}    
FLAG=1;
}
void make_creatures()
{       
        int monsters;
        monsters = has_mobs();
        if(!monsters) {
                if(mons) { mons = ([]); }
                       switch(random(60)){
			case 0..20:
			break;
			case 21..24:
			set_monsters(({MOB"marion_fighter"}),({1}));
			break;
			case 25..30:
			set_monsters(({MOB"marion_cleric"}),({1}));
			break;
			case 31..34:
			set_monsters(({MOB"marion_thief"}),({1}));
			break;
			case 35..39:
			set_monsters(({MOB"marion_cavalier"}),({1}));
			break;
			case 40..42:
			set_monsters(({MOB"marion_fighter"}),({1}));
			set_monsters(({MOB"marion_thief"}),({1}));
			break;
			case 43..45:
			set_monsters(({MOB"marion_fighter"}),({1}));
			set_monsters(({MOB"marion_cleric"}),({1}));
			break;
			case 46..50:
			set_monsters(({MOB"marion_fighter"}),({1}));
			set_monsters(({MOB"marion_cavalier"}),({1}));
			break;
			case 51..55:
			set_monsters(({MOB"marion_cleric"}),({1}));
			set_monsters(({MOB"marion_cavalier"}),({1}));
			break;
			case 56..59:
			set_monsters(({MOB"marion_thief"}),({1}));
			set_monsters(({MOB"marion_cleric"}),({1}));
			break;	 }
        }
        return;
}

void reset() 
	{ ::reset(); 
		FLAG=0; 
		make_creatures();
		return; 
	}