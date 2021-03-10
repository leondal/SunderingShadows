#include <std.h>

inherit VAULT;

void create(){
   ::create();

   set_property("indoors",1);
   set_property("light",2);
   set_short("Library of the Consortium");
   set_long(
   "   %^ORANGE%^Library of the Consortium%^RESET%^\n"+
   "You have entered the storeroom of the library.  Here lies many books on"+
   " portable carts waiting to be put back on the shelves for future readers.  Two"+
   " tables set in the center of the room with spilled ink and blotched papers over"+
   " top of them.  The room is dimly candlelit and it seems as though someone was"+
   " just in here.  Funny you didn't see them leave.  On the walls are several"+
   " shelves of scrolls, papers, and various supplies.  You can see finger-prints in"+
   " the dust on one of the scrolls.\n"
   );

   set_smell("default","This room is musty. Obviously there are some forgotten tomes here.");
   set_listen("default","There is only the slight rustle from the rooms below.");

   set_items(([
              "scrolls":"Most of these scrolls are ancient. Some are cracking and fading. Amongst the older scrolls are newer scrolls.",
              "paper":"The paper here is used by the sages to transcribe scrolls and information.",
              "supplies":"These supplies include quills, ink, and various other implements of scribing.",
              ]));
   set_exits(([
              "down":"/d/guilds/consortium/hall/library",
              "hall":"/d/guilds/consortium/hall/main",
              ]));
   set_invis_exits(({"hall"}));

   set_post_exit_functions(({"hall"}),({"southFunc"}));


}

void init(){
   ::init();

   add_action("lift_scroll","lift");
   
}

int lift_scroll(string str){
   if (!str) {
      return 0;

   }

   if (TP->query_bound() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if (str != "scroll") {
      return notify_fail("Lift what?\n");

   }

   tell_object(TP,"A door to the Consortium hall reveals itself to you.");
    tell_room(TO, TPQCN+" reaches over and lifts a scroll on the table, and places it back down on the table.  As "+TP->query_subjective()+" replaces it, a door into a hall is revealed.", TP);

   
   set_open("hall door",1);
   set_locked("hall door",0);
   remove_invis_exit("hall");
   return 1;
}

void southFunc(){
   
   set_open("hall door",0);
   set_locked("hall door",1);
   set_invis_exits(({"hall"}));
   write("The door closes behind you.");  
   tell_room(TO,"As "+TPQCN+" walks through the door it closes and is then gone.");
}
