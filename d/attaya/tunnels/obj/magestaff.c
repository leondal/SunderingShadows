//Coded by Lujke
// This is a weapon usable only by sc mages (no multis/dual classers
// allowed). The weapon does next to no damage, but has a series of
// specials which cause the wielder to cast a variety of combat spells, or
// other effects when a hit is scored.
// Because it is used by sc mages only, a generous attack_bonus is given
// on wielding and removed again on unwielding. This is to allow the
// character a good chance to hit (ie cast a spell) each round
// The staff has charges, but can be recharged when they run out.
// The staff should hopefully not be overpowered against major mobs
// because it requires a 'hit roll' for most of the powers to work.
// However, it is designed to give sc mages a bit of a chance to wade
// through areas with lots of lesser mobs.

// Charges mechanics had been commented out due to component use
// overhaul, there is no plans to turn it back as this staff is
// largely just a status item 2019.11.08 Illy

#include <std.h>
#include <daemons.h>
inherit "/std/weapon";

#define ATTACK_BONUS 1

int chanting;
// The chanting flag is used to check whether the player is halfway
// through the 'earth_shake' special, and prevents further specials
// occurring until this one is finished. It is reset to 0 in the
// wield_staff() function, to prevent it getting stuck at 1 if a fight
// should end with the special halfway completed.

int charges;
void add_charges(string str);
int recharge(string str);
int wield_staff();
int unwield_staff();
int hit_stuff(object ob);
void earth_shake(object ob);
string help();
void explode();


void create(){
::create();
chanting = 0;
charges = 100 + random(100);
set_name("gnarled wooden staff");
set_id(({ "staff","magus staff", "wizard staff", "mage staff",
                           "gnarled staff", "gnarled wooden staff" }));
set_short("%^MAGENTA%^Magus staff%^RESET%^");
set_obvious_short("%^ORANGE%^Gnarled wooden staff%^RESET%^");
set_long("%^ORANGE%^A stout looking staff of %^RESET%^t%^BOLD%^%^BLACK%^w"
        +"%^RESET%^ist%^ORANGE%^e%^RESET%^d %^ORANGE%^and %^GREEN%^w"
        +"%^RESET%^a%^GREEN%^rp%^ORANGE%^e%^GREEN%^d %^RESET%^gray wood"
        +"%^ORANGE%^. It is about six feet in length and two or three"
        +" inches in diameter. The %^RESET%^wood t%^BOLD%^%^BLACK%^w"
        +"%^RESET%^i%^ORANGE%^s%^RESET%^ts %^ORANGE%^and %^GREEN%^w"
        +"%^BOLD%^%^GREEN%^e%^RESET%^a%^GREEN%^v%^ORANGE%^e%^GREEN%^s"
        +" %^ORANGE%^in on itself, giving it the appearance of two or"
        +" three pieces of %^RESET%^driftwood%^ORANGE%^ or %^GREEN%^tree"
        +" roots%^ORANGE%^ plaited together. The staff is rounded at the"
        +" end and a %^BOLD%^%^BLACK%^dark g%^RESET%^e%^BOLD%^%^BLACK%^m"
        +"%^RESET%^%^ORANGE%^ is nestled in between a couple of the"
        +" %^GREEN%^roots%^ORANGE%^, which seem to be holding it in"
        +" place.");

  set_type("bludgeoning");
  set_prof_type("staff");
//set_weight(20); //changed to 20 from 30, because as it is at present the max weight a sleeve can hold is 20 lbs - valas couldn't sheath this thing
  set_weight(10); //changed weight to 10 because most staves are 4 lbs, so this seemed extreme ~Circe~ 5/11/11
  set_value(3000);
  set_size(3);
  set_wc(2,2);
  set_large_wc(2,2);
  set_wield((:TO, "wield_staff":));
  set_unwield((:TO, "unwield_staff":));
  set_heart_beat(1);
  set_property("enchantment", 5);
  set_property("able to cast",1);
  set_item_bonus("empowered",ATTACK_BONUS);
  set_hit((:TO, "hit_stuff":));
  set_weapon_speed(1);
  set_language("common");
//  set_read("Those with the knowledge may %^BOLD%^%^RED%^recharge%^RESET%^"
//          +" this staff");
  set_lore("The %^MAGENTA%^staff of magus%^RESET%^ is a legendary weapon"
          +" said to have been owned by a number of arch-magi down the"
          +" ages. The staff is said to be able to store magical energy"
          +" and discharge it on its owner's behalf. However, it is only"
          +" as powerful as the hand that holds it and the mind that"
          +" guides it. It is also said to be a magical snob and very"
          +" fussy about who it talks to.\n\nThe %^BOLD%^%^BLACK%^g"
          +"%^RESET%^e%^BOLD%^%^BLACK%^m set at the heart of the staff is"
          +" said to have been the living heart of a devil, slain by the"
          +" arch-magus Asfero Loesris in his younger days when he was"
          +" more adventurer than scholar.");
  set_property("lore difficulty",21);
}

