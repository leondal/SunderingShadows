// Imperial Foot Soldier of Tsarven
// Thorn@ShadowGate
// 6/1/00
// Tsarvani Imperial Army
// impsoldier.c

#include <std.h>

inherit MONSTER;

create() {
        int level;
        object ob;
        ::create();
        set_name("soldier");
        set_id(({ "soldier", "guard", "tsarvani", "impsoldier", "foot soldier" }));
        set_short("Imperial Elite Trooper");
	set_race("human");
	set_body_type("human");
        set_long(
@TSARVEN
  This is a member of the Tsarvani Imperial Army.  Soldiers of the
Imperial Army are well-trained, well-equipped and numerous.  They
fight to protect the Empire and to promote the causes of justice
that the Empire seeks to promote.
TSARVEN
        );
        set_class("fighter");
        level = random(8)+1;
        set_level(level);
	set_alignment(1);
	set_size(2);
        set_stats("strength", random(4)+10);
        set_stats("constitution", random(9)+8);
        set_stats("wisdom", random(5)+7);
        set_stats("charisma", random(7)+8);
        set_stats("intelligence", random(7)+9);
        set_stats("dexterity", random(8)+9);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_hd(level,1);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        switch(random(2)+1) {
                case 1:
                new("/d/azha/equip/ipike.c")->move(TO);
                command("wield pike in right hand and left hand");
		break;
                case 2:
                new("/d/azha/equip/iscimitar.c")->move(TO);
                command("wield sword in right hand");
                new("/d/azha/equip/ishield.c")->move(TO);
                command("wear shield");
		break;
        }
        new("/d/azha/equip/iarmor.c")->move(TO);
        command("wear armor");
        new("/d/azha/equip/ihelm.c")->move(TO);
        command("wear helm");
}
