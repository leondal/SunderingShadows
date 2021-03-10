#include <std.h>
#include <daemons.h>
#include "area_stuff.h"

#define TOMB_DELAY 14400;

#define NORTH_OCEAN_ROOMS ({"166", "167", "168", "169", "170", "171", "172", "173", "174", "175", "176", "177", "178"})
#define WEST_OCEAN_ROOMS ({"1", "15", "30", "45", "60", "75", "90", "105", "120", "135", "150", "165"})
#define EAST_OCEAN_ROOMS ({"14", "29", "44", "59", "74", "89", "104", "119", "134", "149", "164"})
#define SOUTH_OCEAN_ROOMS ({"6", "7", "8", "9"})
#define NORTHEAST_OCEAN_ROOMS ({"165"})
#define NORTHWEST_OCEAN_ROOMS ({"179"})

#define SOUTH_STONE ({"1", "2", "3", "4", "5", "10", "11", "12", "13", "14", "165", "166", "167", "168", "169", "170", "171", "172", "175", "176", "177", "178", "179",\
                      "135", "136", "137", "138", "139", "140", "141", "142"})

#define NORTH_SOUTH_STONE ({"60", "61", "62", "63", "64", "65", "66", "66", "67", "68", "69", "70", "71", "72", "72", "73", "74", "75", "76", "77", "78", "79",\
                            "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100",\
                            "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111", "112", "115", "117", "118", "119",\
                            "120", "121", "122", "123", "124", "125", "126", "127", "130", "131", "132", "133", "134", "144", "145", "146", "147", "148", "149",\
                            "160", "161", "162", "163", "164"})
                            
#define NORTH_STONE ({"45", "46", "47","48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59",\
                      "150", "151", "152", "153", "154", "155", "156", "157"})
                      
#define TOMB_ROOMS ({"158", "146", "113", "68"})
                      
#define NORTH_SOUTH_EAST_STONE ({"113", "128"})

#define WEST_SOUTH_STONE ({"174"})

#define EAST_SOUTH_STONE ({"173", "143"})

#define NORTH_EAST_STONE ({"158"})

#define NORTH_SOUTH_WEST_STONE ({"144", "114", "129", "159"})

#define SOUTH_GAP_STONE ({"1", "14", "62", "79", "103", "109", "116", "121", "129", "141", "147", "159", "167", "177"})

#define NORTH_GAP_STONE ({"47", "64", "88", "94", "101", "106", "114", "126", "132", "152", "144", "162"})

#define DUNE_ROOMS ({"51", "102", "178", "107"})

inherit CROOM;

string clong, tomb_symbol, leads_to;
int tomb_room, gap_string, portal_active = 0;
string base_long();

void populate_area()
{
    if(base_name(TO) != ELINH) 
    { 
        switch(random(30)) 
        {
            case 0..3:
                set_monsters(({}), ({}));
                break;
            case 4..6:
                set_monsters( ({ELMON+"storm_elemental"}), ({1 + random(2)}) );
                break;
            case 7..10:
                set_monsters( ({ELMON+"crazed_nomad", ELMON+"crazed_knight"}), ({3 + random(4), 2 + random(3)}) );
                break;      			
            case 11:
                set_monsters( ({ELMON+"rogue"}), ({1}) );
                break;
            case 12..15:
                set_monsters( ({ELMON+"ettin", ELMON+"desert_worm"}), ({2 + random(3), 1}));
                break;
            case 16..18:
                set_monsters(({ELMON+"desert_hydra", ELMON+"crazed_nomad"}), ({1, 2 + random(3)}));
                break;
            case 19..22:
                set_monsters(({ELMON+"crazed_knight", ELMON+"desert_wyvern"}), ({2 + random(3), 1 + random(2)}));
                break;
            case 23..24:
                set_monsters(({ELMON+"desert_hydra", ELMON+"rogue"}), ({1 + random(2), 1}));
                break;
            case 25..26:
                set_monsters(({ELMON+"crazed_nomad", ELMON+"desert_worm", ELMON+"desert_wyvern"}), ({3 + random(4), 1, 1}));
                break;
            case 27..29:
                set_monsters(({ELMON+"desert_ogre", ELMON+"ettin"}), ({3 + random(4), 1 + random(2)}));
                break;
        }
        set_repop(5 + random(16) + random(16));   
    }    
}

