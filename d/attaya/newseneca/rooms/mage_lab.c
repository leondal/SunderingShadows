//mage_lab.c for new Seneca
//~Circe~ 1/4/07

#include <std.h>
#include "../seneca.h"

inherit "/std/lab";

void create(){
   object ob;
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_property("indoors",1);
   set_property("light",2);
//   set_property("no teleport",1);
   set_name("Laboratory of the Esoteric Haven, Seneca");
   set_short("%^BOLD%^%^WHITE%^Laboratory of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Laboratory of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^\n"+
      "Designed with the busy mage in mind, this laboratory "+
      "provides all the essentials an experimenting wizard might "+
      "need.  %^BOLD%^Alembics %^RESET%^stand ready over %^RED%^"+
      "braziers %^RESET%^on the many %^BOLD%^%^BLACK%^stone "+
      "counters %^RESET%^spread around the laboratory, nestled "+
      "among %^CYAN%^steel scales %^RESET%^in different sizes.  "+
      "Racks holding various %^YELLOW%^chemicals %^RESET%^in "+
      "glass vials %^RESET%^line the walls within easy reach "+
      "of the countertops.  A free-standing %^ORANGE%^cabinet "+
      "%^RESET%^in the southeastern corner holds an array of empty "+
      "%^CYAN%^vials %^RESET%^with %^ORANGE%^cork stoppers "+
      "%^RESET%^for members to use as needed.  Stacked next to "+
      "the vials are several %^BOLD%^%^BLACK%^stone mortars and "+
      "pestles%^RESET%^ along with various other pieces of "+
      "glassware.  %^ORANGE%^Hooks %^RESET%^beside the cabinet "+
      "hold %^BOLD%^aprons %^RESET%^and %^BOLD%^lab coats %^RESET%^"+
      "in several different sizes.  Finally, an %^BOLD%^%^BLACK%^"+
      "iron oven %^RESET%^and %^ORANGE%^kiln %^RESET%^add the "+
      "finishing touches to the alchemy equipment.  In a small "+
      "area of the far eastern part of the room, %^BOLD%^cubbies "+
      "%^RESET%^have been established for members of the tower.  "+
      "Almost hidden to the north of the door is a fantastic "+
      "%^BOLD%^%^CYAN%^mirror %^RESET%^for use in scrying."+
      "\n\n%^RESET%^The command <help laboratory> will instruct "+
      "you in its use.\n");
   set_exits(([
           "west" : ROOMS"mage_landing4"
   ]));
   set_items(([
      ({"alembic","alembics"}) : "A glass construction for "+
         "distilling liquid, the alembic consists of a pear-"+
         "shaped glass container with a neck that allows for "+
         "various tubes to be screwed on and lead to "+
         "a waiting receptacle.  The alembic is placed upon a "+
         "metal stand to be stood above a brazier.",
      ({"brazier","braziers"}) : "Each brazier has a small, "+
         "functional stand made of %^BOLD%^%^BLACK%^iron "+
         "%^RESET%^that supports a matching bowl that can "+
         "be filled with charcoal or candles.  They are placed "+
         "beneath glassware to heat the contents, providing "+
         "the necessary energy for many of the alchemical processes.",
      ({"counter","stone counter","stone counters","counters","countertops"}) : 
         "%^BOLD%^%^BLACK%^Gray stone matching the walls has been "+
         "used to craft countertops, each of which sits upon a "+
         "wooden cabinet.  The stone provides a safe place "+
         "for the braziers and other dangerous substances, "+
         "while extra supplies are stored in the cabinets.%^RESET%^",
      ({"scales","steel scales","balance","balances"}) : 
         "Scales and balances, all made of steel, are spread "+
         "out around the room.  You see tiny constructions "+
         "that can measure fractions of an ounce to larger "+
         "ones that can hold sixty pounds or more.  Each "+
         "scale, no matter the size, has a central post that "+
         "supports a crossbeam which in turn holds a shallow "+
         "metal plate at each end.  Materials to be weighed "+
         "are placed on one of the plates, while weights are "+
         "placed on the other side until balance is achieved.",
      ({"racks","chemicals"}) : "The wooden racks look like "+
         "small wooden bookshelves without backs.  The 'shelves' "+
         "are actually parallel rails that allow vials of "+
         "chemicals to be placed beneath them, ensuring that "+
         "none of them tip over.  Glancing over the labels, "+
         "you see all the more common materials an alchemist "+
         "might need.",
      ({"cabinet","vials","stoppers","cork stoppers"}) : "The "+
         "wooden cabinet has heavy doors that protect the "+
         "fresh, clean materials within.  The glass vials "+
         "come in many different shapes and sizes, and each "+
         "has a stopper made to fit it - though you sometimes "+
         "have to search to find it.",
      ({"mortars","pestles","mortars and pestles"}) : "The "+
         "mortars and pestles are made in different sizes, "+
         "which aids the alchemist in getting just the right "+
         "consistency to powders.  Each one has a stone bowl "+
         "with a matching heavy stone rod to crush, grind, "+
         "and mix materials.",
      ({"hooks","apron","aprons","lab coat","lab coats"}) : "The "+
         "wooden hooks are attached to the wall, though it "+
         "does not look as though they have been driven in as "+
         "normal.  Many different sizes of white aprons and "+
         "lab coats are there for public use, though some of them "+
         "bear stains and obvious burn marks.",
      ({"oven","iron oven","kiln"}) : "The cast iron oven has "+
         "a small door at the top allowing access to the "+
         "chamber where the fire burns.  The oven proper is "+
         "below it, and it is often used as a necessary "+
         "heating tool for potions.  The ceramic kiln sits "+
         "low to the floor and looks like a squat mound.  "+
         "It is heated by charcoal to provide alchemist with "+
         "a place to create many of the powders they use."
   ]));
   set_smell("default","The pure fragrance of the waterfall is masked by the scent of sulfur and acid.");
   set_listen("default","The bubbling of the alchemy equipment rises over the sound of the waterfall.");
   set_door("door","/d/attaya/newseneca/rooms/mage_landing4","west",0,0);
   set_door_description("door","The door in the western wall is "+
      "unique in construction.  It seems to have been made not of "+
      "wood but of metal, which is common enough.  The glaring "+
      "difference is that the surface of the metal shifts and "+
      "flows, giving it the appearance of %^BOLD%^m%^RESET%^o"+
      "%^BOLD%^l%^RESET%^t%^BOLD%^e%^RESET%^n %^BOLD%^m%^RESET%^i"+
      "%^BOLD%^t%^RESET%^h%^BOLD%^r%^RESET%^i%^BOLD%^l%^RESET%^.");
   setOwner("none");
   setLabId("seneca");
   ob=new("/d/magic/obj/mirror");
   ob->move(TO);
}