#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("Ruins in a thick jungle");
  set_short("%^RESET%^Ruins %^GREEN%^in a thick ju%^BOLD%^ng%^RESET%^%^GREEN%^le%^RESET%^");
  set_long((:TO, "long_desc":));
  set_items(([
      ({"shelter","remains","stone shelter","stone remains","vines"}) : "Clearly "+
         "the shelter was built to protect the statue within.  It looks to have "+
         "fallen into disrepair for the most part, but the vines above "+
         "it suggest that someone has taken a new interest in it.",
      ({"disk","stone disk","statue","sun disk","sun statue"}) : "%^ORANGE%^"+
         "The large stone disk is made of deep brown stone and carved "+
         "to resemble a stylized %^YELLOW%^sun%^RESET%^%^ORANGE%^.  "+
         "The carver has filled the center of the sun with countless "+
         "images of beasts and natural occurrences, each of which "+
         "has been meticulously painted to lend this statue a very "+
         "%^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o"+
         "%^CYAN%^r%^RESET%^%^CYAN%^f%^BOLD%^%^BLUE%^u%^RESET%^"+
         "%^MAGENTA%^l %^ORANGE%^appearance.  The "+
         "rays of the sun stretch out to the very edge of the disk.",
      ({"stones","dais","stone dias","steps"}) : "The steps in this "+
         "clearing form a perfect square rising to the top of the "+
         "square dais.  There are three steps in all, and they seem "+
         "to have been worn by many feet over the years."
  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.");
}

string long_desc(){
return "%^GREEN%^Emerging from the dense jungle is this small clearing, "+
       "roughly round in shape.  In the center, %^RESET%^stone "+
       "steps %^GREEN%^are laid out in a perfect square leading "+
       "up to a %^RESET%^square dais%^GREEN%^.  Standing above the "+
       "dais are the %^RESET%^stone remains %^GREEN%^of a shelter of "+
       "some sort.  Interestingly, %^BOLD%^vines %^RESET%^%^GREEN%^"+
       "seem to have been recently intertwined there, giving some "+
       "sort of protection from rain to what lies beneath.  "+
       "Standing upright atop the dias is a %^ORANGE%^wide stone "+
       "disk %^GREEN%^that seems to have been carved from a different "+
       "manner of stone than the building.  It is %^ORANGE%^deep "+
       "brown %^GREEN%^in color and looks to be a %^BOLD%^%^RED%^c"+
       "%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^CYAN%^r%^RESET%^"+
       "%^CYAN%^f%^BOLD%^%^BLUE%^u%^RESET%^%^MAGENTA%^l %^GREEN%^"+
       "representation of the %^YELLOW%^sun%^RESET%^%^GREEN%^.\n%^RESET%^";
}