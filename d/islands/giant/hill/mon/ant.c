#include "/d/islands/giant/giant.h"

inherit MONSTER;

void create(){
   ::create();
   set_name("ant");
   set_id(({"ant"}));
   set_short("A small ant");
   set_long("This is a tiny black ant");
   set_race("ant");
   set_gender("male");
   set_body_type("bug");
   set_hd(1,1);
   set_max_hp(1);
   set_hp(1);
   set_overall_ac(10);
   set_size(1);
}

void init(){
   ::init();
   tell_room(ETO, "A small black ant scuttles into the room");
}
