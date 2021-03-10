//Mechanics by Bane, Atmosphere by Vis
#include <std.h>
inherit ROOM;
void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_name("Daggerdale training room.");
  set_short("Healing Room");
  set_long(
"You have ended up in the healing room after being beaten by the trainer Mykadok.  Return and continue to practice."
  );
    set_property("indoors",1);
   set_property("arena",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("no attack",1);

set_light(2);
    set_exits( ([
      "out" : "/d/dagger/Daggerdale/shops/trainer.c",
    ]) );
  set_items(([
    "fountain":"If you drink from the fountain you will be healed."
  ]));
}

void init(){
  ::init();
  add_action("heal_me","drink");
}

int heal_me(string str){
  int fullhp;
  fullhp = TP->query_max_hp();
  TP->set_hp(fullhp);
  tell_object(TP,"You feel your wounds from battle healing completely.");
  return 1;
}

