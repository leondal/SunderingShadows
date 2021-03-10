// added ignore true_invis, random monsterweapon on armor & sword,
// attempt noted to fix bugginess *Styx* 9/8/02
// took out the offering that created god awful spam since the
// rooms are cleaning themselves now - Ares 09/04/05

#include <std.h>

inherit MONSTER;
void dest_mobs(object targ);

void create(){
    object ob;
    ::create();
    set_name("Spectral Paladin");
    set_id( ({"paladin", "spectre", "spectral paladin"}) );
    set_short("Spectral Paladin");
    set_long(
      "This paladin was once a great warrior who attacked the gates of the Crystal Tower of the Kinnesaruda.  In retribution for his attack, after his death Intruder raised the paladin and tried to turn him to his will.  The paladin's god felt remorse, and the paladin was freed from Intruder's control, but he still wanders the island, delusional from the pain of his undeath, attacking all that comes near him."
    );
    set_race("undead");
    set_body_type("human");
    set_gender("male");
    set_class("fighter");
    set_hd(29,2);
    set_mlevel("fighter", 29);
    set_property("full attacks", 1);
    set_mob_magic_resistance("low");;
    set_alignment(5);
    set("aggressive", 30);
    set_size(2);
    set_max_hp(250);
    set_hp(query_max_hp());
    ob = new("/d/attaya/obj/psword.c");
      if(random(3))  ob->set_property("monsterweapon",1);
      ob->move(TO);
    ob = new("/d/attaya/obj/uarmor.c");
      if(random(3))  ob->set_property("monsterweapon",1);
      ob->move(TO);
    command("wield sword");
    command("wearall");
    set_speed(35);
    set_moving(1);
}

void init(){
    string *str;
    int i;
    ::init();
    str = ETO->query_exits();
    if(!str || (str == ({ })) )  return;
    for(i=0;i<sizeof(str);i++)
      if(userp(TP) && !TP->query_true_invis())
        add_action("push", str[i]);

      if(TP->id("token monster")) { return; }
      if(TP->id("merc")) { return; }
//    if(TP->is_monster()) {  was this
// added to exclude its own type to stop bugs on desting each other
// moved to callout because otherwise dests before they get to move into room
   if(TP->is_monster() && (string)TP->query_name() != "Spectral Paladin")
       call_out("dest_mobs",1,TP);

/* since wasn't attacking normal invis, aggressive 30 should handle this
    if(!objectp(ETO))   return;
    if(!wizardp(TP) && !TP->query_true_invis())
      kill_ob(TP, 1);
*/
}

void dest_mobs(object targ) {
    if(!objectp(TO) || !objectp(targ))
	return;
    kill_ob(targ,0);
    targ->die();
//    command("offer corpse"); // don't need this since the rooms clean themselves now,
//    command("offerall");
}

int push(){
    tell_object(TP, "The Spectral Paladin pushes you back!");
    command("say EVIL!  Evil is everywhere!!  I MUST DESTROY YOU!!");
    return 1;
}
