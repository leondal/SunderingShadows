//updated by Circe 6/1/04 with new desc, lore, etc by Shar
#include <std.h>
inherit "/d/common/obj/weapon/scourge";
create() {
    ::create();
    set_name("whip");
    set_id(({"whip","goblin whip","whip of shards"}));
//    set_obvious_short("bullwhip");
//    set_short("%^BLUE%^Goblin whip%^RESET%^");
    set_short("%^BOLD%^%^BLUE%^Whip of Shards%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^Sections of tough leather have been "+
       "braided to create this whip.   The long lash is affixed to "+
       "a %^RED%^rusty%^BLUE%^ metal handle.  Braided into the whip "+
       "you can see glittering shards, most of them being %^BLACK%^"+
       "obsidian%^BLUE%^ and various %^WHITE%^crystals%^BLUE%^, "+
       "providing a deadly bite to this whip.%^RESET%^"
    );
//    set_weight(7);
    set_value(15);
//    set_wc(1,4);
//    set_large_wc(1,6);
//    set_size(1);
//    set_type("bludgeoning");
//    set_prof_type("whip");
    set_wield((: TO,"extra_wield" :));
    set_hit((: TO,"extra_hit" :));
    set_lore("The Whip of Shards, it is said, the goblins "+
       "first learned how to make by observing the priestesses "+
       "of Loviatar in the creation of their whips.  The crude "+
       "goblins found they could use crystals and rocks to get "+
       "a similar effect, with an uncanny (and unique) brilliance.");
    set_property("lore difficulty",6);
}
int extra_wield() {
    tell_object(ETO,"%^BLUE%^You get the urge to lash out with "+
       "the Whip of Shards.%^RESET%^");
    tell_room(EETO,"%^BLUE%^"+ETOQCN+" starts looking at your "+
       "flesh in a twisted manner.%^RESET%^",ETO);
    return 1;
}

int extra_hit(object ob) {
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if(random(6) > 1) return 1;
    tell_object(ETO,"%^BLUE%^You lash a deep clean slash mark into "+
       ""+vic->QCN+"'s flesh!%^RESET%^");
    tell_room(EETO,"%^BLUE%^"+ETOQCN+" lashes a deep clean slash "+
       "mark into "+vic->QCN+"'s flesh!%^RESET%^",(({ETO, vic})));
    tell_object(vic,"%^BLUE%^"+ETOQCN+" lashes a deep clean slash "+
       "mark into your flesh!%^RESET%^");
    dam = random((int)ETO->query_stats("strength"))+3;
    dam = dam/3;
    if(dam < 1) dam = 1;
/*    if(random(10000) < 1) {
	write("%^BOLD%^%^BLUE%^"
	    "You feel the wrath of the gods being channeled into "
	    "the whip as you strike your foe!%^RESET%^"
        );
        dam = 200;
    } 
This is a little extreme considering the area.  Circe 6/1/04
*/
    return dam;
}
