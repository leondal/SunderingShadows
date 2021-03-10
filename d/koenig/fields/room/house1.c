//house1.c - Coded by Circe 1/1/04
#include <std.h>
inherit ROOM; 

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
   set_name("Near a vast cornfield"); 
   set_short("Near a vast cornfield"); 
   set_long("Just to the south lie the %^BOLD%^%^GREEN%^cornfields "+
      "%^RESET%^that stretch as far as you can see from here.  This "+
      "narrow trail winds its way into the %^ORANGE%^woods %^RESET%^"+
      "just north of the %^BOLD%^%^GREEN%^cornfields %^RESET%^and looks to round "+
      "a bend just to the north.  The %^BOLD%^%^BLUE%^pathway %^RESET%^"+
      "looks to be made by the travelling of feet steadily across it, "+
      "although it doesn't seem to see heavy use.\n");
   set("night long","%^GREEN%^This narrow path winds its way out of the "+
      "%^BOLD%^cornfields %^RESET%^%^GREEN%^to the south.  Looking back "+
      "that way, the %^YELLOW%^cornstalks %^RESET%^%^GREEN%^rise up and "+
      "stretch eerily over the land.  Their shapes cast deep %^BOLD%^%^BLACK%^"+
      "shadows %^RESET%^%^GREEN%^along the ground, and you think it might "+
      "be difficult to find your way through it at night.  This %^ORANGE%^"+
      "path %^GREEN%^seems clear enough, though, and it seems to lead around "+
      "a bend into the woods to the north.\n");
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
      ({"corn","fields","cornfields","field"}) : "To the south is a vast field "+
         "where %^YELLOW%^corn %^RESET%^is grown.  It seems that many hands must "+
         "help in maintaining and planting the fields, and the food is probably "+
         "sold to nearby cities."
   ]));
   set_exits(([
      "southeast" : "/d/koenig/fields/room/field1",
      "north" : "/d/koenig/fields/room/house2"
   ]));
}