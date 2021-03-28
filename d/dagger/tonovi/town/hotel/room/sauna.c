// Chernobog (1/23/21)
// Tonovi Hotel

#include <std.h>
#include "../defs.h"
inherit VAULT;

int steaming;

void create(){
    steaming = 0;
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("The Duchal Suite");
    set_short("%^YELLOW%^T%^RESET%^%^ORANGE%^h%^BOLD%^e D%^RESET%^%^ORANGE%^u%^BOLD%^"+
        "%^BLACK%^ch%^RESET%^%^ORANGE%^a%^BOLD%^l S%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^"+
        "i%^RESET%^%^ORANGE%^t%^BOLD%^e%^RESET%^");
    set_long("%^RESET%^This small room is entirely contructed from %^ORANGE%^cedar"+
        "%^WHITE%^. There is a small bench on the far wall to take a seat, and some "+
        "%^YELLOW%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^we%^RESET%^%^ORANGE%^l"+
        "%^BOLD%^s %^RESET%^hanging nearby on the wall. An odd %^ORANGE%^lever "+
        "%^WHITE%^protrudes from the wall.\n");
    set_smell("default","It smells humid and moist in here.");
    set_listen("default","There is an odd mix of dripping water and muffled curses.");
    set_items(([
        "hatch" : "%^RESET%^%^CYAN%^Cracking the %^ORANGE%^hatch %^CYAN%^open, you see "+
            "a small chamber surrounded by a circle of odd %^BOLD%^%^BLACK%^s%^RESET%^y"+
            "%^BOLD%^mbo%^RESET%^l%^BOLD%^%^BLACK%^s %^RESET%^%^CYAN%^and %^ORANGE%^g"+
            "%^BOLD%^l%^WHITE%^y%^ORANGE%^ph%^RESET%^%^ORANGE%^s%^CYAN%^. Within the "+
            "barrier is a grumbing %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^%^BLACK%^e"+
            "%^RESET%^a%^BOLD%^m %^RESET%^m%^BOLD%^ep%^RESET%^h%^BOLD%^%^BLACK%^i"+
            "%^RESET%^t%^CYAN%^, obviously distressed at its captivity.%^RESET%^",
        "towels" : "%^RESET%^%^CYAN%^A set of %^YELLOW%^t%^RESET%^%^ORANGE%^o%^BOLD%^"+
            "%^BLACK%^we%^RESET%^%^ORANGE%^l%^BOLD%^s %^RESET%^%^CYAN%^hangs on a bar "+
            "attached to the wall. They are %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^"+
            "with %^ORANGE%^g%^BOLD%^o%^WHITE%^l%^ORANGE%^de%^RESET%^%^ORANGE%^n "+
            "%^CYAN%^accents, a common color scheme within the hotel.%^RESET%^",
        "lever" : "%^RESET%^%^CYAN%^There is a %^ORANGE%^wooden lever %^CYAN%^here, "+
            "with directions to %^BOLD%^pull %^RESET%^%^CYAN%^it to operate the sauna. "+
            "It is seated beneath an odd %^ORANGE%^wooden hatch%^CYAN%^.%^RESET%^",
        "mephit" : "%^RESET%^%^CYAN%^Bound within a circle of %^BOLD%^s%^GREEN%^t"+
            "%^CYAN%^r%^GREEN%^a%^CYAN%^n%^GREEN%^g%^CYAN%^e r%^GREEN%^u%^CYAN%^n"+
            "%^GREEN%^e%^CYAN%^s%^RESET%^%^CYAN%^, this %^BOLD%^%^WHITE%^i%^RESET%^m"+
            "%^BOLD%^p%^BLACK%^-%^WHITE%^l%^RESET%^i%^BOLD%^%^BLACK%^k%^WHITE%^e c"+
            "%^RESET%^r%^BOLD%^%^BLACK%^e%^WHITE%^a%^RESET%^t%^BOLD%^u%^RESET%^r"+
            "%^BOLD%^e %^RESET%^%^CYAN%^lurks in obvious agitation. Spindly arms and "+
            "legs propel it as it scurries around the circumference of its prison, "+
            "desperately seeking a way %^RED%^out%^CYAN%^.%^RESET%^",
        ]));
    set_exits(([
        "bathroom" : ROOMS "bathroom",
        ]));
    set_door("wooden door", ROOMS "bathroom", "bathroom", 0);
	set_door_description("wooden door","%^RESET%^%^CYAN%^This is a simple %^ORANGE%^"+
        "wooden door%^CYAN%^, crafted from %^ORANGE%^oaken planks%^CYAN%^.%^RESET%^");
}

void init(){
    ::init();
    add_action("pull_fun","pull");
}

int pull_fun(str){
    if(str!="lever"){
        write("You might try to pull the lever.");
        return 0;
    }
    tell_object(TP,"%^BOLD%^%^BLACK%^As you pull the %^RESET%^%^ORANGE%^lever%^BOLD%^"+
        "%^BLACK%^, you hear a faint, but sharp, %^RESET%^%^RED%^curse %^BOLD%^"+
        "%^BLACK%^from behind a small %^RESET%^%^ORANGE%^hatch%^BOLD%^%^BLACK%^... "+
        "and the room fills will wonderful, warm, and delightful %^RESET%^st%^BOLD%^e"+
        "%^RESET%^a%^BOLD%^m%^BLACK%^.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^BLACK%^As "+TP->QCN+"%^BOLD%^%^BLACK%^ pulls the "+
        "%^RESET%^%^ORANGE%^lever%^BOLD%^%^BLACK%^, you hear a faint, but sharp, "+
        "%^RESET%^%^RED%^curse %^BOLD%^%^BLACK%^from behind a small %^RESET%^"+
        "%^ORANGE%^hatch%^BOLD%^%^BLACK%^... and the room fills with wonderful, warm"+
        ", and delightful %^RESET%^st%^BOLD%^e%^RESET%^a%^BOLD%^m%^BLACK%^."+
        "%^RESET%^",TP);
    return 1;
}

