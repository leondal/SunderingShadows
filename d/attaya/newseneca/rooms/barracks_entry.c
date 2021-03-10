//barracks_entry - Barracks for new Seneca
//~Circe~ 12/4/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

object ob;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Entrance of the Guard Barracks, Seneca");
   set_short("%^BOLD%^%^WHITE%^Entrance of the Guard Barracks, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Entrance of the Guard Barracks, Seneca%^RESET%^\n"+
      "Immediately across from the doorway is a wide %^ORANGE%^"+
      "staircase%^RESET%^ that begins in the south and moves upward "+
      "as it goes north.  It looks as though it would allow "+
      "many people at once, taking up the bulk of this rather "+
      "plain room.  An intricate %^BLUE%^tapestry%^RESET%^ hangs "+
      "from its side, a depiction of the %^BOLD%^%^BLUE%^seal "+
      "%^RESET%^of Seneca woven into its fabric.  Below the "+
      "%^BLUE%^tapestry %^RESET%^is a %^ORANGE%^wooden desk "+
      "%^RESET%^- all lines, angles, and polish - and a matching "+
      "%^ORANGE%^chair%^RESET%^.  A wide %^BLUE%^mat%^RESET%^, "+
      "also bearing the city's %^BOLD%^%^BLUE%^seal %^RESET%^"+
      "lies in front of the doorway, helping to keep the room "+
      "clean.  Off to the north, an %^BOLD%^elliptical archway %^RESET%^"+
      "opens into what must be a dining hall as there are several "+
      "long %^ORANGE%^tables %^RESET%^in the room beyond.\n");
   set_smell("default","The clean fragrance of the ocean is masked somewhat by the aroma of soldiers.");
   set_listen("default","Chatter from the dining halls mixes with the noise of Seneca.");
   set_items(([
      ({"staircase","stairs"}) : "The stairs run along the western "+
         "wall, leading up to a second floor.  The side of the stairs "+
         "forms a sloping wall, upon which a tapestry has been hung.  "+
         "The stairway has a thick wooden banister to provide support, "+
         "and the stairs themselves look wide enough for four or five "+
         "people to walk abreast, likely to allow many guards to leave "+
         "at once, should the need arise.",
      "tapestry" : "Woven from %^BLUE%^deep blue fabric%^RESET%^, this "+
         "tapestry is rectangular in shape and ends in a point.  It is "+
         "edged in %^YELLOW%^gold silk %^RESET%^and features a %^YELLOW%^"+
         "golden tassel%^RESET%^.  Centered on the tapestry is a well-"+
         "rendered version of the %^BOLD%^%^BLUE%^seal %^RESET%^of Seneca.",
      ({"desk","wooden desk","chair"}) : "This wooden desk and chair "+
         "look to be a matched set and have miraculously been made "+
         "to have no curves at all, giving them a stoic appearance.  "+
         "A guardsman is always on duty here, ready to take reports and "+
         "dispatch his fellow guardsmen.  A %^ORANGE%^leather-bound "+
         "book %^RESET%^lies on the desk with writing materials "+
         "nearby - likely a place to record reports.",
      ({"mat","doormat"}) : "Balancing the %^BLUE%^tapestry %^RESET%^"+
         "on the western wall is this %^BLUE%^doormat%^RESET%^.  It "+
         "has a %^BOLD%^%^RED%^red band%^RESET%^ about two inches "+
         "from the edge, and it bears the %^BOLD%^%^BLUE%^seal %^RESET%^"+
         "of Seneca in its center.",
      ({"archway","arch","elliptical archway","dining hall","tables"}) :
         "The archway to the north is flattened in the middle, forming "+
         "almost a rectangle.  Through the opening, you can see a "+
         "large dining hall where it seems many guardsmen can be found "+
         "eating at almost any time of day.  Long tables with rows of "+
         "stools fill the hall, and it looks like a doorway at the far "+
         "end likely leads to a kitchen.",
      "seal" : (:TO,"look_seal":)
   ]));
   set_door("door","/d/attaya/newseneca/rooms/estreet15","east",0,0);
   set_door_description("door","%^ORANGE%^The door to the street is "+
      "relatively plain.  Its wooden surface has been varnished to "+
      "a high shine.%^RESET%^");
   set_exits(([
      "east" : ROOMS"estreet15",
      "north" : ROOMS"barracks_dining",
      "up" : ROOMS"barracks_common1"
   ]));
}

//add guardsman to load

int look_seal(){
   return("%^BOLD%^%^BLUE%^A trio of %^YELLOW%^golden fleurs-de-lis "+
      "%^BLUE%^are arranged in an inverted pyramid on a shield of blue edged "+
      "in %^RED%^red%^BLUE%^.%^RESET%^\n\n"+
      "%^BOLD%^%^RED%^################\n"+
      "#%^BLUE%^@@@@@@@@@@@@@@%^RED%^#\n"+
      "#%^BLUE%^@@%^YELLOW%^\\|/%^BLUE%^@@@@%^YELLOW%^\\|/%^BLUE%^@@%^RED%^#\n"+
      "#%^BLUE%^@@%^YELLOW%^~T~%^BLUE%^@@@@%^YELLOW%^~T~%^BLUE%^@@%^RED%^#\n"+
      "#%^BLUE%^@@@@@@@@@@@@@@%^RED%^#\n"+
      "#%^BLUE%^@@@@@@@@@@@@@@%^RED%^#\n"+
      "#%^BLUE%^@@@@@%^YELLOW%^\\|/%^BLUE%^@@@@@@%^RED%^#\n"+
      " #%^BLUE%^@@@@%^YELLOW%^~T~%^BLUE%^@@@@@%^RED%^#\n"+
      "  #%^BLUE%^@@@@@@@@@@%^RED%^#\n"+
      "   #%^BLUE%^@@@@@@@@%^RED%^#\n"+
      "     ######%^RESET%^\n");
   return 1;
}

void reset(){
   ::reset();
   if(!present("seneca guard")){
      ob = new(MON"city_guard");
      ob->set_speec(0);
      ob->move(TO);
   }
}
