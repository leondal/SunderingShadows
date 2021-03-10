#include <std.h>;
inherit ROOM;

void create(){
   ::create();
   set_property("indoors", 1);
   set_property("light", 1);
   set_property("no teleport",1);
   set_smell("default", "The air smells strangely flat.");
   set_listen("default", "You can't hear anything.");
   set_short("%^BOLD%^%^WHITE%^Inside white void");
   set_long("%^BOLD%^You are floating in endless white void.");
}