void init()
{
  ::init();
//  add_action("recharge", "recharge");
}

int recharge(string str)
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  if (str!="staff"&& str!="magus staff" && str !="mage staff"
       && str != "wizard staff" && str != "gnarled staff"
        && str != "gnarled wooden staff") {return 0;}

  if (!str)
  {
    return help();
  }
  if ((!ETO->is_class("mage") || !ETO->is_singleClass()) && !avatarp(ETO))
  {
    tell_object(ETO, "You wouldn't know where to begin recharging the"
                    +" staff");
    return 1;
  }

  if(ETO->query_bound())
  {
    write("You can't recharge the staff whilst bound.");
    return 1;
  }
  if (!EETO->is_lab())
  {
      write("You need the facilities of a laboratory to recharge the"
           +" staff.\n");
      return 1;
  }
  if (ETO->query_invis()&& !ETO->query_true_invis())
  {
    return notify_fail("You can not do this while in hiding.\n");
  }
  if((int)SAVE_D->is_member("enchant_restricted",TP->query_name()) != -1)
  {
        write("%^BOLD%^%^WHITE%^Your use of this ability has been "+
        "restricted for inappropriate use.%^RESET%^");
        return 1;
  }
  if (charges==200)
  {
    tell_object(ETO, "The staff is already fully charged with power.");
  }

  tell_object(ETO, "%^BOLD%^%^CYAN%^You carefully prepare the things in"
                  +" the laboratory that you will need to assist you in"
                  +" the process of %^RESET%^%^MAGENTA%^enchanting"
                  +" %^BOLD%^%^CYAN%^the staff\n");
  tell_object(ETO,"Please enter the number of charges that you want to"
                 +" add to the staff. This can be up to 50");
  tell_room(EETO, "%^BOLD%^%^CYAN%^" + ETO->QCN + "%^BOLD%^"
                 +"%^CYAN%^ begins moving around the laboratory,"
                 +" appearing to be preparing for some kind of %^RESET%^"
                 +"%^MAGENTA%^ritual",ETO);
  write("~q to quit");
  input_to("add_charges",0);
  return 1;
}

