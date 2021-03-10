//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit "/realms/lujke/tecqumin/mons/hunt_mon.c";

nosave int BEAT, heartcount;

void create()
{
      object ob;
      ::create();
  	set_name("Orchevid");
  	set_id(({"orchevid","plant","orchid", "orchid like plant",
               "large plant",}));
  	set_short("%^RESET%^%^GREEN%^large, %^MAGENTA%^o%^BOLD%^"
               +"%^MAGENTA%^r%^RESET%^%^MAGENTA%^ch%^BOLD%^%^BLACK%^i"
               +"%^RESET%^%^MAGENTA%^d%^RESET%^%^GREEN%^ like plant");
  	set_race("plant");
    set_fake_limbs(({"stem", "root", "flower head",
      "stamen", "aerial root", 
      "left forearm", "right forearm"}));
      set_property("not random monster", 1);
    set_attack_limbs(({"mandibles", "left forearm", "right forearm"}));
    set("aggressive", 0);
      set_new_exp(55, "normal");

        set_gender("neuter");
  	set_long("%^GREEN%^A large %^BOLD%^%^GREEN%^plant%^RESET%^%^GREEN%^"
              +", reaching nine to ten feet in height. Its broad,"
              +" %^BOLD%^%^GREEN%^w%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^xy"
              +" %^RESET%^%^GREEN%^leaves sit beneath a delicate looking"
              +" bell-shaped %^MAGENTA%^fl%^BOLD%^%^MAGENTA%^o%^RESET%^"
              +"%^MAGENTA%^wer h%^ORANGE%^e%^MAGENTA%^ad%^GREEN%^, with"
              +" distinct %^BOLD%^%^MAGENTA%^stamen%^RESET%^%^GREEN%^."
              +" Trailing roots spread out across the ground around it,"
              +" and several aerial roots descnd from just beneath the"
              +" flower head to soak up the moisture of the %^BOLD%^"
              +"%^GREEN%^humid %^RESET%^%^GREEN%^air" );

    set_attacks_num(7);
    set_damage(4,9);
    set_base_damage_type("piercing");
    set_fake_limbs(({"stalk", "root", "head",
      "aerial root", "aerial root", 
      "lower stalk", "root"}));
    set_attack_limbs(({"aerial root", "aerial root", "maw"}));

	set_class("fighter");
	set_mlevel("fighter",52);
	level = 52;
	set_guild_level("fighter",52);
   	set_hp(3000);
	set_max_level(49);
	set_property("swarm",1);
      set_alignment(7);
  	set_overall_ac(-71);
      set_size(3);
      add_attack_bonus(71); 
      set_property("magic",1);
      set_monster_feats(({
        "damage resistance",
        "daze",
    })); 
      set_stats("strength",30);
      set_stats("intelligence",10);
      set_stats("dexterity",16);
      set_stats("charisma",6);
      set_stats("wisdom",20);




  	set_size(3);
  	set("aggressive",30);
      add_attack_bonus(68); 
      set_skill("perception", 70);
	set_level(70);
 	set_nogo(({ JUNG_ROOM4 + "city_jung14", JUNG_ROOM5 + "j_link9", JUNG_ROOM9 + "j_link9a"}));
	set_max_level(60);
	set_property("swarm",1);
  	set_overall_ac(-68);
      set_funcs(({"blind", "mute", "bite"}));
      set_func_chance(33);
  	set_alignment(4);
      set_property("full attacks",1);
//      set_spell_chance(5);
  	set_emotes(2,({
           "The pretty %^MAGENTA%^orch%^BOLD%^%^MAGENTA%^e%^RESET%^"
          +"%^MAGENTA%^vid%^RESET%^ plant shivers slightly with the"
          +" breeze.",
            "The flower head of the tall %^MAGENTA%^orch%^BOLD%^"
          +"%^MAGENTA%^e%^RESET%^%^MAGENTA%^vid%^RESET%^%^GREEN%^"
          +" plant%^RESET%^ dips down and sways from left to right.",
            ""
 
    	}),0);
  	set_emotes(10,({
           "The %^MAGENTA%^orch%^BOLD%^%^MAGENTA%^e%^RESET%^"
          +"%^MAGENTA%^vid%^RESET%^ lashes out with its aerial roots",
    	}),1);
      set_property("no random treasure", 1);
      BEAT = 0;
      heartcount = 0;
      check_my_heart();
      set_speed(2);
 

}

void heart_beat(){
  object * critters;
  int i, count;
  ::heart_beat();
  critters = query_attackers();
  count = sizeof(critters);
  if (count>0){
    for (i=0;i<count;i++){
      if (interactive(critters[i])){
        if (member_array(critters[i]->query_name(), quarry)==-1);
          set_prey(critters[i]->query_name());
      }
    }
  }
  if (objectp(ETO) && present("player", ETO)){
    heartcount = 0;
  }
}

void check_my_heart()
{
    if (heartcount>300){
      return;
    }
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}

