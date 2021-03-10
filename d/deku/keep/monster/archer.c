#include <std.h>
inherit "/std/monster.c";
int build,reload, flag;
string *outs,*exit_dir;
object ob;

void create() 
{
    ::create();
    set_name("keep archer");
    set_id( ({ "keep archer","orc", "archer" }) );
    set_race("orc");
    set_gender("male");
    set_short("Keep archer");
    set_long("%^RESET%^This orcish archer wears a dull suit of %^BOLD%^%^WHITE%^silver chain mail%^RESET%^. This creature "+
    "is obviously very unkept, hygiene is not a term that applies to it. Its "+
    "skin is a sickly gray and its course hair is matted together with all types "+
    "of filth. A heavy foul odor is emitted from this creature. He carries "+
    "a longsword at ready and keeps a shortbow handy in case of intruders.%^RESET%^");
    set_overall_ac(-3);
    set("aggressive", 20);
    set_alignment(6);
    set_size(2);
    set_hd(22,1);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",19);
    set_stats("charisma",7);
    set_stats("dexterity",19);
    set_stats("constitution",16);
    set_hp(400 + random(41));
    set_max_hp(query_hp());
    new("/d/common/obj/lrweapon/arrows")->move(TO);
    new("/d/common/obj/lrweapon/arrows")->move(TO);
    new("/d/common/obj/lrweapon/shortbow")->move(TO);
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield longsword");
    ob = new("/d/common/obj/armour/chain");
    ob->set_name("silver chain mail");
    ob->set_id(({"chain","Chain","silver chain","Silver Chain","chainmail","Chainmail","Mail","mail"}));
    ob->set_obvious_short("silver chain mail");
    ob->set_short("%^BOLD%^%^WHITE%^Silver Chain Mail%^RESET%^");
    ob->set_long("%^BOLD%^%^WHITE%^This dull chain mail is made from "+
    "interlocking rings of a silver alloy.  "+
    "The entire suit of mail is three layers thick and has a thick "+
    "fabric laid underneath of it to provide at least some comfort.  A pattern of "+
    "shiny silver on the torso creates the image of a large %^BOLD%^%^BLACK%^"+
    "wolf%^BOLD%^%^WHITE%^ head.%^RESET%^");
    if(!random(2)) ob->set_property("enchantment",3);
    ob->move(TO);
    command("wear chainmail");
    set_new_exp(20, "normal");	
    set_max_level(25);
    set_heart_beat(1);
    set_monster_feats(({
    "parry",
    "powerattack",
    "shatter",
    "sunder",
    "rush"
    }));
    //set_funcs(({"rushit","flashit","flashit"}));
    //set_func_chance(30);   
}

void init() 
{
    command("unwield bow");
    command("wield sword");
    ::init();
}

void heart_beat()
{
    object *ob;
    int inc,inc2,exits, shots;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    build++;
    reload++;
    if(build == 2)	
    {
        outs = ETO->query_destinations();
        exit_dir = ETO->query_exits();
        for(inc2 = 0;inc2<sizeof(outs);inc2++)
        {
            if(!ob = all_inventory(find_object_or_load(outs[inc2])))
            continue;
            else
            {
                for(inc = 0;inc < sizeof(ob);inc ++)
                {
                    if(!interactive(ob[inc])) 
                    {
                        continue;
                    }
                    if(ob[inc]->query_invis()) 
                    {
                        continue;
                    }
                    else 
                    {
                        flag = 1;
                        command("unwield longsword");
                        command("wield bow");
                        for(shots = 0;shots < random(3) + 1;shots++) 
                        {
                            command("shoot "+ob[inc]->query_name()+" "+exit_dir[inc2]);
                        }
                    }
                }
            }
            build = 0;
        }

        if(sizeof(ob) == 0 && flag == 1) 
        {
            flag = 0;
            command("unwield bow");
            command("wield longsword");
        }
    }
}
