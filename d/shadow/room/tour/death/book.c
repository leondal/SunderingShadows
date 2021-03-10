#include <std.h>
 
inherit OBJECT;
 
void init(){
        ::init();
        add_action("read","read");
        }
 
void create() {
  ::create();
    set_name("book");
    set_id( ({ "book","journal" }) );
    set_short("An old book");
    set_long("This old book seems to be some "+
       "sort of journal.\n");
    set_weight(1);
    set_value(5);
    set_cointype("silver");
}
 
int read(string str){
  if (!str){
    notify_fail("Read What??");
    return 0;
  }
  if (str != "book") {
    notify_fail("You can not read that!");
    return 0;
  }
  else {
   write("Thiese are secrets!!");
   return 1;
  }

}

