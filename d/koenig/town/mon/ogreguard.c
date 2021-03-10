#include <std.h>
inherit MONSTER;

void create() 
{
  ::create();
  set_name("ogre guard");
  set_id( ({"ogre", "guard", "ogre guard"}) );
  set_short("%^RESET%^%^ORANGE%^An Ugly Ogre Guard%^RESET%^");
  set_long("As you look this guy over, you come to agree with your nose... This guy needs a bath and BADLY! He also looks dumb as a post. He is wearing mangy furs about the majority of his body and bits and pieces of armor from previous victims he has slain. You also notice that attached to his belt are a few heads of said victims.");
  set_race("ogre");
  set_gender("male");
  set_alignment(9);
  set_body_type("human");
  set_hd(10,1);
  set_new_exp(12, "normal");
  set_stats("strength", 18);
  set_stats("constitution", 16);
  set_stats("dexterity", 12);
  set_stats("wisdom", 8);
  set_stats("intelligence", 8);
  set_stats("charisma", 2);
  set_size(3);
  set_max_hp(88);
  set_hp(88);
  set_overall_ac(5);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  new("/d/koenig/town/mon/weapons/giantclub.c")->move(this_object());
  command("wield club in left hand");
}

void init()
{
  ::init();
    add_action("kill","kill");
}

int kill(string str) {
    if(!str != "gentleman") return 0;
    write("The ogre blocks your malicious attempt at harming his boss.");
    say("The ogre moves to block "+TPQCN+" from doing harm to the Gentleman.");
    return 1;
}
