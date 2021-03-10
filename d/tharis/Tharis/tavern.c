//tavern.c

#include <std.h>
#include "../tharis.h"

inherit CVAULT;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",2);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
The Fattened dwarf
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^%^RED%^The Fattened Dwarf%^RESET%^
This quaint place has a dark and musty atmosphere. The
small round tables look well beaten but clean. The chatter
of folk around lets you know that life should be simple.
You notice a lack of the traditional shouting and yelling. There
is a menu here.
JAVAMAKER
   );

   set_smell("default","The mixed smell of dark ale and bread and meat.");
   set_listen("default","A low hum of covered murmurs fills the room. A harsh snap from the kitchen breaks the mood every now and then.");
   set_items(([
      "tables":"The tables here are scarred and chipped, but it looks as if they are well kept and clean.",
      "menu":"You should read the menu, if offers a lot.",
   ]));

   set_exits(([
      "out":ROOMS"side2",
   ]));


   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));

   set_door("door",ROOMS"side2","out",0);
   set_open("door",1);
   set_locked("door",0);
}


void reset(){
   ::reset();
   if(!present("gralesh")){
      find_object_or_load(MON"gralesh")->move(TO);
   }

}

void init(){
   ::init();
   add_action("read","read");

}

int read(string str){
    object ob;
    int i;
    if(str != "menu")  return 0;
    ob = present("gralesh");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
    write("The following great foods are served here at the Fattened Dwarf Tavern.");

    write("--------------------------------------------------------------------");
    write("Stuffed Pheasant\t\t\t\t"+ (int)ob->get_price("stuffed pheasant") + " copper");
    write("Tharisian Dark Lager\t\t\t\t"+(int)ob->get_price("tharisian dark lager")+" copper");
    write("Mug of Water\t\t\t\t\t"+(int)ob->get_price("water")+" copper");
    write("Bread\t\t\t\t\t\t"+ (int)ob->get_price("bread")+" copper");
    write("Dwarven stew\t\t\t\t\t"+ (int)ob->get_price("dwarven stew")+" copper");
    write("Antiochish Wine\t\t\t\t\t"+ (int)ob->get_price("antiochish wine")+" copper");
    write("Fattened Dwarf\t\t\t\t\t"+ (int)ob->get_price("fattened dwarf")+" copper");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}






