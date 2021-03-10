#include <std.h>
inherit ROOM;

int FLAG;

void create(){
    ::create();
    set_name("Tharis caverns");
    set_short("A dark cavern");
    set_long(
	"You stand in a dark dreary cave. A large cobweb hangs across the "+
	"entire room blocking the north exit. A few torches light the room."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_listen("default","You can hear nothing but silence.");
    set_smell("default","The air still smells stale.");
    set_items( ([
	({"web"}):"This huge web encompasses the entire room blocking the north exit."
    ]) );
    set_exits( ([
	"south":"/d/tharis/caverns/cavern5",
	"north":"/d/tharis/caverns/cavern11"
    ]) );
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}
void init(){
    ::init();
    add_action("pull","pull");
}
int GoThroughDoor(string str) {
   if(query_verb() == "north") {
      if(FLAG != 1) {
         tell_object(TP,"You cannot walk through that big cobweb!");
         return 0;
      }
      return 1;
   }
}

int pull(string str){
   if(!str) {
      tell_object(TP,"Pull what?\n");
      return 0;
   }
   if(str == "web" || str == "cobweb") {
      if(FLAG == 1) {
         tell_object(TP,"The cobweb has already been pulled away!\n");
         return 0;
      }
      tell_object(TP,"You pull the cobweb down.");
      tell_room(ETP,""+TP->query_cap_name()+" pulls the cobweb down.",TP);
      FLAG = 1;
      return 1;
   }
}
