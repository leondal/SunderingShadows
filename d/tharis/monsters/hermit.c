//hermit_quest.c

#include <std.h>
#include <daemons.h>

inherit MONSTER;

int flag1,flag2;

void create(){
        ::create();
        set_name("old hermit");
        set_id(({"hermit","Hermit","Old","Old hermit","old","old hermit","man"}));
        set_short("An old hermit");
        set("long",
@OLI
      This old man moves like part of the forest. His movements are slow and
exact but easy and free. His sun beaten skin shows through tattered clothes
and various hides. His warm eyes show not a love for you but a love for what
is all about you. Concern creases his face and worry seems all around.
OLI
        );
        set_hd(40,8);
        set_hp(500);
        set_exp(300);
        set_race("human");
        set_gender("male");
        set_class("ranger");
        set_overall_ac(-10);
  		set_body_type("human");
        new("/d/common/obj/weapon/quarter_staff")->move(TO);
        command("wield quarterstaff in left hand and right hand");
}

void init(){
    object ob;
        ::init();

        if(member_array((string)TP->query_name(), SAVE_D->query_array("forest")) == -1&& (!flag2)){
                call_out("do_entrance",2,TP);
        } else {
           if(ob=present("Forest Quest",TP,)){
                  flag2 = 1;
                  call_out("do_end",2,TP,ob);
                  return;
            }

       }
}

void do_entrance(object ob){
        if(!objectp(ob)) return;

        tell_object(ob,"%^BOLD%^%^GREEN%^Welcome, adventurer");
        tell_object(ob,"%^BOLD%^%^GREEN%^Look around you. Everything is being wasted!");
        tell_object(ob,"%^BOLD%^%^GREEN%^I need you to stop this war! You must bring peace to this place!");
        if(ALIGN->is_good(ob)){
                tell_object(ob,"%^BOLD%^%^GREEN%^You are good. I can feel the good dwelling in you.");
                tell_object(ob,"%^BOLD%^%^GREEN%^You must hunt out the Forest Linnorm and end its terror.");
                tell_object(ob,"%^BOLD%^%^GREEN%^Bring its head back to me so I might see the sight of peace!");
        }
        if(ALIGN->is_evil(ob)){
                tell_object(ob,"%^BOLD%^%^GREEN%^You are evil. I can feel the evil dwelling in you.");
                tell_object(ob,"%^BOLD%^%^GREEN%^You must hunt out the Steel Dragon and end its quest for good.");
                tell_object(ob,"%^BOLD%^%^GREEN%^Bring its head back to me so I might see the sight of peace!");
        }
        if(ALIGN->is_neutral(ob)){
                tell_object(ob,"%^BOLD%^%^GREEN%^You are neither good nor evil. I can feel this about you.");
                tell_object(ob,"%^BOLD%^%^GREEN%^You must now decide how you feel for this deed may well change your life.");
                tell_object(ob,"%^BOLD%^%^GREEN%^You must hunt out the Forest Linnorm and end its terror.");
                tell_object(ob,"%^BOLD%^%^B_GREEN%^OR");
                tell_object(ob,"%^BOLD%^%^GREEN%^You must hunt out the Steel Dragon and end its quest for good.");
                tell_object(ob,"%^BOLD%^%^GREEN%^Bring its head back to me so I might see the sight of peace!");
        }

        tell_object(ob,"%^BOLD%^%^GREEN%^Placed carefully by each army are scrolls which are meant for when they assault the dragons.");
        tell_object(ob,"%^BOLD%^%^GREEN%^Hunt these out and use them in your quest!");
        tell_object(ob,"%^BOLD%^REMEMBER adventurer that the head of a dragon disappears quickly after it dies. You must bring it back quickly!");

        SAVE_D->set_value("forest",TPQN);
        return;
}

void do_end(object ob,object head){

        object ob2;
        if(!objectp(ob)) return;
		if(!objectp(head)) return;
		
        tell_room(ETO,"%^BOLD%^%^GREEN%^ AHH I see you have brought me the head of the dragon!");
        tell_room(ETO,"%^BOLD%^%^GREEN%^ My world is at peace!");
        message("info","%^BOLD%^%^GREEN%^Peace hast been brought to the forest by "+ob->getParsableName()+"!",users());
  		if(member_array("Peace to the Forest",ob->query_quests()) == -1){
        	ob->set_quest("Peace to the Forest");
        	if((ALIGN->is_good(ob) && present("evil head",ob)) || (ALIGN->is_evil(ob) && present("good head",ob)) || ALIGN->is_neutral(ob)){
				ob->fix_exp(1000000,ob);
            ob->add_money("gold",40000);
			} else {
				force_me("say Silly boy, yes I thank you for the peace you have brought us. But what price you pay. You have brought to an end your own way of life here. You will always suffer I'm afraid for this");
				message("info","%^BOLD%^%^GREEN%^"+ob->query_cap_name()+" has betrayed "+ob->query_possessive()+" way of life and beliefs!",users());
			}
		}
		head->remove();
        tell_object(ob,"\n\n\ncongratulations!\n\n\n");
        ob2 = new("/d/deku/armours/ring_p");
        ob2->set_property("enchantment",2);
    	ob2->move(ob);

        tell_room(ETO,"%^BOLD%^%^GREEN%^As the old man leaves you notice animals come forth from the shadows and glance around with a thankful look on their faces!");

        remove();
}
