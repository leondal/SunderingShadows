#include <std.h>
#include <daemons.h>

#include "area_stuff.h"

#include "/d/common/common.h"

inherit HAUNTING;
int myRoomState, hid_state;
string original_long, sexit, dest;


void open_hidden_room()
{
    object hidroom;
    if(hid_state == 0) 
    {
        hid_state = 1;
        tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexit+"ern"+
        " wall slides to the side, revealing "+
        "an opening!%^RESET%^");
        TO->add_exit(dest, sexit);
        if(catch(hidroom = to_object(dest))) 
        {
            tell_room(TO, "ERROR: Tell Saide something BROKE IN THIS OTHER ROOM(THIS MESSAGE IS SPECIFIC TO THIS ROOM");
        }
        if(objectp(hidroom)) hidroom->open_hidden_room();
        return;
    }
}

void close_hidden_room()
{
    object hidroom;
    if(hid_state == 1)
    {
        tell_room(TO, "%^BOLD%^%^RED%^A section of the "+sexit+"ern"+
        " wall slides back into place!%^RESET%^");
        hid_state = 0;
        TO->remove_exit(sexit);
        if(catch(hidroom = to_object(dest))) 
        {
            tell_room(TO, "ERROR: Tell Saide something BROKE IN THIS OTHER ROOM(THIS MESSAGE IS SPECIFIC TO THIS ROOM");
        }
        if(objectp(hidroom)) hidroom->close_hidden_room();
        return;
    }
}

void pick_room()
{
    int tmp;
    tmp = myRoomState;
    myRoomState = random(2);
    if(tmp == myRoomState) return;
    switch(myRoomState)
    {
        case 0:		
            set_short("%^RESET%^%^ORANGE%^A delapidated hallway inside the house%^RESET%^");

            original_long = "%^RESET%^%^ORANGE%^The hallway around you is in an advanced "+
            "state of %^BOLD%^%^RED%^decay%^RESET%^%^ORANGE%^. It was once constructed from "+
            "a pristine %^GREEN%^oak%^RESET%^%^ORANGE%^ that has since intensely "+
            "deteriorated. %^GREEN%^Thick moss%^RESET%^%^ORANGE%^ covers most visible "+
            "surfaces of the walls. The ceiling over your head hangs down much lower than "+
            "what it should and the floor beneath your feet seems like it might "+
            "give away at any moment. A %^BOLD%^%^BLUE%^cold breeze%^RESET%^%^ORANGE%^ "+
            "exists here constantly, seemingly just another method of making the "+
            "venture here even more unpleasant. It is quite dark on this floor of the "+
            "house and there is no source of light that you can tell. Perhaps whoever "+
            "or whatever lives here, likes it that way? Thick %^BOLD%^%^BLACK%^shadows"+
            "%^RESET%^%^ORANGE%^ around you seem to be moving.%^RESET%^";

            set_long(original_long);

            set_smell("default","\nA faint odor of something burning mixes with "+
            "a strong odor of decay.");
			
            set_items(([
            ({"walls", "wall", "ceiling", "floor", 
            "oak", "decay"}) : "%^BOLD%^%^BLACK%^The state of decay in the hallway "+
            "around you is amazing. The oak, from which it is constructed, is deteriorated "+
            "and rotted to the point where travel here is probably no longer safe. The ceiling "+
            "hangs down much lower than it should and it is quite remarkable that it supports "+
            "the weight of the floor above you. The floor beneath your feet seems like it "+
            "might give away at any moment. The walls around you are covered by a thick moss "+
            "which threatens to overtake them.%^RESET%^",

            ({"moss", "thick moss"}) : "%^RESET%^%^GREEN%^This thick moss is the same "+
            "that grew outside the house. It has obviously made it inside here and threatens "+
            "to overtake this place.%^RESET%^",

            ({"breeze", "cold breeze"}) : "%^BOLD%^%^BLUE%^You are unsure where this "+
            "breeze is coming from but it is constant and unabating.%^RESET%^",

            ({"shadow", "shadows"}) : "%^BOLD%^%^BLACK%^The shadows around you "+
            "seem almost palpable, you are sure that they move on their own "+
            "volition.%^RESET%^",

            ]) );

            break;
        case 1:
            set_short("%^RESET%^%^GREEN%^A pristine hallway inside the house%^RESET%^");

            original_long = "%^RESET%^%^GREEN%^The hallway around you is in "+
            "%^BOLD%^pristine%^RESET%^%^GREEN%^ condition! It looks remarkably "+
            "well kept, as if much effort has went into making sure that it "+
            "is cared for. The %^BOLD%^oak%^RESET%^%^GREEN%^ from which it is "+
            "constructed literally %^BOLD%^%^CYAN%^shines%^RESET%^%^GREEN%^ "+
            "as if someone regularly polishes it. The ceiling above you is straight and "+
            "precise, showing no signs of bearing the weight of the floor above you. "+
            "The floor beneath your feet is firm and solid, a testament to the excellent "+
            "skill of whoever constructed this house. The temperature here is "+
            "quite comfortable. Unfortunately it is quite dark here, you can "+
            "discern no obvious source of light. Perhaps whoever or whatever lives "+
            "here, likes it that way? If not for that and the thick %^BOLD%^"+
            "%^BLACK%^shadows%^RESET%^%^GREEN%^ around you that seem "+
            "to be moving the venture here would not be an unpleasant one.%^RESET%^";
	
            set_smell("default","\nVarious sweet fragrances assault your nostrils.");
	
            set_long(original_long);	
		
            set_items(([
                ({"walls", "wall", "ceiling", "floor", "well kept", 
                "oak"}) : "%^RESET%^%^GREEN%^The ceiling here is precise, "+
                "it shows no signs of bearing the weight of the floor above "+
                "you. The floor beneath your feet is firm and solid, a "+
                "testament to the excellent skill of whoever constructed "+
                "this house. The walls around you are in pristine condition. "+
                "In fact the entire area seems to shine, the obvious result of "+
                "someone who frequently polishes it. It is amazing the "+
                "effort that has went into keeping this hallway in such "+
                "remarkable shape.%^RESET%^",

                ({"shadow", "shadows"}) : "%^BOLD%^%^BLACK%^The shadows "+
                "around you give you pause. They seem out of place here "+
                "but they are almost palpable and you are sure that they "+
                "move on their own volition.%^RESET%^",
            ]));
            break;
    }

    if(tmp != myRoomState)
    {
        if(objectp(TO)) 
        {
            tell_room(TO, "%^BOLD%^%^RED%^You blink and the very hallway around "+
            "you changes!!%^RESET%^");
		
            tell_room(TO, "%^BOLD%^%^BLUE%^An insane laughter erupts from the very air "+
            "around you, but quickly dies out!%^RESET%^");
		
            TO->adjust_room(myRoomState);
        }
    }
	
}

