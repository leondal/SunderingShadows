inherit "/std/room";

void create() {
     ::create();
     set_light(-8);
     set_indoors(1);
     set_short("Inside the ancient tomb.");
     set_long("
It is the inside of the ancient tomb
");
set_listen("default", "The wall near you cracks, and you can hear a heartbeat behind it.\n");
set_smell("default", "The air is musty and carries the odor of mildew and decay.\n");
}
void reset() {
 ::reset();
    if(!present("grimwall"))
      new("d/attaya/mon/grimwall")->move(this_object());
}

void init() {
     ::init();
add_action("pull", "pull");
add_action("exit", "exit");
}
int exit(string str) {
write("%^BOLD%^You cannot leave, the wall has transformed into a monster.\n");
write("%^BOLD%^%^MAGENTA%^In the darkness, you slam into a stone spike!\n");
say((string)this_player()->query_cap_name()+" Slams into a stone spike in the darkness.\n");
this_player()->do_damage((random(20)));
return 1;
}
int pull(string str) {
write("You pull the lever in the darkness.\n");
write("%^GREEN%^You are magically teleported somewhere.\n");
say((string)this_player()->query_cap_name()+" pulls a lever in the darkness
.\n");
this_player()->move_player("/d/attaya/jun64",);
return 1;
}

