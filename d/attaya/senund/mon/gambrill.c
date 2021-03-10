#include <std.h>
#include "../areadefs.h"
inherit MONSTER;
void create() {
    object ob;
    ::create();
    set_name("gambrill");
    set_id(({"gambrill"}));
    set_short("%^CYAN%^Gambrill%^RESET%^");
    set_long(
@BRUENOR
    %^CYAN%^Gambrill stands before you.  He is a man of about six feet in height
    %^CYAN%^with shaggy brown hair. He has not shaven in a few days and looks
    %^CYAN%^a bit worn as does the emerald dagger he holds in his left hand.
    %^CYAN%^Both him and his dagger are covered in dirt, grime, and blood.
    %^CYAN%^He does not look very impressed by your presence.
BRUENOR
);
    set_race("human");
    set_gender("male");
    set_hd(39,10);
    set_class("fighter");
    set_class("assassin");
    add_search_path("/cmds/fighter");
    add_search_path("/cmds/assassin");
    set_property("full attacks",1);
    set_size(2);
    set_mlevel("fighter",39);
    set_overall_ac(-10);
    set_max_hp(1330);
    set_hp(1330);
    set_exp(115000);
    add_money("gold",random(15000)+30000);
    set("aggressive","aggfunc");
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("no bump",1);
    set_stats("strength",19);
    set_stats("dexterity",16);
    set_stats("constitution",15);
    set_stats("intelligence",16);
    set_stats("wisdom",12);
    set_stats("charisma",10);
    set_mob_magic_resistance("average");
    set_alignment(9);
    set_funcs(({"stun"}));
    set_func_chance(30);
    set_stabbed_func((:TO,"stab":));
    set_skill("small blades", 200);
    new(OBJ+"emdagger.c")->move(TO);
command("wield dagger");
    ob = new("/d/islands/tonerra/obj/powergem.c");
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    new(OBJ+"old_key")->move(TO);
    ob = new("/d/attaya/obj/screamer.c");
    ob->set_property("monsterweapon",1);
    ob->set_property("enchantment", 2);
    ob->move(TO);
command("wield dagger");

    ob = new("/d/common/obj/potion/healing");
    ob->move(TO);
    ob->set_uses(50);
    set_property("not random monster", 1);

}

void stab()
{

  int i,j;
  object *att;
  if(!objectp(TO)) return;
  if(!objectp(ETO)) return;
  if(objectp(TP)) TP->set_disabled(5);
  tell_room(ETO, "Gambrill flinches at the pain but recovers quickly!");
  tell_room(ETO, "%^GREEN%^Gambrill spins around slashing with his%^BOLD%^ "+
                 "emerald%^RESET%^%^GREEN%^ dagger.");


    if((att=(object *)TO->query_attackers()) !=({}))
    {
        j=sizeof(att);
        for(i=0;i<j;i++)
        {
         call_out("force_me",1,"rush "+att[i]->query_name());
        }
    }

  tell_room(ETO, "Gambrill seems slightly more invigorated");
  if(query_hp()<0) set_hp(700);
}


int kill_ob(object victim, int which)
{
    int i,j, hold;
    object *att;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    hold = ::kill_ob(victim, which);
    if(hold)
    {
        if(interactive(victim))
        {
          TO->force_me("say I get back from a job and I find my guild "+
               "running around in chaos chasing down some intruders! "+
               "I am really not in the mood to piss off Elseroad. He "+
               "is quite a pain to deal with when he is bothered and "+
               "me and my crew's part of this deal is to provide security "+
               "in exchange for being able to stay here!!");
    if((att=(object *)TO->query_attackers()) !=({}))
    {
        j=sizeof(att);
        for(i=0;i<j;i++)
        {
         call_out("force_me",1,"rush "+att[i]->query_name());
        }
    }

        if(!random(5))
          {
          TO->force_me("crit "+victim->query_name());
          }
        }
        }
   return hold;
}


void aggfunc()
{
        if((string)TPQCN != "bruenor")
        {
        command("say I hope you carry a good bit of money, I'm not "+
                "getting paid this time....");
        command("rush "+TPQN);
        command("parry");
        }
}

void heart_beat(){

     int count;
     ::heart_beat();
    if(!objectp(TO)){ return;}
      if(present("kit",TO) && query_hp() < query_max_hp()/2)
      {
        for(count = 0;count < 20;count++)
        {
           force_me("open kit");
           force_me("quaff vial");
           force_me("offer bottle");
        }
      }
    return;
}

void die(object ob)
{
    tell_room(ETO,"%^RED%^Gambrill falls over %^BOLD%^bleeding%^RESET%^%^RED%^ "+
              "to death as he clutches his wounds.");
    tell_room(ETO, "%^MAGENTA%^Gambrill mumbles%^RESET%^: You all are good. "+
              "I underestimated.....");
    tell_room(ETO, "Gambrill falls over dead.");
    ::die(ob);
}
void stun(object targ)
{
        command("say You really think you can win against me?");
        TO->force_me("crit "+targ->query_name());
        tell_object(targ,
          "%^BOLD%^%^GREEN%^Gambril leaps forward and stabs "+
          "his daggers into each of your shoulders!"
                );
        tell_room(ETO,
                "%^BOLD%^%^GREEN%^Gambrill leaps towards "
                +targ->query_cap_name()+
                "%^BOLD%^%^GREEN%^ and stabs his daggers into "
                +targ->query_cap_name()+
             "'s shoulders!",targ);
    targ->do_damage("torso",roll_dice(4,6));
//    targ->set_paralyzed(random(20)+15,"%^RED%^Your shoulder is "+
    targ->set_paralyzed(roll_dice(4,6),"%^RED%^Your shoulder is "+ // same as shieldbash
    "throbbing with pain!");
    return 1;
}
