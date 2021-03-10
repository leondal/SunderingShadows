#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no teleport",1);
   set_property("light",3);
   set_short("%^BOLD%^Paladin's Hall%^RESET%^");
   set_long(
   "You are standing in the altar room of the Antioch paladin's guild hall."+
   " There are holy symbols around the wall depicting every possible paladin"+
   " god. In the center of the room is a large %^BOLD%^%^CYAN%^pool%^RESET%^"+
   " of clear water. Beyond the pool is an ornately carved wooden box for"+
   " placing tithes in, it stands upon a %^BOLD%^marble%^RESET%^ pedestal."+
   " The walls of the room are bare except for the holy symbols, but light"+
   " seems to emenate from the %^BOLD%^%^CYAN%^pool%^RESET%^."
   );
   set_smell("default","The faint scent of vanilla is in the air.");
   set_listen("default","A respectful silence cloaks the room.");
   set_items(([
   "floor" : "The floor is covered in a fine rug that is %^BOLD%^%^BLUE%^"+
   " royal blue%^RESET%^ trimmed with %^BOLD%^white%^RESET%^.",
   ({"rug","blue rug","royal blue rug"}) : "%^BOLD%^%^BLUE%^The rug is a"+
   " rich royal blue with %^WHITE%^white%^BLUE%^ edges, it stretches down"+
   " the entire hallway.%^RESET%^",
   ({"wall","walls"}) : "The walls are hung with holy symbols of all the"+
   " possible gods a paladin might have.",
   "pool" : "%^BOLD%^%^CYAN%^There is a crystal clear blue pool held in a"+
   " granite basin that is raised off the floor.",
   ({"box","wooden box","ornate box"}) : "There is an ornately carved wooden"+
   " box that has all the intricate symbols of the various paladin gods"+
   " carefully worked into a complex pattern in which they seem to blend"+
   " together perfectly.",
   ({"basin","granite basin"}) : "A large granite basin rests on a thick"+
   " base of granite that raises it approximately three and a half feet off"+
   " the floor. It is filled with clear blue water.",
   ({"pedestal","marble pedestal"}) : "%^BOLD%^A marble pedestal sits behind"+
   " the pool, supporting the wooden tithing box.",
   ]));
   set_exits(([
   "south" : "/d/antioch/cguilds/paladin/hall3",
   ]));
}

void init()
{
   ::init();
   add_action("tithe_it","tithe");
}

void tithe_it(string str)
{
   string type, vl, vit;
   int x, y, i;
   if(!TP->is_class("paladin")) {
      tell_object(TP,"Sorry, but you don't get to tithe.");
      return 1;
   }
   if(!str) {
      tell_object(TP,"Tithe what?");
      return 1;
   }
   if(sscanf(str,"%d %s", x, type) != 2) {
      tell_object(TP,"Tithe <amount> gold");
      return 1;
   }
   if(type != "gold") {
      tell_object(TP,"Only gold is accepted in the tithing box.");
      return 1;
   }
   if(x <= 29) {
      tell_object(TP,"If that is all you have to give, perhaps it's best if you keep it.");
      return 1;
   }
   if((int)TP->query_money("gold") < x) {
      tell_object(TP,"You don't even have that much gold!");
      return 1;
   }
   y = x/30;
   tell_object(TP,"%^BOLD%^You tithe "+x+" %^YELLOW%^gold%^WHITE%^"+
   " into the wooden box.");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" tithes some %^YELLOW%^gold%^WHITE%^"+
   " into the wooden box.",TP);
   TP->use_funds("gold",x);
   if(y < 2) {
      tell_object(TP,"%^BOLD%^%^CYAN%^The pool seems to glow and a bottle"+
      " appears, you quickly fill it with holy water.");
      tell_room(TP,"%^BOLD%^%^CYAN%^The pool seems to glow and a bottle"+
      " appears above it, "+TPQCN+" quickly fills the bottle with holy water.",TP);
   }
   else {
      tell_object(TP,"%^BOLD%^%^CYAN%^The pool begins to glow and several"+
      " bottles appear above the pool, you carefully fill all of them with"+
      " holy water.");
      tell_room(TP,"%^BOLD%^%^CYAN%^The pool begins to glow and several"+
      " bottles appear above the pool, "+TPQCN+" carefully fills all of them"+
      " holy with water.",TP);
   }
   for(i=1;i<y+1;i++) {
      new("/d/shadow/room/city/cguild/paladin/hlywater")->move(TP);
   }
   write_file("/realms/grazzt/paladin/logs/tithe",
   ""+TPQCN+" tithed "+x+" gold to the gods in the Antioch tithe room: "+ctime(time())+"\n");
   return 1;
}
