//was clothshop.c
//updated by Circe 12/3/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Designs by Akanar, Seneca");
   set_short("%^BOLD%^%^WHITE%^Designs by Akanar, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Designs by Akanar, Seneca%^RESET%^\n"+
      "%^CYAN%^This warm building has been painted a %^BOLD%^soft "+
      "blue %^RESET%^%^CYAN%^that is easy on the eyes and creates a "+
      "relaxed atmosphere.  Every inch of the floor has been filled "+
      "with %^ORANGE%^wooden racks %^CYAN%^that hold %^RESET%^clothing "+
      "%^CYAN%^on hangers ready for sale.  A %^BOLD%^window %^RESET%^"+
      "%^CYAN%^with %^BOLD%^%^BLUE%^blue curtains %^RESET%^%^CYAN%^in the "+
      "western wall holds a %^ORANGE%^window basket%^CYAN%^ that can be seen "+
      "through the glass and is %^CYAN%^filled with %^BOLD%^"+
      "%^WHITE%^coir fibers %^RESET%^%^CYAN%^to support the %^ORANGE%^ora"+
      "%^YELLOW%^n%^RESET%^%^ORANGE%^ge bou%^YELLOW%^g%^RESET%^%^ORANGE%^"+
      "ain%^YELLOW%^v%^RESET%^%^ORANGE%^ill%^YELLOW%^e%^RESET%^%^ORANGE%^"+
      "a%^RESET%^%^CYAN%^ growing within.  %^ORANGE%^Shelves %^CYAN%^along the "+
      "southern wall hold extra %^MAGENTA%^fabric%^CYAN%^, %^RESET%^thread"+
      "%^CYAN%^, and %^GREEN%^supplies %^CYAN%^needed to create the "+
      "wonderful clothing Akanar prides himself on.  A carved %^ORANGE%^"+
      "wooden cabinet %^CYAN%^with a %^MAGENTA%^ma%^BOLD%^r%^RESET%^"+
      "%^MAGENTA%^bl%^RESET%^e %^MAGENTA%^t%^BOLD%^o%^RESET%^%^MAGENTA%^"+
      "p %^CYAN%^has been set a few feet in front of the southern wall, "+
      "and a %^MAGENTA%^padded chair %^CYAN%^behind it offers a comfortable "+
      "place to conduct business, though Akanar can rarely be caught "+
      "sitting down.%^RESET%^\n");
/*
@DESC
This large tent houses the %^CYAN%^Clothing Shop%^RESET%^. Bright colored 
clothing hangs from poles throughout the room. It is quite 
warm in here. In the center of the room is a round marble 
table where transactions are made.
DESC
   );
*/
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"racks","wooden racks","clothing"}) : "The shop is cramped "+
         "with the many wooden racks upon which hang a variety of "+
         "clothing.  The racks are simple affairs, with most of "+
         "them having two legs and a bar across, while others are "+
         "a single leg in the center supporting a wheel design.  "+
         "The clothing is in a wide %^BOLD%^%^CYAN%^a%^BLUE%^r"+
         "%^RED%^r%^MAGENTA%^r%^YELLOW%^a%^GREEN%^y %^RESET%^of "+
         "colors and fabrics.",
      ({"window","curtains","blue curtains"}) : "The %^BOLD%^%^BLUE%^"+
         "curtains %^RESET%^on the western window are a deeper "+
         "shade of blue than the walls.  The are simple in design, "+
         "supported by a %^ORANGE%^wooden rod %^RESET%^that matches "+
         "the racks on the floor.  Through the glass of the window, "+
         "you can see a %^ORANGE%^basket %^RESET%^of flowers.",
      ({"window basket","flower basket","flowers","bougainvillea","orange bougainvillea"}) :
         "The rectangular %^ORANGE%^window basket %^RESET%^visible "+
         "beyond the blue curtains is blossoming with beautiful "+
         "%^ORANGE%^ora%^YELLOW%^n%^RESET%^%^ORANGE%^ge bou%^YELLOW%^g%^RESET%^%^ORANGE%^"+
         "ain%^YELLOW%^v%^RESET%^%^ORANGE%^ill%^YELLOW%^e%^RESET%^%^ORANGE%^"+
         "a%^RESET%^ whose petals wave upon the %^CYAN%^ocean "+
         "breeze%^RESET%^.",
      ({"shelves","thread","fabric","supplies"}) : "A testament "+
         "to the fastidious nature of the shop owner, the "+
         "wooden shelves in the back of the room are perfectly "+
         "spaced and filled with neat rows of supplies.  The "+
         "threads are arranged by color, with varying shades "+
         "of the same hue moving in a smooth progression so "+
         "that the perfect one is easy to find.  Fabric is "+
         "similarly arranged by color as well as material, and "+
         "the various scissors and other supplies are kept "+
         "neatly in %^ORANGE%^wicker baskets%^RESET%^.",
      ({"wooden cabinet","cabinet","top","marble top"}) : "The "+
         "varnished %^ORANGE%^wooden cabinet %^RESET%^in "+
         "front of the shelves has no openings from the front, "+
         "and it is capped with a beautiful %^MAGENTA%^pu%^BOLD%^"+
         "r%^RESET%^%^MAGENTA%^p%^RESET%^l%^MAGENTA%^e ma%^BOLD%^r%^RESET%^%^MAGENTA%^"+
         "bl%^RESET%^e %^MAGENTA%^t%^BOLD%^o%^RESET%^%^MAGENTA%^p"+
         "%^RESET%^.  It is across this counter that Akanar "+
         "conducts his business.",
      ({"chair","padded chair"}) : "The %^ORANGE%^wooden chair "+
         "%^RESET%^behind the counter is fitted with plush "+
         "%^MAGENTA%^s%^BOLD%^t%^YELLOW%^r%^MAGENTA%^i%^RESET%^"+
         "%^MAGENTA%^p%^BOLD%^e%^YELLOW%^d %^MAGENTA%^p%^RESET%^"+
         "%^MAGENTA%^a%^BOLD%^d%^YELLOW%^d%^MAGENTA%^i%^RESET%^"+
         "%^MAGENTA%^n%^BOLD%^g %^RESET%^and looks incredibly "+
         "comfortable.  The polished arms, though, are without "+
         "wear or mark, hinting that it is rarely ever used."
   ]));
   set_exits(([
      "north" : ROOMS"street2"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/street2","north",0,0);
   set_door_description("door","The door to the tailor's shop is "+
      "%^ORANGE%^oaken %^RESET%^and has a curved top.  A small half-moon "+
      "%^CYAN%^window %^RESET%^is set near the top of the door.");
}

void reset() {
   ::reset(); 
   if(!present("akanar"))
      find_object_or_load(MON"akanar")->move(TO);
}
