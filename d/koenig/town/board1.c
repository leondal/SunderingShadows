#include <std.h>
inherit ROOM;

void create() {
  object ob;
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("Poetry Room");
  set_long("%^CYAN%^The room is filled with comfortable "+
  "%^BOLD%^%^MAGENTA%^f%^RESET%^%^MAGENTA%^u%^BOLD%^rnitu%^RESET%^%^MAGENTA%^r%^BOLD%^e%^RESET%^%^CYAN%^, "+
  "and %^ORANGE%^tables %^CYAN%^seem to have been liberally dispersed throughout the room. "+ 
  "Two of the far walls are lined with shelves that are filled from top to bottom with "+ 
  "all sorts of %^WHITE%^books%^CYAN%^. Stacks of %^BOLD%^%^WHITE%^w%^RESET%^r%^BOLD%^iti%^RESET%^n%^BOLD%^g "+ 
  "p%^RESET%^a%^BOLD%^per%^RESET%^%^CYAN%^, used and blank alike, fill a shelf all their own. "+ 
  "There are several %^BOLD%^%^BLACK%^inkpots %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^writing quills %^RESET%^%^CYAN%^on yet "+ 
  "another shelf. This room has a warm feel to it. And you can sense that many a great work has been written here. "+ 
  "This is a room for love and sorrow and joy and pain and rage, for %^BOLD%^creativity %^RESET%^%^CYAN%^and "+ 
  "%^BOLD%^freedom %^RESET%^%^CYAN%^and a love of words.%^WHITE%^\n");
  set_smell("default", "It smells of paper and ink.");
  set_listen("default", "You can hear the soft rustle of paper as a breeze blows through an open window.");
  ob = new(BBOARD);
  ob->set_name("board");
  ob->set_id( ({"board","poetry board","poetry"}) );
  ob->set_board_id("Poetry");
  ob->set_max_posts(40);
  ob->set_location("/d/koenig/town/board1");
  ob->set("short","Poetry Board");
  ob->set("long","Poets from near and far, old and new, have left their hearts here in poetry and prose.");
  set_exits( ([
     "east":"/d/koenig/town/stable2"
]) );
}
