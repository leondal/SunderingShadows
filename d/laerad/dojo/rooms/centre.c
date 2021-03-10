#include <std.h>
#include "../dojo.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("The central chamber of a wooden dojo hall");
    set_short("%^RESET%^%^ORANGE%^The central chamber of a wooden dojo hall%^RESET%^");
    set_long("%^CYAN%^Leading up from a depression that forms the entry to the building in the southwest, a small step "
"flattens out into a raised level of %^ORANGE%^poli%^RED%^sh%^ORANGE%^ed wooden floorboards %^CYAN%^that run the length "
"and breadth of this room.  The vast chamber is walled upon four sides with vertical slats, all of which have been oiled "
"to a %^RED%^da%^ORANGE%^r%^RED%^k and rich fi%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^ish%^CYAN%^.  At the upper middle of "
"each wall lies a short, broad %^BOLD%^win%^WHITE%^d%^CYAN%^ow %^RESET%^%^CYAN%^broken up by narrow slats and sheeted "
"with %^RESET%^ricepaper%^CYAN%^, permitting a soft and steady stream of %^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^RESET%^"
"%^CYAN%^into the room.  Beneath each window lies a solidly closed %^ORANGE%^door%^CYAN%^, marked with a single "
"%^RED%^ch%^ORANGE%^ar%^GREEN%^ac%^BLUE%^te%^MAGENTA%^r %^CYAN%^in a different coloration.  The rest of the room is "
"starkly austere, except for a %^RED%^spiral staircase %^CYAN%^leading upwards from the centre of the room, and a "
"%^ORANGE%^tatami mat %^CYAN%^settled beside it at the base.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The soft, sweet smell of %^MAGENTA%^c%^BOLD%^h%^WHITE%^er%^MAGENTA%^r%^RESET%^%^MAGENTA%^y bl%^BOLD%^o%^WHITE%^ss%^MAGENTA%^o%^RESET%^%^MAGENTA%^ms %^ORANGE%^wafts in from the %^GREEN%^gar%^ORANGE%^d%^GREEN%^en %^ORANGE%^beyond.%^RESET%^");
    set_listen("default","%^GREEN%^There is a comfortable %^CYAN%^si%^GREEN%^l%^CYAN%^en%^BOLD%^c%^RESET%^%^CYAN%^e %^GREEN%^to this place.%^RESET%^");

    set_items(([
      ({"floor","floor boards","floorboards"}) : "%^ORANGE%^Beneath your feet are smooth floorboards that spread the "
"length and breadth of the room.  No flaw or splinter can be seen or felt.  Judging by their worn surface, these boards "
"are regularly oiled and polished until they shine.  A depression steps down from the raised floorboards to ground level "
"in the southwest, where lies an exit to the building.%^RESET%^",
      ({"walls","slats","vertical slats"}) : "%^RED%^Polished wooden slats form a perfectly symmetrical border to this "
"chamber, interrupted at each of the cardinal points by a solid doorframe and a short window above.  A sliding door "
"sheeted with ricepaper offers an exit to the building in the southwest, where a depression steps down from the raised "
"floorboards to ground level.%^RESET%^",
      ({"window","windows"}) : "%^CYAN%^At the upper middle of each wall lies a single short, broad window.  Narrow slats "
"form a frame to support ricepaper sheeting over each, which filters light into the room as a soft illumination rather "
"than a harsh glare.%^RESET%^",
      ({"door","doors","doorframe","doorframes","door frames","character","characters"}) : "%^ORANGE%^At each of the four "
"cardinal points to the north, south, east and west, lies a sturdy wooden door, set within a frame as dark as the walls "
"around it.  No handle or other means of opening is readily apparent, leaving you to wonder if these perhaps slide or are "
"pushed.  Upon each, a single character is marked in a different color.%^RESET%^",
      ({"stairs","staircase","spiral staircase"}) : "%^RED%^A spiral staircase serves as the centrepoint of the chamber.  "
"Open stairs bordered by a railing of wooden struts lead upwards to what appears to be only a very small area "
"above.%^RESET%^",
      ({"mat","tatami","tatami mat"}) : "%^ORANGE%^At the foot of the stairs lies a simple tatami mat, made of woven "
"rushes and with a narrow edge of cloth.  It is much softer beneath the feet than the rest of the solid wooden "
"floorboards.%^RESET%^",
      ({"north door","northern door","south door","southern door","east door","eastern door","west door","western door"}) : (:TO,"door_desc":),
    ]));
    set_exits(([
      "southwest" : ROOMS"garden",
      "up" : ROOMS"stairs",
    ]));
    set_door("sliding door",ROOMS+"garden","southwest",0);
    set_door_description("sliding door","%^ORANGE%^A foot beyond the depression in the floorboards to the southwest lies "
"a sliding door, usually closed against the outside world.  From its sturdy frame extend a multitude of slats that criss-"
"cross their way to the opposite side, forming a support for the ricepaper that lies in a sheet across its surface.  A "
"small indentation near its closing point allows one to slide it open or shut at will.%^RESET%^");
    set_string("sliding door","open","%^ORANGE%^The door slides silently open upon well-oiled tracks.%^RESET%^");
    set_string("sliding door","close","%^ORANGE%^The door slides shut without a sound.%^RESET%^");
}

