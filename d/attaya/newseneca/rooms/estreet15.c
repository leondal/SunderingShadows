//estreet15 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"Directly west of here is a tall %^RED%^"+
      "brick building %^RESET%^that serves as the %^BOLD%^%^BLACK%^"+
      "barracks %^RESET%^for the %^BOLD%^%^BLUE%^Seneca Guard%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"estreet14",
      "south" : ROOMS"estreet16",
      "west" : ROOMS"barracks_entry"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/barracks_entry","west",0,0);
   set_door_description("door","%^ORANGE%^The varnished wooden door "+
      "on the barracks has been painted with the %^BOLD%^"+
      "%^BLUE%^seal %^RESET%^%^ORANGE%^of %^BOLD%^%^WHITE%^Seneca "+
      "%^RESET%^%^ORANGE%^in its center.%^RESET%^");
   add_item("building","The building to the west is three stories "+
      "tall and crafted of %^RED%^brick %^RESET%^with gray mortar.  "+
      "A wide %^ORANGE%^wooden door %^RESET%^painted with the "+
      "%^BOLD%^%^BLUE%^seal %^RESET%^of Seneca grants entry.");
   add_item("seal",(:TO,"look_seal":));
}

int look_seal(){
   return("%^BOLD%^%^BLUE%^A trio of %^YELLOW%^golden fleurs-de-lis "+
      "%^BLUE%^are arranged in an inverted pyramid on a shield of blue edged "+
      "in %^RED%^red%^BLUE%^.%^RESET%^\n"+
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
