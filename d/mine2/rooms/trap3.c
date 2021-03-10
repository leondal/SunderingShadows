#include <std.h>
#include <objects.h>

inherit "/d/mine2/mine.c";

inherit ROOM;
object ob;
void create() {
          ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("mine trap 3");
    set_long(""
"%^RED%^ "
"You are standing on a small rock, that has lava all around it.  There a small "
"rope that is hanging from the side of the wall.  The hot air makes you sweat "
"like a pig!.  "
""
"");

     set_listen("default","You hear lava bubble.");
     set_smell("default","You smell hot lava.");




    set_items(([
         "cavern" : "It is a large filled with lava.",
         "lava" : "It is very hot, and could kill you in one slashm.",
         "rope" : "It is far away, but you could probably grab it.",
         "shaft" : "It is filled with lava .",
         "walls" : "There is a rope on one of the walls.",
         "rock" : "It is very small, and hard to keep your balance on.",
         "ground" : "It is lava.",
    ] ));
set_max_mining(1);
set_chance(0);
set_max_find(0);
set_nugget( ([ "1":1, ]) );
}
void init()
{
  ::init();
write("%^RED%^As you enter the room, you fall down a long shaft.  You end up on a hot lava room, standing no a small rock!");
say("Someone joins you.");
add_action("grab","grab");
}
int grab(string str) {
if(str != "rope")  {return 0;}
 if(!ob || member_array(ob, all_inventory(this_object())) == -1)
     if(random(5) == 1)
     {

      switch(random(5))
        {
        case 0: ob  = this_player()->move_player("/d/shadow/room/grassland/grass18");
            write("As you jump for the rope, you catch it and swing out a hole.\nWhen you go through the hole, you notice that you are in the grass lands.");
                  break;
        case 1: ob  = this_player()->add_hp(-20);
          write("As you jump for the rope, you catch your foot on a laval bubble.");
                  break;
        case 2: ob  = this_player()->add_hp(-30);
          write("As you jump for the rope, you slip and you fall into the lava, but get back onto the rock.");
                  break;
        case 3: ob  = this_player()->add_hp(-40);
          write("As you jump for the rope, you slip and fall into the lava.  You almost die!");
                  break;
        case 4: ob  = this_player()->add_hp(-50);
          write("As you jump for the rope, you slip and flal into the lava, and you know you are going to die!");
                  break;
   }
}
    return 1;
}