string door_desc(string str) {
   if((int)TP->query_skill("academics") > 25) {
     switch(str) {
       case "north door": case "northern door":
       return("%^GREEN%^The northern door is as solid as its three companions, differing only in the single character "
"marked in vibrant emerald upon its surface.  You recognize the character as an ancient symbol for %^BOLD%^earth%^RESET%^"
"%^GREEN%^.%^RESET%^");
       break;
       case "south door": case "southern door":
       return("%^RED%^The southern door is as solid as its three companions, differing only in the single character "
"marked in deep crimson upon its surface.  You recognize the character as an ancient symbol for %^BOLD%^fire%^RESET%^"
"%^RED%^.%^RESET%^");
       break;
       case "east door": case "eastern door":
       return("%^ORANGE%^The eastern door is as solid as its three companions, differing only in the single character "
"marked in golden yellow upon its surface.  You recognize the character as an ancient symbol for %^BOLD%^air%^RESET%^"
"%^ORANGE%^.%^RESET%^");
       break;
       case "west door": case "western door":
       return("%^BLUE%^The western door is as solid as its three companions, differing only in the single character "
"marked in vivid azure upon its surface.  You recognize the character as an ancient symbol for %^BOLD%^water%^RESET%^"
"%^BLUE%^.%^RESET%^");
       break;
     }
   }
   switch(str) {
     case "north door": case "northern door":
     return("%^GREEN%^The northern door is as solid as its three companions, differing only in the single character "
"marked in vibrant emerald upon its surface.  The character is unfamiliar to you, leaving you to wonder about its meaning"
".%^RESET%^");
     break;
     case "south door": case "southern door":
   return("%^RED%^The southern door is as solid as its three companions, differing only in the single character marked in "
"deep crimson upon its surface.  The character is unfamiliar to you, leaving you to wonder about its meaning.%^RESET%^");
     break;
     case "east door": case "eastern door":
     return("%^ORANGE%^The eastern door is as solid as its three companions, differing only in the single character "
"marked in golden yellow upon its surface.  The character is unfamiliar to you, leaving you to wonder about its meaning"
".%^RESET%^");
     break;
     case "west door": case "western door":
     return("%^BLUE%^The western door is as solid as its three companions, differing only in the single character marked "
"in vivid azure upon its surface.  The character is unfamiliar to you, leaving you to wonder about its meaning.%^RESET%^");
     break;
   }
}

void init() {
   ::init();
   if(!present("tattva")) find_object_or_load(MON"tattva")->move(TO);
   add_action("touch_fun","touch");
}

int touch_fun(string str) {
   if(!str) return 0;
   if(str == "north door" || str == "the north door" || str == "northern door" || str == "the northern door") {
     tell_object(TP,"%^GREEN%^You reach out to touch the northern door.  As your hand makes contact with the emerald "
"character, you suddenly find yourself elsewhere!%^RESET%^");
     tell_room(TO,"%^GREEN%^"+TP->QCN+" reaches out to touch the northern door.  As "+TP->QP+" hand makes contact with "
"the emerald character, "+TP->QS+" suddenly vanishes!%^RESET%^",TP);
     TP->move_player(ROOMS"north");
     return 1;
   }
   if(str == "south door" || str == "the south door" || str == "southern door" || str == "the southern door") {
     tell_object(TP,"%^RED%^You reach out to touch the southern door.  As your hand makes contact with the crimson "
"character, you suddenly find yourself elsewhere!%^RESET%^");
     tell_room(TO,"%^RED%^"+TP->QCN+" reaches out to touch the southern door.  As "+TP->QP+" hand makes contact with the "
"crimson character, "+TP->QS+" suddenly vanishes!%^RESET%^",TP);
     TP->move_player(ROOMS"south");
     return 1;
   }
   if(str == "east door" || str == "the east door" || str == "eastern door" || str == "the eastern door") {
     tell_object(TP,"%^ORANGE%^You reach out to touch the eastern door.  As your hand makes contact with the golden "
"character, you suddenly find yourself elsewhere!%^RESET%^");
     tell_room(TO,"%^ORANGE%^"+TP->QCN+" reaches out to touch the eastern door.  As "+TP->QP+" hand makes contact with "
"the golden character, "+TP->QS+" suddenly vanishes!%^RESET%^",TP);
     TP->move_player(ROOMS"east");
     return 1;
   }
   if(str == "west door" || str == "the west door" || str == "western door" || str == "the western door") {
     tell_object(TP,"%^CYAN%^You reach out to touch the western door.  As your hand makes contact with the azure "
"character, you suddenly find yourself elsewhere!%^RESET%^");
     tell_room(TO,"%^CYAN%^"+TP->QCN+" reaches out to touch the western door.  As "+TP->QP+" hand makes contact with the "
"azure character, "+TP->QS+" suddenly vanishes!%^RESET%^",TP);
     TP->move_player(ROOMS"west");
     return 1;
   }
   return 0;
}