void add_charges(string str)
{
 int added_charges;
  string * diamond;
  object bag;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return;}
   added_charges = atoi(str);
  bag = present("compx",ETO);
  if(!objectp(bag))
  {
    write("You are not carrying your components bag.");
    return;
  }

  if ( added_charges < 10) {
      diamond = "small diamond";
  } else if ( added_charges> 25) {
      diamond = "diamond";
  } else {
      diamond = "large diamond";
  }

  if (bag->query_comp(diamond) < 1) {
      tell_object(ETO,"You need a "+diamond+" as a component to add that"
                     +" many charges to the staff");

      return;
  }
  bag->use_comp(diamond,1);
  charges +=  added_charges;
  if (random(charges)>150
      && random (200)> 140 + ETO->query_class_level("mage"))
  {
    explode();
    return;
  }
  if (charges > 200) {charges = 200;}
  tell_object(ETO, "%^ORANGE%^You complete a complex"
                  +" %^BOLD%^%^CYAN%^incantation %^RESET%^%^ORANGE%^and"
                  +" hold the %^BOLD%^%^WHITE%^" + diamond + " %^RESET%^"
                  +"%^ORANGE%^up on the palm of your hand. As your voice"
                  +"fades at the end of the %^BOLD%^%^CYAN%^chant"
                  +"%^RESET%^%^ORANGE%^, a %^BOLD%^%^BLUE%^b%^RESET%^"
                  +"%^CYAN%^l%^BOLD%^%^CYAN%^u%^BLUE%^e l%^i%^BLUE%^ght"
                  +"%^RESET%^%^ORANGE%^ builds slowly from the centre of"
                  +" the %^BOLD%^%^WHITE%^gem%^RESET%^%^ORANGE%^ and"
                  +" suddenly %^YELLOW%^b%^CYAN%^u%^YELLOW%^rsts%^RESET%^"
                  +" %^ORANGE%^forth, jumping from the diamond into the"
                  +" %^BOLD%^%^BLACK%^dark g%^RESET%^e%^BOLD%^%^BLACK%^m"
                  +" %^RESET%^%^ORANGE%^at the end of the%^MAGENTA%^"
                  +" staff%^ORANGE%^. When the light fades, the %^BOLD%^"
                  +"%^WHITE%^d%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^am"
                  +"%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^nd%^RESET%^"
                  +"%^ORANGE%^ is gone.");
  tell_room(EETO,"%^ORANGE%^" + ETO->QCN + "%^ORANGE%^"
                +"You completes a complex %^BOLD%^%^CYAN%^incantation"
                +" %^RESET%^%^ORANGE%^and holds up a %^BOLD%^%^WHITE%^"
                + diamond + " %^RESET%^%^ORANGE%^ on the palm of one hand"
                +". As the %^BOLD%^%^CYAN%^chant%^RESET%^%^ORANGE%^"
                +" reaches the end, a %^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^l"
                +"%^BOLD%^%^CYAN%^u%^BLUE%^e l%^i%^BLUE%^ght%^RESET%^"
                +"%^ORANGE%^ builds slowly from the centre of the"
                +" %^BOLD%^%^WHITE%^gem%^RESET%^%^ORANGE%^ and suddenly"
                +" %^YELLOW%^b%^CYAN%^u%^YELLOW%^rsts %^RESET%^%^ORANGE%^"
                +"forth, jumping from the diamond into the"
                +" %^BOLD%^%^BLACK%^dark g%^RESET%^e%^BOLD%^%^BLACK%^m at"
                +" the end of the %^MAGENTA%^staff%^ORANGE%^. When the"
                +" light fades, the %^BOLD%^%^WHITE%^d%^BOLD%^%^CYAN%^i"
                +"%^BOLD%^%^WHITE%^am%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^nd"
                +"%^RESET%^%^ORANGE%^ is gone.",ETO);
  return 1;
}

void explode()
{
  object env, *things;
  int hp, i;
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return;}
  if (!interactive(ETO)){ env = ETO;}
  else{ env = EETO;}
  things = all_living(env);
  if (sizeof(things)<1){return;}
  tell_object(ETO,"%^ORANGE%^As you finish %^BOLD%^%^CYAN%^chanting"
                 +"%^RESET%^%^ORANGE%^, you realise that you have lost"
                 +" control of the energies of the ritual! A %^YELLOW%^r"
                 +"%^RESET%^%^ORANGE%^ag%^YELLOW%^g%^RESET%^%^ORANGE%^e"
                 +"%^YELLOW%^d l%^RESET%^i%^YELLOW%^ght %^RESET%^"
                 +"%^ORANGE%^ bursts forth from the %^BOLD%^"
                 +"%^WHITE%^diamond %^RESET%^%^ORANGE%^ you are holding"
                 +" and jumps into the %^MAGENTA%^staff"
                 +"%^ORANGE%^, which %^RED%^explodes%^RESET%^%^ORANGE%^,"
                 +" sending sharp fragments of wood flying through the"
                 +" room like %^RESET%^shrapnel%^ORANGE%^!");
  tell_room(EETO, "%^ORANGE%^As " + ETO->QCN + "%^ORANGE%^"
                 +" finishes %^BOLD%^%^CYAN%^chanting%^RESET%^%^ORANGE%^,"
                 +" a %^YELLOW%^r%^RESET%^%^ORANGE%^ag%^YELLOW%^g"
                 +"%^RESET%^%^ORANGE%^e%^YELLOW%^d l%^RESET%^i"
                 +"%^YELLOW%^ght %^RESET%^%^ORANGE%^ bursts forth from a"
                 +" %^BOLD%^%^WHITE%^diamond %^RESET%^%^ORANGE%^ and"
                 +" jumps into the %^MAGENTA%^staff%^ORANGE%^, which"
                 +" %^RED%^explodes%^RESET%^%^ORANGE%^, sending sharp"
                 +" fragments of wood flying through the room like"
                 +" %^RESET%^shrapnel%^ORANGE%^!", ETO);
  for(i=0;i<sizeof(things);i++)
  {
    hp = (int)things[i]->query_max_hp()/5;
    things[i]->do_damage(things[i]->return_target_limb(),random(hp));
    things[i]->add_attacker(TO);
    things[i]->continue_attack();
    if(objectp(things[i]))    things[i]->remove_attacker(TO);

  }


}

