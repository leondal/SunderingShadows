#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("invisible feather maker");
}

void init(){
   string ldesc;
   ::init();
   ETO->set("long","%^BOLD%^%^RED%^"+capitalize(TP->QS)+" is covered in blood and feathers.");
   call_out("remove_me",1);
}

void remove_me(){
   TO->remove();
}