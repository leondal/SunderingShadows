#include <std.h>
inherit BARKEEP;

string time;

create() {
  ::create();
  set_property("no bump", 1);
  set_name("Mercury");
  set_id( ({"mercury","barkeep","Mercury"}) );
  set_short("%^RESET%^%^ORANGE%^Mercury, the Barkeep%^RESET%^");
  set("aggressive", 0);
  set_level(12);
  set_long("Mercury is the proprietor of Bloody Mary's Bar and Grill. He's a rough looking fellow who seems unaccustomed to taking anybody's crap.");
   set_gender("female");
  set_alignment(9);
  set("race", "barbarian");
  set_hd(13,2);
  add_money("gold", random(200));
  set_body_type("human");
  set_class("fighter");
  set_wielding_limbs(({"right hand"}));
  new("/d/common/obj/weapon/shortsword.c")->move(this_object());
  command("wield sword in right hand");
  set_exp(3960);
  set_hp(120);
  set_currency("gold");
  set_menu(({
  "bloody mary","red wine","beer","tequila","ale"}),
  ({"alcoholic","alcoholic","alcoholic","alcoholic","alcoholic"}),
    ({25,15,10,15,10})
    );
    set_my_mess(
        ({
        "%^RED%^Hmmmm. Odd but good. Your body strongly encourages you to drink more.%^RESET%^\n",
        "%^MAGENTA%^Wow, this is a very fine wine. It would pair well with red meat.%^RESET%^\n",
        "%^ORANGE%^You down some great beer from another age.%^RESET%^\n",
        "%^BOLD%^%^WHITE%^You appreciate the smooth kick of the alcohol.%^RESET%^\n",
        "%^ORANGE%^You chug down some ale.%^RESET%^\n",
        }));
    set_your_mess(
        ({
        "screams from the burning sensation of the drink.\n",
          "enjoys the refreshing taste of a fine wine.\n",
	"shakes his head in approval of this fine alcohol.\n",
	",after a squint, looks around for another drink.\n",
        "drinks some ale.\n"
        })
    );
    set_menu_short(
        ({
        "%^BOLD%^%^RED%^A Bloody Mary Special%^RESET%^",
          "%^MAGENTA%^A red wine%^RESET%^",
	"%^ORANGE%^A bottle of beer%^RESET%^",
        "%^YELLOW%^A shot of tequila%^RESET%^",
        "%^ORANGE%^A mug of pale ale%^RESET%^"
        })
    );
    set_menu_long(
        ({
        "A special drink to soothe the hardships of travel.\n",
        "A nice red wine to accompany a dish of red meat.\n",
        "A bottle of beer from the brewers of Verbobone.\n",
        "A tequila from far off Seneca.\n",
        "A pale ale brewed outside of Verbobone.\n"
        })
    );
} 

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
/*
    if(time == "dawn")
    remove();
*/
}
