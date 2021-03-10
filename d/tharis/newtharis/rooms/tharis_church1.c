#include <std.h>
#include "../tharis.h"
inherit "/std/church";

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Church Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		set_property("no sticks", 1);
		set_property("light",2);
		set_property("indoors",1);
		
		set_name("Tharis Cathedral");
        set_short("%^YELLOW%^Tharis Cathedral%^RESET%^");
        set_long("%^YELLOW%^Tharis Cathedral%^RESET%^\n"+
			"%^BOLD%^%^WHITE%^The Cathedral of Tharis is a "+
			"grandiose structure of immense proportions. Thick "+
			"%^RESET%^%^ORANGE%^timbers%^BOLD%^%^WHITE%^, harvested "+
			"from the Tharis Forest lift to a %^YELLOW%^gold "+
			"trimmed%^WHITE%^, vaulted ceiling complete with "+
			"%^CYAN%^angelic effigies %^WHITE%^staring down in "+
			"endless judgement. Towering statues of each of the "+
			"pantheon's gods stand %^RESET%^%^MAGENTA%^regally "+
			"%^BOLD%^%^WHITE%^within the thirty or so alcoves that "+
			"line either side of the church. Before each, kneeling "+
			"with their hands cast upward in praise and offering, "+
			"are life sized statues of men and women. Each of which "+
			"is garbed in the finest of %^CYAN%^cloth%^WHITE%^, "+
			"%^RESET%^%^MAGENTA%^jewels %^WHITE%^%^BOLD%^and "+
			"%^YELLOW%^metalwork%^WHITE%^. Wealthy petitioners to "+
			"the watching gods. Between these alcoves thick "+
			"%^RESET%^%^ORANGE%^wood pews%^BOLD%^%^WHITE%^, "+
			"gilded in fine carvings and accented with %^YELLOW%^"+
			"gold%^WHITE%^, silver and %^CYAN%^platinum%^WHITE%^, "+
			"can be found. Over a hundred of them total, they form "+
			"two lines that flow down to the raised %^RESET%^"+
			"%^ORANGE%^platform %^BOLD%^%^WHITE%^where the "+
			"%^CYAN%^glass podium %^WHITE%^stands, waiting to "+
			"display the preacher who has come to give service. "+
			"Behind this otherwise simple platform is the most "+
			"startling and beautiful feature of the whole "+
			"cathedral. Floor to ceiling, wall to wall, the "+
			"%^RESET%^%^MAGENTA%^s%^BOLD%^%^CYAN%^t%^WHITE%^a"+
			"%^YELLOW%^i%^WHITE%^n%^CYAN%^e%^RESET%^%^MAGENTA%^d "+
			"%^WHITE%^%^BOLD%^glass shimmers with %^YELLOW%^sun "+
			"%^WHITE%^and %^CYAN%^moonlight %^WHITE%^both, "+
			"displaying the artist's rendition of the metropolis "+
			"that is Tharis.%^RESET%^");
		
		set_smell("default","Sweet incense tickles you nose.");
		set_listen("default","A low murmur of prayer echoes "+
			"through the chamber.");
		
        set_items(([
			({"timbers","ceiling"}):"%^BOLD%^%^WHITE%^The high "+
				"vaulted ceiling is painted brilliant white and "+
				"accented with %^CYAN%^precious metals%^WHITE%^, "+
				"of which %^YELLOW%^gold %^WHITE%^seems most used. "+
				"The bare %^RESET%^%^ORANGE%^timbers %^BOLD%^"+
				"%^WHITE%^of the supports add a deep, rich "+
				"contrast with their polished oak and pine "+
				"surfaces.  Set between these timbers, looking "+
				"down at the congregation, %^CYAN%^angelic "+
				"effigies %^WHITE%^watch.  Beautiful, androgynous "+
				"forms with wide swept wings and flowing robes, "+
				"each angel is unique in its detail and purpose."+
				"%^RESET%^",
			({"angels","effigies","angelic effigies"}):"%^BOLD%^"+
				"%^WHITE%^These beautiful, androgynous figures "+
				"keep a watchful eye upon the congregation.  Each "+
				"carved with such detail that it is hard not to "+
				"imagine them coming to life at any moment.  Wide "+
				"swept wings reach outward, touching the beams "+
				"that create the ceiling, while flowing robes "+
				"cover their bodies in tempered modesty.  Known "+
				"as the eight judgements, their eyes appear to "+
				"follow each person that enters the Cathedral, "+
				"looking deep within them and judging the "+
				"petitioner's inner qualities.%^RESET%^",
			({"men","women","statues","gods","alcoves"}):"%^BOLD%^"+
				"%^WHITE%^Lining either side of the grand "+
				"Cathedral are over thirty recessed alcoves.  "+
				"Within these, story-tall statues of the many "+
				"gods of %^BLACK%^Shadowgate %^WHITE%^can be "+
				"found.  From %^YELLOW%^benign %^WHITE%^to "+
				"%^RESET%^%^MAGENTA%^sinister%^BOLD%^%^WHITE%^, "+
				"it would appear that each and every god is "+
				"represented.  Carved of suitable material to "+
				"the represented faith and surrounded by "+
				"decorations that are central to the god's "+
				"teachings, each alcove is like a mini-church "+
				"unto itself, where faithful can %^CYAN%^worship "+
				"%^WHITE%^or leave %^YELLOW%^offerings %^WHITE%^"+
				"for the gods they seek favor from.  Positioned "+
				"to either side of the alcoves are human figures, "+
				"statues cast in kneeling supplication, one male "+
				"and one female for each and every alcove.  "+
				"Dressed in the finest of %^RESET%^%^MAGENTA%^"+
				"garments%^BOLD%^%^WHITE%^, these kneeling figures "+
				"hold up %^YELLOW%^precious offerings %^WHITE%^in "+
				"their up raised hands.  Like the gods and the "+
				"alcoves themselves, no two of the petitioner "+
				"statues are the same.  A few of the apparently "+
				"unused alcoves have been draped in %^BOLD%^"+
				"%^BLACK%^dark curtains %^WHITE%^almost as though "+
				"it is expected other gods will turn up at some "+
				"point, or as markers for those gods that have "+
				"fallen.%^RESET%^",
			({"curtains"}):"%^BOLD%^%^BLACK%^Heavy velvet curtains "+
				"have been hung across a few of the rear alcoves, "+
				"hiding the presumably empty spaces behind them. "+
				"Why extra alcoves were creates is a mystery, "+
				"unless they were intended as markers for the "+
				"fallen gods, or as anticipation for when new "+
				"gods reveal themselves to the world.  Regardless "+
				"there is probably nothing behind them worth "+
				"seeing.",
			({"pews","wooden pews","wood pews","carvings"}):""+
				"%^RESET%^%^ORANGE%^Richly grained woods, polished "+
				"to a mirror bright shine, have been used to "+
				"create the many pews that line the cathedral's "+
				"two seating columns.  Each bench is intricately "+
				"%^BOLD%^%^BLACK%^carved %^RESET%^%^ORANGE%^along "+
				"the back and sides, in %^BOLD%^%^CYAN%^celestial "+
				"motifs %^RESET%^%^ORANGE%^that span the range of "+
				"divine interests.  The seating itself is smooth "+
				"and, while not exactly comfortable, is polished "+
				"and lacquered enough to prevent snags in clothing "+
				"as well as endure the high traffic that such "+
				"seating arrangements sustain.%^RESET%^",
			({"glass podium","podium"}):"%^BOLD%^%^CYAN%^Created "+
				"to appear as though it were grown from the earth "+
				"fully formed, this extraordinary glass podium is "+
				"a work of art in and of itself, though its "+
				"simple beauty is lost amongst the overwhelming "+
				"gaudiness of the entire cathedral.  Swirls of "+
				"%^BLUE%^blue%^CYAN%^, %^GREEN%^emerald%^CYAN%^ "+
				"and %^WHITE%^silver%^CYAN%^ create delicate "+
				"whorls within the sky blue glass, giving the "+
				"speaker the appearance of standing in the sky "+
				"and looking down at the congregation.%^RESET%^",
			({"platform","stage"}):"%^RESET%^%^ORANGE%^Constructed "+
				"from the same rich grained woods as the pews, "+
				"this simple platform's function appears to be to "+
				"raise the glass podium up above the congregation. "+
				"Three stairs lead up to the top of the platform, "+
				"with another two that curve to the side where "+
				"the podium is located on the left side of the "+
				"stage.  To the right, the area is clear, leaving "+
				"room for choirs to gather or for ceremonies to "+
				"be performed.%^RESET%^",
			({"stained glass","window"}):"%^BOLD%^%^WHITE%^Awe "+
				"inspiring, the image, captured in %^RESET%^"+
				"%^MAGENTA%^c%^BOLD%^%^CYAN%^o%^WHITE%^l%^YELLOW%^"+
				"o%^WHITE%^r%^CYAN%^e%^RESET%^%^MAGENTA%^d "+
				"%^WHITE%^%^BOLD%^glass and led, is the most eye "+
				"catching piece of the entire cathedral. Designed "+
				"to give the appearance of looking out over the "+
				"%^YELLOW%^Grand City of Tharis%^WHITE%^, and in "+
				"general the merchant district with its bustling "+
				"streets that lead toward the Upper Quarter, the "+
				"perspective is such that one feels almost as if "+
				"they have been raised on %^CYAN%^high %^WHITE%^"+
				"and now look down upon the %^CYAN%^glittering "+
				"streets %^WHITE%^and %^YELLOW%^wealth %^WHITE%^"+
				"of a city reborn.  Though not immediately "+
				"obvious on first glance, closer inspection shows "+
				"that a second sheet of clear glass has been set "+
				"on either side of the image, protecting it from "+
				"the elements or mishaps.%^RESET%^\n\n",
		]));
        
		set_exits(([
                "west":ROOMS"north5",
        ]));

		set_search("default","%^BOLD%^%^BLACK%^What did you want to search?%^RESET%^");
		set_search("curtain",(:TO,"search_alcove":));
		set_search("alcove",(:TO,"search_alcove":));		
		set_search("curtains",(:TO,"search_alcove":));		
}

