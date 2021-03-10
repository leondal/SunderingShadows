//Ogre.c

#include <std.h>

inherit MONSTER;

void create(){
    object ob;
    ::create();

    set_name("ogre mage");
    set_id(({"ogre","ogre mage","mage","Ogre"}));
    set_short("Ogre mage");
    set_long( (: TO, "ldesc" :) );
    set_hd(10,8);
    set_hp(80);
    set_exp(1200);
    set_race("ogre mage");
    set_body_type("ogre-mage");
    set_size(3);
    set_gender("male");
    set_stats("intelligence",18);
    set_stats("strength",19);
    set_stats("wisdom",19);
    set_stats("constitution",18);
    set_stats("wisdom",6);
    set_stats("charisma",1);
    set_guild_level("mage",10);
    set_spells(({"fireball","scorcher","lightning bolt","cone of cold","magic missile"}));
    set_property("swarm",1);
      set_property("alignment adjustment",3);
    set_mob_magic_resistance("average");
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(2);
    ob = new("/d/tharis/obj/katana");
      if(random(5)) ob->set_property("monsterweapon", 1);
      ob->move(TO);
    command("wield katana");
    set_spell_chance(50);
    set_alignment(3);
}

string ldesc(string str) {
   return("This sharply cut creature is quite impressive.  A bluish brown "
     "skin is streched tightly across his sharp face.  You realize that "
     "just as the elven rangers have come to help in the battle these "
     "creatures have come much farther to join the the evil side.");
}
