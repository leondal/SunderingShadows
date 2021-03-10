//barracks_common1 - Barracks for new Seneca
//~Circe~ 12/6/07
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
   set_name("Common Room of the Guard Barracks, Seneca");
   set_short("%^BOLD%^%^WHITE%^Common Room of the Guard Barracks, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Common Room of the Guard Barracks, Seneca%^RESET%^\n"+
      "The wide %^ORANGE%^staircase %^RESET%^along the western wall "+
      "opens upon this common room.  The %^RED%^walls %^RESET%^here "+
      "have been left the natural %^RED%^brick%^RESET%^, leaving "+
      "this room more affected by the outside temperature than the "+
      "rooms on the first floor.  A frayed %^BLUE%^blue rug %^RESET%^"+
      "covers most of the floor, its edges unraveling.  Several "+
      "%^ORANGE%^wooden chairs %^RESET%^and a couple of mismatched "+
      "%^ORANGE%^tables %^RESET%^crowd the room, giving the guardsmen "+
      "a place to relax other than the dormitory.  It seems that most "+
      "leave when not on duty, but several guardsmen can always be "+
      "seen here talking, laughing, and playing cards.  A narrow "+
      "%^ORANGE%^stairway%^RESET%^ has been built along the southern wall "+
      "leading up to a doorway above, while a closed %^ORANGE%^door "+
      "%^RESET%^is set within the northern wall.\n");
   set_smell("default","The clean fragrance of the ocean is masked somewhat by the aroma of soldiers.");
   set_listen("default","Chatter from the guardsmen mixes with the noise of Seneca.");
   set_items(([
      ({"staircase","stairs"}) : "The stairs run along the western "+
         "wall, leading down to the first floor.  "+
         "The stairway has a thick wooden banister to provide support, "+
         "and the stairs themselves look wide enough for four or five "+
         "people to walk abreast, likely to allow many guards to leave "+
         "at once, should the need arise.",
      ({"wall","walls","brick"}) : "The walls are plain %^RED%^red "+
         "brick %^RESET%^and unadorned.  They do little to make this "+
         "room more comfortable, but they do seem sturdy.",
      ({"rug","blue rug"}) : "%^BLUE%^The faded rug covering the "+
         "floor has become frayed, and it seems to have been cheaply "+
         "woven to begin with.  It looks rather stiff and scratchy, "+
         "making you glad of the chairs around the room.%^RESET%^",
      ({"chair","chairs","table","tables"}) : "A square table sits in the "+
         "northeastern corner, nearly getting in the way of the door "+
         "to the north.  It is surrounded by four chairs, each of which "+
         "is rickety and seems to have been snagged from a different "+
         "place.  A nicer round table is in the south central portion "+
         "of the room, and three of the five chairs surrounding it match.",
      "stairway" : "The stairway at the southern end of the room is "+
         "much more narrow than the staircase to the west.  It seems "+
         "to have been made from the same wood, though, and has a "+
         "thin banister for support.  The stairs end in a door leading "+
         "to a third floor."
   ]));
   set_exits(([
      "north" : ROOMS"barracks_housing1",
      "down" : ROOMS"barracks_entry",
      "up" : ROOMS"barracks_women"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/barracks_housing1","north",0,0);
   set_door("stairway door","/d/attaya/newseneca/rooms/barracks_women","up",0,0);
   set_door_description("stairway door","The door at the top of the stairs "+
      "is narrow and has a sign that says 'Female Guard Only' attached "+
      "near the top in the center.");
}

void reset(){
   ::reset();
   if(!present("seneca guard 2") && !random(2)){
      ob = new(MON"city_guard");
      ob->set_speec(0);
      ob->move(TO);
   }
}