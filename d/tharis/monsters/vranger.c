//voadkynr.c

#include <std.h>

inherit NPC;

void do_stuff(string msg, object ob);

void create(){
   ::create();

   set_name("voadkyn ranger");
   set_short("%^GREEN%^Voadkyn Ranger");

   set_id(({"voadkyn","ranger","voadkyn ranger"}));
   set_long(
@OLI
   %^GREEN%^This is a wood giant. The voadkyn is the ruler of the
demi-human races. This one will continue to fight the war until his
forest is won. This massive creature of good wins battles not only
with his extreme power and the massive weapons which he double
wields but with his dexterity and speed.
OLI
   );

   set_alignment(7);
   set_class("ranger");
   set_mlevel("ranger",20);
   set_hd(20,10);
   set_stats("strength", 20);
   set_hp(330);
   set_race("voadkyn");
   set_body_type("human");
   set_size(3);
   set_overall_ac(0);
   set_exp(9000);
   set_max_level(25);
   set_speed(30);
   set_property("alignment adjustment",-5);
   set_property("full attacks",1);
   new("/d/tharis/obj/vchain")->move(TO);
   command("wear chain");
   new("/d/tharis/obj/skincloak")->move(TO);
   command("wear cloak");
   new("/d/tharis/obj/vaxe")->move(TO);
   command("wield axe");
   new("/d/tharis/obj/vaxe")->move(TO);
   command("wield axe");
   set_stabbed_func((:TO,"stabbed":));
}

void stabbed(){
   TP->set_disabled();
   kill_ob(TP,1);
   execute_attack();
}

// Adopted from the elven ranger leader, so pcs don't have to kill him for his stuff

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) { return; }
    if(TO->query_hp() < 0) { TO->die(); }
    return;
}


void catch_say(string msg){
   ::catch_say(msg);
   do_stuff(msg,TP);
}

int choose;

void do_something(string str)
{
    if(!stringp(str)) { return; }
    force_me(str);
    return;
}

void disappear()
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    tell_room(ETO,"%^BOLD%^%^GREEN%^The voadkyn ranger disappears into the forest.%^RESET%^");
    TO->move("/d/shadowgate/void");
    TO->remove();
}

