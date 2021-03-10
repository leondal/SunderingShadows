#include <std.h>
inherit "/std/guild";

void create(){
    ::create();
    set_name("Ebony Mask");
    set_id( ({"hand mask","mask","ebony mask"}));
    set_short("Ebony Mask");
    set_long(
    "This strangely crafted mask looks to be made to fit your face exactly.  You can sense an evil power emeniating from it as a strange black glow darkens the world around it."
    );
    set_weight(1);
    set_value(1);
    set_ac(1);
    set_leader("gal");
    set_guild_hc( ({"gal","alister", "bralock", "tyrion", "lanfear"}) );
    set_guild_items( ({"/d/guilds/pack/obj/mask.c"}) );
    set_guild_home("/d/guilds/pack/hall/main.c");
    set_guild_name("Crimson Hand");
    set_type("ring");
    set_limbs(({"right hand"}));
    set_wear( (:TO, "wear_me":) );
    set_remove("as you slide the mask from your face, you feel your face return to normal");
}

void init(){
    guild::init();
    if (ETO==TP)
      TP->force_me("wear mask");
    else
      TO->remove();
}

int wear_me() {
    if( (string)TP->query_guild() != "Crimson Hand" ) {
      TO->remove();
      return 0;
    }
    tell_object(TP, "As you don the mask, your face contorts under it into an eternal snarl!");
    return 1;
}
