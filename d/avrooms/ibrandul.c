#include <std.h> 
#include "/d/avrooms/crystalmsg.h"
inherit ROOM;

void create() { 
   ::create(); 
   set_property("indoors",1); 
   set_property("light",2); 
   set_property("no teleport",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
set_name("A sphere of darkness"); 
set_short("%^BLACK%^%^BOLD%^A sphere of darkness"); 
set_long("%^RESET%^%^BOLD%^%^BLACK%^This room, if you could call it that, is a perfect sphere without a single corner to hide in. You blink a few times to accustom yourself to the light until you realize that not a single %^RESET%^%^WHITE%^mo%^RESET%^%^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^e of li%^RESET%^%^BOLD%^%^WHITE%^g%^RESET%^%^WHITE%^ht "
"%^RESET%^%^BOLD%^%^BLACK%^exists in this room. However the normal rules don't apply in this darkness and you can see perfectly well. A %^RESET%^%^ORANGE%^straw dummy %^RESET%^%^BOLD%^%^BLACK%^sits to one side of the room dressed up like a beastman that has been almost %^RESET%^%^RED%^to%^RESET%^%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^n %^RESET%^%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^part%^RESET%^%^BOLD%^%^BLACK%^. The room is dominated by a %^RESET%^%^ORANGE%^large table "
"%^RESET%^%^BOLD%^%^BLACK%^with a thousand %^RESET%^%^WHITE%^notes%^RESET%^%^BOLD%^%^BLACK%^, %^RESET%^%^BOLD%^%^WHITE%^drawings%^RESET%^%^BOLD%^%^BLACK%^, %^RESET%^%^YELLOW%^memos %^RESET%^%^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^scale models%^RESET%^%^BOLD%^%^BLACK%^. It seems to be "
"quite the mess, but the owner obviously has a 'system'. The only colorful item in the room is a %^RESET%^%^MAGENTA%^lar%^RESET%^%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^e gla%^RESET%^%^CYAN%^s%^RESET%^%^MAGENTA%^s b%^RESET%^%^WHITE%^o%^RESET%^%^MAGENTA%^ttle%^BOLD%^%^BLACK%^.%^RESET%^\n");
set_smell("default","You smell ink and charcoal.");
set_listen("default","%^BLACK%^%^BOLD%^You hear the whispers of a thousand personas.");

set_items(([ 
({"straw dummy","dummy"}) : "%^RESET%^%^ORANGE%^Obviously the brunt of a lot of 'stress release', this straw dummy has been burned, sliced, bashed, and generally abused. It looks like a beastman...%^RESET%^", 
"table" : "%^RESET%^%^ORANGE%^The table is enormous, cluttered with a thousand different things.", 
({"notes", "note" }) : "%^RESET%^There are hundreds of notes, some of them plot ideas, others just diary entries. They are organized into a system completely unrecognizable to mortals.", 
({"drawings", "drawing" }) : "%^BOLD%^%^WHITE%^Drawings of armor, weapons, and maps of areas you havent seen before litter the table. Some are signed, others defaced with a giant %^RED%^red marker%^WHITE%^.%^RESET%^", 
({"memos", "memo" }) : "%^RESET%^%^YELLOW%^Little yellow post it notes are stuck to the table, the models, notes, even the walls. They have been written by different people, and rarely have any lasting meaning. Except the ones with bunny drawings, those are always important.%^RESET%^", 
({"models", "scale models" }) : "%^RESET%^%^ORANGE%^What first looked like scale models of ships, cities and little people are in reality tiny moving people. You see little assassins, illithids, baby black dragons and little exploding seagulls all playing out a world of their own.%^RESET%^",
({"bottle", "glass bottle" }) : "%^RESET%^%^MAGENTA%^This bottle almost looks out of place, an odd colourful item in a room of mostly black and brown. However the bottle seems to have a place of honor on the table. A large cork keeps the contents of the bottle secure. You really feel like giving it a good shake, just to upset things.%^RESET%^", 
])); 
}

void reset() {
   object ob;
   ::reset();
   if (!objectp(present("ibrandul_board"))) {
      ob = new("std/bboard");
      ob->set_name("ibrandul board");
      ob->set_id( ({ "board", "ibrandul_board", "my board" }) );
      ob->set_board_id("ibrandul_board");
      ob->set("short", "Ibby's Board");
      ob->set("long", "A black noteboard stuck with notes.\n");
      ob->set_max_posts(30);
      ob->set_ooc_board(1);
      ob->set_restricted_read();
      ob->set_location(base_name(TO));
      ob->move(TO);
      ob->set_property("no steal",1);
   }
}

void init() {
   ::init();
   add_action("enter_fun","enter");
   add_action("shake_fun","shake");
}

int enter_fun(string str) {
   object destination;
   if(!avatarp(TP)) return notify_fail("Naughty player, no escaping!");
   if(!str) return notify_fail("What do you want to enter?");
   if(str != "bottle") return notify_fail("You can't enter that.");
   tell_object(TP,"%^BOLD%^%^BLACK%^You enter the bottle!%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLACK%^"+TP->QCN+" enters the bottle!%^RESET%^",TP);
   destination = find_object_or_load("/d/avrooms/lurue");
   TP->move(destination);
   TP->force_me("look");
   return 1;
}

int shake_fun(string str) {
   if(!avatarp(TP)) return notify_fail("You don't have the power to do that!");
   if(!str) return notify_fail("What do you want to shake?");
   if(str != "bottle") return notify_fail("You can't shake that.");
   tell_object(TP,"%^WHITE%^%^BOLD%^You pick up the bottle and gives it a good shake.%^RESET%^");
   tell_room(TO,"%^WHITE%^%^BOLD%^"+TP->QCN+" picks up the bottle and gives it a good shake.%^RESET%^",TP);
   tell_room(TO,""+CRYSTALMSG[0]+"\n");
   TO->set_property("crystalmsg",1);
   call_out("domsg",3,TO);
   return 1;
}

void domsg(object ob){
   int flag;
   flag = ob->query_property("crystalmsg");
   ob->remove_property("crystalmsg");
   if(flag < sizeof(CRYSTALMSG)){
     tell_room(ob,""+CRYSTALMSG[flag]+"\n");
     flag++;
     ob->set_property("crystalmsg",flag);
     call_out("domsg",3,ob);
   }
}