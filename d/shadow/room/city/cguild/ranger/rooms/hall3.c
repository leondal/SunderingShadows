#include <std.h>
#include "../ranger.h"
inherit ROOM;

#define DARKWOOD "/d/tharis/conforest/rooms/"
#define MOONSTONE "/d/antioch/valley/rooms/"
#define KILKAEN "/d/dagger/road/"
#define SHADOWLORD "/d/deku/forest/"
#define PARNELLI "/d/laerad/parnelli/forest/"
#define PETH "/d/undead/rooms/forest/"
#define KILDARE ({\
   "/d/shadow/room/kildare/rooms/roads/wroad02.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad03.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad04.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad05.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad06.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad07.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad08.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad09.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad10.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad11.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad12.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad13.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad14.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad15.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad16.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad17.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad18.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad19.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad20.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad21.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad22.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad23.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad24.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad25.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad26.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad27.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad28.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad29.c",\
   "/d/shadow/room/kildare/rooms/roads/wroad30.c",\
})
#define ATTAYA ({\
   "/d/attaya/jungle/jun1.c",\
   "/d/attaya/jungle/jun2.c",\
   "/d/attaya/jungle/jun3.c",\
   "/d/attaya/jungle/jun4.c",\
   "/d/attaya/jungle/jun5.c",\
   "/d/attaya/jungle/jun6.c",\
   "/d/attaya/jungle/jun7.c",\
   "/d/attaya/jungle/jun8.c",\
   "/d/attaya/jungle/jun9.c",\
   "/d/attaya/jungle/jun10.c",\
   "/d/attaya/jungle/jun11.c",\
   "/d/attaya/jungle/jun13.c",\
   "/d/attaya/jungle/jun14.c",\
   "/d/attaya/jungle/jun15.c",\
   "/d/attaya/jungle/jun16.c",\
   "/d/attaya/jungle/jun17.c",\
   "/d/attaya/jungle/jun18.c",\
   "/d/attaya/jungle/jun19.c",\
   "/d/attaya/jungle/jun20.c",\
   "/d/attaya/jungle/jun21.c",\
   "/d/attaya/jungle/jun22.c",\
   "/d/attaya/jungle/jun23.c",\
   "/d/attaya/jungle/jun24.c",\
   "/d/attaya/jungle/jun25.c",\
   "/d/attaya/jungle/jun26.c",\
   "/d/attaya/jungle/jun27.c",\
   "/d/attaya/jungle/jun28.c",\
   "/d/attaya/jungle/jun29.c",\
   "/d/attaya/jungle/jun30.c",\
})
#define NOTMOONSTONE ({\
   "/d/antioch/valley/rooms/walnut.c",\
   "/d/antioch/valley/rooms/willow.c",\
   "/d/antioch/valley/rooms/ogrecamp.c",\
   "/d/antioch/valley/rooms/orccave.c",\
   "/d/antioch/valley/rooms/cave1.c",\
   "/d/antioch/valley/rooms/cave2.c",\
   "/d/antioch/valley/rooms/fring.c",\
})
#define NOTKILKAEN ({\
   "/d/dagger/road/hut.c",\
   "/d/dagger/road/bridge2.c",\
   "/d/dagger/road/monsters_d.bkp",\
   "/d/dagger/road/monsters_d.c",\
   "/d/dagger/road/road2.bak.saide",\
   "/d/dagger/road/road2b.bak.saide",\
   "/d/dagger/road/road3.bak.saide",\
   "/d/dagger/road/road1.c",\
   "/d/dagger/road/road2.c",\
   "/d/dagger/road/road2b.c",\
   "/d/dagger/road/road3.c",\
   "/d/dagger/road/road4.c",\
   "/d/dagger/road/tollbooth.c",\
   "/d/dagger/road/tollbooth2.c",\
   "/d/dagger/road/short.h",\
   "/d/dagger/road/tsrroom.c",\
})
#define NOTSHADOWLORD ({\
   "/d/deku/forest/dforest11-al2.c",\
   "/d/deku/forest/dforest11-al2a.c",\
})
#define NOTPARNELLI ({\
   "/d/laerad/parnelli/forest/carr1.c",\
   "/d/laerad/parnelli/forest/carr3.c",\
   "/d/laerad/parnelli/forest/hut.c",\
   "/d/laerad/parnelli/forest/pittrap1.c",\
   "/d/laerad/parnelli/forest/pittrap2.c",\
})
#define ARGH ({\
   "/d/islands/argentrock/rooms/argpath1",\
   "/d/islands/argentrock/rooms/argpath2",\
   "/d/islands/argentrock/rooms/argpath3",\
   "/d/islands/argentrock/rooms/argpath4",\
   "/d/islands/argentrock/rooms/argpath5",\
})
void create(){
   ::create();
   set_terrain(BRANCHES);
   set_travel(DIRT_ROAD);
   set_property("light",2);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_name("Near the top of the World Tree");
   set_short("%^RESET%^%^GREEN%^Near the top of the World Tree%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Near the top of the World Tree%^RESET%^\n"
"%^RESET%^%^ORANGE%^You have found your way to the very top of this impossibly large %^GREEN%^oak tree"
"%^ORANGE%^.  Standing within a hollow inside the trunk, the massive %^GREEN%^branches %^ORANGE%^spread and "
"cross above your head, blotting out the sky from view.  The room you stand in is roughly circular and "
"bordered on all sides by rough walls of %^RED%^wood %^ORANGE%^and %^BOLD%^%^BLACK%^bark%^RESET%^%^ORANGE%^.  "
"Beneath your feet, a relatively smooth level of wood seems to have grown to form a floor.  %^RED%^Wooden slats"
"%^ORANGE%^, almost like tree limbs, grow outwards from the inside of the trunk, forming a circular pathway of "
"stairs that leads down around the edge of the room to unseen areas below.  Softly glowing orbs of %^GREEN%^vi"
"%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh%^GREEN%^t %^ORANGE%^shed a gentle radiance about the partially enclosed "
"room, replacing the natural light that fails to penetrate the canopy above.  At a few points around the room, "
"however, gaps can be seen between the branches that a person could easily fit through, to make their way into "
"the %^GREEN%^fo%^BOLD%^re%^RESET%^%^GREEN%^st %^ORANGE%^beyond.\n%^RESET%^");
   set_smell("default","The sweet smell of fresh air and greenery surrounds you.");
   set_listen("default","The quiet surroundings are occasionally interrupted by the soft creak of wood.");

   set_items(([
     ({"walls","wood","bark","tree","trunk","stairs","limbs","slats","pathway","roof","floor"}):"%^RESET%^"
"%^ORANGE%^The sturdy trunk of a %^GREEN%^massive oak tree %^ORANGE%^forms this room, enclosed on all sides "
"except above by %^RED%^rough-barked wood%^ORANGE%^.  The floor is formed of the same wood, which appears to "
"have grown naturally into the flat layers that provide the remaining enclosure to the room.  %^RED%^Wooden "
"slats%^ORANGE%^, much like tree limbs, have grown outwards from the walls to provide a circular stairway that "
"leads down into rooms below you.%^RESET%^",
     ({"branches","canopy","sky"}):"%^RESET%^%^ORANGE%^Above your head, the canopy of %^RED%^branches "
"%^ORANGE%^and %^GREEN%^leaves %^ORANGE%^spreads and crosses, blotting out the sky from view.  A few gaps "
"remain visible between them, letting %^CYAN%^fresh air %^ORANGE%^into the room.  Only a small handful of them "
"look big enough for a person to escape through.%^RESET%^",
     ({"orbs","light","radiance"}):"%^RESET%^%^ORANGE%^Around the walls, softly glowing orbs of %^GREEN%^vi"
"%^CYAN%^rid%^GREEN%^ian li%^CYAN%^gh%^GREEN%^t %^ORANGE%^shed a gentle radiance upon the room itself."
"%^RESET%^",
     "gaps":"%^RESET%^%^ORANGE%^A few gaps lie between the branches, most only small enough to let %^CYAN%^"
"fresh air %^ORANGE%^in.  Only a handful look big enough to permit escape by a person, into the %^GREEN%^fo"
"%^BOLD%^re%^RESET%^%^GREEN%^st %^ORANGE%^beyond.  Though a closer look reveals that the forest appears "
"different through each one... as if they each opened upon a different location entirely.%^RESET%^",
   ]));

   set_exits(([
     "darkwood":"/d/tharis/conforest/rooms/path1",
     "moonstone":"/d/antioch/valley/rooms/v4",
     "kildare":"/d/shadow/room/kildare/rooms/roads/wroad02",
     "kilkaen":"/d/dagger/road/road40",
     "shadowlord":"/d/deku/forest/dforest15-5",
     "attaya":"/d/attaya/jun1",
     "parnelli":"/d/laerad/parnelli/forest/for070",
     "peth":"/d/undead/rooms/forest/room5",
     "argentrock":"/d/islands/argentrock/rooms/argpath1",
     "down":RROOM"hall2",
   ]));

   set_pre_exit_functions(({"darkwood"}),({"darkwood_fun"}));
   set_pre_exit_functions(({"moonstone"}),({"moonstone_fun"}));
   set_pre_exit_functions(({"kildare"}),({"kildare_fun"}));
   set_pre_exit_functions(({"kilkaen"}),({"kilkaen_fun"}));
   set_pre_exit_functions(({"shadowlord"}),({"shadowlord_fun"}));
   set_pre_exit_functions(({"attaya"}),({"attaya_fun"})); 
   set_pre_exit_functions(({"parnelli"}),({"parnelli_fun"}));
   set_pre_exit_functions(({"peth"}),({"peth_fun"}));
   set_pre_exit_functions(({"argentrock"}),({"argh_fun"}));
}

