//rebirther object for use with the rebirth spell to 
//give players the option of coming back or not
//The included files are the ones included in user.c
//Likely not all of them are necessary, but better safe 
//than sorry :) ~Circe~ 5/19/08
#include <config.h>
#include <dieties.h>
#include <rooms.h>
#include <security.h>
#include <daemons.h>
#include <move.h>
#include <objects.h>
#include <money.h>
#include <flags.h>
#include <user.h>
#include <dirs.h>
#include <council.h>
#include <clock.h>
#include <std.h>
inherit OBJECT;

void do_rebirth();
void do_death();
object reborn;
string reztype;

void create(){
   set_name("rebirther999");
   set_id(({"rebirther999"}));
   set_short(0);
   set_invis();
   set_property("no detect",1);
}

int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

void set_invis() {
  if (TO->query_invis())
    return;
  else ::set_invis();
  return;
}

void init(){
   ::init();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   reborn = ETO;
   reborn->set_hp(1);
   if(!stringp(reztype) || reztype != "foresight") {
     tell_object(reborn,"%^BOLD%^%^RED%^You have died while under the "+
      "effects of a rebirth spell.  Would you like to be reborn?%^RESET%^");
   }
   else {
     tell_object(reborn,"%^BOLD%^%^RED%^The world seems to slow down as you see the "+
      "fatal blow coming that would end your life.  Do you step aside?%^RESET%^");
   }
   tell_object(reborn,"%^BOLD%^WHITE%^y%^RED%^es or %^WHITE%^n%^RED%^o?%^RESET%^");
   input_to("pref");
}

void pref(string str) {
   if(!str){
      if(!stringp(reztype) || reztype != "foresight") {
         tell_object(reborn,"%^BOLD%^If you would like to be reborn, please type "+
         "%^RED%^yes %^WHITE%^or simply %^RED%^y%^WHITE%^.%^RESET%^");
      }
      else {
         tell_object(reborn,"%^BOLD%^If you step aside from the blow, please type "+
         "%^RED%^yes %^WHITE%^or simply %^RED%^y%^WHITE%^.%^RESET%^");
      }
      tell_object(reborn,"%^BOLD%^Otherwise, type %^RED%^no%^WHITE%^ or simply "+
         "%^RED%^n%^WHITE%^.%^RESET%^");
      input_to("pref");
      return;
   }
   if(str == "yes" || str == "y" || str == "Yes" || str == "Y"){
      do_rebirth();
      return;
   }else if(str == "no" || str == "n" || str == "No" || str == "N"){
      do_death();
      return;
   }else{
      if(!stringp(reztype) || reztype != "foresight") {
        tell_object(reborn,"%^BOLD%^If you would like to be reborn, please type "+
         "%^RED%^yes %^WHITE%^or simply %^RED%^y%^WHITE%^.%^RESET%^");
      }
      else {
         tell_object(reborn,"%^BOLD%^If you step aside from the blow, please type "+
         "%^RED%^yes %^WHITE%^or simply %^RED%^y%^WHITE%^.%^RESET%^");
      }
      tell_object(reborn,"%^BOLD%^Otherwise, type %^RED%^no%^WHITE%^ or simply "+
         "%^RED%^n%^WHITE%^.%^RESET%^");
      input_to("pref");
      return;
   }
}

void do_rebirth()
{
    object reborn, myob;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    reborn = ETO;
    if((int)reborn->query_class_level(reborn->query_class()) > 1 && !wizardp(reborn) && (int)"/daemon/config_d.c"->check_config("death") == 0)
    {
        reborn->remove_XP_tax("death");
        if(!reborn->query_diety() || (string)reborn->query_diety() == "pan")
        {
            reborn->resetLevelForExp(-((int)reborn->query_exp()*8/100));
        }
        else
        {
//         tell_object(reborn,"Your deity is "+(string)reborn->query_diety()+".");
            reborn->resetLevelForExp(-((int)reborn->query_exp()*5/100));
        }
    }
    //forgoing exp penalty when reborn - at least for now - Saide - November 2016 (just comment the following code in to enable it)
    /*if((int)reborn->query_class_level(reborn->query_class()) > 1 && !wizardp(reborn) && (int)"/daemon/config_d.c"->check_config("death") == 1)
    {
        reborn->set_XP_tax(0, 0, "death"); 
    }*/
    //half exp loss when reborn.  May change if the spell is too good.
    reborn->set_ghost(0);
    reborn->set_hp((int)reborn->query_max_hp());
    reborn->set_heart_beat(1);
    reborn->force_me("look");
    reborn->remove_pk_death_flag();
    reborn->set_death_age(0);
    reborn->set_property("rebirth time",time());
    save_player( reborn->query_name() );
    PLAYER_D->add_player_info();
    reborn->remove_property("rebirth");
    if(myob = present("kelemvor-rebirth-blessing999",reborn)) myob->remove();
    if(!stringp(reztype) || reztype != "foresight") 
    {
        tell_object(reborn,"%^YELLOW%^You have chosen to accept your deity's blessing "+
        "of rebirth!  You feel your consciousness slip back into "+
        "your body.%^RESET%^");
        tell_room(environment(reborn),"%^YELLOW%^"+ETOQCN+" suddenly stirs and "+
        "takes a ragged breath, rising once more!%^RESET%^",reborn);
    }
    else 
    {
        tell_object(reborn,"%^YELLOW%^The unsettling sensation of slowed time seems to "+
        "slowly return to normal, and you step aside from the blow that would end your life!.%^RESET%^");
        tell_room(environment(reborn),"%^YELLOW%^Just when you thought "+ETOQCN+" was "+
        "finished, you realise that somehow they'd stepped aside from the killing blow!%^RESET%^",reborn);
    }
    TO->remove();
    return;
}

