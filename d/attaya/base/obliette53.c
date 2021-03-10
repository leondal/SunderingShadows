inherit "/std/room";

#include <std.h>
void create() {
     ::create();
     set_light(2);
     set_indoors(1);
     set_short("The chamber of evil awareness");
      set_long("
    You have come to a hidden altar.  This is a circular chamber with stained glass walls!  Bright lights glow behind the walls and beneath the floor where they shine through a glass symbol of the Kinnesaruda.
    A kneeling block lies at the center of the room and a sacrificial table sits at either side.  The ceiling in here is vaivering as if a pocket of intense heat were between you and it.
    You can feel the angry glare of a powerful evil presence upon you.
%^BOLD%^%^BLUE%^A Mysterious Portal is here.
");
     set_items(([
      "ceiling" : "The ceiling seems to be unstable, some unseen force lies between you and it, or perhaps reality is warped.",
      "altar" : "This is an altar dedicated to resurrecting the dead.  It is a holy place for the most malevolant forces imaginable.",
      "tables" : "The sacrificing tables are stained with blood",
      "sacrificial tables" : "The tables are stained with blood",
      "walls" : "They are comprised of colored glass panels.  Bright light pours into the room from behind them."
]));
     set_listen("default", "A beautiful dark melody fills your head.  You have heard it somewhere before, and could listen to it forever.\n");
}
void reset() {
  ::reset();
    if(!present("ashtar"))
      new("d/attaya/mon/ashtar")->move(this_object());
}
void init() {
  ::init();
  add_action("storm", "storm");
  add_action("enter", "enter");
}
int storm(string str) {
  this_player()->add_hp(-(random(5)));
        call_out("backup",1,TP);
  return 1;
}
void backup(object targ){
        object ob;
        if(objectp(targ)){
                if(present(targ->query_name())){
                        tell_room(TO,"A skeletal entity emerges from the shadows nearby!");
                       ob=new("/d/attaya/mon/entity");
                        ob->move(TO);
               }
          }
}

int enter(string str) {
  write("%^CYAN%^You enter the mysterious portal.\n");
  say((string)this_player()->query_cap_name()+" enters the mysterious portal.\n");
  this_player()->move_player("/d/attaya/cliff59");
  return 1;
}

