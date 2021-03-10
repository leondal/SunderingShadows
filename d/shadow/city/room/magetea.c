//Octothorpe (1/18/17)
//Shadow, Mage Tower Library Lounge
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
   set_name("The Library's Lounge");
   set_short("%^BOLD%^The Library's Lounge%^RESET%^");
   set_long("%^BOLD%^The Library's Lounge%^RESET%^\n"+
      "%^ORANGE%^This is a %^WHITE%^wide %^ORANGE%^and %^WHITE%^airy "+
      "%^ORANGE%^space, largely thanks to the open balcony on one "+
      "side, and the wall panelled with windows on the other. "+
      "In-between is an arrangement of small %^CYAN%^tables%^ORANGE%^, "+
      "%^MAGENTA%^sofas %^ORANGE%^and %^MAGENTA%^plush chairs"+
      "%^ORANGE%^. The balcony overlooks the main floor of the "+
      "library, and the stunning amount of books that line the high "+
      "walls. The %^CYAN%^arched windows %^ORANGE%^take up the "+
      "entirety of the opposite wall, from floor to ceiling, allowing "+
      "a grand view of the surrounding city. To the right is a posh "+
      "%^BOLD%^%^RED%^c%^RESET%^%^RED%^h%^ORANGE%^e%^BOLD%^%^BLACK%^"+
      "r%^RED%^r%^RESET%^%^RED%^y %^ORANGE%^w%^RED%^o%^BOLD%^o"+
      "%^BLACK%^d %^RESET%^%^ORANGE%^b%^RED%^a%^BOLD%^r%^RESET%^"+
      "%^ORANGE%^, which provides some additional seating, while to "+
      "the left is a magnificent %^BOLD%^%^BLACK%^stone fireplace"+
      "%^RESET%^%^ORANGE%^. This is a %^MAGENTA%^relaxing %^ORANGE%^"+
      "space where people can gather for quiet conversation, or simply "+
      "to take a break from their studies. No reading material is "+
      "allowed here, however.%^RESET%^\n\n"+
      "%^RESET%^%^CYAN%^A %^BOLD%^%^BLACK%^chalkboard %^RESET%^%^CYAN%^"+
      "behind the bar lists the various %^ORANGE%^teas %^CYAN%^"+
      "available for purchase.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^GREEN%^The aromatic %^RESET%^scent "+
      "%^BOLD%^%^GREEN%^of teas fill the air.%^RESET%^");
   set_listen("default","%^BOLD%^You hear the soft clink of teacups "+
      "against saucers, and %^RESET%^%^CYAN%^hushed %^BOLD%^"+
      "%^WHITE%^conversations.%^RESET%^");
   set_items(([
      "balcony" : "%^RESET%^%^CYAN%^The balcony features a thick "+
         "%^ORANGE%^wooden banister %^CYAN%^that is carved to look like "+
         "twisting vines and lillies. From up here, one can see most of "+
         "the library's main floor and admire the ornate, if not "+
         "ostentatious, room below.%^RESET%^",
      "windows" : "%^RESET%^%^CYAN%^There are eight very large, arched "+
         "windows in all, allowing a wonderful view of the city. Each "+
         "window is lined with %^BOLD%^%^MAGENTA%^plush %^RESET%^"+
         "%^MAGENTA%^purple %^BOLD%^d%^RESET%^%^MAGENTA%^r%^BOLD%^aper"+
         "%^RESET%^%^MAGENTA%^ie%^BOLD%^s%^RESET%^%^CYAN%^, which can "+
         "be drawn closed, or tied open to allow in copious amounts of "+
         "%^YELLOW%^sunlight%^RESET%^%^CYAN%^. The windows have been "+
         "treated so that while one can clearly see out, nobody on the "+
         "other side can see in.%^RESET%^",
      ({"tables","sofas","chairs"}) : "%^RESET%^%^CYAN%^Small round "+
         "tables with comfortable chairs are set up in one section, "+
         "providing a place for acquaintances to chat and enjoy their "+
         "tea. A couple of %^MAGENTA%^purple sofas %^CYAN%^have been "+
         "neatly arranged for lounging near the %^BOLD%^%^BLACK%^"+
         "fireplace%^RESET%^%^CYAN%^, and the matching plush "+
         "%^MAGENTA%^chairs %^CYAN%^can easily accommodate a party "+
         "of one.%^RESET%^",
      "bar" : "%^RESET%^%^CYAN%^This looks like the sort of %^ORANGE%^"+
         "bar %^CYAN%^one would expect to find in an upscale tavern, "+
         "with highly polished %^ORANGE%^wooden shelves%^CYAN%^, a "+
         "%^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^y m%^RESET%^a"+
         "%^BOLD%^%^BLACK%^rbl%^RESET%^e%^BOLD%^%^BLACK%^-t%^RESET%^"+
         "o%^BOLD%^%^BLACK%^p c%^RESET%^ou%^BOLD%^%^BLACK%^nt%^RESET%^"+
         "e%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^, and a large %^BOLD%^"+
         "%^WHITE%^mirror %^RESET%^%^CYAN%^that reflects the room. "+
         "But instead of bottles of liquor, jars of %^ORANGE%^tea "+
         "leaves %^CYAN%^line the tidy shelves.%^WHITE%^",
      "fireplace" : "%^RESET%^%^CYAN%^Taking up a good amount of space "+
         "along the wall, the %^BOLD%^%^BLACK%^fireplace %^RESET%^"+
         "%^CYAN%^is made from %^BOLD%^%^BLACK%^black%^RESET%^"+
         "%^CYAN%^, %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^"+
         "y%^RESET%^%^CYAN%^, and %^WHITE%^w%^BOLD%^%^BLACK%^h%^RESET%^"+
         "ite s%^BOLD%^%^BLACK%^to%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^"+
         "s %^CYAN%^that reach from the floor to the ceiling. The "+
         "hearth itself is deep and black. A %^RED%^fi%^MAGENTA%^r"+
         "%^RED%^e %^CYAN%^burns steadily, although it seems to be "+
         "more for decoration than warmth. The fire flickers in a "+
         "%^RED%^m%^GREEN%^y%^MAGENTA%^ri%^ORANGE%^a%^RED%^d %^CYAN%^"+
         "of colors and gives off no heat nor smoke.%^RESET%^",
      "chalkboard" : "%^RESET%^%^CYAN%^The %^BOLD%^%^BLACK%^chalkboard "+
         "%^RESET%^%^CYAN%^hangs above the bar's mirrors. The "+
         "lettering is %^MAGENTA%^lovely%^CYAN%^, an art unto itself. "+
         "Perhaps you could %^BOLD%^read %^RESET%^%^CYAN%^it to see "+
         "what's available on the menu.%^WHITE%^"
   ]));
   set_exits(([
      "down" : ROOMS"magelibrary",
   ]));
}



