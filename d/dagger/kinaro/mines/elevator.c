#include <std.h>
#include "../defs.h"
inherit ROOM;

int do_moving(string direction, object player);
void move_elevator(string direction,int counter);
int remote_moving(string direction);

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   if(!random(4)) set_property("no teleport",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("A mining elevator");
   set_short("%^ORANGE%^A mining elevator%^RESET%^");
   set_long("%^ORANGE%^A mining elevator%^RESET%^\n"
"This %^BOLD%^%^BLACK%^metal contraption %^RESET%^is set within a straight "
"vertical shaft in the mining tunnels.  It consists of a cage of what appears "
"to be %^BOLD%^%^WHITE%^steel%^RESET%^, with a flat sheet to serve as a "
"floor, and bars around to protect its occupants.  A mesh door is set into "
"one side of the cage, with a %^ORANGE%^mechanical system %^RESET%^beside it "
"to open and close it.  More cogs and pulleys run the length of the shaft "
"beside the elevator, presumably to move it up and down.  It seems a little "
"%^BLUE%^old%^RESET%^, but quite sturdy and well-built.  A single %^BOLD%^"
"%^BLACK%^lever %^RESET%^stands near the mesh gates.\n");
   set_smell("default","The air carries a dry and dusty smell.");
   set_listen("default","The occasional sound of metal on stone reaches your ears.");
   set_items(([
     ({"cage","floor","bars","contraption","elevator"}):"The elevator "
"consists of a full cage of protective bars, made of what appears to be "
"%^BOLD%^%^WHITE%^steel%^RESET%^.  A flat sheet of the same metal serves as "
"the floor to this contraption.",
     ({"cogs","pulleys"}):"A series of cogs, gears and pulleys run the "
"length of the vertical shaft beside the elevator, presumably to move the "
"contraption up and down.",
     "lever":"A %^BOLD%^%^BLACK%^lever%^RESET%^ has been set into the wall, "
"a few feet back from the vertical shaft that leads downwards.  You could "
"probably %^YELLOW%^pull the lever up %^RESET%^or %^YELLOW%^down%^RESET%^.",
   ]));
   set_exits(([
     "out":MINES"shaft0",
   ]));
}

void init(){
   ::init();
   add_action("pull_fun","pull");
}

int pull_fun(string str){
   object mylift;
   if(!str) {
     notify_fail("What do you want to pull?\n");
     return 0;
   }
   if(str == "lever"){
     notify_fail("Do you want to pull it up or down?\n");
     return 0;
   }
   if(str == "lever up" || str == "the lever up") {
     TO->do_moving("up",TP);
     return 1;
   }
   if(str == "lever down" || str == "the lever down") {
     TO->do_moving("down",TP);
     return 1;
   }
   notify_fail("You can't pull that\n");
   return 0;
}

