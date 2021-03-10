//Hijacked March 31, 2011 by Ergo for Squire's Trial
#include <std.h>
#include "../squires_trial.h"
inherit ROOM;

int active;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",0);
   set_property("no teleport",1);
   set_terrain(NAT_CAVE);
   set_travel(DIRT_ROAD);
   set_name("Prison of ShadowFlame (Squire's Trial)");
   set_short( "%^BOLD%^%^BLACK%^Prison of Sh%^RESET%^%^BLUE%^ad" +
              "%^BOLD%^%^BLACK%^owF%^RESET%^%^BLUE%^l" +
              "%^BOLD%^%^BLACK%^a%^BLUE%^m%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^");
   set_long(  "%^BOLD%^%^BLACK%^This is a prison of Sh%^RESET%^%^BLUE%^ad" +
              "%^BOLD%^%^BLACK%^owF%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a" +
              "%^RESET%^%^BLUE%^m%^BOLD%^%^BLACK%^e.  It seems as if it's a" +
              " small pocket of some dimension that may even be artificial." +
              "  Frequent tongues of %^RESET%^%^BLUE%^blue %^BOLD%^%^BLACK%^" +
              "f%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^m" +
              "%^BOLD%^%^BLACK%^e swirl and spark at random, casting eerie " +
              "shadows in all directions." +
              "\n%^BOLD%^%^WHITE%^An ivory portal frame stands here.");
   add_item(({"frame","portal"}),"%^BOLD%^%^WHITE%^This is an ornate portal " +
              "frame, which is currently lifeless.  The carvings are " +
              "delicate, and swirling.%^RESET%^%^WHITE%^");
   active = 0;
   
}


int portal_active(){
  if(active) return 0;
  set_long(  "%^BOLD%^%^BLACK%^This is a prison of Sh%^RESET%^%^BLUE%^ad" +
              "%^BOLD%^%^BLACK%^owF%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a" +
              "%^RESET%^%^BLUE%^m%^BOLD%^%^BLACK%^e.  It seems as if it's a" +
              " small pocket of some dimension that may even be artificial." +
              "  Frequent tongues of %^RESET%^%^BLUE%^blue %^BOLD%^%^BLACK%^" +
              "f%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^m" +
              "%^BOLD%^%^BLACK%^e swirl and spark at random, casting eerie " +
              "shadows in all directions.\n" +
              "%^BOLD%^%^WHITE%^An ivory portal %^YELLOW%^glows brightly %^WHITE%^here.");
  add_item(({"frame","portal"}),"%^BOLD%^%^WHITE%^This is an ornate portal " +
              "frame, glowing with white energy.%^RESET%^%^WHITE%^");
  add_exit(CAVES+"cave10","portal");
  active = 1;
  return 1;
}

int portal_inactive(){
  
  if(!active) return 0;
  
  set_long(  "%^BOLD%^%^BLACK%^This is a prison of Sh%^RESET%^%^BLUE%^ad" +
              "%^BOLD%^%^BLACK%^owF%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a" +
              "%^RESET%^%^BLUE%^m%^BOLD%^%^BLACK%^e.  It seems as if it's a" +
              " small pocket of some dimension that may even be artificial." +
              "  Frequent tongues of %^RESET%^%^BLUE%^blue %^BOLD%^%^BLACK%^" +
              "f%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^m" +
              "%^BOLD%^%^BLACK%^e swirl and spark at random, casting eerie " +
              "shadows in all directions." +
              "\n%^BOLD%^%^WHITE%^An ivory portal frame stands here.");

  add_item(({"frame","portal"}),"%^BOLD%^%^WHITE%^This is an ornate portal " +
              "frame, which is currently lifeless.  The carvings are " +
              "delicate, and swirling.%^RESET%^%^WHITE%^" );
  
  remove_exit("portal");
  active = 0;
  return 1;
}       

void reset(){
  ::reset();
  portal_inactive();
  if(!present("shadow"))
   find_object_or_load(SQUIREMOBS"shadowmonster")->move(TO);
}
