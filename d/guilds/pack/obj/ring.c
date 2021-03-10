
#include <std.h>
inherit "/std/guild";

void create(){
    ::create();
    set_name("Signet Ring");
    set_id( ({"signet ring","ring","signet"}));
    set_short("%^BOLD%^Signet Ring");
    set_long(
@OLI
    This is the signet ring of the Illuminati. They wear it to
show to them selves who they are. Only they recognize the
difference between it and other signet rings.
OLI
 
    );
    set_weight(1);
    set_value(1);
    set_ac(1);
    set_leader("alister");
    set_guild_hc( ({"tyrion", "charr", "henso", "wrath", "alister"}) );
    set_guild_items( ({"/d/guilds/pack/obj/ring.c"}) );
    set_guild_home("/d/guilds/pack/hall/main.c");
    set_guild_name("Illuminati");
    set_type("ring");
    set_limbs(({"right hand"}));
    set_wear( (:TO, "wear_me":) );
    set_remove("As you slide the ring from your finger, you feel a longing to return it.");
}

void init(){
    guild::init();
    if (ETO==TP)
      TP->force_me("wear signet ring");
    else
      TO->remove();
}

int wear_me() {
    if( (string)TP->query_guild() != "Illuminati" ) {
      TO->remove();
      return 0;
    }
    tell_object(TP, "As you wear the ring, visions of ill gotten gains brings a smile to your face.");
    TP->force_me("smile halfway");
    return 1;

}



