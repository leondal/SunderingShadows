#include <std.h>
#include "../theater.h"
inherit CROOM;
int FLAG;
	void make_creatures();
	void create(){
   	::create();
      make_creatures();
      set_repop(55);
   	set_property("indoors",1);
   	set_property("light",0);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun Theater - Costumes Storage");
   	set_short("%^RED%^Desert Sun Theater - Costumes Storage");
   	set_long("%^ORANGE%^Racks and racks of clothing fill this"+
		" space.  The storage room for all the costumes used in The"+
		" Desert Sun's productions are housed here.  Metals"+
		" bars run vertically across the room, dividing the space.  "+
		"Numerous costumes are crammed on each rack, filled with "+
		"dazzling %^RED%^pa%^BOLD%^tt%^YELLOW%^er%^WHITE%^ns%^RESET%^"+
		"%^ORANGE%^, %^RED%^c%^YELLOW%^o%^GREEN%^l%^BLUE%^o%^RESET%^"+
		"%^CYAN%^r%^MAGENTA%^s%^ORANGE%^, and %^BLUE%^f%^CYAN%^a%^RED%^"+
		"b%^WHITE%^r%^BOLD%^%^BLACK%^i%^GREEN%^c%^BLUE%^s%^RESET%^"+
		"%^ORANGE%^.  A "+
		"few of the %^BOLD%^%^BLACK%^metals bars%^RESET%^%^ORANGE%^ "+
		"have began to buckle in the middle from the weight of the "+
		"costumes.  Dim lighting filters through the light covers, in"+
		" an attempt to prevent any color fading to the costumes.  The"+
		" space feels narrow and stifling with all the clothing packed"+
		" in here. \n");
	set_smell("default","%^BOLD%^%^RED%^The pungent aroma hangs in the air.");
   	set_listen("default","%^YELLOW%^There is a creepy stillness down here.");
  	set_items(([
      	({"costumes","clothing"}) : "%^BOLD%^%^WHITE%^A variety "+
	"of costumes fill the racks. The clothing seems to be separated"+
	" between%^BLUE%^ male%^WHITE%^ and %^MAGENTA%^female%^WHITE%^ "+
	"costumes. ",
      	({"male costumes"}) : "%^CYAN%^Costumes to help an actor"+
	" play any role imaginable hang on these metal bars.  Rich "+
	"looking%^MAGENTA%^ tunics%^CYAN%^, %^RED%^cloaks%^CYAN%^, "+
	"and %^BLUE%^robes%^CYAN%^, among other garments, to portray "+
	"a king, prince, or knight reside in one section.  Rough looking"+
	" %^ORANGE%^tunics%^CYAN%^, %^GREEN%^shirts%^CYAN%^ are just the"+
	" start of all the garments that could aid an actor to play a "+
	"peasant.  All types of costumes stand in waiting, from elves, "+
	"to fey creatures, to fearsome and frightening villains and "+
	"monsters. An actor could find anything he needs to play any"+
	" role here.",
		({"female costumes"}) : "%^BOLD%^%^MAGENTA%^Costumes to"+
	" help an actress play any role imaginable hang on these metal"+
	" bars.  Rich looking%^RESET%^%^MAGENTA%^ gowns%^BOLD%^, %^CYAN%^"+
	"cloaks%^MAGENTA%^, and %^YELLOW%^robes%^MAGENTA%^, among other"+
	" garments, to portray a princess or regal queen stand in waiting"+
	".  Coarse looking %^GREEN%^shifts%^MAGENTA%^ and %^CYAN%^dresses"+
	"%^MAGENTA%^ are just the start of all the garments that could "+
	"aid an actress to play a peasant.  The costumes run a wide "+
	"gamete, from faerie gowns, to drow attire, to fearsome and frightening"+
	" villains and monsters.  An actress could find anything she "+
	"need to play any role here.",
		({"bars","metal bars","racks"}) : "%^BOLD%^%^BLACK%^Thick "+
	"iron bars run vertically from one wall to the next.  The pipes "+
	"are filled with costumes.  Some bars are so overstuffed with "+
	"costumes that they buckle in the middle, seeming to snap at any moment.",
		({"lights","light covers"}) : "%^BLUE%^Light covers made "+
	"from tin help to defuse the lighting in here.  The tin covers"+
	" are square shaped and feature a tin punched design of a "+
	"sunburst.  The light is allowed to shine through the holes,"+
	" illuminating the image while protecting the garments from fading.",
	]));
	set_search("default","%^BOLD%^%^CYAN%^The costumes look interesting.");
	set_search("costumes",(:TO,"search_costumes":));
	set_search("clothing",(:TO,"search_costumes":));
	make_creatures();
	FLAG=0;
}
void search_costumes(){
	if(FLAG) { 
		tell_object(TP,"%^RED%^The costumes look as if"+
			" they have already been searched.");
    	return 0; 
	}
	if(present("theater_mon")){
   		tell_object(TP,"Yeah, right, they won't let you search that.");
   	return 1;
	}
	if(random(3)){
		tell_object(TP,"%^RED%^You search through the costumes"+
			" and find some lint.");
		tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    			"the costumes and discovers something.",TP);
	FLAG=1;
	return ;
	}else{
		switch(random(6)){
case 1 :
	tell_object(TP,"%^RED%^You search through the costumes"+
		" and find something hidden in a pocket.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the costumes and discovers something.",TP);
			"/d/common/daemon/randtreasure_d"->find_stuff(TO,"random");
break;
case 2..4:
	tell_object(TP,"%^RED%^You search through the costumes"+
		" and find a dark blue leather cloak....that comes alive!");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the costumes and discovers a dark blue leather cloak"+
		"...that comes alive!",TP);
			new(MOB"cloaker")->move(TO);
break;
case 5:
	tell_object(TP,"%^RED%^You search through the costumes"+
		" and find something hidden in a pocket.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the costumes and discovers something.",TP);
	 		new("/d/tharis/obj/rings/pendant_royal.c")->move(TO);
break;
case 6:
	tell_object(TP,"%^RED%^You search through the costumes"+
		" and find something hidden in a pocket.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the costumes and discovers something.",TP);
	 		new("/d/darkwood/tabor/obj/c_cufflinks.c")->move(TO);
break;
default:
	tell_object(TP,"%^RED%^You search through the costumes"+
		" and find some lint.");
	tell_room(ETP,"%^RED%^"+TPQCN+" searches through "+
    		"the costumes and discovers something.",TP);
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
			break;
 				 }
        }
        return;
}

void reset() { 
	::reset(); 
		FLAG=0; 
		return; 
}	