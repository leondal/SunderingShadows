inherit "/std/room";

#include <std.h>
void create() {
     ::create();
     set_light(2);
     set_indoors(1);
     set_property("no teleport",1);
     set_short("High Council Chamber of the Kinnesaruda");
      set_long("
    You are within a long thin chamber.  The ceiling rises dramatically to a thin wedge.  A great stone altar at the far end of the room is glowing with the light of dozens of candles.  Several rows of chairs line up around the altar.  
    Grooves in the ceiling allow a strange blue light to flood the room.
");
     set_exits( ([
       "north" : "/d/attaya/tower/hall11",
]) );
     set_items( ([
   "altar" : "The long obsidian altar is one of several you have come across in your travels.  It is a sacrificial altar to the gods that govern the Kinnesaruda and their re-emergence onto the world.",
   "candles" : "Dozens of red candles shine upon the altar and from surrounding shelves.",
    "floor" : "The floor is carpeted with the same blue and gold carpet from the hallway.",
    "chairs" : "Rows and rows of chairs surround the altars.",
    "ceiling" : "A high vaulted ceiling rises to a thin wedge about 3 stories above you.  Grooves within it glow with a blueish light.",
    "grooves" : "The grooves in the ceiling allow a blue light to seep into the room from an unseen sourse.  You begin to wonder what plane of existance this place is in.",
    "walls" : "The walls are made from granite bricks and are very rough.",
    "shelves" : "A few shelves hold candles and other strange items.",
]) );
}
void reset() {
  ::reset();
    if(!present("volkerps"))
      new("d/attaya/mon/volkerps")->move(this_object());
}
void init() {
      int num, i;
  ::init();
  add_action("axis", "axis");
  add_action("allies", "allies");
}
int axis(string str) {
         tell_room(TO,"%^BOLD%^%^BLUE%^Volkerps raises his hands to the ceiling and a spinning vortex of light appears above you.");
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
        tell_room(TO,"%^BOLD%^%^BLUE%^%^Volkerps raises his hands to the ceiling and a spinning vortex of light appears above you.");
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
