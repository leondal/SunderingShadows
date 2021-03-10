#include "../cave.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , 1);
    set_property("indoors" , 1);
    set_property("no sticks", 1);
    set_terrain(NAT_CAVE);
    set_travel(RUBBLE);
    set_short("Dragon's Den Caverns");
    set_long(
      "%^BOLD%^You are in the Dragon's Den Caverns.%^RESET%^
%^ORANGE%^Ths narrow opening in the mountain wall leads to this large cavern. The rounded cavern has solid, rough walls, and the air feels cool and damp. The floor is covered with a light dusting of dirt and rock, though it seems to be worn quite smooth. A large hole near the western end of the cavern seems to lead to another cavern below. You can try to <descend> here."
);
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats and dripping water.");
    set_exits((["exit" : PASSDIR+"pass10",
                //"north" : "/d/shadow/guilds/pack/bridge1"]));
]));
//  set_invis_exits( ({"north"}) );
    set_climb_exits((["descend":({ CAVEDIR+"cave2",10,6,100})]));
    set_fall_desc(
@FALL
You fall down about 50 feet. You land on some rocks and other debris. Pain racks your body.
FALL
);

}

void reset(){
   ::reset();
   if(!present("area sign")) new("/d/common/obj/areas/dd_sign")->move(TO);
}