void do_death()
{
    object reborn;
    object ob, corpse, money_ob, *stuff, klr,*keeping=({});
    string *currs,curclass, seen, msg_death;
    int tmp, hp_loss, i,j, room,num;

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    reborn = ETO;
    reborn->set_hp(-1);
    reborn = ETO;
    corpse = new(OB_CORPSE);
    if(!avatarp(reborn) || !reborn->query_disguised()) corpse->set_name(reborn->getParsableName());
    else corpse->set_name(capitalize(reborn->query_vis_name()));
    corpse->add_id("corpse of "+query_vis_name());
    corpse->copy_body(reborn);
    corpse->move(environment(reborn));
    corpse->set_was_user(1);
    stuff = all_inventory(reborn);
    if((int)"/daemon/config_d.c"->check_config("death") == 0)
    {
        money_ob = new("/std/obj/coins");
        currs = query_currencies();
        for(i=0,tmp= sizeof(currs);i<tmp;i++)
        {
            money_ob->set_money(currs[i], query_money(currs[i]));
            add_money(currs[i],-query_money(currs[i]));
            money_ob->set_property("died time",time());
        }
        money_ob->move(corpse);       

        if((objectp(klr)) && klr->is_player() && reborn->is_player())
        {
            for(i=0;i<sizeof(stuff);i++)
            {
                keeping += ({stuff[i]});
                keeping = distinct_array(keeping);
            }
        }
        else
        {
            if((objectp(klr)) && !klr->is_player() && reborn->is_player())
            {
                num = (sizeof(stuff)*10)/100;
                if(num && sizeof(stuff))
                {
                    i=0; 
                    while(sizeof(keeping) != num && i<50)
                    {
                        i++;
                        ob = stuff[random(sizeof(stuff))];
                        if(!ob->query_property("monsterweapon") || !ob->query_property("death remove") || !ob->query_property("death keep"))
                        {
                            keeping += ({ ob });
                            keeping = distinct_array(keeping);
                        }
                    }
                }
            }
        }
        for(i=0;i<sizeof(stuff);i++)
        {
            if(!objectp(stuff[i])) continue;
            if(member_array(stuff[i],keeping) != -1)
            {
                if(!objectp(stuff[i])) { continue; }
                if(stuff[i]->is_armor() && stuff[i]->query_worn()) { stuff[i]->set_not_equipped(); }
                if (stuff[i]->query_wielded()) { stuff[i]->set_not_inhand(); }
                continue; 
            }
            if(stuff[i]->query_property("monsterweapon") ||stuff[i]->query_property("death remove"))
            {
                stuff[i]->remove();
                continue;
            }
            if (stuff[i]->query_property("death keep")) continue;
            if(stuff[i]->query_item_owner_prop("death_clear"))
            {
                stuff[i]->clear_item_owners();
            }
            else if(stuff[i]->query_item_owner_prop("death_remove")) 
            {
                stuff[i]->remove_item_owner(reborn->query_name());
            }
            if (!stuff[i]->drop()) stuff[i]->move(corpse);
            stuff[i]->set_property("died time",time());
        }
    }
    else if((int)"/daemon/config_d.c"->check_config("death") == 1)
    {
        stuff = deep_inventory(reborn);
        for(i=0;i<sizeof(stuff);i++)
        {
            if(!objectp(stuff[i])) continue;
            if(stuff[i]->is_armor() && stuff[i]->query_worn()) { stuff[i]->set_not_equipped(); }
            if (stuff[i]->query_wielded()) { stuff[i]->set_not_inhand(); }
            stuff[i]->set_overallStatus((int)stuff[i]->query_overallStatus()/2);
            continue; 
        }
    }
    save_player( query_name() );
    PLAYER_D->add_player_info();
    if(!present("kelemvor-rebirth-blessing999",reborn)) reborn->remove_property("rebirth");
    tell_object(reborn,"%^BOLD%^%^CYAN%^You have chosen to forgo your "+
        "chance at life and accept Kelemvor's judgment!%^RESET%^");
    reborn->move("/d/shadowgate/death/death_room");
    TO->remove();
    return;
}

void set_reztype(string str) { reztype = str; }