#include <std.h>
#include "../theater.h"
inherit CROOM;
int FLAG;
	void make_creatures();
	void create(){
	make_creatures();
	set_repop(55);
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun Theater - Props Storage");
   	set_short("%^RED%^Desert Sun Theater - Props Storage");
   	set_long("%^ORANGE%^This large crowded room is filled "+
		"with numerous objects. This space seems as if it served"+
		" as storage for props from former productions.  A narrow"+
		" path offers access into the storage room.  Large%^YELLOW%^"+
		" crates%^RESET%^%^ORANGE%^ are stacked on top of each other,"+
		" reaching clear to the ceiling.  Wooden bookshelves, benches,"+
		" and tables are propped against the crates.  Numerous chairs,"+
		" end tables, and even frames and mattresses for beds are stored"+
		" here.  Stacks of paintings rest against one crate.  A large sofa"+
		" rests partially in the pathway, protected from dust with a"+
		"%^RESET%^ white%^ORANGE%^ cloth.  Chandeliers and lamps hang from"+
		" a ceiling beam.  You can't help but feel stifled and confined"+
		" within this crowded room. \n");
	set_smell("default","%^BOLD%^%^RED%^The air is thick with an old dusty scent.");
   	set_listen("default","%^YELLOW%^There is a creepy stillness down here.");
  	set_items(([
      	({"crates"}) : "%^YELLOW%^Numerous wooden crates have been "+
	"nailed shut and stacked on top of each other on the outer edges of"+
	" this room.  The crates are marked with a colored stripe, seeming "+
	"to suggest some kind of inventory system.",
      	({"bookcases","tables","benches"}) : "%^ORANGE%^You can make "+
	"out at least four different style bookshelves, seven benches and nine"+
	" tables housed in here.  The furniture is pressed up against the wooden"+
	" crates, in an attempt to maximize the storage potential of this room."+
	"  Some of the furniture still retains the natural color of the wood, "+
	"while some have been painted.  Intermixed with these furniture pieces"+
	" are rolled up cylinders of rugs, tied shut with twine.  It is "+
	"impressive how these people were able to pack all these items "+
	"within this space.",
		({"paintings"}) : "%^BOLD%^%^RED%^Three stacks of paintings"+
	" rest side by side.  Each stack runs about as deep as a Halfling is tall."+
	"  Landscape scenes, portraits and still life studies make up the majority"+
	" of the paintings.  Each painting is housed in a wooden frame, each frame"+
	" as different as the paintings are.",
		({"chairs","end tables","frames","mattresses"}) : "%^RED%^Crowded in "+
	"the chaos of this room are numerous chairs.  Some of the chairs seems"+
	" to be a matching set, while others are crafted from various woods "+
	"and covered with a multitude of patterns and fabrics.  End tables made"+
	" to mirror the style of various periods are stacked on top of each "+
	"other.  Wooden frames for beds are bound together with rope, resting"+
	" against where ever there is free space.  Mattresses stuffed with down"+
	" or straw rest up on one stack of crates, keeping them out of the way.",
		({"couch","sofa"}) : "%^ORANGE%^A two cushioned sofa rests "+
	"partially in the middle of the path.  A white sheet covers the "+
	"majority of the sofa.  Though the left side of the cloth has "+
	"been moved, offering a glimpse of the caramel patterned velvet "+
	"fabric.  Strange though that the cover does not protect all of "+
	"this sofa.",
		({"lamp","lamps","chandeliers","chandelier"}) : "%^BOLD%^%^BLUE%^"+
	"Lamps and chandeliers crafted from metal, glass or a combination of "+
	"the two are chained to a support beam up high.  The light fixtures "+
	"are all dim right now, but seem to reflect a variety of cultures and"+
	" periods in their designs.",
	]));
	set_search("default","%^BOLD%^%^CYAN%^The sofa looks interesting.");
	set_search("sofa",(:TO,"search_sofa":));
	set_search("couch",(:TO,"search_sofa":));
	FLAG=0;
	make_creatures();
}
void search_sofa(){
	if(FLAG) { 
		tell_object(TP,"%^ORANGE%^The sofa looks as if its"+
			" already been searched.");
    	return; 
	}
	if(present("theater_mon")){
   		tell_object(TP,"Yeah, right, they won't let you search that.");
   	return 1;
	}
	if(random(4)){
		tell_object(TP,"%^ORANGE%^You search through the cushions"+
			" of the sofa and find some dust.");
		tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
    			"the cushions of the sofa and discovers something.",TP);
	FLAG=1;
	return ;
	}else{
 		switch(random(6)){
case 1..3 :
	tell_object(TP,"%^ORANGE%^You search through the cushions"+
		" and find something hidden in the sofa.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the cushions of the sofa and discovers something.",TP);
			"/d/common/daemon/randtreasure_d"->find_stuff(TO,"random");
break;
case 4..6:
	tell_object(TP,"%^ORANGE%^You pull your hand back before"+
		" the sofa can bite you!");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" yelps as the"+
		"sofa comes alive!",TP);
			new(MOB"mimic")->move(TO);
break;
default:
	tell_object(TP,"%^ORANGE%^You search through the cushions"+
		" of the sofa and find some dust.");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
    		"the cushions of the sofa and discovers something.",TP);
break;
		}
		FLAG=1;
		return;
	}
}
void make_creatures()
{	
	int monsters;
   	monsters = has_mobs();
	if(!monsters) 
	{
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
			set_monsters(({MOB"purplesiren"}),({1}));
			set_monsters(({MOB"marion_thief"}),({1}));
			break;
			case 43..45:
			set_monsters(({MOB"pinksiren"}),({1}));
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
			set_monsters(({MOB"pinksiren"}),({1}));
			set_monsters(({MOB"purplesiren"}),({1}));
			break;break;
			}
	}
	return;
}

void reset() 
	{ ::reset(); 
		FLAG=0; 
		make_creatures();
		return; 
	}
