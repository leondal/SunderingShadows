#include <std.h>

inherit OBJECT;

int eats;
int set_eats(int i);

void create() {
    ::create();
    set_id( ({ "food","pile","pile of food" }) );
    set_name("food");
    set_short("A pile of food");
    set_long("A pile of food. Looks like it is edible.");
    set_weight(100000);
    set("value", 0);
    set_eats(random(20));
     set_property("no animate",1);
   }

void init(){
    ::init();
	add_action("eat_some","eat");
}

int set_eats(int i) {
   if ( i < 5  ) i = 5;
   if ( i > 20 ) i = 20;
   eats = i;
   eats *= 3;
   return 1; }

int eat_some(string str){
    if((!str) || (str != "food from pile"))
	return notify_fail("Syntax: <eat food from pile>\n");
    else
        if(!TP->add_stuffed(50)) return notify_fail("You are already stuffed!\n");
    write("You take a large portion from the pile and eat it.");
    write("This stuff is pretty nasty tasting, but it is filling.");
    eats --;
    if(eats < 1) remove();
    return 1;

}
