#include <std.h>
#include <daemons.h>
#include "area_stuff.h"
#define TOMB_ROOMS ({"158", "146", "113", "68"})
inherit CROOM;

string leads_to;
int portal_active;
void check_tombs();

void populate_area()
{
    if(base_name(TO) != TOMBHALL) 
    { 
        switch(random(11)) 
        {
            case 0..3:
                set_monsters(({}), ({}));
                break;
            case 4..6:
                set_monsters( ({ELMON+"twisted_figure"}), ({3 + random(4)}) );
                break;
            case 7..10:
                set_monsters( ({ELMON+"twisted_figure"}), ({2 + random(3)}) );
                break;      			
        }
        set_repop(35);   
    }    
}

void create()
{
    populate_area();
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_property("no teleport", 1);
    set_property("scry proof", 1);
    set_climate("arctic");
    set_name("Inside an ebon hall");
    set_short("%^BOLD%^%^BLACK%^Inside a %^BOLD%^%^CYAN%^fr%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^g"+
    "%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^d%^BOLD%^%^BLACK%^ ebon hall%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^You find yourself in a hallway composed of interlocked "+
    "%^BOLD%^%^WHITE%^ebon stones%^BOLD%^%^BLACK%^. The very first thing that you notice here is that "+
    "it is freezing. A bitter %^BOLD%^%^CYAN%^cold%^BOLD%^%^BLACK%^ and %^BOLD%^%^CYAN%^frigid%^BOLD%^"+
    "%^BLACK%^ air hangs heavily in here, almost as if it has been somehow trapped by the %^BOLD%^%^WHITE%^"+
    "stones%^BOLD%^%^BLACK%^ or perhaps it is radiating outward from them. The hall looks ancient, as if "+
    "it were from some other time and place, yet it seems so sturdy that no amount of time would ever "+
    "have the power to erode it. It is huge, large enough for giants to easily move about with "+
    "enough room for possibly an entire army of them to walk through the hall. A strange "+
    "%^BOLD%^%^WHITE%^darkness%^BOLD%^%^BLACK%^ cloaks the edges of the hall and something "+
    "deep within you almost screams in utter terror at the sight of it, though you are unable "+
    "to explain it and manage to will yourself to remain steady.%^RESET%^");
    
    set_listen("default", "%^CYAN%^\nYour footsteps echo through the hall and loud "+
    "cracking sounds are heard all around you.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThis place smells ancient and an odor of stagnation hangs "+
    "heavily here.%^RESET%^");

    set_items(([
        ({"hall", "stones", "ebon stones", "walls", "ceiling", "floor"}) : "%^BOLD%^%^BLACK%^This hall is massive and "+
        "composed entirely of interlocked ebon stones. The floor, the ceiling, and the walls are composed of these "+
        "same stones. Each is giving "+
        "off a %^BOLD%^%^WHITE%^freezing cold aura%^BOLD%^%^BLACK%^, which chills the entire hall. The hall "+
        "looks ancient but seems so sturdy that not even time would be enough to erode the stones which compose "+
        "it.%^RESET%^",
        
        ({"darkness", "utter darkness"}) : "%^BOLD%^%^BLACK%^This darkness stirs something within "+
        "you, something almost primordial. A raw and utter terror almost awakens deep within you but "+
        "you have no explanation for it and are able to will yourself to remain steady.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    
    set_property("traps_known_to_monsters", ELMON);
    set_property("random trap frequency", 20);
    set_property("random traps", "epic");
    portal_active = 0;
    leads_to = 0;
    check_tombs();
    return;
}

void check_tombs()
{
    string nt_enter, st_enter, et_enter, wt_enter, nt_exit, st_exit, et_exit, wt_exit;
    string *tmp, *tombs;
    int delay;
    tombs = TOMB_ROOMS;
   
    st_enter = ELROOMST + "3_1";
    nt_enter = ELROOMST + "1_1";
    et_enter = ELROOMST + "2_1";
    wt_enter = ELROOMST + "4_1";
    //SAVE_D->query_array(array)
    //SAVE_D->set_value(array, value)
    //SAVE_D->remove_array(array);
    
    if(!pointerp(tmp = SAVE_D->query_array("eldebaro_tomb_delay")) || !sizeof(tmp))
    {
        st_exit = tombs[random(sizeof(tombs))];
        tombs -= ({st_exit});
        SAVE_D->remove_array("eldebaro_south_tomb_location");
        SAVE_D->remove_array("eldebaro_tomb_delay");
        SAVE_D->remove_array("eldebaro_south_tomb_exit");
        SAVE_D->set_value("eldebaro_south_tomb_location", st_exit);
        SAVE_D->set_value("eldebaro_south_tomb_exit", st_enter);
        
        nt_exit = tombs[random(sizeof(tombs))];
        tombs -= ({nt_exit});
        SAVE_D->remove_array("eldebaro_north_tomb_location");
        SAVE_D->remove_array("eldebaro_north_tomb_exit");
        SAVE_D->set_value("eldebaro_north_tomb_location", nt_exit);
        SAVE_D->set_value("eldebaro_north_tomb_exit", nt_enter);
        
        et_exit = tombs[random(sizeof(tombs))];
        tombs -= ({et_exit});
        SAVE_D->remove_array("eldebaro_east_tomb_location");
        SAVE_D->remove_array("eldebaro_east_tomb_exit");
        SAVE_D->set_value("eldebaro_east_tomb_location", et_exit);
        SAVE_D->set_value("eldebaro_east_tomb_exit", et_enter);
        
        wt_exit = tombs[random(sizeof(tombs))];
        tombs -= ({wt_exit});
        SAVE_D->remove_array("eldebaro_west_tomb_location");
        SAVE_D->remove_array("eldebaro_west_tomb_exit");
        SAVE_D->set_value("eldebaro_west_tomb_location", wt_exit);
        SAVE_D->set_value("eldebaro_west_tomb_exit", wt_enter);
        SAVE_D->set_value("eldebaro_tomb_delay", (time() + 14400));
    }
    else if(pointerp(tmp) && sizeof(tmp))
    {      
        if(time() > to_int(tmp[0]))
        {
            st_exit = tombs[random(sizeof(tombs))];
            tombs -= ({st_exit});
            SAVE_D->remove_array("eldebaro_south_tomb_location");
            SAVE_D->remove_array("eldebaro_tomb_delay");
            SAVE_D->remove_array("eldebaro_south_tomb_exit");
            SAVE_D->set_value("eldebaro_south_tomb_location", st_exit);
            SAVE_D->set_value("eldebaro_south_tomb_exit", st_enter);
        
            nt_exit = tombs[random(sizeof(tombs))];
            tombs -= ({nt_exit});
            SAVE_D->remove_array("eldebaro_north_tomb_location");
            SAVE_D->remove_array("eldebaro_north_tomb_exit");
            SAVE_D->set_value("eldebaro_north_tomb_location", nt_exit);
            SAVE_D->set_value("eldebaro_north_tomb_exit", nt_enter);
        
            et_exit = tombs[random(sizeof(tombs))];
            tombs -= ({et_exit});
            SAVE_D->remove_array("eldebaro_east_tomb_location");
            SAVE_D->remove_array("eldebaro_east_tomb_exit");
            SAVE_D->set_value("eldebaro_east_tomb_location", et_exit);
            SAVE_D->set_value("eldebaro_east_tomb_exit", et_enter);
        
            wt_exit = tombs[random(sizeof(tombs))];
            tombs -= ({wt_exit});
            SAVE_D->remove_array("eldebaro_west_tomb_location");
            SAVE_D->remove_array("eldebaro_west_tomb_exit");
            SAVE_D->set_value("eldebaro_west_tomb_location", wt_exit);
            SAVE_D->set_value("eldebaro_west_tomb_exit", wt_enter);
                
            SAVE_D->set_value("eldebaro_tomb_delay", (time() + 14400));                   
        }
    }
    if(!stringp(nt_exit)) { tmp = SAVE_D->query_array("eldebaro_north_tomb_location"); nt_exit = tmp[0]; }
    if(!stringp(et_exit)) { tmp = SAVE_D->query_array("eldebaro_east_tomb_location"); et_exit = tmp[0]; }
    if(!stringp(wt_exit)) { tmp = SAVE_D->query_array("eldebaro_west_tomb_location"); wt_exit = tmp[0]; }
    if(!stringp(st_exit)) { tmp = SAVE_D->query_array("eldebaro_south_tomb_location"); st_exit = tmp[0]; }
    if(base_name(TO) == nt_enter)
    {           
        leads_to = ELROOMSD + nt_exit;
    }
    else if(base_name(TO) == st_enter)
    {
        leads_to = ELROOMSD + st_exit;
    }
    else if(base_name(TO) == et_enter)
    {
        leads_to = ELROOMSD + et_exit;
    }
    else if(base_name(TO) == wt_enter)
    {
        leads_to = ELROOMSD + wt_exit;
    }    
    if(stringp(leads_to) && !portal_active)
    {
        add_item(({"portal", "mysterious portal"}), "%^BOLD%^%^CYAN%^A mysterious portal flares to life in "+
        "the center of the hallway here. It appears to lead to a %^RESET%^%^ORANGE%^vast s%^BOLD%^a"+
        "%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^.%^BOLD%^%^CYAN%^ You "+
        "could <%^BOLD%^%^WHITE%^enter%^BOLD%^%^CYAN%^> it if you wanted.%^RESET%^");
        TO->set_long(TO->query_long() + "%^BOLD%^%^BLACK%^ A %^BOLD%^%^CYAN%^mysterious portal%^BOLD%^%^BLACK%^ "+
        "flares to life in the center of the hallway here.%^RESET%^");
        portal_active = 1;
    }
}

void init()
{
    ::init();
    add_action("enter_function", "enter");
}

int enter_function(string str)
{
    object ob;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if (TP->query_bound() || 
    TP->query_unconscious() || 
    TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if(!stringp(str)) return 0;
    if(str != "portal" && str != "mysterious portal") return 0;
    if(!portal_active) return 0;
    check_tombs();
    if(!stringp(leads_to))
    {
        tell_room(TO, "Something is wrong with the portal destination... notify Saide");
        return 1;
    }
    
    tell_object(TP, "%^BOLD%^%^WHITE%^You step through the portal and "+
    "find yourself in a %^RESET%^%^ORANGE%^vast s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^BOLD%^%^WHITE%^!%^RESET%^");
    
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ steps through the portal!%^RESET%^", TP);
    
    TP->move_player(leads_to);
    return 1;
}


string query_weather()
{
    return "\n%^BOLD%^%^CYAN%^A frigid cold hangs heavily here.%^RESET%^";
}

void reset()
{
    ::reset();
    populate_area();
}