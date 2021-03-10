//viento50 - Circe 11/10/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
   set_long(::query_long()+"This stretch of road lies just south of "+
      "a %^MAGENTA%^costume shop %^RESET%^"+
      "with large %^BOLD%^%^CYAN%^windows %^RESET%^filled with %^YELLOW%^c"+
      "%^RED%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r%^RESET%^%^MAGENTA%^f%^ORANGE%^u"+
      "%^CYAN%^l %^YELLOW%^costumes%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"viento49",
      "east" : ROOMS"viento51",
      "north" : ROOMS"bard_costume",
//      "south" : ROOMS"jewelry"
   ]));
/*   set_door("jeweler door","/d/attaya/newseneca/rooms/jewelry","south",0,0);
   set_door_description("jeweler door","The door leading to the jewelry "+
      "shop to the south is a simple wooden door bound with %^BOLD%^%^BLACK%^"+
      "iron %^RESET%^and set with a small window.");
*/
   set_door("costume door","/d/attaya/newseneca/rooms/bard_costume","north",0);
   set_door_description("costume door","%^BOLD%^%^BLUE%^The door to the costume "+
      "shop is painted a %^CYAN%^brilliant blue%^BLUE%^ with %^YELLOW%^small "+
      "flowers %^BLUE%^stenciled around its edge.%^RESET%^");
   add_item("costume shop","The costume shop to the north has a bright "+
      "%^BOLD%^%^BLUE%^blue door %^RESET%^with %^YELLOW%^yellow flowers "+
      "%^RESET%^stenciled around its edges.  Large, rounded %^CYAN%^windows "+
      "%^RESET%^to either side of the door house %^YELLOW%^c"+
      "%^RED%^o%^GREEN%^l%^CYAN%^o%^BLUE%^r%^RESET%^%^MAGENTA%^f%^ORANGE%^u"+
      "%^CYAN%^l %^YELLOW%^costumes%^RESET%^ that change daily it seems.");
/*
   add_item("jewelry store","The jewelry store to the south seems small but "+
      "well-tended.  It is squeezed between a bustling restaurant to the "+
      "west and a peaceful park to the east.");
   add_item("jeweler","The jewelry store to the south seems small but "+
      "well-tended.  It is squeezed between a bustling restaurant to the "+
      "west and a peaceful park to the east.");
Leaving the jewelry store out for now.  Jewelry is sold in the souvenir shop.  Maybe a player will want to open a store :)
*/
}