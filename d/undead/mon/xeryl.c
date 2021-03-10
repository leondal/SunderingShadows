#include <std.h>
#define SAVE_D "/daemon/save_d"
#include "/d/undead/undead.h"

inherit WEAPONLESS;

#define HOMEROOM "/d/undead/rooms/xerylhome"

string *revenge;

int doing;
int angry;
void create()
{
    object ob;
    ::create();
    set_race("dragon");
    set_no_clean(1);
    set_name("obsidian dragon");
    set_property("no bow",1);
    set_property("no bows",1);
    set_id(({"dragon","obsidian dragon","Dragon","obsidian","xeryl","Xeryl"}));
    set_short("%^BOLD%^%^BLACK%^Xeryl, an old obsidian dragon");
    set_long("%^BOLD%^%^BLACK%^This reptilian behemoth is ob%^WHITE%^s%^BLACK%^idi%^CYAN%^a%^BLACK%^n that has sprung to life."
" Scales that are as smooth as %^CYAN%^g%^WHITE%^l%^CYAN%^ass%^BLACK%^ run the entirety of its form, lending one to think them"
" adapted to mere defense - given their hardness, it would not be a terrible assumption. Looking closely, one would find that"
" the edges of each individual scale are %^WHITE%^ra%^RESET%^zo%^BOLD%^%^BLACK%^r-s%^RESET%^ha%^BOLD%^%^WHITE%^rp%^BLACK%^ when"
" they meet each and every joint of the great beast. A maw of %^WHITE%^t%^RESET%^ee%^BOLD%^%^WHITE%^th%^BLACK%^ is where you see"
" the most deviation, as each tooth appears as a jagged o%^WHITE%^n%^BLACK%^yx m%^WHITE%^o%^BLACK%^no%^CYAN%^l%^BLACK%^ith ready"
" to ensnare prey, %^RED%^r%^RESET%^%^RED%^en%^BOLD%^d %^WHITE%^b%^RESET%^o%^BOLD%^%^BLACK%^n%^WHITE%^e%^BLACK%^, and"
" %^RESET%^%^RED%^t%^BOLD%^ea%^RESET%^%^RED%^r %^ORANGE%^f%^BOLD%^l%^RESET%^%^ORANGE%^esh%^BOLD%^%^BLACK%^ - releasing volumes"
" of %^RESET%^%^RED%^bl%^BOLD%^oo%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^ to the air as simply as a painter would deliver brush to"
" canvas. If it were not for the myriad re%^RESET%^fl%^BOLD%^%^WHITE%^ec%^RESET%^ti%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^BLACK%^s"
" of %^WHITE%^l%^YELLOW%^igh%^WHITE%^t%^BLACK%^ upon the dragon, one might think it devoid of color altogether - night harnessed"
" within a j%^RESET%^%^RED%^e%^BOLD%^w%^BLACK%^el. When its wings spread, it feels reminiscent of being enveloped within a"
" %^RESET%^%^ORANGE%^vo%^YELLOW%^lc%^RESET%^%^ORANGE%^a%^RED%^n%^ORANGE%^ic %^BOLD%^%^BLACK%^cavern."
" %^RED%^Te%^RESET%^%^RED%^rr%^BOLD%^or%^BLACK%^ is the picture presented by this muscle-corded,"
" darkly-re%^RESET%^fl%^BOLD%^%^WHITE%^ec%^RESET%^ti%^BOLD%^%^WHITE%^v%^RESET%^e%^BOLD%^%^BLACK%^,"
" o%^WHITE%^b%^BLACK%^si%^CYAN%^d%^BLACK%^ian-sh%^WHITE%^a%^BLACK%^do%^CYAN%^w%^BLACK%^ed, ancient dragon.%^RESET%^ ");
    set_class("fighter");
    set_class("mage");
    set_hd(44,8);
    set_hp(2050);
    set_guild_level("fighter",44);
    set_guild_level("mage",44);
    set_mlevel("fighter",44);
    set_mlevel("mage",44);
    set_exp(100000);
    set_new_exp(50,"boss");
    set_overall_ac(-30); // -36 with bonuses
    set_body_type("dragon");
    set_attack_limbs(({"right claw","left claw","mouth"}));
    set_attacks_num(3);
    set_damage(1,25);
    set_hit_funcs((["mouth":(:TO,"mouth_attack":),"right claw":(:TO,"claw_attack":),"left
claw":(:TO,"claw_attack":)]));
    set_base_damage_type("slashing");
    set_class("fighter");
    set_gender("male");
    set_race("dragon");
    set_funcs(({"do_me"}));
    set_func_chance(102);
    add_money("gold",random(20000));
    add_money("platinum",random(1000));
   set_alignment(6);
   set_mob_magic_resistance("average");
    set_property("no knockdown",1);
    set_property("no death",1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_property("no steal",1);
    set_property("damage resistance",5);
    set_wimpy(15);
    //   revenge = ({});
   new("/d/undead/obj/powergem.c")->move(TO);
   "/daemon/monster_d.c"->add_death_watcher(TO);
   set_resistance("fire",20);
}
int mouth_attack(object targ)
{
   if(present("powergem",TO))
    {
        tell_room(ETO,"The chunk of obsidian the dragon carries darkens.");
        return roll_dice(3,25);
    }
    return roll_dice(2,15);
}

int claw_attack(object targ)
{
   if(present("powergem",TO))
    {
        tell_room(ETO,"The chunk of obsidian the dragon carries darkens.");
        return roll_dice(2,7);
    }
    return 0;
}
void do_me(object targ)
{
    int i,j;
    object *inven;

    inven = all_living(ETO);

    j = sizeof(inven);
   tell_room(ETO,"%^BOLD%^%^BLACK%^As the serpent rears its head back, the image of"
" %^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^va%^BOLD%^%^BLACK%^ building within a %^RESET%^%^ORANGE%^vo%^YELLOW%^lc"
"%^RESET%^%^ORANGE%^a%^RED%^n%^ORANGE%^o %^BOLD%^%^BLACK%^immediately before eruption builds within its re%^RESET%^fl"
"%^BOLD%^%^WHITE%^ec%^RESET%^ti%^BOLD%^%^WHITE%^v%^RESET%^e%^BOLD%^%^BLACK%^ maw - just before it releases a"
" %^RESET%^%^RED%^h%^BOLD%^el%^RESET%^%^RED%^li%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^ torrent of"
" %^RED%^d%^RESET%^%^RED%^r%^BOLD%^a%^YELLOW%^g%^RED%^o%^RESET%^%^RED%^n f%^BOLD%^i%^YELLOW%^r%^RESET%^%^ORANGE%^e%^RED%^!%^RESET%^");
    for(i=0;i<j;i++)
    {
        if(!objectp(inven[i])) continue;
        if(inven[i] == TO) continue;
        if(avatarp(inven[i])) continue;
        set_property("magic",1);
      tell_object(inven[i],"%^RESET%^%^RED%^The torrent of d%^RESET%^%^RED%^r%^BOLD%^a%^YELLOW%^g%^RED%^o%^RESET%^%^RED%^n f%^BOLD%^i%^YELLOW%^r%^RESET%^%^ORANGE%^e%^RED%^ strikes you down shaking your soul.\n");
        //if("daemon/saving_d"->saving_throw(inven[i],"breath_weapon",-35)) // switching to 3ed
        if("/daemon/saving_throw_d"->reflex_save(inven[i],-35))
        {
            inven[i]->do_damage("torso",roll_dice(24,4)/2+6);
        }
        else 
        {
            inven[i]->do_damage("torso",roll_dice(24,4)+12);

            //if ( !"daemon/saving_d"->saving_throw(inven[i],"breath_weapon",-14)) {
            if(!"/daemon/saving_throw_d"->fort_save(inven[i],-14)) 
            {
              inven[i]->set_paralyzed(( roll_dice(1,12))*8,"The panic instilled still grips
you!");
            } 
            else
            {
                inven[i]->add_attack_bonus(-1);
            }
        }
        remove_property("magic");
    }
    set_func_chance(25);
}

void heart_beat()
{
    int i,j;
    object ob;
    string *tmp, location;

    ::heart_beat();

    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tmp = ({});

   if(query_attackers() == ({}))
    {
        set_func_chance(102);
        if(!doing && sizeof((string *)SAVE_D->query_array("obsidian_revenge")))
        {
            call_out("get_um",60);
            doing = 1;
        }
        if(base_name(ETO) != HOMEROOM)
        call_out("home",10);
    } 
    else
    {
        doing = 0;
    }

    if(query_attackers() != ({})) { add_hp(55); }
    else { set_hp(query_max_hp()); }
    
    j=sizeof(revenge = (string *)SAVE_D->query_array("obsidian_revenge"));
    
    for(i=0;i<j;i++)
    {
        if(objectp(ob = find_player(revenge[i])))
        if(ob->query_ghost())
        SAVE_D->remove_name_from_array("obsidian_revenge",revenge[i]);
    }
    location = base_name(ETO);
   if(location == HOMEROOM || location == "/d/undead/rooms/mts/room97")
    {
      if(!present("powergem",TO)) new("d/undead/obj/powergem.c")->move(TO);
    }
    
    else 
    {
      if(ob = present("powergem",TO))
        {
            ob->move("/d/shadowgate/void");
            ob->remove();
        }
    }
}

void run_away()
{
   if(!query_paralyzed())

   {
      tell_room(ETO,"With horrible wounds the dragon flies high into the sky.");
      tell_room(ETO,"The words revenge echo through your mind.");
      tell_room(ETO,"You know that you will meet that dragon again.");
      tell_room(ETO,"\n\nREVENGE\n\n");
      move("/d/magic/obj/place");
   }
}

int clean_up() { return 1; }

void set_paralyzed(int time, string mes)
{
    if(!PO->is_spell()) return ::set_paralyzed(time,mes);
    return;
}

int kill_ob(object victim, int which)
{
    int hold;

    hold = ::kill_ob(victim,which);

    if(!hold) return hold;

    if(userp(victim))
    {
        SAVE_D->set_value("obsidian_revenge",victim->query_name());
    }
    return hold;
}

void set_bound(int xxx, string msg) {return 1;}

void set_tripped(int xxx, string msg) {return 1;}

void init()
{
    ::init();

    if(wizardp(TP)) return;

    if(TP->query_invis())
    {
        tell_object(TP,"The dragon chuckles as he glances in your direction.\n");
    }
    
    if(TP == TO) return;
    if((int)SAVE_D->is_member("obsidian_revenge",(string)TP->query_name()) != -1)
    {
        tell_object(TP,"Xeryl raises with a mighty roar and lashes out at you.\n");
        tell_room(ETP,"Xeryl, with a mighty roar drives himself into "+TPQCN,TP);
        TP->set_paralyzed(5,"You're still reeling from the dragon's blow!");
        kill_ob(TP,1);
        return;
    }

    if(member_array((string)TP->query_race(),({"firbolg","voadkyn","ogre","giant"})) != -1)
    {
        tell_object(TP,"Xeryl raises with a mighty roar and lashes out at you.\n");
        tell_room(ETP,"Xeryl, with a mighty roar drives himself into "+TPQCN,TP);
        TP->set_paralyzed(5,"You're still reeling from the dragon's blow!");
        kill_ob(TP,1);
        return;
    }

    if(TP == present("horse"))
    {
        tell_room(ETO,"The dragon picks the horse up in his mouth and shakes "
            "it violently breaking its neck.");
        TP->die(TO);
    }
    ETO->set_property("no pocket space",1);
    add_action("steal","steal");
}

int steal(string str)
{
    string who,what;
    if(!str) return 0;
    if(sscanf(str,"%s from %s",what,who) != 2) return 0;
    if(!id(who)) return 0;
    SAVE_D->set_value("obsidian_revenge",TP->query_name());
    tell_object(TP,"I will extract revenge.\n");
    return 0;
}

void home()
{
    if(query_attackers() == ({}))
    if(base_name(ETO) != HOMEROOM)
    {
        tell_room(ETO,"Xeryl lifts into the air and heads home.");
        move(HOMEROOM);
    }
}

void get_um()
{
    int i,j,k = 0;
    object ob;



    if(query_attackers() != ({})) return;

    j = sizeof(revenge = SAVE_D->query_array("obsidian_revenge"));

    for(i=0;i<j;i++)
    {
        if (objectp(ob = find_player(revenge[i]))) 
        {
            if (environment(ob)->query_property("indoors")) { continue; } 
            else 
            {
                k = i+1;
                break;
            }
        }
    }
    if(!k)
    {
        doing = 0;
        return;
    }

   message("combat","%^BOLD%^%^BLACK%^A dragon awakes as he searches for revenge.",users());
    call_out("headin",5,revenge[k-1],environment(find_player(revenge[k-1])));

    set_wimpy(25);
}

void break_um() 
{
    if(!random(3))
    new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,TO->query_guild_level("mage"),200,"mage");
}


void headin(string who, object waswhere) 
{
    object ob;


    if(query_attackers() != ({})) return;
    
    if(!objectp(ob = find_player(who)))
    {
        doing = 0;
        return;
    }

    tell_room(environment(ob),"The beating of wings draws close to you.");
    
    if(environment(ob)->query_property("indoors")) 
    {
        tell_room(waswhere,"The beating of wings receeds off into the distance...");
        doing = 0;
        return;
    }
    
    tell_room(environment(ob),"Xeryl lands before you, angry as hell itself, and "
        "screeches: RETURN TO ME WHAT IS MINE!");
    move(environment(ob));

    doing = 0;
    tell_object(ob,"Xeryl raises with a mighty roar and lashes out at you.\n");
    tell_room(environment(ob),"Xeryl, with a mighty roar drives himself into "+TPQCN,ob);
    ob->set_paralyzed(5,"You're still reeling from the dragon's blow!");
    kill_ob(ob,1);
    call_out("break_um",0);
    call_out("break_um",3);
}

string *query_revenge() { return (string *)SAVE_D->query_array("obsidian_revenge"); }

void add_revenge(string str) { SAVE_D->set_value("obsidian_revenge", str); return; }

void die(object obj)
{
    int i,j;
    object ob;
    revenge = TO->query_attackers() + TO->query_hunted();

    if(revenge != ({}))
    {
        j = sizeof(revenge);
        for(i=0;i<j;i++)
        {
            if(objectp(ob = find_player(revenge[i])))
            {
                if(ob->query_highest_level() > 15)
                {
                    tell_object(ob,"You have helped to silence the voice of the mountain.");
                    ob->set_mini_quest("Silence the volcano voice\n",45000,"Silence the mountains
voice\n");
                }
            }
        }
    }

    SAVE_D->remove_array("obsidian_revenge");
    ::die(obj);
}

int test_heart() { return 1; }

void receive_given_item(object obj)
{
    object item;
    string location;
    if(!objectp(obj)) return;
    location = base_name(ETO);
   if(location == HOMEROOM || location == "/d/undead/rooms/mts/room97")
    {
      if(base_name(obj) == "/d/undead/obj/powergem") 
        {
            tell_room(ETO,"The two gemstones flare brightly upon contact and "
                "merge into one!");
            obj->move("/d/shadowgate/void");
        obj->remove();
        }
        return;
    }

   if(base_name(obj) == "/d/undead/obj/powergem" && !avatarp(TP))
    {
        tell_room(ETO,"Xeryl's attentions are drawn abruptly to the "
            "gem before him, his rage forgotten.  He takes it between two claws, holding "
            "it almost tenderly, as he raises it to eye level.");
        tell_room(ETO,"A flash of anger returns to his fearsome gaze as "
            "he looks back upon you, and his hissing words seem to vibrate upon the "
            "air: Take what is mine ever again, and I will not be so merciful.");
      tell_room(ETO,"He lifts his head, and a single flap of his mighty "
      "wings draws him aloft.");
        message("combat","The dragon returns to his lair, his rage abated.",users());
        TO->move(HOMEROOM);
        SAVE_D->remove_array("obsidian_revenge");
    }
}

void notice_death(object whom) {remove_attacker(whom); return;}