int search_alcove(string str){
	object ob;
	if(str == "alcove" || str == "curtain" || str == "curtains"){
		tell_object(TP,"%^BOLD%^%^BLACK%^You pull aside one "+
			"of the dark curtains that drapes an empty alcove "+
			"and find a set of stairs leading down into the "+
			"basement.%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" steps up to "+
			"one of the empty alcoves and pulls the dark drapes "+
			"aside, revealing a stairwell leading down."+
			"%^RESET%^",TP);
		add_exit(ROOMS"tharis_church2","stairs");
		return 1;
	}
}

void reset(){
	::reset();
   if(member_array("stairs",TO->query_exits()) != -1) {
     tell_room(TO,"%^RESET%^%^RED%^The curtains fall back into place, hiding the stairway from view.%^RESET%^");
     remove_exit("stairs");
   }
	switch(random(8)){
		case 0:
			tell_room(TO,"%^BOLD%^%^WHITE%^Several petitioners "+
				"enter the cathedral and take their seats amongst "+
				"the pews.%^RESET%^");
		break;
		case 1:
			tell_room(TO,"%^BOLD%^%^BLACK%^An elderly man pauses "+
				"before one of the alcoves and makes an offering "+
				"to the god within.%^RESET%^");
		break;
		case 2:
			tell_room(TO,"%^BOLD%^%^GREEN%^Two young children "+
				"giggle softly as they point at one of the angels "+
				"above.  They're quickly quieted by their parents "+
				"and ushered off to their seats.%^RESET%^");
		break;
		case 3:
			tell_room(TO,"%^BOLD%^%^BLUE%^A middle aged woman "+
				"stands near the podium and gazes at the amazing "+
				"%^RESET%^%^MAGENTA%^s%^BOLD%^%^CYAN%^t%^WHITE%^a"+
				"%^YELLOW%^i%^WHITE%^n%^CYAN%^e%^RESET%^"+
				"%^MAGENTA%^d %^BOLD%^%^BLUE%^glass window "+
				"beyond.%^RESET%^");
		break;
		case 4:
			tell_room(TO,"%^BOLD%^%^RED%^A pair of priests speak "+
				"quietly with some of the cathedral's visitors "+
				"off to one side.%^RESET%^");
		break;
		case 5:
			tell_room(TO,"%^YELLOW%^Rays of light filter through "+
				"the stain glass window, illuminating the stage "+
				"and casting dancing shadows of glittering color "+
				"across most of the cathedral's interior.%^RESET%^");
		break;
		case 6:
			tell_room(TO,"%^RESET%^%^MAGENTA%^A group of "+
				"caretakers polishes the pews and dusts the "+
				"alcoves.%^RESET%^");
		break;
		case 7:
			tell_room(TO,"%^RESET%^%^ORANGE%^A wealthy merchant "+
				"heads to a selected pew, almost as though he "+
				"believes he owns it.");
		break;
	return 1;
	}
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}