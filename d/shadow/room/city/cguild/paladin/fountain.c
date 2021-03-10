#include <std.h>
#define RPATH "/d/shadow/room/city/cguild/paladin/"+
inherit ROOM;
void init() {
    ::init();
    add_action("drink_func","drink");
}
void create() {
    ::create();
    set_property("light",2);
    set_property("night light",2);
    set_property("outdoors",1);
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"The aroma of goodness and purity fill the air."
    );
    set_listen("default","A slight singing fills your ears.");

    set_items(([
	"clearing":"%^CYAN%^You stand within a clearing. "
 	   "A %^RESET%^stone fountain "
	   "%^CYAN%^rests in the center of the clearing.%^RESET%^",
	"fountain":"%^CYAN%^The %^RESET%^"
           "fountain%^CYAN%^ bears three intertwining statues that spout "
           "%^BLUE%^water%^CYAN%^ into the basin of the fountain.%^RESET%^",
	"ceiling":"%^CYAN%^The %^GREEN%^trees%^CYAN%^ here provide a "
	   "ceiling like canopy.%^RESET%^",
        "water":"%^BLUE%^The water looks clear and refreshing.%^RESET%^",
	"canopy":"%^CYAN%^The %^GREEN%^trees%^CYAN%^ here provide a "
	   "ceiling like canopy.%^RESET%^",
	"trees":"%^CYAN%^The %^GREEN%^trees%^CYAN%^ here provide a "
	   "ceiling like canopy.%^RESET%^",
	"statues":"The statues spout water into the fountain.",
	"statue":"The statues spout water into the fountain.",
        "figures":"As you look upon the figures, one begins to speak to "
	   "you...\n%^YELLOW%^Figure says: %^CYAN%^Merely drink from the "
	   "fountain if you are of worth and entrance will be "
	   "granted!%^RESET%^"
    ]));
    set_exits(([
        "east":"/d/shadow/room/city/ch_rd_mu",
        "west":"/d/shadow/room/city/cguild/paladin/wood"
	    ]));
//    set_pre_exit_functions(({"north"}),({"exit_fun"}));  (no north - ??)
}

string lng_fun(string str) {
	if(!objectp(TP)) 
	{
	 	str = 
            "%^CYAN%^You stand within a clearing. A %^RESET%^stone fountain "
	    "%^CYAN%^rests in the center of the clearing. The %^RESET%^"
	    "fountain%^CYAN%^ bears three intertwining statues that spout "
	    "%^BLUE%^water%^CYAN%^ into the basin of the fountain. The "
	    "%^GREEN%^trees%^CYAN%^ here provide a ceiling like canopy."
	    "%^CYAN%^ ";
	}
	else
	{
    		if(!TP->is_class("paladin")) 
		{
			str = 
	            "%^CYAN%^You stand within a clearing. A %^RESET%^stone fountain "
		    "%^CYAN%^rests in the center of the clearing. The %^RESET%^"
		    "fountain%^CYAN%^ bears three intertwining statues that spout "
		    "%^BLUE%^water%^CYAN%^ into the basin of the fountain. The "
		    "%^GREEN%^trees%^CYAN%^ here provide a ceiling like canopy."
		    "%^CYAN%^ ";
	    	} 
		else 
		{
			str =
	            "%^CYAN%^You stand within a clearing. A %^RESET%^stone fountain "
		    	"%^CYAN%^rests in the center of the clearing. The %^RESET%^"
		    	"fountain%^CYAN%^ bears %^WHITE%^three intertwining angelic "
		    	"figures "
	    		"%^RESET%^%^CYAN%^that spout "
	    		"%^BLUE%^water%^CYAN%^ into the basin of the fountain. The "
	    		"%^GREEN%^trees%^CYAN%^ here provide a ceiling like canopy."
            	"\n%^YELLOW%^You recognize this as the shrine of the Paladins."
	    		"%^RESET%^"
	    		"%^CYAN%^ ";
    		}
	}
    	if(present("grazzt")) 
	{
		str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
		"by the evil presense of Grazzt.%^RESET%^";
    	}
    	return str;
}

string shrt_fun(string str) {
	if(!objectp(TP)) 
	{
		str = "%^CYAN%^Under the trees%^RESET%^";
	}
	else
	{
    		if(!TP->is_class("paladin")) 
		{
			str = "%^CYAN%^Under the trees%^RESET%^";
		} 
		else 
		{	
			str = "%^CYAN%^The Shrine of the Paladins%^RESET%^";
    		}
	}
    	return str;
}

int exit_fun() {
    write("%^CYAN%^You depart from the holy presense of the area.%^RESET%^" );
    say("%^CYAN%^"+TPQCN+" leaves the clearing.""%^RESET%^",TP);
    return 1;
}	

int drink_func(string str) {
    if(!str) return notify_fail("Drink what?\n");

    if(str != "water" && str != "fountain") return notify_fail("Drink what?\n");

    if(TP->is_class("paladin")) {
      tell_object(TP, "%^YELLOW%^As you drink from the fountain, the statues turn towards you and begin to sing!\n%^WHITE%^You appear elsewhere!%^RESET%^");
      tell_room(ETP, "%^YELLOW%^As "+TPQCN+" drinks from the fountain, the statues turn towards "+TPQCN+" and "+TP->query_subjective()+" vanishes in a bright flash of light!%^RESET%^", TP);
      TP->move_player( RPATH "sanctum.c");
      return 1;
    } else {
      tell_object(TP, "%^YELLOW%^As you start to drink from the water, the three statues turn towards you and begin to shriek!");
      tell_room(ETP, "%^YELLOW%^As "+TPQCN+" drinks from the fountain, the statues turn towards him and start to shriek!", TP);
      TP->move_player("/d/shadow/room/city/cguild/paladin/guardroom1.c");
      return 1;
    }
}
