//Octothorpe (1/21/17)
//Shadow, Mage Tower Mad Hat Comp Shop
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_climate("temperate");
   set_name("The Mad Hat");
   set_short("%^BOLD%^The Mad Hat, %^BOLD%^%^BLACK%^Shadow %^WHITE%^"+
      "Mage Tower%^RESET%^");
   set_long("%^BOLD%^The Mad Hat, %^BOLD%^%^BLACK%^Shadow %^WHITE%^"+
      "Mage Tower%^RESET%^\n"+
      "%^RESET%^%^BOLD%^Catching your eye first is the large "+
      "%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r "+
      "%^WHITE%^metal counter, its surface gleaming beneath the "+
      "%^BLACK%^wired %^WHITE%^lights that hang down at varying "+
      "intervals around the room. Behind the counter, the wall is "+
      "lined with %^RESET%^glass cylinders %^BOLD%^attached to a "+
      "network of %^RESET%^pipes%^BOLD%^, %^RESET%^gears %^BOLD%^and "+
      "%^RESET%^levers%^BOLD%^, all of which are used to measure and "+
      "deliver the many components sold by %^BLACK%^Barantheo%^WHITE%^. "+
      "Set on shining %^BLACK%^m%^RESET%^eta%^BOLD%^%^BLACK%^l "+
      "s%^RESET%^h%^BOLD%^elv%^RESET%^e%^BOLD%^%^BLACK%^s %^WHITE%^and "+
      "%^RESET%^within glass cases %^BOLD%^are more %^RESET%^jars "+
      "%^BOLD%^and %^RESET%^vials%^BOLD%^, all of which contain various "+
      "%^MAGENTA%^c%^RESET%^%^MAGENTA%^o%^BLUE%^l%^BOLD%^o%^CYAN%^r"+
      "%^RESET%^%^CYAN%^e%^GREEN%^d l%^CYAN%^i%^BOLD%^q%^BLUE%^u"+
      "%^RESET%^%^BLUE%^i%^MAGENTA%^d%^BOLD%^s %^WHITE%^and other "+
      "%^RED%^c%^RESET%^%^RED%^u%^ORANGE%^r%^BOLD%^i%^GREEN%^o%^RESET%^"+
      "%^GREEN%^s%^BOLD%^i%^ORANGE%^t%^RESET%^%^ORANGE%^i%^RED%^e"+
      "%^BOLD%^s %^WHITE%^(and the occasional curiosity suspended in "+
      "colored liquid). Exposed %^RESET%^pipes %^BOLD%^line the "+
      "%^BLACK%^black ceiling %^WHITE%^in a chaotic fashion, lending "+
      "the room an industrial appearance. Large %^RESET%^gears%^BOLD%^, "+
      "%^RESET%^sundials%^BOLD%^, %^RESET%^metallic bells %^BOLD%^and "+
      "%^RESET%^clockwork oddities %^BOLD%^are just a few of the pieces "+
      "found sitting aimlessly around the room.%^RESET%^\n\n"+
      "Please use %^BOLD%^<help shop> %^RESET%^for information on how "+
      "to use this shop.%^RESET%^\n");
   set_smell("default","%^RESET%^A thousand different %^BOLD%^%^BLACK%^"+
      "overwhelming %^RESET%^scents all compete for dominance.");
   set_listen("default","%^BOLD%^%^BLACK%^A %^RESET%^haunting %^BOLD%^"+
      "%^BLACK%^melody drifts in from the hall.%^RESET%^");
   set_items(([
      ({"cylinders","gears","levers","pipes"}) : "%^CYAN%^Levers, "+
         "gears and knobs are pulled, turned or twisted in order to "+
         "produce a perfectly proportionate amount of any requested "+
         "component. They are made from %^ORANGE%^brass%^CYAN%^, "+
         "%^BOLD%^%^WHITE%^silver %^RESET%^%^CYAN%^and even %^YELLOW%^"+
         "gold%^RESET%^%^CYAN%^, and all are highly polished, oiled "+
         "and quite efficient. The components are contained in strange "+
         "%^WHITE%^glass cylinders %^CYAN%^that reach the height of "+
         "the room, from floor to ceiling.%^RESET%^",
      ({"shelves","jars","vials","curiosities"}) : "%^RESET%^%^CYAN%^Set "+
         "on shining %^BOLD%^%^WHITE%^metal shelves %^RESET%^%^CYAN%^"+
         "and within %^BOLD%^%^WHITE%^glass cases %^RESET%^%^CYAN%^are "+
         "jars and vials which contain various colored liquids and "+
         "other curiosities. You can not say for certain what floats "+
         "about in these jars, and perhaps it's better that way.%^RESET%^",
      ({"pieces","sundials","bells","clockworks","oddities"}) : "%^RESET%^"+
         "%^CYAN%^The little bits of this and that seem to serve no "+
         "real purpose beyond making someone wonder why they're there "+
         "in the first place.%^RESET%^",
      "counter" : "%^RESET%^%^CYAN%^The giant counter is made from "+
         "decorative %^BOLD%^%^WHITE%^silver metal plates %^RESET%^"+
         "%^CYAN%^that are nailed together. The surface is made from "+
         "%^BOLD%^%^BLACK%^obsidian %^RESET%^%^CYAN%^and is very "+
         "reflective.%^RESET%^",
      "lights" : "%^RESET%^%^CYAN%^Small %^BOLD%^orbs %^RESET%^%^CYAN%^"+
         "are strung from wires and nestled within small metal "+
         "%^ORANGE%^cymbals%^CYAN%^. It looks as if small %^WHITE%^"+
         "white fires %^CYAN%^burn within the orbs, perhaps through "+
         "some alchemical process?%^RESET%^",
      ({"piping","pipes"}) : "%^RESET%^%^CYAN%^There is so much going "+
         "on in this room that it is difficult to discern if the pipes "+
         "have a purpose or if they're merely an ornament. They are made "+
         "from %^BOLD%^%^WHITE%^v%^RESET%^a%^ORANGE%^r%^BOLD%^i"+
         "%^WHITE%^o%^RESET%^%^ORANGE%^u%^BOLD%^s %^RESET%^m%^BOLD%^"+
         "e%^ORANGE%^t%^RESET%^%^ORANGE%^a%^WHITE%^l%^BOLD%^s%^RESET%^"+
         "%^CYAN%^, all of which give off a different color and "+
         "sheen.%^RESET%^",
   ]));
   set_exits(([
      "east" : ROOMS"mage2ndlanding",
   ]));
}

void reset()
{
   ::reset();
   if(!present("barantheo"))
   {
      find_object_or_load(MON"barantheo")->move(TO);
   }
}