string help()
{
  string help;

 if ((!ETO->is_class("mage") || !ETO->is_singleClass()) && !avatarp(ETO)) {return 0; }

  help = "From your general knowledge of magical affairs and all things"
        +" arcane, you realise that to enchant an item like this with"
        +" additional charges, you will need to be able to access the"
        +" facilities of a laboratory. You will also need to have some"
        +" diamonds available as components. The more charges you wish to"
        +" add to the staff, the more and larger the diamonds you will"
        +" need.\n";
  return help;
}
int wield_staff()
{
  if (!objectp(TO)||!objectp(ETO)){return 0;}
  if (TP->is_class("bard"))
  {
    tell_object(ETO,"The %^MAGENTA%^staff of magus%^RESET%^ squirms away"
                   +" from your hand");
    tell_object(ETO,"%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^staff of"
                   +" magus%^BOLD%^ %^RED%^tells you%^BOLD%^%^BLACK%^:"
                   +"%^RESET%^ Ack! I'm not working with you! I simply"
                   +" can't abide all that singing into battle. And I"
                   +" won't put up with poetry, either.");
    return 0;
  }
  if (TP->is_class("thief"))
  {
    tell_object(ETO,"The %^MAGENTA%^staff of magus%^RESET%^ squirms away"
                   +" from your hand");
    tell_object(ETO,"%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^staff of"
                   +" magus%^BOLD%^ %^RED%^tells you%^BOLD%^%^BLACK%^:"
                   +"%^RESET%^ Hey! What do you think you're doing? Get"
                   +" your hands off of me! Stop! Thief!");
    return 0;
  }
  if (TP->is_class("fighter")||TP->is_class("cavalier")
    ||TP->is_class("ranger")||TP->is_class("paladin")
    ||TP->is_class("antipaladin"))
  {
    tell_object(ETO,"The %^MAGENTA%^staff of magus%^RESET%^ squirms away"
                   +" from your hand");
    tell_object(ETO,"%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^staff of"
                   +" magus%^BOLD%^ %^RED%^tells you%^BOLD%^%^BLACK%^:"
                   +"%^RESET%^ Oh dear me, no! I couldn't possibly let"
                   +" you fight with me. I am quite sure you would be far"
                   +" too rough with me - swinging me this way, bashing"
                   +" things with me that way. Ugh. No, no, no. That"
                   +" would never do. Besides, you're all sweaty.");
    return 0;
  }
  if (TP->is_class("cleric"))
  {
    tell_object(ETO,"The %^MAGENTA%^staff of magus%^RESET%^ squirms away"
                   +" from your hand");
    tell_object(ETO,"%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^staff of"
                   +" magus%^BOLD%^ %^RED%^tells you%^BOLD%^%^BLACK%^:"
                   +"%^RESET%^ I'm sorry your holiness, but I could"
                   +" simply never work with someone as sanctimonious as"
                   +" you. I'm sure I am just not worthy");
    return 0;
  }

  if((int)TP->query_stats("intelligence") < 16)
  {
    tell_object(ETO,"The %^MAGENTA%^staff of magus%^RESET%^ squirms away"
                   +" from your hand");
    tell_object(ETO,"%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^staff of"
                   +" magus%^BOLD%^ %^RED%^tells you%^BOLD%^%^BLACK%^:"
                   +"%^RESET%^ I'm sorry, I just don't think we are made"
                   +" for each other. You're not terribly bright, so I"
                   +" really can't imagine the conversation would make"
                   +" it worth my while.");
    return 0;
  }
  if (TP->is_class("mage")==0)
  {
    tell_object(ETO,"The %^MAGENTA%^staff of magus%^RESET%^ squirms away"
                   +" from your hand");
    tell_object(ETO,"%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^staff of"
                   +" magus%^BOLD%^ %^RED%^tells you%^BOLD%^%^BLACK%^:"
                   +"%^RESET%^ Get your grubby hands off of me, you"
                   +" ignorant lump. You're no mage!");
    return 0;
  }
  tell_object(ETO,"You feel the %^CYAN%^flows of the weave%^RESET%^ wrap"
                 +" themselves around you like swaddling, as your hand"
                 +" closes round the %^MAGENTA%^staff of magus%^RESET%^");
  tell_object(ETO,"%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^staff of magus"
                 +"%^BOLD%^ %^RED%^tells you%^BOLD%^%^BLACK%^:%^RESET%^"
                 +" Ahh, greetings. I can tell from your mind that we"
                 +" will have much of interest to discuss");

  chanting = 0;
  return 1;
}

