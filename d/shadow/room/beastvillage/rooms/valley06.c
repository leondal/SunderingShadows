#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);  
   set_property("light",2); 
   set_terrain(NEW_MOUNTS); 
   set_travel(FOOT_PATH); 
   set_name("A clearing in the forest");    
   set_short("%^GREEN%^A clearing in the forest%^RESET%^");

   set_long("%^GREEN%^A clearing in the forest%^RESET%^\n"
"%^ORANGE%^You stand in a clearing of sorts, with downtrodden dirt covering "
"most of the ground where grass and tiny shrubs have not struggled through.  A few haphazard "
"%^RESET%^boulders%^ORANGE%^ lie about, probably tumbled long ago from the mountains above.  "
"Bordering the limits of the clearing are the sturdy trunks of the pine and ash that spread "
"thick branches and foliage over the lesser shrubs beneath, and it is to these that your eyes "
"are repeatedly drawn.  Within their %^GREEN%^canopy%^ORANGE%^, numerous dwellings have been "
"woven from branches and leaves, and you can regularly see green-furred humanoids moving with "
"ease between them, and occasionally descending to the forest floor to travel.  Somewhere nearby"
", you can hear the roar of tumbling %^CYAN%^water%^ORANGE%^, towards which the path further "
"to the south seems to lead.%^RESET%^\n");

   set_smell("default","The mountain air is crisp and carries the fresh aroma of pine.");
   set_listen("default","You can hear the distant roar of a waterfall.");

   set_items(([
           ({"path","pathway","dirt","rocks","boulders"}) : "%^ORANGE%^Beneath "
"your feet lies the downtrodden dirt of a clearing, with a pathway leading off "
"to the south.  A few tumbled stones lie about, along with the discarded remnants "
"of some kind of civilisation - ashes from fire, discarded bones and scraps of "
"wood that have been partly carved.%^RESET%^",

           ({"mountains","ridges" }) : "%^BOLD%^%^WHITE%^High above the forest rise "
"the ridges of the Charu Mountains, effectively hemming in this tiny valley on all "
"sides.%^RESET%^",

           ({"forest","trees","pine","ash","shrubs"}) : "%^GREEN%^Within this isolated "
"valley stands an ancient forest, which rises above you on all sides.  Pine and ash branches "
"claw toward the sky above, casting dappled shadows across the lesser shrubs at their feet, "
"and the dirt upon which you stand.%^RESET%^",

        ]));

   set_exits(([ 
     "south":ROOMS"valley05",
   ])); 
}

void reset() {
   ::reset();
   switch(random(10)) {
     case 0:
     tell_room(TO,"%^ORANGE%^Tiny birds take up a vibrant song in the trees above.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^CYAN%^A crack sounds off to the side, somewhere in the undergrowth, as a creature passes by.%^RESET%^");
     break;
     case 2:
     tell_room(TO,"%^GREEN%^A beastman strides into the clearing, returning from the hunt with bloodied spear and a brace of rabbits in hand. Without apparent difficulty, he scales a nearby tree one-handed and disappears into one of the shelters above.%^RESET%^");
     break;
     case 3:
     tell_room(TO,"%^BLUE%^The sound of chanting rises briefly from a shelter above, several aged voices joining in a strangely harmonious song.%^RESET%^");
     break;
     case 4:
     tell_room(TO,"%^GREEN%^Chattering sounds back and forth in the canopy above, as several beastmen call one to the other.%^RESET%^");
     break;
     case 5:
     tell_room(TO,"%^ORANGE%^A sharp wail goes up from one of the shelters above, as a child cries its indignance to anyone who will hear. The chattering of an elder soon follows to quiet the babe, and before long quiet falls again.%^RESET%^");
     break;
     case 6:
     tell_room(TO,"%^RED%^Hissing and sharp chatter rises from a nearby shelter, as it seems several beastmen try to resolve an argument of some kind.%^RESET%^");
     break;
     case 7:
     tell_room(TO,"%^YELLOW%^Pinpoint eyes gleam at the entry to one of the habitations above, watching you for a long moment before they disappear again.%^RESET%^");
     break;
     case 8:
     tell_room(TO,"%^CYAN%^You hardly notice the beastmen passing through the canopy above until they are about to disappear into a woven shelter. Their mottled fur keeps them almost perfectly hidden within the forest.%^RESET%^");
     break;
     case 9:
     tell_room(TO,"%^CYAN%^A pack of beastmen, male and female, come bounding and leaping down from the trees above, simple spears and knives and nets in hand. With little more than a glance in your direction, they slink into the forest to hunt, and are quickly lost to view amidst the green that so closely matches their fur.%^RESET%^");
     break;
   }
   if(!present("tiktik")) find_object_or_load(MON"tiktik")->move(TO);
}