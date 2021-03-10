#include <std.h>
#include <objects.h>



inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Hidden passage.");
    set_long("
    You stand within a part of the fortress which was for some unseen reason sealed off.  Rubble covers the floor everywhere.  This is a junction of two hallways that run west and south from here.  The large door that once lead to the library has been bricked up.
    Some of the bricks are missing, leaving a hole just big enough to squeeze through.

");

     set_smell("default","It is very calm in here.");
 
    set_exits(([
    "west" : "/d/attaya/tower/hall32",
    "south" : "/d/attaya/tower/hall28",


    ] ));
   set_items(([
    "opening" : "A few bricks have fallen from the wall, and an opening is here, near the floor where you could squeeze through...  mabye.",
    "rubble" : "Mostly bricks, and various wooden planks, nails, plaster and stone fragments, and metal shards.",
]));
}

void reset(){
       int num, i;
      ::reset();
       if(!present("entity")){
                num = random(4)+1;
                for(i=0;i<num;i++)
                       new("/d/attaya/mon/entity")->move(TO);
    }
}
void init() {
  ::init();
  add_action("squeeze", "squeeze");
}
int squeeze(string str) {
  if(str=="through opening") {
  write("You carefully squeeze through the small opening in the bricks.\n");
  say((string)this_player()->query_cap_name()+" squeezes through the small opening in the bricks.\n");
  this_player()->move_player("/d/attaya/tower/hall25");
  return 1;
}
  return 0;
}