string cloud_desc()
{
    string current_location, ret;
    current_location = RUNEPLACE->get_current_location();
    ret = "%^BOLD%^%^BLACK%^The clouds "+
        "that hang over the island look nightmarish. Simply looking up at them you get a terrible feeling in "+
        "the pit of your stomach. It is as if there is a storm of apocalyptic proportions hanging just over the "+
        "horizon. It seems like something is keeping it at bay, at least for the time being, but you are "+
        "unsure of what or for how long that will last.%^RESET%^";
    
    if(stringp(current_location))
    {
        if(current_location != "" && current_location != "NIL")
        {
            ret += "%^BOLD%^%^BLACK%^ Bolts of %^BOLD%^%^YELLOW%^lightning%^BOLD%^%^BLACK%^"+
            " zap toward "+current_location+"!%^RESET%^";
        }
    }
    return ret;
}

void create()
{
    if(!random(4)) populate_area();
    ::create();
	set_property("light",2);
	set_property("indoors",0);
    set_climate("desert");
    set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
    set_name("A vast sandscape");
    set_short("%^RESET%^%^ORANGE%^A vast s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^");
    

    set_listen("default", "%^CYAN%^\nThe loud slapping of water echoes all around you "
        "here, as the winds continue to increase in ferocity.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA tranquil odor from the sea assaults you and mixes "
        "with something else that you are not quite able to discern.%^RESET%^");

    set_items(([
        ({"trees", "palm trees", "broken trees", "uprooted trees"}) : "%^BOLD%^%^GREEN%^"+
        "These once vibrant palm trees are now blown around violently and chaotically in the wind. "+
        "Only very few of them are not either uprooted or broken over as they have failed to withstand "+
        "the vicious onslaught of the ever increasing wind.%^RESET%^",
        
        ({"sandscape", "vast sandscape", "sand", "wet sand", "thick sand"}) : "%^RESET%^%^ORANGE%^"+
        "The sandscape stretches out before you. The sand of which it is composed is very thick and wet, as "+
        "if a recent torrential storm drenched the entire island. Or perhaps most of it was actually "+
        "under water until recently. It is impossible to tell, however, the heavy storm clouds that hang "+
        "over the island suggest that soon there may be a torrential storm the likes of which you have "+
        "never before seen.%^RESET%^", 
        
        ({"storm", "clouds", "storm clouds", "heavy storm clouds"}) : (:TO, "cloud_desc":),
        
        ({"dunes", "sand dunes", "rolling dunes", "rolling sand dunes", "dune"}) : "%^BOLD%^%^YELLOW%^The sand dunes "+
        "are moved about constantly by the chaotic and violent wind. Some of them are much larger than others, but most "+
        "of them are quite small and not difficult to traverse at all.%^RESET%^",
    ]));
    
    clong = "";
    base_long();
    set_long( (: TO, "base_long" :) );
    return;
}

void init()
{
    ::init();
    add_action("say_function","say");
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
    if(!stringp(leads_to))
    {
        tell_room(TO, "Something is wrong with the portal destination... notify Saide");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^With some trepidation you step through the portal and "+
    "find yourself in a hallway made of interlocked %^BOLD%^%^BLACK%^ebon stones%^BOLD%^%^WHITE%^!%^RESET%^");
    
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ steps through the portal!%^RESET%^", TP);
    
    TP->move_player(leads_to);
    return 1;
}

int say_function(string str) 
{
    object ob;
    string myostr;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if((string)TP->query("last say") == str) 
    {
        return 0;
    }
    if(!tomb_room || !stringp(leads_to)) return 0;
    if(portal_active) return 0;
    myostr = str;
    str = lower_case(str);
    if(strsrch(str, "asantra show me the way") != -1)
    {
        if(!objectp(ob = present("dreadhorn_xxx_horn", TP))) return 0;        
        portal_active = 1;
        if(objectp(ob)) ob->remove();
        TP->force_me("say "+myostr);
        tell_object(TP, "%^BOLD%^%^BLACK%^At the completion of your phrase the dreadhorn turns to dust in your hands!%^RESET%^");               
        tell_room(TO, "%^BOLD%^%^WHITE%^A %^BOLD%^%^CYAN%^mysterious portal%^BOLD%^%^WHITE%^ flares to life within "+
        "the archway!%^RESET%^");
        add_item(({"portal", "mysterious portal"}), "%^BOLD%^%^CYAN%^This mysterious portal flares brilliantly within "+
        "the archway. It appears to lead into a hallway composed of interlocked %^BOLD%^%^BLACK%^ebon stones%^BOLD%^%^CYAN%^"+
        ". You believe that you could <%^BOLD%^%^WHITE%^enter%^BOLD%^%^CYAN%^> it if you wanted.%^RESET%^");
        clong = "";
        return 1;
    }
    return 1;
}

