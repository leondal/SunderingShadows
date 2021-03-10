#include <std.h>
inherit ROOM;

void create(){
  :: create();
  set_property("no teleport",1);
  set_property("light", 2);
  set_property("indoors", 0);
  set_short("A pathway");
  set_long(
@ISLAND
You hope you have come to the end of your journey.  A large temple-like 
building stands before you.  Shaped like a cone, built of gray stone 
and reaching a height of approximately 60 feet, it looms, dark, cold, 
yet wondrous.  You see someone standing before you, and you feel that 
he would try to bar your passage into the temple.
ISLAND
  );
  set_smell("default", "You smell damp earth and heavy scented flowers");
  set_listen("default", "You can hear insects and the odd scurrying small animal, and your own heavy breathing.");
  set_exits( ([
    "temple" : "/d/hm_quest/rooms/quest31",
    "southwest" : "/d/hm_quest/rooms/quest29"
  ]) );
  set_items(([
    "huts" : "Small round huts appear off to the east, built of small saplings and leaves",
    "skiffs" : "Small low boats made from large trees, carved out, rest upon the sand.",
    "nets" : "Nets woven from the brightly coloured vines abundant in the forest, await their owners.",
    "bushes" : "The bushes are fairly low, only three feet high, but support blossoms of riotous colour and deep heavy fragrance.",
    "sand"  : "Sand is sand, what can I say, this sand however, is a soft golden colour and glistens when the sun is out",
    "sea" : "Crystal blue-green ocean lapping upon sand, sounds and feels wonderful",
    "boughs" : "Great leafy boughs create a canopy of life above your head",
    "trees" : "Large trees start to surround you once again, although these have a more tropical feel with huge leaves of three to four feet long and two feet wide",
    "island" : "Yes! You are on an island",
    "rocks" : "Large rocks, the size of small elephants, and the same colour appear to try and block your way",
    "vines" : "Vines of every hue, drape from the trees, some are only half an inch wide but some are as thick as hawsers and as tough.",
    "path" : "The path is strewn with pebbles and scrub",
    "scrub" : "Small plants struggle to stay alive in this area",
    "hills" : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",
    "wildflowers" : "Purple thistle, wild roses, and buttercups are among the few wildflowers you can identify upon the hills",
    "plants" : "Small bits of crabgrass and the occaisional struggling bush try to survive on just sand and sky.",
    "bird" : "A bird, with red wings, and a black beak circles above you screeching with joy or hatred, it's hard to tell",
    "sand" : "Miles upon miles of golden sand is to the left and right of you."
  ]) );
  add_pre_exit_function("southwest","go_back");
  add_pre_exit_function("temple","GoThroughDoor");
}

void init(){
  object ob;
  string cl;
  ::init();
  if(!interactive(TP) || wizardp(TP)) return;
  cl = TP->query_class_string();
  cl = replace_string(cl,"/","-");
  if(!present(cl))
  	new("/d/hm_quest/mon/q"+cl+".c")->move(TO);
}

int go_back(){
  if(!present("hm_quest_mon",TO)) return 1;
  tell_object(TP,"You cannot go back while you are fighting!");
  return 0;
}

int GoThroughDoor(){
  if(!present("hm_quest_mon",TO)) return 1;
  tell_object(TP,"You cannot get by the man!");
  return 0;
}
