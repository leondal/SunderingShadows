//Black dragon claws
//Origionally Created: 12-26-95
 
#include <std.h>
 
inherit WEAPON;
 
void create() {
  ::create();
  set_name("dragon claw");
  set("id",({"dragon claws","dragon claw","claw","claws"}));
  set("short","dragon claws");
  set("long",
"These are huge hideous dragon claws that are glowing slightly");
  set_type("piercing");
  set_weight(60);
  set("value",100);
  set_size(3);
  set_wield("The claws begin glowing as you wield them");
  set_unwield("The claws dim as you unwield them.");
  add_poisoning(10);
}
//eof
