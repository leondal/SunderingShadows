#include <std.h>
#include "../inherits/area_stuff.h"
inherit BASEMENT;

int searched;

void create() 
{
    ::create();
    set_name("An ancient tomb");
    set_short("%^BOLD%^%^RED%^An ancient tomb%^RESET%^");

    set_long("%^BOLD%^%^RED%^The room that you find yourself in has been "+
    "constructed from a darker %^RESET%^%^GREEN%^oak%^BOLD%^%^RED%^. It has decayed "+
    "to the point of being totally unstable. The beams in the ceiling have all "+
    "broken and fallen out of place, allowing clumps of %^BOLD%^%^MAGENTA%^earth"+
    "%^BOLD%^%^RED%^ to spill into the room. The walls, which have cracked and split "+
    "open in several places, are covered with a %^RESET%^%^GREEN%^thick moss%^BOLD%^%^RED%^. "+
    "The floor is mostly bare %^BOLD%^%^MAGENTA%^earth%^BOLD%^%^RED%^ with most of the "+
    "wood that once composed it long since rotted away. In the very middle of the room "+
    "there is an %^BOLD%^%^CYAN%^altar%^BOLD%^%^RED%^, constructed from what appears to be "+
    "human %^BOLD%^%^WHITE%^bones%^BOLD%^%^RED%^ with a large sarcophagus "+
    "resting upon it. In front of the altar there is a large %^BOLD%^%^WHITE%^stone"+
    "%^BOLD%^%^RED%^ which has a message that has been hastily scrawled into "+
    "it.%^RESET%^");
	
    set_smell("default","\nThe smell of earth tained by decay hangs heavily.");
    set_listen("default","Sounds of wood snapping can be heard all around you.");			

    set_items(([
        ({"walls", "ceiling", "floor", "earth", "decay",
        "oak", "moss", "thick moss", "clumps"}) : "%^RESET%^%^GREEN%^The walls of this "+
        "room have cracked and split open in spots, the remainder of their "+
        "surface has been covered with a thick moss. The ceiling is in no "+
        "better state with the beams which construct it having broke long ago, "+
        "allowing fresh earth to spill through in clumps. The floor is "+
        "almost entirely bare earth, the wood from which it was once constructed "+
        "having long since rotted away.%^RESET%^",
		
        ({"altar", "bones"}) : "%^BOLD%^%^BLACK%^This altar rests in almost the direct "+
        "of the room. It has been constructed from what appears to be human bones. The "+
        "bones have been %^BOLD%^%^RED%^charred%^BOLD%^%^BLACK%^ by something unknown. "+
        "They rise up above the sarcophagus that rests on the altar to form what almost "+
        "looks like horns on each corner of the altar. You are not sure what the purpose "+
        "of this thing might be, but it is definitely evil.%^RESET%^",
		
        ({"stone", "large stone"}) : ({"%^BOLD%^%^WHITE%^This large stone looks "+
        "as if it were placed here as an afterthought, perhaps as a %^BOLD%^%^RED%^warning"+
        "%^BOLD%^%^WHITE%^ for anyone who might find themselves here. It has a message "+
        "that has been hastily scrawled into it.%^RESET%^", "I have placed this stone "+
        "here as a warning. It took great effort to get it into this place. I found this "+
        "chamber deep under the graveyard. Something horrible is taking place, "+
        "something worse than what rests here. I hear talk of a new, ancient name, "+
        "some Au'rus Devar. I believe whatever darkness once ruled Deku has bowed "+
        "to him, forcibly, I think. The creatures moan and groan his name, in what "+
        "language they are able to speak. I know that a change is coming, one "+
        "which will forever change this island.... or at least the world "+
        "beneath it. Many do not know that it goes down! I ramble... I will "+
        "place more messages elsewhere, if I am able... For now DO NOT "+
        "open the sarcophagus! Some slave to Au'rus Devar has enslaved "+
        "ancient warriors here and they will not be kind to any "+
        "disturbances! You HAVE been warned!%^RESET%^", "common"}), 
		
        ({"sarcophagus", "tomb"}) : "%^BOLD%^%^MAGENTA%^This large "+
        "sarcophagus looks relatively new in comparison to the rest "+
        "of the room. It has been constructed from a dull %^BOLD%^"+
        "%^BLACK%^marble%^BOLD%^%^MAGENTA%^. You might be able to "+
        "%^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^open%^BOLD%^%^WHITE%^> "+
        "%^BOLD%^%^MAGENTA%^it, if you were so inclined.%^RESET%^",

    ]));
	
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    searched = 0;
    TO->check_adjustment();
}

void init()
{
    ::init();
    add_action("open_tomb", "open");	
}

void reset()
{
    ::reset();	
    if(searched == 0 || !random(5)) 
    {
        if(searched == 1) 
        {
            if(!present("elazo", TO) && !present("narameon", TO)) searched = 0;
        }
        if(!present("tomb spirit", TO)) new(HHMON+"tomb_spirit")->move(TO);
        if(!present("tomb guardian", TO)) new(HHMON+"tomb_guardian")->move(TO);
    }
}

void awaken()
{
    object mon;
    if(!objectp(TO)) return;
    if(!searched) return;
    switch(random(10))
    {
        case 0..4:
            mon = new(HHMON+"elazo");
            break;
        case 5..9:
            mon = new(HHMON+"narameon");
            break;
    }
    tell_room(TO, "%^BOLD%^%^GREEN%^You watch in %^BOLD%^%^RED%^HORROR%^BOLD%^%^GREEN%^"+
    " as "+mon->query_short()+" crawls quickly out of the tomb!%^RESET%^");
    mon->move(TO);
    return;
}

int open_tomb(string arg)
{
    object mon;
    int myStr;
    if(!arg) return 0;
    if(arg != "tomb" && arg != "sarcophagus") return 0;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(searched == 1)
    {
        tell_object(TP, "%^BOLD%^%^RED%^The sarcophagus is already open.%^RESET%^");
        return 1;
    }

    if(objectp(mon = present("tomb spirit", TO)) || 
    objectp(mon = present("tomb guardian", TO))) 
    {
        tell_object(TP, mon->query_short() + " will not let you get close enough to the "+
        "tomb to try to open it!%^RESET%^");
        return 1;
    }

    myStr = (int)TP->query_stats("strength");
	
    tell_object(TP, "%^BOLD%^%^RED%^You strain and struggle trying to open the "+
    "massive tomb!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ strains and struggles, trying to open the "+
        "massive tomb!%^RESET%^", TP);
    }
    if((myStr + roll_dice(1, 20)) < 32) 
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^Despite all of your struggle the lid of the "+
        "tomb does not budge!%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^BLACK%^ is unable to lift the lid of the tomb!%^RESET%^");
        }
        return 1;
	}
    tell_object(TP, "%^BOLD%^%^WHITE%^Finally! All of your struggling has paid off... you lid of the "+
    "tomb slides off to the side!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ struggles and struggles and finally the lid of the "+
        "tomb slides off!%^RESET%^", TP);
    }
    else tell_room(TO, "%^BOLD%^%^RED%^With a loud THUD the lid of the tomb slides off to the side!%^RESET%^", TP);
	
    searched = 1;
    tell_room(TO, "%^BOLD%^%^GREEN%^A horrible stench wafts out from within the tomb.... and "+
    "you hear the sounds of something stirring within!%^RESET%^");
    call_out("awaken", 5);
    return 1;
}
