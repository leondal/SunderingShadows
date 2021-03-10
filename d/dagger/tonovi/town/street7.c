//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light",2);
    set_short("Crossroad");
    set_long(
      "%^GREEN%^Crossroads of %^BOLD%^Main Street %^RESET%^"+
      "%^GREEN%^and %^BOLD%^%^BLACK%^Ekan Street%^RESET%^\n"+
      "This is the main crossroads to the city.  All around you "+
      "the %^GREEN%^peasants %^RESET%^of the city wander by, and "+
      "amazingly it seems that most have %^BOLD%^%^BLACK%^slaves "+
      "%^RESET%^in tow.  To the south you see a couple of lone "+
      "%^BOLD%^shops%^RESET%^.  To the north the street moves "+
      "towards the %^BLUE%^soldiers' barracks%^RESET%^, and a "+
      "%^ORANGE%^strange structure %^RESET%^far to the north.  "+
      "To the east and west %^BOLD%^%^GREEN%^Main Street %^RESET%^"+
      "crosses through the city, leading to the %^CYAN%^bazaar "+
      "%^RESET%^of %^YELLOW%^Tonovi%^RESET%^ to the west.\n"
    );
    set_items( ([
       "peasants" : "These peasants look to be rather well-dressed "+
          "and wealthy.  You can't help but wonder how they make "+
          "their money.",
	"slaves" : "You've noticed a lot of slaves around this town.  "+
          "In fact, now you notice that almost all are elven.  Where "+
          "could they be coming from?",
      "barracks" : "This town seems to be in a constant state of war.  "+
          "Attesting to this fact is the rather nondescript building to "+
          "the north that houses the common soldiers of the city.  Many "+
          "of them can often be seen entering and leaving there.",
      "shops" : "You can see the rooftops of a couple of shops above "+
          "the heads of some of the people in the streets.  You cannot "+
          "tell what they sell from here, however.",
      ({"structure","strange structure"}) : "Far to the north, you can "+
          "barely make out what looks to be some sort of compound.  "+
          "You can tell few details from here, though, only a rooftop "+
          "and another wall.",
      "bazaar" : "This open air marketplace seems to be constantly "+
          "bustling with people."
      ]) );
    set_exits( ([
	"north" : RPATH "street18",
	"south" : RPATH "street10",
	"east" : RPATH "street6",
	"west" : RPATH "street8"
      ]) );
}
