#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

int searched;

void create(){
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Sleeping quarters");
   set_short("Sleeping quarters");
   set_long("%^BOLD%^Sleeping quarters%^RESET%^\n"
"This room is of a moderate size, sparsely furnished, but not without a certain degree of expense.  Despite "
"it being entirely closed in, it's still partially %^YELLOW%^lit %^RESET%^by several small, round windows "
"that have been placed within the far wall.  The roof, walls and floor are made of the same %^ORANGE%^timber"
"%^RESET%^, a little weathered by time, but have been recently %^WHITE%^%^BOLD%^polished%^RESET%^.  Across "
"the room is a bed with finely engraved posts, and an ornate bedside table rests beside it on the floor.  Several paintings adorn the walls, mostly of scenes of battle, though one particularly masterful piece shows a tiger stalking through long grass.  The doorway leads back to the west, into a short hallway.\n");
   set_smell("default","You smell fresh ocean air, lightly spiced with hints of tobacco.");
   set_listen("default","The waves of the ocean lap at the boat's sides.");
   set_items(([
     ({"deck","boards","wooden boards","roof","walls"}):"Wooden boards form the entirety of the roof, floor "
"and walls.  They are a little weathered over time, but they've obviously been polished recently.",
     "bed":"A bed sits against the back wall.  It looks far more expensive than anything the rest of the "
"pirates have to sleep on, and has finely engraved wooden posts.",
     "table":"Beside the bed is an ornate table, with five evenly-spaced legs.",
     "paintings":"Several paintings cover the walls here, mostly of battle scenes.  One particularly "
"striking piece, however, captures the image of a tiger stalking through long grass."
   ]));
   set_exits(([
     "west":COVE"boatb08"
   ]));
   set_search("default","There's a bed, a table, and several paintings on the walls.");
   set_search("bed",(:TO,"search_fun":));
   set_trap_functions(({"bed"}),({"trap_fun"}),({"search"}));
}

void reset() {
   searched = 1;
   if(!random(2)) searched = 0;
   if(!has_mobs()) {
     if(mons) mons = ([]);
     switch(random(3)) {
       case 0:
       set_monsters(({MON"piratecrew3"}),({1}));
       break;
       case 1:
       set_monsters(({MON"piratecrew2"}),({1}));
       break;
       case 2:
       set_monsters(({MON"piratecrew"}),({1}));
       break;
     }
   }
   ::reset();
}

int search_fun(string str) {
   object thechest,thescroll;
   if(present("pirate",TO)) {
     tell_object(TP,"The pirate is in your way.");
     return 1;
   }
   if(searched) {
     tell_object(TP,"You look under the bed, but you don't find anything.");
     return 1;
   }
   // boat1: Coins, components, gems and one art item
   // boat2: Coins, components, gems and one scroll
   "/d/common/daemon/randstuff_d"->treas_chest(TO,5,4000);
   thechest = present("chest",TO);
   thechest->toggle_closed();
   "/d/common/daemon/randstuff_d"->find_stuff(thechest,"component",random(20));
   "/d/common/daemon/randstuff_d"->find_stuff(thechest,"component",random(20));
     thescroll = new("/d/magic/scroll");
     thescroll->set_av_spell(random(3)+5);
     thescroll->move(thechest);
   switch(random(4)) {
     case 0: new(OBJ"map1")->move(thechest); break;
     case 1: new(OBJ"map2")->move(thechest); break;
     case 2: new(OBJ"map3")->move(thechest); break;
     case 3: new(OBJ"map4")->move(thechest); break;
   }
   thechest->toggle_closed();
   thechest->set_lock("locked");
   thechest->set_key("thereisnokey");
   thechest->set_lock_difficulty(40);
   tell_object(TP,"You search around under the bed, and find a small locked chest.");
   tell_room(TO,""+TP->QCN+" searches around under the bed, and finds a small chest.",TP);
   searched = 1;
   return 1;
}

int trap_fun(string str) {
   int i;
   object *pplz;
   pplz = all_living(TO);
   tell_object(TP,"You search around under the bed.  Something clicks, and suddenly a bolt of lightning "
"streaks directly through the air at you!\n");
   tell_room(ETP,""+TPQCN+" searches around the area, and you hear a click.  Suddenly a bolt of lightning streaks directly through the air, jolting "+TP->QO+" as it goes!\n",TP);
   TP->do_damage("torso",roll_dice(5,10));

   for(i=0;i<sizeof(pplz);i++) {
     if(pplz[i] != TO && pplz[i] != TP && !pplz[i]->query_true_invis() && objectp(pplz[i])) {
       if(!"daemon/saving_d"->saving_throw(pplz[i],"spell")) {
         tell_object(pplz[i],"The bolt of lightning catches you with full force!\n");
         pplz[i]->do_damage("torso",roll_dice(4,10));
       }
       else {
         tell_object(pplz[i],"The bolt of lightning barely misses you, making your hair stand on end!\n");
         pplz[i]->do_damage("torso",roll_dice(2,10));
       }
     }
   }
   toggle_trap("bed","search");
   return 1;
}
