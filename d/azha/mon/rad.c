// Ellgarsh al-Radin
// Thorn@ShadowGate
// 970309
// Town of Azha
// alradin.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/azha/azha.h"

inherit MONSTER;

int flag;



void create()
{
  object ob;

  ::create();
  set_name("al-Radin");
  set_id( ({ "alradin","ellgarsh","al-radin","radin" }) );
  set_property("no steal", 1);
  set("race", "elf");
  set_gender("male");
  set("short", "Ellgarsh al-Radin");
  set_property("assassin", 1);
  set_long(
@AZHA
  This finely dressed elf is known as Ellgarsh al-Radin, son of
a important official in Sindh Province.  A notorious gambler
and rake, it is likely that this rogue's only possessions right
now are his fine clothes, and his weapons. Rumors have it that
al-Radin is the only thief to have ever relieved a hobbit
assassin of one his special daggers.  It has resulted in a
chase that has left him weary, and paranoid.  It is possible
that he could attack anyone who comes too near him.
AZHA
  );
  set_level(30);
  set_body_type("human");
  set_class("thief");
  set("aggressive", 0);
  set_alignment(5);
  set_size(2);
  set_hd(30, 8);
  set_stats("intelligence",15);
  set_stats("wisdom",11);
  set_stats("strength",15);
  set_stats("charisma",18);
  set_stats("dexterity",21);
  set_stats("constitution",17);
  set_max_mp(0);
  set_mp(query_max_mp());
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  add_money("silver",random(100));
  add_money("gold",random(60));
  add_money("copper",random(10));
  add_search_path("/cmds/thief");
  set_thief_skill("pick pockets", 95);
  set_thief_skill("hide in shadows", 95);
  set_thief_skill("move silently", 95);
  toggle_steal();
  ob=new("/d/tharis/obj/wrist_sheath");
  ob->move(TO);
  force_me("wear sheaths");
  ob=new("/d/azha/obj/crescent");
  ob->move(TO);
  force_me("wear crescent");
  flag = 0;
}

heart_beat() {
  object atkr,ob;

  ::heart_beat();
   if(!objectp(TO)) return;
  atkr = TO->query_current_attacker();
  if(!atkr) {
    flag = 0;
    if(ob=present("dagger", TO))
      if(!ob->remove()) destruct(ob);
    return;
  }
  if(present("powder", TO) && !(atkr->query_paralyzed()))
    TO->force_me("throw powder at "+atkr->query_name());
  else if(TO->query_hp() < 45)
    new("/d/tharis/obj/bpowder")->move(TO);
  if(flag) return;
  ob=new("/realms/grazzt/assassins/dagger");
  tell_room(environment(TO), "%^RED%^Ellgarsh turns to "+atkr->query_cap_name()+
  "%^RED%^ and screams something about hobbit assassins as he rips a cruel-looking"+
  "%^RED%^ dagger from a secret compartment in his clothing!");
  ob->move(TO);
  TO->force_me("wield dagger");
  flag = 1;
  TO->force_me("stab "+atkr->query_name());
}

init()
{
  ::init();
  add_action("xlook", "look");
  add_action("xsteal", "steal");
  add_action("xsteal", "pp");
  add_action("xstab", "stab");
  add_action("xrush", "rush");
}

int xlook(string str)
{
  object ob;
  if(flag) return 0;
  if(!str) return 0;
  if((member_array(str, query_id()) != -1) &&

  ((int)TP->query_level() > 15) &&
  ((int)TP->query_stats("charisma") < 16))
  {
    write("Excuse me, "+TPQCN+", I think you were looking at me...");
    write("I wonder why...");
    write("I hope you weren't planning to kill me.");
    write("%^BOLD%^I think I'll just make sure by KILLING YOU!!");
    ob=new("/d/common/assassins/obj/assassins_dagger.c");
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
    force_me("stab "+TPQN);
    return 0;
  }
  else if(member_array(str, query_id()) != -1)
  {
    write("Excuse me, "+TPQCN+", I think you were looking at me...");
    write("I would usually kill you, but you seem harmless enough.");
    write("Just don't even THINK of trying anything.\nOr else...");
    write("Al-Radin smiles.");
    write("You smile.");
    return 0;
  }

return 0;
}

int xstab(string str)
{
  object ob;

  if(flag) return 0;
  if(member_array(str, query_id()) != -1) {
    write(
@RAD
As you bare your weapon to stab Ellgarsh, he wheels around and
catches your hand!

He smiles for a second and says:

RAD
  );
    write("A good attempt "+TPQCN+", but now you die.");
    ob=new("/d/common/assassins/obj/assassins_dagger.c");
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
    force_me("stab "+TPQN);
    return 1;
  }
return 0;
}

int xrush(string str)
{
  object ob;

  if(flag) return 0;
  if(random(2)) return 0;
  if(member_array(str, query_id()) != -1) {
    write(
        "%^RED%^"+
        "As you break from the crowd to attack him, "+
        "al-Radin manages to catch a "+
        "glimpse of you.  He reaches into his cloak "+
        "and produces a small bag...%^RESET%^"
       );
    write("Damn you, "+TPQCN+"!  I won't be taken so easily!");
    ob=new("/d/tharis/obj/bpowder");
    ob->move(TO);
    TO->force_me("throw powder at "+TPQN);
    ob=new("/d/common/assassins/obj/assassins_dagger.c");
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
  force_me("stab "+TPQN);
  }
return 0;
}
int xsteal(string str)
{
  object ob;

  if(flag) return 0;
  if(!str) return 0;
  if(member_array(str, query_id()) != -1) {
    write(
@RAD
Ellgarsh exclaims:  Is there no honor among thieves?  I guess
not!  Oh well.  I assume you want my dagger, everyone else does.
So here, take it...

%^BOLD%^...IN THE BACK!!!%^RESET%^

RAD
  );
    ob=new("/realms/grazzt/assassins/dagger");
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
    force_me("stab "+TPQN);
    return 1;
  }
return 0;
}
