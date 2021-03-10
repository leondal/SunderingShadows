#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

int searched;

void create(){
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Cargo hold");
   set_short("Cargo hold");
   set_long("%^BOLD%^Cargo hold%^RESET%^\n"
"This is the dark, dank cargo hold of the ship.  The floor, walls and roof are all made of the same old "
"%^ORANGE%^wood%^RESET%^, creaking as the boat rocks on the water.  Around you is an assortment of cartons "
"and crates, though you can only wonder at what might be within them.  A trapdoor outlined in heavy metal "
"is set within the ceiling, with an old set of creaky stairs leading up to it in the darkness.\n");
   set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
   set_listen("default","You hear the boards of the ship creak in an unsettling way.");
   set_items(([
     ({"floor","walls","roof","wood"}):"The floor, walls and roof are all made of the same old%^ORANGE%^ "
"wood%^RESET%^, that creaks as the ship moves.  The wood looks quite old, and is in desperate need of a "
"polish.",
     ({"crates","cartons"}):"A variety of crates and cartons are stacked around the room, you can only guess "
"at what might be in them.  You could probably take a look inside them if you wanted to.",
     "trapdoor":"A trapdoor is set within the ceiling, outlined in heavy metal.  If you're strong enough you "
"could probably try to lift it."
   ]));
   set_exits(([ ]));
   set_search("default","There isn't much in the room here except the assortment of crates and cartons.");
   set_search("crates",(:TO,"search_fun":));
   set_search("cartons",(:TO,"search_fun":));
   set_trap_functions(({"crates","cartons"}),({"trap_fun","trap_fun"}),({"search","search"}));
}

void reset(){
   object otherroom;
   ::reset();
   if(member_array("up",TO->query_exits()) != -1) {
     remove_exit("up");
     tell_room(TO,"Someone slams the trapdoor shut from above!");
     otherroom = find_object_or_load(COVE"boata02");
     if(member_array("down",otherroom->query_exits()) != -1) {
       tell_room(otherroom,"Someone slams the trapdoor shut from below!");
       otherroom->remove_exit("down");
     }
   }
   searched = 1;
   if(!random(2)) searched = 0;
   if(!trapped("crates")) {
     toggle_trap("crates","search");
     toggle_trap("cartons","search");
   }
}

void init(){
   ::init();
   add_action("liftem","lift");
}

int liftem(string str){
   object otherroom;
   if(!str) return notify_fail("Lift what?\n");
   if(str != "trapdoor") return notify_fail("What are you trying to lift?\n");
   if(member_array("up",TO->query_exits()) != -1) return notify_fail("It's already been lifted.\n");
   if((roll_dice(1,20))>(TP->query_stats("strength")))
     return notify_fail("You heave mightily but you can't seem to lift the heavy trapdoor.\n");
   tell_object(TP,"You lift the heavy trapdoor, revealing the ship's main deck above.");
   tell_room(ETP,""+TPQCN+" lifts the heavy trapdoor, revealing the ship's main deck above.",TP);
   add_exit(COVE"boata02","up");
   otherroom = find_object_or_load(COVE"boata02");
   tell_room(otherroom,"Someone lifts the heavy trapdoor from below!");
   otherroom->add_exit(COVE"boata04","down");
   return 1;
}

int search_fun(string str) {
   object thechest;
   if(searched) {
     tell_object(TP,"It looks like someone has already been through the crates, and taken anything of "
"value.");
     return 1;
   }
   // boat1: Coins, components, gems and one art item
   // boat2: Coins, components, gems and one scroll
   "/d/common/daemon/randstuff_d"->treas_chest(TO,5,4000);
   thechest = present("chest",TO);
   thechest->toggle_closed();
   "/d/common/daemon/randstuff_d"->find_stuff(thechest,"component",random(20));
   "/d/common/daemon/randstuff_d"->find_stuff(thechest,"component",random(20));
   switch(random(8)) {
     case 0: new(OBJ"gemknow")->move(thechest); break;
     case 1: new(OBJ"amberring")->move(thechest); break;
     case 2..8: new(OBJ"statue")->move(thechest); break;
   }
   switch(random(4)) {
     case 0: new(OBJ"map1")->move(thechest); break;
     case 1: new(OBJ"map2")->move(thechest); break;
     case 2: new(OBJ"map3")->move(thechest); break;
     case 3: new(OBJ"map4")->move(thechest); break;
   }
   thechest->toggle_closed();
   thechest->set_lock("locked");
   tell_object(TP,"You don't find much of value in the crates or cartons, except a single locked chest.");
   tell_room(TO,""+TP->QCN+" searches around the cartons and crates, and finds a locked chest.",TP);
   searched = 1;
   return 1;
}

int trap_fun(string str) {
   int i;
   object *pplz;
   pplz = all_living(TO);
   tell_object(TP,"As you search around the area, you accidentally bump an unnoticed wire across the floor.  "
"The wire snaps, and flames burst into the room around you!\n");
   tell_room(ETP,""+TPQCN+" searches around the area, and you hear something snap, as flames burst into the "
"air around you!\n",TP);
   tell_object(TP,"The flames crackle and burn at your skin!");
   TP->do_damage("torso",roll_dice(3,20));

   for(i=0;i<sizeof(pplz);i++) {
     if(pplz[i] != TO && pplz[i] != TP && !pplz[i]->query_true_invis() && objectp(pplz[i])) {
       if(!"daemon/saving_d"->saving_throw(pplz[i],"spell")) {
         tell_object(pplz[i],"The flames crackle and burn at your skin!\n");
         pplz[i]->do_damage("torso",roll_dice(3,20));
       }
       else {
         tell_object(pplz[i],"You dive to the side, avoiding the worst of the flames.\n");
         pplz[i]->do_damage("torso",roll_dice(1,20));
       }
     }
   }
   toggle_trap("crates","search");
   toggle_trap("cartons","search");
   return 1;
}
