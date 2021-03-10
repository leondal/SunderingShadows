#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>

inherit MONSTER;
int absorb_amt;

void create() 
{
    object ob;
    string *VALCOLOR = ({"%^RED%^", "%^BLUE%^", "%^YELLOW%^", "%^GREEN%^", 
    "%^ORANGE%^", "%^CYAN%^", "%^MAGENTA%^", "%^WHITE%^","%^BOLD%^%^BLACK%^"});

    string cone, ctwo;
    ::create();
    set_name("a malevolent ghost");
    set_id(({"ghost", "malevolent ghost", "hhghostmon"}));

    if(!random(2)) set_gender("male");
    else set_gender("female");

    set_race("ghost");

    cone = VALCOLOR[random(sizeof(VALCOLOR))];
    VALCOLOR -= ({cone});
    if(!random(2)) cone = "%^BOLD%^"+cone;
    ctwo = VALCOLOR[random(sizeof(VALCOLOR))];
    if(!random(2)) ctwo = "%^BOLD%^"+ctwo;

    set_short(cone +"Malevolent ghost with %^RESET%^"+
    ctwo+"glowing%^RESET%^"+cone+" eyes%^RESET%^");

    set_long(cone+"This ethereal creature's face is set in an "+
    "eternal grimace. It screams silently in what seems to be "+
    "an overwhelming %^RESET%^"+ctwo+"AGONY%^RESET%^"+cone+
    ". From what you can tell of its body it suffered a "+
    "great deal in life. The legs and arms are all horribly "+
    "bent forever, the fingers on both hands are %^RESET%^"+
    ctwo+"twisted%^RESET%^"+cone+" and %^RESET%^"+ctwo+
    "mangled%^RESET%^"+cone+" almost beyond recognition. "+
    "The eyes of this creature%^RESET%^"+ctwo+" blaze"+
    "%^RESET%^"+cone+" brilliantly with a %^RESET%^"+ctwo+
    "RAGE%^RESET%^"+cone+" that threatens to erupt "+
    "violently.%^RESET%^");

    set_body_type("human");
    set_level(32);
    set_size(1+random(3));
    set_alignment(9);
    set_hd(32,2);
    set("aggressive",45);
    set_overall_ac(-5);
    set_property("undead",1);

    set_hp(425 + random(176));
    set_max_hp(query_hp());
    set_new_exp(32, "normal");
    ob = new(AOITEMS+"midnights_edge");
    if(random(100)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield scimitar");
    ob = new(AOITEMS+"midnights_edge");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield scimitar");
    set_property("full attacks", 1);
    set_func_chance(35); 
    set_funcs(({"absorb_life", "feed_life"}));
    
    set_stats("strength",18);
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",18);
    set_stats("charisma",8);
    set_stats("constitution",12);
    
}

void absorb_life(object vic)
{
    int dam;
    string tlim;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;

    tlim = vic->return_target_limb();

    tell_object(vic, TO->query_short() + "%^BOLD%^%^CYAN%^ "+
    "lets its twisted and mangled fingers slowly caress "+
    "your "+tlim+"!%^RESET%^");
	
    tell_room(ETO, TO->query_short() + "%^BOLD%^%^CYAN%^ "+
    "slowly caresses "+vic->QCN+"%^BOLD%^%^CYAN%^'s "+tlim+
    " with its twisted and mangled fingers!%^RESET%^", vic);
	
    dam = roll_dice(10, 10);
	
    if(vic->fort_save(40)) 
    {
        dam = dam/2;
        tell_object(vic, "%^BOLD%^%^RED%^You shudder "+
        "%^BOLD%^%^GREEN%^VIOLENTLY%^BOLD%^%^RED%^ "+
        "from the touch but manage to resist most of its "+
        "effect!%^RESET%^");
		
        tell_room(ETO, vic->QCN+"%^BOLD%^%^RED%^ shudders "+
        "%^BOLD%^%^GREEN%^VIOLENTLY%^BOLD%^%^RED%^ "+
        "from the touch!%^RESET%^", vic);
        absorb_amt += dam;		
        vic->cause_typed_damage(vic, tlim, dam, "negative energy");
    }
    else
    {
        tell_object(vic, "%^BOLD%^%^BLACK%^You shudder "+
        "%^BOLD%^%^RED%^VIOLENTLY%^BOLD%^%^BLACK%^ from "+
        "the touch and "+
        "begin %^BOLD%^%^RED%^CONVULSING%^BOLD%^%^BLACK%^ "+
        "uncontrollably!%^RESET%^");

        tell_room(ETO, vic->QCN+"%^BOLD%^%^BLACK%^ shudders "+
        "%^BOLD%^%^RED%^VIOLENTLY%^BOLD%^%^BLACK%^ from "+
        "the touch and begins %^BOLD%^%^RED%^CONVULSING"+
        "%^BOLD%^%^BLACK%^ uncontrollably!%^RESET%^", vic);

        vic->set_paralyzed(10, "%^BOLD%^%^RED%^You are "+
        "CONVULSING violently!%^RESET%^");

        absorb_amt += dam;
		
        vic->cause_typed_damage(vic, tlim, dam, "negative energy");
    }

    tell_room(ETO, TO->query_short()+"%^BOLD%^%^CYAN%^ "+
    "screams in %^BOLD%^%^RED%^RAGE%^BOLD%^%^CYAN%^ "+
    "as its lifeforce is replenished!%^RESET%^");

    TO->set_hp((int)TO->query_hp() + dam);
    return;
}

void feed_life(object vic)
{
    object *life;
    int x, tmp, flag;
    string tlim;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;
    if(!absorb_amt) 
    {
        absorb_life(vic);
        return;
    }
    life = all_living(ETO);
    tmp = absorb_amt/3;
    if(tmp < 20) tmp = 20;
    for(x = 0; x < sizeof(life);x++)
	{
        if(!objectp(life[x])) continue;
        //if(life[x]->query_true_invis()) continue;
        if(!life[x]->id("hhghostmon")) continue;
        flag = 1;
        tlim = life[x]->return_target_limb();

        tell_room(ETO, TO->query_short() + "%^BOLD%^%^CYAN%^ "+
        "lets its twisted and mangled fingers slowly caress "+
        life[x]->query_short() +"%^BOLD%^%^CYAN%^'s "+tlim+"!%^RESET%^");

        tell_room(ETO, life[x]->query_short()+"%^BOLD%^%^CYAN%^ "+  
        "screams in %^BOLD%^%^RED%^RAGE%^BOLD%^%^CYAN%^ "+
        "as its lifeforce is replenished!%^RESET%^");
		
        life[x]->set_hp((int)life[x]->query_hp() + tmp);
		
    }
    if(flag) 
    {
        tell_room(ETO, TO->query_short()+"%^BOLD%^%^CYAN%^ "+
        "screams in %^BOLD%^%^RED%^RAGE%^BOLD%^%^CYAN%^ "+
        "as its lifeforce is replenished!%^RESET%^");
        TO->set_hp((int)TO->query_hp() + absorb_amt);
        absorb_amt = 0;
        return;
    }
    else absorb_life(vic);
    return;
}