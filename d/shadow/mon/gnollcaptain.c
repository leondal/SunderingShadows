//gnollcaptain.c - updated to use current code by Circe - 8/25/03
#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
        object ob;
        ::create();
        set_name("gnoll captain");
        set_id(({"gnoll captain","gnoll","captain","monster"}));
        set_race("gnoll");
        set_gender("male");
        set_short("A ferocious gnoll captain");
        set_long(
@OLI        
This gnoll stands larger than the average human, and has a very human 
looking body. Its head though is that of a canine, almost hyena-like 
with a mane from the head spreading down over its greenish gray skin. 
Its snarling mouth and dripping blood tends to make you think it's not 
going to wait for you to die before it starts to eat you.  This one stands 
head and shoulders taller than most other gnolls and has a commanding 
presence, as seen by the fearless look in its eyes.
OLI        
   );
        set_level(10);
        set_class("fighter");
        set_mlevel("fighter",8);
        set_body_type("human");
        set("aggressive",19);
        set_alignment(3);
        set_size(3);
        set_overall_ac(8);
        set_stats("intelligence",10);
        set_stats("wisdom",8);
        set_stats("strength",18);
        set_stats("charisma",3);
        set_stats("dexterity",15);
        set_stats("constitution",12);
        set_hd(10, 3);
        set_hp(random(10)+60);
        set_max_hp(query_hp());
        set_wielding_limbs( ({ "right hand", "left hand"}) );
        ob = new(CWEAP"mace");
        ob->set_property("monsterweapon",1);
        ob->move(TO);
        command("wield mace");
        ob = new(CARMOR"hide");
        ob->move(TO);
        command("wear armor");
        add_money("gold",random(100));
        add_money("copper",random(20));
        set_max_level(10);
        //set_exp(250);
        set_exp(1200);
        set_hp(random(20)+55);
}
