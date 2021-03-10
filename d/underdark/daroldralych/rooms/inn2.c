#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("The Flaming Goblin");
   set_short("%^BLUE%^The Flaming Goblin%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^The Flaming Goblin%^RESET%^\n"
"%^BLUE%^You have entered a small, shadowy tavern, obviously one of the %^RED%^s%^RESET%^h%^ORANGE%^ad%^BOLD%^%^BLACK%^i"
"%^RESET%^%^RED%^er %^BLUE%^locales of the city.  All sorts of sinister-looking characters lurk at the tables in the "
"%^BOLD%^%^BLACK%^dark%^RESET%^%^MAGENTA%^en%^BOLD%^%^BLACK%^ed corners %^RESET%^%^BLUE%^of the room, speaking in "
"whispers among themselves, or simply watching the room with a suspicious gaze.  An %^ORANGE%^old w%^RESET%^o%^ORANGE%^"
"oden bar%^BOLD%^%^BLACK%^to%^RESET%^%^ORANGE%^p %^BLUE%^takes up the centre of the rear wall, scarred and stained from "
"wear so that you can't possibly fathom what color it might once have been.  Two large windows face onto the street, "
"though for what purpose you can't tell, as they are strongly barred, and too %^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^ri"
"%^BOLD%^%^BLACK%^m%^RESET%^y %^BLUE%^to actually see through.  Sitting upon the bartop is a menu of all the foods and "
"beverages available in the inn.  A creaky wooden doorway covered in thick metal bars allows access to the street to the "
"north.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The room is thick with %^BOLD%^%^BLACK%^smoke %^RESET%^%^ORANGE%^and the sharp %^BOLD%^%^BLACK%^ta%^YELLOW%^n%^BLACK%^g %^RESET%^%^ORANGE%^of cheap alcohol.");
   set_listen("default","%^GREEN%^For a crowded bar, it's unusually %^CYAN%^qu%^GREEN%^ie%^CYAN%^t %^GREEN%^here.");

   set_items(([
     ({"wall","walls","roof"}):"%^BLUE%^The walls and roof of this shop are made of %^BOLD%^%^BLACK%^black st%^RESET%^"
"%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, a common sight in this city.  However, here they carry no elaborate "
"markings, just a thick coating of dirt and grime.%^RESET%^",
     "windows":"%^BLUE%^Two large windows fill the wall toward the street, but they are too heavily barred "
"and covered in a thick layer of %^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RESET%^t %^RESET%^%^BLUE%^to "
"actually see through.%^RESET%^",
     ({"bar","bartop","menu"}):"%^BLUE%^The %^ORANGE%^old w%^RESET%^o%^ORANGE%^oden bar%^BOLD%^%^BLACK%^to%^RESET%^"
"%^ORANGE%^p %^BLUE%^sections off much of the rear wall of the room, much stained and scarred from use.  A menu sits upon "
"it, which you could probably %^WHITE%^read%^BLUE%^.%^RESET%^",
   ]));
   set_exits(([
     "north":ROOMS"outer14",
   ]));
}

void init() {
    ::init();
    add_action("read", "read");
}

void reset(){
    object ob;
    ::reset();
    if(!present("ghauntar")) find_object_or_load(MON"ghauntar")->move(TO);
    if(!present("dartboard")) {
      ob = new(OBJ"dartboard");
      ob->set_mastery_list("daroldralych");
      ob->move(TO);
    }
}

int read(string str) {
   object ob;
   int i;

   if(str!="menu") return notify_fail("Read what?");
   ob=present("ghauntar");
   if (!ob){
     write("There's noone here to serve you right now.");
     return 1;
   }
   else{
write("%^RESET%^%^RED%^\n\t  =+=+=+=+=+=+=+=+=+= FOOD +=+=+=+=+=+=+=+=+=+=");
write("%^YELLOW%^\n\tCheese and crackers\t\t\t %^WHITE%^"+ (int)ob->get_price("cheese and crackers")+" silver");
write("%^YELLOW%^\tSporebread\t\t\t\t %^WHITE%^"+ (int)ob->get_price("sporebread")+" silver");
write("%^YELLOW%^\tMushroom salad\t\t\t\t %^WHITE%^"+ (int)ob->get_price("mushroom salad")+" silver");
write("%^YELLOW%^\tCured rothe meat\t\t\t%^WHITE%^"+ (int)ob->get_price("cured rothe meat") + " silver");
write("%^YELLOW%^\tSpiced sausages\t\t\t\t%^WHITE%^"+ (int)ob->get_price("spiced sausages") + " silver");

write("%^RESET%^%^RED%^\n\t  =+=+=+=+=+=+=+=+=+ DRINKS =+=+=+=+=+=+=+=+=+=");
write("%^YELLOW%^\n\tWater\t\t\t\t\t %^WHITE%^"+(int)ob->get_price("water")+" silver");
write("%^YELLOW%^\tLichen tea\t\t\t\t %^WHITE%^"+(int)ob->get_price("lichen tea")+" silver");
write("%^YELLOW%^\tMushroom ale\t\t\t\t%^WHITE%^"+(int)ob->get_price("mushroom ale")+" silver");
write("%^YELLOW%^\tBerdruskan dark\t\t\t\t%^WHITE%^"+(int)ob->get_price("berdruskan dark")+" silver");
write("%^RED%^\n\t  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
     return 1;
   }
}
