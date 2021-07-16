/* fixed so have to specify open door or doors so open kit won't open it accidentally based on a bug report & cleaned up a little.  Do not use this as an exact example to code anything from because it isn't coded to current standards.  *Styx* 8/17/03
*/

#include <std.h>
inherit ROOM;
// #define SAVEROOM "/d/save/templedrow"  doesn't look like this is used *Styx*
string *exp_grants;
int GLYPH;
int RUNE;
int TABLET;
int SPHERE;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    seteuid(getuid());
    exp_grants = ({});
//    restore_object(SAVEROOM);  doesn't look like this is used or needed
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Within the temple walls");
    set_long(
	"%^BLACK%^%^BLUE%^You stand within the entrance of the %^CYAN%^temple "
 	"%^BLUE%^and now the %^CYAN%^temple doors%^BLUE%^ are clearly within "
	"view. The double doors are formed from black obsidian stone and "
	"are sealed shut. The doors are covered in symbols. "
	"\n%^RED%^A great evil seeps out from underneath the doors. "
	"%^RESET%^" 
    );
    set_listen("default",
 	"You hear a faint chanting that seems to come through the doors of the temple."
    );
    set_smell("default",
	"There is a faint trace of elemental disorder."
    );
    set_items(([
	"temple":"%^BOLD%^%^BLUE%^The temple is formed of black obsidian and there is no entrance from this point in the courtyard.%^RESET%^",
   "pinnacle":"%^MAGENTA%^The roof of the temple is pyramidical in shape and comes to a point at its apex.%^RESET%^",
	"symbol":"There are four symbols on the doors.",
	"symbols":"%^CYAN%^%^BOLD%^The first symbol is located in the center of "
	"the door and is of a sphere containing the wind."
	"\n%^BLUE%^The second symbol is located above the first and is formed as a "
	"depression in the door. It is depicted as rushing water."
	"\n%^RED%^The third symbol is located to the bottom left of the first "
	"is a mural of flames painted on the door."
	"\n%^GREEN%^The last symbol is located to the bottom right of the first "
	"and is a rectangular depression in the door's surface.%^RESET%^",
	"stone":"%^RED%^The stone is warm to the touch.",
	"walls":"The temple walls stand twenty feet high.",
	"wall":"There is no apparent entrance into the temple.",
	"hint":"%^BLUE%^Find the elven elder to seek entrance.%^RESET%^"
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/court8"
    ]));
}
void init() {
    ::init();
    add_action("inscribe_glyph","inscribe");
    add_action("open_doors","open");
    GLYPH = 0;
}
int inscribe_glyph(string str) {
    object *obs;
    int FLAG,x;
    if( !str || str != "glyph" || GLYPH != 0 ) {
	notify_fail ("Inscribe what?\n");
        return 0;
    }
    FLAG = 0;
    obs = all_inventory(TP);
    for ( x=0; x<sizeof(obs); x++) // I think this should use present("glyph of fire", TP)
        if ( obs[x]->id("glyph of fire")) {
	FLAG = 1;
        GLYPH = 1;
        if (FLAG) {
            message ( "my_action",
	        "%^BOLD%^%^RED%^You inscribe the glyph to the temple "
		"door in a burst "
		"of flames!%^RESET%^"
            ,TP);
            message ( "other_action",
	        "%^BOLD%^%^RED%^"+TPQCN+" inscribes a glyph to the "
		"temple door in a "
		"burst of flames!%^RESET%^"
    	    ,environment (TP), TP);
            remove_action("inscribe_glyph","inscribe");
            TABLET = 0;
            add_action("inset_tablet","inset");
            obs[x]->remove();
    	    FLAG = 0;
    	    return 1;
        }
    }
    if ( GLYPH != 1) {
        notify_fail ("Inscribe what?\n");
        return 0;
    }
}
int inset_tablet(string str) {
    object *obs;
    int FLAG,x;
    if( !str || ( str != "tablet" ) || TABLET != 0 ) {
	notify_fail ("Inset what?\n");
        return 0;
    }
    FLAG = 0;
    obs = all_inventory(TP);
    for ( x=0; x<sizeof(obs); x++)  
        if ( obs[x]->id("tablet of earth")) {
	FLAG = 1;
        TABLET = 1;
        if (FLAG) {
            message ( "my_action",
	        "%^BOLD%^%^GREEN%^You inset the tablet to the temple "
		"door and the "
		"earth seems to shake for a few seconds!%^RESET%^"
            ,TP);
    	    message ( "other_action",
	        "%^BOLD%^%^RED%^"+TPQCN+" insets a tablet to the "
		"temple door and the "
		"earth seems to shake for a few seconds!%^RESET%^"
    	    ,environment (TP), TP);
    	    remove_action("inset_tablet","inset");
    	    RUNE = 0;
    	    add_action("place_rune","place");
    	    obs[x]->remove();
    	    FLAG = 0;
            return 1;
        }
    } 
    if (TABLET != 1) {
        notify_fail ("Inset what?\n");
        return 0;
    }
}
int place_rune(string str) {
    object *obs;
    int FLAG,x;
    if( !str || ( str != "rune" ) || RUNE != 0 ) {
	notify_fail ("Place what?\n");
        return 0;
    }
    FLAG = 0;
    obs = all_inventory(TP);
    for ( x=0; x<sizeof(obs); x++)
        if ( obs[x]->id("rune of water")) {
	FLAG = 1;
        RUNE = 1;
        if (FLAG) {
            message ( "my_action",
	        "%^BOLD%^%^BLUE%^You place the rune upon the temple "
		"door and the doors "
		"seem to soften slightly!%^RESET%^"
    	    ,TP);
            message ( "other_action",
		"%^BOLD%^%^BLUE%^"+TPQCN+" places a rune upon the "
		"temple door and "
		"the doors seem to soften slightly!%^RESET%^"
            ,environment (TP), TP);
    	    remove_action("place_rune","place");
            SPHERE = 0;
            add_action("smash_sphere","smash");
            obs[x]->remove();
            FLAG = 0;
            return 1;
        }
    } 
    if(RUNE != 1) {
        notify_fail ("Place what?\n");
        return 0;
    }
}
int smash_sphere(string str) {
    object *obs;
    int FLAG,x;
    if( !str || ( str != "sphere" ) || SPHERE != 0) {
	notify_fail ("Smash what?\n");
        return 0;
    }
    FLAG = 0;
    obs = all_inventory(TP);
    for ( x=0; x<sizeof(obs); x++)
        if ( obs[x]->id("sphere of air")) {
        FLAG = 1;
        SPHERE = 1;
        if (FLAG) {
            message ( "my_action",
	        "%^BOLD%^%^CYAN%^You smash the sphere against the "
		"temple door!"
		"%^RESET%^"
            ,TP);
    	    message ( "other_action",
	        "%^BOLD%^%^CYAN%^"+TPQCN+" smashes a sphere against "
		"the temple door!"
		"%^RESET%^"
    	    ,environment (TP), TP);
    	    remove_action("smash_sphere","smash");
    	    obs[x]->remove();
            FLAG = 0;
            if(member_array("Drow Temple Doors",TP->
			    query_mini_quests()) == -1)
	      {
                TP->set_mini_quest(
			"Drow Temple Doors",2000000,"%^BOLD%^%^BLUE%^You "
        	        "mastered the secret of the Drow symbols to gain "
			"permanent "
	                "passage into their temple.%^RESET%^"
	        );
                write("The seal on the temple doors breaks free!");
            }
            return 1;
        }
    } 
    if( SPHERE !=1) {
        notify_fail ("Smash what?\n");
        return 0;
    }
}