int unwield_staff(){
  if (!objectp(TO)||!objectp(ETO)){return 0;}
  tell_object(ETO, "The %^CYAN%^flows of the weave%^RESET%^ unwrap"
                  +" themselves from around you as you release the"
                  +" %^MAGENTA%^staff of magus");
  tell_room(EETO, ETO->QCN + "sighs as " + ETO->QS
                 + " releases " + ETO->QP + " grip on the staff.",ETO);
  return 1;
}

int hit_stuff(object ob)
{
  object wielder;
  object foe;
  int effect;
  int level;
  int i;
  if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
  if (chanting>0)
  {
    return 0;
  }
  wielder = ETO;

  //charges -=1;
  /* if (charges<1) */
  /* { */
  /*   tell_object(wielder, "%^BOLD%^%^RED%^Your %^RESET%^%^MAGENTA%^staff" */
  /*                       +" of the magus%^BOLD%^%^RED%^ is out of" */
  /*                       +" charges!"); */
  /*   return 0; */
  /* } */


  // NOTE: since MPEN depends on clevel.
  level = ETO->query_guild_level("mage");

  effect = random(9);
  switch(effect)
  {
  case 0:
    new("/cmds/spells/l/_lightning_bolt.c")->use_spell(ETO, ob, level, 100, "mage");
    return 0;
  case 1:
    new("/cmds/spells/f/_fireball.c")->use_spell(ETO, ob,level, 100, "mage");
    return 0;
  case 2:
    new("/cmds/spells/m/_magic_missile.c")->use_spell(ETO, ob,level, 100, "mage");
    return 0;
  case 3:
    new("/cmds/spells/m/_magic_missile.c")->use_spell(ETO, ob,level, 100, "mage");
    return 0;
  case 4:
    new("/cmds/spells/l/_lightning_bolt.c")->use_spell(ETO, ob,level, 100, "mage");
    return 0;
  case 5:
    if (sizeof(all_living(EETO))> 6)
    {
      new("/cmds/spells/c/_cone_of_cold.c")->use_spell(ETO, ob,level, 100, "mage");
      return 0;
    }
    new("/cmds/spells/h/_hold_person.c")->use_spell(ETO, ob,level, 100, "mage");
    return 0;
  case 6:
    new("/cmds/spells/f/_fireball.c")->use_spell(ETO, ob,level, 100, "mage");
    return 0;
  case 7:
    tell_object(wielder, "%^BOLD%^%^CYAN%^Twisting away from your foe,"
                        +" you whirl the %^RESET%^%^MAGENTA%^staff of"
                        +" magus%^BOLD%^%^CYAN%^ above your head then"
                        +" bring it around in a %^RESET%^%^MAGENTA%^great"
                        +" arc%^BOLD%^%^CYAN%^, sending a %^BLUE%^w"
                        +"%^RESET%^a%^BOLD%^%^BLUE%^ve of f%^RESET%^o"
                        +"%^BOLD%^%^BLUE%^rce %^CYAN%^out in front of"
                        +" you!");
    tell_room(EETO, "%^BOLD%^%^CYAN%^" + wielder->QCN
                    +"%^BOLD%^%^CYAN%^ twists away from the battle and"
                    +" whirls the %^RESET%^%^MAGENTA%^ staff of magus"
                    +"%^BOLD%^%^CYAN%^ above "
                    + wielder->QP +" head. Bringing it"
                    +" around in a %^RESET%^%^MAGENTA%^great arc"
                    +"%^BOLD%^%^CYAN%^, " + wielder->QS
                    +"%^BOLD%^%^CYAN%^, sends a %^BLUE%^w%^RESET%^a"
                    +"%^BOLD%^%^BLUE%^ve of f%^RESET%^o%^BOLD%^%^BLUE%^"
                    +"rce %^CYAN%^ out in front of "
                    + wielder->QO +"!", wielder);
    ob->set_stunned(random(4)+1);
    tell_object(ob, "%^BOLD%^%^GREEN%^You are blasted backwards off your"
                    +" feet!");
    tell_room(EETO, "%^BOLD%^%^GREEN%^" + ob->QCN+ "%^BOLD%^"
                   +"%^GREEN%^ is blasted backwards off "
                   + ob->query_possessive() +" feet!",ob);
    return 0;
  case 8:
    tell_object(wielder, "%^RED%^Holding the %^MAGENTA%^ staff of the"
                        +" magus %^RED%^aloft above your head, you feel"
                        +" the %^MAGENTA%^magic%^RED%^ flow in your veins"
                        +" as you chant %^GREEN%^e%^BOLD%^%^GREEN%^l"
                        +"%^BLACK%^d%^RESET%^%^GREEN%^r%^RESET%^i"
                        +"%^GREEN%^t%^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^"
                        +"h %^BOLD%^%^GREEN%^words %^RESET%^%^GREEN%^of"
                        +" %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^o%^BOLD%^"
                        +"%^GREEN%^w%^BLACK%^e%^RESET%^%^GREEN%^r");
    tell_room(EETO, "%^RED%^Holding the %^MAGENTA%^ staff of the magus"
                   +" %^RED%^aloft above " + wielder->query_possessive()
                   + " head," + wielder->QCN + " takes on a"
                   +" look of serenity and power as "
                   + wielder->QS + " chants%^GREEN%^"
                   + "e%^BOLD%^%^GREEN%^l%^BLACK%^d%^RESET%^%^GREEN%^r"
                   +"%^RESET%^i%^GREEN%^t%^BOLD%^%^GREEN%^c%^RESET%^"
                   +"%^GREEN%^h %^BOLD%^%^GREEN%^words %^RESET%^"
                   +"%^GREEN%^from the d%^BOLD%^%^GREEN%^a%^RESET%^"
                   +"%^GREEN%^wn o%^BOLD%^%^GREEN%^f t%^BLACK%^i%^RESET%^"
                   +"%^GREEN%^m%^BOLD%^e.",wielder);
    chanting = 1;
    call_out("earth_shake", 3, ob);
    return 0;
  }
  tell_object (ETO,"You're not making anything work! Please tell a Wiz"
                  +" there's an ERROR with your staff of magus!");
  return 0;
}

