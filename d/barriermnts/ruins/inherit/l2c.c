// level 2 rooms

#include <std.h>
#include "../inherit/ruins.h"
inherit VAULT;

int searchflag;

void create() {
    ::create();
    searchflag = random(20);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("Enclosed room of an abandoned building");
    set_short("%^ORANGE%^Enclosed room of an abandoned building%^RESET%^");
    set_smell("default","An old, musty smell brushes at your nose.");
    set_listen("default","Whispers echo off the walls around you... or is that just the wind?");
    set_items(([
      "floor" : "%^ORANGE%^The floor is perfectly level beneath your feet, set with "
"%^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^-coated tiles.  Covering most of the tiles is a layer of old, "
"%^RED%^moroon%^ORANGE%^ carpet.%^RESET%^",
      "carpet" : "%^ORANGE%^A layer of %^RED%^deep moroon%^ORANGE%^ carpet rests over most of the tiles, "
"covering the centre of the floor and up to the door, cushioning your steps.  It looks rather old and is "
"smudged with grime, but is otherwise undamaged.%^RESET%^",
      ({"walls","wall"}) : "%^ORANGE%^Thick %^BLACK%^%^BOLD%^dirt%^RESET%^%^ORANGE%^ coats the stone "
"walls on all sides of you, though an occasional clearer patch reveals what must have once been "
"detailed patterns upon them; somehow these have been preserved over the ages.  Ornate bordering lines "
"the edges where the walls meet the ceiling, covered in dust and the occasional spiderweb.%^RESET%^",
      "roof" : "%^ORANGE%^The roof reaches high above your head, shrouded in a thick layer of "
"%^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Beneath the grime, you can just make out the remains of what "
"must have once been elaborately decorated mosaic tiles.  No cracks or damages mar the tiles, even "
"though they must be very old.  Ornate bordering from nearby walls traces along the ceiling's "
"edges, covered in dust and an occasional spiderweb.%^RESET%^",
      ({"dirt","dust"}) : "%^ORANGE%^A thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ coats "
"every visible surface.  The building has probably been abandoned for a long time.%^RESET%^",
      "beds" : "%^ORANGE%^Several simple beds are placed around the room, covered in dusty "
"sheets.%^RESET%^",
      "desk" : "%^ORANGE%^A single desk stands against the wall.  It is set with a few closed "
"drawers.%^RESET%^",
      "cupboard" : "%^ORANGE%^The tall cupboard's doors are closed, and a thick layer of dust coats "
"it.%^RESET%^"
    ]));
    set_search("default",(:TO,"search_room":));
    set_search("desk",(:TO,"search_room":));
    set_search("beds",(:TO,"search_room":));
    set_search("cupboard",(:TO,"search_room":));
}

void set_string(string id, string which, string str) {
   if(!id) return;
   if(!which) return;
   if(!doors) return;
   if(!doors[id]) return;
   if (which == "open") {
     switch(random(3)) {
       case 0:
       str = "The door swings open silently, shedding a little dust onto the carpet.";
       break;
       case 1:
       str = "The door opens with a soft whisper as it brushes along the carpet.";
       break;
       case 2:
       str = "The door slides open soundlessly despite its aged hinges.";
       break;
     }
   }
   else {
     switch(random(3)) {
       case 0:
       str = "The door slides easily shut.";
       break;
       case 1:
       str = "The door closes with a quiet click.";
       break;
       case 2:
       str = "The door offers not a creak as it closes.";
       break;
     }
   }
   doors[id][which+" string"] = str;
}

void set_open(string id, int open) {
    if(!id) return;
    if(!doors) return;
    if(!doors[id]) return;
    doors[id]["open"] = open;
    if (open == 1) { set_string(id,"open","stuff"); }
    else { set_string(id,"close","stuff"); }
}

void reset() {
    ::reset();
    searchflag = random(20);
}

