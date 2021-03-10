//stole Crystal's descriptions for the nymphs in the valley
//Circe 4/27/04
#include <std.h>
#include "../../fways.h"
inherit MONSTER;

string type, color;
object obj;
void create()
{
  ::create();
    set_name("Nymph");
    set_gender("female");
    set_level(25);
    set_body_type("human");
    set_class("fighter");
    set_class("cleric");
    set_mlevel("cleric",25);
    set_class("mage");
    set_mlevel("mage",25);
    set_spell_chance(45);
        set_spells( ({
        "bliss",
        "thorn spray",
        "bliss",
        "kiss of torment"
        }) );
    set_alignment(9);
    set_size(2);
    set_hd(25, 1);
    set_overall_ac(-6);
    set_hp(455+random(175));
    set("aggressive", 16);
    set_new_exp(26, "high");
    set_race("nymph");
    set_property("add kits",15);
    if(!random(4)){
       new("/d/islands/dallyh/forest/obj/rosebodice")->move(TO);
       command("wear bodice");
    }
	 if(query_night() == 1) {
                if(!random(7)) {
                        new("/d/antioch/valley/obj/nymph_dress")->move(TO);
                        command("wear dress");
                }
                else {
                       obj=new("/d/deku/sanctuary/obj/orchidgown");
				if(random(3)){
        				obj->set_property("monsterweapon",1);
				}
				obj->move(TO);
                        command("wear gown");
                }
        }
        else {
                if(!random(7)) {
                        new("/d/antioch/valley/obj/nymph_dress2")->move(TO);
                        command("wear dress");
                }
                else {
                        obj=new("/d/deku/sanctuary/obj/orchidgown");
				if(random(3)){
        				obj->set_property("monsterweapon",1);
				}
				obj->move(TO);
                        command("wear gown");
                }
        }
        switch(random(13)) {
                case 0:
                        type = "blonde";
                        break;
                case 1:
                        type = "black";
                        break;
                case 2:
                        type = "red";
                        break;
                case 3:
                        type = "brown";
                        break;
                case 4:
                        type = "strawberry blonde";
                        break;
                case 5:
                        type = "auburn";
                        break;
                case 6:
                        type = "white";
                        break;
                case 7:
                        type = "sandy blonde";
                        break;
                case 8:
                        type = "silver";
                        break;
                case 9:
                        type = "sky-blue";
                        break;
                case 10:
                        type = "emerald green";
                        break;
                case 11:
                        type = "ebony";
                        break;
                case 12:
                        type = "golden";
                        break;
        }
        switch(random(13)) {
                case 0:
                        color = "blue";
                        break;
                case 1:
                        color = "green";
                        break;
                case 2:
                        color = "brown";
                        break;
                case 3:
                        color = "black";
                        break;
                case 4:
                        color = "hazel";
                        break;
                case 5:
                        color = "purple";
                        break;
                case 6:
                        color = "yellow";
                        break;
                case 7:
                        color = "violet";
                        break;
                case 8:
                        color = "gold";
                        break;
                case 9:
                        color = "azure";
                        break;
                case 10:
                        color = "chocolate";
                        break;
                case 11:
                        color = "emerald";
                        break;
                case 12:
                        color = "sapphire";
                        break;
        }

        set_long(
        "There is truly no way to describe this lovely creature in"+
        " words or thoughts. She's the incarnation of beauty, a young"+
        " woman with a perfect hour glass figure, thick "+type+" hair,"+
        " a perfect complexion. Her smile is dazzling, showing"+
        " perfect teeth behind her full, red lips. Her eyes seem"+
        " caring and are a lovely shade of "+color+". The breeze"+
        " blows the most wonderful scent to you. From her stance you"+
        " can tell she is graceful and charming. She is the perfect"+
        " woman."
        );
    set_id(({"nymph","Nymph", "woman", "young woman", "dallyhallyevil"}));
    set_short("%^BOLD%^%^WHITE%^A young woman with "+type+" hair and "+color+" eyes%^RESET%^");
    set_moving(1);
    set_speed(20);
    set_wielding_limbs(({"right hand", "left hand"}));
    new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger in left hand");
    if(random(6)){
       new("/d/islands/dallyh/forest/obj/sky_dagger")->move(TO);
       command("wield dagger in right hand");
    }else{
       new("/d/islands/dallyh/forest/obj/rosevinewhip")->move(TO);
       command("wield whip in right hand");
    }
    add_money("gold",500 + random(1200));
    set_mob_magic_resistance("high");
    set_stats("strength",17);
    set_stats("intelligence",25);
    set_stats("wisdom",16);
    set_stats("charisma",28);
    set_stats("constitution",16);
    set_stats("dexterity",17);
    set_nogo(({DDOCK, FRPATH"road1"}));
}
//wtf is this?? - Saide
/*
void die(object ob)
{
    if(query_money("gold")) add_money("gold", -(query_money("gold")));
    if(query_money("platinum")) add_money("platinum", -(query_money("platinum")));
    if(query_money("electrum")) add_money("electrum", -(query_money("electrum")));
    if(query_money("silver")) add_money("silver", -(query_money("silver")));
    if(query_money("copper")) add_money("copper", -(query_money("copper")));
    add_money("gold", random(100));
    ::die(ob);
}*/
