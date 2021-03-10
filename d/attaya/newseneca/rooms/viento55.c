//viento55 - Circe 11/12/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"To the north is a shop that bears the official "+
      "%^BOLD%^%^BLUE%^seal %^RESET%^of %^BOLD%^Seneca%^RESET%^ on the door and "+
      "seems to sell clothing.  To the south is the broadside of a building, "+
      "though there is no entrance here.  Visible over the roof of the southern "+
      "building is a magnificent round %^BOLD%^stone structure%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"viento54",
      "east" : ROOMS"viento56",
      "north" : ROOMS"clothing2"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/clothing2","north",0,0);
   set_door_description("door","%^ORANGE%^The varnished wooden door "+
      "on the shop to the north has been painted with the %^BOLD%^"+
      "%^BLUE%^seal %^RESET%^%^ORANGE%^of %^BOLD%^%^WHITE%^Seneca "+
      "%^RESET%^%^ORANGE%^in its center.%^RESET%^");
   add_item("shop","A rather bland wooden building to the north seems to be "+
      "a clothing shop.  Though plain, it is clearly well-tended and "+
      "clean, and it seems to do a brisk business.  The %^BOLD%^%^BLUE%^"+
      "seal %^RESET%^of %^BOLD%^Seneca %^RESET%^is carefully painted in the "+
      "center of the door.");
   add_item("seal",(:TO,"look_seal":));
   add_item("structure","The stone structure is impressive, featuring levels of "+
      "archways just visible above the wooden building to the south.  At intervals "+
      "all around the coliseum are shield-shaped penants in %^BOLD%^%^BLUE%^"+
      "blue %^RESET%^bordered with %^BOLD%^%^RED%^red%^RESET%^."); 
   add_item("stone structure","The stone structure is impressive, featuring levels of "+
      "archways just visible above the wooden building to the south.  At intervals "+
      "all around the coliseum are shield-shaped penants in %^BOLD%^%^BLUE%^"+
      "blue %^RESET%^bordered with %^BOLD%^%^RED%^red%^RESET%^."); 
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
