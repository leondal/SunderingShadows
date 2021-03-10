#include <std.h>
#include "../arctic.h"
#include "../cracks.h"

inherit UNDERWATER;

void break_ice();
int climb_out();
void freeze();
void make_creatures();

int broken;
int breaking = random(7)+1;
int x;


void create()
{
    make_creatures();
    set_repop(50);

    ::create();
    set_name("Under the Lake");
    set_property("indoors", 1);
    set_property("light", 1);
    set_property("no teleport", random(2));
    set_terrain(DEEP_WATER);
    set_travel(RUTTED_TRACK);
    set_climate("arctic");
    
    set_short("%^BLUE%^In the %^BOLD%^i%^CYAN%^c%^BOLD%^y%^BLUE%^ water%^RESET%^");

    set_long("%^BLUE%^The frigid water is unbearably cold.  "
             "The ice above you appears solid, and there "
             "seems to be no way back to the surface from here.  "
             "Debris floats in the water in various places, "
             "and fish of all sizes swim quickly around.%^RESET%^");
    
    set_items(([ 
             "water" : "%^BLUE%^The icy water is all around, "
             "if you can't breathe underwater, you might be "
             "in trouble.%^RESET%^",
             "ice" : "%^CYAN%^The %^BOLD%^i%^BLUE%^c%^BOLD%^e%^CYAN%^ "
             "appears solid above you, but perhaps you can break "
             "it if you try.%^RESET%^",
             "surface" : "%^BOLD%^You can still see some light "
             "making its way through the ice from the surface.%^RESET%^",
             "debris" : "Debris hangs in the waters of the lake, some "
             "floating, some frozen in the ice.",
             ]));


    set_smell("default", "You can't smell anything.");
    set_listen("default", "The bubbling echo of water fills your ears.");
    
    set_exits(([
        "up" : ROOMS"uw",
        "out" : ROOMS"uw",
             ]));

}


void break_ice()
{
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    
    if(broken) return;
    x = TP->query_stats("strength");
    if(random(x) > random(20)) x = 1; else x = 0;
    
    if(x == 1)
    {
        breaking -= 1;
        
        if(breaking > 0)
        {
            tell_object(TP,"%^BOLD%^The ice pops and groans as you "
                "try to break through!%^RESET%^");
            tell_room(TO,"%^BOLD%^The ice pops and groans as "+TPQCN+" tries "
                "to break through.%^RESET%^",TP);
            remove_item("ice");
            add_item("ice", "%^CYAN%^The %^BOLD%^i%^BLUE%^c%^BOLD%^e%^CYAN%^ "
                "has several cracks in it.  It won't take much more to break "
                "it.%^RESET%^");
            TP->set_paralyzed(random(6)+5, "You are trying to break through the ice.");
            return;
        }
        tell_object(TP,"%^BOLD%^You smash through the ice and can see "
            "the sweet air of the surface!%^RESET%^");
        tell_room(TO,"%^BOLD%^"+TPQCN+" smashes through the ice and "
            "you can see the surface!%^RESET%^",TP);
        remove_item("ice");
        add_item("ice", "%^CYAN%^The %^BOLD%^i%^BLUE%^c%^BOLD%^e%^CYAN%^ "
            "is broken and there is a hole leading to the surface!.%^RESET%^");
        add_item("hole", "%^CYAN%^The hole looks quite slippery and difficult "
            "to climb, but it leads straight to the surface!.%^RESET%^");
        add_exit(CRACKS[base_name(TO)], "hole");
        set_pre_exit_functions(({"hole"}),({"climb_out"}));
        broken = 1;
        return 1;
    }
    
    if(x == 0)
    {
        tell_object(TP,"%^BOLD%^You smash against the ice but it doesn't "
            "seem to have any effect.%^RESET%^");
        tell_room(TO,"%^BOLD%^"+TPQCN+" smashes against the ice but it doesn't "
            "seem to have an effect.%^RESET%^",TP);
        TP->set_paralyzed(random(6)+5, "You are trying to break through the ice.");
        return;
    }

}

int climb_out()
{
    x = TP->query_stats("dexterity");
    if(random(x) > random(10))
    {
        tell_object(TP,"%^BOLD%^You scramble out of the frigid water and "
            "back to the surface!%^RESET%^");
        tell_room(TO,"%^BOLD%^"+TPQCN+" quickly scrambles out of the "
            "frigid water and back to the surface!%^RESET%^",TP);
        TP->move_player(CRACKS[base_name(TO)]);
        return 0;
    }
    tell_object(TP,"%^BOLD%^You lose your grip on the slippery "
        "ice and plunge back into the frigid water!%^RESET%^");
    tell_room(TO,"%^BOLD%^"+TPQCN+" loses " +TP->QP+ " grip on "
        "the ice and falls back into the water!%^RESET%^",TP);
    return 0;
}

void freeze()
{
    if(broken)
    {
        remove_pre_exit_function("hole");
        remove_exit("hole");
        remove_item("hole");
        remove_item("ice");
        remove_exit("hole");
        add_item("ice", "%^CYAN%^The %^BOLD%^i%^BLUE%^c%^BOLD%^e%^CYAN%^ "
             "appears solid above you, but perhaps you can break "
             "it if you try.%^RESET%^");
        broken = 0;
        breaking = random(7)+1;
        return;
    }
    return;
}

void reset()
{
    ::reset();
    if(!random(3)) freeze();
    return;
}



void init()
{
    ::init();
    if(member_array("hole", TO->query_exits()))
    {
        add_action("break_ice","break");
        return;
    }
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
            set_monsters( ({MON"fish.c"}),({ random(3) }) );
        }
    }
    return;
}