#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l1b";

int green,blue;

void create() {
    ::create();
    green = 0;
    blue = 0;
    set_long("%^ORANGE%^You are standing within an extensive hallway, set with strong pillars at " 
"regular intervals.  The roof reaches high above your head, supported by curved arches from these "
"pillars, decorated ornately but covered in a thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  "
"The floor beneath your feet is perfectly flat, without rubble or upturned stones to impede your "
"progress, though it is coated in still more %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Upon the "
"southern wall directly in front of you, is the outline of a single large doorway, marked with two "
"%^BOLD%^%^GREEN%^g%^BLUE%^lo%^GREEN%^w%^BLUE%^in%^GREEN%^g%^RESET%^%^ORANGE%^ sigils.  It seems very "
"%^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your shoulders, making you feel a "
"little uneasy.%^RESET%^\n");
    add_item(({"door","doorway"}),"%^ORANGE%^Upon the southern wall is an ornately-outlined doorway of "
"grand size.  Strangely enough though, there seems no way to open it, and no lock or handle upon it.  "
"The only outstanding feature of the outlined door is the two sigils carved into it, one edged by a "
"strange %^BLUE%^%^BOLD%^blue%^RESET%^%^ORANGE%^ glow, and the other edged with "
"a %^GREEN%^%^BOLD%^green%^RESET%^%^ORANGE%^ shade.%^RESET%^");
    add_item("sigils","%^ORANGE%^Two sigils, ornate symbols of an unknown meaning, are carved deeply "
"into the outlined door before you.  One is edged by a strange %^BLUE%^%^BOLD%^blue%^RESET%^%^ORANGE%^ "
"glow, and the other is edged with %^BOLD%^%^GREEN%^green%^RESET%^%^ORANGE%^.%^RESET%^");
    add_item(({"blue sigil"}),"%^ORANGE%^The first carved sigil glows a faint "
"%^BLUE%^%^BOLD%^blue%^RESET%^%^ORANGE%^ shade.%^RESET%^");
    add_item(({"green sigil"}),"%^ORANGE%^The second carved sigil glows a faint "
"%^GREEN%^%^BOLD%^green%^RESET%^%^ORANGE%^ shade.%^RESET%^");
    set_exits(([
      "north" : ROOMS+"2-3",
      "east" : ROOMS+"3-4",
      "west" : ROOMS+"3-2",
    ]));
    set_pre_exit_functions(({"south"}),({"gosouth_fun"}));
}

void init() {
   ::init();
   add_action("fitsigil_fun","fit");
}

void reset() {
   ::reset();
   if(member_array("south",TO->query_exits()) != -1) {
     remove_exit("south");
   }
   if(green == 1 || blue == 1) {
     remove_item("sigils");
     remove_item("door");
     remove_item("doorway");
     add_item(({"door","doorway"}),"%^ORANGE%^Upon the southern wall is an ornately-outlined doorway of "
"grand size.  Strangely enough though, there seems no way to open it, and no lock or handle upon it.  "
"The only outstanding feature of the outlined door is the two sigils carved into it, one edged by a "
"strange %^BOLD%^%^BLUE%^blue%^RESET%^%^ORANGE%^ glow, and the other edged with a "
"%^GREEN%^%^BOLD%^green%^RESET%^%^ORANGE%^ shade.%^RESET%^");
     add_item("sigils","%^ORANGE%^Two sigils, ornate symbols of an unknown meaning, are carved deeply "
"into the outlined door before you.  One is edged by a strange %^BLUE%^%^BOLD%^blue%^RESET%^%^ORANGE%^ "
"glow, and the other is edged with %^BOLD%^%^GREEN%^green%^RESET%^%^ORANGE%^.%^RESET%^");
   }
   if(blue == 1) {
     add_item(({"blue sigil"}),"%^ORANGE%^The first carved sigil glows a faint "
"%^BLUE%^%^BOLD%^blue%^RESET%^%^ORANGE%^ shade.%^RESET%^");
   blue = 0;
   }
   if(green == 1) {
     add_item(({"green sigil"}),"%^ORANGE%^The second carved sigil glows a faint "
"%^GREEN%^%^BOLD%^green%^RESET%^%^ORANGE%^ shade.%^RESET%^");
   green = 0;
   }
}

