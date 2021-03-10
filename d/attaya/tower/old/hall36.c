#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Mysterious room");
    set_long("
    A lavish bedroom stretches out before you in the darkness.  Like wraiths, the furniture snaps into focus as your eyes adjust.  A few small dressers and a nightstand, a large cornerpiece with a mirror above it, and a grand four poster bed take shape around you.  It seems like such a fine room.
    As you walk around the room, you come across a grizzly sight.  Dusty bones lie in the bed, ropes still tied around the arms and legs.  Whoever this was, they were sealed inside.
    The bricked up doorway lies on the west wall and an open closet to the east.
    A pile of clothes lies at the floor beside the bed, coated in dust.

");

     set_smell("default","It is very calm in here.");
 
    set_exits(([
    "east" : "/d/attaya/tower/hall37",


    ] ));
   set_items(([
    "opening" : "A few bricks have fallen from the wall, and an opening is here, near the floor where you could squeeze through...  maybe.",
    "dressers" : "A few stained dressers rest against the walls.",
    "nightstand" : "The small black nightstand sits next to the bed, coated in dust.",
    "skeleton" : "The skeleton lies in the soft bed, the sheets around it are stained with the lacquer of rotting flesh from long ago.  The arms and legs of the skeleton are tied to the bedposts.",
    "cornerpiece" : "It is a desk that curves from the north wall to the east wall.  A large round mirror is just above it.",
    "mirror" : "You can see your reflection in the mirror",
    "bones" : "The skeleton lies in the soft bed, the sheets around it are stained with the lacquer of rotting flesh from long ago.  The arms and legs of the skeleton are tied to the bedposts.",
    "ropes" : "Thin but strong, the ropes are securely fastened to the bedposts, and hang loosely around the bones.",
    "closet" : "%^RED%^It looks scary.",
    "floor" : "The floor is made from hardwood tiles.",
    "clothes" : "They are the clothes of a woman.  They lie discarded in a pile of dust on the floor.",
    "bed" : "The beautiful hand carved four poster bed looks very comfortable if not for the skeleton.",
    "rubble" : "Mostly bricks, and various wooden planks, nails, plaster and stone fragments, and metal shards.",
    "wall" : "It is a wall of thick concrete bricks.  Something has torn a large hole in it from the other side.  You might be able to squeeze through!",
    "doorway" : "It is a wall of thick concrete bricks.  Something has torn a large hole in it that you might be able to squeeze through!",
]));
}

int squeeze(string str) {
  if(!str) {  
      tell_object(TP,"Squeeze through what?\n");
      return 1;
  }
  if(str !="through opening" && str != "through hole") {
      tell_object(TP,"Squeeze through what?\n");
      return 1;
  }
  write("You carefully squeeze through the small opening in the bricks.\n");
  tell_room(ETP,TPQCN+" squeezes through the small opening in the bricks.\n", TP);
  TP->move_player("/d/attaya/tower/hall35");
  return 1;
}

void init(){
   ::init();
      add_action("squeeze","squeeze");
}
