#include <std.h>
#include "../theater.h"
inherit DROOM;
int FLAG;
	void create(){
   	::create();
      set_name("%^RED%^Desert Sun Theater - Men's Dressing Room");
   	set_short("%^RED%^Desert Sun Theater - Men's Dressing Room");
   	set_long("%^ORANGE%^With the dark sepia brown paint on the "+
		"walls this small room seems even smaller.  Several small "+
		"tables are flush against the northern wall, utilizing the"+
		"%^BOLD%^%^WHITE%^ mirrors%^RESET%^%^ORANGE%^ on the wall."+
		"  Set up on the western end of the room is a wooden clothing"+
		" rack.  Most of the costumes litter the floor of the room, "+
		"though a few still hang on the rack.  A worn and battered "+
		"%^RESET%^teak wood%^ORANGE%^ dresser dominates the eastern "+
		"wall. Near the entrance a simple %^BOLD%^%^BLACK%^pottery jug"+
		"%^RESET%^%^ORANGE%^ and small cups reside on a %^BOLD%^chestnut"+
		" wood%^RESET%^%^ORANGE%^ table.  %^RED%^Dark red%^ORANGE%^ "+
		"wool curtains hangs over the southern opening.  \n");
   	set_smell("default","%^RED%^A musty masculine scent lingers in the air.");
   	set_listen("default","%^YELLOW%^There is a creepy stillness in here.");
  	set_items(([
      	({"tables","mirror","table","mirrors"}) : "%^YELLOW%^Small"+
	" wooden tables"+
	" and stools make use of the %^WHITE%^mirrors%^YELLOW%^ on the wall."+
	"  The tables are laid out with jars of creams and salves that actors"+
	" use to paint their faces.  Cheap costume jewelry made from brass, "+
	"iron, and copper rest on some tables; accessories no doubt to some "+
	"elaborate costumes.  Brushes and combs in a variety of materials are"+
	" laid out on the tables.  On each table there is a short golden tone "+
	"lamp, to provide the actors with plenty of light.",
      	({"rack","costumes","costume"}) : "%^BOLD%^%^BLUE%^Dominating the "+
	"western wall, this massive rack looks as if it could hold over fifty"+
	" costumes at once. Color coded wooden blocks serve as dividers, to "+
	"separate an actor's costumes from others.  Most of the costumes now"+
	" lay on the stone floor.  The elaborate patterns and mixture of "+
	"fabrics reduced to tattered, torn, or rotting cloth.",
		({"chestnut table","jug","cups","table 2"}) : "%^YELLOW%^The short"+
	" solid chestnut table is set with a large %^BLACK%^black pottery%^YELLOW%^"+
	" jug and ceramic cups.  A small sunburst design is embossed on the jug"+
	" and each cup, identifying it as property of The Desert Sun Theater.  "+
	"Perhaps at one time the jug use to house water to refresh the actor's "+
	"throats before rushing back on stage.  Now though dust is the only "+
	"thing within the jug.",
		({"red curtain","red curtains","dark red curtain""+
	","dark red curtains"}) : "%^RED%^These tightly woven dark red "+
	"wool curtains covers the northern entrance.  Woven into the "+
	"wool fibers is a large %^YELLOW%^golden sunburst%^RESET%^%^RED%^"+
	" design.  The colors of the curtain are faded in some section, from"+
	" time.  The two curtains meet in the middle, allowing for one to part"+
	" them as they enter and leave.",
		({"door","dresser door"}) : "The wooden door of the dresser "+
	"looks as if at once it had a lock, though that has been removed."+
	"  A simple iron ring has been afixed to the door.",
		({"dresser","teak dresser"}) : "%^BOLD%^%^WHITE%^The large"+
	" teak wood dresser serves as a home for the props and accessories an "+
	"actor might need to play his part.  Blunt daggers and swords are "+
	"carelessly tossed on the top of the dresser, mixing with the "+
	"glass gems and costume jewelry.  The battered and worn dresser"+
	" looks like a cast off from someone's home.  There is a central"+
	" door on the dresser that might open.",]));
	set_exits(([ "south" : ROOMDIR"under2",
	]));
	set_search("default","%^YELLOW%^The dresser looks interesting.");
	set_search("dresser",(:TO,"search_dresser":));
	set_search("door",(:TO,"search_dresser":));
	FLAG=0;
}
void search_dresser(){
	if(FLAG) { 
		tell_object(TP,"%^YELLOW%^The dresser looks as if"+
			" it has already been searched.");
        return; 
	}
	if(present("theater_mon")){
   		tell_object(TP,"Yeah, right, they won't let you search that.");
   	return 1;
	}
	if(random(3)){
		tell_object(TP,"%^YELLOW%^You search through the dresser"+
                        " and find nothing of interest.");
		tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches through "+
    			"the dresser.",TP);
	FLAG=1;
	return ;
	}else{
		switch(random(6)){
default :
	tell_object(TP,"%^YELLOW%^You search through the dresser"+
		" and find part of a script.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the dresser and discovers something.",TP);
			new(OBJ"script2")->move(TO);
break;
case 5..6:
	tell_object(TP,"%^YELLOW%^The dresser comes alive and "+
		"tries to bite you!");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" jumps back in suprise"+
		" as the dresser comes alive!",TP);
			new(MOB"mimic")->move(TO);
break;
		}
	FLAG=1;
	return;
	}
}
void reset() 
	{ ::reset(); 
		FLAG=0; 
			return; 
	}

