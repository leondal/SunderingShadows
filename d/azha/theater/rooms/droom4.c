#include <std.h>
#include "../theater.h"
inherit DROOM;
int DFLAG;
int SFLAG;
	void create(){
   	::create();
      set_name("%^RED%^Desert Sun Theater - Diva's Dressing Room");
   	set_short("%^RED%^Desert Sun Theater - Diva's Dressing Room");
   	set_long("%^MAGENTA%^The lavender walls add to the spacious"+
		" feeling of this dressing room.  Unlike the common dressing"+
		" rooms, this one seems to have been crafted for the use of"+
		" only one person.  A %^WHITE%^large table%^MAGENTA%^ rests"+
		" against the southern wall to make use of the large mirror "+
		"that dominates the wall.  Orbs of light in glass sconces "+
		"frame the mirror, bathing it in plenty of light.  A large "+
		"%^YELLOW%^cypress %^RESET%^%^MAGENTA%^wardrobe rests on the"+
		" eastern end of the room, serving as a home for costumes, "+
		"props, and accessories.  The plaster walls of the dressing"+
		" room have been painted with a %^BOLD%^f%^BLUE%^l%^GREEN%^o"+
		"%^MAGENTA%^r%^BLUE%^a%^CYAN%^l%^RESET%^%^MAGENTA%^ mural, "+
		"adding a lavish touch to this dressing room.  A %^BLUE%^p"+
		"%^BOLD%^a%^MAGENTA%^tt%^CYAN%^er%^BLUE%^n%^MAGENTA%^ed"+
		"%^RESET%^%^MAGENTA%^ rug covers the majority of the stone "+
		"floor.  The western wall is arranged into a seating area "+
		"with a %^BOLD%^%^BLUE%^velvet couch%^RESET%^%^MAGENTA%^ and"+
		" a pair of%^BOLD%^%^MAGENTA%^ chairs%^RESET%^%^MAGENTA%^%^, "+
		"with a short table in the middle of the grouping. %^BOLD%^"+
		"%^WHITE%^Silver\n"+
		" leaf%^RESET%^%^MAGENTA%^ crown molding joins the walls to the darker violet"+
		" ceiling.  Silk lavender curtains with a "+
		"%^BOLD%^%^WHITE%^silver%^RESET%^%^MAGENTA%^ starburst pattern"+
		" offers privacy to this dressing room. \n");
   	set_smell("default","%^RED%^A faint floral scent lingers in the air.");
   	set_listen("default","%^YELLOW%^There is a creepy stillness in here.");
  	set_items(([
      	({"tables","mirror","table","sconces"}) : "%^MAGENTA%^Almost all"+
	" of the southern wall is covered with a %^BOLD%^%^WHITE%^large mirror"+
	"%^RESET%^%^MAGENTA%^, offering a full view of the body.  The mirror "+
	"also serves to create the illusion that the dressing room is bigger"+
	" than it truly is, buy reflecting the light.  A %^WHITE%^limewaxed"+
	"%^MAGENTA%^ large table rests against the mirror, housing higher "+
	"quality creams, salves, and paints that an actress would apply to his"+
	" face.  A matching pair of gold and silver comb and brush set rest "+
	"on the tabletop.  Laying on the floor near the table is a %^BOLD%^"+
	"%^WHITE%^bu%^MAGENTA%^tt%^YELLOW%^er%^WHITE%^f%^MAGENTA%^l"+
	"%^YELLOW%^y%^RESET%^%^MAGENTA%^ pattern brocade stool.  Clear "+
	"frosted glass sconces, carved in a starburst shape, frame the mirror"+
	" and bathe the room in pure %^BOLD%^%^WHITE%^white%^RESET%^%^MAGENTA%^"+
	" light.",
      	({"wall","walls","molding","ceiling","mural"}) : "%^MAGENTA%^The"+
	" light lavender"+
	" walls have been painted with a mural along the lower edges.  The mural"+
	" depicts a rolling meadow of %^BOLD%^wi%^BLUE%^ld%^CYAN%^fl%^GREEN%^o"+
	"%^CYAN%^w%^BLUE%^e%^MAGENTA%^rs%^RESET%^%^MAGENTA%^ and %^BOLD%^"+
	"%^WHITE%^bu%^YELLOW%^tt%^MAGENTA%^er%^BLUE%^fl%^WHITE%^ie%^YELLOW%^"+
	"s%^RESET%^%^MAGENTA%^, giving a feminine tranquil feeling to this"+
	" dressing room. %^BOLD%^%^WHITE%^Silver leaf%^RESET%^%^MAGENTA%^"+
	" crown molding carved to look like butterflies in flight join"+
	" the walls and ceiling.",
		({"wardrobe","pine wardrobe"}) : "%^BOLD%^%^BLUE%^This large"+
	" %^YELLOW%^cypress%^BLUE%^ wardrobe features detailed carvings of "+
	"butterflies.  %^WHITE%^Silver%^BLUE%^ and %^YELLOW%^gold%^BLUE%^"+
	" leafing has been brushed across the wardrobe, highlighting the"+
	" intricate patterned borders.  A seam runs down the center of the"+
	" dresser, revealing that it can be opened.",
		({"lavender curtain","lavender curtains"}) : "%^MAGENTA%^These"+
	" tightly woven lavender silk"+
	" curtains covers the southern entrance.  Woven into the silk fibers is "+
	"a large %^BOLD%^%^WHITE%^silver%^RESET%^%^MAGENTA%^ starburst design.  "+
	"The colors of the"+
	" curtain are faded in some sections, from time.  The two curtains meet"+
	" in the middle, allowing for one to push them aside as they enter "+
	"and leave.",
		({"couch","sofa","chairs"}) : "%^MAGENTA%^The plush %^BOLD%^"+
	"%^BLUE%^light blue velvet%^RESET%^%^MAGENTA%^ couch rests against"+
	" the western wall of the dressing room.  A pair of %^BOLD%^pink silk"+
	"%^RESET%^%^MAGENTA%^ low backed chairs  rest to the left and right of"+
	" couch, creating a comfortable seating area.  A short %^RESET%^marble"+
	"%^MAGENTA%^ top table has been placed in the middle of the couch and "+
	"chairs.  An empty glass pitcher and glasses rests on the surface of "+
	"the table. One of the cushions of the sofa seems to be off centered "+
	"and resting higher than the other.",
		({"rug","floor"}) : "%^CYAN%^A tightly woven wool rug nearly "+
	"covers all of the stone floor.  The patterned rug has been woven "+
	"with a %^MAGENTA%^flowering %^GREEN%^vine%^CYAN%^ border.  "+
	"In the center of "+
	"the rug images of %^BOLD%^%^WHITE%^bu%^MAGENTA%^tt%^YELLOW%^er"+
	"%^WHITE%^f%^MAGENTA%^l%^YELLOW%^i%^MAGENTA%^es%^RESET%^%^CYAN%^ "+
	"frolic in a %^BLUE%^clear blue%^CYAN%^ sky.  Shards of glass and"+
	" the crushed dried "+
	"petals of flowers scatter across the surface of the wool rug.  "+
	"Water stains from the remains of the vases have stained and damaged"+
	" the once expensive rug.",
	]));
	set_exits(([ "north" : ROOMDIR"under3",
	]));
	set_search("default","%^CYAN%^The dresser looks interesting.");
	set_search("dresser",(:TO,"search_dresser":));
	set_search("wardrobe",(:TO,"search_dresser":));
	set_search("couch",(:TO,"search_couch":));
	set_search("sofa",(:TO,"search_couch":));
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
		" and find a dress folded up inside.");
	tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" searches through "+
		"the dresser and discovers something.",TP);
			new(OBJ"womendress")->move(TO);
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
case 1..8 :
	tell_object(TP,"%^BLUE%^You search through the sofa"+
		" and find something.");
	tell_room(ETP,"%^BLUE%^"+TPQCN+" searches through "+
    		"the sofa and discovers something.",TP);
			"/d/common/daemon/randtreasure_d"->find_stuff(TO,"random");
	break;
default:
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
		if(!present("bard")) 
		{
			new(MOB"marion_bard")->move(TO) ;
    		return;
		}
		return; 
}