void reset(){
   ::reset();
   if(!present("tree")) new(RNPC"tree")->move(TO);
}

void init() {
   ::init();
   add_action("sneak_fun","sneak");
   add_action("peer_fun","peer");
}

int sneak_fun(string str){
   if(!str) return 0;
   if(str == "down" || str == "d") return 0;
   if(TP->is_class("ranger") || TP->is_class("druid")) return 0;
   tell_object(TP,"%^GREEN%^You move stealthily forward, but you realise the treant is watching you still, and "
"you find that the very gaps in the branches seem to close before you!  It seems stealth will not aid you "
"here.%^RESET%^");
   return 1;
}

int peer_fun(string str){
   if(!str) return 0;
   if(str == "down" || str == "d") return 0;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see a vast forest beyond.  You're "
"not entirely sure as to its identity or location.%^RESET%^");
     return 1;
   }
   switch(str) {
     case "darkwood":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see a %^ORANGE%^temperate forest "
"%^GREEN%^beyond that is scattered with broadleaf trees and shrubs.  It resembles %^CYAN%^Darkwood forest"
"%^GREEN%^, near the mainland city of Shadow.%^RESET%^");
     break;
     case "parnelli":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see a vibrant, open forest that "
"seems almost %^BOLD%^gli%^YELLOW%^t%^GREEN%^tering %^RESET%^%^GREEN%^with life.  It could only be %^CYAN%^"
"Parnelli Forest%^GREEN%^, upon the island of Laerad.%^RESET%^");
     break;
     case "peth":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see a %^BLUE%^dark and dismal "
