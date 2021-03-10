//Some problems with the divine weapon spell and these guys
//So I just commented out the divine weapons stuff for now
//and gave them a new +2 mace I made - as
//there are few +2 maces out there - Cythera 10/05
#include <std.h>

#define HEIGHTS ({"short","tall","slight"})
#define HAIR ({"%^RED%^red","%^RED%^scarlet","%^YELLOW%^auburn",\
"%^BOLD%^%^BLACK%^black","%^MAGENTA%^brown","%^YELLOW%^light brown",\
"%^YELLOW%^blonde"}) 
#define HAIRM ({"short","long","curly","straight"})
#define EYES ({"%^BOLD%^%^GREEN%^emerald","%^GREEN%^green",\
"%^CYAN%^hazel","%^BLUE%^blue","%^MAGENTA%^brown"})
#define EYEM ({"intense","calm","alert"}) 

inherit MONSTER;
string height;

void make_me() 
{
    !random(2) ? set_gender("male") : set_gender("female");
    !random(2) ? set_race("human") : set_race("half-elf");
    height = HEIGHTS[random(sizeof(HEIGHTS))];
    set_short("A "+height+ " "+query_gender()+" "+
    query_race()+" wearing a %^BOLD%^%^BLACK%^black%^RESET%^"+
    "%^RED%^ robe%^RESET%^");
}

void create() {
    string eyes,hair,hairm,eyesm;
    object ob;
    int x;
    ::create();

    eyes = EYES[random(sizeof(EYES))];
    eyesm = EYEM[random(sizeof(EYEM))];
    hair = HAIR[random(sizeof(HAIR))];
    hairm = HAIRM[random(sizeof(HAIRM))];

    set_name("priest");
    set_id(({"priest","cleric"}));
    make_me();
    set_class("cleric");
    set_mlevel("cleric",21);
    set_guild_level("cleric",query_level());
    set_stats("strength",15);
    if(!random(5)) {
        set_class("fighter");
        set_guild_level("fighter",query_guild_level("cleric") - 2);
        set_mlevel("fighter",query_guild_level("fighter"));
        set_stats("strength",16 + random(3));
    }
    set_stats("wisdom",17);
    set_stats("intelligence",13);
    set_stats("dexterity",13 + random(6));
    set_stats("constitution",13);
    set_stats("charisma",11);
   
    set_hp(375 + random(51));
    set_new_exp(20, "normal");
    set_alignment(4);
    set_overall_ac(-2);
    set_diety("kelemvor");
    set_sphere("death");
    if((string)TO->query_class_string() == "Cleric") {
        set_spells(({"flame strike","cause critical wounds",
        "hold person","call lightning","spectral panther"}));
        set_spell_chance(50);
    }
    ob = new("/d/deku/fortress/obj/jade_mace.c");
    if(random(2)){
        ob->set_property("monsterweapon",1);
    }
    ob->move(TO);
    command("wield mace");
    ob = new("/d/common/obj/armour/robe");
    ob->set_short("%^BLUE%^A flowing black robe%^RESET%^");
    ob->set_long("%^BOLD%^%^BLACK%^This flowing and fluffy robe "+
    "is made from a thick black cloth that seems to glisten even "+
    "in the complete absence of light.  The front of it is "+
    "embroidered with the holy symbol of kelemvor, a "+
    "raised %^BOLD%^%^WHITE%^skeletal arm%^BOLD%^%^BLACK%^ "+
    "evenly balancing the %^YELLOW%^golden%^BOLD%^%^BLACK%^ "+
    "scales of justice in its clenched fist.  The rest of the "+
    "fabric is sewn flawlessly, with every grain of the "+
    "thread going in a veritical direction.%^RESET%^");
    if(!random(3))
    {
        ob->set_property("enchantment",1);
    }
    ob->move(TO);
    command("wear robe"); 

    set_long("%^RESET%^This "+height+ " "+query_race()+ " is draped "+
    "with a flowing %^BOLD%^%^BLACK%^black robe%^RESET%^.  The robe "+
    "is embroidered with the symbol of kelemvor, a raised "+
    "%^BOLD%^%^WHITE%^skeletal arm%^RESET%^ evenly balancing "+
    "the %^YELLOW%^golden%^RESET%^ scales of justice in "+
    "its clenched fist.  "+capitalize(hairm)+" "+hair+ "%^RESET%^ "+
    "hair comes from the top of "+TO->QP+" head and is "+
    "complimented by "+TO->QP+ " always "+eyesm+" " +eyes+ 
    "%^RESET%^ eyes.  "+capitalize(TO->QS)+" appears "+
    "weaponless and defenseless, though something suggest "+
    "to you that you'd be wise to carefully consider any "+
    "attack against "+TO->QO);

    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    command("speak common");
    set_lang("common",100);
}

void heart_beat() {
    object ob;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    if(TO->query_exp() > 8000) {
        TO->set_exp(8000);
        return;
    }
    if((ob = present("corpse",ETO)) && !living(ob)) 
    { 
        TO->force_me("get corpse");
        TO->force_me("offer corpse to kelemvor");
        return;
    }
    if(!random(5) && (int)TO->query_hp() < (int)TO->query_max_hp() / 2) 
    {
         new("/cmds/spells/h/_heal")->use_spell(TO,TO,20,100,"cleric");
         return;
    }
}


void statements() 
{
    switch(random(5)) 
    {
        case 0:
            TO->force_me("speech say calmly");
            TO->force_me("say Undead, tis time for your rest!");
            break;
        case 1:
            TO->force_me("emote growls and begins muttering loudly");
            break;
        case 2:
            TO->force_me("yell FOR THE GLORY OF KELEMVOR!!");
            break;
        case 3:
            TO->force_me("speech utter with excitement");
            TO->force_me("say there's a foul undead, get 'em!");
            break;
        case 4:
            TO->force_me("speech growl angrily");
            TO->force_me("say those who have done this shall pay!");
            break;
    }
}
   

void init() 
{
    int spoke;
    ::init();
    if(TP->query_property("undead")) 
    {
        if(spoke == 0) 
        {
            statements();
            spoke = 1;
        }
        TO->force_me("kill "+TP->query_name());
    }
}