void earth_shake(object ob)
{
  int i;
  object wielder;
  object foe;
  wielder = ETO;
  if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
  if (sizeof(all_living(environment(ob)))<2){
    return 0;
  }
  tell_object(wielder, "%^YELLOW%^Completing your %^BOLD%^%^GREEN%^c"
                      +"%^RESET%^%^GREEN%^h%^RESET%^a%^BOLD%^%^GREEN%^n"
                      +"%^RESET%^%^GREEN%^t%^YELLOW%^ with a last few"
                      +" %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^a%^BOLD%^"
                      +"%^GREEN%^r-wr%^RESET%^e%^BOLD%^%^GREEN%^nch"
                      +"%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^ng s"
                      +"%^RESET%^y%^BOLD%^%^GREEN%^ll%^BOLD%^%^BLACK%^a"
                      +"%^BOLD%^%^GREEN%^bl%^RESET%^%^GREEN%^e%^BOLD%^"
                      +"%^GREEN%^s%^YELLOW%^, you slam the base of the"
                      +" %^MAGENTA%^staff of the magus%^RESET%^ onto the"
                      +" floor, sending %^BOLD%^%^CYAN%^shockwaves"
                      +"%^YELLOW%^ out in every direction!");
  tell_room(EETO, "%^YELLOW%^Completing " + wielder->query_possessive()
                + " %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^h%^RESET%^a"
                + "%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^t%^YELLOW%^ with a"
                + " last few %^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^a"
                + "%^BOLD%^%^GREEN%^r-wr%^RESET%^e%^BOLD%^%^GREEN%^nch"
                + "%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^ng s%^RESET%^y"
                + "%^BOLD%^%^GREEN%^ll%^BOLD%^%^BLACK%^a%^BOLD%^"
                + "%^GREEN%^bl%^RESET%^%^GREEN%^e%^BOLD%^%^GREEN%^s"
                + "%^YELLOW%^, " + wielder->QCN + " slams"
                + " the base of the %^RESET%^%^MAGENTA%^staff of the"
                + " magus%^YELLOW%^ onto the floor, sending %^BOLD%^"
                + "%^CYAN%^shockwaves%^YELLOW%^ out in every direction!"
                , wielder);
  for (i=0;i<sizeof(all_living(environment(ob)));i++)
  {
    foe = all_living(environment(ob))[i];
    if (foe != wielder && foe->query_true_invis()==0)
    {
      if (random(35+foe->query_level())<foe->query_stats("dexterity")+
                  foe->query_level()) {
        tell_object(foe, "%^BOLD%^%^BLUE%^You jump back nimbly and manage"
                        +" to keep your feet as the room shakes!");
        tell_room(EETO, "%^CYAN%^" + foe->QCN +" jumps back"
                        +" nimbly and mangages to stay upright!", foe);

      } else {
        foe->set_tripped(random(2));
        tell_object(foe, "%^BOLD%^%^RED%^You are tossed to the ground as"
                        +" the floor quakes beneath you!");
        tell_room(EETO, "%^BOLD%^%^GREEN%^" + foe->QCN
                      + "%^BOLD%^%^GREEN%^ is tossed to the ground!",foe);
      }
    }
  }
  chanting = 0;
}
void staff_say(object owner, string str){
  tell_object(owner, "%^BOLD%^%^RED%^The %^RESET%^%^MAGENTA%^magus staff"
                    +"%^BOLD%^%^RED%^ tells you%^BOLD%^%^BLACK%^:"
                    +"%^RESET%^" + str);
}