int fitsigil_fun(string str) {
   object *inven;
   int flag,i;
   flag = -1;
   if (!str) {
     write("Fit what?\n");
     return 1;
   }
   if (strsrch(str,"sigil") == -1) {
     write("You can't find somewhere to fit that.\n");
     return 1;
   }
   if (str == "red sigil" || str == "yellow sigil") {
     write("There is no place here to fit a "+str+".\n");
     return 1;
   }
   if (str == "blue sigil") {
     inven=all_inventory(TP);
     for (i=0;i<sizeof(inven);i++) {
       if(inven[i]->id("blue sigil")) {
         flag = i;
       }
     }
     if (flag >= 0) {
       if (!id("blue sigil")) {
         write("You can't seem to fit the blue sigil anywhere.\n");
         return 1;
       }
       else {
         write("The sigil fits perfectly within the glowing blue engraving, merging to become part of the "
"stone door itself.\n");
         say(""+TPQCN+" sets the sigil into the glowing blue engraving within the door's outline, where "
"it merges to become part of the stone door itself.\n",TP);
         inven[flag]->remove();
         remove_item("blue sigil");
         remove_item("sigils");
         remove_item("door");
         remove_item("doorway");
         blue = 1;
         if (green == 1) {
           tell_room(ETP,"The outlined doorway flickers and becomes transparent, revealing an entrance to "
"an inner sanctum.\n");
           add_exit(ROOMS+"inner1","south");
         }
         else {
         add_item(({"door","doorway"}),"%^ORANGE%^Upon the southern wall is an ornately-outlined doorway "
"of grand size.  Strangely enough though, there seems no way to open it, and no lock or handle upon it.  "
"The only outstanding feature of the outlined door is the sigil carved into it, edged by a strange "
"%^GREEN%^%^BOLD%^green%^RESET%^%^ORANGE%^ glow.%^RESET%^");
    add_item("sigils","%^ORANGE%^Only one sigil is carved deeply into the doorway before you, edged with "
"glowing %^GREEN%^%^BOLD%^green%^RESET%^%^ORANGE%^ light.%^RESET%^");
         }
         return 1;
       }
     }
     else {
       write("You don't have a blue sigil!\n");
       return 1;
     }
   }
   if (str == "green sigil") {
     inven=all_inventory(TP);
     for (i=0;i<sizeof(inven);i++) {
       if(inven[i]->id("green sigil")) {
         flag = i;
       }
     }
     if (flag >= 0) {
       if (!id("green sigil")) {
         write("You can't seem to fit the green sigil anywhere.\n");
         return 1;
       }
       else {
         write("The sigil fits perfectly within the glowing green engraving, merging to become part of "
"the stone door itself.\n");
         say(""+TPQCN+" sets the sigil into the glowing green engraving within the door's outline, where "
"it merges to become part of the stone door itself.\n",TP);
         inven[flag]->remove();
         remove_item("green sigil");
         remove_item("sigils");
         remove_item("door");
         remove_item("doorway");
         green = 1;
         if (blue == 1) {
           tell_room(ETP,"The outlined doorway flickers and becomes transparent, revealing an entrance to "
"an inner sanctum.\n");
           add_exit(ROOMS+"inner1","south");
         }
         else {
         add_item(({"door","doorway"}),"%^ORANGE%^Upon the southern wall is an ornately-outlined doorway "
"of grand size.  Strangely enough though, there seems no way to open it, and no lock or handle upon it.  "
"The only outstanding feature of the outlined door is the sigil carved into it, edged by a strange "
"%^BLUE%^%^BOLD%^blue%^RESET%^%^ORANGE%^ glow.%^RESET%^");
    add_item("sigils","%^ORANGE%^Only one sigil is carved deeply into the doorway before you, edged with "
"glowing %^BLUE%^%^BOLD%^blue%^RESET%^%^ORANGE%^ light.%^RESET%^");
         }
         return 1;
       }
     }
     else {
       write("You don't have a green sigil!\n");
       return 1;
     }
   }
   write("What colour sigil do you want to fit?\n");
   return 1;
}

int gosouth_fun() {
  tell_object(TP,"You step through the doorway, into the inner sanctum.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" steps through the doorway, into the inner sanctum beyond.\n",TP);
  }
  return 1;
}
