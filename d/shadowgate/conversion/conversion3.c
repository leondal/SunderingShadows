#include <std.h>
inherit ROOM;

void create()
{
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);

    set_name("beyond the haze");
    set_short("%^BOLD%^%^BLUE%^Beyond the Haze%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^Beyond the Haze%^RESET%^\n"+
        "%^BOLD%^%^CYAN%^With your soul housed once again within "+
        "a solid body, you feel yourself pulled down toward the "+
        "world.  The guiding presence that you have felt helping "+
        "you withdraws now, leaving the last choice to you.  "+
        "Where will you go to start your new life or pick up on "+
        "your old one?\n\n"+
        "%^YELLOW%^Please select one of the exits.  Please only "+
        "choose %^WHITE%^Offestry%^YELLOW%^ if you are under "+
        "level 7.  Thank you, and enjoy the new system.  Any "+
        "bugs, errors or issues, please report them via the "+
        "<bug> command, if no one is available to help you right "+
        "away.");

    set_smell("default","\nThere is nothing within the haze "+
        "to smell.");
    set_listen("default","You can hear nothing within the "+
        "haze.");

    set_exits(([ 
        "lothwaite"     : "/d/barriermnts/lothwaite/rooms/pathway20",
        "azha"          : "/d/azha/town/high1",
        "muileann"      : "/d/koenig/town/room1",
        "antioch"       : "/d/antioch/antioch2/rooms/street2",
        "verbobone"     : "/d/deku/town/road5",
        "daggerdale"    : "/d/dagger/Daggerdale/fountain/fountain",
        "shadow"        : "/d/shadow/city/room/plaza",
        "muuldaan"      : "/d/shadow/room/muuldaan/rooms/cavern1",
        "offestry"      : "/d/newbie/rooms/town/square",
        "kildare"       : "/d/shadow/room/kildare/rooms/ptrail1",
        "tonovi"        : "/d/dagger/tonovi/town/street5",
        "tabor"         : "/d/darkwood/tabor/room/cnchall",
        "kinaro"        : "/d/dagger/kinaro/guard3",
        "tharis"        : "/d/tharis/Tharis/main8",
        "asgard"        : "/d/laerad/parnelli/asgard/as08",
        "exchange"      : "/d/dagger/exchange/rooms/hallway",
        "juran"         : "/d/shadow/juran/city/quest_room",
        "seneca"        : "/d/attaya/newseneca/rooms/cath_nave",
        "torm"          : "/d/dagger/Torm/city/c45",
    ]));


    set_pre_exit_functions(({"out"}),({"GoThroughDoor"}));
 
    set_pre_exit_functions(({ "lothwaite","azha","muileann","antioch","verbobone","daggerdale","shadow",
        "muuldaan","offestry","kildare","tonovi","tabor","kinaro","tharis","asgard","exchange","juran",
        "seneca","torm" }),({"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor",
        "GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor",
        "GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor",
        "GoThroughDoor","GoThroughDoor"}));

}

int GoThroughDoor()
{
    string verb;
    if(!objectp(TP)) { return 1; }
    if(avatarp(TP)) { return 1; }

    verb = query_verb();

    if((int)TP->query_base_character_level() > 6 && verb == "offestry")
    {
        tell_object(TP,"Only newbies can take that exit.");
        return 0;
    }
    if((int)TP->query_base_character_level() < 6 && verb != "offestry")
    {
        tell_object(TP,"You are only allowed to use the offestry exit");
        return 0;
    }
    return 1;
}
    
