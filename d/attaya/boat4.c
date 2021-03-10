inherit "/std/room";

void create() {
     ::create();
     set_light(2);
     set_indoors(0);
     set_short("You are on the river of flame");
     set_long("
%^RED%^
    You are sailing across the River of Flame aboard a magical vessel.  The heat is nearly unbearable.  Flames jump high into the air, occasionally making glowing arches of fire as the river of molten metals displays it's power.
    The phantom, Riptide, stands motionless on the bow of the boat.  His hands locked around a sphere of pure energy in front of him, he controlls the vessel with mere thought.
");
     set_smell("default", "The incredible heat and overpowering tang of molten metals forces you to cover your nose.\n");
set_listen("default", "Currents of flame crackle and pop around you.\n");
}
void init() {
     ::init();
add_action("jump_off", "jump");
add_action("motion", "motion");
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
write("You motion to Riptide and he nods.\n");
write("%^RED%^The vessel lunges forward across the River of Flame.\n");
say((string)this_player()->query_cap_name()+" Motions to Riptide
.\n");
this_player()->move_player("/d/attaya/boat5",);
return 1;
}

