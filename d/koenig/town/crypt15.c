#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_name("crypt15");
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Room Far Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^Well there are only two directions to go here. Either back the way you came, or down. Which shall you choose?%^RESET%^\n");
  set_exits( ([
     "west" : "/d/koenig/town/crypt14.c",
     "down" : "/d/koenig/town/crypt1.c"
]) );
  set_trap_functions( ({"down"}),({"rock_fall"}),({"down"}) );
}
void rock_fall() {
  	int rocks, damage;
  	tell_object(TP,"%^BOLD%^%^BLACK%^As you start move across the floor you trip over "+
  		"some rubble and fall against the wall.%^RESET%^");
  	tell_object(TP,"%^BOLD%^%^BLACK%^A section of wall sinks back.");
  	tell_object(TP,"%^CYAN%^...You get the feeling today just isn't your day.");
  	tell_object(TP,"%^RESET%^%^ORANGE%^You hear a rumbling above your head as though something "+
  		"is giving way.");
  	TP->force_me("emote grimaces!");
  	tell_room(ETP,"You see "+TPQCN+" trip over some rubble and fall "+
  		"against the wall.", TP);
  	tell_room(ETP,"You see the section of wall they have landed against "+
  		"sink back with a slow grinding sound.", TP);
  	tell_room(ETP,"The room shudders.");
  	tell_room(ETP,"You see a section of the ceiling start to "+
  		"fall on "+TPQCN+"'s head.", TP);
  	tell_object(TP,"%^BOLD%^%^RED%^The ceiling starts to fall on you!");
  	rocks = random(4)+1;
  	damage = random(10)+1;
  	TP->do_damage("torso",(damage*rocks));
	TP->add_attacker(TO);
	TP->continue_attack();
}
