#include <std.h>
inherit ROOM;

void create()
{
        object obj;
        ::create();
        set_property("no teleport",1);
        set_property("indoors",1);
        set_property("light",2);
        set_short("Standards Discussion Board");
        set_long(
        "This room is bare except for the large posting board in the center of it."+
        " It is where the avatars and wizzes can post their discussions about possible"+
        " standards for game play."
        );
        set_smell("default","You smell dusty tomes of lore.");
        set_listen("default","You hear voices debating at what point to levelcap someone.");
        obj = new("std/bboard");
        obj->set_name("board");
        obj->set_id(({"board", "bulletin board","standards board","posting board"}));
        obj->set_board_id("stds_board");
        obj->set_short("Standards Discussion Board");
        obj->set_long("This is a large board for avatars and wizzes to post about"+
        " discussions pertaining to standards of game play.");
        obj->set_max_posts(200);
        obj->set_location("/d/dagger/stdsboard.c");
        set_exits(([
        "south" : "/d/dagger/avalounge",
        "taborjail" : "/d/darkwood/tabor/room/jail",
        "library" : "/d/dagger/Torm/city/library1",
        ]));
}