string query_original_long() { return original_long; }

void create() 
{
    if(base_name(TO) != FFH) 
    { 
        switch(random(11)) 
        {
            case 0..6:
                break;
            case 7..10:
                set_monsters(({HHMON+"crazed_guard"}), ({1 + random(3)}));
                break;      			
        }
        set_repop(40);
    }
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("A hallway inside the house");
    myRoomState = -1;
    pick_room();
    
    set_listen("default","Silence hangs in the air as a heavy blanket here interrupted only "+
    "by the uncertain sounds coming from the darkness around you.");
    if(sexit) 
    {
        set_search(sexit, (:TO, "lever_search":));
        set_search(sexit+"ern wall", (:TO, "lever_search":));
        set_search(sexit+" wall",(:TO, "lever_search":));	
        set_search("default", "%^BOLD%^%^WHITE%^The %^BOLD%^%^CYAN%^"+
        sexit+"ern wall%^BOLD%^%^WHITE%^ draws your attention.%^RESET%^");
    }
    else
    {
        set_search("default", "%^BOLD%^%^WHITE%^You notice no place for anything to be "+
        "hidden.%^RESET%^");
    }
}

void init()
{
    ::init();
    add_action("pull_lever", "pull");
}

int lever_search(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!sexit) return 0;
    tell_object(TP, "%^BOLD%^%^RED%^You search the "+sexit+" wall and find a small lever! "+
    "You should %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^pull%^BOLD%^%^WHITE%^>%^BOLD%^%^RED%^ "+
    "it!%^RESET%^");
    return 1;
}

int pull_lever(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!sexit) return 0;
    tell_object(TP, "%^BOLD%^%^RED%^You easily pull the small lever!%^RESET%^");
    if(!TP->query_invis()) 
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ pulls a small lever on the "+sexit+" wall!%^RESET%^", TP);
    }
    if(hid_state == 0) 
    {
        open_hidden_room();
        return 1;
    }
    if(hid_state == 1)
    {
        close_hidden_room();
        return 1;
    }
}


void reset()
{
    ::reset();
    close_hidden_room();
    pick_room();
}