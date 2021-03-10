#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Hidden passage.");
    set_long("
    This is a once majectic hallway that now lies in a state of disrepair.  It has been sealed for who knows how long.  Rubble litters the floor.
    Huge walls of bricks block movement to the north and east.  The only obvious way to go is the way you came, but you can't help but sense that something is in fact here!

");

     set_smell("default","It is very calm in here.");
 
    set_exits(([
    "south" : "/d/attaya/tower/hall34",


    ] ));
   set_items(([
    "opening" : "A few bricks have fallen from the wall, and an opening is here, near the floor where you could squeeze through...  maybe.",
    "rubble" : "Mostly bricks, and various wooden planks, nails, plaster and stone fragments, and metal shards.",
    "walls" : "The bricked up doorways lie to the north and west.",
    "north wall" : "It is a wall of thick concrete bricks that is inpenetratable.",
    "east wall" : "It is a wall of thick concrete bricks.  Something has torn a large hole in it from the other side.  You might be able to squeeze through!",
]));
}

void reset(){
       int num, i;
      ::reset();
       if(!present("poltergeist")){
                num = random(4)+1;
                for(i=0;i<num;i++)
                       new("/d/attaya/mon/poltergeist")->move(TO);
    }
}
void init() {
  ::init();
  add_action("squeeze", "squeeze");
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
  TP->move_player("/d/attaya/tower/hall36");
  return 1;
}