#include <std.h>
#include "../inherit/ruins.h"
inherit ROOM;

int sigilflag, searched;

void create() {
    ::create();
    sigilflag = 1;
    searched = 0;
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","Scents of phosphorus and carbon and various other components waft through the air.");
    set_listen("default","Perfect silence surrounds you.");
    set_name("Hidden laboratory of an abandoned building");
    set_short("%^ORANGE%^Hidden laboratory of an abandoned building%^RESET%^");
    set_long("%^ORANGE%^Despite its size, this room is rather cluttered, though it is entirely free of "
"dust and dirt.  A few %^WHITE%^softly-glowing%^ORANGE%^ orbs are placed around the walls, adding light "
"to the area.  Shelves surround most of the room, some holding thick, old tomes and a few scrolls, and "
"others decked with labelled bottles and jars of various spell components.  Taking up much of the back "
"wall is a large worktable, covered in an assortment of beakers, scales, globes, glass tubes and the "
"like, as well as a %^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^.  To your left is an "
"impressive %^CYAN%^%^BOLD%^mirror%^RESET%^%^ORANGE%^ with a stout frame.  Behind you upon the wall is "
"the outline of a %^WHITE%^glowing%^ORANGE%^ portal, through which you can see an ornate bedroom.  Upon "
"the smooth floor are the outlines of several %^BLUE%^%^BOLD%^mystical circles%^RESET%^%^ORANGE%^, and a "
"matching design mirrors this upon the roof above.  A faint presence lingers in the air here, making you "
"feel somewhat uneasy.%^RESET%^\n");
    set_items(([
      "floor" : "%^ORANGE%^The floor is perfectly smooth and level beneath your feet, and patterned with "
"the outlines of several %^BLUE%^%^BOLD%^mystical circles%^RESET%^%^ORANGE%^, mirroring the design on "
"the roof above.%^RESET%^",
      ({"walls","wall"}) : "%^ORANGE%^You can barely see the walls here, for all the shelves and clutter "
"around the room.%^RESET%^",
      "roof" : "%^ORANGE%^Outlines of several overlapping %^BLUE%^%^BOLD%^mystical "
"circles%^RESET%^%^ORANGE%^ cover the roof above, perfectly matching those on the floor below.%^RESET%^",
      ({"sigil","yellow sigil"}) : "%^ORANGE%^Upon the worktable, amongst the beakers and tubes and "
"other paraphernalia, is a %^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^, strangely alone and clear "
"of the clutter around it.  You could probably %^CYAN%^take%^ORANGE%^ it if you wanted to.%^RESET%^",
      ({"shelf","shelves"}) : "%^ORANGE%^Shelves line the walls around the room, on nearly every side of "
"you.  Upon some of them are an assortment of thick, old books and a few scrolls, while on others there "
"are bottles and jars of a myriad of components, some of which look more familiar to you than "
"others.%^RESET%^",
      "circles" : "%^ORANGE%^The outlines of many overlapping %^BLUE%^%^BOLD%^circles%^RESET%^%^ORANGE%^ "
"have been traced upon the floor and the roof, both designs matching as perfect mirror-images of each "
"other.%^RESET%^",
      "portal" : "%^ORANGE%^There is a %^WHITE%^glowing%^ORANGE%^ portal upon the wall behind you.  "
"Through it, you can see what looks like an ornately-decorated bedroom.%^RESET%^",
      ({"table","worktable"}) : "%^ORANGE%^A large table takes up most of the back wall, and is covered "
"in a clutter of tubes, beakers, scales, and other magical implements.  Right in the centre, sits a "
"%^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^, strangely clear of all the clutter nearby.%^RESET%^"
    ]));
    set_exits(([
      "portal" : ROOMS+"t2"
    ]));
    new("/d/magic/obj/mirror")->move(TO);
    set_search("default","Where do you want to search?");
    set_search("shelves",(:TO,"search_fun":));
    set_search("shelf",(:TO,"search_fun":));
    set_pre_exit_functions(({"portal"}),({"portal_fun"}));
    set_trap_functions(({"sigil"}),({"trap_fun"}),({"take"}));
}

void init() {
   ::init();
   add_action("take_fun","take");
}

