#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_name("Bruno");
    set_id( ({"Bruno", "bruno", "barkeeper", "barkeep", "Gtonovimon"}) );
    set_short("Bruno the Barkeep");
    set("aggressive", 0);
    set_level(23);
    set_exp(10);
    set_long(
    "Bruno is a short stocky man, obviously able to drink his weight in alcohol and not feel it at all.  Dressed in perfect clothing, Bruno is one of those great barkeeps that can make you feel like the only person that has problems, and give you enough to drink to down those problems."
    );
    set_gender("male");
    set_alignment(6);
    set("race", "human");
    set_hp(400);
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_exp(5);
    set_menu(
    ({ "whiskey", "vodka", "goldschlager", "beer"}),
    ({ "alcoholic", "alcoholic", "alcoholic", "alcoholic" }),
    ({ 10,10,20,2})
    );
    set_my_mess(
      ({
    "The whiskey burns your throat on the way down.",
    "The vodka burns your throat.",
      "The taste of cinnamon bursts in your mouth.",
    "The tart beer slides down your parched throat.",
      })
    );
    set_your_mess(
      ({
    "makes strange faces as the whiskey burns down their throat.",
    "makes strange faces as the vodka burns down his throat.",
    "smiles and briefly slips into a coma.",
    "belches loud when he finishes chugging the beer.",
      })
    );
    set_menu_short(
      ({
    "Whiskey",
    "a shot of Vodka",
    "Goldschlager",
    "Mug of Beer",
      })
    );
    set_menu_long(
      ({
    "A small glass of whiskey waits for your lips",
    "A small glass of Vodka, waiting just for you.",
    "A small glass holding a strange alcoholic substance with flecks of gold in it.",
    "A dark brew of great beer.",
      })
    );
}
