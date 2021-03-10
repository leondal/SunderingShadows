#include <std.h>
#include "graveyard.h"
inherit GRAVEYARD"tomb";

int shieldobj;

void create(){
   ::create();
   set_long((:TO,"ldesc":));
   set_smell("default","The air is musty and thick, and carries a foul smell.");
   set_listen("default","It is eerily quiet in here... a little too quiet.");
   add_item("shield",(:TO,"shielddesc":));
   set_exits(([
     "east":GRAVEYARD"tomb1",
     "south":GRAVEYARD"tomb4",
   ]));
}

void init() {
   ::init();
   add_action("take_fun","take");
}

string ldesc() {
   if(shieldobj) {
     return("%^BOLD%^%^BLACK%^Musty tomb%^RESET%^\n%^BLUE%^This small building appears to be a tomb of sorts.  "
"It seems to be very old, and has been untended for quite some time.  The crumbling stone%^BOLD%^%^BLACK%^ "
"walls %^RESET%^%^BLUE%^are coated in patches of %^GREEN%^moss %^BLUE%^and grime.  Off to the side are a few "
"%^ORANGE%^coffins %^BLUE%^that have been carelessly left on the floor.  Upon one of the walls is hanging an "
"old, dusty %^RESET%^%^WHITE%^shield%^BOLD%^%^BLACK%^.%^RESET%^\n");
   }
   else {
     return("%^BOLD%^%^BLACK%^Musty tomb%^RESET%^\n%^BLUE%^This small building appears to be a tomb of sorts.  "
"It seems to be very old, and has been untended for quite some time.  The crumbling stone%^BOLD%^%^BLACK%^ "
"walls %^RESET%^%^BLUE%^are coated in patches of %^GREEN%^moss %^BLUE%^and grime.  Off to the side are a few "
"%^ORANGE%^coffins %^BLUE%^that have been carelessly left on the floor.%^RESET%^\n");
   }
}

string shielddesc() {
   if(shieldobj) {
     return("%^ORANGE%^Hanging upon the wall is an old, dusty %^WHITE%^shield%^ORANGE%^.  You could probably "
"%^BLUE%^take%^ORANGE%^ it if you wanted to.%^RESET%^");
   }
   else { return("%^RESET%^You do not notice that here."); }
}

void reset() 
{
    ::reset();
    if(!shieldobj) 
    { 
        shieldobj = 1; 
        TO->add_item("shield", (:TO,"shielddesc":));
    }
}

int take_fun(string str) {
   if(!str) {
     notify_fail("What do you want to take?\n");
     return 0;
   }
   if(str != "shield") {
     notify_fail("That doesn't seem to be here.\n");
     return 0;
   }
   if(!shieldobj) {
     notify_fail("There doesn't seem to be a shield here for you to take.\n");
     return 0;
   }
   tell_object(TP,"%^ORANGE%^You reach up and take the shield off the wall.%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TP->QCN+" reaches up and takes the shield off the wall.%^RESET%^",TP);
   new(OBJ2"shield")->move(TP);
   TO->remove_item("shield");
   shieldobj = 0;
   return 1;
}
