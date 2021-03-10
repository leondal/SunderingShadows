//Lothwaite's healer.  Circe 6/22/04
#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "../lothwaite.h"

inherit HEALER;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_name("gwendolyn");
    set_short("Gwendolyn's Infirmary");
    set_long(
       "%^RESET%^%^ORANGE%^This large infirmary is made much like the "+
       "other buildings in the village, with walls made of wattle "+
       "surrounding a large %^RED%^hearth %^ORANGE%^in the center of "+
       "the floor.  Unlike most of the buildings, however, the floor "+
       "here is made of %^RESET%^stone %^ORANGE%^that seems to have "+
       "been quarried from the valley.  Atop the stone are fresh "+
       "%^GREEN%^rushes%^ORANGE%^, still %^GREEN%^green %^ORANGE%^"+
       "after having been gathered from the %^BOLD%^%^BLUE%^lake"+
       "%^RESET%^%^ORANGE%^.  It is apparent that the healer "+
       "here believes in cleanliness as an aid to healing, as "+
       "the entire room is ordered and free of any %^RESET%^dust"+
       "%^ORANGE%^.  Two massive %^GREEN%^cots %^ORANGE%^stand "+
       "against the wall, though it seems they are rarely used.  "+
       "Behind the %^RED%^hearth %^ORANGE%^is a curving %^RESET%^"+
       "stone counter %^ORANGE%^laden with healing supplies, potions, "+
       "and poultices.%^RESET%^\n"
    );
    set_items(([
       ({"cot","cots"}) : "Each of the two cots is large enough for "+
          "a full grown firbolg - or three or four halflings.  They "+
          "are made from stout willow frames that support doubled "+
          "muslin stretched taunt to provide a somewhat giving "+
          "place to rest while healing.",
      ({"walls","wall","wattle","wattle walls"}) : "%^ORANGE%^"+
         "The walls are made of wattle - woven panels of osier, or "+
         "willow, that have been packed with mud to seal the cracks "+
         "and keep out the wind.  The very bottom of the walls are "+
         "made of %^RESET%^stones %^ORANGE%^shaped to fit without "+
         "mortar.",
      ({"floor","stone floor","rushes"}) : "The stone floor is covered "+
         "with a layer of rushes taken from the lake nearby.  The "+
         "rushes look to be changed ever so often to keep them "+
         "clean.  They add a slight grassy fragrance to the shop.",
      ({"hearth","round hearth"}) : "The center of the shop is "+
         "dominated by a round, stone hearth, in which a %^BOLD%^"+
         "%^RED%^f%^YELLOW%^ir%^RED%^e %^RESET%^burns ceaselessly.  "+
         "An %^BOLD%^%^BLACK%^iron cauldron %^RESET%^is suspended "+
         "above it, with a few herbs being boiled for their healing "+
         "properties.",
      ({"counter","stone counter","supplies","potions","poultices"}) : 
         "The stone counter curves close to the hearth and rises "+
         "about eight feet above the floor.  There are many different "+
         "supplies atop it, from dried and fresh herbs to bandages, "+
         "completed potions and poultices in jars and vials.  It "+
         "looks as though everything is well-organized and kept "+
         "within arm's reach."
    ]));
    set_smell("default", "The unusual fragrance of herbs and rushes is heavy in the air.");
    set_listen("default", "The crackle of the fireplace mingles with the sound of herbs being ground.");
    set_exits( ([
        "north" : PATHEXIT"pathway22"
    ] ));
}

void reset(){
    ::reset();
    if(!present("gwendolyn")) 
        new(MON"gwendolyn")->move(TO);
}
