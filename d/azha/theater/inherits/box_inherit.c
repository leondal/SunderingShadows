#include <std.h>
#include "../theater.h"
inherit CROOM;
int SFLAG;
	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun Theater - Box Seat");
   	set_short("%^RED%^Desert Sun Theater - Box Seat");
   	set_long("%^RED%^Overlooking the theater below,"+
		" the box seat offers an unobstructed view of the"+
		" stage.  Curving around the front of the box seat,"+
		" a low wall helps to segregate these seats from the"+
		" general ones.   The interior of the box seat is covered"+
		" with dark crimson velvet drapes, aiding in absorbing any "+
		"sounds.  Intermixed with the velvet drapes are lengths of"+
		" %^YELLOW%^metallic gold %^RESET%^%^RED%^silk, adding a touch"+
		" of excess.  Swags of pleated %^YELLOW%^golden fabric%^RESET%^"+
		"%^RED%^ adorn the front of the box seat.  A plush sofa is centered"+
		" in the box seat, once offering comfortable seating for these patrons."+
		"  Now the sofa has been ripped open, its stuffing littering the floor."+
		"  The%^ORANGE%^ wood parquet%^RED%^ floor is covered with an expensive"+
		" wool rug. Piles of dust and cobwebs fill the corners. \n");  
   	set_smell("default","A stale musty scent fills the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^A bewitching melody floats in the air.");
  	set_items(([
      	({"rug","runner","floor","parquet floor"}) : "%^ORANGE%^Golden wood "+
	"parquet flooring covers the interior of the box seat.  Over the expensive"+
	" floor treatment a wool rug rest.  The wool rug is woven with an intricate"+
	" pattern of curling vines.  Such rugs hail from deep within the Tsvarian "+
	"Empire, and were once viewed as a status symbol  for those that could afford"+
	" the steep prices.",
		({"couch","sofa"}) : "%^RED%^The dark red couch almost seems to blend "+
	"in with the drapes, carrying on the theme of the theater.  The plush couch use"+
	" to be overstuffed, creating a very comfortable seat to watch the performances."+
	"  Now the sofa has been ripped open, the stuffing littering the floor"+
	"  Throw pillows in patterned silks and brocades have been ripped open,"+
	" adding the litter on the floor",
      	({"curtains","drapes"}) : "%^RED%^Dark crimson velvet covers the "+
	"interior of the box seats.  The red curtains are a shade or two darker"+
	" than the rest of the theater, helping to draw attention to those seated"+
	" in the box seats without being too distracting.  Intermixed with the "+
	"dark crimson drapes are lengths of thin diaphones %^YELLOW%^metallic gold"+
	" %^RESET%^%^RED%^silk.  As the light falls on the thin silk, the metallic"+
	" threads seem to shine.  Identical %^YELLOW%^golden silk%^RESET%^%^RED%^ is"+
	" used to create the swags that cover the front of the box seats.",
		({"theater","stage"}) : "%^ORANGE%^From here the "+
	"view is magnificent.  The unobstructed view of the stage allowed the patrons"+
	" to watch the performances without having to look over someone's shoulders or"+
	" head.  The privacy that these box seats granted was well cherished by those "+
	"who leased them.  Though now all you can really make out is the rubble that "+
	"covers the stage, blocking off access to the backstage area."
	]));
  	set_search("default","%^YELLOW%^The debris on floor looks interesting.");
	set_search("floor",(:TO,"search_floor":));
	set_search("debris",(:TO,"search_floor":));
	SFLAG=0;
}
void search_floor(){
	if(SFLAG) { 
		tell_object(TP,"%^ORANGE%^The floor looks as if its"+
			" already been searched");
        	return 0; 
	}
	if(present("theater_mon")){
   		tell_object(TP,"Yeah, right, they won't let you search that.");
   		return 1;
	}
	if(random(4)){
		tell_object(TP,"%^ORANGE%^You search through the debris"+
			" on the floor and find nothing of interest.");
		tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
    			"the debris on the floor.",TP);
		SFLAG=1;
		return 1;
	}else{
	tell_object(TP,"%^ORANGE%^You search through the debris"+
		" on the floor and find something.");
		tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the debris and discovers something.",TP);
			switch(random(10)){
case 1..2:
	"/d/common/daemon/randtreasure_d"->find_stuff(TO,"random");
break;
default:
	new(OBJ"handbill")->move(TO);
break;
case 8..9:
	new("/d/antioch/valley/obj/jewelry.c")->move(TO);
break;
case 10:
	new("/d/shadow/room/meadows/obj/d_earrings.c")->move(TO);
			}
		SFLAG=1;
		return;
			}
	}
void reset() 
	{ ::reset(); 
		SFLAG=0; 
		return; 
	}