void bite2(object targ){
  string limb;
  if (!objectp(ETO) || !objectp(targ) || !present(targ, ETO)){
    tell_room(ETO,  "%^GREEN%^The %^BOLD%^%^WHITE%^t%^RESET%^ee"
      +"%^BOLD%^%^WHITE%^th %^RESET%^%^GREEN%^of the"
      +" %^MAGENTA%^fl%^BOLD%^o%^RESET%^%^MAGENTA%^wer"
      +" h%^ORANGE%^e%^MAGENTA%^ad%^GREEN%^ snap shut on thin air.");  
    return;
  }
  limb = targ->return_target_limb();
  if (!targ->reflex_save(55)){
    tell_object(targ, "%^GREEN%^The %^MAGENTA%^fl%^BOLD%^o%^RESET%^"
      +"%^MAGENTA%^wer h%^ORANGE%^e%^MAGENTA%^ad%^GREEN%^ snaps shut,"
      +" biting a chunk out of your " + limb);
  tell_room(ETO,  "%^GREEN%^The %^MAGENTA%^fl%^BOLD%^o%^RESET%^"
    +"%^MAGENTA%^wer h%^ORANGE%^e%^MAGENTA%^ad%^GREEN%^ snaps shut,"
    +" biting a chunk out of " + targ->QCN + "'s " + limb, targ);  
  }  
  targ->do_damage(250+random(300));
}

void bite(object targ){
  tell_room(ETO, "%^GREEN%^The %^BLUE%^bell shaped %^MAGENTA%^fl"
    +"%^BOLD%^o%^RESET%^%^MAGENTA%^wer h%^ORANGE%^e%^MAGENTA%^ad"
    +"%^GREEN%^ suddenly opens wide, revealing rows of%^CYAN%^"
    +" frighteningly%^BOLD%^ sharp %^BOLD%^%^WHITE%^t%^RESET%^"
    +"ee%^BOLD%^%^WHITE%^th %^RESET%^%^GREEN%^inside.");
  call_out("bite2", 1, targ);
}

void blind(object targ){
  tell_object(targ, "The %^MAGENTA%^orch%^BOLD%^%^MAGENTA%^e%^RESET%^"
    +"%^MAGENTA%^vid%^RESET%^ strikes you in the face with a"
    +" %^MAGENTA%^strange %^BLUE%^pad%^RESET%^ at the end of one of"
     +"%^its %^ORANGE%^aerial roots%^RESET%^.");
  tell_room(ETO,  "The %^MAGENTA%^orch%^BOLD%^%^MAGENTA%^e%^RESET%^"
    +"%^MAGENTA%^vid%^RESET%^ strikes "+targ->QCN+"%^RESET%^ in the"
    +" face with a %^MAGENTA%^strange %^BLUE%^pad%^RESET%^ at the end"
    +" of one of%^its %^ORANGE%^aerial roots%^RESET%^.", targ);  
  if (!targ->fort_save(55)){
    tell_object(targ, "%^RED%^Your eyes %^BOLD%^burn%^RESET%^%^RED%^"
      +" with %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^o%^BOLD%^i%^RESET%^"
      +"%^GREEN%^s%^BOLD%^%^YELLOW%^o%^GREEN%^n%^RESET%^%^RED%^ and"
      +" you can't see!");
    if (!targ->fort_save(55)){
      tell_object(targ, "The %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^o"
        +"%^BOLD%^i%^RESET%^%^GREEN%^s%^BOLD%^%^YELLOW%^o%^GREEN%^n"
        +"%^RESET%^%^RED%^ %^BOLD%^%^RED%^burns %^RESET%^painfully,"
        +" and you fear you are suffering permanent damage");
      targ->set_blind(100);
    } else {
      targ->set_temporary_blinded(100);
    }
  }
}

void mute(object targ){
  tell_object(targ, "The %^MAGENTA%^orch%^BOLD%^%^MAGENTA%^e%^RESET%^"
    +"%^MAGENTA%^vid%^RESET%^ strikes you on the side of the cheek with a"
    +" %^MAGENTA%^strange %^BLUE%^pad%^RESET%^ at the end of one of"
     +"%^its %^ORANGE%^aerial roots%^RESET%^.");
  tell_room(ETO,  "The %^MAGENTA%^orch%^BOLD%^%^MAGENTA%^e%^RESET%^"
    +"%^MAGENTA%^vid%^RESET%^ strikes "+targ->QCN+"%^RESET%^ on the side"
    +" of the cheek with a %^MAGENTA%^strange %^BLUE%^pad%^RESET%^ at the"
    +" end of one of%^its %^ORANGE%^aerial roots%^RESET%^.", targ);  
  if (!targ->fort_save(55)){
    tell_object(targ, "%^RED%^Your jaw stiffens, and your tongue goes"
      +" numb as %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^o%^BOLD%^i%^RESET%^"
      +"%^GREEN%^s%^BOLD%^%^YELLOW%^o%^GREEN%^n%^RESET%^%^RED%^"
      +" seeps into your system! ");
    targ->set_gagged(2000);
    targ->set_gagged_message("You can't speak because your jaw is locked"
      +" and your tongue is numb from the poison");
  }
}
