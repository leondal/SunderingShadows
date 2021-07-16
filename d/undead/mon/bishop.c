#include <std.h>
#include "../undead.h"

inherit CREATURE;

int builder;
object player,sucker;

void create() 
{
    ::create();
    set_name("bishop");
    set_id(({"bishop","archbishop","boquillas"}));
    set_race("human");
	set_gender("male");
    set_short("Boquillas, the Bishop of Graez");
    set_long("%^RESET%^%^CYAN%^Boquillas is a short fellow standing just over "
"five feet tall.  He wears the %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^and "
"%^BOLD%^%^WHITE%^white %^RESET%^%^CYAN%^robes of a priest, and can often be "
"seen with a book in his hand.  He is not only the religious leader of Graez, "
"but also the political leader.  As you might imagine given the state of the "
"city, he seems very %^MAGENTA%^troubled%^CYAN%^, yet there is something more "
"to it.  He seems to have this almost tangible aura about him, a very "
"%^BOLD%^%^GREEN%^sick %^RESET%^%^CYAN%^aura.  It leaves you wondering just "
"what was causing this.  Perhaps if you %^YELLOW%^listen %^RESET%^%^CYAN%^to "
"him he will tell you his tale.%^RESET%^");
    set_body_type("human");
    set_class("cleric");
    set_guild_level("cleric",30);
    set_hd(30,5);
    set_exp(50000);
    set_new_exp(25,"boss");
	set_hp(500);
    set_overall_ac(0);
  	set("aggressive", 0);
  	set_alignment(9);
  	set_size(2);
   	set_stats("intelligence",18);
   	set_stats("wisdom",18);
   	set_stats("strength",18);
   	set_stats("charisma",18);
   	set_stats("dexterity",18);
   	set_stats("constitution",18);
	add_money("electrum",random(10));
	add_money("silver",random(10));
    add_money("gold",random(100));
	add_money("copper",random(20));
    set_spells(({
        "cause light wounds",
        "slay living",
        "sticks into snakes",
        "animate dead",
        "limb attack",
        "flamestrike"
              }));
    set_spell_chance(100);

}

void init()
{
    ::init();
    if(interactive(TP))
    {
        add_action("startit","talk");
        add_action("listenit","listen");
    }
}

void reply_back(string str) 
{
    tell_room(ETO,"%^MAGENTA%^Boquillas says:%^RESET%^ "+str,TO);
}

void reply_back1(string str) 
{
    tell_room(ETO,"%^MAGENTA%^The Archbishop frowns but continues: %^RESET%^"+str,TO);
}

void reply_back2(string str) 
{
    tell_room(ETO,"%^MAGENTA%^The Bishop plays with the pages of his book while he speaks: %^RESET%^"+str,TO);
}

void reply_back3(string str) 
{
    tell_room(ETO,""+str,TO);
}

int listenit(string str) 
{
    string tem;
    player = this_player();
    if(!str) return notify_fail("Listen to whom?\n");
    if(!sscanf(str, "to %s", tem)) return notify_fail("You can't listen to that!\n");
    if(tem != "bishop") return notify_fail("The "+tem+" is not present!\n");
    
    call_out("reply_back",2,"\n"
        "You should know that this story begins a very long time ago.\n"
        "A time full of hope, and happiness, where a powerful and \n"
        "benevolent king ruled these lands. His name was High King Morock.\n"
        "He is the reason that I need adventurers such as yourself\n"
        "so badly. You see years ago, when Kartakass had first started \n"
        "to make himself known, Morock lead his legions to crush the Undead\n"
        "Lord now known as Kartakass.  Little did he know that Kartakass\n"
        "had all ready managed to corrupt one of his warlords. So when \n"
        "they rode onto the battlefield and engaged in combat, this warlord\n"
        "took the opportunity to slay High King Morock. Morock's armies \n"
        "were in shambles and without his guidance they were beside themselves\n"
        "it was an easy task for Kartakass to finish off the army, turning\n"
        "most of them into his own undead slaves. But after all of these \n"
        "years of war, I have finally found a way to beat him, this is\n"
        "where you come in. I have formulated a spell that will allow \n"
        "me to bring Morock back to life, so that he can lead our army\n"
        "to victory against the armies of darkness. I need you to gather\n"
        "the components for my spell, and return them to me.\n");
  
    call_out("reply_back1",12,"\n");
  
    call_out("reply_back3",13,""
        "Well, I hope you have %^BOLD%^listened%^RESET%^ to me well, \n"
        "because I desperately need for you to recover these spell \n"
        "components. The components are as follows: \n"
        "      A snake that moves with two feet\n"
        "      An eye from someone with great foresight\n"
        "      A holy cross from an unholy man\n"
        "      The eyes of someone who does not see the present\n"
        "      The horn of a minotaur\n"
        "Collect these ingredients for me, then return them for me and \n"
        "victory will be ensured!\n");
  
    call_out("reply_back2",16,"\n");
  
    call_out("reply_back3",17,""
        "It is urgent that you help us, the survival of this entire "
        "continent rests on your shoulders, don't let us down.  Hurry back "
        "and %^BOLD%^talk %^RESET%^to me.");

    return 1;
}

