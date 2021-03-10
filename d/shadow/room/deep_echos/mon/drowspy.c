// spy with some notes oohhhhh
#include <std.h>
#include <daemons.h>
#include "../deep_echo.h"

inherit "/std/monster";

object scroll;
int xx = 0;

void create() {
   object pap;
   ::create();
   set_name("drow spy");
   set_id( ({ "drow spy","drow","drowspy","spy" }) );
   set_race("drow");
   set_gender("male");
   set_short("A drow clothed in black");
   set_long("It is hard to tell what race this "+
   "figure is.  He is of a lithe build and about "+
   "5 foot tall.  He walks with grace, agility and stealth."+
   "  The only thing that belies his race is his dark skin "+
   "and white hair.  Both are barely noticeable because he "+
   "is completely clothed in tight fitting clothing.  Even "+
   "his face is covered in a mask that is completely black."+
   " His outfit is like some kind of night camouflage.");
   set_class("mage");
   set_mlevel("mage",17);
   set_guild_level("mage",17);
   add_search_path("/cmds/mage");
   set_mob_magic_resistance("average");
   set_hd(17,4);
   set_hp(230 + random(61));
   set_exp(9000);
   set("aggressive", 0);
   set_alignment(9);
   set_stats("intelligence",18);
   set_stats("wisdom",10);
   set_stats("strength",10);
   set_stats("charisma",10);
   set_stats("dexterity",20);
   set_stats("constitution",16);
   add_money("copper",random(2000));

   set_funcs(({"special_spell"}));
   set_func_chance(95);    
   set_monster_feats(({"hardenedminions"}));
   set_overall_ac(0);
   if(!random(3)) {
     scroll = new("/d/magic/scroll");
     scroll->set_spell(5);
     scroll->move(TO);
   }     
  new(OBJ"dcloak")->move(TO);
  new(OBJ"dpants")->move(TO);
  new(OBJ"dmask")->move(TO);
  new(OBJ"pwand")->move(TO);
  command("wearall"); 
  pap = new("/d/common/obj/misc/paper");
  pap->move(TO);
  pap->set("language","drow");
  pap->set("read","%^GREEN%^Drow Journal\n\n%^RESET%^"+
       "525 SG:\n  Our forces "+
	   " gathered up most of the defeated "+
	   "ogre forces.   They had been "+
	   "all but driven from their caves "+
	   "near tabor.\n"+
	   "We lead the ogres through underdark "+
	   "passages to attack the dwarven mountian "+
	   "from below.  It looked like it would be "+
	   "a quick success however the ogres kept "+
	   "in fighting so the dwarved held the upper "+
	   "levels. \n"+
	   "My mentor, a drow by the name of zast kept"+
	   " trying to regroup the ogres for many years\n\n"+
	   "610 SG:\n We had enough ogres to wipe out the "+
	   " dwarves from this place.  However on the eve "+
	   "of the attack, adventurers from a town called"+
	   " shadow killed zast and the large group of "+
	   "ogres battled each other for standing "+
	   "A king arose from the chaos so I am sent "+
	   "here to watch these brute's progress "+
	   "for the priestesses.\n \n"+
       "680 SG:\n I hate this assignment. "+
	   "Been watching the ogres in a stalemate "+
	   "against the dwarves for years now.  "+
	   "They are so ungreatful for us saving them "+
	   "from tabor all those years ago.  "+
	   "The king is a fool, he'll never finish "+
	   "driving out these dwarves.\n \n"+
	   "690 SG:\n"+
	   "  It looks like my side project is over"+
	   " Some malarites have moved in and "+
	   "are condunting hunts for their dark"+
	   " rituals.  They've broken the portal "+
	   "I was using to send slaves back to the city."+
	   " One hunter even spotted my tracks. "+
	   "He's made it his mission to hunt drow down "+
	   "The malarites are stupid they'll never catch me.");
  set_hidden(1);
}
int special_spell(object targ){
		object me;
        object vic;
        if(!objectp(TO)) return 1;
        if(!objectp(ETO)) return 1;
		
       me= TO;
	     if(!objectp(vic = me->query_current_attacker())) { return 0; } 
		vic = me->query_current_attacker();
		
		
        if (xx == 0) {
          new("/cmds/spells/b/_blink.c")->use_spell(TO,TO,17,100,"mage");
		  command("hardenedminions");
         } 
        xx=random(6)+1;
        switch(xx) {
              case 1:{
                tell_object(vic,"%^RED%^Drow points at you "+
                        "and a darkness chills your soul.");
                tell_room(ETO,"%^RED%^Drow points at "+
                        vic->query_cap_name()+" and darkness"+
                   " envelops them.",vic);
                vic->do_damage("torso",random(40)+3);
                return 1;}
              case 2:{
                if (vic->query_tripped()) 
                   { 
	new("/cmds/spells/l/_lightning_bolt")->use_spell(TO,vic->query_name(),17,100,"mage");
                    return 1;}
                tell_object(vic,"%^RED%^Drow laughs and causes "+
                        "your feet to float out from you!");
                tell_room(ETO,"%^RED%^Drow laughs and causes "+
                        vic->query_cap_name()+
                        "'s feet to fall out from under them." ,vic);
                vic->set_tripped(1,"you're recovering from"+
                        " being knocked down.");}
                return 1;
              case 3:{
                tell_object(vic,"%^RED%^Drow's darkness"+
                  " invokes fear within you!");
                tell_room(ETO,""+vic->query_cap_name()+" runs "+
                        "from the drow's darkness.",vic);              
                vic->run_away();
                return 1;}
              case 4:{
       new("/cmds/spells/b/_burning_hands")->use_spell(TO,vic->query_name(),17,100,"mage");
                } 
              case 5:{
 new("/cmds/spells/m/_monster_summoning_i")->use_spell(TO,vic->query_name(),17,100,"mage");
 new("/cmds/spells/c/_cone_of_cold")->use_spell(TO,vic->query_name(),17,100,"mage");
                }
              case 6:{
        new("/cmds/spells/h/_hideous_laughter")->use_spell(TO,vic->query_name(),17,100,"mage");
                } 
        }
}