void reset() {
   ::reset();
   searched = 0;
   if(!trapped("sigil")) {
     toggle_trap("sigil","take");
   }
   if (sigilflag == 0) {
     sigilflag = 1;
     set_long("%^ORANGE%^Despite its size, this room is rather cluttered, though it is entirely free of "
"dust and dirt.  A few %^WHITE%^softly-glowing%^ORANGE%^ orbs are placed around the walls, adding light "
"to the area.  Shelves surround most of the room, some holding thick, old tomes and a few scrolls, and "
"others decked with labelled bottles and jars of various spell components.  Taking up much of the back "
"wall is a large worktable, covered in an assortment of beakers, scales, globes, glass tubes and the "
"like, as well as a %^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^.  To your left is an "
"impressive %^CYAN%^%^BOLD%^mirror%^RESET%^%^ORANGE%^ with a stout frame.  Behind you upon the wall is "
"the outline of a %^WHITE%^glowing%^ORANGE%^ portal, through which you can see an ornate bedroom.  Upon "
"the smooth floor are the outlines of several %^BLUE%^%^BOLD%^mystical circles%^RESET%^%^ORANGE%^, and a "
"matching design mirrors this upon the roof above.  A faint presence lingers in the air here, making you "
"feel somewhat uneasy.%^RESET%^\n");
     remove_item("table");
     remove_item("worktable");
     add_item("sigil","%^ORANGE%^Upon the worktable, amongst the beakers and tubes and other "
"paraphernalia, is a %^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^.%^RESET%^");
     add_item("yellow sigil","%^ORANGE%^Upon the worktable, amongst the beakers and tubes and other "
"paraphernalia, is a %^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^.%^RESET%^");
     add_item("table","%^ORANGE%^A large table takes up most of the back wall, and is covered in a "
"clutter of tubes, beakers, scales, and other magical implements.  Right in the centre, sits a "
"%^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^, strangely clear of all the clutter nearby.%^RESET%^");
     add_item("worktable","%^ORANGE%^A large table takes up most of the back wall, and is covered in a "
"clutter of tubes, beakers, scales, and other magical implements.  Right in the centre, sits a "
"%^BOLD%^glowing yellow sigil%^RESET%^%^ORANGE%^, strangely clear of all the clutter nearby.%^RESET%^");
   }
}

int take_fun(string str) {
   if (!str) {
     notify_fail("Take what?\n");
     return 0;
   }
   if (str != "sigil" && str != "yellow sigil") {
     notify_fail("You can't take that.\n");
     return 0;
   }
     //if (query_trap_status("sigil","take")) { return 0;}
   if (sigilflag == 0) {
     notify_fail("That is not here.\n");
     return 0;
   }
   if (sigilflag == 1) {
     sigilflag = 0;
     set_long("%^ORANGE%^Despite its size, this room is rather cluttered, though it is entirely free of "
"dust and dirt.  A few %^WHITE%^softly-glowing%^ORANGE%^ orbs are placed around the walls, adding light "
"to the area.  Shelves surround most of the room, some holding thick, old tomes and a few scrolls, and "
"others decked with labelled bottles and jars of various spell components.  Taking up much of the back "
"wall is a large worktable, covered in an assortment of beakers, scales, globes, glass tubes and the "
"like.  To your left is an impressive %^CYAN%^%^BOLD%^mirror%^RESET%^%^ORANGE%^ with a stout frame.  "
"Behind you upon the wall is the outline of a %^WHITE%^glowing%^ORANGE%^ portal, through which you can "
"see an ornate bedroom.  Upon the smooth floor are the outlines of several %^BLUE%^%^BOLD%^mystical "
"circles%^RESET%^%^ORANGE%^, and a matching design mirrors this upon the roof above.  A faint presence "
"lingers in the air here, making you feel somewhat uneasy.%^RESET%^\n");
     remove_item("sigil");
     remove_item("yellow sigil");
     remove_item("table");
     remove_item("worktable");
     add_item("table","%^ORANGE%^A large table takes up most of the back wall, and is covered in a "
"clutter of tubes, beakers, scales, and other magical implements.%^RESET%^");
     add_item("worktable","%^ORANGE%^A large table takes up most of the back wall, and is covered in a "
"clutter of tubes, beakers, scales, and other magical implements.%^RESET%^");
     tell_object(TP,"You pick up the %^YELLOW%^glowing sigil%^RESET%^ from the bench.\n");
     tell_room(ETP,""+TP->QCN+" picks up the %^YELLOW%^glowing sigil%^RESET%^ from the bench.\n",TP);
     new(OBJ+"sigilyellow")->move(TP);
     return 1;
   }
}

