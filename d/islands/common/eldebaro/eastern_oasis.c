#include <std.h>
#include <daemons.h>
#include "area_stuff.h"

#define WEST_OCEAN_ROOMS ({"13", "14"})
#define EAST_OCEAN_ROOMS ({"1", "2"})
#define SOUTH_OCEAN_ROOMS ({"4", "9", "10"})
#define SOUTH_EAST_OCEAN_ROOMS ({"3"})
#define SOUTH_WEST_OCEAN_ROOMS ({"15"})
          
#define NORTH_STONE ({"13", "12", "7", "6", "1"})
                   
#define NORTH_GAP_STONE ({"1"})
#define TENT_ROOMS ({"6", "5", "4", "9", "7", "10", "11", "12", "15", "14", "8", "3", "13"})
#define SPRING_ROOMS ({"8"})
inherit CROOM;

string clong, gap_string;

string base_long();

void populate_area()
{
    if(base_name(TO) != EASTOASIS) 
    { 
        switch(random(7)) 
        {
            case 0..3:
                set_monsters(({ELMON+"oasis_guard"}), ({3 + random(4)}));
                monster_party(50);
                set_repop(45);  
                break;
            case 4..6:
                break;
        }         
    }    
}

string cloud_desc()
{
    string current_location, ret;
    current_location = RUNEPLACE->get_current_location();
    ret = "%^BOLD%^%^BLACK%^The clouds "+
        "that hang over the island look nightmarish. Simply looking up at them you get a terribly feeling in "+
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
    if(!random(2)) populate_area();
    ::create();
	set_property("light",2);
	set_property("indoors",0);
    set_climate("desert");
    set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
    set_name("Eastern oasis");
    
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis%^RESET%^");

    set_listen("default", "%^CYAN%^\nThe slapping of water echoes all around you "
        "here.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA tranquil odor from the sea assaults you and mixes "
        "with something else that you are not quite able to discern.%^RESET%^");

    set_items(([
        ({"trees", "palm trees"}) : "%^BOLD%^%^GREEN%^"+
        "These vibrant palm trees dot the sandscape here. They offer some measure of shade to weary "+
        "travelers as well as to the new growth which spreads slowly across the sandscape.%^RESET%^",
        
        ({"vegetation", "new growth", "new vegetation"}) : "%^BOLD%^%^GREEN%^"+
        "Most of this is rather course grass, but there are a few small shrubs mixed in as well. "+
        "It is sporadic, but it appears to be slowly spreading across the sandscape.%^RESET%^",
        
        ({"sandscape", "vast sandscape", "sand"}) : "%^RESET%^%^ORANGE%^"+
        "The sandscape stretches out before you. In this area the sand is much finer and mostly dry. "+
        "It is much calmer here, as if something is somehow managing to hold the violent and chaotic winds "+
        "at bay.%^RESET%^", 
        
        ({"storm", "clouds", "storm clouds", "heavy storm clouds"}) : (:TO, "cloud_desc":),
        
        ({"dunes", "sand dunes", "dune"}) : "%^BOLD%^%^YELLOW%^The sand dunes "+
        "here are much smaller and easier to traverse. They do not move about nearly as often since the "+
        "wind is mostly calm.%^RESET%^",
    ]));
    
    clong = "";
    base_long();
    set_long( (: TO,"base_long" :) );
    return;
}

