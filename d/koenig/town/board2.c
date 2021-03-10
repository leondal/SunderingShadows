#include <std.h>
inherit ROOM;

void create() {
  object ob;
  ::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
  set_property("light", 1);
  set_property("indoors", 1);
   set_short("Short Story Room");
  set_long("%^MAGENTA%^Books and papers, some blank and some not, litter the tops of %^ORANGE%^tables "+
  "%^MAGENTA%^in this cozy room. Here is where the %^BOLD%^storytellers %^RESET%^%^MAGENTA%^come to "+ 
  "capture their minds and hearts within the pages of a book. %^BOLD%^%^BLACK%^Inkpots "+ 
  "%^RESET%^%^MAGENTA%^and %^BOLD%^%^BLACK%^quills %^RESET%^%^MAGENTA%^are placed randomly "+ 
  "around the room, assuring a utensil is always within grasp for when inspiration strikes. "+ 
  "Here, writers share their experiences, their fears, their dreams and their tragedies. Be welcome "+ 
  "%^BOLD%^daydreamers and wishers%^RESET%^%^MAGENTA%^, for here is where fantasies are born.%^WHITE%^\n");
  set_smell("default", "It smells of paper and ink.");
  set_listen("default", "You can hear the soft rustle of paper as a breeze blows through an open window.");
  ob = new(BBOARD);
  ob->set_name("board");
  ob->set_id( ({"board","short stories board","short stories","stories"}) );
  ob->set_board_id("ShortStories");
  ob->set_max_posts(30);
  ob->set_location("/d/koenig/town/board2");
  ob->set("short","Short Stories Board");
  ob->set("long","This is the short story board where you can shares your adventures and dreams.");
  set_exits( ([
     "west":"/d/koenig/town/stable2"
]) );
}