void close_portal()
{
    if(!objectp(TO)) return;
    tell_room(TO, "%^BOLD%^%^CYAN%^The portal in the archway wavers and then abruptly closes!%^RESET%^");
    remove_item(({"portal", "mysterious portal"}));
    portal_active = 0;
    clong = "";
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
        SAVE_D->remove_aray("eldebaro_south_tomb_exit");
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
            SAVE_D->remove_aray("eldebaro_south_tomb_exit");
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
    if(base_name(TO) == ELROOMSD + nt_exit)
    {
        tomb_symbol = "%^BOLD%^%^WHITE%^'%^BOLD%^%^CYAN%^N%^BOLD%^%^WHITE%^'%^RESET%^";
        if(leads_to != nt_enter) 
        {
            if(portal_active) close_portal();
            leads_to = nt_enter;
        }       
    }
    else if(base_name(TO) == ELROOMSD + st_exit)
    {
        tomb_symbol = "%^BOLD%^%^WHITE%^'%^BOLD%^%^CYAN%^S%^BOLD%^%^WHITE%^'%^RESET%^";
        if(leads_to != st_enter) 
        {
            if(portal_active) close_portal();
            leads_to = st_enter;
        }  
    }
    else if(base_name(TO) == ELROOMSD + et_exit)
    {
        tomb_symbol = "%^BOLD%^%^WHITE%^'%^BOLD%^%^CYAN%^E%^BOLD%^%^WHITE%^'%^RESET%^";
        if(leads_to != et_enter) 
        {
            if(portal_active) close_portal();
            leads_to = et_enter;
        }  
    }
    else if(base_name(TO) == ELROOMSD + wt_exit)
    {
        tomb_symbol = "%^BOLD%^%^WHITE%^'%^BOLD%^%^CYAN%^W%^BOLD%^%^WHITE%^'%^RESET%^";
        if(leads_to != wt_enter) 
        {
            if(portal_active) close_portal();
            leads_to = wt_enter;
        }  
    }    
}

string archway_desc()
{
    string res;
    check_tombs();
    res = "%^BOLD%^%^BLACK%^A strange archway is carved into one of the stones here. Above the archway is "+
    "a symbol that vaguely looks like "+tomb_symbol+".%^RESET%^";
    if(portal_active)
    {
        res += "%^BOLD%^%^BLACK%^ A portal flares to life inside the archway. You could <%^BOLD%^%^CYAN%^enter"+
            "%^BOLD%^%^BLACK%^> it if you wanted to. It appears to lead to a hallway composed of similar stones "+
            "interlocking with one another.%^RESET%^";
    }
    return res;
}

string query_stone_desc()
{
    string ret;
    if(!objectp(TO)) { return "something this room is not a valid object. Notify saide"; }
    if(gap_string != "") 
    {
        ret = "%^BOLD%^%^BLACK%^Th massive stones tower upward in the "+
        "sky, they are covered with strange %^BOLD%^%^CYAN%^symbols%^BOLD%^%^BLACK%^ which look very "+
        "ancient. They look as if they have only recently been unearthed. A gap in them allows passage to the "+
        gap_string+".%^RESET%^";
    }
    else
    {           
        ret = "%^BOLD%^%^BLACK%^Th massive stones tower upward in the "+
        "sky, they are dark and covered with strange %^BOLD%^%^CYAN%^symbols%^BOLD%^%^BLACK%^ which look very "+
        "ancient. They look as if they have only recently been unearthed.%^RESET%^";
    }
    if(tomb_room) 
    {
        check_tombs();
        ret += "%^BOLD%^%^BLACK%^ You notice a strange archway carved into one of the stones. Above the archway is "+
        "a symbol that vaguely looks like "+tomb_symbol+".%^RESET%^";
        if(portal_active)
        {
            ret += "%^BOLD%^%^BLACK%^ A portal flares to life inside the archway. You could <%^BOLD%^%^CYAN%^enter"+
            "%^BOLD%^%^BLACK%^> it if you wanted to. It appears to lead to a hallway composed of similar stones "+
            "interlocking with one another.%^RESET%^";
        }
    }
    return ret;
}

