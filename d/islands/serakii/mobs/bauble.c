//bauble summoned by weapon


#include <std.h>
inherit "/std/monster";


create() {
    ::create();
    set_name("bauble");
    set("id", ({ "bauble" }));
    set("short", "%^RESET%^%^BOLD%^a floating silver bauble%^RESET%^");
    set("long", "%^RESET%^%^BOLD%^This bauble is a glowing silver ball that "+
	"dances about. It is the size of a small rock and some magic must "+
	"be at play here.%^RESET%^");
    add_search_path("/cmds/mortal");
    set_stats("wisdom", 3);
    set_stats("strength", 3);
    set_stats("charisma", 25);
    set_stats("dexterity", 3);
    set_stats("constitution", 3);
    set_hd(2,1);
    set_level(1);
    set_class("theif");
    set_body_type("humanoid");
    set_alignment(5);
    set("race", "bauble");
    set_exp(0);
    set_gender("female");
    set_ac(1);
    set_max_hp(60);
    set_hp(60);
    if(clonep(TO)) call_out("remove",40);

}

int remove() {
    if(!objectp(TO) || !objectp(ETO)) return ::remove();
    tell_room(ETO,""+
          "The bauble shatters!");
    return ::remove();
}

void die(object ob){
remove();
}
