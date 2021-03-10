#include <std.h>

inherit VAULT;

int lifted;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(1);
   set_indoors(1);
   set_short("A Kitchen Pantry");
   set_long( (: TO, "ldesc" :) );
   set_smell("default", "It smells rather dusty in here.");
   set_listen("default", "You can hear the faint squeak of a mouse somewhere.");
   set_items(([
      "room" : "Along one wall of this tiny room are shelves, "
         "and a rug has been spread across the floor.",
      "shelves" : "There are many containers on these shelves. Some look to "
         "contain spices, while others hold strange things, and "
         "there are still others that you can not see into."
   ]));
   set_exits(([
      "kitchen" : "/d/koenig/town/house3",
      "trapdoor" : "/d/koenig/town/tunnel1"
   ]));
   set_invis_exits( ({"trapdoor"}) );
   set_door("door", "/d/koenig/town/house3", "kitchen", "open_door");
   set_open("door", 0);
   set_string("door","open","You open the door, and it leads you back to the "
      "kitchen.");
   set_door("trapdoor", "/d/koenig/town/tunnel1", "trapdoor", "open_trapdoor");
   set_open("trapdoor", 0);
   set_string("trapdoor","open","As you open the trapdoor, you get a blast of "
      "stale air in your face.");

}

void init(){
  ::init();
    add_action("lift_rug","lift");
    add_action("lift_rug","move");
}

int lift_rug(string str){
   if(str != "rug" && str != "area rug") return notify_fail("You can't lift that, but maybe you wanted to lift the rug?");
   if(lifted) tell_object(TP,"The area rug has already been moved!");
   tell_room(ETP,""+TPQCN+" lifts the area rug.",TP);
   tell_object(TP,"You find a secret trapdoor.");
   remove_invis_exit("trapdoor");
   lifted = 1;
   return 1;
}

void reset() {
   ::reset();
   if(!present("rug"))
   new("/d/koenig/town/items/rug.c")->move(TO);
   if(lifted){
      lifted = 0;
      set_invis_exits(({"trapdoor"}));
   }
}

void ldesc(string str){
   if(lifted){
      return("%^CYAN%^Well, well, adventurer, some things are just not what they "
          "appear to be, are they?  Upon entering what you thought to be a "
          "pantry, you find a very tiny room with a set of stairs leading "
          "down through a %^GREEN%^trapdoor%^CYAN%^ in the floor into %^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^.  Now I wonder where "
          "they could lead you...\n%^RESET%^");
   }
   return("%^CYAN%^This tiny pantry is lined with %^ORANGE%^shelves%^CYAN%^ covered in jars and other "
      "containers. %^RESET%^Cobwebs%^CYAN%^ in the corner and %^RESET%^dust motes%^CYAN%^ dancing in the air make you "
      "think the supplies are not used very often. Curiously, a %^RED%^rug%^CYAN%^ on the floor seems "
      "cleaner than the rest of the space.%^RESET%^\n");
}     