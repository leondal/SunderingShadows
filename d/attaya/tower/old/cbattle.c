inherit "/std/room";

#include <std.h>
void create() {
     ::create();
     set_terrain(STONE_BUILDING);
     set_travel(FOOT_PATH);
     set_light(3);
     set_indoors(1);
     set_property("no teleport",1);
     set_short("Deadly Beauty");
      set_long("
    Great waterfalls immediately catch your eye as water pours from far above you into a channel here.  There is a small bridge that you must cross if you wish to continue to the east.
    This area has been designed to look like part of the jungle.  Trees and tropical foliage grows alongside the channel and all around you.  Brilliant lights above create rainbows in the mist from the waterfall.
    It is hard to imagine that you are still indoors.
");
     set_listen("default", "The powerful rush of water fills your ears.");
     set_exits( ([
       "west" : "/d/attaya/tower/floor20",
      "east" : "/d/attaya/tower/floor22",
]) );
     set_items( ([
    "waterfalls" : "%^CYAN%^Water rushes from caves high in the natural looking stone walls, into a deep channel.",
    "bridge" : "A well maintained wooden bridge spans the channel.",
    "ground" : "The ground where you stand is a stone path.  Off the path is rich soil.",
    "trees" : "Magnificent royal palms and banana trees rise around you.",
    "foliage" : "The tropical plants grow in abundance and beauty here.",
    "lights" : "They are too far up to see clearly, and it gets misty and foggy above you.",
]) );
set_pre_exit_functions( ({"east"}), ({"go_east"}) );
}
int go_east() {
if(present("callista")) {
write("Callista pushes you back!");
return 0;
}
else return 1;
}
void reset() {
  ::reset();
    if(!present("callista"))
      new("d/attaya/mon/callista")->move(this_object());
}
void init() {
      int num, i;
  ::init();
  add_action("axis", "axis");
  add_action("allies", "allies");
}
int axis(string str) {
         tell_room(TO,"%^BOLD%^%^BLUE%^Callista raises her hands to the ceiling and a spinning vortex of light appears above you.");
  this_player()->add_hp(-(random(5)));

        call_out("backup",1,TP);
  return 1;
}
void backup(object targ){
        object ob;
       int num, i;
     tell_room(TO,"%^BOLD%^%^BLACK%^several phantasmic crows appear from the vortex before it closes.");
        if(objectp(targ)){
                if(present(targ->query_name())){
               num = random(4)+1;
                for(i=0;i<num;i++)
                        new("/d/attaya/mon/crow")->move(TO);
               }
          }
}

int allies(string str) {
        tell_room(TO,"%^BOLD%^%^BLUE%^%^Callista raises her hands to the ceiling and a spinning vortex of light appears above you.");
       call_out("evil",1,TP);
 return 1;
}
void evil(object targ){
       object ob;
      int num, i;
    tell_room(TO,"%^BOLD%^%^BLACK%^Several phantasmic jackals leap from the vortex before it closes.");
       if(objectp(targ)){
               if(present(targ->query_name())){
             num = random(4)+1;
           for(i=0;i<num;i++)
                      new("/d/attaya/mon/jackal")->move(TO);
            }
       }
}