void reset()
{
   ::reset();
   if(!present("shan"))
   {
      find_object_or_load(MON"shan")->move(TO);
   }
}

void init()
{
   ::init();
   add_action("read_menu","read");
}

int read_menu(string str)
{
   object obj;
   int i;
   if(str == "menu" || str == "chalkboard") 
   {
      obj = present("shan");
      if(!objectp(obj))
      {
         tell_object(TP,"The tea mistress has stepped away from the bar.");
         return 1;
      }
      say(""+TPQCN+" looks over the menu on the chalkboard.");
      message("Ninfo","The menu reads:\n",TP);
      message("Ninfo","%^ORANGE%^-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-%^RESET%^\n",TP);
      message("Ninfo","\n                         %^BOLD%^%^CYAN%^Teas%^RESET%^\n\n",TP);
      message("Ninfo","\t%^CYAN%^White Cinnamon Sage%^RESET%^\t"+
         " "+(int)obj->get_price("white cinnamon sage")+" pieces of silver\n",TP);
      message("Ninfo","\t%^CYAN%^Jasmine Green%^RESET%^\t\t"+
         " "+(int)obj->get_price("jasmine green")+" pieces of silver\n",TP);
      message("Ninfo","\t%^CYAN%^Sweet Orange Spice%^RESET%^\t"+
         " "+(int)obj->get_price("sweet orange spice")+" pieces of silver\n",TP);
      message("Ninfo","\t%^CYAN%^Orchid Vanilla%^RESET%^\t\t"+
         " "+(int)obj->get_price("orchid vanilla")+" pieces of silver\n",TP);
      message("Ninfo","\t%^CYAN%^Apple Red%^RESET%^\t\t"+
         " "+(int)obj->get_price("apple red")+" pieces of silver\n",TP);
      message("Ninfo","\n                         %^BOLD%^%^GREEN%^Food%^RESET%^\n\n",TP);
      message("Ninfo","\t%^GREEN%^Fresh Vegetable Salad%^RESET%^\t"+
         " "+(int)obj->get_price("fresh vegetable salad")+" pieces of silver\n",TP);
      message("Ninfo","\t%^GREEN%^Turkey Wrap%^RESET%^\t\t"+
         " "+(int)obj->get_price("turkey wrap")+" pieces of silver\n",TP);
      message("Ninfo","\n                         %^BOLD%^%^MAGENTA%^Pastries%^RESET%^\n\n",TP);
      message("Ninfo","\t%^MAGENTA%^Tea Cookies%^RESET%^\t\t"+
         " "+(int)obj->get_price("tea cookies")+" pieces of silver\n",TP);
      message("Ninfo","\t%^MAGENTA%^Apple Strudel%^RESET%^\t\t"+
         " "+(int)obj->get_price("apple strudel")+" pieces of silver\n\n",TP);
message("Ninfo","%^ORANGE%^-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-%^RESET%^\n",TP);
      message("Ninfo","Use %^BOLD%^<buy dish_name> %^RESET%^to purchase food.\n",TP);
      return 1;
   }
}