#include <std.h>

inherit OBJECT;

void create() {
   ::create();
   set_name("long box");
   set_id( ({"box","long","long box"}) );
   set("short","Long box");
     set("long","This box looks weird. It is totally black in color and "
      "made of wood. It looks very heavy. Having two odd openings of about "
       "a foot long at either end.");
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
}

void init() {
   ::init();
   add_action("insert_func","insert");
}

int insert_func(string str) {
   string what,where;
   object obj;
   if(!str) return notify_fail("You want to insert something into what?\n");
   if(sscanf(str,"%s into %s",what,where) != 2)
      return notify_fail("Maybe insert something into the box?\n");
   if(member_array(where,query_id()) == -1)
       return notify_fail("Maybe insert something into the box?\n");
   if(obj = present(what,TP)) {
      if(member_array("firedoom staff",obj->query_id()) == -1)
         return notify_fail("That thing can't fit into the box.\n");
      else {
         tell_object(TP,"You insert the firedoom staff into the box.");
         tell_room(ETP,TPQCN+" inserts a staff into the box.",TP);
         tell_room(ETP,"The staff comes out from the other opening and "
            "appears to be different in size!");
         obj->set_size(random(3)+2);
      }
   }
   return 1;
}
