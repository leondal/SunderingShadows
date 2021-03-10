#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l1c";

int red,yellow;

void create() {
    ::create();
    set_long("%^ORANGE%^This corridor extends east and west, lined by stone walls on either side.  The "
"roof spans high above your head, supported by curved arches from both walls, decorated ornately but "
"covered in a thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  The floor beneath your feet is "
"perfectly flat, without rubble or upturned stones to impede your progress, though it is coated in still "
"more %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  No windows mark this length of corridor, making it a "
"little darker here.  The corridor itself continues into darkness in both directions.  Upon the southern "
"wall directly in front of you, is the outline of two large doorways set beside each other, each marked "
"with a %^YELLOW%^g%^RED%^lo%^YELLOW%^w%^RED%^in%^YELLOW%^g%^RESET%^%^ORANGE%^ sigil.  It seems very "
"%^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your shoulders, making you feel a "
"little uneasy.%^RESET%^\n");
    add_item(({"doors","doorways"}),"%^ORANGE%^Upon the southern wall are two "
"ornately-outlined doorways of grand size.  Strangely enough though, there seems no way to open them, "
"and no lock or handle upon either.  The only outstanding feature of the outlined doors is the sigil "
"carved into each; the one upon the first door is edged by a strange %^YELLOW%^yellow%^RESET%^%^ORANGE%^ "
"glow, and upon the second door it is edged in glowing %^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^.%^RESET%^");
     add_item("yellow sigil","%^ORANGE%^The first carved sigil glows a faint "
"%^YELLOW%^yellow%^RESET%^%^ORANGE%^ shade.%^RESET%^");
     add_item("red sigil","%^ORANGE%^The second carved sigil glows a faint "
"%^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^ shade.%^RESET%^");
    add_item("sigils","%^ORANGE%^Two sigils, ornate symbols of an unknown meaning, are carved deeply "
"into the outlined door before you.  One is edged by a strange %^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^ "
"glow, and the other is edged with %^YELLOW%^yellow%^ORANGE%^.%^RESET%^");
    set_exits(([
      "east" : ROOMS+"8-4",
      "west" : ROOMS+"8-2",
    ]));
    set_pre_exit_functions(({"up"}),({"goup_fun"}));
    set_pre_exit_functions(({"down"}),({"godown_fun"}));
}

void init() {
   ::init();
   add_action("fitsigil_fun","fit");
}

