#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

int items;

void create() {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This room is very bare except for three steel %^RESET%^tables%^BOLD%^%^BLACK%^,"+
      " two sets of wall %^RESET%^shackles%^BOLD%^%^BLACK%^, and a pile of %^RESET%^bars%^BOLD%^%^BLACK%^ stacked up in one corner."+
      " There is one table each lined up on the north and south walls. Each of"+
      " those tables are bare, but the third table on the west wall is covered"+
      " in an assortment of torture devices. From the contents on the third table,"+
      " you assume the bars in the corners were used for beatings."
   );
   set_items( ([
      ({"torture devices","devices"}) : "The devices range from knives to a complex tool used to rip people open and hold them open.",
      "tables" : "The tables are cold and bare.",
      "shackles" : "The shackles are old and rusty and one of them is still holding a skeleton.",
      "skeleton" : "The skeleton is shackled to the wall, but there is a key tied around its boney neck. Maybe you can pull it off?",
   ]) );
   set_exits( ([
      "door" : TOWER+"bottom09",
   ]) );
   set_door("door",TOWER+"bottom09","door","cellar key");
   items = 1;
}

void init() {
   ::init();
   add_action("pull_key","pull");
}

int pull_key(string str) {
object ob;
   if(!str) {
      write("What do you want to pull?");
      return 1;
   }
   if(!items) {
      write("You find nothing.");
      return 1;
   }
   if(str == "key") {
      write("You pull the key from the skeleton.");
      tell_room(TO,""+TPQCN+" pulls the key from the skeleton.",TP);
      ob = new(OBJ+"c_key")->move(TO);
      items = 0;
      return 1;
   }
}
