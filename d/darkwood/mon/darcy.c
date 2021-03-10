#include <std.h>
#include "/d/darkwood/darcy/darcy.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("Lord d'Arcy");
    set_id(({"darcy","marquis","lord krink", "lord", "krink" }));
    set_short("Lord Krink, the Marquis d'Arcy");
    set_long(
@DARKWOOD
  Lord Krink is one of the heroes of the Old Days of Shadow, having
lead the armies of the gods against the terrifying power of the two
evil immortal Archlords of Shadow: Kai the Despot and Belphy the
Foolish.  His skill is legendary and his name is enscribed on the
monument in Shadow, a lasting testiment to his service to the
realms.

  Now, evil has come again to the ancient City and a risen
Archlord has returned and disturbed his rest.  The Marquis has now
been driven out of his Chateau by combined forces of Aloysius and
Lord Kai, who now leads the Death's Head Legion to reclaim his
place.

  If you are brave enough and strong enough, you can enter the
Chateau and fight the minions of the evil powers.  If you are even
braver, you can <talk to the marquis> and he will give you a
dangerous quest, perhaps even to face Aloysius or Kai themselves. 
Consider carefully.
DARKWOOD
    );
    set_gender("male");
    set_hd(45,6);
    set_size(3);
    set_overall_ac(-16);
    set_class("antipaladin");
    set_guild_level("fighter",29);
    set_guild_level("paladin",29);
    set_max_hp(600);
    set_hp(600);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_race("fallen immortal");
    set_property("swarm",1);
    set("aggressive", 23);
    set_property("no_bump",1);
    set_stats("dexterity",22);
    set_stats("constitution",17);
    set_stats("strength",24);
    set_mob_magic_resistance("average");
    set_alignment(9);
    set_exp(55000);
    set_emotes(5,({
        "%^BOLD%^Lord Krink sings an old war song!",
        "Lord Krink looks at you thoughtfully, and nods to himself.",
        "%^MAGENTA%^Lord Krink says:%^RESET%^ Kai the Despot has returned, I will stop him.",
        "%^MAGENTA%^Lord Krink says:%^RESET%^ This reminds me of the bad old days.",
    }),0);
    ob=new("/d/attaya/obj/karmor.c");
    ob->set_property("monsterweapon",1);
    ob->set_short("Armor of Kryyyshk");
    ob->move(this_object());
    command("wear armor");
    ob=new("/d/attaya/obj/shoulderplate.c");
    ob->set_short("White Shoulderplates");
    ob->set_property("monsterweapon",1);
    ob->move(this_object());
    command("wear shoulderplates");
    ob = new("/d/shadow/obj/weapon/longsword");
    ob->set_id(({"guerrin","sword", "sword of Kryyyshk"}));
    ob->set_name("Guerrin");
    ob->set_short("Guerrin, Sword of Kryyyshk");
    ob->set_long("Guerrin is the golden blade forged by the Archlord Kryyyshk in the ancient "+
        "days before he was driven out by the evil Lord Kai.  Lord Krink wielded it in the "+
        "his duel against Kai during the great overthrow of the evil Archlords."
        );
    ob->set_property("enchantment",5);
    if(random(40) < 39) ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield guerrin in left hand");
    ob = new("/d/shadow/obj/weapon/longsword");
    ob->set_id(({"sword","blade", "knights blade", "knights"}));
    ob->set_name("Knight's Blade");
    ob->set_short("Knight's Blade");
    ob->set_long("The Knight's Blade is the original holy weapon given to the Lord "+
        "Krink when the gods sent him to depose the evil Archlords Kai and Belphy."+
        "It is said that this blade performs miracles for those who use it against evil."
        );
    ob->set_property("enchantment",3);
    if(random(40) < 39) ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield blade in right hand");
}

void die(object ob) {
    message("environment",
     "%^BOLD%^%^GREEN%^Lord Krink's spirit departs for its just reward in the heavens."
    ,environment(TO));
    force_me("bow");
    :: die(ob);
}

void heart_beat(){
   ::heart_beat();
  if(!objectp(TO)) return;
  if((TO->query_hp()+1) > TO->query_max_hp())
    TO->set_hp(TO->query_max_hp());
  else TO->add_hp(1);
}

