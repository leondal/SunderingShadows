#include <std.h>
#include "../inherit/ruins.h"
inherit VAULT;

int chestflag,sigilflag;

void create() {
    ::create();
    chestflag = 0;
    sigilflag = 1;
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("Enclosed room of an abandoned building");
    set_short("%^ORANGE%^Enclosed room of an abandoned building%^RESET%^");
    set_smell("default","The air is clean, but a little stale.");
    set_listen("default","It is distinctly silent in here.");
    set_long("%^ORANGE%^This room is lavishly decorated, and surprisingly is entirely free of dust and "
"dirt, as if someone or something had been keeping it clean.  The immediate feature that catches your "
"eye is the large, arching window of %^CYAN%^mu%^BLUE%^lt%^GREEN%^i-%^RED%^hu%^MAGENTA%^ed%^ORANGE%^ "
"glass that takes up most of the northern wall, giving a view of the path and steps that lead up to the "
"building outside.  %^RED%^Blood-red%^ORANGE%^ drapes frame either side of the window, brushing against "
"the carpeted floor.  Against the western wall is a comfortable-looking bed, covered in sheets of the "
"same deep hue as the curtains.  Sitting beside the bed is an ornate dresser, upon which rests a "
"%^CYAN%^%^BOLD%^crystal globe%^RESET%^%^ORANGE%^, and a small %^BLACK%^%^BOLD%^wooden chest%^RESET%^ "
"%^ORANGE%^covered in patterned engravings.  Opposite this on the east side of the room, is a broad "
"cupboard of the same wood as the dresser, and beside it a large %^CYAN%^mirror%^ORANGE%^ rests against "
"the wall.  The stone walls here rise up to meet the roof with the same ornate border designs as the rest "
"of the building, but here they are perfectly clean, and above you are visible the mosaic tiles covering "
"the roof.  Within the south wall is set a door of a %^RED%^da%^BOLD%^r%^RESET%^%^RED%^k "
"cri%^BOLD%^m%^RESET%^%^RED%^son%^ORANGE%^ hue, blending in with the room's red decor.  A faint presence "
"lingers in the air here, making you feel somewhat uneasy.%^RESET%^\n");
    set_items(([
      "floor" : "%^ORANGE%^The floor is perfectly level beneath your feet, set with "
"%^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^-coated tiles.  Covering most of the tiles is a layer of "
"%^RED%^moroon%^ORANGE%^ carpet.%^RESET%^",
      "carpet" : "%^ORANGE%^A layer of %^RED%^deep moroon%^ORANGE%^ carpet rests over most of the tiles, "
"covering the centre of the floor and up to the door, cushioning your steps.  It looks rather old, "
"though it is in flawless condition.%^RESET%^",
      ({"walls","wall"}) : "%^ORANGE%^No dust or dirt conceals the detailed patterns upon the walls "
"around you; somehow these have been preserved over the ages.  Ornate bordering lines the edges where "
"the walls meet the ceiling.%^RESET%^",
      "roof" : "%^ORANGE%^The roof reaches high above your head, covered in elaborately decorated mosaic "
"tiles.  No cracks or damages mar the tiles, even though they must be very old.  Ornate bordering from "
"nearby walls traces along the ceiling's edges.%^RESET%^",
      "drapes" : "%^ORANGE%^A pair of %^RED%^blood-red%^ORANGE%^ drapes border the large window to the "
"north, matching perfectly with the room's red decor.  Their long, flowing ends brush lightly on the "
"carpeted floor.",
      "window" : "%^ORANGE%^A high window of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass is set "
"within the northern wall. No dirt or dust blackens its surface, letting light into the room and "
"revealing a clear %^CYAN%^view%^ORANGE%^ of the path leading to the building.%^RESET%^",
      "bed" : "%^ORANGE%^A comfortable-looking bed rests against the western wall, covered with "
"%^RED%^crimson sheets%^ORANGE%^.%^RESET%^",
      "dresser" : "%^ORANGE%^This exquisitely-carved dresser is set against the western wall, beside the "
"bed.  Upon it is a %^CYAN%^%^BOLD%^crystal globe%^RESET%^%^ORANGE%^, and a small wooden chest.%^RESET%^",
      ({"globe","crystal globe"}) : "%^ORANGE%^Upon the dresser, to the left side, sits a globe made of "
"perfect %^CYAN%^%^BOLD%^crystal%^RESET%^%^ORANGE%^.  You feel your eyes drawn to it, and are almost "
"overcome with a desire to gaze into the globe.%^RESET%^",
      ({"chest","wooden chest"}) : "%^ORANGE%^A small wooden chest is set directly upon the centre of "
"the dresser. Its lid is currently closed.%^RESET%^",
      "cupboard" : "%^ORANGE%^A tall cupboard stands against the east wall, beside the tall "
"mirror.%^RESET%^",
      "mirror" : "%^ORANGE%^A tall mirror, that nearly reaches from the roof to the floor, is hung "
"against the wall beside the cupboard.  It is bordered by an ornate frame of the same wood as the "
"dresser and cupboard.  It looks just like a normal mirror, but something doesn't seem quite right about "
"it... maybe you should look closer at it.%^RESET%^"
    ]));
    set_exits(([
      "south" : ROOMS+"t1"
    ]));
    set_door("crimson door",ROOMS+"t1","south",0);
    set_door_description("crimson door","%^ORANGE%^The door within the south wall is perfectly free of "
"dust and dirt. It is of a %^RED%^da%^BOLD%^r%^RESET%^%^RED%^k cri%^BOLD%^m%^RESET%^%^RED%^son%^ORANGE%^ "
"colour, and despite its obvious age, it looks to be in near perfect condition.%^RESET%^");
    set_string("crimson door","open","stuff");
    set_string("crimson door","close","stuff");
}

