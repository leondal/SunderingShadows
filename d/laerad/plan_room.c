#include <std.h>

inherit ROOM;

object ob;

void create() {
  ::create();
  set_property("no teleport",1);
  set_property("indoors",1);
  set_property("light",2);
  set_short("A small stone chamber.");
  set_long(
  "%^RESET%^BOLD%^A small stone chamber...%^RESET%^\n"+
  "You find yourself in a small, cramped chamber. Scattered about "+
  "the room are stray maps, rusty tools, and trash. Various "+
  "blue-prints are posted against the walls, and a large-oak table "+
  "rests in the center of the room, surrounded by several chairs. "+
  "A lit lantern hangs from the ceiling.");
    set_smell("default","The smell of ink and wet paper fill the room.");
    set_listen("default","Only the scratching of a quill on paper can be heard.");
  set_exits(([
   	"baneroom":"/realms/bane/workroom",
	"dock":"/d/shadow/virtual/sea/laerad.dock",
  ]));
  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id(({"board"}));
  ob->set_board_id("laerad");
  ob->set_max_posts(40);
  ob->set_location("d/laerad/plan_room");
  ob->set_short("The Planning Board of Laerad Island");   
  ob->set_long(
  "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"+
  "Laerad's Planning Board -- Ideas, Suggests, Etc.\n"+
  "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  ob->set_property("no steal",1);
}
