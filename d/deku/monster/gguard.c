//lowered exp from 900 to 300 They aren't much of a challenge - Styx 7/21/01

#include <std.h>

inherit "/std/monster";
void create() {
    ::create();
        set_name("guard");
        set_id( ({ "guard"  }) );
        set("race", "human");
        set_gender("male");
        set("short","%^BOLD%^%^GREEN%^V%^RESET%^%^GREEN%^erbobone %^BOLD%^%^WHITE%^G%^BLACK%^a%^WHITE%^t%^BLACK%^e %^WHITE%^g%^BLACK%^u%^WHITE%^a%^BLACK%^r%^WHITE%^d%^RESET%^");
        set("long","This guard stands pretty idly at the entrance gates to "
           "the Town of Verbobone. His chainmail seems recently polished "
           "but to a dull lustre, not a shine. He seems to be more "
           "concerned with watching who comes and goes than actually guarding "
           "the town for some reason.");
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
        set_hd(15,8);
        set_stats("intelligence",6);
        set_stats("wisdom",4);
        set_stats("strength",13);
        set_stats("charisma",3);
        set_stats("dexterity",8);
        set_stats("constitution",7);
        set_max_hp(query_hp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/common/obj/weapon/longsword")->move(TO);
        command("wield longsword");
        new("/d/deku/armours/chain")->move(TO);
        command("wear chainmail");
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
       set_exp(300);
} 