string base_long()
{
    string str, extra, room, dir_string;
    if(stringp(clong) && clong != "") return clong;
    if(!objectp(TO)) { return "Somehow this room is not a valid object. Notify Saide"; }
    
    room  = base_name(TO);
    room  = replace_string(room,ELROOMSD,"");
    if(member_array(room, DUNE_ROOMS) != -1) 
    {
        str = "%^ORANGE%^A vast s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ "+
        "stretches out before you. The sand is %^BOLD%^%^BLACK%^"+
        "dark%^RESET%^%^ORANGE%^ and wet making it difficult to walk through. There are rolling %^BOLD%^"+
        "sand dunes%^RESET%^%^ORANGE%^ which never stay in the same place for long, as the wind here is "+
        "increasing v%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
        "n%^BOLD%^%^MAGENTA%^t%^RESET%^%^ORANGE%^ and ch%^BOLD%^%^BLACK%^ao%^BOLD%^%^WHITE%^tic%^RESET%^%^ORANGE%^, "+
        "and causes them to shift continually. However, there is one much larger %^BOLD%^sand dune%^RESET%^%^ORANGE%^"+
        " here which stands out. In fact, the wind almost seems"+
        " as if something or someone is controlling it. Judging by the cl%^BOLD%^%^WHITE%^ou%^RESET%^%^ORANGE%^ds "+
        "hanging heavily over the island it looks like a st%^BOLD%^%^YELLOW%^o%^RESET%^%^ORANGE%^rm "+
        "of %^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^"+
        "l%^BOLD%^%^BLACK%^y%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^ "+
        "proportions is just over the horizon. There are many %^BOLD%^palm trees%^RESET%^%^ORANGE%^ "+
        "dotting the s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^, "+
        "and they are blowing about crazily in the wind. Some of them have actually been uprooted and many of the ones that "+
        "remain standing are br%^BOLD%^o%^RESET%^%^ORANGE%^k%^BOLD%^e%^RESET%^%^ORANGE%^n over.\n\n"+
        "%^RESET%^%^ORANGE%^A %^BOLD%^%^RED%^large sand dune%^RESET%^%^ORANGE%^ rises out of the desert above the others here.";
        add_item(({"dunes", "dune", "sand dunes", "rolling dunes", "rolling sand dunes", "large sand dune"}), 
        "%^BOLD%^%^YELLOW%^The sand dunes "+
        "are moved about constantly by the chaotic and violent wind. One of them looks much larger and much more "+
        "solid. As if perhaps it has gathered either on top of something else. You think that you could "+
        "climb it and see what is on top, if you were so inclined.%^RESET%^");
        set_short("%^BOLD%^%^RED%^Giant Sand Dune%^RESET%^");
    }    
    else 
    {
        str = "%^ORANGE%^A vast s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ "+
        "stretches out before you. The sand is %^BOLD%^%^BLACK%^"+
        "dark%^RESET%^%^ORANGE%^ and wet making it difficult to walk through. There are rolling %^BOLD%^"+
        "sand dunes%^RESET%^%^ORANGE%^ which never stay in the same place for long, as the wind here is "+
        "increasing v%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^o%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
        "n%^BOLD%^%^MAGENTA%^t%^RESET%^%^ORANGE%^ and ch%^BOLD%^%^BLACK%^ao%^BOLD%^%^WHITE%^tic%^RESET%^%^ORANGE%^, "+
        "and causes them to shift continually. In fact, the wind almost seems"+
        " as if something or someone is controlling it. Judging by the cl%^BOLD%^%^WHITE%^ou%^RESET%^%^ORANGE%^ds "+
        "hanging heavily over the island it looks like a st%^BOLD%^%^YELLOW%^o%^RESET%^%^ORANGE%^rm "+
        "of %^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^"+
        "l%^BOLD%^%^BLACK%^y%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^ "+
        "proportions is just over the horizon. There are many %^BOLD%^palm trees%^RESET%^%^ORANGE%^ "+
        "dotting the s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^, "+
        "and they are blowing about crazily in the wind. Some of them have actually been uprooted and many of the ones that "+
        "remain standing are br%^BOLD%^o%^RESET%^%^ORANGE%^k%^BOLD%^e%^RESET%^%^ORANGE%^n over.";
    }    
    clong = str;   
    if(!random(4)) set_property("no teleport", 1);
    extra = "";
    dir_string = "";
    gap_string = "";
    
    
    if(member_array(room, SOUTH_STONE) != -1) { dir_string = "south"; }
    else if(member_array(room, NORTH_STONE) != -1) { dir_string = "north"; }
    else if(member_array(room, NORTH_SOUTH_STONE) != -1) { dir_string = "north and south"; }
    else if(member_array(room, NORTH_SOUTH_EAST_STONE) != -1) { dir_string = "north, south, and east"; }
    else if(member_array(room, NORTH_SOUTH_WEST_STONE) != -1) { dir_string = "north, south, and west"; }
    else if(member_array(room, WEST_SOUTH_STONE) != -1) { dir_string = "south and west"; }
    else if(member_array(room, EAST_SOUTH_STONE) != -1) { dir_string = "east and south"; }
    else if(member_array(room, NORTH_EAST_STONE) != -1) { dir_string = "north and east"; }
 
    if(member_array(room, SOUTH_GAP_STONE) != -1) { gap_string = "south"; }
    else if(member_array(room, NORTH_GAP_STONE) != -1) { gap_string = "north"; }
    if(member_array(room, TOMB_ROOMS) != -1) tomb_room = 1;
    if(dir_string != "")
    {
        extra = "%^RESET%^%^ORANGE%^ Massive %^BOLD%^%^BLACK%^ebon%^RESET%^%^ORANGE%^ stones tower upward here to the "+dir_string+". They are covered with "+
        "strange %^BOLD%^%^CYAN%^symbols%^RESET%^%^ORANGE%^ which look very ancient.";
        if(gap_string != "")
        {
            extra += "%^RESET%^%^ORANGE%^ A gap in them allows passage to the "+gap_string+".%^RESET%^";
           
        }
        if(tomb_room) 
        {
            clong += "\n\n%^BOLD%^%^RED%^An ancient archway%^RESET%^%^ORANGE%^ stands oddly intact here amongst the stones.%^RESET%^";
            set_short("%^BOLD%^%^RED%^An %^BLACK%^Ancient%^RED%^ Archway%^RESET%^");
            add_item(({"archway", "strange archway"}), (:TO, "archway_desc":));
            if(portal_active)
            {
                extra += "%^RESET%^%^ORANGE%^ A portal flares to life inside an archway in the stones.%^RESET%^";
            }
        }
        add_item(({"stones", "massive stones", "towering stones", "symbols", "ebon stones"}), (:TO, "query_stone_desc":));
        clong += extra;
    }
    
    dir_string = "";
    extra = "";
    
    
    if(member_array(room, NORTH_OCEAN_ROOMS) != -1) { dir_string = "north"; }
    else if(member_array(room, WEST_OCEAN_ROOMS) != -1) { dir_string = "west"; }
    else if(member_array(room, EAST_OCEAN_ROOMS) != -1) { dir_string = "east"; }
    else if(member_array(room, SOUTH_OCEAN_ROOMS) != -1) { dir_string = "south"; }
    else if(member_array(room, NORTHEAST_OCEAN_ROOMS) != -1) { dir_string = "north and east"; }
    else if(member_array(room, NORTHWEST_OCEAN_ROOMS) != -1) { dir_string = "north and west"; }
    else dir_string = "";
    
    if(dir_string != "") 
    {
        extra = " %^RESET%^%^ORANGE%^The forboding ocean collides v%^BOLD%^%^MAGENTA%^i%^RESET%^"+
        "%^MAGENTA%^o%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
        "n%^BOLD%^%^MAGENTA%^tl%^RESET%^%^ORANGE%^y with the s%^BOLD%^a%^RESET%^%^ORANGE%^"+
        "ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ to the "+dir_string+"%^RESET%^.\n";
        clong += extra;
    }    
    return clong;
}

void reset()
{
    ::reset();
    RUNEPLACE->place_rune(TO);
    if(tomb_room) check_tombs();
    if(!random(6)) populate_area();
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}
