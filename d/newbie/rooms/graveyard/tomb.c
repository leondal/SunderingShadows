//tomb.c - inherited room for cemetery's tomb
#include <std.h>
#include "graveyard.h"
inherit CROOM;

int searchflag;
void pick_treasure();

void create(){
   ::create();
   set_name("Musty tomb");
   set_property("light",2);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_short("%^BLUE%^Musty tomb%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","The air is musty and thick, and carries a foul smell.");
   set_listen("default","It is eerily quiet in here... a little too quiet.");
   set_items( ([
     "moss":"%^ORANGE%^Sporadic patches of moss and grime coat the crumbling remains of the tomb's walls.%^RESET%^", 
     ({"walls","stone walls","stone"}):"%^ORANGE%^The tomb's walls are made of crumbling stone, worn down over "
"the ages by weather and lack of care.  They are covered in sporadic patches of %^GREEN%^moss %^ORANGE%^and "
"grime.%^RESET%^", 
     ({"coffin","coffins"}):"%^ORANGE%^A few old wooden coffins have been stacked off to the side.  Some are large enough to fit a human, while some were obviously designed with a smaller body in mind.  They are all closed, but you could probably %^BLUE%^search%^ORANGE%^ them if you dared.%^RESET%^",
   ]) );
   set_search("default",(:TO,"search_room":));
   set_search("coffin",(:TO,"search_room":));
   set_search("coffins",(:TO,"search_room":));
}

void reset() {
   ::reset();
   searchflag = 1;
   switch(random(10)){
     case 0..2: break;
     case 3: tell_room(TO,"%^ORANGE%^A small breath of wind stirs the dust on the floor."); break;
     case 4: tell_room(TO,"%^CYAN%^A low moan echoes around the tomb... hopefully just the wind outside?"); break;
     case 5: tell_room(TO,"%^GREEN%^The musty air tickles at your nose."); break;
     case 6: tell_room(TO,"%^BOLD%^%^BLACK%^A faint scratching sound comes from down the hall."); break;
     case 7: tell_room(TO,"%^BOLD%^%^CYAN%^A brief, cold wind brushes past you, making you shiver."); break;
     case 8: tell_room(TO,"%^MAGENTA%^The hairs on the back of your neck tingle, sending chills down your spine."); break;
     case 9: tell_room(TO,"%^RED%^The air is heavy and still, so silent you can hear your own heartbeat."); break;
     default: break;
   }
}

int search_room(string str) {
   object ob;
   if (!str) {
     tell_object(TP,"%^ORANGE%^The coffins against the wall catch your attention.%^RESET%^");
     tell_room(ETP,""+TP->QCN+" searches around.",TP);
     return 1;
   }
   if (str != "coffin" && str != "coffins") {
     tell_object(TP,"You don't find anything.");
     tell_room(ETP,""+TP->QCN+" searches around, but doesn't find anything.",TP);
     return 1;
   }
   if(!searchflag) {
     write("It looks like they have already been searched.");
     return 0;
   }
   if(present("zombie",TO) || present("skeleton",TO) || present("spider",TO) || present("rat",TO)) {
     write("There is a creature in your way!");
     return 1;
   }
   switch(random(13)) {
     case 1..2:
       ob = new("/std/obj/coins");
       ob->set_money("gold", random(20)+2);
       ob->set_money("silver", random(50)+10);
       ob->set_money("copper", random(200)+50);
       ob->move(TO);
       tell_object(TP,"You find a few scattered coins in the bottom of one of the coffins.\n");
       tell_room(ETP,""+TP->QCN+" searches around in the coffins and finds a few coins.\n",TP);
       break;
     case 3:
       ob = new("/d/magic/scroll");
       ob->set_spell(1);
       ob->move(TO);
       tell_object(TP,"You find a dusty sheet of parchment in one of the coffins.\n");
       tell_room(ETP,""+TP->QCN+" searches through the coffins and finds a dusty sheet of parchment.\n",TP);
       break;
     case 4:
       ob = new("/d/magic/safe_scroll");
       ob->set_spell(2);
       ob->move(TO);
       tell_object(TP,"You find a dusty sheet of parchment in one of the coffins.\n");
       tell_room(ETP,""+TP->QCN+" searches through the coffins and finds a dusty sheet of parchment.\n",TP);
       break;
     case 5..7:
       ob = new("/d/common/obj/potion/healing");
       ob->set_uses(random(3)+2);
       ob->move(TO);
       tell_object(TP,"You find a few unbroken bottles in one of the coffins.\n");
       tell_room(ETP,""+TP->QCN+" searches through the coffins and finds a few unbroken bottles.\n",TP);
       break;
     case 8..9:
       pick_treasure();
       tell_object(TP,"You find something sparkly in one of the coffins.");
       tell_room(TO,""+TPQCN+" finds something sparkly in the bottom of a coffin.", TP);
       break;
     case 10:
       pick_treasure();
       tell_object(TP,"As you search the coffins, you disturb some rats!");
       tell_room(TO,""+TPQCN+" searches through the coffins, and finds some rats!", TP);
       new(MON"rat")->move(TO);
       new(MON"rat")->move(TO);
       break;
     case 11:
       tell_object(TP,"As you search the coffins, a spider jumps out at you!");
       tell_room(TO,""+TPQCN+" searches through the coffins, and finds a spider!", TP);
       new(MON"spider")->move(TO);
       break;
     default:
       tell_object(TP,"You don't find anything in the coffins.");
       tell_room(ETP,""+TP->QCN+" searches through the coffins but doesn't find anything.",TP);
       break;
   }
   searchflag = 0;
   return 1;
}

void pick_treasure() {
   switch(random(5)){
     case 0: new(CLOTHING"c_bracelet")->move(TO); break;
     case 1: new(CLOTHING"c_necklace")->move(TO); break;
     case 2: new(CLOTHING"c_ring")->move(TO); break;
     case 3: new(CLOTHING"c_clasp")->move(TO); break;
     case 4: new(CLOTHING"c_pendant")->move(TO); break;
   }
}
