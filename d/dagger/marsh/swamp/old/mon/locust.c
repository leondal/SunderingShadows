#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit "/std/monster";
object owned;
void setup_locust(object owner); 
create() {
    ::create();
    set_name("locust");
    set("id", ({ "locust","giant locust" }));
    set("short", "%^RESET%^%^RED%^Giant locust%^RESET%^");
    set_hd(1,1);
    set("long", "This is a locust of sorrow and pestilence."
    );
    set_level(1);
    set_class("fighter");
    set_body_type("insect");
    set_alignment(5);
    set("race", "insect");
    set_ac(5);
    set_max_hp(6);
    set_hp(6);
    set_exp(0);
    call_out("removal",25);    
}
void setup_locust(object owner) {
    owned = owner;
}
void removal() {
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_room(ETO,"%^BOLD%^%^GREEN%^"
	"A giant locust flies away to ravage the lands!%^RESET%^"
    );
   if(!objectp(owned)) return;
    owned->add_exp(TO->query_exp());
    TO -> remove();
    return;
}
