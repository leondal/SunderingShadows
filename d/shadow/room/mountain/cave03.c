//cave03.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this "+
      "tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic "+
      "workmanship suggest "+
      "that the dwarves who make their home here have expanded and "+
      "improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings "+
      "%^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every "+
      "fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along "+
      "the walls between the arches, "+
      "creating a sense of being in the open air despite the drab "+
      "walls of the tunnels.  A large "+
      "%^BLUE%^hole %^RESET%^dominates the center of the floor here.  "+
      "A large, %^BOLD%^%^BLACK%^black iron ring "+
      "%^RESET%^is pounded into the stone wall, and from it, a "+
      "%^ORANGE%^knotted rope %^RESET%^dangles."
      "\n"
    );
    add_item("hole","The large, round hole is centered in the tunnel here, and opens "+
      "into the darkness below.  It would probably be fairly difficult to move around.");
    add_item("ring","The black iron ring in the wall looks as though it would hold "+
      "quite a bit of weight.");
    add_item("rope","The sturdy rope hanging from the iron ring has been knotted at "+
      "intervals to provide better handholds for climbing.  It would probably make "+
      "the descent down below much easier and safer.");

    set_exits(([
        "south" : ROOMS"cave02",
        "down" : ROOMS"cave06",
        "north" : ROOMS"cave04"
        ]));
      set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
  int chance,num;
  int dam;
  num = random(20);
  chance = this_player()->query_stats("dexterity");
  if(chance < num) {
    tell_object(TP,"You try to move around the large hole, but lose your balance.");
    tell_room(ETP,""+TPQCN+" loses "+TP->query_possessive()+" balance and falls into the hole.",TP);
    tell_object(TP,"You fall into the hole, and hit the floor with a THUMP!");
    dam = random(6);
    this_player()->add_hp(-dam);
    this_player()->move_player(ROOMS"cave06");
    return 0;
  }
  tell_object(TP,"You manage to move around this large hole in the floor.");
  tell_room(ETP,""+TPQCN+" manages to move around the large hole.",TP);
  return 1;
}
