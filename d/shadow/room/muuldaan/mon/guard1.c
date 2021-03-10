#include <std.h>
inherit MONSTER;

int rushOK;
object *atkrs;

void create() {
    int level;
    object ob;
    ::create();
    set_name("bugbear guard");
    set_id(({"guard","bugbear guard","muuldaan guard"}));
    set_short("bugbear guard");
    set_long("This is a large goblinoid creature known as a bugbear.  Its body is covered in hair, with dull yellow skin and dirty red hair.  It looks rather fierce and hungry, and is armed for a fight.");
    set_body_type("human");
    set_race("bugbear");
    set_gender("male");
    set_class("fighter");
    level = random(5)+10;
    set_guild_level("fighter",level);
    set_hd(level,10);
    set_exp(200);
    set_max_hp(100+random(75));
    set_hp(query_max_hp());
    set_overall_ac(1);
    set_property("swarm",1);
    set_alignment(9);
    set_size(3);
    set_stats("strength", random(4)+12);
    set_stats("constitution", random(9)+8);
    set_stats("wisdom", random(8)+9);
    set_stats("charisma", random(5)+9);
    set_stats("intelligence", random(7)+9);
    set_stats("dexterity", random(8)+11);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new("/d/common/obj/weapon/halberd")->move(TO);
    force_me("wield halberd");
    new("/d/common/obj/armour/leather")->move(TO);
    force_me("wear leather");
    rushOK = 1;
    set_spoken("undercommon");
}

heart_beat() {
    object ob;
    int x;
    ::heart_beat();
    if(!objectp(TO)) return;
    atkrs = TO->query_attackers();
    if(rushOK) doRush();
}

int doRush() {
    string atkrnames;
    int x;

    if(!rushOK) return 0;
    if(!(sizeof(atkrs))) return 1;
    for(x=0;x<sizeof(atkrs);x++) {
        force_me("rush "+atkrs[x]->query_name());
    }
    rushOK = 0;
    call_out("OkToRush", 60);
}

int OkToRush() {
    rushOK = 1;
    return rushOK;
}