void heart_beat() {
  int i, j;
  object owner,env,obj,*inv;
  env = ETO;
  if(!objectp(ETO)){ return;}
  if(objectp(env) && living(env)) {
    owner = env;
    env = environment(owner);
  }

  if(!(TO->query_wielded())) { return;}
  else {
    i = random(700);
    j = random(19)+1;
    if(i > 0) { return;}
    switch (j){
    case 0:
      staff_say(owner,"Being a mage is more or less like being a"
                       +" warrior. Only without all the undignified sweat"
                       +" and grunting. Oh, and without the need to wear"
                       +" enough metal to melt your grey matter into a"
                       +" puddle of sludge that runs out of your ears and"
                       +" drips into your boots on hot days.");
       break;
     case 1:
       staff_say(owner,"There is more to being a wizard than muttering"
                        +" to yourself, wiggling your fingers and"
                        +" spending your evenings up to your elbows in"
                        +" bat guano. There is also the matter of"
                        +" choosing what sort of robe to wear.");
        break;
     case 2:
       staff_say(owner,"Have you ever wondered what people go around"
                      +" waving tatty bits of parchment at you for? As if"
                      +" you, a proper mage, would be buying scrolls from"
                      +" strangers! You never know what they might have"
                      +" been doing with them.");
        break;
      case 3:
        staff_say(owner,"All mages must be literate. The mage who does"
                       +" not read does not breathe.");
        break;
      case 4:
        staff_say(owner,"Wizardry and religion can be a little"
                       +" incompatible at times. It's hard to worship a"
                       +" God when you're intending to become as powerful"
                       +" as one yourself." );
        break;
      case 5:
        staff_say(owner,"What is important about Art Magic? Research,"
                       +" studying, and education, education, education."
                       +" Oh, and producing really BIG explosions.");
        break;
      case 6:
        staff_say(owner,"Mages should share their secrets about as"
                       +" readily as your average two year old shares his"
                       +" toys." );
        break;
      case 7:
        staff_say(owner,"Anyone who walks around clad in metal for the"
                       +" first fifty percent of their adventuring career"
                       +" has no right to call themselves a mage. The"
                       +" only magical thing about some of them is how"
                       +" fast they seem to be able to whip off their"
                       +" armour when a spell is required.");
        break;
      case 8:
        staff_say(owner,"Selling scrolls to strangers? Why would you want"
                       +" to help others acquire the knowledge that you"
                       +" sweated blood for? Especially when you don't"
                       +" know how they will use that power!");
        break;
      case 9:
        staff_say(owner,"The foundation of magic is science and the"
                       +" inspiration of magic is Art. The continuation"
                       +" of magic, though, is craft. Work hard at your"
                       +" skills and never cease your studies.");
        break;
      case 10:
        staff_say(owner,"Focus the force of your powers through the lens"
                       +" of your minds eye. Keep your magic pure and"
                       +" clean, regardless of your other entanglements."
                       +" Magic is magic. Use it and shape it to your"
                       +" will, but do not suffer others to treat the"
                       +" magic itself as good or evil, for it is"
                       +" neither.");
        break;
      case 11:
        staff_say(owner,"Focus the force of your powers through the lens"
                       +" of your minds eye. Keep your magic pure and"
                       +" clean, regardless of your other entanglements."
                       +" Magic is magic. Use it and shape it to your"
                       +" will, but do not suffer others to treat the"
                       +" magic itself as good or evil, for it is"
                       +" neither.");
        break;
      case 12:
        staff_say(owner,"Only pure bat guano is good enough for"
                       +" fireballs. Mix a few rat droppings in it to"
                       +" keep the costs down and you are in trouble.");
        break;
      case 13:
        staff_say(owner,"Only pure bat guano is good enough for"
                       +" fireballs. Mix a few rat droppings in it to"
                       +" keep the costs down and you are in trouble.");
        break;
      case 14:
        staff_say(owner,"An archmage I once knew warned against"
                       +" frivolously selling enchanted items. He pointed"
                       +" out that as his magic was the most powerful he"
                       +" knew, he certainly did not want to risk it"
                       +" being used against himself!");
        break;
      case 15:
        staff_say(owner,"Try to keep your elbows tucked in a bit more"
                       +" when you are casting. It will help you keep"
                       +" your shoulders back and your breathing more"
                       +" regular, which should help keep your mind clear"
                       +" and stop you forgetting important parts of the"
                       +" spell.");
        break;
      case 16:
        staff_say(owner,"Try to keep your elbows tucked in a bit more"
                       +" when you are casting. It will help you keep"
                       +" your shoulders back and your breathing more"
                       +" regular, which should help keep your mind clear"
                       +" and stop you forgetting important parts of the"
                       +" spell.");
        break;
      case 17:
        staff_say(owner,"Be careful about how many powerful spells you"
                       +" cast. There are those who watch the Weave and"
                       +" monitor what is going on within its strands."
                       +" Attaching the attention of Those Who Watch is"
                       +"not generally considered to be a good thing.");
        break;
      case 18:
        staff_say(owner,"The summoning spells can be particularly tricky"
                       +" at times. Do make sure you have also researched"
                       +" and practiced your abjuration spells, in case"
                       +" whatever you call up is not to happy to be"
                       +" there and needs sending back.");
        break;
      };
   }
}
