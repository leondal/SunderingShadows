//viento56 - Circe 11/12/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VIENTO;

void create(){
   ::create();
/*
   set_long(::query_long()+"North of here is a shop with %^BOLD%^stone "+
      "walls %^RESET%^and a %^GREEN%^tiled roof%^RESET%^.  To the south "+
      "is the broad entryway of a large %^ORANGE%^building%^RESET%^.  "+
      "Rising above it to the south is a magnificent round %^BOLD%^"+
      "stone structure%^RESET%^.\n");
Return this description when the coliseum opens
*/
   set_long(::query_long()+"North of here is a shop with %^BOLD%^stone "+
      "walls %^RESET%^and a %^GREEN%^tiled roof%^RESET%^.  To the south "+
      "is the broad entryway of a large %^ORANGE%^building%^RESET%^.  "+
      "Rising above it to the south is a magnificent round %^BOLD%^"+
      "stone structure%^RESET%^.  The southern entryway remains "+
      "closed as construction on the stone structure continues.\n");
   set_exits(([
      "west" : ROOMS"viento55",
      "east" : ROOMS"viento57",
      "north" : ROOMS"weapon",
//      "south" : ROOMS"coliseum_entry"
   ]));
   set_door("weaponsmith door","/d/attaya/newseneca/rooms/weapon","north",0,0);
   set_door_description("weaponsmith door","The weapons shop to the north "+
      "has a wide wooden door set within its stone walls.  It is often left "+
      "open, helping to relieve some of the heat of the smithy.");
/*
   set_door("coliseum door","/d/attaya/newseneca/rooms/coliseum_entry","south",0,0);
   set_door_description("coliseum door","The door to the southern building "+
      "is a wide wooden structure slightly darker than the walls.");
*/
   add_item("shop","The shop to the north has thick stone walls broken only "+
      "by short, wide windows near the tiled roof and a wide wooden door, all of "+
      "which help provide ventilation from the adjoining smithy.  When the "+
      "door is open, you can see that the interior is filled with weapons of "+
      "all kinds.");
   add_item("building","South of the road is a well-tended building with "+
      "wooden walls.  A broad walkway leads to its wide door, but there is "+
      "little other ornamentation.");
   add_item("structure","The stone structure is impressive, featuring levels of "+
      "archways just visible above the wooden building to the south.  At intervals "+
      "all around the coliseum are shield-shaped penants in %^BOLD%^%^BLUE%^"+
      "blue %^RESET%^bordered with %^BOLD%^%^RED%^red%^RESET%^."); 
   add_item("stone structure","The stone structure is impressive, featuring levels of "+
      "archways just visible above the wooden building to the south.  At intervals "+
      "all around the coliseum are shield-shaped penants in %^BOLD%^%^BLUE%^"+
      "blue %^RESET%^bordered with %^BOLD%^%^RED%^red%^RESET%^."); 
   if(query_night()==1){
      set_open("weaponsmith door",0);
      "/d/attaya/newseneca/rooms/weapon"->set_open("weaponsmith door",0);
   }else{
      set_open("weaponsmith door",1);
      "/d/attaya/newseneca/rooms/weapon"->set_open("weaponsmith door",1);
   }
}