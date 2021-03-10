//cave4.c
#include "../kildare.h"

inherit CAVE;

void create()
{
   ::create();
   set_long(
      "%^YELLOW%^A Large Cavern\n"+
      "%^RESET%^%^ORANGE%^This large cavern seems to be a natural "+
      "landing of sorts.  The ground here is much more level than the "+
      "surrounding caverns, and it seems that some artist decided to "+
      "make this his home for a time.  Strange symbols and runes are "+
      "carved into the walls, surrounded by rudimentary cave paintings.  "+
      "The northern part of the cavern is dominated by hewn stone stairs "+
      "leading up, while the passageway resumes its downward slope to the south."

    );
   set_items(([
      "steps" : "The steep slope of the cavern floor has been made "+
      "easier by roughly hewn steps leading upwards to the north.",
      "cavern" : "The dark walls of this cavern seem to be "+
      "hewn rather than naturally carved as the rest of Echoes Mountains.",
      ({"floor","ceiling","stone"}) : "The ceiling seems to be very roughly hewn "+
      "while the dark stone floor has been worn smooth.",
      ({"symbols","runes"}) : "Intricate %^BOLD%^%^CYAN%^symbols %^RESET%^ and "+
      "%^BOLD%^%^BLACK%^runes %^RESET%^are scattered around the walls and stand "+
      "at odds with the rudimentary cave paintings.  Surely more than one "+
      "artist was involved here.  Some of them seem to have a somewhat arcane look.",
      ({"paintings","cave paintings"}) : "Simple cave paintings have been drawn "+
      "onto the rough stone walls.  Rudimentary hunters follow images of deer and "+
      "bear, all drawn in faded %^RED%^reds %^RESET%^and %^BOLD%^%^BLACK%^blacks."
      ]));

    set_exits(([
      "south" : ROOMS"cave3",
      "up" : ROOMS"cave5"
        ]));

}
