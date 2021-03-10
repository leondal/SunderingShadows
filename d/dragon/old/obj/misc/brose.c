#include <std.h>
inherit OBJECT;
void create(){
    ::create();
    set_id(({"rose"}));
    set_name("black rose");
    set_short("A beautiful black rose");
  set_long("This is an exotic black rose.  The orgin of this wonderful \n"+
             "flower is unknown.  It is known to possess many powers.");
    set_weight(1);
    set_value(10);
}
void init(){
    ::init();
    add_action("smell", "smell");
}
int smell(string str){
    string temp;
    if(str != "rose") return 0;
    write("The rose smells like that of death and of life.  The feeling of life\n"+
            "comes back to you, as you breath the fragrance from the exotic flower.");
    this_player()->do_damage("torso", -(random(5)));
    remove();
    return 1;
}
