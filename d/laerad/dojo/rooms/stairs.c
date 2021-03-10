#include <std.h>
#include "../dojo.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("The upper floor of a wooden dojo hall");
    set_short("%^RESET%^%^ORANGE%^The upper floor of a wooden dojo hall%^RESET%^");
    set_long("%^CYAN%^This section of the building is fairly small, with room only for a few people to stand comfortably "
"upon the flat landing of %^ORANGE%^poli%^RED%^sh%^ORANGE%^ed wooden floorboards%^CYAN%^.  Simple railings border the "
"landing to either side, meeting at a %^RED%^spiral staircase %^CYAN%^that leads downwards to the vast main chamber below"
".  On three sides rise walling of vertical slats, all of which have been oiled to a %^RED%^da%^ORANGE%^r%^RED%^k and rich "
"fi%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^ish%^CYAN%^.  The fourth wall, immediately opposite the staircase, is set with a "
"solidly closed door, which is marked with a single %^BOLD%^%^WHITE%^ivo%^YELLOW%^r%^BOLD%^%^WHITE%^y %^RESET%^%^CYAN%^glyph"
".  A lone %^BOLD%^win%^WHITE%^d%^CYAN%^ow %^RESET%^%^CYAN%^lies above the staircase, broken up by narrow slats and sheeted "
"with %^RESET%^ricepaper%^CYAN%^, that sheds a soft and steady stream of %^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^RESET%^"
"%^CYAN%^into this small space.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The soft, sweet smell of %^MAGENTA%^c%^BOLD%^h%^WHITE%^er%^MAGENTA%^r%^RESET%^%^MAGENTA%^y bl%^BOLD%^o%^WHITE%^ss%^MAGENTA%^o%^RESET%^%^MAGENTA%^ms %^ORANGE%^wafts in from the %^GREEN%^gar%^ORANGE%^d%^GREEN%^en %^ORANGE%^beyond.%^RESET%^");
    set_listen("default","%^GREEN%^There is a comfortable %^CYAN%^si%^GREEN%^l%^CYAN%^en%^BOLD%^c%^RESET%^%^CYAN%^e %^GREEN%^to this place.%^RESET%^");

    set_items(([
      ({"floor","floor boards","floorboards"}) : "%^ORANGE%^Beneath your feet are smooth floorboards that spread the "
"limited length and breadth of the landing.  No flaw or splinter can be seen or felt.  Judging by their worn surface, "
"these boards are regularly oiled and polished until they shine.  Stairs of the same smooth wood lead down to the "
"chamber below.%^RESET%^",
      ({"walls","slats","vertical slats"}) : "%^RED%^Polished wooden slats form a near perfectly symmetrical border to "
"this small space on three sides, interrupted only by the window above the stairs, and the solid doorway set directly "
"opposite it.%^RESET%^",
      "window" : "%^CYAN%^Directly above the staircase lies a single short, broad window.  Narrow slats form a frame to "
"support ricepaper sheeting over its surface, which filters light into this small area as a soft illumination rather "
"than a harsh glare.%^RESET%^",
      ({"door","doorway","doorframe","door frame","solid door","character","glyph"}) : (:TO,"door_desc":),
      ({"stairs","staircase","spiral staircase"}) : "%^RED%^A spiral staircase meets the edge of this landing.  A railing "
"of wooden struts lines its curved path downwards, toward the main chamber of this building.%^RESET%^",
    ]));
    set_exits(([
      "down" : ROOMS"centre",
    ]));
}

string door_desc(string str) {
   if((int)TP->query_skill("academics") > 25) {
     return("%^ORANGE%^Directly opposite the stairs lies a sturdy wooden door, set within a frame as dark as the walls "
"around it.  No handle or other means of opening is readily apparent, leaving you to wonder if it is designed perhaps to "
"slide, or to be pushed.  Upon its surface is a single character marked in pale ivory upon its surface.  You recognize the "
"character as an ancient symbol for %^BOLD%^%^WHITE%^spirit%^RESET%^%^ORANGE%^.%^RESET%^");
   }
   return("%^ORANGE%^Directly opposite the stairs lies a sturdy wooden door, set within a frame as dark as the walls "
"around it.  No handle or other means of opening is readily apparent, leaving you to wonder if it is designed perhaps to "
"slide, or to be pushed.  Upon its surface is a single character marked in pale ivory upon its surface.  The character is "
"unfamiliar to you, leaving you to wonder about its meaning.%^RESET%^");
}

void init() {
   ::init();
   add_action("touch_fun","touch");
}

int touch_fun(string str) {
   object ob;
   int failflag;
   if(!str) return 0;
   failflag = 0;
   if(str == "door") {
     ob = present("dojoairtoken",TP);
     if(!ob || base_name(ob) != OBJ"airtoken") failflag = 1;
     ob = present("dojofiretoken",TP);
     if(!ob || base_name(ob) != OBJ"firetoken") failflag = 1;
     ob = present("dojowatertoken",TP);
     if(!ob || base_name(ob) != OBJ"watertoken") failflag = 1;
     ob = present("dojoearthtoken",TP);
     if(!ob || base_name(ob) != OBJ"earthtoken") failflag = 1;

     if(failflag) {
       tell_object(TP,"%^BOLD%^%^WHITE%^You reach out to touch the door.  As your hand makes contact with the ivory "
"character, you get the feeling that you are missing something.  Nothing happens.%^RESET%^");
     tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" reaches out to touch the door.  "+capitalize(TP->QP)+" hand makes "
"contact with the ivory character, but nothing happens.%^RESET%^",TP);
       return 1;
     }
     tell_object(TP,"%^BOLD%^%^WHITE%^You reach out to touch the door.  As your hand makes contact with the ivory "
"character, you suddenly find yourself elsewhere!%^RESET%^");
     tell_room(TO,"%^BOLD%^%^WHITE%^"+TP->QCN+" reaches out to touch the door.  As "+TP->QP+" hand makes contact with "
"the ivory character, "+TP->QS+" suddenly vanishes!%^RESET%^",TP);
     TP->move_player(ROOMS"spirit");
     return 1;
   }
   return 0;
}