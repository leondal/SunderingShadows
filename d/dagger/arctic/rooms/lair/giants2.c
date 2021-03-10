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

                "table" : "%^RESET%^%^BOLD%^The large, round table sits "
                "roughly in the center of the room.  It is covered with "
                "several maps and a few large wooden cups.%^RESET%^",

                "chairs" : "%^RESET%^%^BOLD%^These are very large, but "
                "simple chairs made from oak.  The backs are made from "
                "what appears to be yeti hides.%^RESET%^",

                "cups" : "%^RESET%^%^BOLD%^The strong smell of ale come "
                "from some of the large wooden cups, coffee from others.%^RESET%^",

                "maps" : "%^RESET%^%^BOLD%^There are several maps.  Some "
                "are of the cave and surrounding mountains.  Others are "
                "of the terrain around the dagger region and as far south "
                "as the city of Shadow.  You get the impression that "
                "this is a scout post for a larger group.%^RESET%^",
             ]));                
    
    set_smell("default", "The scent of water and ice mix in the air.");
    set_listen("default", "Echoing splashes of water can be heard throughout the cave.");


    set_exits(([
        "south"         : LAIR"giants1",
             ]));
    if(!present("scout leader") && !present("giant shaman"))
    {   
        new(MON"scout_leader")->move(TO);
        new(MON"giant_shaman")->move(TO);
    }
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
             "This seems to be a command post of sorts.  A round table "
             "covered with various maps sits in the center of the room.  "
             "A few very large chairs sit around the table.%^RESET%^");
}



void reset()
{
    ::reset();
    if(present("scout leader") || present("giant shaman")) return;
    if(!random(5))
    {   
        new(MON"scout_leader")->move(TO);
        new(MON"giant_shaman")->move(TO);
    }
    return;
}
