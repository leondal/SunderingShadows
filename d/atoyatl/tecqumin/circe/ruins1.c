#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();
string plant_desc();

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
      ({"column","columns","broken columns"}) : "The broken columns are "
         "at regular intervals around the oval paving stones.  They are "
         "broken at different heights, revealing that each column was "
         "made by piling stone disks atop each other.",
      ({"statue","tree","stone statue","quali statue","Quali statue"}) : "The "
         "statue of the tree appears to be ancient, and its form suggests "
         "that it has great meaning for the Tecqumin.  As you study it closer, "
         "you notice that the head has eyes that seem to be crafted from "
         "%^YELLOW%^amber%^RESET%^.",
      ({"stones","paving stones","oval"}) : "The oval area is fitted with "
         "paving stones carved to the appropriate shape.  Some are now "
         "loose or missing, and you notice that they seem to have been "
         "painted at one time with greens, blues, and tans."
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
void init() {
   ::init();
}

string long_desc(){
return "%^GREEN%^The dense jungle gives way here to a %^BOLD%^small "
       "clearing %^RESET%^%^GREEN%^dominated by a %^RESET%^stone "
       "structure%^GREEN%^.  Roughly cut %^RESET%^paving stones "
       "%^GREEN%^form the basis for an impressive %^CYAN%^statue "
       "%^GREEN%^carved in %^RESET%^pale gray stone%^GREEN%^.  "
       "The %^RESET%^paving stones %^GREEN%^form an oval base "
       "set with faded %^CYAN%^c%^GREEN%^o%^BOLD%^l%^RESET%^"
       "%^GREEN%^o%^CYAN%^r%^GREEN%^e%^BOLD%^d stones%^RESET%^ "
       "%^GREEN%^that support an immense statue of a %^BOLD%^"
       "towering tree%^RESET%^%^GREEN%^.  The %^ORANGE%^stone "
       "tree %^GREEN%^is colored with weathered %^ORANGE%^"
       "browns %^GREEN%^and %^BOLD%^greens%^RESET%^%^GREEN%^, "
       "lending accent to its great spreading canopy.  Strangely, "
       "the tree's trunk seems to split into two %^ORANGE%^knobbly "
       "legs%^GREEN%^, and it looks to have a head of some sort "
       "atop its spreading branches.  It looks as though this "
       "statue was once protected by a roofed structure, but all "
       "that remains now are broken %^RESET%^stone columns %^GREEN%^"
       "arranged around the oval.%^RESET%^\n";
}