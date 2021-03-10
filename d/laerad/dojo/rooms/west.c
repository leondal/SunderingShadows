#include <std.h>
#include "../dojo.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("The eastern chamber of a wooden dojo hall");
    set_short("%^RESET%^%^RED%^The eastern chamber of a wooden dojo hall%^RESET%^");
    set_long("%^CYAN%^This chamber is almost as austere as the main one from which you have come. %^ORANGE%^Poli%^RED%^sh"
"%^ORANGE%^ed wooden floorboards %^CYAN%^that run the length and breadth of the room, bordered upon all sides with "
"vertical slats that have been oiled to a %^RED%^da%^ORANGE%^r%^RED%^k and rich fi%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^ish"
"%^CYAN%^.  At either side of the room, near the roof, small %^BOLD%^win%^WHITE%^d%^CYAN%^ows %^RESET%^%^CYAN%^are "
"broken up by narrow slats and sheeted with %^RESET%^ricepaper%^CYAN%^, permitting a soft and steady stream of %^YELLOW%^"
"lig%^WHITE%^h%^YELLOW%^t %^RESET%^%^CYAN%^into the room.  At the eastern end of the room lies a single solidly closed "
"%^ORANGE%^door%^CYAN%^.  The rest of the room is bareexcept for two decorations, one of which is long tapestry upon the "
"western wall that depicts a gentle pool fed by the %^BOLD%^%^BLUE%^tumbl%^CYAN%^i%^BLUE%^ng f%^RESET%^%^BLUE%^l%^BOLD%^"
"ow %^RESET%^%^CYAN%^of a waterfall.  The other sits directly before it upon the floor; a smooth and gleaming bowl that "
"holds a full measure of %^BLUE%^water %^CYAN%^in motionless tranquility.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The soft, sweet smell of %^MAGENTA%^c%^BOLD%^h%^WHITE%^er%^MAGENTA%^r%^RESET%^%^MAGENTA%^y bl%^BOLD%^o%^WHITE%^ss%^MAGENTA%^o%^RESET%^%^MAGENTA%^ms %^ORANGE%^wafts in from the %^GREEN%^gar%^ORANGE%^d%^GREEN%^en %^ORANGE%^beyond.%^RESET%^");
    set_listen("default","%^GREEN%^There is a comfortable %^CYAN%^si%^GREEN%^l%^CYAN%^en%^BOLD%^c%^RESET%^%^CYAN%^e %^GREEN%^to this place.%^RESET%^");

    set_items(([
      ({"floor","floor boards","floorboards"}) : "%^ORANGE%^Beneath your feet are smooth floorboards that spread the "
"length and breadth of the room.  No flaw or splinter can be seen or felt.  Judging by their worn surface, these boards "
"are regularly oiled and polished until they shine.%^RESET%^",
      ({"walls","slats","vertical slats"}) : "%^RED%^Polished wooden slats form a perfectly symmetrical border to this "
"chamber, interrupted at the top of the northern and southern walls by a short window.  A single door stands within the "
"eastern wall, while most of the west is covered by a single long tapestry.%^RESET%^",
      ({"window","windows"}) : "%^CYAN%^At the upper middle of the northern and southern walls lies a single short, broad "
"window.  Narrow slats form a frame to support ricepaper sheeting over each, which filters light into the room as a soft "
"illumination rather than a harsh glare.%^RESET%^",
      ({"door","doorframe"}) : "%^ORANGE%^To the east lies a sturdy wooden door, set within a frame as dark as the walls "
"around it.  No handle or other means of opening is readily apparent, leaving you to wonder if these perhaps slide or are "
"pushed.  You feel a sudden desire to touch the door.%^RESET%^",
      ({"tapestry"}) : "%^CYAN%^A single tapestry takes up most of the western wall.  It is simple in design, depicting "
"a gentle pool fed by the tumbling flow of a waterfall.%^RESET%^",
      ({"bowl","water"}) : "%^BLUE%^Sitting before the tapestry is a smooth silver bowl, within which lies an undisturbed "
"surface of clear water that reaches nearly to its rim.%^RESET%^",
    ]));
}

void init() {
   ::init();
   if(!present("jala")) find_object_or_load(MON"jala")->move(TO);
   add_action("touch_fun","touch");
}

int touch_fun(string str) {
   if(!str) return 0;
   if(str != "door" && str != "the door") return 0;
   tell_object(TP,"%^CYAN%^You reach out to touch the door, and you suddenly find yourself in the main chamber!%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TP->QCN+" reaches out to touch the door, and suddenly vanishes!%^RESET%^",TP);
   TP->move_player(ROOMS"centre");
   return 1;
}