#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
  set_property("light",2);
  set_long(
   "%^BOLD%^Torm's central park.\n"
   "%^GREEN%^The first thing you notice about Torm's park is how green it is"+
   " compared to the city outside the walls here. A path runs around the"+
   " park and at its center is an ornate mansion, almost a palace. %^YELLOW%^Butterflies%^GREEN%^"+
   " flit about the %^MAGENTA%^flowers%^GREEN%^ and the hedges that line the paths. A small"+
   " %^CYAN%^stream%^GREEN%^ runs along the inside of the path, crossed by a small bridge at"+
   " the south of the mansion where the path leads up to its great steps."
  );
  set("night long",
  "%^BLUE%^"
   "A light fog covers the ground of the park. The path that runs around"+
   " the park shimmers almost magically as the fog collects there and"+
   " drifts into the streambed. The mansion in the center of the park"+
   " still has its lights on, although most of them are on the second"+
   " floor, probably the politicians burning the midnight oil while the"+
   " servants get some rest."
  );
    set_short("Torm's central park");
    set_smell("default","You smell the fragrances of many flowers and roses.");
   if(query_night()) {
      set_listen("default","You hear the distant waves crashing against"+
      " the rocks.");
   }
   else {
      set_listen("default","A few birds chirp faintly with the sound of"+
     " the waves pounding in the background.");
  }
  set_items(([
  "flowers" : "%^MAGENTA%^Many small flowers are planted about the bases of"+
  " the tree here.  They smell so sweet and there is an amazing variaty of"+
  " colors.%^RESET%^",
  (({"tree","trees"})) : "%^GREEN%^There are a few blossoming trees scattered"+
  " about the park.%^RESET%^",
  (({"butterflys","butterflies"})) : "%^YELLOW%^Multi-colored butterflies"+
  " flitter about the flowers and bushes.%^RESET%^",
  "stream" : "%^BOLD%^%^CYAN%^This small stream runs with cool blue looking"+
  " water around the park alongside the inner edge of the path.  A small"+
  " bridge crosses it at the south of the mansion where the path goes.%^RESET%^",
  "bridge" : "It's a strong looking structure without rails. Its wood"+
  " construction shows signs of heavy use but no signs of failing.",
  (({"path","paths"})) : "%^RED%^The paths are lined with small hedge"+
  " bushes and are paved in red and brown bricks to compliment the green of"+
  " the grass.%^RESET%^",
  (({"lawn","grass"})) : "%^BOLD%^%^GREEN%^The lawn is well manicured and"+
  " very green at all times of the year.  You're pretty sure some magic is"+
  " at work here to keep the park so nice.%^RESET%^",
  (({"bushes","bush","hedge","hedges"})) : "%^GREEN%^Small green hedges line the paths.%^RESET%^",
   (({"mansion","building"})) : "A large, ornate mansion sits at the center"+
   " of the park, you have the feeling this was all just its grounds before"+
   " it was converted over to the city park.",
   "fog" : "A light fog blankets the ground of the park at night,"+
   " mostly staying close to the streambed.",
  ]));
}

void reset(){
   ::reset();
   if(!(query_night())){
      if(!present("butterfly") && !random(4)){
         new(MON+"butterfly.c")->move(TO);
      }
      if(!present("citizen") && !random(2)){
         new(MON+"citizen.c")->move(TO);
      }
   }
}
