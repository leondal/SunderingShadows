inherit "/d/attaya/spec/cliff";

void create() {
     ::create();
     set_light(2);
     set_indoors(0);
     set_short("Ancient Tomb");
     set_long("
    This is the center of the shadowy rotunda.  It is a large chamber dedicated to the worship and calling of ancient evil spirits.  A towering stone altar graces the center of the room.  Glowing symbols upon the altar give you a feeling for the power you are dealing with here!
    To the north and the south are stone circles where undead hordes watch the rituals.  The roof is made of sandstone and bears the symbol of the Kinnesaruda directly above the altar!
");
    set_exits(([
"east":"/d/attaya/cliff59",
"north":"/d/attaya/guard1",
"south":"/d/attaya/guard2",
]));
set_listen("default", "The nomad mumbles to the ancient evils around you, and to the north and south, the undead shriek\n");
    set_items(([
     "altar" : "The massive altar has been brought in from a distant land.  It is comprised of obsidian and dark glass.  You think you can make out movement inside it!",
     "ceiling" : "The ceiling is made of large blocks of sandstone with carvings in them.",
     "symbol" : "The symbol of the Kinnesaruda glows from the altar, and graces the ceiling.",
     "circles" : "The circles of stones are north and south of the main rotunda.  You can climb a few steps to get to them."
]));
}
void reset() {
  ::reset();
    if(!present("nomad"))
      new("d/attaya/mon/nomad")->move(this_object());
}
void init() {
     ::init();
add_action("search", "search");
add_action("enter", "enter");
}
int search(string str) {
write("The nomad notices your attempt.\n");
write("%^BOLD%^%^BLUE%^The nomad casts a blue light upon you%^RESET%^!\n"
    "You are magically teleported somewhere.\n"
);
say((string)this_player()->query_cap_name()+" is bathed in a blue aura as the nomad raises her hands!\n");
this_player()->move_player("/d/attaya/cliff61.c");
return 1;
}
int enter(string str) {
write("You pull and pull on the front of the altar, pissing off the gods.\n");
write("%^BLUE%^A shadowy hand grasps you by the neck and pulls you from the room through a portal.\n");
say((string)this_player()->query_cap_name()+" Pulls on the front of the massive altar in vain
.\n");
this_player()->move_player("/d/attaya/dock",);
write("%^BOLD%^%^RED%^Intruder tells you: %^RESET%^Leave here, or DIE!\n");
say((string)this_player()->query_cap_name()+" is grabbed by a shadowy hand and wisked out of the room!\n");
return 1;
}