void reset() {
   ::reset();
   if(red == 1 && yellow == 1) { remove_item("sigils"); }
   if(red == 1 || yellow == 1) {
     remove_item("door");
     remove_item("doorway");
     add_item(({"doors","doorways"}),"%^ORANGE%^Upon the southern wall are two "
"ornately-outlined doorways of grand size.  Strangely enough though, there seems no way to open them, "
"and no lock or handle upon either.  The only outstanding feature of the outlined doors is the sigil "
"carved into each; the one upon the first door is edged by a strange %^YELLOW%^yellow%^RESET%^%^ORANGE%^ "
"glow, and upon the second door it is edged in glowing "
"%^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^.%^RESET%^");
     add_item("sigils","%^ORANGE%^Two sigils, ornate symbols of an unknown meaning, are carved deeply "
"into the outlined door before you.  One is edged by a strange %^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^ "
"glow, and the other is edged with %^YELLOW%^yellow%^ORANGE%^.%^RESET%^");
   }
   if(member_array("down",TO->query_exits()) != -1) {
     remove_exit("down");
     add_item("yellow sigil","%^ORANGE%^The first carved sigil glows a faint "
"%^YELLOW%^yellow%^RESET%^%^ORANGE%^ shade.%^RESET%^");
     yellow = 0;
   }
   if(member_array("up",TO->query_exits()) != -1) {
     remove_exit("up");
     add_item("red sigil","%^ORANGE%^The second carved sigil glows a faint "
"%^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^ shade.%^RESET%^");
     red = 0;
   }
   if(!present("spirit")) { new(MON+"advspirit")->move(TO); }
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
   if (str == "green sigil" || str == "blue sigil") {
     write("There is no place here to fit a "+str+".\n");
     return 1;
   }
   if (str == "red sigil") {
     inven=all_inventory(TP);
     for (i=0;i<sizeof(inven);i++) {
       if(inven[i]->id("red sigil")) {
         flag = i;
       }
     }
     if (flag >= 0) {
       if (member_array("up",TO->query_exits()) != -1) {
         write("You can't seem to fit the red sigil anywhere.\n");
         return 1;
       }
       else {
         write("The sigil fits perfectly within the glowing red engraving, merging to become part of the "
"stone door itself.\n");
         say(""+TPQCN+" sets the sigil into the glowing red engraving within the door's outline, where "
"it merges to become part of the stone door itself.\n",TP);
         inven[flag]->remove();
         tell_room(ETP,"The outlined doorway flickers and becomes transparent, revealing a set of stairs "
"spiralling upwards.\n");
         add_exit(ROOMS+"u1-3","up");
         remove_item("red sigil");
         remove_item("doors");
         remove_item("doorways");
         remove_item("sigils");
         red = 1;
         if (yellow == 0) {
         add_item(({"doors","doorways"}),"%^ORANGE%^Upon the southern are two ornately-outlined doorways "
"of grand size.  Strangely enough though, there seems no way to open them, and no lock or handle upon "
"them.  The only outstanding feature of the outlined doors are the sigils carved into them, edged by a "
"strange %^YELLOW%^yellow%^RESET%^%^ORANGE%^ glow.%^RESET%^");
    add_item("sigils","%^ORANGE%^Only one sigil is carved deeply into the doorways before you, edged "
"with glowing %^YELLOW%^yellow%^RESET%^%^ORANGE%^ light.%^RESET%^");
         }
         else {
         add_item(({"doors","doorways"}),"%^ORANGE%^Upon the southern are two ornately-outlined doorways "
"of grand size.  Strangely enough though, there seems no way to open them, and no lock or handle upon "
"them.%^RESET%^");
         }
         return 1;
       }
     }
     else {
       write("You don't have a red sigil!\n");
       return 1;
     }
   }
   if (str == "yellow sigil") {
     inven=all_inventory(TP);
     for (i=0;i<sizeof(inven);i++) {
       if(inven[i]->id("yellow sigil")) {
         flag = i;
       }
     }
     if (flag >= 0) {
       if (member_array("down",TO->query_exits()) != -1) {
         write("You can't seem to fit the yellow sigil anywhere.\n");
         return 1;
       }
       else {
         write("The sigil fits perfectly within the glowing yellow engraving, merging to become part of "
"the stone door itself.\n");
         say(""+TPQCN+" sets the sigil into the glowing yellow engraving within the door's outline, "
"where it merges to become part of the stone door itself.\n",TP);
         inven[flag]->remove();
         tell_room(ETP,"The outlined doorway flickers and becomes transparent, revealing a set of stairs "
"spiralling downwards into pitch darkness.\n");
         add_exit(ROOMS+"b1-3","down");
         remove_item("yellow sigil");
         remove_item("doors");
         remove_item("doorways");
         remove_item("sigils");
         yellow = 1;
         if (red == 0) {
         add_item(({"doors","doorways"}),"%^ORANGE%^Upon the southern are two ornately-outlined doorways "
"of grand size.  Strangely enough though, there seems no way to open them, and no lock or handle upon "
"them.  The only outstanding feature of the outlined doors are the sigils carved into them, edged by a "
"strange %^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^ glow.%^RESET%^");
    add_item("sigils","%^ORANGE%^Only one sigil is carved deeply into the doorways before you, edged "
"with glowing %^RED%^%^BOLD%^red%^RESET%^%^ORANGE%^ light.%^RESET%^");
         }
         else {
         add_item(({"doors","doorways"}),"%^ORANGE%^Upon the southern are two ornately-outlined doorways "
"of grand size.  Strangely enough though, there seems no way to open them, and no lock or handle upon "
"them.%^RESET%^");
         }
         return 1;
       }
     }
     else {
       write("You don't have a yellow sigil!\n");
       return 1;
     }
   }
   write("What colour sigil do you want to fit?\n");
   return 1;
}

int goup_fun() {
  tell_object(TP,"You carefully ascend the spiralling stairs.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" carefully ascends the spiralling stairs, disappearing from sight.\n",TP);
  }
  return 1;
}

int godown_fun() {
  tell_object(TP,"You carefully descend the spiralling stairs into the darkness below.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" carefully descends the spiralling stairs, disappearing from sight into "
"the darkness below.\n",TP);
  }
  return 1;
}
