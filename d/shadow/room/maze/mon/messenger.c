#include <std.h>

inherit MONSTER;

create() 
{
  ::create();

  set_name("messenger");
  set_id( ({"messenger"}) );
  set_class("fighter");
  set("race", "human");
  set_body_type("human");
  set_gender("male");
  set_short("A messenger of war.");
  set_long("He has a message to tell.");
set_level(1);
  set_emotes(10, ({
    "The messenger yells, RUN RUN RUN!!!!.",
    "The messenger of war runs in circles.",
    "The messenger says, THERE COMMING!!.",
    "The messenger of war says, There is an invasion coming!",
            }), 0);
  new("/realms/zeek/obj/scroll.c")->move(this_object());
  new("/realms/zeek/weapons/sword.c")->move(this_object());
set_hp(1);
}

init()
{
  ::init();
  force_me("wield sword");
}
