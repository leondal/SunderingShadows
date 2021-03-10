#include <std.h>
#include "../../arctic.h"

inherit CROOM;

void create()
{

    ::create();
    set_name("Ice Cave");
    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
    set_property("indoors", 1);
    set_property("light", 1);
    set_climate("arctic");
    
    
    set_short("%^BLUE%^Inside an icy cave.%^RESET%^");
        
    set_long( (: TO,"long" :) );
   
    set_items(([
                "ice" : "%^RESET%^%^BOLD%^The walls of the cave "
                "seem to be several feet of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
                "%^RESET%^%^BOLD%^covering the smooth gray stone of the mountain.%^RESET%^",
                
                ({"pool","pools","water"}) : "%^RESET%^%^BOLD%^"
                "Small %^RESET%^%^BLUE%^pools %^RESET%^%^BOLD%^of "
                "%^BLUE%^wat%^RESET%^e%^BLUE%^r %^RESET%^%^BOLD%^have "
                "been formed in places where the moisture has not "
                "been frozen.%^RESET%^",
                
                ({"stalagmite","stalagmites","stalactite","stalactites"}) : 
                "%^RESET%^%^BOLD%^Some of the stalagmites and "
                "stalactites are made only of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e, "
                "%^RESET%^%^BOLD%^while others are made of the smooth "
                "gray stone of the mountain.  Still others are "
                "stone covered with several inches of "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.%^RESET%^",
                
                ({"stone","granite","gray stone"}) : "%^RESET%^%^BOLD%^"
                "The smooth %^BOLD%^%^BLACK%^stone%^RESET%^%^BOLD%^ "
                "of the mountain cave can been seen through thin places in the "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.%^RESET%^",
                
                "icicles" : "%^RESET%^%^BOLD%^"
                "i%^RESET%^%^CYAN%^c%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^c"
                "%^RESET%^%^BOLD%^l%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^s "
                "cling to every possible vantage "
                "point.  Untold thousands of them, small to large, new "
                "to ancient, line the insides of the "
                "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^y "
                "%^RESET%^%^BOLD%^cave.",
                
                ({"crystals","light","glow"}) : "%^RESET%^%^BOLD%^"
                "Small crystals are imbedded in the stone of the "
                "mountain.  The crystals "
                "%^RESET%^%^BOLD%^g%^YELLOW%^lo%^RESET%^%^BOLD%^w "
                "very softly, allowing for normal vision in most places "
                "without another source of light.%^RESET%^",
                
                "cots" : "%^RESET%^%^BOLD%^These cots are gigantic, "
                "almost thirty feet in length.  Whatever sleeps on "
                "them must be very large indeed.%^RESET%^",

                "table" : "%^RESET%^%^BOLD%^The large table is covered "
                "with various giant sized dishes.  The top of the table "
                "is taller than an average man.  It is made from sturdy "
                "oak.%^RESET%^",

                "benches" : "%^RESET%^%^BOLD%^These heavy oak benches "
                "are almost six feet high and close to five feet wide.  "
                "They run the length of the table along either side.%^RESET%^",
             ]));                

    set_smell("default", "The scent of water and ice mix in the air.");
    set_listen("default", "Echoing splashes of water can be heard throughout the cave.");


    set_exits(([
        "north"         : LAIR"giants2",
        "south"         : CAVE"cave53",
             ]));
    new(MON"scout")->move(TO);
    new(MON"scout")->move(TO);
}


string long(string str){
    return("%^RESET%^%^BLUE%^The walls inside the frozen "
             "cave seem to be made of %^RESET%^%^BOLD%^solid "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.  "
             "%^RESET%^%^BLUE%^The air inside is not as cold as the "
             "f%^RESET%^r%^BLUE%^ig%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^d "
             "air outside and as a result, small "
             "pools of water have formed all about the floor.  "
             "%^RESET%^%^BOLD%^Stalagmites %^RESET%^%^BLUE%^"
             "and %^RESET%^%^BOLD%^stalactites %^RESET%^"
             "%^BLUE%^of both crystal clear "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
             "%^RESET%^%^BLUE%^and slick gray "
             "%^RESET%^%^BOLD%^stone %^RESET%^%^BLUE%^are in abundance "
             "while %^RESET%^%^BOLD%^"
             "i%^RESET%^%^CYAN%^c%^RESET%^%^BOLD%^i%^RESET%^%^BLUE%^c"
             "%^RESET%^%^BOLD%^l%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^s "
             "%^RESET%^%^BLUE%^hang from every place they can "
             "find purchase.  Here and there tiny "
             "%^RESET%^%^BOLD%^cr%^YELLOW%^yst%^RESET%^%^BOLD%^a"
             "%^BLUE%^l%^RESET%^%^BOLD%^s %^RESET%^%^BLUE%^"
             "inside the granite walls of the mountain "
             "give off a small amount of %^RESET%^light "
             "%^RESET%^%^BLUE%^that shines through the "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e.  "
             "%^RESET%^%^BLUE%^The walls of "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
             "%^RESET%^%^BLUE%^over the smooth "
             "stone of the mountain, along with the multitude of "
             "colors created by the "
             "%^RESET%^%^BOLD%^g%^YELLOW%^lo%^RESET%^%^BOLD%^w "
             "%^RESET%^%^BLUE%^from the "
             "%^RESET%^%^BOLD%^cr%^YELLOW%^yst%^RESET%^%^BOLD%^a"
             "%^BLUE%^l%^RESET%^%^BOLD%^s %^RESET%^%^BLUE%^"
             "shining through the various layers of "
             "%^RESET%^%^CYAN%^i%^RESET%^%^BOLD%^c%^RESET%^%^CYAN%^e "
             "%^RESET%^%^BLUE%^and the echoing sounds of dripping "
             "water lend the whole of the cavern "
             "a surreal atmosphere.  "
             "This room has been turned into a barracks for very "
             "large creatures.  There are some giant sized cots along "
             "the walls, and a large table with wooden benches sits "
             "in the center of the room.");
}

void reset()
{
    ::reset();
    if(present("giant")) return;
    if(!random(3))
    {   
        new(MON"scout")->move(TO);
        new(MON"scout")->move(TO);
    }
    return;
}