int search_room(string str) {
    object ob;
    if (!str) {
      tell_object(TP,"Where do you want to search?");
      tell_room(ETP,""+TP->QCN+" searches around.",TP);
      return 1;
    }
    if (str != "desk" && str != "cupboard" && str != "beds") {
      tell_object(TP,"You don't find anything.");
      tell_room(ETP,""+TP->QCN+" searches around, but doesn't find anything.",TP);
      return 1;
    }
    if (str == "desk") {
      switch(searchflag) {
        case 1..2:
        new("/d/antioch/valley/obj/gem")->move(ETP);
        tell_object(TP,"You find a gem hidden in one of the desk drawers.\n");
        tell_room(ETP,""+TP->QCN+" rummages through the desk's drawers and seems to find "
"something.\n",TP);
        searchflag = 0;
        break;
        case 3:
        ob = new("/d/magic/scroll");
        ob->set_av_spell(random(2)+5);
        ob->move(ETP);
        tell_object(TP,"You find a rolled-up sheet of parchment in a drawer.\n");
        tell_room(ETP,""+TP->QCN+" searches through the desk's drawers and seems to find "
"something.\n",TP);
        searchflag = 0;
        break;
        case 4:
        ob = new("/std/obj/coins");
        ob->set_money("gold",random(12)*random(13));
        ob->set_money("electrum",random(12)*7);
        ob->move(ETP);
        tell_object(TP,"You find a few coins hidden away in one drawer.\n");
        tell_room(ETP,""+TP->QCN+" searches through the desk's drawers and seems to find "
"something.\n",TP);
        searchflag = 0;
        break;
        default:
        tell_object(TP,"You don't find anything in the desk's drawers.");
        tell_room(ETP,""+TP->QCN+" searches through the desk's drawers but doesn't find anything.",TP);
        break;
      }
    }
    if (str == "beds") {
      switch (searchflag) {
        case 5:
        new("/d/common/obj/misc/soap")->move(ETP);
        tell_object(TP,"You find an unused bar of soap put away at the foot of one of the beds.\n");
        tell_room(ETP,""+TP->QCN+" searches around the beds and seems to find something.\n",TP);
        searchflag = 0;
        break;
        case 6:
        new(OBJ+"ribbons")->move(ETP);
        tell_object(TP,"You find a few pretty hair-ribbons hidden under a pillow.\n");
        tell_room(ETP,""+TP->QCN+" searches around the beds and seems to find something.\n",TP);
        searchflag = 0;
        break;
        case 7:
        new(OBJ+"oils")->move(ETP);
        tell_object(TP,"You find a bottle of scented oils under the a pillow.\n");
        tell_room(ETP,""+TP->QCN+" searches around the beds and seems to find something.\n",TP);
        searchflag = 0;
        break;
        case 8:
        new(OBJ+"perfume")->move(ETP);
        tell_object(TP,"You find a vial of soft-smelling perfume amongst the sheets of one bed.\n");
        tell_room(ETP,""+TP->QCN+" searches around the beds and seems to find something.\n",TP);
        searchflag = 0;
        break;
        default:
        tell_object(TP,"You don't find anything in the beds.");
        tell_room(ETP,""+TP->QCN+" searches around the beds but doesn't find anything.",TP);
        break;
      }
    }
    if (str == "cupboard") {
      switch (searchflag) {
        case 9:
        new("/std/obj/cloth.c")->move(ETP);
        tell_object(TP,"You find a length of cloth folded up near the back of the cupboard.\n");
        tell_room(ETP,""+TP->QCN+" searches around in the cupboard and seems to find something.\n",TP);
        searchflag = 0;
        break;
        case 10:
        new("/d/common/obj/misc/lantern")->move(ETP);
        new("/d/common/obj/misc/oil")->move(ETP);
        tell_object(TP,"You find an unused lantern and some oil, stashed away at the back of the "
"cupboard.\n");
        tell_room(ETP,""+TP->QCN+" searches around in the cupboard and seems to find something.\n",TP);
        searchflag = 0;
        break;
        case 11..12:
        new("/d/antioch/valley/obj/jewelry")->move(ETP);
        tell_object(TP,"You find a delicate piece of jewelry hidden within the cupboard.\n");
        tell_room(ETP,""+TP->QCN+" searches around in the cupboard and seems to find something.\n",TP);
        searchflag = 0;
        break;
        default:
        tell_object(TP,"You don't find anything in the cupboard.");
        tell_room(ETP,""+TP->QCN+" searches around in the cupboard but doesn't find anything.",TP);
        break;
      }
    }
    return 1;
}
