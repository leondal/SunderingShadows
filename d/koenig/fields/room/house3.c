//house3.c - Coded by Circe 1/1/04
#include <std.h>
inherit VAULT; 

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
   set_name("Near a vast cornfield"); 
   set_short("Near a vast cornfield"); 
   set_long("The narrow trail winding its way into the %^ORANGE%^woods %^RESET%^"+
      "just north of the %^BOLD%^%^GREEN%^cornfields %^RESET%^ends here "+
      "at the doorstep of a small house.  The pathway continues to the west, "+
      "but just to the east you see a small house with smoke rising "+
      "from the chimney.  The %^BOLD%^%^BLUE%^pathway %^RESET%^"+
      "looks to be made by the travelling of feet steadily across it, "+
      "although it doesn't seem to see heavy use.\n");
   set("night long","%^GREEN%^This narrow path winds its way out of the "+
      "%^BOLD%^cornfields %^RESET%^%^GREEN%^to the south.  The trees "+
      "loom overhead here, making it difficult to see very far.  This %^ORANGE%^"+
      "path %^GREEN%^seems clear enough, though, and it seems to round a "+
      "bend to the west here.  To the east, you can see points of "+
      "%^YELLOW%^cheery light %^RESET%^%^GREEN%^that seem to come from "+
      "the windows of a small house.\n");
   set_smell ("default","You can smell the clean earthy scent of the cornfields.");
   set_listen ("default","A light breeze rustles in the trees."); 
   set_items(([ 
      ({"path","pathway","trail","footpath","road"}) : "The trail is nothing "+
         "more than packed earth that has been tread upon by many feet.  It seems "+
         "to see steady use, if not by many people.",
      ({"tree","trees","woods"}) : "Just north of the cornfield lie these woods.  "+
         "Here, evergreens are mixed with maples and other hardwoods, a sign that "+
         "the more temperate climates south of here are giving way with the colder "+
         "mountain air.",
      ({"house","windows","light","smoke","chimney"}) : (: TO, "house_desc" :),
   ]));
   set_exits(([
      "west" : "/d/koenig/fields/room/house2",
      "east" : "/d/koenig/fields/room/house4"
   ]));
   set_door("door","/d/koenig/fields/room/house4","east",0);
   set_door_description("door","A simple wooden door set with a "+
      "small window near the top.");
}

string house_desc() {
   if(query_night()) {
     return(
       "%^YELLOW%^A cheerful light pours out of the windows of the "+
       "house to the east, allowing you to see a bit of the pathway "+
       "in front of you.  Thin curtains cover the windows, blocking "+
       "a view of the inside of the house.  Wispy %^CYAN%^puffs of "+
       "smoke %^YELLOW%^wind up out of the chimney into the sky."
     );
   } else {
     return(
       "The house to the east looks peaceful and pleasant.  Beneath "+
       "the two windows facing the path you can see %^ORANGE%^window "+
       "boxes %^RESET%^that hold various %^GREEN%^herbs%^RESET%^.  "+
       "%^BOLD%^%^BLUE%^Bright blue curtains %^RESET%^have been pulled "+
       "back to let in the daylight, but the %^RED%^front door %^RESET%^"+
       "stands closed.  The path seems to lead right to the door."
     );
   }
}
