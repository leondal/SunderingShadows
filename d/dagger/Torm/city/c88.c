#include <std.h>
#include "../tormdefs.h"
inherit BOARDWALK;

void create()  {
  ::create();
  set_long(""+::query_long()+"  You notice a signpost has been set at the entrance to this long wide pier, with a plaque on it.");
  set_exits(([
  "west":TCITY+"c87",
  ]));
  add_item("plaque","  %^YELLOW%^##################################\n"
"  %^YELLOW%^#                                %^YELLOW%^#\n"
"  %^YELLOW%^#     %^CYAN%^Windsail Harbor Pier       %^YELLOW%^#\n"
"  %^YELLOW%^# %^WHITE%^Donated by Val-Toran of Gigi's %^YELLOW%^#\n"
"  %^YELLOW%^#   %^WHITE%^Lifeday, 5 Sundays 670 SG    %^YELLOW%^#\n"
"  %^YELLOW%^#                                %^YELLOW%^#\n"
"  %^YELLOW%^##################################\n");
}

void reset(){
  ::reset();
  if(query_night()) return;
  if(!present("dock worker",TO)) {
     new(MON+"dockworker.c")->move(TO);
     new(MON+"dockworker.c")->move(TO);
  }
}