//cath_living.c 
//for new Seneca ~Circe~ 06/01/08
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Common Room of the Cathedral, Seneca");
   set_short("Common Room of the Cathedral, Seneca");
   set_long("%^BOLD%^Common Room of the Cathedral, Seneca%^RESET%^\n"+
      "This large living area is made cozy by the flickering "+
      "%^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^re%^RESET%^ that burns "+
      "no matter the season in the %^BOLD%^stone fireplace "+
      "%^RESET%^placed in the middle of the western wall.  The "+
      "expansive fireplace is bordered by a %^BOLD%^ma%^BLACK%^"+
      "r%^WHITE%^bl%^BLACK%^e %^WHITE%^he%^BLACK%^a%^WHITE%^rt"+
      "%^BLACK%^h%^RESET%^ and topped with a long matching "+
      "%^BOLD%^ma%^BLACK%^n%^WHITE%^tl%^BLACK%^e%^RESET%^.  "+
      "A set of %^BOLD%^%^BLACK%^iron implements %^RESET%^and a "+
      "small stack of %^ORANGE%^wood %^RESET%^rest upon the "+
      "hearth, ready to be used should the need arise.  Gathered "+
      "around the fireplace are a series of %^ORANGE%^wooden "+
      "benches %^RESET%^of various sizes as well as a scattering "+
      "of a few %^ORANGE%^tables%^RESET%^.  It looks as though "+
      "the %^BOLD%^monks %^RESET%^relax together here in "+
      "communion and fellowship during the few moments they are "+
      "not busy at their work for the monastery.\n");
   set_exits(([
      "east" : ROOMS"cath_hall1"
   ]));
   set_smell("default","The light fragrance of beeswax fills the air.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"wall","walls"}) : "%^BOLD%^%^WHITE%^The stone walls are "+
         "smooth and whitewashed for a pristine appearance.%^RESET%^",
      "floor" : "The smooth stone floor was hewn at one point but "+
         "has also been worn by countless feet over the years, "+
         "making it seem almost soft.",
      ({"fire","fireplace"}) : "The massive fireplace in the "+
         "western wall is dominated by a crackling %^BOLD%^"+
         "%^RED%^f%^YELLOW%^i%^RED%^re%^RESET%^ even during "+
         "the heat of summer.  Thankfully, the location "+
         "underground seems to help the room stay just the "+
         "right temperature.",
      ({"hearth","marble hearth"}) : "Both functional and "+
         "attractive, the hearth is made of %^BOLD%^"+
         "white marble %^RESET%^shot through with %^BOLD%^"+
         "%^BLACK%^bl%^WHITE%^a%^BLACK%^ck v%^WHITE%^e"+
         "%^BLACK%^ins%^RESET%^.  A border of marble runs "+
         "up both sides of the fireplace, while a slab of "+
         "marble hewn to a glassy finish provides a hearth "+
         "shelf at its base.",
      ({"implements","iron implements","wood"}) : "The "+
         "hearth shelf is partially occupied by a set "+
         "of well-made, well-used %^BOLD%^%^BLACK%^iron "+
         "tools %^RESET%^such as pokers, shovels, tongs, "+
         "and brushes.  An %^BOLD%^%^BLACK%^iron basket "+
         "%^RESET%^to the side holds a supply of %^ORANGE%^"+
         "split wood%^RESET%^ for use in the fireplace.",
      ({"mantle","mantle shelf"}) : "Made of %^BOLD%^ma%^BLACK%^"+
         "r%^WHITE%^bl%^BLACK%^e %^RESET%^that matches the hearth, "+
         "the mantle provides a nice long shelf above the "+
         "fireplace.  It appears to have been made for "+
         "function, but like most things in the cathedral, "+
         "it shines with beauty nonetheless.  Spread along "+
         "its length is a series of %^BOLD%^candles %^RESET%^"+
         "that provide soft, relaxing illumination for the "+
         "common room.",
      ({"benches","bench","wooden benches","wooden bench"}) :
         "Spread around the room are a colletion of %^ORANGE%^"+
         "wooden benches %^RESET%^in various sizes.  Some "+
         "are backless while some have both backs and arms, "+
         "but a common simplicity in design runs throughout, "+
         "giving the illusion that they all match.",
      ({"table","tables"}) : "None of the tables are very "+
         "large, and each has a square top.  They are likely "+
         "meant to hold drinks or a light snack, as well as "+
         "provide a surface for playing games."
   ]));
}
