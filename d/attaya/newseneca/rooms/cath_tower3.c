//cath_tower3 - bell tower for new Seneca
//~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit STORAGE"cath_tower";

void create(){
string myseason,mytree,myleaves;
   ::create();
   myseason = season(time());
   switch(myseason){
      case "spring" : mytree = "%^BOLD%^%^GREEN%^Attaya oak"; 
                      myleaves = "%^BOLD%^%^GREEN%^vibrant green";
                      break;
      case "summer" : mytree = "%^RESET%^%^GREEN%^Attaya oak";
                      myleaves = "%^RESET%^%^GREEN%^weathered green";
                      break;
      case "fall" :   mytree = "%^YELLOW%^A%^RED%^t%^RESET%^%^RED%^"+
                      "t%^ORANGE%^a%^GREEN%^y%^YELLOW%^a %^RED%^o"+
                      "%^RESET%^%^RED%^a%^ORANGE%^k";
                      myleaves = "%^ORANGE%^c%^GREEN%^h%^YELLOW%^a"+
                      "%^RED%^n%^RESET%^%^RED%^g%^ORANGE%^i"+
                      "%^YELLOW%^n%^RESET%^%^GREEN%^g";
                      break;
      case "winter" : mytree = "%^BOLD%^%^WHITE%^A%^RESET%^t%^BOLD%^t"+
                      "%^RESET%^a%^BOLD%^y%^RESET%^a %^BOLD%^o"+
                      "%^RESET%^a%^BOLD%^k";
                      myleaves = "scattered %^ORANGE%^chestnut brown";
                      break;
      default: mytree = "Attaya oak";
               myleaves = "%^GREEN%^green";
               break;
   }
   set_long(::query_long()+"\nHere on the third floor of the bell "+
      "tower, the western window looks out upon the upper %^BOLD%^"+
      "boughs %^RESET%^of the grand "+mytree+"%^RESET%^ that rises above "+
      "the cemetery.\n");
   set_exits(([
      "down" : ROOMS"cath_tower2",
      "up" : ROOMS"cath_tower4"
   ]));
   add_item("boughs","In "+myseason+", the "+mytree+"%^RESET%^ has "+
      ""+myleaves+" leaves %^RESET%^that dance on the wind.");
   add_item("oak","In "+myseason+", the "+mytree+"%^RESET%^ has "+
      ""+myleaves+" leaves %^RESET%^that dance on the wind.");
   add_item("Attaya oak","In "+myseason+", the "+mytree+"%^RESET%^ has "+
      ""+myleaves+" leaves %^RESET%^that dance on the wind.");
   add_item("tree","In "+myseason+", the "+mytree+"%^RESET%^ has "+
      ""+myleaves+" leaves %^RESET%^that dance on the wind.");
}