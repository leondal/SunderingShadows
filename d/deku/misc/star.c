inherit "/std/Object";

int toss;

create() {
  ::create();
  set_name("star");
  set_id(({"ninja star","star"}));
set("short","Ninja's throwing star");
  set("long","It is a throwing star, you can simply toss it to anyone.");
  set_weight(1);
  set_value(200);
}

void init() {
  ::init();
  add_action("toss","toss");
  add_action("toss","throw");
}

int toss(string str) {
  object whob;
  string who;
  if(!str) {
    write("Useage: toss <who>\n");
    return 1;
  }
   whob = find_living(str);
  tell_object(this_player(), "You throw the ninja star to "+str+"\n");
  say(this_player()->query_cap_name()+" throws a ninja star to "+str+"\n");
  tell_object(whob, this_player()->query_cap_name()+" hits you with a ninja star!\n");
move_object(this_object(),whob);
  return 1;
}