void do_stuff(string msg, object ob)
{
   string race,name;
   object obj;
   race = TP->query_race();
   name = TP->query_name();
   if(race == "elf" || race == "half-elf")  force_me("speak elven");
   else if(race == "voadkyn")               force_me("speak voadkyn");
   else                                     force_me("speak common");

    if(TP->query_invis()) 
    {
        switch(random(2)) 
        {
        case 0:    
            new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,20,100,"cleric");
            break;
        case 1:  
            force_me("emote tightens his old on his axes and looks around carefully.");
            force_me("say %^GREEN%^Who goes there?  Show yourself!%^RESET%^");
            break;
        default :
            break;
        }
        if(random(5))  return;
    }
  
    if(!choose) 
    {
        msg = lower_case(msg);

        if(strsrch(msg,"evil") != -1)
        {
            if(race != "voadkyn")
            {
                call_out("do_something",1,"emote hmms");
                call_out("do_something",2,"say %^GREEN%^You are not a voadkyn, "
                    "but maybe you can help, the forest is overrun with evil.  "
                    "The gods will smile apon your soul if you help to destroy "
                    "it.%^RESET%^");
            }
            else
            {
                call_out("do_something",1,"emote smiles");
                call_out("do_something",2,"say %^GREEN%^Greetings "
                    "brother.  Are you here to help cleanse the forest "
                    "of evil?%^RESET%^");
            }
            return;
        }

        if(strsrch(msg, "help") != -1 || strsrch(msg,"weapon") != -1 || 
            strsrch(msg,"axe") != -1 || strsrch(msg,"yes") != -1 || 
            strsrch(msg,"armor") != -1 || strsrch(msg,"chain") != -1)
        {
            if(race != "voadkyn")
            {
                call_out("do_something",1,"emote hmms as he seems to consider");
                call_out("do_something",2,"say %^GREEN%^Very well, if you will "
                    "destroy one of the ogre-magi and bring me its katana as "
                    "proof.  I will reward you with either a cloak or an "
                    "axe.%^RESET%^");
                call_out("do_something",3,"show cloak to "+name+"");
                call_out("do_something",3,"show axe to "+name+"");
            }
            else
            {
                call_out("do_something",1,"emote nods gruffly");
                call_out("do_something",2,"say %^GREEN%^The forests are "
                    "infested with the vermin called ogre-magi. defeat these "
                    "vile creatures, and bring me one of their blades.  I "
                    "will reward you with any of the magic items I have.%^RESET%^");
                call_out("do_something",3,"show cloak to "+name+"");
                call_out("do_something",3,"show axe to "+name+"");
                call_out("do_something",3,"show chain to "+name+"");
            }
            return;
        }
 

        if(strsrch(msg, "hello") != -1 || strsrch(msg,"greeting") != -1)
        {

            if(race != "voadkyn") 
            {
                call_out("do_something",1,"emote nods in greeting");
                call_out("do_something",2,"say %^GREEN%^Greetings, I hope "
                    "your travels find you save from the evil all around "
                    "us.%^RESET%^");
            }
            else
            {
                call_out("do_something",1,"emote smiles in greeting");
                call_out("do_something",2,"say %^GREEN%^Greetings brother, "
                    "I hope this day finds you faring well and safe from "
                    "the evil around us.");
            }
            return;
        }
    }


    if(choose) 
    {
        if(strsrch(msg,"chain") != -1)
        {
            if(race != "voadkyn")
            {
                call_out("do_something",1,"emoteat "+name+" looks $N over");
                call_out("do_something",2,"emote shakes his head");
                call_out("do_something",3,"say %^GREEN%^I am sorry, but "
                    "I cannot give you the chain.  Only voadkyns have the "
                    "ability to use it.%^RESET%^");
            }
            else
            {
                call_out("do_something",1,"emoteat "+name+" bows before $N");
                call_out("do_something",2,"say %^GREEN%^You have done well "
                    "in helping to rid this place of its investation of "
                    "ogre-magi.  Take this, your reward.");
                obj = present("chain",TO);
                if((int)obj->query_property("enchantment") < 0)
                {
                    obj->set_property("enchantment",absolute_value((int)obj->query_property("enchantment")));
                }
                call_out("do_something",3,"drop chain");
            }
            choose = 0;
            call_out("disappear",8);
            return;
        }

        if(strsrch(msg,"axe") != -1)
        {
            call_out("do_something",1,"emote nods gruffly and then grins");
            call_out("do_something",2,"say %^GREEN%^You have done well in "
                "ridding this place of evil.  May this axe serve you "
                "well.%^RESET%^");
            obj = present("axe",TO);
            if((int)obj->query_property("enchantment") < 0)
            {
                obj->set_property("enchantment",absolute_value((int)obj->query_property("enchantment")));
            }
            call_out("do_something",3,"drop axe");
        }

        if(strsrch(msg,"cloak") != -1)
        {
            call_out("do_something",1,"emote nods his head and bows.");
            call_out("do_something",2,"say %^GREEN%^You have protected "
                "the creatures of this forest by vanquishing the ogre"
                "-magi that well here.  May this cloak protect you.%^RESET%^");
            obj = present("cloak",TO);
            if((int)obj->query_property("enchantment") < 0)
            {
                obj->set_property("enchantment",absolute_value((int)obj->query_property("enchantment")));
            }
            call_out("do_something",3,"drop cloak");
        }
    choose = 0;
    call_out("disappear",8);
    }

    return;
}
    
 
void receive_given_item(object ob){
   string race,name,id,*ids;
   race = TP->query_race();
   name = TP->query_name();
   ids = ob->query_id();
   id = ids[0];   
   if(race == "elf" || race == "half-elf")  force_me("speak elven");
   else if(race == "voadkyn")               force_me("speak voadkyn");
   else                                     force_me("speak common");

    if(base_name(ob) == "/d/tharis/obj/katana")
    {
        choose = 1;
        TO->set_speed(0);
        call_out("do_something",1,"emote looks down at the katana.");
        call_out("do_something",2,"emoteat "+name+" nods and looks up at $N");
        call_out("do_something",5,"offer katana");
        call_out("do_something",3,"say %^GREEN%^This is a blade from the "
            "foul ogre-magi.  You have earned a reward.");
        if(race != "voadkyn")
        {
            call_out("do_something",4,"say %^GREEN%^You may choose either an "
                "axe or the cloak.");
        }
        else
        {
            call_out("do_something",4,"say %^GREEN%^You may choose the axe, the "
                "cloak, or the voadkyn chain.");
        }
    }
    else
    {
        call_out("do_something",1,"emote looks at the item and shakes his head.");
        call_out("do_something",2,"say %^GREEN%^This is not the item I am looking "
            "for.%^RESET%^");
        call_out("do_something",3,"give "+id+" to "+name+"");
    }
    return;
}






