inherit "/std/monster.c";
string LUCIFER;
void create() {
  :: create();  
   set_name("ghoul");
   set_id( ({ "ghoul" }) );
   set_short("A Ghoul");
   set_level(15);
   set("long", 
@LUCIFER
The Ghoul is a rubbery, loathsome humanoid with hooflikr feet, 
canine features, and claws.  He is encrused in grave-mold.
LUCIFER
);
    set_gender("male");
    set("race", "human");
    set_body_type("human");
    set_alignment(-7);
    set_size(2);
    set_hd(14,8);
    set_stats("intelligence",8);
    set_stats("wisdom",4);
    set_stats("strength",18);
    set_stats("charisma",2);
    set_stats("dexterity",12);
    set_stats("constitution",17);
    set_max_mp(50);
    set_class("mage");
    set_guild_level("mage",8);
    set_hp(55);
    set_overall_ac(6);
    set_wielding_limbs(({"right hand","left hand"}));
    set("aggressive",16);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_max_hp(query_hp());
    set_mp(query_max_mp());
    set_exp(60+4*query_max_hp());
    set_spell_chance(27);
    set_spells(({"fireball","lightning_bolt"}));
    new("/d/islands/carcosa/weapons/dclaws.c")->move(this_object());
    command("wield claw in right hand");
    new("/d/islands/carcosa/weapons/dclaws.c")->move(this_object());
    command("wield claw in left hand");
    add_money("silver",100 + random(250));
    add_money("copper",50 + random(300));

}



