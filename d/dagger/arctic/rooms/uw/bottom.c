#include <std.h>
#include "../../arctic.h"
inherit UNDERWATER;

int enter_gash_dead();
void set_functions();

int FLAG,ACTION;

void create()
{
    ::create();
    set_name("The Bottom of the Lake");
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_terrain(DEEP_WATER);
    set_travel(RUTTED_TRACK);
    set_property("light", -1);
    set_climate("arctic");
    
    set_short("%^BOLD%^%^BLACK%^Deep in the icy water%^RESET%^");
        
    set_long("%^BOLD%^%^BLACK%^The water this deep in the icy lake "
        "is warmer than that closer to the surface.  It is still cold "
        "here, but not unbearably so.  The pressure of the water this "
        "far down is intense, it compresses your chest, and forces "
        "your eyes farther back into the sockets.  You can feel the "
        "tightness of it all around your body pushing against your skin.  "
        "you are more than a hundred feet down from the surface, but "
        "less than two hundred feet.%^RESET%^");
    
    set_items(([
                "water" : "The icy water is all around you, if you "
                "cannot hold your breath, you might be in trouble.",
                ({"ice","surface"}) : "The ice of the surface is far above you.",
                ({"center","lake"}) : "The dark water in the center "
                "of the lake is deep and forboding."
              ]));
                
    
    set_smell("default", "You can't smell anything.");
    set_listen("default", "The bubbling echo of water fills your ears.");

    set_exits(([ 
        "up" : UW"uwb5", 
             ]));
    FLAG = 0;

    new(MON"dire_shark")->move(TO);

}

void init()
{
    ::init();
    add_action("cut_hole", "cut");
    return;
}

void cut_hole()
{
    object obj,obj1;
    if(FLAG) 
    { 
        tell_object(TP, "%^RESET%^%^BOLD%^There is already a hole cut "
        "in the belly of the shark.%^RESET%^"); 
        return 1; 
    }
    if(present("shark corpse")) 
    { 
        present("shark corpse")->remove(); 
        tell_object(TP, "%^RED%^You gut a ragged gash into the belly "
            "of the shark that is large enough to crawl into.%^RESET%^");
        tell_room(ETP, "%^RED%^"+TP->QCN+" is covered with blood and gore "
            "as "+TP->QS+" cuts a large gash into the belly of the shark.%^RESET%^",TP);
        obj = new(OBJ"shark_corpse_gashed");
        obj->move(TO);
        obj1 = find_object_or_load(UW"shark_stomach");
        obj1->add_exit(UW"bottom", "gash");
        obj1->set_functions();
        add_exit(UW"shark_stomach", "crawl");
        set_invis_exits(({"crawl"}));
        set_functions();
        FLAG = 1;
        return 1;
    }
    tell_object(TP, "What?\n");
    return 1;
}

void set_functions()
{
    if(present("dire shark", TO))
    {
        set_pre_exit_functions(({"crawl"}),({"enter_gash_alive"}));
        return;
    }
    set_pre_exit_functions(({"crawl"}),({"enter_gash_dead"}));
    return;
}

int enter_gash_alive()
{
    if(!present("dire shark", TO)) { set_pre_exit_functions(({"crawl"}),({"enter_gash_dead"})); enter_gash_dead(); return 1; }
    if(roll_dice(1,20)+4 > TP->query_dexterity())
    {
        tell_object(TP, "%^RED%^The shark dodges to the side, preventing "
            "you from crawling in the gash in its stomach!%^RESET%^");
        tell_room(ETP, "%^RED%^"+TP->QCN+" tries to crawl into the gash "
            "in the shark's stomach, but the shark dodges aside!%^RESET%^", TP);
        TP->set_paralyzed(3, "You're trying to crawl inside the shark!");
        return 0;
    }

    tell_object(TP, "%^RED%^The shark tries in vain to dodge aside as you "
        "crawl into the gash in its stomach!%^RESET%^");
    tell_room(ETP, "%^RED%^The shark tries to dodge aside, but "+TP->QCN+" manages "
        "to crawl inside the gash in its stomach!%^RESET%^",TP);
    return 1;
}

int enter_gash_dead()
{
    tell_object(TP, "%^RED%^You wiggle your way into the gash in the "
        "cold remains of the dire shark!%^RESET%^");
    tell_room(ETP, "%^RED%^"+TP->QCN+" wiggles "+TP->QP+" way into "
        "the gash in the cold remains of the dire shark!%^RESET%^",TP);
    return 1;
}