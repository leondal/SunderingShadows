#include <std.h>
#include "../theater.h"
inherit DROOM;
int DFLAG;
int SFLAG;
	void create(){
   	::create();
      set_name("%^RED%^Desert Sun Theater - Maestro's Dressing Room");
   	set_short("%^RED%^Desert Sun Theater - Maestro's Dressing Room");
   	set_long("%^BOLD%^%^CYAN%^The sky blue walls add to the "+
		"spacious feeling of this dressing room.  Unlike the common"+
		" dressing rooms, this one seems to have been crafted for the"+
		" use of only one person.  A %^WHITE%^large table%^CYAN%^ rests"+
		" against the northern wall to make use of the large mirror that"+
		" dominates the wall.  Orbs of light in glass sconces frame the"+
		" mirror, bathing it in plenty of light.  A large %^YELLOW%^pine"+
		" %^CYAN%^wardrobe rests on the eastern end of the room, serving "+
		"as a home for costumes, props, and accessories.  The plaster walls"+
		" of the dressing room have been painted with a %^RESET%^%^BLUE%^"+
		"diamond%^BOLD%^%^CYAN%^ pattern, adding a lavish touch to this "+
		"dressing room.  A %^BLUE%^pat%^GREEN%^te%^CYAN%^rn%^BLUE%^ed"+
		"%^CYAN%^ rug covers the majority of the stone floor.  The "+
		"western wall is arranged into a seating area with a %^RESET%^"+
		"%^BLUE%^velvet couch%^BOLD%^%^CYAN%^ and a pair of%^GREEN%^ "+
		"chairs%^CYAN%^, with a short table in the middle of the grouping."+
		"%^WHITE%^  Silver leaf%^CYAN%^ crown molding joins the walls to the"+
		" darker blue ceiling. Silk sky blue curtains with a "+
		"%^WHITE%^silver%^CYAN%^ starburst pattern offers privacy to "+
		"this dressing room. \n");
   	set_smell("default","%^RED%^A faint spicy masculine scent lingers in the air.");
   	set_listen("default","%^YELLOW%^There is a creepy stillness in here.");
  	set_items(([
      	({"tables","mirror","table","sconces"}) : "%^BOLD%^%^CYAN%^Almost"+
	" all of the northern wall is covered with a %^WHITE%^large mirror%^CYAN%^"+
	", offering a full view of the body.  The mirror also serves to create "+
	"the illusion that the dressing room is bigger than it truly is, by "+
	"reflecting the light.  A %^WHITE%^whitewashed%^CYAN%^ large table "+
	"rests against the mirror, housing higher quality creams, salves, and"+
	" paints that an actor would apply to his face.  A matching pair of bone"+
	" and silver comb and brush set rest on the tabletop.  Laying on the floor"+
	" near the table is a%^BLUE%^ blue %^CYAN%^and %^WHITE%^silver%^CYAN%^"+
	" brocade stool.  Clear frosted glass sconces, carved in a starburst shape"+
	", frame the mirror and bathe the room in pure %^WHITE%^white%^CYAN%^ light.",
      	({"wardrobe","pine wardrobe"}) : "%^BOLD%^%^BLUE%^This large "+
	"%^YELLOW%^pine%^BLUE%^ wardrobe features detailed carvings of The "+
	"Muses of Performing Arts.  %^WHITE%^Silver%^BLUE%^ and %^YELLOW%^gold"+
	"%^BLUE%^ leafing has been brushed across the wardrobe, highlighting"+
	" the intricate patterned borders.  A seam runs down the center of "+
	"the dresser, revealing that it can be opened.",
		({"wall","walls","molding","ceiling"}) : "%^BLUE%^A dark blue "+
	"diamond pattern has been painted over the %^BOLD%^%^CYAN%^sky blue"+
	"%^RESET%^%^BLUE%^ walls, creating a masculine feeling to the room.  "+
	"%^BOLD%^%^WHITE%^Silver leaf %^RESET%^%^BLUE%^crown molding in the"+
	" shape of billowing clouds joins the patterned wall with the "+
	"%^BOLD%^%^CYAN%^sky blue%^RESET%^%^BLUE%^ ceiling.",
		({"sky blue curtain","sky blue curtains","blue curtain""+
	","blue curtains"}) : "%^BOLD%^%^CYAN%^These tightly woven sky blue "+
	"silk curtains covers the southern entrance.  Woven into the "+
	"silk fibers is a large %^WHITE%^silver%^CYAN%^ starburst design"+
	".  The colors of the curtain are faded in some section, from"+
	" time.  The two curtains meet in the middle, allowing for one to part"+
	" them as they enter and leave.",
		({"couch","sofa","chairs"}) : "%^CYAN%^The plush %^BLUE%^dark blue"+
	" velvet%^CYAN%^ couch rests against the western wall of the dressing room"+
	".  A pair of %^GREEN%^green linen%^CYAN%^ high backed chairs  rest to the"+
	" left and right of couch, creating a comfortable seating area.  A short "+
	"%^RESET%^granite%^CYAN%^ top table has been placed in the middle of the "+
	"couch and chairs.  An empty glass pitcher and glasses rests on the surface"+
	" of the table. One of the cushions of the sofa seems to be off centered and"+
	" resting higher than the other.",
		({"rug","floor"}) : "%^CYAN%^A tightly woven wool rug "+
	"nearly covers all of the stone floor.  The patterned rug has been woven"+
	" with a %^GREEN%^vine%^CYAN%^ border.  In the center of the rug images"+
	" of %^BOLD%^c%^BLUE%^o%^MAGENTA%^l%^GREEN%^o%^YELLOW%^r%^WHITE%^f%^BLUE%^"+
	"u%^CYAN%^l%^RESET%^%^CYAN%^ birds and %^BOLD%^sylphs%^RESET%^%^CYAN%^ "+
	"frolic in a clear blue sky.  Shards of glass and the crushed dried petals"+
	" of flowers scatter across the surface of the wool rug.  Water stains from"+
	" the remains of the vases have stained and damaged the once expensive rug.",]));
	set_exits(([ "south" : ROOMDIR"under3",
	]));
        set_search("default","%^CYAN%^The dresser looks interesting.");
	set_search("dresser",(:TO,"search_dresser":));
	set_search("wardrobe",(:TO,"search_dresser":));
	set_search("couch",(:TO,"search_couch":));
	set_search("sofa",(:TO,"search_couch":));
	DFLAG=0;
	SFLAG=0;
}
void search_dresser(){
	if(DFLAG) { 
		tell_object(TP,"%^CYAN%^The dresser looks as if"+
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
	DFLAG=1;
	return ;
	}else{
		switch(random(8)){
default :
	tell_object(TP,"%^YELLOW%^You search through the dresser"+
		" and find part of a script.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the dresser and discovers something.",TP);
			new(OBJ"script3")->move(TO);
break;
case 5..6:
	tell_object(TP,"%^YELLOW%^The dresser comes alive and "+
		"tries to bite you!");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" jumps back in suprise"+
		" as the dresser comes alive!",TP);
			new(MOB"mimic")->move(TO);
break;
case 7:
	tell_object(TP,"%^BOLD%^%^CYAN%^You search through the dresser"+
		" and find a shirt folded up inside.");
	tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" searches through "+
		"the dresser and discovers something.",TP);
			new(OBJ"menshirt")->move(TO);
break;
case 8:
	tell_object(TP,"%^BOLD%^%^CYAN%^You search through the dresser"+
		" and find something.");
	tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" searches through "+
		"the dresser and discovers something.",TP);
			new(OBJ"r_shoes")->move(TO);
break;
		}
		DFLAG=1;
		return;
	}
}
void search_couch(){
	if(SFLAG) { 
		tell_object(TP,"%^CYAN%^The sofa looks as if"+
			" it has already been searched.");
 	return; 
	}
	if(random(3)){
		tell_object(TP,"%^CYAN%^You search through the sofa"+
			" and find nothing of interest.");
		tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches through "+
    			"the sofa.",TP);
	SFLAG=1;
	return ;
	}else{
		switch(random(10)){
default:
	tell_object(TP,"%^BLUE%^You search through the sofa"+
		" and find something.");
	tell_room(ETP,"%^BLUE%^"+TPQCN+" searches through "+
    		"the sofa and discovers something.",TP);
			"/d/common/daemon/randtreasure_d"->find_stuff(TO,"random");
break;
case 9..10:
	tell_object(TP,"%^BLUE%^The couch comes alive and "+
		"tries to bite you!");
	tell_room(ETP,"%^BLUE%^"+TPQCN+" jumps back in suprise"+
		" as the sofa comes alive!",TP);
			new(MOB"mimic")->move(TO);
break;
		}
		SFLAG=1;
		return;
	}
}
void reset() 
	{ ::reset(); 
		DFLAG=0;
		SFLAG=0; 
	return; 
	}