void init() {
   ::init();
   add_action("view_fun","view");
   add_action("open_fun","open");
   add_action("close_fun","close");
   add_action("take_fun","take");
   add_action("crystal_fun","gaze");
   add_action("mirror_fun","step");
   add_action("mirror_fun2","enter");
   add_action("mirrorlook","look");
}

void reset() {
   object mycrystal;
   ::reset();
   sigilflag = 1;
   chestflag = 0;
   remove_item("chest");
   remove_item("wooden chest");
   add_item("chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the dresser.  Its "
"lid is currently closed.%^RESET%^");
   add_item("wooden chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the "
"dresser.  Its lid is currently closed.%^RESET%^");
   if(!present("crystal ball")) {
     mycrystal = new("/d/magic/obj/crystal_ball");
     mycrystal->move(TO);
     mycrystal->set_long("%^ORANGE%^Upon the dresser, to the left side, sits a globe made of perfect %^CYAN%^%^BOLD%^crystal%^RESET%^%^ORANGE%^.  You feel your eyes drawn to it, and are almost overcome with a desire to gaze into the globe.%^RESET%^");
   }
}
   
int view_fun(string str) {
   object *viewed;
   int i;
   viewed = all_living(find_object_or_load(ROOMS+"path0"));
   tell_object(TP,"You look down from the window to the pathway below.");
   tell_room(ETP,""+TPQCN+" looks out the window.",TP);
   tell_object(TP,"%^ORANGE%^Before an old building%^RESET%^\n");
   for(i=0;i<sizeof(viewed);i++) {
      if(!viewed[i]->query_invis())
         tell_object(TP,viewed[i]->query_short());
   }
   return 1;
}

int open_fun(string str) {
   if (!str) {
     notify_fail("Open what?");
     return 0;
   }
   if (str != "chest") {
     notify_fail("You can't open that.");
     return 0;
   }
   if (chestflag == 1) {
     write("It is already open.");
     return 1;
   }
   chestflag = 1;
   tell_room(ETP,""+TP->QCN+" opens the chest on the dresser.\n",TP);
   remove_item("chest");
   remove_item("wooden chest");
   if (sigilflag == 0) {
     tell_object(TP,"You open the chest on the dresser, to reveal an empty interior.\n");
     add_item("chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the dresser.  "
"Its lid is open, revealing an empty interior.%^RESET%^");
     add_item("wooden chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the "
"dresser.  Its lid is open, revealing an empty interior.%^RESET%^");
     return 1;
   }
   tell_object(TP,"You open the chest on the dresser, and notice something within it.\n");
   add_item("chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the dresser. Its "
"lid is open, revealing a %^GREEN%^%^BOLD%^glowing green sigil%^RESET%^%^ORANGE%^ you could probably "
"%^CYAN%^take%^ORANGE%^.%^RESET%^");
   add_item("wooden chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the "
"dresser.  Its lid is open, revealing a %^GREEN%^%^BOLD%^glowing green sigil%^RESET%^%^ORANGE%^ you "
"could probably %^CYAN%^take%^ORANGE%^.%^RESET%^");
   return 1;
}

int close_fun(string str) {
   if (!str) {
     notify_fail("Open what?");
     return 0;
   }
   if (str != "chest") {
     notify_fail("You can't open that.");
     return 0;
   }
   if (chestflag == 0) {
     write("It is already closed.");
     return 1;
   }
   tell_room(ETP,""+TP->QCN+" closes the chest on the dresser.\n",TP);
   tell_object(TP,"You close the chest on the dresser.\n");
   remove_item("chest");
   remove_item("wooden chest");
   add_item("chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the dresser.  Its "
"lid is currently closed.%^RESET%^");
   add_item("wooden chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the "
"dresser.  Its lid is currently closed.%^RESET%^");
   chestflag = 0;
   return 1;
}

