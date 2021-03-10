#include <std.h>
#include <objects.h>

inherit "/d/deku/inherits/vexia-lair.c";

int pulled;

void create() {
    ::create();
    set_short("Reception Chamber");
    set_long(
@KAYLA
The huge door swings into a dusty torchlit room with solid stone walls.
Torch brackets are set in the wall every 10' but only one holds a 
burning torch.  On the west side of the room, semicircular stairs lead 
up to a 30' wide dais.  In the western wall of the dais, another door 
is set deeply into the wall.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/open/cave_r1"
    ] ));
    set_items(([
      ({"steps", "stairs"}) : "Chiseled into the steps of the dais are runes "
         "or glyphs of some kind although you can't make out any meaning.",
      ({"door", "western door"}):"The western door is made of split oaken logs "
         "bound together with iron strips and coated with some kind of sticky, "
         "resilient pitch.  Door latches and levers are iron.  Perhaps you "
         "could open it if you tried.",
      ({"torch", "torches", "brackets"}) :"Something does seem a little odd "
         "about the bracket on the torch that's burning.",
      "dais": "A raised platform that the steps lead up to.  It's empty except "
         "for the door on the west wall.",
    ] ));
}

void init() {
  ::init();
  add_action("search","search");
  add_action("open","open");
  add_action("pull","pull");
  add_action("pull","push");
  add_action("pull","move");
}

int search(string str) {
  if(!str) {
    write("Search what?");
    return 1;
  }
  if (str == "room" || str == "torch" || str == "bracket") {
    write("You search the "+str+" and find that the bracket holding the "
          "burning torch could be used as some kind of lever, maybe to "
          "open some secret door.");
    tell_room(ETP,TPQCN+" discovers a lever.",TP);
  return 1;
  }
}

int pull(string str) {
   object obj;
  if(!str) {
    write("Push or move what?");
    return 1;
  }
   if(sizeof(TP->query_attackers()) > 0){
    write("There are monsters in the room, you cannot do that right now!");
    return 1;
  }
  if (str == "lever") {
    write("You must push or move the lever upward or downward.");
    return 1;
  }
  if (str == "lever downward") {
    write("You move the lever downward but nothing seems to happen.");
    if(pulled)  return 1;
    tell_room(ETP,"While "+TPQCN+" moves the lever downward, you notice a small "                              "opening in the wall form and a scroll drop from it silently",TP);
     obj=new("/d/magic/scroll");
     obj->set_spell(3);
     obj->move(TO);
    pulled = 1;
    return 1;
  }
  if (str == "lever upward") {
    write("As you move the lever upward a secret door opens to the north.");
    tell_room(ETP,TPQCN+" moves the lever upward.", TP);
    tell_room(ETP,"A secret door opens to the north.", TP);
    write("%^BOLD%^You move through the northern secret door, ready or not!");
    TP->move_player("/d/deku/open/cave_r2");
    tell_room(ETP, TPQCN+" disappears through the northern exit.", TP);
    return 1;
  }
}

int open(string str) {
  if(!str) {
    write("Open what?");
    return 1;
  }
  if (str == "door") {
    write("Open which door?");
    return 1;
  }
  if (str != "west door" && str != "western door") {
    write("You cannot open that!");
    return 1;
  }
  write("You try to open the western door.  What a mistake, for it was a trap!\n"
    "Spears are lauched from both the north and south walls!!\n");
  tell_room(ETP, TPQCN+" tries to open the western door.\n"
    "What a mistake that was, for spears lauch from both the north and south "
    "walls!!", TP);
  TP->do_damage("torso",random(10));
  return 1;
}

void reset() {
  ::reset();
  pulled = 0;
  if(!present("centaur") && !random(2)) {
    new("/d/deku/monster/centaur")->move(TO);
    new("/d/deku/monster/centaur")->move(TO);
    new("/d/deku/monster/centaur")->move(TO);
  if(!random(3))  new("/d/deku/monster/centaur")->move(TO);
  }
}
