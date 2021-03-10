
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Library");
        set_long("
    This is a great library!  The ceiling is just above you.  High up on a balcony that circles the room, you can look down past another level to see the floor and rows of bookcases.  Two large chandeliers hang far above you and decend into the room on chains.  A ladder here links this floor to the ones above it!
");
       set_exits(([
       "south" : "/d/attaya/tower/hall26",
       "west" : "/d/attaya/tower/hall24",
       "ladder" : "/d/attaya/tower/hallb1",
]));
       set_items(([
    "floor" : "A blue and gold carpet covers the marble floor.",
    "carpet" : "The carpet is mostly comprised of interlocking gold embroidered triangles upon a field if deep blue.  It is stained with blood.",
    "walls" : "The walls are comprised of decorated tiles.",
    "railing" : "It is brass and surrounds the walkway.",
    "chandeliers" : "The two chandeliers are not all that far away, perhaps you could jump to them if you really wanted to.",
    "chandelier" : "The chandelier is not all that far away, perhaps you could jump to it if you really wanted to.",
    "books" : "The books range in size, color, age, and type.",
    "ceiling" : "The ceiling is lavishly decorated with colored tiles and patterns.",
    "chain" : "The chain holds the great chandelier...  It must be under enormous strain!",
    "chains" : "The chains hold the great chandeliers...  They must be under enormous strain!",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void reset(){
        ::reset();
    if(!present("bookcase"))
     new("d/attaya/obj/chair")->move(this_object());
     new("d/attaya/obj/chair")->move(this_object());
   if(!present("bookcase"))
     new("d/attaya/obj/bookcase3")->move(this_object());
}
void init() {
  ::init();
   add_action("jump", "jump");
}
int jump(string str) {
  if(str=="chandelier") {
  write("You jump to the chandelier.\n");
  say((string)this_player()->query_cap_name()+" jumps to the chandelier.\n");
    tell_room(TO,"%^BOLD%^%^RED%^The chain snaps and the chandelier crashes to the floor below!");
  this_player()->move_player("/d/attaya/tower/floor1");
  write("%^BOLD%^%^CYAN%^The chandelier smashes against a row of bookcases and your fall is broken somewhat!");
 return 1;
}
  return 0;
}
