inherit "/std/monster.c";
string LUCIFER;
void create() {
  :: create();  
   set_name("Deep One");
   set_id( ({ "deep","deep one" }) );
   set_short("A Deep One");
   set_level(9);
   set("long", 
@LUCIFER
A predominantly greyish-green creature with white bellies.
They are mostly shiny and slippery, but the ridges on their 
backs appear scaly.  Although they walk on two legs, the 
Deep One has a fish-like apperrance.  His eyes are large 
black bulging orbs that never seem to close, pulsating 
gils are visiable in the side of his neck, and his webbed 
hands and feet end in sharp claws.
LUCIFER
);
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_alignment(-7);
   set_size(2);
   set_hd(11,0);
   set_stats("intelligence",8);
   set_stats("wisdom",4);
   set_stats("strength",18);
   set_stats("charisma",2);
   set_stats("dexterity",12);
   set_stats("constitution",17);
   set_max_mp(3);
    set_hp(40);
    set_overall_ac(6);
    set_class("fighter");
    set_wielding_limbs(({"right hand","left hand"}));
    set("aggressive",16);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_max_hp(query_hp());
    set_mp(query_max_mp());
    set_exp(60+4*query_max_hp());
    new("/d/islands/carcosa/weapons/dclaws.c")->move(this_object());
    command("wield claw in right hand");
    new("/d/islands/carcosa/weapons/dclaws.c")->move(this_object());
    command("wield claw in left hand");
    add_money("silver",100 + random(250));
    add_money("copper",50 + random(300));

}

