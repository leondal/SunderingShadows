#include <std.h>
#include "../theater.h"
inherit DROOM;
int FLAG;
	void create(){
   	::create();
      set_name("%^RED%^Desert Sun Theater - Women's Dressing Room");
   	set_short("%^RED%^Desert Sun Theater - Women's Dressing Room");
   	set_long("%^BOLD%^%^MAGENTA%^With the rose paint on the "+
		"walls this small room seems cheerful.  Several small "+
		"tables are flush against the southern wall, utilizing the"+
		"%^BOLD%^%^WHITE%^ mirrors%^MAGENTA%^ on the wall."+
		"  Set up on the western end of the room is a wooden clothing"+
		" rack.  Most of the costumes litter the floor of the room, "+
		"though a few still hang on the rack.   A worn "+
		"%^RESET%^%^ORANGE%^oak wood%^BOLD%^%^MAGENTA%^ dresser "+
		"dominates the eastern "+
		"wall.  Near the entrance a simple %^RED%^terra cotta%^MAGENTA%^"+
		" pottery jug and small cups reside on a %^WHITE%^poplar"+
		" wood%^MAGENTA%^ table.  %^YELLOW%^Sunny yellow%^MAGENTA%^"+
		" wool curtains hangs over the northern opening.  \n");
   	set_smell("default","%^RED%^A musty floral scent lingers in the air.");
   	set_listen("default","%^YELLOW%^There is a creepy stillness in here.");
  	set_items(([
      	({"tables","mirror","table","mirrors"}) : "%^YELLOW%^Small"+
	" wooden tables"+
	" and stools make use of the %^WHITE%^mirrors%^YELLOW%^ on the wall."+
	"  The tables are laid out with jars of creams and salves that actresses"+
	" use to paint their faces.  Cheap costume jewelry made from brass, "+
	"iron, and copper rest on some tables; accessories no doubt to some "+
	"elaborate costumes.  Brushes and combs in a variety of materials are"+
	" laid out on the tables.  On each table there is a short golden tone "+
	"lamp, to provide the actresses with plenty of light.",
      	({"rack","costumes","costume"}) : "%^MAGENTA%^Dominating the "+
	"western wall, this massive rack looks as if it could hold over fifty"+
	" costumes at once. Color coded wooden blocks serve as dividers, to "+
	"separate an actress' costumes from others.  Most of the costumes now"+
	" lay on the stone floor.  The elaborate patterns and mixture of "+
	"fabrics reduced to tattered, torn, or rotting cloth.",
		({"poplar table","jug","cups","table 2"}) : "%^BOLD%^%^WHITE%^The short"+
	" solid poplar table is set with a large %^RED%^terra cotta%^WHITE%^ pottery"+
	" jug and ceramic cups.  A small sunburst design is embossed on the jug"+
	" and each cup, identifying it as property of The Desert Sun Theater.  "+
	"Perhaps at one time the jug use to house water to refresh the actress''s "+
	"throats before rushing back on stage.  Now though dust is the only "+
	"thing within the jug.",
		({"yellow curtain","yellow curtains","sunny yellow curtains""+
	","sunny yellow curtains"}) : "%^YELLOW%^These tightly woven sunny yellow"+
	" curtains covers the southern entrance.  Woven into the wool fibers is "+
	"a large %^RED%^fiery red%^YELLOW%^ sunburst design.  The colors of the"+
	" curtain are faded in some sections, from time.  The two curtains meet"+
	" in the middle, allowing for one to push them aside as they enter "+
	"and leave.",
		({"door","dresser door"}) : "The wooden door of the dresser "+
	"looks as if at once it had a lock, though that has been removed."+
	"  A simple iron ring has been afixed to the door.",
		({"dresser","oak dresser"}) : "%^ORANGE%^The large"+
	" oak wood dresser serves as a home for the props and accessories an "+
	"actress might need to play her part.  Blunt daggers and swords are "+
	"carelessly tossed on the top of the dresser, mixing with the "+
	"glass gems, costume jewelry, and rotting undergarments.  The "+
	"worn dresser"+
	" looks like a cast off from someone's home.  There is a central"+
	" door on the dresser that might open.",]));
	set_exits(([ "north" : ROOMDIR"under2",
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
default:
	tell_object(TP,"%^YELLOW%^You search through the dresser"+
		" and find part of a script.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the dresser and discovers something.",TP);
			new(OBJ"script1")->move(TO);
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
