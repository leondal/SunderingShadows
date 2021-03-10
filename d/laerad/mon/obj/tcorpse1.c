//Coded by Bane//
#include <std.h>
inherit BAG;
void create(){
    ::create();
    set_id(({"corpse","troll corpse"}));
    set_name("corpse of troll");
    set_short("The corpse of Troll guard");
    set_long("The corpse of Troll guard.");
    set_weight(99999);
    call_out("animate",10,TO);
}
void animate(object targ){
    object ob;
    tell_room(ETO,"The corpse of troll rises from the ground.");
    new("/d/laerad/mon/troll2")->move(environment(targ));
    ::remove(ob);
    return 1;
}
