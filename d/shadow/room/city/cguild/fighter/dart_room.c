#include <std.h>

inherit ROOM;

void create() {
   ::create();
   set_short("Fighters guild");
   set_long("This is the Fighters guild.\n"
      "This is where all the fighters come to enjoy their life "
      "here in Shadow. There is a dartboard hanging over the "
      "wall at the far end. A line is drawn on the floor parallel "
      "to the wall. You think you can stand behind the line and "
      "have some game of darts with a few fellow fighters. A sign is "
      "on the wall.");
   set_items( (["dartboard":"It has nine concentric rings and a red "
      "bull's-eye at the center. The rings are marked 10, 20 ... 90 "
      "from outermost to the bull's-eye.",
      "line":"You should not try to cheat!",
      "wall":"It is quite distant from you.",
      "sign" : "This is where you can enjoy a game of darts with your fellow fighters.\n"
      "You can <throw dart> to play the game.\n"
      "You can <retrieve dart> to retrieve the dart from the dartboard "
      "and see how many darts are still left on the dartboard.\n"
      "If too many darts are already on the board, you need to retrieve "
      "some first.",]) );
   set_exits( (["south":"/d/shadow/room/city/cguild/fighter/fighter"]) );
   set_property("light",2);
   set_property("indoors",1);
//   set_property("no teleport",1);
}

void reset() {
    object ob;
   ::reset();
   if(!present("mastery list")) {
      new("/d/shadow/room/city/cguild/fighter/master_list")->move(TO);
   }
   if(!present("dartboard")) {
      new("/d/common/obj/misc/dart_board")->move(TO);
   }

}

