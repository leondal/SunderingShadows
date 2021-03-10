#include <std.h>
#include "/d/shadow/room/goblin/short.h"
inherit "/std/monster";
 
create() {
    ::create();
    set_name("rabbit");
    set("id", ({ "rabbit" }));
    set("short", "a small rabbit");
    set_hd(1,1);
    set("long", "This is a cute little rabbit with a mean temper."
    );
    set_level(1);
    set_class("fighter");
    set_body_type("humanoid");
    set_alignment(5);
    set("race", "rabbit");
    set_exp(0);
   set_gender("female");
    set_ac(9);
    set_max_hp(6);
    set_hp(6);
    if(clonep(TO)) call_out("remove",20);
}

int remove() {
    if(!objectp(TO) || !objectp(ETO)) return ::remove();
    //tell_room(ETO,"The rabbit has returned to the creator's arm.");
    tell_room(ETO,"The rabbit has returned to Garrett's arm.");
    return ::remove();
}
