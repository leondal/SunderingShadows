#define owner "abolition"
#define SAVE_PATH "/d/mine2/virtualocean/boats/"+owner+"room.c"
#include <std.h>
inherit MONSTER;
object shiproom;
void create() {
   object ob;
    ::create();
 if(ob = find_player(owner))
	set_short(ob->query_cap_name()+"'s ship");
else set_short("someone's ship");
set_name(owner+"'s ship");
set_id(( { "abolition's ship", "psfvo" } ));
        set("long","This is a large sailboat");
set_race("sailboat");
set_gender("male");
set_class("boat");
set_hp(100);
  shiproom=find_object_or_load(SAVE_PATH);
}
init() {
  ::init();
add_action("mon_look","mon_look");
}
int mon_look()
{
  string tmp;
  object env;
object monster;
monster=this_object();
  env = environment(monster);
  message("room_description", (string)env->query_long(0), monster);
  message("room_exits", (string)env->query_long_exits(), monster);
  if( ( tmp = (string)env->describe_living_contents( ({ monster }) ) ) !=
"" )
    message("living_item", tmp, monster);
  if( ( tmp = (string)env->describe_item_contents( ({ }) ) ) != "" )
    message("inanimate_item", tmp, monster);
}
