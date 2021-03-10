#include <std.h>

int found = 0;
inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_short("Thessingthorn's Tree house");
    set_long(
@KAYLA
This is the stick mansion of Thessingthorn, the greenhag.  It is made of
a collection of wooden log walls and floors at various angles.  The
tree house is a bizarre, twisting series of rooms with no determinable
halls or pattern whatsoever.  There is a large iron cauldron in the
center of the tree house.
There is a trapdoor leading down to the clearing.
KAYLA
    );
   set_smell("default","A rather sickening smell is coming from the cauldron.");
    set_exits(([
       "out" : "/d/deku/open/clear2"
    ] ));
    set_items(([
          "cauldron":"This is where Thessingthorn, the greenhag, makes potions"
                    " and other magical things...  The large pot is 4' tall"
                    " and 4' wide at the mouth.  There seems to be something"
                    " in this cauldron."
    ] ));
  found = 0;
}

void init(){
  ::init();
  add_action("out","out");
  add_action("search","search");
}

int out() {
  say(this_player()->query_cap_name()+" leaves through the trapdoor.");
  write("You leave the treehouse through the trapdoor.");
  write("\n");
  say("\n");
  this_player()->move_player("/d/deku/open/clear2");
  return 1;
}

int search(string str) {
   object obj;
   if(!str) {
      write("Search what?\n");
      return 1;
   }
  if(present("hag")) {
    write("The seahag won't let you search anything in her tree house.");
    return 1;
  }
   if(present("guard") && (string)present("guard")->query_name() == "bugbear") {
    write("The seahag's pets won't let you search anything in the tree house.");
    return 1;
  }
   if(present("ogre guard")) {
    write("The seahag's pets won't let you search anything in the tree house.");
    return 1;
  }
  if (str == "cauldron" ) {
    say(this_player()->query_cap_name()+" searches the cauldron and finds nothing.");
    write("You search the cauldron and find skulls and bones mixed within the dirty water.");
  return 1;
  }
   if(str == "water") {
  if(found) {
    write("You don't find anything in the dirty water.");
    return 1;
  } else {
     write("You find a purple stone in the dirty water.");
    say(this_player()->query_cap_name()+" searches the dirty water and finds a purple stone.");
    new("/d/deku/misc/purple")->move(ETP);
    found = 1;
    return 1;
  }
  }
}

void reset() {
  ::reset();
  if(!present("hag")) {
    new("/d/deku/monster/thess")->move(this_object());
  }
  if(!present("bugbear")) {
    new("/d/deku/monster/bugbear")->move(this_object());
    new("/d/deku/monster/bugbear")->move(this_object());
    new("/d/deku/monster/bugbear")->move(this_object());
  }
  if(!present("ogre")) {
    new("/d/deku/monster/ogre1")->move(this_object());
  }
  if(found) {
    found = 0;
  }
}
