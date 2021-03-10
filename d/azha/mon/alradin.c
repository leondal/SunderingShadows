// Ellgarsh al-Radin
// Thorn@ShadowGate
// 970309
// Town of Azha
// alradin.c
//cleaned up code and made him fire gen- cyth 12/7

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
  set_race("fire genasi");
  set_gender("male");
  set("short", "Ellgarsh al-Radin");
  set_property("assassin", 1);
  set_property("no steal",1);
set_long("%^RESET%^%^RED%^With %^BOLD%^%^BLACK%^coal black%^RESET%^%^RED%^"+
" skin, and burning %^ORANGE%^orange%^RED%^ eyes, Ellgarsh al-Radin is"+
" undoubtable a fire genasi.  His lean features only serve to accentuate"+
" his alien looking appearance.  His %^BOLD%^crimson%^RESET%^%^RED%^"+
" colored hair has been stiffened into exaggerated spikes, making him seem"+
" even taller.  Dressed in a flamboyant style, his clothing is embroidered"+
" with metallic threads of %^ORANGE%^bronze%^RED%^ and %^YELLOW%^gold%^RESET%^"+
"%^RED%^.  Decked out in almost gaudy jewelry, Al-Radin looks the part more of"
" a rake than anyone who is a threat.");
set_hd(30, 8);
set_class("thief");
set_class("fighter");
set_class("assassin");
set_level(30);
set_mlevel("thief",30);
set_mlevel("fighter",30);
set_mlevel("assassin",30);
set_guild_level("thief",30);
set_guild_level("fighter",30);
set_guild_level("assassin",30);
  set_body_type("human");
  set("aggressive", 0);
  set_alignment(6);
  set_size(2);
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
  add_search_path("/cmds/fighter");
  add_search_path("/cmds/thief");
  add_search_path("/cmds/assassin");
  set_thief_skill("pick pockets", 95);
  set_thief_skill("hide in shadows", 95);
  set_thief_skill("move silently", 95);
  set_mob_magic_resistance("average");
  toggle_steal();
  set_scrambling(1);
  ob=new("/d/darkwood/tabor/obj/c_pantaloons.c");
  ob->set_property("enchantment",1);
  ob->move(TO);
 ob=new("/d/common/obj/armour/leather.c");
ob->set_short("%^YELLOW%^Gilded Leather Vest%^RESET%^");
 ob->set_obvious_short("%^YELLOW%^A gilded leather vest%^RESET%^");
 ob->set_long("%^BOLD%^%^BLACK%^Crafted out of %^RED%^red%^BLACK%^ leather,"
" this leather vest has been adorned with metallic threads of %^YELLOW%^gold"+
"%^RESET%^%^BOLD%^%^BLACK%^ and %^RESET%^%^ORANGE%^bronze%^BOLD%^%^BLACK%^.  "+
"The threads take on a %^RED%^flame%^BOLD%^%^BLACK%^ appearance, twisting and "+
"spiraling up the vest.  The vest is fashioned without any closers, meaning that"+
" it can never be fastened.  A high collar of %^YELLOW%^golden%^RESET%^"+
"%^BOLD%^%^BLACK%^ leather offers some protection to the wearer's neck.  Stitched "+
"into the golden leather are images of salamanders, fire drakes, red dragons, and "+
"fire serpents.%^RESET%^");
ob->add_id("vest");
  ob->set_property("enchantment",2);
  ob->move(TO);
  force_me("wear vest");
  force_me("wear pants");
 ob=new("/d/tharis/obj/wrist_sheath");
   ob->move(TO);
  force_me("wear sheaths");
  ob=new("/d/azha/obj/gmr_ring");
  ob->move(TO);
command("wear ring");
    ob = new("/d/tharis/obj/bpowder");
         ob->set_property("monsterweapon",1);
     ob->move(TO);
  flag = 0;
    set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes",
	  "blindfighting"
    }));
}

heart_beat() {
  object atkr,ob;

  if(!objectp(TO)) return;
  ::heart_beat();
  atkr = query_current_attacker();
  if(!atkr) {
    flag = 0;
    if(ob=present("dagger"))
      if(!ob->remove()) destruct(ob);
    return;
  }
 // if(present("powder", TO) && !(atkr->query_paralyzed()))
 //   TO->force_me("toss powder at "+atkr->query_name());
  if(flag) return;
  ob=new("/d/common/assassins/obj/assassins_dagger.c");
  ob->set_property("monsterweapon",1);
 tell_room(environment(TO), "%^RED%^Ellgarsh turns to "+atkr->query_cap_name()+
  "%^RED%^ and screams something about hobbit assassins as he rips a
cruel-looking"+
  "%^RED%^ dagger from a secret compartment in his clothing!");
  ob->move(TO);
  TO->force_me("wield dagger");
  flag = 1;
  TO->force_me("stab "+atkr->query_name());
  TO->force_me("crit "+TPQN);
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
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
    TO->force_me("stab "+TPQN);
	TO->force_me("crit "+TPQN);
    TO->force_me("toss powder at "+TPQN);
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
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
    TO->force_me("stab "+TPQN);
	TO->force_me("crit "+TPQN);
    TO->force_me("toss powder at "+TPQN);
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
    ob=new("/d/common/assassins/obj/assassins_dagger.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
  TO->force_me("stab "+TPQN);
  TO->force_me("crit "+TPQN);
  TO->force_me("toss powder at "+TPQN);
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
    ob=new("/d/common/assassins/obj/assassins_dagger.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    TO->force_me("wield dagger");
    flag = 1;
    TO->force_me("stab "+TPQN);
	TO->force_me("crit "+TPQN);
    TO->force_me("toss powder at "+TPQN);
    return 1;
  }
return 0;
}