int take_fun(string str) {
   if (!str) {
     notify_fail("Take what?");
     return 0;
   }
   if (str != "sigil" && str != "green sigil") {
     notify_fail("You can't take that.");
     return 0;
   }
   if (chestflag == 0 || sigilflag == 0) {
     notify_fail("You can't take that");
     return 0;
   }
   tell_room(ETP,""+TP->QCN+" takes a %^GREEN%^%^BOLD%^glowing sigil%^RESET%^ from the chest.\n",TP);
   tell_object(TP,"You take the %^GREEN%^%^BOLD%^glowing sigil%^RESET%^ from the chest.\n");
   remove_item("chest");
   remove_item("wooden chest");
   add_item("chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the dresser.  "
"Its lid is open, revealing an empty interior.%^RESET%^");
   add_item("wooden chest","%^ORANGE%^A small wooden chest is set directly upon the centre of the "
"dresser.  Its lid is open, revealing an empty interior.%^RESET%^");
   new(OBJ+"sigilgreen")->move(TP);
   sigilflag = 0;
   return 1;
}

int crystal_fun(string str) {
   if (!str) {
     notify_fail("Gazing into space doesn't reveal anything to you.");
     return 0;
   }
   if (str != "into globe" && str != "into crystal globe") {
     notify_fail("Gazing at that doesn't reveal anything to you.");
     return 0;
   }
   tell_room(ETP,"%^WHITE%^%^BOLD%^"+TP->QCN+" gazes deep into the crystal globe, "+TP->QP+" eyes "
"taking on a glassy sheen.%^RESET%^",TP);
   write(""+CRYSTALMSG[0]+"\n\n");
   TP->set_property("crystalmsg",1);
   call_out("domsg",1,TP);
   TP->setAdminBlock(1);
   return 1;
}

void domsg(object ob){
   int flag;
   flag = ob->query_property("crystalmsg");
   ob->remove_property("crystalmsg");
   if(flag < sizeof(CRYSTALMSG) && environment(ob) == TO){
     tell_object(ob,""+CRYSTALMSG[flag]+"\n\n");
     flag++;
     ob->set_property("crystalmsg",flag);
     ob->setAdminBlock(5);
     call_out("domsg",5,ob);
   }
   else {
     tell_object(ob,"%^CYAN%^You shake your head forcefully, pulling your gaze away from the crystal "
"ball to look around you.%^RESET%^\n\n");
     tell_room(environment(ob),""+ob->QCN+" shakes "+ob->QP+" head forcefully, pulling "+ob->QP+" gaze "
"away from the crystal ball and looking around.\n\n",ob);
   }
}

int mirror_fun(string str) {
   if (!str) {
     notify_fail("Step what?");
     return 0;
   }
   if (str != "into mirror" && str != "into the mirror" && str != "through the mirror" && str != "through mirror") {
     notify_fail("You can't do that.");
     return 0;
   }
   tell_room(ETP,""+TP->QCN+" steps right through the mirror and vanishes!",TP);
   tell_object(TP,"You step right through the mirror!");
   TP->move_player(ROOMS+"t3");
   return 1;
}

int mirror_fun2(string str) {
   if (!str) {
     notify_fail("Enter what?");
     return 0;
   }
   if (str != "mirror") {
     notify_fail("You can't do that.");
     return 0;
   }
   tell_room(ETP,""+TP->QCN+" steps right through the mirror and vanishes!",TP);
   tell_object(TP,"You step right through the mirror!");
   TP->move_player(ROOMS+"t3");
   return 1;
}

void set_string(string id, string which, string str) {
   if(!id) return;
   if(!which) return;
   if(!doors) return;
   if(!doors[id]) return;
   if (which == "open") {
     switch(random(3)) {
       case 0:
       str = "The door swings open silently.";
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

int mirrorlook(string str) {
   if (!str) {
     notify_fail("Look at what?");
     return 0;
   }
   if (str != "closer at mirror") {
     notify_fail("You do not notice that here.");
     return 0;
   }
   tell_room(ETP,""+TP->QCN+" inspects the mirror closely.",TP);
   tell_object(TP,"%^ORANGE%^You take a closer look in the mirror, and suddenly realise it's not even "
"reflecting you!  A touch of your hand reveals that the mirror is nothing more than an illusion - your "
"hand passes straight through it!%^RESET%^");
   return 1;
}