int search_fun(string str) {
   object ob;
   if (searched == 1) {
     write("They look like they have already been searched.\n");
     return 1;
   }
   switch(random(5)) {
     case 0:
     ob = new("/d/magic/scroll");
     ob->set_av_spell(7);
     ob->move(ETP);
     tell_object(TP,"You find an interesting sheet of parchment between two tomes.\n");
     tell_room(ETP,""+TP->QCN+" searches through the shelves and seems to find something.\n",TP);
     break;
     case 1..3:
     call_out("add_comp",0,TP);
     tell_object(TP,"You find a component that looks useable.\n");
     tell_room(ETP,""+TP->QCN+" searches through the shelves and seems to find something.\n",TP);
     break;
     case 4:
     tell_object(TP,"You don't find anything that looks particularly useful.\n");
     tell_room(ETP,""+TP->QCN+" searches through the shelves but doesn't find anything useful.\n",TP);
   }
   searched = 1;
   return 1;
}

int portal_fun() {
  tell_object(TP,"The portal shimmers as you step through it.\n");
  if (!TP->query_invis()) {
    tell_room(ETP,""+TP->QCN+" steps through the shimmering portal and disappears.\n",TP);
  }
  return 1;
}

int add_comp(object player) {
   string str;
   object ob;
   int num;
   switch(random(18)) {
      case 0:
         str = "eyelash";
         num = random(10)+5;
         break;
      case 1..2:
         str = "small diamond";
         num = random(6)+3;
         break;
      case 3..4:
         str = "gum arabic";
         num = random(6)+2;
         break;
      case 5:
         str = "owlfeather";
         num = random(5)+3;
         break;
      case 6..7:
         str = "spider web";
         num = random(10)+5;
         break;
      case 8:
         str = "talc";
         num = random(4)+4;
         break;
      case 9..10:
         str = "diamond";
         num = random(4)+1;
         break;
      case 11:
         str = "phosphorus";
         num = random(6)+3;
         break;
      case 12:
         str = "tiny bag";
         num = random(10)+4;
         break;
      case 13:
         str = "small candle";
         num = random(10)+3;
         break;
      case 14..17:
         str = "blessed leather";
         num = random(8)+2;
         break;
    }
   ob = new("/d/magic/store_comp.c");
   ob->set_name(str);
   ob->set_id(({"str","component","spell component"}));
   ob->set_short(capitalize(str)+" (a spell component)");
   ob->set_long("     "+num+" "+str+""+ ""+ob->query_long());
   ob->set_comp_quantity(num);
   ob->move(environment(player));
   return 1;
}

int trap_fun(string str) {
   int i;
   object *pplz;
   pplz = all_living(TO);
   tell_object(TP,"As you reach for the sigil, a %^CYAN%^%^BOLD%^bright%^RESET%^ barrier flashes into
existance over it!\n");
   tell_room(ETP,""+TPQCN+" reaches for the sigil, but a %^CYAN%^%^BOLD%^bright%^RESET%^ barrier flashes
into existance over it!\n",TP);
   tell_object(TP,"The barrier %^WHITE%^%^BOLD%^flares%^RESET%^ with blinding light, and the resulting explosion throws you back across the room!\n");
   TP->do_damage("torso",roll_dice(5,20));

   for(i=0;i<sizeof(pplz);i++) {
     if(pplz[i] != TO && pplz[i] != TP && !pplz[i]->query_true_invis() && objectp(pplz[i])) {
       if(!"daemon/saving_d"->saving_throw(pplz[i],"spell")) {
         tell_object(pplz[i],"The barrier %^WHITE%^%^BOLD%^flares%^RESET%^ with blinding light, and the resulting explosion rocks you from your feet!\n");
         pplz[i]->do_damage("torso",roll_dice(3,20));
       }
       else {
         tell_object(pplz[i],"The barrier %^WHITE%^%^BOLD%^flares%^RESET%^ with blinding light, though you manage to avoid the worst of the resulting explosion.\n");
         pplz[i]->do_damage("torso",roll_dice(1,20));
       }
     }
   }
   tell_room(ETP,"The barrier flickers once and dies.\n");
   toggle_trap("sigil","take");
   return 1;
}
