//Mechanics by Bane, Atmosphere by Vis
#include <std.h>
inherit ROOM;
void create(){
  ::create();
  set_name("Healing room of the %^RED%^Iron Fist.%^RESET%^");
  set_short("Healing Room");
  set_long(
@GUILD
%^BOLD%^The Healing Room of the %^RED%^Iron Fist%^RESET%^
This room is where the warriors of the %^RED%^Iron Fist%^RESET%^ who have been 
defeated by their brothers and sisters in arena combat go to
be healed.  There is a fountain in the center of the room.
GUILD
  );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_property("no attack",1);
set_light(2);
  set_listen("default","You hear the ghostly whispering of long dead warriors of the %^RED%^Iron Fist.");
  set_smell("default","You smell the odor of the old blood that has long since dried into the fine brown patina on the floor.");
    set_exits( ([
"north":"/d/shadow/guilds/fist/guild2.c"
    ]) );
  set_items(([
    "fountain":"If you %^BLUE%^drink%^RESET%^ from the fountain you will be healed."
  ]));
}

void init(){
  ::init();
  add_action("heal_me","drink");
}

int heal_me(string str){
  int fullhp;
  if((string)TP->query_guild()!="Iron Fist"){
    tell_object(TP,"%^BOLD%^You cannot be healed here unless you are a member of the %^RED%^Iron Fist%^RESET%^!");
    return 1;
  }
  fullhp = TP->query_max_hp();
  TP->set_hp(fullhp);
  tell_object(TP,"%^BLUE%^You feel your wounds from battle healing completely.");
  return 1;
}
