#include <std.h>
#include "../arctic.h"

inherit UNDERWATER;

void make_creatures();

void create()
{
    make_creatures();
    set_repop(50);

    ::create();
    set_name("Under the Lake");
    set_property("indoors", 1);
    set_property("light", 0);
    set_property("no teleport", random(2));
    set_terrain(DEEP_WATER);
    set_travel(RUTTED_TRACK);
    set_climate("arctic");
   
    
    set_short("%^BLUE%^Deep in the icy water%^RESET%^");
        
    set_long("%^BLUE%^The frigid water is unbearably cold.  "
             "The ice above you appears solid, It is darker "
             "here, this far away from the light of the surface.  "
             "The pressure of the water squeezes against your "
             "skin.  The center of the lake is deeper, and the "
             "water down there looks dark and foreboding.%^RESET%^");
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
      "out"   : ROOMS"uwb",
           ]));

}

int say_func(string str)
{
    if(!TP->query_true_invis())
    {
        tell_object(TP,"You open your mouth to speak and many bubbles escape.  "
            "You realize it will be impossible to speak underwater.");
        tell_room(ETP,""+TP->QCN+" opens "+TP->QP+" mouth as if to speak and "
            "many bubbles come out instead.",TP);
        return 1;
    }
    return 0;
}

void init()
{
    ::init();
    add_action("say_func", "say");
    return;
}

void make_creatures()
{
    int monsters;
    monsters = has_mobs();
    if(!random(2))
    {
        if(!monsters) 
        {
            if(mons) { mons = ([]); }
            set_monsters( ({MON"fish.c"}),({ random(2)+1 }) );
        }
    }
    return;
}
