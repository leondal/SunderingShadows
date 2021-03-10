#include "/d/islands/dallyh/fways.h"
inherit "/std/barkeep";

void create() 
{
    ::create();

    set("aggressive", 0);
    set_level(25);
    set_guild_level("fighter", 25);
    set_mlevel("fighter", 25);   
    set_gender("female");
    set_alignment(4);
    set_race("human");
    set_hd(25,8);
    set_new_exp(25, "normal");
    set_hp(575);
    set_max_hp(575);
    add_money("copper", random(200));
    set_body_type("human");
    
    switch(random(2))
    {
        case 0:
            set_name("Ssertiaw");
            set_id( ({ "ssertiaw", "woman", "blonde woman", "friendly woman", "hospitalitywoman"}) );
            set_short("%^BOLD%^%^WHITE%^Ssertiaw, A friendly looking woman with strikingly %^BOLD%^%^YELLOW%^blonde"+
            "%^BOLD%^%^WHITE%^ hair%^RESET%^");
            set_long("%^BOLD%^%^WHITE%^This woman is large, towering nearly six feet tall and with a muscular "+
            "body that has more than its fair share of scars. She is dressed in modest %^RESET%^%^GREEN%^green%^BOLD%^%^WHITE%^ "+
            "attire that seems light weight and floats loosely away from her body. The most striking thing about her is "+
            "perhaps her hair, which is a brilliant and almost golden %^BOLD%^%^YELLOW%^blonde%^BOLD%^%^WHITE%^ that flows down "+
            "easily to her hips. It is exceedingly straight as if she has put a lot of effort into keeping it such. "+
            "You realize that her face and eyes portray an honest kindness, yet there is something else there. You catch "+
            "a fleeting glimpse of what you can describe only as hopelessness or perhaps profound sadness.%^RESET%^");
            break;
            
        case 1:
            
            set_name("Peekrab");
            set_id(  ({"Peekrab", "woman", "tense woman", "green eyed woman", "hospitalitywoman" })  );
            set_short("Peekrab the barkeep");
            set_short("%^BOLD%^%^WHITE%^Peekrab, A tense woman with hauntingly %^BOLD%^%^GREEN%^green eyes%^RESET%^");
            set_long("%^BOLD%^%^WHITE%^This woman is large, almost six and a half feet tall. Her body is very muscular and "+
            "well toned, as if she has spent a lot of time to keep it so, at least from what you can tell. Most of her body is "+
            "covered with very loose fitting blue clothing. Her %^RESET%^%^ORANGE%^brown hair%^BOLD%^%^WHITE%^ "+
            "is kept short and is quite curly. Looking her over you realize that her face portrays an almost tangible tenseness. "+
            "It is almost as if she is always on alert or watch but for what you are unsure. You almost get lost in her deep "+
            "hauntingly %^BOLD%^%^GREEN%^green eyes%^BOLD%^%^WHITE%^. They are quite unlike anything that you have seen before and "+
            "reveal a very deep intelligence as well as a very real nervousness.%^RESET%^");
            break;
    }
    
    set_currency("gold");

    set_menu(
      ({"leg of lamb", "roast boar", "berries", "water", "mysterious water"}),
      ({ "food", "food", "food", "water", "alcoholic" }),
      ({50, 20, 10, 10, 40})
    );
    set_my_mess(
      ({
        "The leg of lamb is delicious!\n",
        "The boar tastes different but very good!\n",
        "Mmmm. Good berries.\n",
        "You take a sip of water.\n",
        "You open your eyes wide as you feel the alcohol taking affect. \n",        
      })
    );
    
    set_your_mess(
      ({
        "rubs "+TP->query_possessive()+" stomach as they enjoy the leg of lamb.\n",
        "licks "+TP->query_possessive()+" lips after eating the boar.\n",
        "munches on some berries.\n",
        "takes a drink of water.\n",
        "opens "+TP->query_possessive()+" eyes as the alcohol takes affect.",
      })
    );
    set_menu_short(
      ({
        "A leg of lamb.",
         "A roasted boar.",
        "Some tasty berries.", 
        "Water",
        "Mysterious water",
      })
    );
    set_menu_long(
      ({
         "A plate of Leg of lamb",
         "A plate of delicious roast boar",
         "A bowl of forest berries",
         "A clear and filtered water, from nearby streams.\n",
         "A murky type water that seems to fizzle.\n",        
      })
    );
    
    
}
