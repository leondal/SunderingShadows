#include <std.h>
 
inherit ROOM;
 
object ranger;
int bribe;
 
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
    set_short("Shadowlord forest");
    set_long(
@KAYLA
%^ORANGE%^This seems to be the only pass that leads to the Fortress.  Ahead is a bridge that crosses the river to it.  All along this route there is an ominous silence of something waiting to happen.  Cold drafts howl through the cracks in the old planks of the bridge to the east and send a shiver up your spine.
KAYLA
    );
    set_smell("default","The mist carries the smell of death and decay.");
    set_listen("default","You hear rushing water from the river to the east.");
    set_exits(([
          "west" : "/d/deku/open/pass",
          "east" : "/d/deku/open/bridge"
    ] ));
    set_items(([
    ] ));
}
 
void reset(){
  ::reset();
  if(!present("hermit") && !random(3)) {
    new("/d/deku/monster/hermit")->move(TO);
    return 1;
  }
}
 
void init() {
  ::init();
  add_action("east","east");
  add_action("bribe","bribe");
}
 
int east() {
  if(!present("hermit") || TP->query_true_invis()) {
    TP->move_player("/d/deku/open/bridge");
    return 1;
    } else {
    write("The %^RED%^Hermit%^RESET%^ won't let you pass onto the bridge.  "
    "He doesn't want your death on his mind...  As you look deeper into his "
    "eyes, you notice that he is very weary.  Perhaps there is a way to "
    "get him to let you pass.");
    say("The Hermit forbids "+TPQCN+" passage eastward.\n");
    return 1;
  }
}
 
int bribe(string str) {
   if(!str) {
    write("Bribe who?");
    write("%^MAGENTA%^The Hermit says:%^RESET%^ I'll let you pass for 75 gold coins.\n");
    return 1;
  }
  if(str == "hermit") {
    if( (int)TP->query_money("gold") < 50 ) {
      write("%^MAGENTA%^The Hermit says:%^RESET%^ You are too poor!\n");
      return 1;
    }
    write("You bribe the hermit and he lets you journey eastward.\n");
    say(TPQCN+" bribes the Hermit and moves eastward.\n");
    TP->add_money("gold", -50);
    TP->move_player("/d/deku/open/bridge");
    return 1;
  }
}
 
