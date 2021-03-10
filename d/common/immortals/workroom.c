#include <std.h>
inherit ROOM;

void create()
{
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_property("no sticks",1);
        set_property("no teleport",1);
        set_property("no starve",1);
        set_property("no magic",1);
	set_property("no steal",1);

        set_short("%^RED%^An Empty Workroom%^RESET%^");
        set_long(
@WORKROOM
%^RED%^An Empty Workroom%^RESET%^
This room is rather empty, and full of possibilities.  You probably should
decorate it somewhat when you are ready to do so.

%^ORANGE%^Sign: %^YELLOW%^42.%^RESET%^
WORKROOM
        );
        set_smell("default","You smell nothing.");
        set_listen("default","You hear nothing.");
        set_items(([
]));
        set_exits(([
        "out" : "/d/common/immortals/builderlounge",
        ]));
}

void init()

{
        ::init();
}

void reset() {
  object ob;
  ::reset();
  if (!objectp(present(getuid(TO)+"_board"))) {
     ob = new("std/bboard");
     ob->set_name(getuid(TO)+"board");
     ob->set_id( ({ "board", getuid(TO)+"_board", "my board" }) );
     ob->set_board_id(geteuid(TO)+"_board");
     ob->set("short", "A New Board");
     ob->set("long", "A board for a new builder. Probably you!\n");
     ob->set_max_posts(20);
     ob->set_ooc_board(1);
     ob->set_restricted_read();
     ob->set_location(base_name(TO));
     ob->move(TO);
     ob->set_property("no steal",1);
     // Garrett has no idea why that is there. He thinks it is a mistake.

  }
}
