//Octothorpe (1/16/17)
//Shadow, Mage Tower Comp Shop
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
   set_name("Stick and Stones");
   set_short("%^BOLD%^%^BLACK%^Sticks and Stones, Shadow Mage "+
      "Tower%^RESET%^");
   set_long("%^%^BOLD%^%^BLACK%^Sticks and Stones, Shadow Mage "+
      "Tower%^RESET%^\n"+
      "%^ORANGE%^This small shop is neatly tucked away beneath "+
      "the tower stairs. A large %^BOLD%^%^RED%^r%^RESET%^%^RED%^e"+
      "%^BOLD%^d t%^RESET%^%^RED%^ap%^BOLD%^es%^RESET%^%^RED%^tr"+
      "%^BOLD%^y %^RESET%^%^ORANGE%^covers the sloping ceiling, "+
      "and a %^BOLD%^%^BLACK%^black area rug %^RESET%^%^ORANGE%^"+
      "softens the stone floor. Every bit of available wall space is "+
      "lined with shelves, and the shelves are entirely covered in "+
      "the various %^WHITE%^jars%^ORANGE%^, %^CYAN%^vials%^ORANGE%^, "+
      "%^GREEN%^pouches%^ORANGE%^, and the sort of %^MAGENTA%^oddities "+
      "%^ORANGE%^that one expects to find in a component shop. "+
      "Candles, placed into every crevice or left to burn on any "+
      "available surface, lend the room a warm glow. A %^MAGENTA%^"+
      "petite%^ORANGE%^, %^BOLD%^%^BLACK%^dark-haired %^RESET%^"+
      "%^MAGENTA%^woman %^ORANGE%^bustles around behind an old wooden "+
      "counter, and a fat %^BOLD%^%^BLACK%^black cat %^RESET%^"+
      "%^ORANGE%^seems to have the run of the small shop.%^WHITE%^\n\n"+
      "Please use %^BOLD%^<help shop> %^RESET%^for information on how "+
      "to use this shop.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^BLACK%^The musky scent of incense "+
      "fills the air.%^RESET%^");
   set_listen("default","%^RESET%^%^MAGENTA%^A bit of the music from "+
      "the foyer manages to drift in...%^WHITE%^");
   set_items(([
      ({"ceiling","tapestries"}) : "%^RESET%^%^CYAN%^A %^BOLD%^"+
         "%^RED%^red tapestry %^RESET%^%^CYAN%^with a metallic "+
         "%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^ld %^RESET%^"+
         "%^CYAN%^border hangs above your head, capturing your "+
         "attention with the %^GREEN%^serpentine %^CYAN%^pattern "+
         "that winds across its surface. The tapestry holds a faint "+
         "red glow as if it is somehow dimly lit from behind.%^RESET%^",
      ({"rug","area rug","floor"}) : "%^RESET%^%^CYAN%^A soft "+
         "%^BOLD%^%^BLACK%^black rug %^RESET%^%^CYAN%^covers the "+
         "cold stone floor, bearing some signs of heavy traffic.%^RESET%^",
      ({"shelves","jars","vials","bowls","components"}) : "%^RESET%^"+
         "%^CYAN%^Every bit of available wall space is lined with "+
         "shelves, and the shelves are entirely covered in the "+
         "various jars, vials, pouches and the sort of oddities that "+
         "one expects to find in a component shop. There is no good "+
         "sense of organization to be found, and a good dusting might "+
         "be in order.%^WHITE%^",
      "candles" : "%^RESET%^%^CYAN%^While nearly every surface is "+
         "cluttered with one thing or another, some candles manage "+
         "to stand defiantly against the mess. They are fat and "+
         "colored things, that burn with a bright light despite not "+
         "giving off any smoke or scent, and they never seem to melt.%^WHITE%^",
      "counter" : "%^RESET%^%^CYAN%^The counter is quite cluttered "+
         "but seems to hold most of the tools necessary to "+
         "successfully run a shop like this.%^WHITE%^"
   ]));
   set_exits(([
      "out" : ROOMS"magefoyer",
   ]));
}

void reset()
{
   ::reset();
   if(!present("delilah"))
   {
      find_object_or_load(MON"delilah")->move(TO);
   }
}