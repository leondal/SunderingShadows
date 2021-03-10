//Octothorpe (1/22/17)
//Shadow, Mage Tower Roof
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("The rooftop of the Shadow Mage Tower");
   set_short("%^YELLOW%^The Rooftop of the %^BOLD%^%^BLACK%^Shadow "+
      "%^RESET%^%^YELLOW%^Mage Tower%^RESET%^");
   set_long("%^YELLOW%^The Rooftop of the %^BOLD%^%^BLACK%^Shadow "+
      "%^RESET%^%^YELLOW%^Mage Tower%^RESET%^\n"+
      "%^WHITE%^%^BOLD%^Nestled here, so high above the city that the "+
      "heavens seem to be within fingertips reach, the rooftop of "+
      "Shadow's mage tower offers a %^CYAN%^breathtaking %^WHITE%^view "+
      "of the city and the sea. The rooftop has been transformed into "+
      "an amphitheater, quite unlike anything you have seen before. "+
      "The design of the tower lends itself naturally to arena seating, "+
      "with a semi-circle arrangement of %^RESET%^benches %^BOLD%^facing "+
      "the %^BLACK%^black stage%^WHITE%^. Enchanted orbs %^MAGENTA%^"+
      "gl%^RESET%^%^MAGENTA%^o%^BOLD%^w %^WHITE%^from beneath the "+
      "seats, casting light over the entire area and filling the sky "+
      "above the tower with a myriad of %^MAGENTA%^w%^RESET%^"+
      "%^MAGENTA%^o%^CYAN%^n%^GREEN%^dr%^CYAN%^o%^MAGENTA%^u%^BOLD%^s "+
      "%^WHITE%^colors. %^RESET%^%^MAGENTA%^Purple carpeting %^BOLD%^"+
      "%^WHITE%^cuts between the middle of the seating area, covering "+
      "the %^BLACK%^hard gray stones%^WHITE%^. The benches are padded "+
      "in a matching shade of %^RESET%^%^MAGENTA%^purple%^BOLD%^"+
      "%^WHITE%^. The stage holds multiple purposes, providing not "+
      "only an area for lectures and demonstrations, but also a place "+
      "for battling mages to safely duel without tearing apart the "+
      "surrounding walls. Lacking walls or other barriers, there does "+
      "not seem to be anything beyond the stage except for a very long "+
      "drop. The backdrop is a view of the %^CYAN%^sky %^WHITE%^and the "+
      "%^BLUE%^sea%^WHITE%^, both of which seem to extend into infinity. "+
      "An %^RESET%^invisible force %^BOLD%^prevents any inclement "+
      "weather from affecting the area.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^CYAN%^The area is free from "+
      "scents.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^It is surprisingly quiet "+
      "here.%^RESET%^");
   set_items(([
      ({"view","city","sea","backdrop"}) : "%^RESET%^%^CYAN%^The "+
         "%^WHITE%^city %^CYAN%^spreads out before you in a riveting "+
         "display of roads and water, parks and homes. Everything is "+
         "small and it seems to be, from here, very serene. "+
         "%^BOLD%^%^GREEN%^Forests %^RESET%^%^CYAN%^close in on the "+
         "city from most sides, while eastward is the %^BOLD%^%^BLUE%^"+
         "vast blue sea%^RESET%^%^CYAN%^.%^RESET%^",
      ({"seating","benches"}) : "%^RESET%^%^CYAN%^The benches are made "+
         "from %^BOLD%^%^BLACK%^stone%^RESET%^%^CYAN%^, which would be "+
         "rather uncomfortable were it not for %^MAGENTA%^velvet purple "+
         "cushioning %^CYAN%^that lines them.%^RESET%^",
      ({"lights","orbs","colors"}) : "%^RESET%^%^CYAN%^Light seeps out "+
         "from beneath the rows of benches and, while it seems to glow "+
         "%^WHITE%^white %^CYAN%^as a default, at times the lights are "+
         "used for something more festive, and can be altered into any "+
         "color desired.%^RESET%^",
      ({"rugs","stones","floor"}) : "%^RESET%^%^CYAN%^A soft %^MAGENTA%^"+
         "purple rug %^CYAN%^runs up the center aisle, softening the "+
         "hardness of the smooth %^BOLD%^%^BLACK%^gray "+
         "%^RESET%^%^CYAN%^floors.%^RESET%^",
      "stage" : "%^RESET%^%^CYAN%^The stage is little more than a "+
         "smooth, flat floor made from the same %^BOLD%^%^BLACK%^gray "+
         "stones %^RESET%^%^CYAN%^as the rest of the tower.%^RESET%^",
      ({"force","weather"}) : "%^RESET%^%^CYAN%^By some act of magic, "+
         "not even the wind manages to blow through the aisles of this "+
         "arena. In fact, any weather, rain or snow, seems to simply "+
         "vanish as it nears the rooftop.%^RESET%^"
   ]));
   set_exits(([
      "down" : ROOMS"mage3rdlanding"
   ]));
   set_door("silver door",ROOMS"mage3rdlanding","down",0,0);
   set_door_description("silver door","%^RESET%^%^CYAN%^The door is "+
      "made from %^WHITE%^light metal%^CYAN%^. A circle of %^BOLD%^"+
      "%^BLUE%^seven silver stars %^RESET%^%^CYAN%^are engraved into "+
      "its otherwise seamless surface.%^RESET%^");
}

string query_weather()
{
   return "%^BOLD%^%^CYAN%^It is clear.%^RESET%^";
}