string base_long()
{
    string str, extra, room, dir_string;
    if(stringp(clong) && clong != "") return clong;
    if(!objectp(TO)) { return "Somehow this room is not a valid object. Notify Saide"; }
    
    room  = base_name(TO);
    room  = replace_string(room,ELROOMSE,"");
    
    
    str = "%^ORANGE%^The vast s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ "+
    "here is different. The most striking difference that you notice right off is that the wind here seems to be somehow "+
    "held at bay. It still blows around you but no where near as v%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^o%^BOLD%^"+
    "%^RED%^l%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^MAGENTA%^t%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^y%^RESET%^%^ORANGE%^. "+
    "The only dunes are much smaller and much easier to traverse. Amazingly you also notice that there is some "+
    "%^BOLD%^%^GREEN%^new vegetation%^RESET%^%^ORANGE%^ growing here, it is small and sporadic, but it appears to be "+
    "spreading across the s%^BOLD%^a%^RESET%^%^ORANGE%^ndsc%^BOLD%^a%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^ slowly. "+
    "There are several %^BOLD%^%^GREEN%^palm trees%^RESET%^%^ORANGE%^ which also offer shade to travelers and "+
    "to the %^BOLD%^%^GREEN%^new growth%^RESET%^%^ORANGE%^. The sky is still ominous. Despite the fact that something is managing "+
    "to keep the winds at bay here you can still see what looks to be a st%^BOLD%^%^YELLOW%^o%^RESET%^%^ORANGE%^rm "+
    "of %^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^"+
    "l%^BOLD%^%^BLACK%^y%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^ "+
    "proportions just over the horizon.%^RESET%^";   
 
    clong = str;   
    extra = "";
    dir_string = "";
    gap_string = "";
    
    
    if(member_array(room, NORTH_STONE) != -1) { dir_string = "south"; }
 
    if(member_array(room, NORTH_GAP_STONE) != -1) { gap_string = "north"; }
        
    if(dir_string != "")
    {
        extra = "%^RESET%^%^ORANGE%^ Massive %^BOLD%^%^BLACK%^ebon%^RESET%^%^ORANGE%^ stones tower upward here to the "+dir_string+". They are covered with "+
        "strange %^BOLD%^%^CYAN%^symbols%^RESET%^%^ORANGE%^ which look very ancient.";
        if(gap_string != "")
        {
            extra += "%^RESET%^%^ORANGE%^ A gap in them allows passage to the "+gap_string+".%^RESET%^";
           
        }
        clong += extra;
    }
    if(member_array(room, SPRING_ROOMS) != -1)
    {
        clong += "%^RESET%^%^ORANGE%^ A large %^BOLD%^%^CYAN%^spring%^RESET%^%^ORANGE%^ bubbles up to the surface and spills "+
        "out here before being absorbed by the sand. A large %^BOLD%^%^BLACK%^metal grate%^RESET%^%^ORANGE%^ has been "+
        "fitted over the top of it. You believe it is to keep people out of it or perhaps it is to prevent anyone "+
        "from accidentally falling into it. A very thick and heavy tent has been set up here just next to the spring. It appears "+
        "much grander than the others in the area, as it is made from multipled colors of materials all stitched together "+
        "flawlessly.%^RESET%^";
        
        add_item(({"tent", "heavy tent", "thick tent", "thick and heavy tent", "grand tent"}), "%^RESET%^%^ORANGE%^This large tent "+
        "stands out amongst the rest of the those in the area. It is not much larger, if at all, but it composed of multiple colors of "+
        "materials that are all stitched together flawlessly. Right above the entrance to it, embroidered into the material is the name "+
        "'%^CYAN%^Dyveryll Wyndar%^RESET%^%^ORANGE%^'.%^RESET%^");
        add_item(({"spring", "bubbling spring", "grate", "metal grate"}), "%^BOLD%^%^CYAN%^This large spring bubbles up to the surface "+
        "and spills out here before it is absorbed by the sand. A large metal grate has been fitted over the top of it. It looks "+
        "very heavy and very solid. You are not sure what purpose it serves but it is likely either intended to keep people out "+
        "or perhaps to prevent anyone from accidentally falling into it. You can not tell how deep it is from looking but judging by how "+
        "dark the water becomes the bottom may very well meet with the ocean.%^RESET%^");

    }
    else if(member_array(room, TENT_ROOMS) != -1) 
    {
        clong += "%^RESET%^%^ORANGE%^ A very thick and heavy tent has been set up here to serve as a makeshift shelter of some kind.%^RESET%^";
        add_item(({"tent", "heavy tent", "thick tent", "thick and heavy tent"}), "%^RESET%^%^ORANGE%^This large tent has been sewn from a "+
        "very thick material. It has been coated with a thick and malleable substance to help protect it from the elements. It almost creates a "+
        "square, that is approximately fifty feet on each side. It is set up here as a makeshift shelter of some type.%^RESET%^");
    }   
    
    dir_string = "";
    extra = "";   
    if(member_array(room, WEST_OCEAN_ROOMS) != -1) { dir_string = "west"; }
    else if(member_array(room, EAST_OCEAN_ROOMS) != -1) { dir_string = "east"; }
    else if(member_array(room, SOUTH_OCEAN_ROOMS) != -1) { dir_string = "south"; }
    else if(member_array(room, SOUTH_EAST_OCEAN_ROOMS) != -1) { dir_string = "south and east"; }
    else if(member_array(room, SOUTH_WEST_OCEAN_ROOMS) != -1) { dir_string = "south and west"; }
    else dir_string = "";
    
    if(dir_string != "") 
    {
        extra = " %^RESET%^%^ORANGE%^The ocean collides much less violently here with "+
        "the s%^BOLD%^a%^RESET%^%^ORANGE%^nd to the "+dir_string+"%^RESET%^.\n";
        clong += extra;
    }
    return clong;
}

void reset()
{
    ::reset();
    RUNEPLACE->place_rune(TO);
    if(!random(2)) populate_area();
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}