int open_doors(string str) {
// adding a check for str == door so things like 'open kit' won't open them accidentally 
   if(!str) {
	write("Did you want to open doors or something else?");
	return 1;
   }
   if(str != "door" && str != "doors")
	return 0;
   if(present("drider")){
        tell_object(TP,"%^BLUE%^You are denied access by the drider.");
      return 1;
   }
    if(member_array("Drow Temple Doors",TP->query_mini_quests()) != -1)
  
      {
        write(
	    "%^BOLD%^%^BLUE%^With a slow ancient shudder, you swing open "
	    "the temple doors!%^RESET%^"
	);
        say(
	    "%^BOLD%^%^BLUE%^With a slow ancient shudder, "+TPQCN+" swings "
	    "open the temple doors!%^RESET%^"
	,TP);
        add_exit("/d/dagger/drow/rooms/temple1","temple");
        return 1;
    } else {
        write(
	    "%^BOLD%^%^BLUE%^The temple doors refuse to budge!%^RESET%^"
	);
        say(
	    "%^BOLD%^%^BLUE%^"+TPQCN+" struggles to open the temple doors..."
	    "but has no success in gaining entrance.%^RESET%^"
	,TP);
        return 1;
    }
}

void reset() {
    object ob;
    ::reset();
// adding check for players present so it won't reset while they are there in the process of figuring it out *Styx*  8/18/03
    if(present("player"))
	return;		// yes I mean to skip everything else if they are there
    remove_action("inset_tablet","inset");
    TABLET = 0;
    remove_action("place_rune","place");
    RUNE = 0;
    remove_action("smash_sphere","smash");
    SPHERE = 0;
    remove_exit("temple");
    if(!present("drider") && !random(4)){
        ob = new("/d/dagger/drow/temple/mon/drider.c");
        ob->set_property("no bows",1);
        ob->move(TO);
    }
}