#include <std.h>
inherit ROOM;

init() {
::init();
add_action("armband","pull");
}
void create(){
object ob;
    ::create();
set_short("The Inner Sanctum of the %^RED%^Iron Fist.");
	set_long(
@FIST
%^MAGENTA%^This is the Inner Sanctum of the %^RED%^Iron Fist%^MAGENTA%^.
%^MAGENTA%^Here members come from all across the realms to rest, and renew their ties to each other. The wood paneled walls are covered with objects that members have brought back from every corner of the world.
There are many comfortable chairs, all worn from continual use. A %^RED%^fire%^MAGENTA%^ roars in the huge fireplace, warming the room, and taking off the harsh chill.
%^MAGENTA%^Next to the door is a %^RED%^red velvet pull rope%^MAGENTA%^, behind it is a small plaque.
FIST
	);
set_property("no teleport",1);
set_light(2);
set_property("indoors",1);
set_property("no attack",1);
set_property("no steal",1);
set_property("no clean",1);
set_items((["rope":"This is a red velvet pull rope. You suspect it's connected to a bell.",
"plaque":"The plaque reads: Pull rope to replace your armband.",
"fireplace":"The fireplace is huge, so big you could stand inside, but you wouldn't want to, as it's currently filled with a huge fire.",
"chairs":"The chairs range from harsh wooden items, to leather covered easy chairs.",
"walls":"The walls are covered with exotic items ranging from a Drow longbow, to the head of a Thri-Kreen."
]));
	set_exits(([
      "enter":"/d/shadow/guilds/fist/hc_room.c",
"west":"/d/shadow/guilds/fist/guild2.c"
	]));
  set_invis_exits(({"enter"}));
  set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}));
set_smell("default","The biting aroma of fine whiskey blends with the soft smell of fine tobacco.");
set_listen("default","You hear tinkling of glasses, and soft conversation.");
ob= new(BBOARD);
ob->set_name("board");
ob->set_id(({"board","guild board"}));
ob->set_board_id("fistguild");
ob->set_max_posts(30);
ob->set_location("/d/shadow/guilds/fist/guild3.c");
ob->set_short("Iron Fist guild board");
ob->set_long("%^RED%^The Iron Fist%^MAGENTA%^ guild board, for fist members to brag and leave messages for each other");
}

int armband() {
    tell_object(this_player(),
"You pull on the rope.");
    tell_room(environment(this_player()),
(string)this_player()->query_cap_name()+" pulls on the rope.",
           ({ this_player() }) );
call_out("restore_armband",5);
    return 1;
}

int restore_armband() {
object armband;
    tell_object(this_player(),
"The smith hurries in, and clamps a new armband around your left bicep.");
    tell_room(environment(this_player()),
"The smith enters the room, and fits "+
(string)this_player()->query_cap_name()+" with a new armband.",
        ({ this_player() }) );
armband = new("/d/shadow/guilds/fist/fist_armband.c");
armband->move(this_player());
    return 1; 
}

int GoThroughDoor(){

  string name;
  name = TPQN;
  if(name!="coyotte" && name!="spider" && name!="oog" && name !="piezo" && !wizardp(TP)){
    tell_object(TP,"You are not allowed in there!\n");
    return 0;
  }
  else
    return 1;
}
