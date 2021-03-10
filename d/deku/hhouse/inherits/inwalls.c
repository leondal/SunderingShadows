#include <std.h>
#include <daemons.h>
#include <move.h>

#include "area_stuff.h"
#include "/d/common/common.h"

inherit HAUNTING;
int searched, hid_state, has_floor_hole, has_roof_hole;
string sexit, dest;

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
            tell_room(TO, "ERROR: Tell Saide something BROKE IN THIS ROOM (THIS MESSAGE IS SPECIFIC TO THIS ROOM");
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
            tell_room(TO, "ERROR: Tell Saide something BROKE IN THIS ROOM (THIS MESSAGE IS SPECIFIC TO THIS ROOM");
        }
        if(objectp(hidroom)) hidroom->close_hidden_room();
        return;
    }
}

void create() 
{
    ::create();
    set_name("In the walls of the house");
    set_short("%^BOLD%^%^BLACK%^In the walls of the house%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You find yourself in a passage way "+
    "between the walls of the house. Everything here is %^BOLD%^%^MAGENTA%^"+
    "warped%^BOLD%^%^BLACK%^ and %^BOLD%^%^RED%^decaying%^BOLD%^%^BLACK%^. "+
    "The walls of the passageway are actually leaning slightly and the "+
    "ceiling is hanging down low enough that an average sized human would "+
    "be hard pressed not to bump his head occassionally. The floor beneath your "+
    "feet sags and feels quite spongy, you think that it would definitely "+
    "be possible to %^BOLD%^%^RED%^fall%^BOLD%^%^BLACK%^ through from here "+
    "if you do not carefully watch your step. Dust, grime, and %^BOLD%^"+
    "%^WHITE%^thick %^BOLD%^%^BLACK%^webs have built up all over "+
    "the walls, as if nothing has been "+
    "in this passage for a very long time.%^RESET%^");
	
    set_smell("default","\nSweet odors mix with sulfur and a hint of decay.");
	
    set_listen("default","Faint screams, moans, groans, and other less "+
    "identifiable sounds are coming from the walls!");			
			
    set_items(([
        ({"walls", "ceiling", "floor", "decaying", 
        "warped", "sags"}) : "%^BOLD%^%^RED%^The floor, walls, and "+
        "ceiling here are decaying. They are quite warped and it is "+
        "suprising that this passage way is still useable at all. "+
        "The ceiling hangs down far too low and the floor "+
        "sags beneath your weight.%^RESET%^",

        ({"dust", "grime", "webs", "thick webs", "web", 
        "thick web"}) : "%^BOLD%^%^WHITE%^"+
        "The layers of grime, dust, and web are thick and "+
        "look mostly undisturbed, as if this passage has not been "+
        "used in a very long time. You wonder about what could be "+
        "hidden within the webs.%^RESET%^",
    ]));

    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);

    if(sexit) 
    {
        set_search(sexit, (:TO, "lever_search":));
        set_search(sexit+"ern wall", (:TO, "lever_search":));
        set_search(sexit+" wall",(:TO, "lever_search":));	
        set_search("default", "%^BOLD%^%^YELLOW%^Perhaps the "+
        "%^BOLD%^%^WHITE%^web%^BOLD%^%^YELLOW%^ hides sommething? The "+
        "%^BOLD%^%^CYAN%^"+sexit+"ern wall%^BOLD%^%^YELLOW%^ draws your attention.%^RESET%^");
    }
    else
    {
        set_search("default", "%^BOLD%^%^YELLOW%^Perhaps the "+
        "%^BOLD%^%^WHITE%^web%^BOLD%^%^YELLOW%^ hides something?%^RESET%^");
    }
    set_search("web", (:TO, "web_search":));
    set_search("webs", (:TO, "web_search":));
    searched = random(5);	
}

void init()
{
    ::init();
    add_action("pull_lever", "pull");
}

int web_search(string str)
{
    string tmp;
    object ob, ob2;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ carefully searches the web.%^RESET%^", TP);
    }
    if(searched != 1) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You carefully search the web, getting some "+
        "of the strands to stuck to you, but finding nothing of interest.%^RESET%^");
        searched = 0;
        tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ doesn't seem to find anything of value..%^RESET%^", TP);
        return 1;
    }
    searched = 0;
    if(random(6)) 
    {
        switch(random(10)) 
        {
            case 0..8:
                tmp = "a lost pouch";
                ob = new("/d/common/obj/misc/pouch");
                ob2 = new("/std/obj/coins");
                ob2->set_money("gold", 400 + random(1250));
                ob2->move(ob);
                break;
            case 9:
                ob = new("/d/magic/scroll");
                ob->set_spell(4 + random(4));
                tmp = "an old scroll";
                break;
        }
        tell_object(TP, "%^BOLD%^%^WHITE%^You carefully search the web, getting some of "+
        "the strands to stuck to you, but you manage to find "+tmp+"!%^RESET%^");
        if(ob->move(TP) != MOVE_OK)
        {
            tell_object(TP, "%^RESET%^%^ORANGE%^You drop the "+tmp+"!%^RESET%^");
            ob->move(TO);
        }
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^An uneasy feeling almost overwhelms you as "+
        "you sense immediate danger!%^RESET%^");
        ob = new(HHMON+"spectral_spider");
        tell_room(TO, "%^BOLD%^%^RED%^A "+ob->query_short()+"%^BOLD%^%^RED%^ "+
        "appears among the webs!%^RESET%^");
        ob->move(TO);
        ob->soul_theft(TP);
        return 1;
    }
    return 1;
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
    searched = random(5);
}