int startit(string str)
{
    string temp;
    player = this_player();
	if(!str) return notify_fail("Talk to who?\n");
	if(!sscanf(str,"to %s",temp)) return notify_fail("You can't talk to that!\n");
    if(temp != "bishop") return notify_fail("The "+temp+" is not here!");
	builder = 1;
	return 1;
}

void heart_beat() 
{
    object targ,ob,obj,obj2,obj3,obj4,obj5;
    ::heart_beat();
    
    if(!builder) { return; }
	    
    builder++;

    switch(builder) 
    {

    case 2:
        {        
            say("%^MAGENTA%^Boquillas says:%^RESET%^ Good day to you "+player->QCN+"."); 
            return 1;
        }
    case 3:
        {         
            say("%^MAGENTA%^Boquillas says:%^RESET%^ I'm glad some people are still brave enough to come to this hellish isle!.\n"); 
            return 1;
        }        
    case 4:
        {
            say("%^MAGENTA%^Boquillas says:%^RESET%^ Please tell me you've brought the ingredients I asked for.\n"); 
            
            if(!(obj = present("horn",player))) 
            {
		        builder = 0;
                say("%^MAGENTA%^Boquillas says:%^RESET%^ What! You did not bring me the horn "
                    "of a minotaur! How dare you!");
			    return 1;
		    }
            if(!(obj2 = present("eye",player)))
            {
                builder = 0;
                say("%^MAGENTA%^Boquillas says:%^RESET%^ You didn't bring me the eye of someone "
                    "with great foresight? How dare you!");
                return 1;
            }
            if(!(obj3 = present("necklace of eyes",player)))
            {
                builder = 0;
                say("%^MAGENTA%^Boquillas says:%^RESET%^ You didn't bring me the eyes of someone "
                    "who does not see the present? How dare you!");
                return 1;
            }
            if(!(obj4 = present("cruciform",player)))
            {
                builder = 0;
                say("%^MAGENTA%^Boquillas says:%^RESET%^ You didn't bring me the holy cross of "
                    "an unholy man? How dare you!");
                return 1;
            }
            if(!(obj5 = present("medusa's snake",player)))
            {
                builder = 0;
                say("%^MAGENTA%^Boquillas says:%^RESET%^ You didn't bring me a snake that moves "
                    "with two feet? How dare you!");
                return 1;
            }
		
           obj->remove();
           obj2->remove();
           obj3->remove();
           obj4->remove();
           obj5->remove();
          
            say("%^MAGENTA%^Boquillas says:%^RESET%^ Good! You did succeed in gathering "
                "the ingredients!\n");
            write("Boquillas takes the ingredients from you.\n");
            return 1;
        }	    
    case 5:
        {    
            say("%^MAGENTA%^Boquillas says:%^RESET%^ Thank you very much for bringing these to me.\n");
            return 1;
        }    
    case 6:
        {    
            write("Boquillas begins to pour the ingredients into a cauldron.");
            say("%^MAGENTA%^Boquillas says:%^RESET%^ Now for your reward you greedy fool!");
            tell_room(ETO,"You see the ground crack open and fire spews out of it!",TO);
            tell_room(ETO,"You see a small, but very well built dwarf rise up out of the flames.",TO);
            tell_room(ETO,"But he is followed very closely by a hideous demon!",TO);
            return 1;
        }    
    case 7:
        {  
            int i;
            object *live;
            say("%^MAGENTA%^Boquillas says:%^RESET%^ My Lord Morock! Kill him so that we may "
                "then deal with Kartakass!");
            tell_room(ETO,"%^RED%^A grin forms on the demons face, things are obviously going "
                "according to his plan.%^RESET%^");
            if(member_array("Undead Quest",player->query_quests()) == -1)
            {
                player->set_quest("Undead Quest");
                player->fix_exp(6200000,player);
            }

            command("say For your idiocy you shall die!");

            live = filter_array(all_living(ETO), "is_target", CREATURE);
            for(i=0;i<sizeof(live);i++)
            {
                TO->kill_ob(live[i],0);
            }
            new(MON"king_morock.c")->move(ETO);
            new(MON"demon.c")->move(ETO);
            return 1;
        }
    }
    
    return 1;
}