int do_moving(string direction, object player){
   string mydir;
   object myroom;
   if(!objectp(TO)) return 1;
   if(!objectp(player)) return 1;
   if(TO->query_property("moving")){
     tell_object(player,"%^ORANGE%^You pull the lever, but nothing happens, "
"perhaps because the elevator is already moving.%^RESET%^");
     tell_room(TO,"%^ORANGE%^"+player->QCN+" pulls the lever, but nothing "
"happens, perhaps because the elevator is already moving.%^RESET%^",player);
     return 1;
   }
   if(member_array("out",TO->query_exits()) != -1) {
     mydir = (string)TO->query_exit("out");
     if(direction == "down" && mydir == (MINES"lower1a")) {
       tell_object(player,"%^ORANGE%^You pull the lever down, but nothing "
"happens.%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+player->QCN+" pulls the lever down, but "
"nothing happens.%^RESET%^",player);
       return 1;
     }
     if(direction == "up" &&  mydir == (MINES"shaft0")) {
       tell_object(player,"%^ORANGE%^You pull the lever up, but nothing "
"happens.%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+player->QCN+" pulls the lever up, but "
"nothing happens.%^RESET%^",player);
       return 1;
     }
   }
   if(direction == "down") {
     tell_room(TO,"%^ORANGE%^"+player->QCN+" pulls the lever down, and the "
"cage doors rattle shut.  With a shudder, the whole cage starts moving down "
"the shaft!%^RESET%^",player);
     tell_object(player,"%^ORANGE%^You pull the lever down, and the cage "
"doors rattle shut.  With a shudder, the whole cage starts moving down the "
"shaft!%^RESET%^");
     if(member_array("out",TO->query_exits()) != -1) {
       TO->remove_exit("out");
       myroom = find_object_or_load(mydir);
       if(member_array("enter",myroom->query_exits()) != -1) {
         myroom->remove_exit("enter");
         tell_room(myroom,"%^ORANGE%^The cage doors rattle shut.  With a "
"shudder, the whole cage starts moving down the shaft!%^RESET%^");
       }
     }
     TO->set_property("moving",1);
     call_out("move_elevator",3,"down",1);
     return 1;
   }
   if(direction == "up") {
     tell_room(TO,"%^ORANGE%^"+player->QCN+" pulls the lever up, and the "
"cage doors rattle shut.  With a shudder, the whole cage starts moving up "
"the shaft!%^RESET%^",player);
     tell_object(player,"%^ORANGE%^You pull the lever up, and the cage "
"doors rattle shut.  With a shudder, the whole cage starts moving up the "
"shaft!%^RESET%^");
     if(member_array("out",TO->query_exits()) != -1) {
       TO->remove_exit("out");
       myroom = find_object_or_load(mydir);
       if(member_array("enter",myroom->query_exits()) != -1) {
         myroom->remove_exit("enter");
         tell_room(myroom,"%^ORANGE%^The cage doors rattle shut.  With a "
"shudder, the whole cage starts moving up the shaft!%^RESET%^");
       }
     }
     TO->set_property("moving",1);
     call_out("move_elevator",3,"up",1);
     return 1;
   }
   tell_object(player,"Oops, you broke something. Please contact a wiz!");
   return 1;
}

void move_elevator(string direction,int counter) {
   object myroom;
   if(!objectp(TO)) return;
   if(counter == 1) {
     tell_room(TO,"%^BOLD%^%^BLACK%^The cage rumbles as it moves "+direction+
" the shaft.%^RESET%^");
     myroom = find_object_or_load(MINES"shaft0");
     tell_room(myroom,"%^BOLD%^%^BLACK%^A low rumbling comes from the "
"vertical shaft.%^RESET%^");
     myroom = find_object_or_load(MINES"lower1a");
     tell_room(myroom,"%^BOLD%^%^BLACK%^A low rumbling comes from the "
"vertical shaft.%^RESET%^");
     call_out("move_elevator",3,direction,2);
     return;
   }
   if(direction == "up") {
     myroom = find_object_or_load(MINES"shaft0");
     TO->add_exit(MINES"shaft0","out");
     myroom->add_exit(MINES"elevator","enter");
     tell_room(TO,"%^BOLD%^%^BLACK%^The cage rumbles slowly to a halt as it "
"reaches the top of the shaft.  Its doors rattle open.%^RESET%^");
     tell_room(myroom,"%^BOLD%^%^BLACK%^A metal cage rumbles slowly up the "
"shaft and comes to a halt before you.  Its doors rattle open.%^RESET%^");
     if(TO->query_property("moving")) TO->remove_property("moving");
     return;
   }
   if(direction == "down") {
     myroom = find_object_or_load(MINES"lower1a");
     TO->add_exit(MINES"lower1a","out");
     myroom->add_exit(MINES"elevator","enter");
     tell_room(TO,"%^BOLD%^%^BLACK%^The cage rumbles slowly to a halt as it "
"reaches the bottom of the shaft.  Its doors rattle open.%^RESET%^");
     tell_room(myroom,"%^BOLD%^%^BLACK%^A metal cage rumbles slowly down the "
"shaft and comes to a halt before you.  Its doors rattle open.%^RESET%^");
     if(TO->query_property("moving")) TO->remove_property("moving");
     return;
   }
   tell_room(TO,"Uhoh, something's busted, contact a wiz!");
   return;
}

int remote_moving(string direction){
   call_out("move_elevator",3,direction,1);
}
