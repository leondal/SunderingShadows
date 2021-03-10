#include <std.h>
inherit MONSTER;
create() {
        ::create();
        set_name("dog");
        set_id( ({ "dog" }) );
        set("race", "dog");
        set_gender("male");
set_short("A golden dog");
set_level(1);
set_long("This is a golden dog, perhaps you could pet it.");
set_wielding_limbs( ({ "right foot", "left foot", "right paw", "left paw", "mouth" }) );
set_alignment(9);
set("aggressive", 1);
set_hd(15,4);
set_body_type("quadruped");
}

void init()
{
   ::init();
   add_action("pet","pet");
}
pet(string str)
{
 if(str != "dog") {return 0;}
write("You pet the dog for a moment, then he looks up at you.  "
"You looks confused for a while, then you see the dog dropa pouch from his mouth.  "
"You open the pouch and notice that there is a bunch of gold in it.  "
"As you look back at the dog, he stands up and runs off, for his job is done.  "
"You pick up the 100000 gold coins, and then ponder about how much money that is.");
if(str=="dog") this_player()->add_money( "gold", 100000);
destruct(TO);
return 1;
}
