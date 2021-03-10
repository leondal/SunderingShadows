inherit "/std/room";


void create() {
     ::create();
     set_light(2);
     set_indoors(0);
     set_short("You are on the river of flame");
     set_long("
%^RED%^
    The vessel shall go no further.  You are at the other side of the molten river.  A long granite dock extends out to you from a tormented volcanic landscape.  Beyond, lies the rift valley and the jungles of Attaya Island.
    You can 'disembark' from the vessel here.
");
     set_smell("default", "The incredible heat and overpowering tang of molten metals forces you to cover your nose.\n");
set_listen("default", "Currents of flame crackle and pop around you.\n");
}
void init() {
     ::init();
add_action("jump_off", "jump");
add_action("motion", "motion");
  add_action("disembark", "disembark");
}
int jump_off(string str) {
write("%^BOLD%^You leap from the phantom vessel.\n");
say((string)this_player()->query_cap_name()+" leaps from the vessel into the river of flame.\n");
this_player()->move_player("/d/attaya/pain.c");
write("%^BOLD%^%^RED%^You are horribly burned by the flames before a pilar of hot air forms beneath you and throws you against the rocks.\n");
say((string)this_player()->query_cap_name()+" Slams against the rocks near you, horribly burned.\n");
this_player()->do_damage((random(250)));
return 1;
}
int motion(string str) {
write("You motion to Riptide and he shakes his head.\n");
write("%^RED%^The vessel will go no further.\n");
say((string)this_player()->query_cap_name()+" appearantly wants to crash into the dock...  What a loser
.\n");
this_player()->move_player("/d/attaya/boat5a",);
return 1;
}

int disembark(string str) {
  write("You step from the vessel onto the dock..\n");
  say((string)this_player()->query_cap_name()+" steps from the vessel onto the dock.\n");
this_player()->move_player("/d/attaya/firedock",);
  return 1;
}
