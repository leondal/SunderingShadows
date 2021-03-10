//	/realms/pator/castle/castlec1.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

inherit VAULT;

string connecting = CASTLE+"castleC2";
int found = 0;

int sh_cheese(string str) {
   if(str == "cheese") {
      if(found) return 0;
      if(!(present("Marleen-cheese"))) {
         new(CASTLE+OBJECTS+"C_cheese")->move(this_object());
         write("You find a Marleen castle cheese !!");
         found = 1;
         return 1;
      } else {
         return 0;
      }
   }
}

void init() {
   ::init();
   add_action("sh_cheese","search");
}

void reset() {
   ::reset();
   found = 0;
   set_open("door",0);
   set_locked("door",1);
   connecting->set_open("door",0); 
// connecting room door isn't locked from that side
}

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(1);
   set_indoors(1);
   set_short("Inside the castle cellar");
   set_long(
@PATOR
You are inside the castle-kitchen cellar.  All you see are shelves 
filled with food and other nice things.  When you look around you 
wonder who is going to eat all of this?
PATOR
   );
   set_smell("default","You smell the foods lying around here.");
   set_exits((["up" : CASTLE+"castleE8.c",
               "enter" : CASTLE+"castleC2.c" ]));
   set_invis_exits(({"enter"}));
   set_items(([
              "wall" : "The walls are made from stone and are very thick.",
              "walls" : "The walls are made from stone and are very thick.",
              "shelves" : "They are really stacked with all sorts of food : Meat, cheese and more.",
              "food" : "It looks delicious",
              "meat" : "Very fresh, very red",
              "cheese" : "All sorts of cheese.\nMaybe you wanna search look for a special one ??",
              "door" : "Is is a sturdy wooden door."

              ] ));
   set_door("door",connecting,"enter","blackened key");
   set_string("open","door","The door opens with a horrible sound !!\n");
}

