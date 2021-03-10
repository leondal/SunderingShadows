#include <std.h>
#include "../arctic.h"
inherit CREATURE;

void new_fish();

void create()
{
   ::create();
    new_fish();
    set_gender((random(2)?"male":"female"));
    set_race("fish");
    set_body_type("snake");
    set_hd(15,1);
    set_max_level(25);
    set_size(2);
    set_alignment(5);
    set_overall_ac(5);
    set_hp(random(50) + 25);
    set_exp(100);
    set_level(15);
    set_class("fighter");
    set_mlevel("fighter",15);
    set_stats("intelligence", 2);
    set_stats("wisdom", 3);
    set_stats("strength", 8);
    set_stats("charisma", 13);
    set_stats("dexterity", 21);
    set_stats("constitution", 9);
    set_mob_magic_resistance("average");
    set_property("water breather", 1);
    set_speed(random(40) + 5);
    set_base_damage_type("piercing");
    nogo("NOGO2");
    add_money("silver",random(25));
    command("message in swims in");
    command("message out swims $D");

}

void die(mixed ob)
{
    if(!random(3)) { new(OBJ"ring_water_breathing")->move(TO); }
    
    ::die(ob);
}

void new_fish() 
{
    switch(random(5)) 
    {
    case 0:
        set_name("Carp");
        set_id(({"carp","fish","arcticmon"}));
        set_short("large carp");
        set_long("This greenish gray fish stretches several "
        "feet in length.  It has large scales that are more "
        "square than round, and very large black eyes.  The "
        "body of the fish is somewhat slender and elongated, "
        "while the head is rounded and comes to a small mouth.  "
        "The carp eats mosses as it moves along the stones and "
        "debris all about the lake.");
        break;

    case 1:
        set_name("Catfish");
        set_id(({"catfish","fish","arcticmon"}));
        set_short("huge catfish");
        set_long("This is a huge catfish that is slightly "
        "blue in color.  It has a flat heat with whisker like "
        "projections on either side of its wide mouth.  The "
        "fish has no scales on its body, but is covered by a "
        "very tough, and very slimy skin.  Its body is "
        "rounded in the middle, and small at the tail and "
        "near the head.  The fish looks to weigh in excess "
        "of three hundred pounds.");
        break;

    case 2:
        set_name("Giant Eel");
        set_id(({"eel","giant eel","fish", "arcticmon"}));
        set_short("giant eel");
        set_long("This gigantic eel is close to twenty feet "
        "in length, with a maw of jagged teeth in its small "
        "mouth.  Its body is elongated, looking more like an "
        "underwater snake than a fish.  It has small glazed "
        "gray eyes and small fins that run the length of its "
        "body on top and bottom.  The entire length of the eel "
        "is covered by a dark black colored skin.");
        break;

    case 3:
        set_name("Giant Gar");
        set_id(({"gar","giant gar","fish", "arcticmon"}));
        set_short("giant gar");
        set_long("This is a very dangerous looking fish.  The "
        "giant gar has a very long alligator like mouth filled with "
        "row apon row of razor sharp teeth.  Its body is long and "
        "powerful and it's covered with large hardened scales that "
        "are a dark gray in color.  The scales are round shaped, and "
        "reflect the light in strange patters making them more "
        "difficult to see in the murky water.  The fish is easily "
        "several hundred pounds, and is clearly a dangerous "
        "predator.");            
        break;

    case 4:
        set_name("Shark");
        set_id(({"shark","fish","arcticmon"}));
        set_short("shark");
        set_long("This is a small brown shark.  Its smooth "
        "skin is covered with darker brown spots.  The tall "
        "dorsal fin on the back of the shark is clearly evident "
        "as well as the fins along the side of the slender body.  "
        "The sleek body moves fluidly and the long curved mouth "
        "underneath the shark is filled with many sharp teeth.");
        break;
   }    
}     
     

