//General difficulty increase Octothorpe 5/25/09
// adding some objectp checks to try to prevent bugs *Styx*  11/1/03
// Also changing the add_action to toss, assumption is it was meant to stop powder and now powder uses throw


#include <std.h>
inherit WEAPONLESS;
int FLAG,SLEEP;
object vic;

void init()
{
   ::init();
//   add_action("no_cast","throw");
   add_action("no_cast","toss");
}

void create()
{
    :: create();
    set_name("dragon");
    set_id(({
        "red dragon","dragon","old red dragon","snarl","massive dragon","very old red dragon","mirage"
    }));
    set_short("%^RESET%^%^RED%^Snarl, the %^BOLD%^f%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^er%^RED%^y %^RESET%^m%^BOLD%^irag%^RESET%^e %^RED%^of a %^BOLD%^red %^RESET%^%^RED%^dragon%^RESET%^");
    set_long("%^RESET%^%^RED%^This incredible beast before you is shaped from %^WHITE%^smoke %^RED%^and %^BOLD%^fire, %^RESET%^%^RED%^contained within a %^WHITE%^tr%^BOLD%^ans%^RESET%^lu"
			 "%^BOLD%^c%^RESET%^ent sh%^BOLD%^el%^RESET%^l%^RED%^. First, a %^WHITE%^fl%^BOLD%^i%^RESET%^cke%^BOLD%^r%^RESET%^ing m%^BOLD%^irag%^RESET%^e%^RED%^, now %^BOLD%^%^BLACK%^dang"
			 "erously substantial%^RESET%^%^RED%^, it %^BOLD%^%^BLACK%^s%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^f%^BOLD%^%^BLACK%^ts %^RESET%^%^RED%^constantly as though battling"
			 " reality itself. As it again gains %^BOLD%^%^BLACK%^substance%^RESET%^%^RED%^, it takes on the form of a %^BOLD%^gargantuan red dragon%^RESET%^%^RED%^. Massive %^BOLD%^reptilian"
			 " jaws %^RESET%^%^RED%^could sever a giant in half and sharp %^BOLD%^%^WHITE%^fangs %^RESET%^%^RED%^could rip through %^BOLD%^%^WHITE%^titanium %^RESET%^%^RED%^and maul an entire"
			 " army. %^BOLD%^Fire %^RESET%^%^RED%^burns within the narrow slits of its eyes and molten lava drips from %^BOLD%^%^BLACK%^smoky %^RESET%^%^RED%^nostrils. Its ten-foot claws end in"
			 " %^BOLD%^spiked talons %^RESET%^%^RED%^that dig into the ground, a testament to its %^BOLD%^%^WHITE%^massive strength%^RESET%^%^RED%^. Now it %^BOLD%^%^WHITE%^fa%^RESET%^des %^RED%^again,"
			 " its diamond-hard hide turning %^WHITE%^tr%^BOLD%^an%^RESET%^slu%^BOLD%^c%^RESET%^ent%^RED%^. Within the vague shape of a %^BOLD%^dragon%^RESET%^%^RED%^, %^BOLD%^flames %^RESET%^%^RED%^dance"
			 " and %^BOLD%^%^BLACK%^smoke %^RESET%^%^RED%^billows, creating an %^BOLD%^%^WHITE%^angry%^RESET%^%^RED%^, %^BOLD%^f%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^er%^RED%^y %^RESET%^m%^BOLD%^ir%^RESET%^a"
			 "%^BOLD%^g%^RESET%^e%^RED%^.%^RESET");
    set_gender("male");
    set_level(50);
    set_hd(50,9);
    set_size(4);   // changed this to a 4 since he should be very very large *Styx*
    set_race("dragon");  // moved this up to be sure it doesn't wipe the added limb *Styx*
    set_body_type("dragon");
    set_property("undead",1);
    set_weight(300);
    set_attacks_num(12);
    set_damage(8,4);
    set_property("full attacks",1);
    set_base_damage_type("slashing");
    add_limb("jaws","head",0,0,0);
    set_attack_limbs(({"right foreclaw","left foreclaw","jaws"}));
    set_overall_ac(-38);
    set_class("fighter");
    set_guild_level("fighter",50);
    set_stats("strength",25);
    set_stats("constitution",25);
    set_stats("dexterity",25);
    set_stats("wisdom",25);
    set_stats("intelligence",25);
    set_stats("charisma",25);
    set_alignment(9);
    set_mob_magic_resistance("average");
//    set_property("no bows",1);  don't need it twice *Styx*
    set_exp(90000);
    set_max_hp(7500);
    //set_max_level(36);
    set_hp(7500);
    set_property("no bows", 1);
    set_property("magic", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_property("no tripped",1);
    set_property("no death", 1);
    add_money("gold",random(15001)+15000);
    set_emotes(1,({
        "%^RED%^The dragon's massive chest rumbles like a trapped furnace as he sleeps.%^RESET%^",
        "The dragon starts to stir, but drifts back into sleep.",
        "%^RED%^The dragon lets out a huff of air, and flames come blazing out of its jaws.%^RESET%^",
    }),0);
    set_funcs(({"breath"}));
    set_func_chance(75);
}

int no_cast(string str)
{
   object targ;
   targ = this_player();
   if(strsrch(str, "powder") != -1) {
      tell_object(targ, "The dragon is too large for that!");
      return 1;
   }
   return 0;
}

void breath(object targ)
{
    int dam;

    if(FLAG > 3)
    {
        //so he doesn't try breath and do nothing - Saide
        set_func_chance(0);
        return;
    }
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    tell_room(ETO, "%^BOLD%^%^RED%^"
        "The massive red dragon rears back its massive head and begins to exhale!"
        "%^RESET%^");
    call_out("flames",3);
}

void flames()
{
    object ob,sucker,*players;
    int x,num_p, dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;  // added 11/1/03


    players = all_living(ETO);
    tell_room(ETO, "%^BOLD%^RED%^The red dragon %^YELLOW%^exhales%^RED%^ "+
    "a mass of fiery breath which envelops everything in the area!");
    players -= ({TO});
    num_p = sizeof(players);
    for(x=0;x<num_p;x++)
    {
        sucker = players[x];
        if(!objectp(sucker)) continue;
        if(!living(sucker)) continue;
        if(sucker->query_true_invis()) continue;

        dam = roll_dice(50,10);
        tell_object(sucker, "%^BOLD%^%^YELLOW%^You are %^BOLD%^%^RED%^"+
        "burned%^BOLD%^%^YELLOW%^ by the flames!%^RESET%^");

        tell_room(environment(sucker),
        "%^BOLD%^%^RED%^"+sucker->query_cap_name()+
        " screams out as the flames burn "+sucker->QP+" body!%^RESET%^" ,sucker);

        if(sucker->reflex_save(28)) { dam /= 2; }
        //tell_object(sucker, "Damage = "+dam);
        sucker->cause_typed_damage(sucker, sucker->return_target_limb(), dam, "fire");
    }
    FLAG = FLAG + 1;
    return 1;
}

void set_paralyzed(int time,string message){return 1;}


void heart_beat()
{
    ::heart_beat();
    //if(!objectp(TO) || !objectp(ETO))   return;  // *Styx*  11/1/03 you never want to have these checks together,
                                                        //because if TO is invalid then ETO will error because you are trying to pass an invalid object to environment() - Saide
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if((int)TO->query_property("awake") != 1 && vic = TO->query_current_attacker())
    {
        tell_object(vic,
        "%^RED%^As you attack the dragon, it instantly awakens with a rage in its eyes!%^RESET%^");

        TO->set_property("awake",1);
        TO->set("aggressive",100);
        return;
    }
	return;
}