"forest %^GREEN%^beyond, populated by trees that seem mostly to be in stages of death and decay.  This place "
"could only be %^CYAN%^Peth Forest%^GREEN%^, upon the cursed island of Graez.%^RESET%^");
     break;
     case "shadowlord":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see a vast %^BOLD%^%^BLACK%^"
"shadowed forest %^RESET%^%^GREEN%^bordered on the far reaches by the lapping waves of the %^BOLD%^%^BLUE%^"
"ocean%^RESET%^%^GREEN%^.  It resembles the %^CYAN%^Shadowlord Forest%^GREEN%^, upon the island of "
"Deku.%^RESET%^");
     break;
     case "attaya":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see a %^YELLOW%^tropical %^RESET%^"
"%^GREEN%^jungle of palms and vines.  It resembles the jungle upon the island of %^CYAN%^Attaya%^GREEN%^."
"%^RESET%^");
     break;
     case "kildare":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see "
"a %^BOLD%^tree-shadowed %^RESET%^%^GREEN%^path beyond, winding its way up a "
"mountain.  It is well worn from use, with scattered %^ORANGE%^cairnstones "
"%^GREEN%^at intervals to mark its passage.  This must be the rangers' trail "
"leading to %^CYAN%^Kildare%^GREEN%^.%^RESET%^");
     break;
     case "kilkaen":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see an %^BOLD%^evergreen woodland "
"%^RESET%^%^GREEN%^beyond, dotted with fir and pine trees.  The area resembles the %^CYAN%^Kilkaen forest"
"%^GREEN%^, in the cold northern Dagger region of the mainland.%^RESET%^");
     break;
     case "moonstone":
     tell_object(TP,"%^GREEN%^You peer between the gap in the branches, and see a thick-grassed valley "
"bordered by %^BLUE%^dark forest %^GREEN%^on all sides.  It resembles the %^CYAN%^Moonstone Vale%^GREEN%^, "
"north of the mainland city of Antioch.%^RESET%^");
     break;
     case "argentrock":
     tell_object(TP,"%^GREEN%^You peer between the gap in the "+
     "branches, and see a dangerous looking forest covered "+
     "island.   Huge beasts roam about looking for prey.%^RESET%^");
     break;
     default: return 0; break;
   }
   return 1;
}

