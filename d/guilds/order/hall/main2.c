//main.c

#include <std.h>

inherit ROOM;
inherit "/d/guilds/inherit/g_defen.c";

void init(){
     room::init();
     defen::init();
}

void create(){
   object ob;
   ::create();

   set_short("Main hall of the Order of metallic dragons.");
   set_long(
@OLI
    %^BOLD%^Castle courtyard of Tir-Na-Nog%^RESET%^
  %^CYAN%^The is the heart and soul to the castle, quite literally. For Tir-Na-Nog is built around the Great Oak, a mystical tree of great power, which serves to watch over and protect those located within its magical aura. To your north you see gates of Nog, and beside the gate rise two archer towers. All around you there are enterance leading into the castle itself. While at the far end of the courtyard is a small board, where members of the Order may voice their opinions.%^RESET%^
OLI
   );

    set_property("light",2);
    set_property("indoors",1);
  set_smell("default","The fresh scent of the Great Oak fills the courtyard.");
  set_listen("default","Very little sound disturbs the tranquility of the courtyard.");

   set_items(([
    "oak":"%^GREEN%^This great, majestic tree rises high above the castle walls, serving to protect those who lie within.%^RESET%^",
    "towers":"%^BOLD%^%^BLUE%^These two towers rise up far into the sky, serving to give defenders a clear view of the surrounding area.%^RESET%^"
      ]));
   set_exits(([
  "north":"/d/guilds/order/hall/enterance",
  "east":"/d/guilds/order/hall/treasury.c",
  "west":"/d/guilds/order/hall/assign"
   ]));

   ob= new(BBOARD);
   ob->set_name("board");
   ob->set_id(({"board","guild board"}));
  ob->set_board_id("orderguild");
   ob->set_max_posts(30);
  ob->set_location("/d/guilds/order/hall/main2.c");
   ob->set_short("Order of Metallic dragons' guild board");
   ob->set_long("This is the place for common posts to all the elite members of the Order.");

}
