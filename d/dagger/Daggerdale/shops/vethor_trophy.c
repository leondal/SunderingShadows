// /d/dagger/Daggerdale/shops/vethor_trophy.c

#include <std.h>
#include <daemons.h>

inherit ROOM;

string query_time_of_day();

void create(){
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("light", 2);
        set_property("indoors",1);
        set_property("no teleport",1);
	set_short("%^BOLD%^Trophy room");
   set_long( (:TO,"my_query_long" :) );
	set_smell("default", "You smell cleanliness.");
	set_listen("default", "You can hear your own breathing and some movement to the north.");
	set_items(([
	"carpet":"A dark plush carpet that your feet sink deeply into, padding your footsteps.",
   "west wall":"Perhaps you can read the west wall.",
   "east wall": (:TO,"time_east_wall" :),
	"south wall":"This wall would be simple paneling if it weren't for the rich"+ 
	" stain used to give the wood a deep color befitting the rest of the room.",
	"plaque":"A rectangular plaque with words engraved upon it to read.  "+
	"There are several circular scratches on the marble connecting the corners"+
	" of the plaque.",
	"scratches":"The scratches seem to have been made by the corners of the plaque.",
	({"case", "glass case"}) : "Encased in glass on top of the marble platform"+
	" are a pair of wicked-looking daggers, an onyx ring, a pair of silvery"+
	" gloves, and a silver and onyx earring, all set in dark blue velvet,"+
	" the same color as the carpeting.",
	({"daggers", "screaming daggers", "wicked-looking daggers"}) : "A pair of"+ 
	" horrible daggers with engraved blades.  The detail is magnificent yet"+
	" the scene depicted upon their wicked blades is a gruesome one.  A young"+ 	
	" girl is lying beneath a dead tree, bleeding from numerous wounds in her"+ 	
	" chest.  The blood has pooled around a glowing dagger with its blade"+ 
	" planted in the earth.  These particular daggers were Vethor's prized"+ 	
	" possessions.",
	({"ring", "onyx ring"}) :
@STYX
This is the signet ring of the Shades of Death.  They wear it to show to themselves who they are.  The only reason you can tell the difference between this ring and other signet rings is because of the label underneath the ring, identifying it.
STYX
,
	({"gloves", "silvery gloves"}) :
@STYX
These gloves are made of a strange silvery cloth, but much stronger.  The gloves slide over your hands and halfway up your forearms, to protect your arms.  The gloves themselves glow with a strange power and are the symbol of the Legion of Lost Souls.
STYX
,
	({"earring", "silver and onyx earring"}) :
@STYX
This small loop is made of a silver and onyx mixture. Its a small single earring that loops through the left ear lobe of its wearer.  The small loop has a delicate design that wraps around it.  This ring is used as the simple symbol of first the Raiders in Night's Cloak, and later the Tempered Blades.
STYX
,
	({"platform", "marble platform"}) : 
@STYX
This is a marble block approximately three feet high.  On top of the marble block sits a glass case and on the side of the block is a small plaque.
STYX
,
	]));
	set_exits(([
		"out" : "/d/dagger/Daggerdale/shops/wood_back",
	]));
}

string time_east_wall(string str) {
  if(query_time_of_day() == "dawn" || query_time_of_day() == "twilight") {
    return("Runes now cover the entire wall underneath the sunrise symbol."  
    "  Perhaps you can read it.");
  } else {
  return("There is an engraving of a rising sun at the top of the wall, but the "
  "rest is strangely blank.");
  }
}

string my_query_long(string str) {
	if(query_time_of_day() == "dawn" || query_time_of_day() == "twilight") {
		return( "The center of this room is dominated by a %^BOLD%^small "
		"marble platform %^RESET%^with a glass case on top in which several "
		"items of interest rest.  Attached to the platform just below the glass "
		"is a small plaque.  The floor is covered with a %^BLUE%^deep blue "
      "carpeting%^RESET%^ so thick and plush you can't hear your own footsteps.  "
      "The south wall is covered with %^ORANGE%^richly grained walnut paneling "
      "stained a deep brown%^RESET%^.  The east and west walls are stonework.  "
      "The west wall is covered from top to bottom with runes but the east "
      "wall is %^BOLD%^brightly lit with %^RED%^fiery %^RESET%^%^BOLD%^glowing "
      "runes." );
	} else {
	return("The center of this room is dominated by a %^BOLD%^small marble "
	"platform %^RESET%^with a glass case on top in which several items of "
	"interest rest.  Attached to the platform just below the glass is a "
	"small plaque.  The floor is covered with a %^BLUE%^deep blue carpeting "
	"%^RESET%^so thick and plush you can't hear your own footsteps.  The "
	"south wall is covered with %^ORANGE%^richly grained walnut paneling "
	"stained a deep brown%^RESET%^.  The east and west walls are stonework.  "
	"The west wall is covered from top to bottom with runes while the east "
	"wall is nearly blank.");
	}
}
	
void init() {
	::init();
	add_action("read_stuff", "read");
	add_action("twist_plaque", "twist");
	add_action("twist_plaque", "turn");
}

void reset() {
	::reset();
}

int read_stuff(string str){   
	if(str == "plaque") {
		write(
@STYX
This plaque is one of the marks left by Vethor, last of the Crimson Daggers and leader of the Tempered Blades.  Within this glass case lie his screaming daggers, along with the guild items of the three guilds he has had the honor of serving as high commander.
STYX
		);
		tell_room(ETP,TPQCN+" appears to be reading the plaque", TP);
		return 1;
	}
	if(str == "wall") {
		write("Read which wall?\n");
		return 1;
	}
	if(str == "west wall") {
		TP->more("/d/dagger/Daggerdale/shops/vethor_bg1");
		tell_room(ETP,TPQCN+" seems to be reading the runes on the west wall.", TP);
		return 1;
	}
	if(str == "east wall") {
		if(query_time_of_day() == "dawn" || query_time_of_day() == "twilight") {
			TP->more("/d/dagger/Daggerdale/shops/vethor_bg2");
			tell_room(ETP,TPQCN+" seems to be reading the runes on the east wall.",TP);
			return 1;
		}
	write("All you see is the picture of the rising sun.");
	return 1;
	}
}

string query_time_of_day() {
	string str;
	str = EVENTS_D->query_time_of_day();
	return str;
}

int twist_plaque(string str){
	if(!str || str != "plaque") return notify_fail("Twist what?\n");
	tell_room(ETP,""+TPQCN+" twists the plaque and suddenly blinks out of "
	"sight!",TP);
	write("Suddenly you feel a rush of air and movement.\n"+
	"You find yourself someplace else!\n");
	TP->move_player("/d/dagger/Daggerdale/shops/vethor_guild");
	return 1;
}
