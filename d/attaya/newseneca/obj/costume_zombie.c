//costume_zombie.c - zombie costume for new Seneca
//~Circe~ 12/28/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("zombie costume");
   set_id(({"costume","zombie costume","Zombie Costume","tattered zombie costume"}));
   set_short("%^BOLD%^%^BLACK%^tattered %^RESET%^zombie "+
      "%^BOLD%^%^BLACK%^costume%^RESET%^");
   set_long("The %^BOLD%^%^BLACK%^robe %^RESET%^that makes up "+
      "this costume has been heavily "+
      "attacked by a pair of scissors and features many rips and "+
      "tears.  The holes in the %^BOLD%^%^BLACK%^robe %^RESET%^"+
      "have %^BOLD%^p%^RESET%^a%^RED%^t%^BOLD%^%^BLACK%^c%^RESET%^"+
      "h%^BOLD%^e%^RESET%^%^RED%^s %^RESET%^sewn in from behind "+
      "that make it appear as though you are seeing %^RED%^rotting "+
      "flesh %^RESET%^and %^BOLD%^bones%^RESET%^ peeking through.  "+
      "%^ORANGE%^Rusted chains %^RESET%^made of lightweight "+
      "metal crisscross the wearer, forming a belt around the "+
      "waist.  A grizzled %^BOLD%^%^BLACK%^w%^RESET%^i%^BOLD%^"+
      "%^BLACK%^g %^RESET%^and a small compact of make up have "+
      "been provided to complete the look.");
   set_costume_type("%^BOLD%^%^BLACK%^tattered zombie");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}