#include <std.h>
inherit MONSTER;
create() {
        ::create();
set_name("sally");
set_id(({ "sally" }));
set("race", "fighter");
set_gender("female");
set_short("Sally, Freddys' gal");
set_level(3);
set_long("Sally has devoted her life to Freddy.");
set_alignment(9);
set("aggressive", 5);
set_hd(15,4);
set_body_type("human");
new("/d/shadow/room/maze/weapon/stick.c")->move(this_object());
command("wield stick in left hand and right hand");
}

void init()
{
   ::init();
     add_action("kill","kill");
}
kill(string str)
{
 if(str != "sally") {return 0;}
if(str=="sally") new("/d/shadow/room/maze/mon/freddy.c")->move(environment(TP));
if(str=="sally") new("/d/shadow/room/maze/mon/sammy.c")->move(environment(TP));
write("Sally out smarts you, and yells for her boy friend.\n Sally runs away, and then you see freddy and sammy come into the room.");
destruct(TO);
return 1;
}
