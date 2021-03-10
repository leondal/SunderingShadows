#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit CRATER;
void create() 
{
   	::create();
	set_name("An obsidian chamber");
	set_short("%^BOLD%^%^WHITE%^An %^BOLD%^%^BLACK%^obs%^BOLD%^%^WHITE%^"+
    "i%^BOLD%^%^BLACK%^dian%^BOLD%^%^WHITE%^ chamber%^RESET%^");

	set_long("%^BOLD%^%^WHITE%^This chamber is much smaller than the others "+
    "in this cavern. It is much rougher with most of the st%^BOLD%^%^BLACK%^o"+
    "%^BOLD%^%^WHITE%^ne that composes it "+
    "jutting out at odd angles to form razor-sharp edges. The ceiling is "+
    "lower, perhaps only twenty feet overhead, and there are multitudes of small "+
    "%^BOLD%^%^CYAN%^stalactites%^BOLD%^%^WHITE%^ hanging down from it. Along the "+
    "northern wall is a large pool of %^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^a%^BOLD%^"+
    "%^RED%^gm%^BOLD%^%^YELLOW%^a%^BOLD%^%^WHITE%^ which bubbles rapidly and seems to "+
    "be quite unstable. All the walls of the chamber, save for the southern one, appear "+
    "much more solid than the others throughout this cavern, having no visible cracks. "+  
    "The southern wall, however, looks almost collapsed and there is a %^BOLD%^%^BLACK%^"+
    "giant crack%^BOLD%^%^WHITE%^ running the length of it. You are unable to determine much "+
    "about the floor of this chamber as it is "+
    "entirely covered by a thick, disgusting %^BOLD%^%^GREEN%^slime%^BOLD%^%^WHITE%^ "+
    "that you must wade through.%^RESET%^");

    set_smell("default","\nThe air is saturated with the odor of filth and decay.");

    set_property("wild magic", 15);

    set_property("no teleport", 1);

    set_listen("default","Strange sounds bounce off the cavern walls and echoing loudly around you.");			
	
    set_items(([
        ({"obsidian", "walls", "ceiling", "chamber"}) : "%^BOLD%^%^BLACK%^This chamber "+
        "is carved from the same obsidian as the rest of the cavern but it is much smaller and "+
        "much rougher. The ceiling is lower, perhaps only twenty feet high, and covered by "+
        "multitudes of stalactites. The walls, save for the southern wall, look much more "+
        "solid and much of the stone forming them juts out at odd angles to form razor-sharp "+
        "edges.%^RESET%^",

        ({"stalactites", "stalactite"}) : "%^BOLD%^%^CYAN%^These crystal formations are "+
        "a much darker red than the others throughout the cavern. They are much smaller and "+
        "there are multitudes of them.%^RESET%^", 
 
        ({"floor", "slime", "acidic slime"}) : "%^BOLD%^%^GREEN%^This thick, disgusting "+
        "slime covers the entire floor. You are unable to determine anything about what "+
        "might be underneath it but you know that it smells horrific. It occassionally "+
        "drifts into the pool of magma where it burns away but for the most part it is "+
        "firm enough that it does not move and does not allow other liquids to "+
        "enter it.%^RESET%^",

        ({"magma", "pool", "magma pool"}) : "%^BOLD%^%^RED%^This large pool of "+
        "magma rests along the northern wall of the chamber. It bubbles rapidly and "+
        "is obviously quite unstable. It is possible that it could erupt at any moment "+
        "and flood the entire chamber.%^RESET%^",

        ({"crack", "south wall", "giant crack"}) : "%^BOLD%^%^BLACK%^This large crack "+
        "runs the length of the southern wall. It looks as if it opens into a much "+
        "larger cavern. You could %^BOLD%^%^CYAN%^enter%^BOLD%^%^BLACK%^ it, if you were "+
        "so inclined.%^RESET%^",

	]));

    set_property("light",-1);
    set_property("indoors",1);

    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);	
    call_out("do_eruption", 20);
}

void do_eruption()
{
    object *liv;
    int x;
    if(!objectp(TO)) return;
    if(random(25)) 
    { 
        call_out("do_eruption", 20);
        return;
    }
    liv = all_living(TO);

    tell_room(TO, "%^BOLD%^%^RED%^The pool of %^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^a%^BOLD%^"+
    "%^RED%^gm%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^ erupts, flooding the chamber!%^RESET%^");

    for(x = 0;x < sizeof(liv);x++)
    {
        if(!objectp(liv[x])) continue;
        if(liv[x]->query_true_invis()) continue;
        if(liv[x]->id("mass of oozing flesh")) 
        {
            tell_room(TO, liv[x]->QCN+" %^BOLD%^%^GREEN%^hungrily gulps down "+
            "much of the %^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^a%^BOLD%^"+
    		"%^RED%^gm%^BOLD%^%^YELLOW%^a%^BOLD%^%^GREEN%^ and seems "+
            "refreshed by it!%^RESET%^");
            liv[x]->heal(roll_dice(3,20));
            liv[x]->belch();
            continue;
        }
        tell_room(TO, liv[x]->QCN+"%^BOLD%^%^RED%^ is covered by the "
        "%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^a%^BOLD%^"+
 		"%^RED%^gm%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^!%^RESET%^", liv[x]);
        
        tell_object(liv[x], "%^BOLD%^%^RED%^You are covered by the boiling "+
        "%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^a%^BOLD%^"+
    	"%^RED%^gm%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^ and burned horribly!");

        liv[x]->cause_typed_damage(liv[x], 0, roll_dice(4,20), "fire");
        continue;
    }
    tell_room(TO, "%^BOLD%^%^RED%^The pool of %^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^a%^BOLD%^"+
    "%^RED%^gm%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^ settles back down as "+
    "the excess drains back into it!%^RESET%^");
    call_out("do_eruption", 20);
    return;
}

void reset()
{
    ::reset();
    if(!present("mass of oozing flesh", TO) && !random(2)) new(CRMON+"abomination")->move(TO);
}

void init()
{
    ::init();
    add_action("enter_crack", "enter");
}

int enter_crack(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(str != "crack" && str != "large crack" && str != "larger crack" && str != "south crack") return 0;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^BLACK%^You crawl through the large crack on the southern wall.%^RESET%^");
    if(!TP->query_invis()) 
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^BLACK%^ crawls through the large crack on "+
        "the southern wall!%^RESET%^", TP);
    }
    TP->move(CRROOMS+"inner30");
    TP->force_me("look");
    return 1;
}
