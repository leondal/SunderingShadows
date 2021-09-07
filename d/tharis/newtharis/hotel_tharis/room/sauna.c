// Chernobog (9/6/21)
// Tharis Hotel

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
    set_name("The Grand Suite");
    set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^e G%^RESET%^%^MAGENTA%^ran%^BOLD%^%^BLACK%^d S%^RESET%^%^MAGENTA%^uit%^BOLD%^%^BLACK%^e%^RESET%^");
    set_long("This small room is entirely constructed from %^ORANGE%^cedar%^WHITE%^. There is a %^ORANGE%^bench %^WHITE%^that spans the length of the far wall and some %^BOLD%^towels %^RESET%^hanging from a %^BOLD%^%^BLACK%^hook %^RESET%^near the entrance. A %^ORANGE%^lever %^WHITE%^protrudes from the wall.\n");
    set_smell("default","It smells humid and moist in here.");
    set_listen("default","There is an odd mix of dripping water and muffled curses.");
    set_items(([
        "hatch" : "%^RESET%^Cracking the %^ORANGE%^hatch %^WHITE%^open, you see a small chamber surrounded by a circle of odd %^CYAN%^s%^BOLD%^y%^RESET%^%^CYAN%^m%^BOLD%^b%^BLACK%^o%^CYAN%^l%^RESET%^%^CYAN%^s %^WHITE%^and %^CYAN%^g%^BOLD%^l%^BLACK%^y%^CYAN%^p%^RESET%^%^CYAN%^hs%^WHITE%^. Within the barrier is a grumbling %^BOLD%^%^BLACK%^st%^RESET%^e%^BOLD%^a%^BLACK%^m m%^RESET%^e%^BOLD%^%^BLACK%^ph%^WHITE%^i%^BLACK%^t%^RESET%^, obviously %^RED%^d%^BOLD%^i%^RESET%^%^RED%^str%^BOLD%^e%^RESET%^%^RED%^ssed %^WHITE%^at its captivity.%^RESET%^",
        "towels" : "A set of %^BOLD%^towels %^RESET%^hangs near the %^ORANGE%^door%^WHITE%^. They are %^BOLD%^pristine white%^RESET%^, thick and incredibly soft to the touch.",
        "lever" : "%^RESET%^There is a %^ORANGE%^wooden lever %^WHITE%^here, with directions to pull it to operate the sauna. It is seated beneath an odd %^ORANGE%^wooden hatch%^RESET%^.",
        "mephit" : "Bound within a circle of %^CYAN%^str%^BOLD%^a%^BLACK%^n%^CYAN%^g%^RESET%^%^CYAN%^e r%^BOLD%^u%^BLACK%^n%^CYAN%^e%^RESET%^%^CYAN%^s%^WHITE%^, this %^BOLD%^%^BLACK%^i%^RESET%^m%^BOLD%^%^BLACK%^p%^RESET%^-like %^BOLD%^%^BLACK%^cr%^RESET%^e%^BOLD%^a%^BLACK%^t%^RESET%^u%^BOLD%^%^BLACK%^r%^WHITE%^e %^RESET%^lurks in obvious %^RED%^ag%^BOLD%^i%^RESET%^%^RED%^t%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^io%^RESET%^%^RED%^n%^WHITE%^. Sp%^BOLD%^%^BLACK%^i%^RESET%^ndly arms and legs propel it as it scurries around the confines of its %^ORANGE%^prison%^WHITE%^, desperately seeking a way out.",
        ]));
    set_exits(([
        "bathroom" : ROOMS "bathroom",
        ]));
    set_door("wooden door", ROOMS "bathroom", "bathroom", 0);
	set_door_description("wooden door","%^RESET%^%^ORANGE%^This is a thick wooden door, crafted entirely from cedar.%^RESET%^");
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
        "and the room fills with wonderfully warm and delightful %^RESET%^st%^BOLD%^e"+
        "%^RESET%^a%^BOLD%^m%^BLACK%^.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^BLACK%^As "+TP->QCN+"%^BOLD%^%^BLACK%^ pulls the "+
        "%^RESET%^%^ORANGE%^lever%^BOLD%^%^BLACK%^, you hear a faint, but sharp, "+
        "%^RESET%^%^RED%^curse %^BOLD%^%^BLACK%^from behind a small %^RESET%^"+
        "%^ORANGE%^hatch%^BOLD%^%^BLACK%^... and the room fills with wonderful, warm"+
        ", and delightful %^RESET%^st%^BOLD%^e%^RESET%^a%^BOLD%^m%^BLACK%^."+
        "%^RESET%^",TP);
    return 1;
}

