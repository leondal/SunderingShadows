#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",1);
    set_terrain(CITY);
    set_travel(FOOT_PATH);
    set_property("training",1);
    set_short("%^RESET%^%^MAGENTA%^C%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^mf%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^rtable %^MAGENTA%^room%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^C%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^mf%^BOLD%^%^WHITE%^o%^RESET%^%^MAGENTA%^rtable %^MAGENTA%^room%^RESET%^
%^RESET%^%^BLUE%^This is a comfortable room. The %^MAGENTA%^wall%^BOLD%^%^WHITE%^s%^RESET%^%^BLUE%^ are lined with red %^RED%^carpe%^ORANGE%^t%^RED%^s%^BLUE%^ and golden accents. In a recessed wall is a soft feather-down %^MAGENTA%^bed.%^BLUE%^ Nightstands sit at either side of it, and a large %^MAGENTA%^chest%^BLUE%^ beckons you from the foot of the bed. An ornate carpet covers the floor. Several logs lie in a stand by the fireplace, yet, you cannot imagine when it would be cold enough to need them!%^RESET%^");

     set_smell("default","A soft breeze carries through the room the scent of Hibiscus flowers.");
 
    set_exits(([

      "south" : "/d/attaya/seneca4",

    ] ));
    set_items(([
    "bed" : "The soft feather-down bed is remarkably comfortable.  It has been made recently.",
    "chest" : "It cannot be unlocked, and it is too heavy to lift.",
    "walls" : "They have been lavishly decorated as if for a king.",
"nightstands" : "They are made of mahogany.  Nothing useful on top of them or in the drawers.",
    "carpets" : "The beautiful hand-woven carpet is from a nearby island.",
    ] ));
}
