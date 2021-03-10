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
"lig%^WHITE%^h%^YELLOW%^t %^RESET%^%^CYAN%^into the room.  At the western end of the room lies a single solidly closed "
"%^ORANGE%^door%^CYAN%^.  The rest of the room is bare except for two decorations, one of which is a long tapestry "
"upon the eastern wall that depicts an %^BOLD%^%^CYAN%^azu%^BLUE%^r%^CYAN%^e sk%^WHITE%^y%^CYAN%^sca%^RESET%^%^CYAN%^p"
"%^BOLD%^e %^RESET%^%^CYAN%^scattered with whisps of roiling cloud.  The other sits directly before it upon the floor; a "
"slender %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^CYAN%^incense holder, "
"which extends coiling arms into the air each holding a softly smoking stick.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The soft, sweet smell of %^MAGENTA%^c%^BOLD%^h%^WHITE%^er%^MAGENTA%^r%^RESET%^%^MAGENTA%^y bl%^BOLD%^o%^WHITE%^ss%^MAGENTA%^o%^RESET%^%^MAGENTA%^ms %^ORANGE%^wafts in from the %^GREEN%^gar%^ORANGE%^d%^GREEN%^en %^ORANGE%^beyond.%^RESET%^");
    set_listen("default","%^GREEN%^There is a comfortable %^CYAN%^si%^GREEN%^l%^CYAN%^en%^BOLD%^c%^RESET%^%^CYAN%^e %^GREEN%^to this place.%^RESET%^");

    set_items(([
      ({"floor","floor boards","floorboards"}) : "%^ORANGE%^Beneath your feet are smooth floorboards that spread the "
"length and breadth of the room.  No flaw or splinter can be seen or felt.  Judging by their worn surface, these boards "
"are regularly oiled and polished until they shine.%^RESET%^",
      ({"walls","slats","vertical slats"}) : "%^RED%^Polished wooden slats form a perfectly symmetrical border to this "
"chamber, interrupted at the top of the northern and southern walls by a short window.  A single door stands within the "
"western wall, while most of the east is covered by a single long tapestry.%^RESET%^",
      ({"window","windows"}) : "%^CYAN%^At the upper middle of the northern and southern walls lies a single short, broad "
"window.  Narrow slats form a frame to support ricepaper sheeting over each, which filters light into the room as a soft "
"illumination rather than a harsh glare.%^RESET%^",
      ({"door","doorframe"}) : "%^ORANGE%^To the west lies a sturdy wooden door, set within a frame as dark as the walls "
"around it.  No handle or other means of opening is readily apparent, leaving you to wonder if these perhaps slide or are "
"pushed.  You feel a sudden desire to touch the door.%^RESET%^",
      ({"tapestry"}) : "%^ORANGE%^A single tapestry takes up most of the eastern wall.  It is simple in design, depicting "
"an azure sky scattered with whisps of cloud.%^RESET%^",
      ({"holder","incense holder"}) : "%^YELLOW%^Sitting before the tapestry is a single slender incense holder that "
"reaches its coiling arms up in all directions.  Within each sits a single smoking stick, casting its light-scented "
"perfume into the air.%^RESET%^",
    ]));
}

void init() {
   ::init();
   if(!present("pavan")) find_object_or_load(MON"pavan")->move(TO);
   add_action("touch_fun","touch");
}

int touch_fun(string str) {
   if(!str) return 0;
   if(str != "door" && str != "the door") return 0;
   tell_object(TP,"%^ORANGE%^You reach out to touch the door, and you suddenly find yourself in the main chamber"
"!%^RESET%^");
   tell_room(TO,"%^ORANGE%^"+TP->QCN+" reaches out to touch the door, and suddenly vanishes!%^RESET%^",TP);
   TP->move_player(ROOMS"centre");
   return 1;
}