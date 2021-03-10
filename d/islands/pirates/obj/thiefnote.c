#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_id(({"note","crumpled note"}));
   set_name("note");
   set_short("A crumpled note");
   set_long("This is a piece of paper, lined with creases.  A few lines of text are scrawled across it.");
   set_weight(0);
   set_value(0);
}

void init() {
   ::init();
   add_action("read_fun","read");
}

int read_fun(string str){
   if(! str) return notify_fail("Read what?");
   if(str != "note") return notify_fail("You can't read that!");
   if (TP->query_stats("intelligence")<10) return notify_fail("You can't make sense of the scrawled "
"writing.\n");
   tell_object(TP,"The cat is bagged at the flonder in the square\nWhere the bird chases the moon the cow "
"sits down\nLeaf hopping has to be the floor of the earth\nLife is short, vile stones make it worse\nMother "
"Hen collects the 50 bloomen raspberries\n\n");

   if (TP->is_class("thief") || TP->is_class("assassin")){
     tell_object(TP,"%^BLACK%^%^BOLD%^Roughly translated from thieves' cant, it means:%^RESET%^\n\nGo a few "
"paces north of the town square and go in the bushes, and down the grate, and to the south, and the guild "
"master will collect your guild fee of 50000 gold for the use of the facilities.");
   }
   else {
     tell_object(TP,"Whatever the hell that means.");
   }
   return 1;
}