string *get_rooms(string str) {
    string *rooms, *rooms2, *rooms3, thisroom, notstr;
    int i;

    rooms = ({});
    switch(str) {
      case "darkwood":
      rooms = get_dir(DARKWOOD);
      rooms2 = ({});
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = DARKWOOD+rooms[i];
        if(strsrch(thisroom,"path") != -1) rooms2 += ({thisroom});
      }
      break;

      case "moonstone":
      rooms = get_dir(MOONSTONE);
      rooms2 = ({});
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = MOONSTONE+rooms[i];
        if(((strsrch(rooms[i],"g") != -1) || (strsrch(rooms[i],"m") != -1) || (strsrch(rooms[i],"w") != -1) || (strsrch(rooms[i],"v") != -1)) && (strsrch(rooms[i],"bk") == -1))
          rooms2 += ({thisroom});
      }
      rooms2 -= NOTMOONSTONE;
      break;

      case "kildare":
      rooms2 = ({});
      rooms2 += KILDARE;
      break;

      case "kilkaen":
      rooms = get_dir(KILKAEN);
      rooms2 = ({});
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = KILKAEN+rooms[i];
        rooms2 += ({thisroom});
      }
      rooms2 -= NOTKILKAEN;
      break;

      case "shadowlord":
      rooms = get_dir(SHADOWLORD);
      rooms2 = ({});
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = SHADOWLORD+rooms[i];
        rooms2 += ({thisroom});
      }
      rooms2 -= NOTSHADOWLORD;
      break;

      case "attaya":
      rooms2 = ({});
      rooms2 += ATTAYA;
      break;
      case "argentrock":
      rooms2 = ({});
      rooms2 += ARGH;
      break;

      case "parnelli":
      rooms = get_dir(PARNELLI);
      rooms2 = ({});
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = PARNELLI+rooms[i];
        rooms2 += ({thisroom});
      }
      rooms2 -= NOTPARNELLI;
      break;

      case "peth":
      rooms = get_dir(PETH);
      rooms2 = ({});
      for (i=0;i<sizeof(rooms);i++) {
        thisroom = PETH+rooms[i];
        rooms2 += ({thisroom});
      }
      break;
      
    }
    return rooms2;
}

int darkwood_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you find yourself upon a pathway through a temperate forest, where a great canopy of broadleaf "
"trees looms overhead.%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("darkwood");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees that line the path.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int moonstone_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   if((int)TP->query_level() < 15) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you in warning.  You realise the forest beyond is likely "
"not safe for you to be in.%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you find yourself in a grassy meadow bordered by a dark and looming forest.%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("moonstone");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int kildare_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you step free of the trees to find yourself upon a well-travelled pathway leading "
"up a mountainside.%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("kildare");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees that line the path.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int kilkaen_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   if((int)TP->query_level() < 10) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you in warning.  You realise the forest beyond is likely "
"not safe for you to be in.%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you step free of the evergreen woods to find yourself upon a well-travelled roadway that cuts "
"through its heart.%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("kilkaen");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees at the side of the road.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int shadowlord_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   if((int)TP->query_level() < 15) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you in warning.  You realise the forest beyond is likely "
"not safe for you to be in.%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you find yourself within a vast %^BOLD%^%^BLACK%^shadowed forest%^RESET%^%^GREEN%^.%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("shadowlord");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int attaya_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   if((int)TP->query_level() < 25) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you in warning.  You realise the forest beyond is likely "
"not safe for you to be in.%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you step free of the thick tropical jungle onto a path that has been carved through its heart."
"%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("attaya");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees at the side of the path.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int parnelli_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   if((int)TP->query_level() < 20) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you in warning.  You realise the forest beyond is likely "
"not safe for you to be in.%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you find yourself in a vibrant forest that near sparkles with life.%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("parnelli");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int peth_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   if((int)TP->query_level() < 25) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you in warning.  You realise the forest beyond is likely "
"not safe for you to be in.%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you find yourself in a dark forest, filled with trees that are dead or nearly so.%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("peth");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}

int argh_fun(){
   string place, *rooms;
   if(!TP->is_class("ranger") && !TP->is_class("druid") && !TP->query_true_invis()) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you!%^RESET%^");
      return 0;
   }
   if((int)TP->query_level() < 25) {
      tell_object(TP,"%^GREEN%^You move forward, but you realise the treant is watching you, and you find that "
"the very gaps in the branches seem to close before you in warning.  You realise the forest beyond is likely "
"not safe for you to be in.%^RESET%^");
      return 0;
   }
   tell_object(TP,"%^GREEN%^You move forward, slipping through the gap in the branches with ease.  Upon the "
"other side, you step into a thick forest with flowers and mushrooms."
"%^RESET%^");
   tell_room(ETP,"%^GREEN%^"+TP->QCN+" moves forward and slips through a gap in the branches with ease, "
"disappearing from view into the forest beyond.%^RESET%^",TP);
   rooms = ({});
   rooms = get_rooms("argentrock");
   place = rooms[random(sizeof(rooms))];
   tell_room(place,"%^GREEN%^"+TP->QCN+" steps out from among the trees at the side of the path.%^RESET%^",TP);
   TP->move_player(place);
   return 0;
}
