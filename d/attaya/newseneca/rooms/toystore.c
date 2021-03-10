//toystore.c - for new Seneca 11/27/07
//Coded by Circe - base description by Lurue
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_property("indoors",1);  
   set_property("light",0); 
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Dolly's Treasures, Seneca");    
   set_short("%^BOLD%^%^BLUE%^Dolly's Treasures, Seneca%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^Dolly's Treasures, Seneca%^RESET%^\n"+
      "%^YELLOW%^This small, open store is filled a wide selection "+
      "of delightful toys.  The walls are painted a light shade of "+
      "yellow and the hardwood floors are polished and even.  The "+
      "ceiling is high, rising to a central peak from which a %^RED%^"+
      "c%^BLUE%^o%^GREEN%^l%^WHITE%^o%^MAGENTA%^r%^YELLOW%^f%^RED%^"+
      "u%^CYAN%^l %^YELLOW%^display of paper kites can be seen "+
      "hanging - everything from the simple diamond shape to the "+
      "elaborate box kite and dragon.  Wooden shelves, filled with "+
      "%^WHITE%^stuffed animals%^YELLOW%^, %^GREEN%^puppets, "+
      "%^RESET%^%^ORANGE%^wooden soldiers%^YELLOW%^, %^MAGENTA%^"+
      "dolls%^YELLOW%^, and %^CYAN%^wind up toys%^YELLOW%^, create "+
      "a maze through which to wander and explore, with a new "+
      "discovery waiting around every corner.  Toward the back "+
      "wall a wide %^RESET%^%^CYAN%^glass counter %^YELLOW%^offers "+
      "a show place for the delicate %^RESET%^%^MAGENTA%^music boxes "+
      "%^YELLOW%^that fill the shop with the fanciful music.  Toward "+
      "the front, shaded by the large stripped yellow awnings outside, "+
      "are two deep window seats.  Padded with cushy pillows that "+
      "seem made for reclining and relaxing, these seats are flanked "+
      "by narrow book shelves filled with %^WHITE%^children's novels "+
      "%^YELLOW%^and %^RESET%^%^ORANGE%^puzzle boxes%^YELLOW%^.  "+
      "Painted upon the windows themselves are cheerful images of "+
      "happy, playful %^RESET%^%^ORANGE%^animals %^YELLOW%^cavorting "+
      "on a %^GREEN%^grassy field %^YELLOW%^with the shop's name "+
      "written above in stylish blue letters: %^BOLD%^%^CYAN%^Dolly's "+
      "Treasures.%^RESET%^\n");
   set_smell("default","%^RESET%^%^ORANGE%^A delicate floral perfume "+
      "fills the air.%^RESET%^");
   set_listen("default","%^RESET%^%^GREEN%^Tinkling in the background "+
      "is the fanciful sound of music box melodies.%^RESET%^");
   set_items(([
      ({"toys","shelves"}) : "%^BOLD%^%^WHITE%^The shelves are filled "+
         "with a large selection of toys - everything from dolls to "+
         "stuffed animals to wind up toys, puppets, and kites.  It "+
         "would take hours to fully explore every shelf.%^RESET%^",
      ({"counter","glass display"}) : "%^BOLD%^%^WHITE%^The display "+
         "case is made of clear %^RESET%^%^CYAN%^glass%^BOLD%^"+
         "%^WHITE%^ and protects the delicate music boxes that "+
         "are displayed within.%^RESET%^",
      ({"window","windows","seat","window seat","window seats"}) : "%^BOLD%^"+
         "%^WHITE%^The windows are shaded by colorful yellow and white "+
         "striped awnings that protect the window seats from the sun.  "+
         "Painted upon the glass are cheerful images of happy, playful "+
         "%^RESET%^%^ORANGE%^animals %^BOLD%^%^WHITE%^cavorting on a "+
         "%^GREEN%^grassy field%^WHITE%^ with the shop's name written "+
         "in blue print.%^RESET%^"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/viento52","north",0);
   set_door_description("door","%^YELLOW%^The door to the street is painted "+
      "a soft, sunny yellow but is without further adornments.%^RESET%^");
   set_exits(([
      "north" : ROOMS"viento52"
   ]));
}

void reset(){
   ::reset();
   if(!present("toymaker"))
      find_object_or_load(MON"toymaker")->move(TO);
}
